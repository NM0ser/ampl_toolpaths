#include "stdafx.h"
#include "amplWireIntersection.h"

namespace ampl
{
	amplWireIntersection::amplWireIntersection()
	{

	}

	void amplWireIntersection::addEdge(const TopoDS_Edge &edgeIn, bool pushBack)
	{
		TopoDS_Edge edgeInCopy = edgeIn;
		if (pushBack)
		{
			edgeArr.push_back(edgeInCopy);
		}
		else
		{
			std::vector<TopoDS_Edge> edgeArrPushFront;
			edgeArrPushFront.push_back(edgeInCopy);
			for (TopoDS_Edge& iter : edgeArr)
			{
				edgeArrPushFront.push_back(iter);
			}
			edgeArr = edgeArrPushFront;
		}
	}

	void amplWireIntersection::addEdgePnts(const gp_Pnt &pntU1, const gp_Pnt &pntU2, bool pushBack)
	{
		gp_Pnt pntU1Copy = pntU1;
		gp_Pnt pntU2Copy = pntU2;
		if (pushBack)
		{
			edgePoints.push_back({ pntU1 , pntU2 });
		}
		else
		{
			std::vector< std::vector<gp_Pnt> > edgePointsPushFront;
			edgePointsPushFront.push_back({ pntU1 , pntU2 });
			for(std::vector<gp_Pnt>& iter : edgePoints)
			{ 
				edgePointsPushFront.push_back(iter);
			}
			edgePoints = edgePointsPushFront;
		}
	}

	void amplWireIntersection::addReverseFlag(bool reverse, bool pushBack)
	{
		if (pushBack)
		{
			edgeReverseArr.push_back(reverse);
		}
		else
		{
			std::vector<bool> edgeReverseArrPushFront;
			edgeReverseArrPushFront.push_back(reverse);
			for (bool iter : edgeReverseArr)
			{
				edgeReverseArrPushFront.push_back(iter);
			}
			edgeReverseArr = edgeReverseArrPushFront;
		}
	}

	void amplWireIntersection::getOrderedEdgePnts(Standard_Integer edgeIndex, gp_Pnt &firstPnt, gp_Pnt &lastPnt)
	{
		if (edgeReverseArr.at(edgeIndex) == false)
		{
			firstPnt = (edgePoints.at(edgeIndex)).at(0);
			lastPnt = (edgePoints.at(edgeIndex)).at(1);
		}
		else
		{
			firstPnt = (edgePoints.at(edgeIndex)).at(1);
			lastPnt = (edgePoints.at(edgeIndex)).at(0);
		}
		
	}

	void amplWireIntersection::getEdge(Standard_Integer edgeIndex, TopoDS_Edge &edge)
	{
		size_t numEdgesOfCurrentWire = getSizeEdgeArray();

		if (edgeIndex < 0 || edgeIndex > numEdgesOfCurrentWire)
			return;

		edge = edgeArr.at(edgeIndex);
	}

	size_t amplWireIntersection::getSizeEdgeArray(void)
	{
		return edgeArr.size();
	}

	bool amplWireIntersection::containsEdge(const TopoDS_Edge &edgeIn, Standard_Integer &edgeIndexOut)
	{
		Standard_Real curveInU1, curveInU2, curveInU3;
		Handle(Geom_Curve) curveIn = BRep_Tool::Curve(edgeIn, curveInU1, curveInU3);
		curveInU2 = (curveInU1 + curveInU3) / 2.0;

		gp_Pnt  pntCurveInU1, pntCurveInU2, pntCurveInU3;
		pntCurveInU1 = curveIn->Value(curveInU1);
		pntCurveInU2 = curveIn->Value(curveInU2);
		pntCurveInU3 = curveIn->Value(curveInU3);

		size_t numEdgesOfCurrentWire = getSizeEdgeArray();
		for (size_t edgeIndexLocal = 0; edgeIndexLocal < numEdgesOfCurrentWire; edgeIndexLocal++)
		{
			TopoDS_Edge localEdge;
			getEdge(edgeIndexLocal, localEdge);

			if (edgeIn.IsEqual(localEdge))
			{
				edgeIndexOut = edgeIndexLocal;
				return true;
			}

			// Also check 3 discrete points manually in case the object comparison does not catch an equal edge
			Standard_Real curveLocalU1, curveLocalU2, curveLocalU3;
			Handle(Geom_Curve) curveLocal = BRep_Tool::Curve(localEdge, curveLocalU1, curveLocalU3);
			curveLocalU2 = (curveLocalU1 + curveLocalU3) / 2.0;

			gp_Pnt  firstPntLocal, midPntLocal, lastPntLocal;
			firstPntLocal = curveLocal->Value(curveLocalU1);
			midPntLocal = curveLocal->Value(curveLocalU2);
			lastPntLocal = curveLocal->Value(curveLocalU3);

			if (pntCurveInU1.IsEqual(firstPntLocal, 0.002) && pntCurveInU2.IsEqual(midPntLocal, 0.002) && pntCurveInU3.IsEqual(lastPntLocal, 0.002))
			{
				edgeIndexOut = edgeIndexLocal;
				return true;
			}
			else if (pntCurveInU1.IsEqual(lastPntLocal, 0.002) && pntCurveInU2.IsEqual(midPntLocal, 0.002) && pntCurveInU3.IsEqual(firstPntLocal, 0.002))
			{
				edgeIndexOut = edgeIndexLocal;
				return true;
			}
		}

		return false;
	}

	bool amplWireIntersection::isClosedContour(Standard_Real edgeToEdgeTol)
	{
		gp_Pnt firstEdgeFirstPnt, lastEdgeLastPnt;

		firstEdgeFirstPnt = (edgePoints.front()).at(0); // First edge is never reversed

		if (edgeReverseArr.back())	// Last edge is reversed
			lastEdgeLastPnt = (edgePoints.back()).at(0);
		else						// Last edge is not reversed
			lastEdgeLastPnt = (edgePoints.back()).at(1);

		if (firstEdgeFirstPnt.IsEqual(lastEdgeLastPnt, edgeToEdgeTol))
			return true;
		else
			return false;
	}

	void amplWireIntersection::revEdge(Standard_Integer edgeIndex, TopoDS_Edge &edgeOut)
	{
		TopoDS_Edge localEdge, edgeCorrected;
		size_t numEdgesOfCurrentWire = getSizeEdgeArray();

		if (edgeIndex < 0 || edgeIndex > numEdgesOfCurrentWire)
			return;

		getEdge(edgeIndex, localEdge);

		Standard_Real edgeParamU1, edgeParamU2, edgeParamU3;
		gp_Pnt localPntU1, localPntU2, localPntU3;
		Handle(Geom_Curve) curveLocal = BRep_Tool::Curve(localEdge, edgeParamU1, edgeParamU3);
		Handle(Standard_Type) curveType = curveLocal->DynamicType();
		edgeParamU2 = (edgeParamU1 + edgeParamU3) / 2.0;
		localPntU1 = curveLocal->Value(edgeParamU1);
		localPntU2 = curveLocal->Value(edgeParamU2);
		localPntU3 = curveLocal->Value(edgeParamU3);

		Standard_Boolean edgeIsClosed = false;
		if (localPntU1.IsEqual(localPntU3, 0.002))
			edgeIsClosed = true;

		if ((curveType == STANDARD_TYPE(Geom_Circle)) && !edgeIsClosed) // Cannot reverse orientation of a trimmed circle, need to define a trimmed curve to replace it
		{
			Handle(Geom_TrimmedCurve) anArcOfCircle = GC_MakeArcOfCircle(localPntU3, localPntU2, localPntU1);
			BRepBuilderAPI_MakeEdge edgeBuilder(anArcOfCircle);
			if (edgeBuilder.IsDone())
				edgeCorrected = edgeBuilder.Edge();
			else
				return; // Error, could not reconstruct the edge for the wire
		}
		else if (curveType == STANDARD_TYPE(Geom_BSplineCurve))
		{
			Handle(Geom_BSplineCurve) aBSplineCurve = Handle(Geom_BSplineCurve)::DownCast(curveLocal);
			aBSplineCurve->Reverse();
			BRepBuilderAPI_MakeEdge edgeBuilder(aBSplineCurve, edgeParamU3, edgeParamU1);
			if (edgeBuilder.IsDone())
				edgeCorrected = edgeBuilder.Edge();
			else
				return; // Error, could not reconstruct the edge for the wire
		}
		else 
		{
			BRepBuilderAPI_MakeEdge edgeBuilder(curveLocal, edgeParamU3, edgeParamU1);
			if (edgeBuilder.IsDone())
				edgeCorrected = edgeBuilder.Edge();
			else
				return; // Error, could not reconstruct the edge for the wire
		}

		edgeOut = edgeCorrected;
	}

	void amplWireIntersection::toOccWire(TopoDS_Wire &wireOut)
	{
		TopoDS_Wire localWire;
		BRepBuilderAPI_MakeWire wireBuilder;

		size_t numEdgesOfCurrentWire = getSizeEdgeArray();
		for (size_t edgeIndexLocal = 0; edgeIndexLocal < numEdgesOfCurrentWire; edgeIndexLocal++)
		{
			TopoDS_Edge localEdge;

			//if (edgeReverseArr.at(edgeIndexLocal))
			//	revEdge(edgeIndexLocal, localEdge);
			//else
			getEdge(edgeIndexLocal, localEdge);

			wireBuilder.Add(localEdge);
		}

		if (wireBuilder.IsDone())
			localWire = wireBuilder.Wire();

		wireOut = localWire; // Will be empty if conversion failed
	}

	void amplWireIntersection::copy(const amplWireIntersection &other)
	{
		edgeArr = other.edgeArr;
		edgePoints = other.edgePoints;
		edgeReverseArr = other.edgeReverseArr;
	}

	void amplWireIntersection::discretizeWire(Standard_Real stepDist, Standard_Real edgeToEdgeTol, std::vector<gp_Pnt> &pntsOut)
	{
		pntsOut.clear();
		//std::vector<gp_Pnt> localPntArr;
		size_t numEdgesInWire = getSizeEdgeArray();
		Standard_Boolean wireIsClosed = isClosedContour(edgeToEdgeTol);

		for (size_t edgeIndexLocal = 0; edgeIndexLocal < numEdgesInWire; edgeIndexLocal++)
		{
			TopoDS_Edge localEdge;

			//if (edgeReverseArr.at(edgeIndexLocal))
			//	revEdge(edgeIndexLocal, localEdge);
			//else
			getEdge(edgeIndexLocal, localEdge);

			Standard_Real edgeU1, edgeU2; // Get the edge into geometric form and all of its properties
			gp_Pnt localPntFirst, localPntLast;
			Handle(Geom_Curve) curveLocal = BRep_Tool::Curve(localEdge, edgeU1, edgeU2);
			Handle(Standard_Type) curveType = curveLocal->DynamicType();
			GeomAdaptor_Curve edgeAdaptorCurve(curveLocal, edgeU1, edgeU2);
			getOrderedEdgePnts(edgeIndexLocal, localPntFirst, localPntLast);
			//Standard_Real edgeLen = GCPnts_AbscissaPoint::Length(edgeAdaptorCurve, edgeU1, edgeU2, 0.001);

			Standard_Boolean edgeIsClosed = false;
			if (localPntFirst.IsEqual(localPntLast, edgeToEdgeTol))
				edgeIsClosed = true;

			GCPnts_UniformAbscissa pointDistributeBuilder;
			pointDistributeBuilder.Initialize(edgeAdaptorCurve, stepDist, edgeU1, edgeU2);

			Standard_Integer nbr;
			if (pointDistributeBuilder.IsDone()) // Discretizes the curve, though, in an unknown direction. Must sort order later
			{
				nbr = pointDistributeBuilder.NbPoints();
				for (Standard_Integer pointIndex = 1; pointIndex <= nbr; pointIndex++) // Store the calculated points along the edge
				{
					Standard_Real distPointU1 = pointDistributeBuilder.Parameter(pointIndex);
					gp_Pnt distPointLocal = curveLocal->Value(distPointU1);
					pntsOut.push_back(distPointLocal);
				}
			}
		}

		if (pntsOut.front().Distance(pntsOut.back()) < 0.002) // Delete any points that may be duplicates of their neighbors
		{
			pntsOut.erase(pntsOut.begin() + (pntsOut.size() - 1));
		}
		for (int pntIndex = 1; pntIndex < pntsOut.size(); pntIndex++) 
		{
			if (pntsOut.at(pntIndex - 1).Distance(pntsOut.at(pntIndex)) < 0.002)
			{
				pntsOut.erase(pntsOut.begin() + (pntIndex - 1));
				pntIndex--;
			}
		}

	}

	void amplWireIntersection::sequentialSortDiscretizedPnts(gp_Pnt firstWirePnt, std::vector<gp_Pnt> &pntsInOut)
	{
		std::vector<gp_Pnt> localPntArr = pntsInOut;
		pntsInOut.clear();

		std::vector<gp_Pnt> localClosestPnts;
		std::vector<int> localClosestPntsIndices;
		std::vector<Standard_Real> localClosestPntsDist;
		Standard_Real distVar1;
		Standard_Integer pntCount1, pntCount2, startPntIndex;
		gp_Pnt closestPnt;
		bool keepSearching = true;
		pntCount1 = 0;
		while (keepSearching)
		{
			distVar1 = 100000;
			pntCount2 = 0;
			for (gp_Pnt &pntIter1 : localPntArr)
			{
				bool pntUsedAlready = false;
				for (gp_Pnt &pntIter2 : localClosestPnts)
				{
					if (pntIter2.IsEqual(pntIter1, 0.002))
					{
						pntUsedAlready = true;
						break;
					}

				}
				if (pntUsedAlready)
					continue;

				Standard_Real curDist = pntIter1.Distance(firstWirePnt);
				if (curDist < 0.002)
				{
					startPntIndex = pntCount2;
					distVar1 = curDist;
					closestPnt = pntIter1;
					break;
				}
				else if (curDist < distVar1)
				{
					distVar1 = curDist;
					startPntIndex = pntCount2;
					closestPnt = pntIter1;
				}
				pntCount2++;
			}

			localClosestPnts.push_back(closestPnt);
			localClosestPntsIndices.push_back(startPntIndex);
			localClosestPntsDist.push_back(distVar1);

			pntCount1++;
			if (pntCount1 >= 5) // Find 5 closest points
				keepSearching = false;
		}

		int simPntsIndex = 0;
		/*for (int pntIndex = 1; pntIndex < localClosestPnts.size(); pntIndex++)
		{
			Standard_Real diffDist = abs(localClosestPntsDist.at(pntIndex) - localClosestPntsDist.at(pntIndex - 1));
			
			if (diffDist < 0.001) // Determine if multiple points are nearly equally close to the desired starting point
				simPntsIndex = pntIndex;
			else
				break;
		}*/

		if (simPntsIndex == 0) // If only one point is closest to the desired point, use it
		{
			startPntIndex = localClosestPntsIndices.front();
			distVar1 = localClosestPntsDist.front();
			closestPnt = localClosestPnts.front();
		}
		else
		{
			gp_Dir zAxis(0.0, 0.0, 1.0);
			gp_Ax1 rotateAboutZAtOriginAxis(gp_Pnt(0.0, 0.0, 0.0), zAxis);
			gp_Pnt firstWirePntLocal = firstWirePnt.Rotated(rotateAboutZAtOriginAxis, 0.08726646); // Perturb the starting point by a 5deg CCW rotation

			distVar1 = 100000;
			pntCount2 = 0;
			for (gp_Pnt &pntIter1 : localPntArr)
			{
				Standard_Real curDist = pntIter1.Distance(firstWirePntLocal);
				if (curDist < 0.002)
				{
					startPntIndex = pntCount2;
					distVar1 = curDist;
					closestPnt = pntIter1;
					break;
				}
				else if (curDist < distVar1)
				{
					distVar1 = curDist;
					startPntIndex = pntCount2;
					closestPnt = pntIter1;
				}
				pntCount2++;
			}
		}

		//std::vector<gp_Pnt> localPntArrOrdered;
		pntsInOut.push_back(localPntArr.at(startPntIndex));
		std::vector<int> indicesUsed = { startPntIndex };
		for (int pntIndex = 0; pntIndex < localPntArr.size() - 1; pntIndex++)
		{
			distVar1 = 1000000;
			Standard_Integer nextPntIndex = 0;
			gp_Pnt curPnt = pntsInOut.at(pntIndex);

			Standard_Integer secLoopIndex = 0;
			for (gp_Pnt &pntIter1 : localPntArr) // Searching for next closest point in this loop
			{
				bool pntInArray = false;
				for (int thirdLoopIndex = 0; thirdLoopIndex < indicesUsed.size(); thirdLoopIndex++)
				{
					if (indicesUsed.at(thirdLoopIndex) == secLoopIndex) // Skip the next point if it already is in the array
					{
						pntInArray = true;
						break;
					}
				}

				if (pntInArray) // Skip the point if it already is in the ordered array
				{
					secLoopIndex++;
					continue;
				}

				Standard_Real curDist = pntIter1.Distance(curPnt);
				if (curDist < distVar1)
				{
					distVar1 = curDist;
					nextPntIndex = secLoopIndex; // Next one to be added will be the next closest point
				}
				secLoopIndex++;
			}
			pntsInOut.push_back(localPntArr.at(nextPntIndex));
			indicesUsed.push_back(nextPntIndex);
		}

		pntsInOut.push_back(pntsInOut.front()); // Make the contour fully closed in the new location
	}

    void amplWireIntersection::setDiscretizedPntsDirection(pointsXYDirection direction, std::vector<gp_Pnt> &pntsInOut)
	{
		if (pntsInOut.size() < 2)
			return;

		bool formingNegZDirection = true;
		if ((pntsInOut.back()).Z() > (pntsInOut.front()).Z())
			formingNegZDirection = false;

		Standard_Integer arrSize = pntsInOut.size();
		pointsXYDirection curDir = pointsXYDirection::CCW;
		gp_Dir posZDir(0.0, 0.0, 1.0);

		Standard_Real angleCount = 0.0;
		for (int m = 1; m < pntsInOut.size() - 1; m++)
		{
			gp_Pnt pnt_mmo = pntsInOut.at(m - 1);
			gp_Pnt pnt_m = pntsInOut.at(m);
			gp_Pnt pnt_mpo = pntsInOut.at(m + 1);

			if ((pnt_mmo.Distance(pnt_m) < 0.002) || (pnt_m.Distance(pnt_mpo) < 0.002))
				continue;

			gp_Dir lastDir(pnt_m.X() - pnt_mmo.X(), pnt_m.Y() - pnt_mmo.Y(), pnt_m.Z() - pnt_mmo.Z());
			gp_Dir nextDir(pnt_mpo.X() - pnt_m.X(), pnt_mpo.Y() - pnt_m.Y(), pnt_mpo.Z() - pnt_m.Z());

			Standard_Real curRelAngleRad;
			if (lastDir.IsParallel(posZDir, 0.002) || nextDir.IsParallel(posZDir, 0.002))
				continue;

			curRelAngleRad = lastDir.AngleWithRef(nextDir, posZDir); // -Pi to Pi; If > 0 then CCW, and If < 0 then CW

			angleCount = angleCount + curRelAngleRad;
		}

		if (angleCount > 0.0)
			curDir = pointsXYDirection::CCW;
		else
			curDir = pointsXYDirection::CW;

		if (curDir != direction)
			std::reverse(pntsInOut.begin(), pntsInOut.end());
	}

	void amplWireIntersection::getCenterOfMass(gp_Pnt &centerOut)
	{
		GProp_GProps LProps;
		TopoDS_Wire wireIntersect;
		toOccWire(wireIntersect);
		BRepGProp::LinearProperties(wireIntersect, LProps);
		centerOut = LProps.CentreOfMass();
	}

	void amplWireIntersection::getWireLength(Standard_Real &distOut)
	{
		size_t numEdgesInWire = getSizeEdgeArray();
		Standard_Real currentDistance = 0;
		for (size_t edgeIndexLocal = 0; edgeIndexLocal < numEdgesInWire; edgeIndexLocal++)
		{
			TopoDS_Edge localEdge;
			getEdge(edgeIndexLocal, localEdge);

			Standard_Real edgeU1, edgeU2; // Get the edge into geometric form and all of its properties
			gp_Pnt localPntFirst, localPntLast;
			Handle(Geom_Curve) curveLocal = BRep_Tool::Curve(localEdge, edgeU1, edgeU2);
			Handle(Standard_Type) curveType = curveLocal->DynamicType();
			GeomAdaptor_Curve edgeAdaptorCurve(curveLocal, edgeU1, edgeU2);
			getOrderedEdgePnts(edgeIndexLocal, localPntFirst, localPntLast);
			Standard_Real edgeLen = GCPnts_AbscissaPoint::Length(edgeAdaptorCurve, edgeU1, edgeU2, 0.001);
			currentDistance = currentDistance + edgeLen;
		}

		distOut = currentDistance;
	}
}