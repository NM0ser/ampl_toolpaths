#include "stdafx.h"
#include "planeIntersecter.h"

namespace ampl
{
	planeIntersecter::planeIntersecter(const TopoDS_Shape &S1, const TopoDS_Shape &S2)
	{
		sectionBuilder = new BRepAlgoAPI_Section();
		sectionBuilder->Init1(S1);
		sectionBuilder->Init2(S2);
		shellPart = S1;
		myEdgeToEdgeTol = 0.005;
	}

	planeIntersecter::planeIntersecter(const TopoDS_Shape &S1, const gp_Pln &Pl)
	{
		sectionBuilder = new BRepAlgoAPI_Section();
		sectionBuilder->Init1(S1);
		sectionBuilder->Init2(Pl);
		shellPart = S1;
		myEdgeToEdgeTol = 0.005;
	}

	planeIntersecter::~planeIntersecter()
	{
		delete sectionBuilder;
		sectionBuilder = nullptr;
	}

	void planeIntersecter::init(const TopoDS_Shape &S1, const TopoDS_Shape &S2) // Initializing deletes existing objects
	{
		if (sectionBuilder == nullptr)
		{
			sectionBuilder = new BRepAlgoAPI_Section();
		}
		else
		{
			delete sectionBuilder;
			sectionBuilder = nullptr;
			sectionBuilder = new BRepAlgoAPI_Section();
		}

		intersectSuccess = false;
		myEdgeToEdgeTol = 0.005;
		message = "";
		sectionBuilder->Init1(S1);
		sectionBuilder->Init2(S2);
		shellPart = S1;
		intersectShape.Nullify();
		wireArr = {};
	}

	void planeIntersecter::init(const TopoDS_Shape &S1, const gp_Pln &Pl) // Initializing deletes existing objects
	{
		if (sectionBuilder == nullptr)
		{
			sectionBuilder = new BRepAlgoAPI_Section();
		}
		else
		{
			delete sectionBuilder;
			sectionBuilder = nullptr;
			sectionBuilder = new BRepAlgoAPI_Section();
		}

		intersectSuccess = false;
		myEdgeToEdgeTol = 0.005;
		message = "";
		sectionBuilder->Init1(S1);
		sectionBuilder->Init2(Pl);
		shellPart = S1;
		intersectShape.Nullify();
		wireArr = {};
	}

	bool planeIntersecter::performIntersect(void)
	{
		sectionBuilder->SetRunParallel(true);
		//sectionBuilder->SetFuzzyValue(0.002);
		sectionBuilder->Build();
		if (sectionBuilder->IsDone())
		{
			intersectShape = sectionBuilder->Shape();
			TopExp_Explorer explorer1Edge;
			Standard_Integer edgeCount = 0;
			for (explorer1Edge.Init(intersectShape, TopAbs_ShapeEnum::TopAbs_EDGE); explorer1Edge.More(); explorer1Edge.Next())
			{
				edgeCount++;
			}

			if (edgeCount > 0)
			{
				intersectSuccess = true;
				return true;
			}
			else
			{
				intersectSuccess = false;
				//message = "ERROR: Failed to perform intersection. Double-check that the part does not contain self-intersecting geometry and that the input heights are correct.\n";
				return false;
			}
		}
		else
		{
			intersectSuccess = false;
			//message = "ERROR: Failed to perform intersection. Double-check that the part does not contain self-intersecting geometry and that the input heights are correct.\n";
			return false;
		}
	}

	void planeIntersecter::getUnsortedIntersection(TopoDS_Shape &S1)
	{
		S1 = intersectShape;
	}

	void planeIntersecter::setEdgeToEdgeTol(Standard_Real edgeToEdgeTol)
	{
		myEdgeToEdgeTol = edgeToEdgeTol;
		//sectionBuilder->SetFuzzyValue(edgeToEdgeTol);
		//sectionBuilder->Approximation(true);
	}

	Standard_Real planeIntersecter::getEdgeToEdgeTol(void)
	{
		return myEdgeToEdgeTol;
	}

	void planeIntersecter::resetWireArray(void)
	{
		wireArr.clear();
	}

	void planeIntersecter::getWireLength(Standard_Integer intersectIndex, Standard_Real &wireLength)
	{
		if (intersectIndex >= wireArr.size() || intersectIndex < 0)
		{
			return;
		}

		(wireArr.at(intersectIndex)).getWireLength(wireLength);
	}

	bool planeIntersecter::sortIntersection(void)
	{
		Standard_Integer wireIndex = 0;
		TopExp_Explorer explorer1Edge;
		TopExp_Explorer explorer2Edge;
		Standard_Integer explorer1Count = 0;

		bool keepSearchingEdges = true;
		bool foundCoincidentEdge = true;
		explorer1Edge.Init(intersectShape, TopAbs_ShapeEnum::TopAbs_EDGE); 
		while(keepSearchingEdges)
		{
			TopoDS_Edge currentEdge;
			Standard_Integer currentEdgeIndex;
			TopoDS_Edge nextEdge;

			if (explorer1Count == 0)
			{
				wireArr.push_back(amplWireIntersection());

				currentEdge = TopoDS::Edge(explorer1Edge.Current());

				Standard_Real curve1U1, curve1U2;
				Handle(Geom_Curve) currentCurve = BRep_Tool::Curve(currentEdge, curve1U1, curve1U2);
				if (curve1U1 == RealFirst() || curve1U2 == RealFirst())
				{
					message = "ERROR: One of the curves in an intersection was found to be infinite.\n";
					return false;
				}
				gp_Pnt pntCurve1U1, pntCurve1U2;
				pntCurve1U1 = currentCurve->Value(curve1U1);
				pntCurve1U2 = currentCurve->Value(curve1U2);

				wireArr.at(wireIndex).addEdge(currentEdge, true);
				wireArr.at(wireIndex).addEdgePnts(pntCurve1U1, pntCurve1U2, true);
				wireArr.at(wireIndex).addReverseFlag(false, true);
				currentEdgeIndex = 0;
				explorer1Edge.Next();
			}
			else if (wireArr.at(wireIndex).isClosedContour(myEdgeToEdgeTol) || !foundCoincidentEdge) // There's more than one intersect object needed
			{
				// Find a new edge 
				bool edgeAlreadyUsed = false;
				for (explorer2Edge.Init(intersectShape, TopAbs_ShapeEnum::TopAbs_EDGE); explorer2Edge.More(); explorer2Edge.Next())
				{
					nextEdge = TopoDS::Edge(explorer2Edge.Current());
					edgeAlreadyUsed = false;
					for (amplWireIntersection& amplWireIter : wireArr)
					{
						Standard_Integer repeatIndex = -1; // Will be the index of the edge if it is already in the wire being built
						edgeAlreadyUsed = amplWireIter.containsEdge(nextEdge, repeatIndex);

						if (edgeAlreadyUsed)
							break;
					}

					if (edgeAlreadyUsed)
						continue;
					else
						break;
				}

				if (edgeAlreadyUsed) 
					return true; // Apparently there really weren't anymore edges to search through...

				wireIndex++;
				wireArr.push_back(amplWireIntersection());

				currentEdge = TopoDS::Edge(explorer2Edge.Current());

				Standard_Real curve1U1, curve1U2;
				Handle(Geom_Curve) currentCurve = BRep_Tool::Curve(currentEdge, curve1U1, curve1U2);
				if (curve1U1 == RealFirst() || curve1U2 == RealFirst())
				{
					message = "ERROR: One of the curves in an intersection was found to be infinite.\n";
					return false;
				}
				gp_Pnt pntCurve1U1, pntCurve1U2;
				pntCurve1U1 = currentCurve->Value(curve1U1);
				pntCurve1U2 = currentCurve->Value(curve1U2);

				wireArr.at(wireIndex).addEdge(currentEdge, true);
				wireArr.at(wireIndex).addEdgePnts(pntCurve1U1, pntCurve1U2, true);
				wireArr.at(wireIndex).addReverseFlag(false, true);
				currentEdgeIndex = 0;
				explorer1Edge.Next();
			}
			else
			{
				wireArr.at(wireIndex).getEdge(currentEdgeIndex, currentEdge); // Get the last edge in the array
			}

			foundCoincidentEdge = false;
			for (explorer2Edge.Init(intersectShape, TopAbs_ShapeEnum::TopAbs_EDGE); explorer2Edge.More(); explorer2Edge.Next())
			{
				nextEdge = TopoDS::Edge(explorer2Edge.Current());

				bool edgeAlreadyUsed = false; // Determine if the edge being checked is already in the wire being built
				for (amplWireIntersection& amplWireIter : wireArr)
				{
					Standard_Integer repeatIndex = -1; // Will be the index of the edge if it is already in the wire being built
					edgeAlreadyUsed = amplWireIter.containsEdge(nextEdge, repeatIndex);

					if (edgeAlreadyUsed)
						break;
				}

				if (edgeAlreadyUsed)
					continue;

				Standard_Real curve2U1, curve2U2;
				Handle(Geom_Curve) nextCurve = BRep_Tool::Curve(nextEdge, curve2U1, curve2U2);
				if (curve2U1 == RealFirst() || curve2U2 == RealFirst())
				{
					message = "ERROR: One of the curves in an intersection was found to be infinite.\n";
					return false;
				}
				gp_Pnt pntCurve0First, pntCurve0Last, pntCurve1First, pntCurve1Last, pntCurve2U1, pntCurve2U2;
				wireArr.at(wireIndex).getOrderedEdgePnts(0, pntCurve0First, pntCurve0Last); // First edge in the wire
				wireArr.at(wireIndex).getOrderedEdgePnts(currentEdgeIndex, pntCurve1First, pntCurve1Last); // Last edge in the wire
				pntCurve2U1 = nextCurve->Value(curve2U1); // Current points on the edge being compared against the ends of the wire
				pntCurve2U2 = nextCurve->Value(curve2U2);

				if (pntCurve1Last.IsEqual(pntCurve2U1, myEdgeToEdgeTol)) // Found a new edge that connects to the last edge
				{
					wireArr.at(wireIndex).addEdge(nextEdge, true);
					wireArr.at(wireIndex).addEdgePnts(pntCurve2U1, pntCurve2U2, true); // U1 on the left, U2 on the right
					wireArr.at(wireIndex).addReverseFlag(false, true);
					foundCoincidentEdge = true;
					currentEdgeIndex++;
					explorer1Edge.Next();
					break;
				}
				else if (pntCurve1Last.IsEqual(pntCurve2U2, myEdgeToEdgeTol)) // Found a new edge that connects to the last edge, but needs to be reversed
				{
					wireArr.at(wireIndex).addEdge(nextEdge, true);
					wireArr.at(wireIndex).addEdgePnts(pntCurve2U1, pntCurve2U2, true); // U1 on the left, U2 on the right, add a reverse flag
					wireArr.at(wireIndex).addReverseFlag(true, true);
					foundCoincidentEdge = true;
					currentEdgeIndex++;
					explorer1Edge.Next();
					break;
				}
				else if (pntCurve0First.IsEqual(pntCurve2U2, myEdgeToEdgeTol)) // Found a new edge that connects to the first edge
				{
					wireArr.at(wireIndex).addEdge(nextEdge, false);
					wireArr.at(wireIndex).addEdgePnts(pntCurve2U1, pntCurve2U2, false); 
					wireArr.at(wireIndex).addReverseFlag(false, false);
					foundCoincidentEdge = true;
					currentEdgeIndex++;
					explorer1Edge.Next();
					break;
				}
				else if (pntCurve0First.IsEqual(pntCurve2U1, myEdgeToEdgeTol)) // Found a new edge that connects to the first edge, but needs to be reversed
				{
					wireArr.at(wireIndex).addEdge(nextEdge, false);
					wireArr.at(wireIndex).addEdgePnts(pntCurve2U1, pntCurve2U2, false);
					wireArr.at(wireIndex).addReverseFlag(true, false);
					foundCoincidentEdge = true;
					currentEdgeIndex++;
					explorer1Edge.Next();
					break;
				}
			}

			if (explorer1Edge.More()) // false when at the end of the container of edges
			{
				explorer1Count++;
			}
			else
			{
				keepSearchingEdges = false;
			}
		}

		return true;
	}

	void planeIntersecter::getNumClosedWires(Standard_Integer &numContours, std::vector<int> &intersectIndices)
	{
		numContours = 0;
		std::vector<int> localVecIndices;
		int indexCounter = 0;
		for (amplWireIntersection& amplWireIter : wireArr)
		{
			if (amplWireIter.isClosedContour(myEdgeToEdgeTol))
			{
				numContours++;
				localVecIndices.push_back(indexCounter);
			}

			indexCounter++;
		}

		intersectIndices = localVecIndices;
	}

	void planeIntersecter::getNumWires(Standard_Integer &numContours)
	{
		numContours = wireArr.size();
	}

	void planeIntersecter::getWireIntersection(Standard_Integer intersectIndex, amplWireIntersection &wireOut)
	{
		if (intersectIndex < wireArr.size() && intersectIndex >= 0)
		{
			wireOut.copy(wireArr.at(intersectIndex));
		}
	}

	bool planeIntersecter::isIntersectClosed(Standard_Integer intersectIndex)
	{
		if (intersectIndex < wireArr.size() && intersectIndex >= 0)
		{
			return wireArr.at(intersectIndex).isClosedContour(myEdgeToEdgeTol);
		}
		else
		{
			return false;
		}
	}

	void planeIntersecter::toOcctWire(Standard_Integer intersectIndex, TopoDS_Wire &wireOut)
	{
		if (intersectIndex < wireArr.size() && intersectIndex >= 0)
		{
			(wireArr.at(intersectIndex)).toOccWire(wireOut);
		}
	}

	void planeIntersecter::discretizeIntersection(Standard_Integer intersectIndex, Standard_Real stepDist, std::vector<gp_Pnt> &pntsOut)
	{
		if (intersectIndex < wireArr.size() && intersectIndex >= 0)
		{
			gp_Pnt firstWirePnt, tempPnt;
			(wireArr.at(intersectIndex)).getOrderedEdgePnts(0, firstWirePnt, tempPnt);
			(wireArr.at(intersectIndex)).discretizeWire(stepDist, myEdgeToEdgeTol, pntsOut);
			//(wireArr.at(intersectIndex)).sequentialSortDiscretizedPnts(firstWirePnt, pntsOut);
		}
	}

	void planeIntersecter::discretizeIntersection(Standard_Integer intersectIndex, Standard_Real stepDist, const gp_Pnt startPnt, amplWireIntersection::pointsXYDirection direction, std::vector<gp_Pnt> &pntsOut)
	{
		if (intersectIndex < wireArr.size() && intersectIndex >= 0)
		{
			(wireArr.at(intersectIndex)).discretizeWire(stepDist, myEdgeToEdgeTol, pntsOut);
			(wireArr.at(intersectIndex)).sequentialSortDiscretizedPnts(startPnt, pntsOut);
			(wireArr.at(intersectIndex)).setDiscretizedPntsDirection(direction, pntsOut);
		}
	}

	void planeIntersecter::orderDiscretization(const gp_Pnt startPnt, amplWireIntersection::pointsXYDirection direction, std::vector<gp_Pnt> &pntsInOut)
	{
		amplWireIntersection::sequentialSortDiscretizedPnts(startPnt, pntsInOut);
		amplWireIntersection::setDiscretizedPntsDirection(direction, pntsInOut);
	}

	void planeIntersecter::getCenterOfMass(Standard_Integer intersectIndex, gp_Pnt &centOfMass)
	{
		if (intersectIndex < wireArr.size() && intersectIndex >= 0)
		{
			(wireArr.at(intersectIndex)).getCenterOfMass(centOfMass);
		}
	}

	void planeIntersecter::getMaxDistFromPoint(Standard_Integer intersectIndex, const gp_Pnt &pntIn, Standard_Real &maxXYDist)
	{
		if (intersectIndex < wireArr.size() && intersectIndex >= 0)
		{
			std::vector<gp_Pnt> localPntsArr;
			Standard_Real wireLen;
			(wireArr.at(intersectIndex)).getWireLength(wireLen);

			if(wireLen/100.0 >= 0.5)
				discretizeIntersection(intersectIndex, 0.5, localPntsArr);
			else
				discretizeIntersection(intersectIndex, wireLen/100.0, localPntsArr);

			Standard_Real distVar1 = 0;
			for (int pntIndex = 0; pntIndex < localPntsArr.size(); pntIndex++)
			{
				Standard_Real curDist = (localPntsArr.at(pntIndex)).Distance(pntIn);
				if (curDist > distVar1)
					distVar1 = curDist;
			}

			maxXYDist = distVar1;
		}
	}

	void planeIntersecter::getAllSurfProps(const std::vector<gp_Pnt> &discretizedPntsIn, const gp_Pnt &centOfMass, const bool vectPointPosZ, std::vector<gp_Vec> &normalsOut,
		std::vector<float> &kappaMax, std::vector<gp_Vec> &kappaMaxDirection, std::vector<float> &kappaMin, std::vector<gp_Vec> &kappaMinDirection,
		std::vector<float> &kappaMean, std::vector<float> &kappaGaussian)
	{
		normalsOut.clear();
		kappaMax.clear();
		kappaMaxDirection.clear();
		kappaMin.clear();
		kappaMinDirection.clear();
		kappaMean.clear();
		kappaGaussian.clear();

		TopoDS_Face closestFace;
		Handle(Geom_Surface) closestSurf = nullptr;
		int closestSurfIndex;
		for (int pntIndex = 0; pntIndex < discretizedPntsIn.size(); pntIndex++)
		{
			gp_Pnt currentPnt = discretizedPntsIn.at(pntIndex);
			gp_Pnt closestProjPnt;
			Standard_Real pntOnSurfU1, pntOnSurfV1;

			if (!closestSurf.IsNull()) // Try to use last known surface first
			{
				Handle(Geom_Surface) currentSurf = closestSurf;
				Standard_Real pntU1, pntV1;
				//gp_Pnt closestProjPnt;
				bool neededCatch = false;

				GeomAPI_ProjectPointOnSurf pntProjectionBuilder(currentPnt, currentSurf, 0.002);
				if (pntProjectionBuilder.IsDone())
				{
					pntProjectionBuilder.LowerDistanceParameters(pntU1, pntV1);
					closestProjPnt = pntProjectionBuilder.NearestPoint(); // currentSurf->Value(pntU1, pntV1);
				}
				else
				{
					neededCatch = true;
					findPointParamOnSurf(shellPart, currentPnt, closestSurf, closestProjPnt, pntOnSurfU1, pntOnSurfV1);
				}

				if (!neededCatch)
				{
					Standard_Real curDist = currentPnt.Distance(closestProjPnt);
					if (curDist <= 0.002)
					{
						closestSurf = currentSurf;
						pntOnSurfU1 = pntU1;
						pntOnSurfV1 = pntV1;
					}
					else
						findPointParamOnSurf(shellPart, currentPnt, closestSurf, closestProjPnt, pntOnSurfU1, pntOnSurfV1);
				}
			}
			else
				findPointParamOnSurf(shellPart, currentPnt, closestSurf, closestProjPnt, pntOnSurfU1, pntOnSurfV1);

			GeomLProp_SLProps closestSurfProps(closestSurf, pntOnSurfU1, pntOnSurfV1, 1, 0.002);
			
			if (!closestSurfProps.IsNormalDefined())
			{
				normalsOut.push_back(gp_Vec(0, 0, 1));
			}
			else
			{
				gp_Dir surfNormalDir;
				surfNormalDir = closestSurfProps.Normal();
				gp_Vec surfNormalVec(surfNormalDir);

				bool currentVecPointsPosZ = false;
				if (abs(surfNormalVec.Z()) <= 0.001) // Implies that the wall angle is 90deg
				{
					gp_Vec vecCOM(closestProjPnt, centOfMass); // Point the vector towards the CoM, but may not be desired
					vecCOM.Normalize();
					Standard_Real relativeAngle = vecCOM.Angle(surfNormalVec);

					if (abs(relativeAngle) > 3.14159265358979323846 / 2.0)
						surfNormalVec.Reverse();

					normalsOut.push_back(surfNormalVec);
				}
				else
				{
					if (surfNormalVec.Z() > 0)
						currentVecPointsPosZ = true;

					if (currentVecPointsPosZ != vectPointPosZ)
						surfNormalVec.Reverse();

					normalsOut.push_back(surfNormalVec);
				}
			}

			if (!closestSurfProps.IsCurvatureDefined())
			{
				kappaMax.push_back(0.0);
				kappaMin.push_back(0.0);
				kappaMean.push_back(0.0);
				kappaGaussian.push_back(0.0);
				kappaMaxDirection.push_back(normalsOut.back());
				kappaMinDirection.push_back(normalsOut.back());
			}
			else
			{
				kappaMax.push_back(closestSurfProps.MaxCurvature());
				kappaMin.push_back(closestSurfProps.MinCurvature());
				kappaMean.push_back(closestSurfProps.MeanCurvature());
				kappaGaussian.push_back(closestSurfProps.GaussianCurvature());

				gp_Dir kappaMaxDir, kappaMinDir;
				closestSurfProps.CurvatureDirections(kappaMaxDir, kappaMinDir);
				gp_Vec kappaMaxVector(kappaMaxDir);
				gp_Vec kappaMinVector(kappaMinDir);
				
				kappaMaxDirection.push_back(kappaMaxVector);
				kappaMinDirection.push_back(kappaMinVector);
			}
		}
	}

	void planeIntersecter::getAllProjectedPntsOnSurfAlongVec(const TopoDS_Shape &shellPartIn, const std::vector<gp_Pnt> &discretizedPntsIn, std::vector<gp_Pnt> &projPntsOut)
	{
		TopoDS_Face closestFace;
		Handle(Geom_Surface) closestSurf = nullptr;
		int closestSurfIndex;
		for (int pntIndex = 0; pntIndex < discretizedPntsIn.size(); pntIndex++)
		{
			gp_Pnt currentPnt = discretizedPntsIn.at(pntIndex);
			gp_Pnt closestProjPnt;
			Standard_Real pntOnSurfU1, pntOnSurfV1;

			if (!closestSurf.IsNull()) // Try to use last known surface first
			{
				Standard_Real surfBoundU1, surfBoundU2, surfBoundV1, surfBoundV2;
				Handle(Geom_Surface) currentSurf = closestSurf;
				Standard_Real pntU1, pntV1;
				currentSurf->Bounds(surfBoundU1, surfBoundU2, surfBoundV1, surfBoundV2);
				//gp_Pnt closestProjPnt;
				bool neededCatch = false;

				GeomAPI_ProjectPointOnSurf pntProjectionBuilder(currentPnt, currentSurf, surfBoundU1, surfBoundU2, surfBoundV1, surfBoundV2, 0.002);
				if (pntProjectionBuilder.IsDone())
				{
					pntProjectionBuilder.LowerDistanceParameters(pntU1, pntV1);
					closestProjPnt = pntProjectionBuilder.NearestPoint(); //currentSurf->Value(pntU1, pntV1);//
				}
				else
				{
					neededCatch = true;
					findPointParamOnSurf(shellPartIn, currentPnt, closestSurf, closestProjPnt, pntOnSurfU1, pntOnSurfV1);
				}

				if (!neededCatch)
				{
					Standard_Real curDist = currentPnt.Distance(closestProjPnt);
					if (curDist <= 0.002)
					{
						closestSurf = currentSurf;
						pntOnSurfU1 = pntU1;
						pntOnSurfV1 = pntV1;
					}
					else
						findPointParamOnSurf(shellPartIn, currentPnt, closestSurf, closestProjPnt, pntOnSurfU1, pntOnSurfV1);
				}
			}
			else
				findPointParamOnSurf(shellPartIn, currentPnt, closestSurf, closestProjPnt, pntOnSurfU1, pntOnSurfV1);

			projPntsOut.push_back(closestProjPnt);
		}
	}

    void planeIntersecter::getAllIntersectPntsOnSurfAlongVec(const TopoDS_Shape &shellPartIn, const std::vector<gp_Pnt> &discretizedPntsIn, const std::vector<gp_Vec> &pntNormalsIn, std::vector<gp_Pnt> &projPntsOut)
	{
		projPntsOut.clear();

		for (int pntIndex = 0; pntIndex < discretizedPntsIn.size(); pntIndex++)
		{
			gp_Pnt currentPnt = discretizedPntsIn.at(pntIndex);
			gp_Pnt closestProjPnt;
			gp_Vec currentVec = pntNormalsIn.at(pntIndex);
			Handle(Geom_Line) currentLine = GC_MakeLine(currentPnt, gp_Dir(currentVec));
			TopoDS_Edge currentIntersectEdge = BRepBuilderAPI_MakeEdge(currentLine, -10000, 10000);

			//BRepAlgoAPI_Section sectionBuilder(shellPartIn, currentIntersectEdge);
			BRepAlgoAPI_Section sectionBuilder;
			sectionBuilder.Init1(shellPartIn);
			sectionBuilder.Init2(currentIntersectEdge);
			sectionBuilder.SetRunParallel(true);
			sectionBuilder.SetFuzzyValue(0.005);
			sectionBuilder.Approximation(true);
			sectionBuilder.SetOperation(BOPAlgo_Operation::BOPAlgo_SECTION);
			sectionBuilder.Build();

			if (!sectionBuilder.IsDone())
				continue;

			TopoDS_Shape intersectShape = sectionBuilder.Shape();
			TopExp_Explorer explorer1Vertex(intersectShape, TopAbs_ShapeEnum::TopAbs_VERTEX);

			if (!explorer1Vertex.More())
				continue;

			float minIntersectPntDist = 1000000;
			for (; explorer1Vertex.More(); explorer1Vertex.Next())
			{
				TopoDS_Vertex currentIntersectVertex = TopoDS::Vertex(explorer1Vertex.Current());
				gp_Pnt currentIntersectPnt = BRep_Tool::Pnt(currentIntersectVertex);
				float currentIntersectDist = currentIntersectPnt.Distance(currentPnt);

				if (currentIntersectDist < minIntersectPntDist)
				{
					minIntersectPntDist = currentIntersectDist;
					closestProjPnt = currentIntersectPnt;
				}
			}

			projPntsOut.push_back(closestProjPnt);
		}
	}

	void planeIntersecter::findPointParamOnSurf(const TopoDS_Shape &shellPartIn, const gp_Pnt &pntIn, Handle(Geom_Surface) &surfOut, gp_Pnt &closestProjPntOut, Standard_Real &paramU1Out, Standard_Real &paramU2Out)
	{
		TopExp_Explorer explorer1Face;
		gp_Pnt projectedPnt;
		gp_Pnt currentPntOnSurf;
		Standard_Real pntOnSurfU1, pntOnSurfU2;
		TopoDS_Face closestFace;
		Handle(Geom_Surface) closestSurf = nullptr;
		int closestSurfIndex;
		TopTools_IndexedMapOfShape faceMap;
		TopExp::MapShapes(shellPartIn, TopAbs_FACE, faceMap);
		Standard_Real minDist = 1000000;
		Standard_Integer faceIndex = 0;

		for (explorer1Face.Init(shellPartIn, TopAbs_ShapeEnum::TopAbs_FACE); explorer1Face.More(); explorer1Face.Next())
		{
			Standard_Real surfBoundU1, surfBoundU2, surfBoundV1, surfBoundV2;
			TopoDS_Face currentFace = TopoDS::Face(explorer1Face.Current());
			Handle(Geom_Surface) currentSurf = BRep_Tool::Surface(currentFace);
			currentSurf->Bounds(surfBoundU1, surfBoundU2, surfBoundV1, surfBoundV2);
			Standard_Real pntU1, pntU2;
			gp_Pnt closestProjPnt;

			GeomAPI_ProjectPointOnSurf pntProjectionBuilder(pntIn, currentSurf, surfBoundU1, surfBoundU2, surfBoundV1, surfBoundV2, 0.002);
			if (pntProjectionBuilder.IsDone())
			{
				pntProjectionBuilder.LowerDistanceParameters(pntU1, pntU2);
				closestProjPnt = pntProjectionBuilder.NearestPoint(); //currentSurf->Value(pntU1, pntU2);  gets the point closest to the starting point... not the surface!
			}
			else
			{
				continue;
				faceIndex++;
			}

			Standard_Real curDist = pntIn.Distance(closestProjPnt);

			if (curDist <= 0.002)
			{
				projectedPnt = closestProjPnt;
				closestSurf = currentSurf;
				closestSurfIndex = faceMap.FindIndex(explorer1Face.Current());
				currentPntOnSurf = closestProjPnt;
				pntOnSurfU1 = pntU1;
				pntOnSurfU2 = pntU2;
				break;
			}
			else if (curDist < minDist)
			{
				minDist = curDist;
				projectedPnt = closestProjPnt;
				closestSurf = currentSurf;
				closestSurfIndex = faceMap.FindIndex(explorer1Face.Current());;
				currentPntOnSurf = closestProjPnt;
				pntOnSurfU1 = pntU1;
				pntOnSurfU2 = pntU2;
			}

			faceIndex++;
		}
		closestFace = TopoDS::Face(faceMap(closestSurfIndex));
		surfOut = closestSurf;
		closestProjPntOut = currentPntOnSurf;
		paramU1Out = pntOnSurfU1;
		paramU2Out = pntOnSurfU2;
	}

	void planeIntersecter::findPointParamOnSurfAlongVec(const TopoDS_Shape &shellPartIn, const gp_Pnt &pntIn, const gp_Vec &vecIn, Handle(Geom_Surface) &surfOut, gp_Pnt &closestProjPntOut, Standard_Real &paramU1Out, Standard_Real &paramU2Out)
	{
		closestProjPntOut = gp_Pnt(0.0, 0.0, 0.0);
		TopExp_Explorer explorer1Face;
		gp_Pnt currentPntOnSurf;
		Standard_Real pntOnSurfU1, pntOnSurfU2;
		gp_Vec currentVec = vecIn;
		if (currentVec.Magnitude() < 0.002)
			currentVec = gp_Vec(0.0, 0.0, 1.0);
		Handle(Geom_Line) currentLine = GC_MakeLine(pntIn, gp_Dir(currentVec));
		TopoDS_Face closestFace;
		Handle(Geom_Surface) closestSurf = nullptr;
		int closestSurfIndex;
		TopTools_IndexedMapOfShape faceMap;
		TopExp::MapShapes(shellPartIn, TopAbs_FACE, faceMap);
		Standard_Real minDist = 1000000;
		Standard_Integer faceIndex = 0;

		for (explorer1Face.Init(shellPartIn, TopAbs_ShapeEnum::TopAbs_FACE); explorer1Face.More(); explorer1Face.Next())
		{
			Standard_Real surfBoundU1, surfBoundU2, surfBoundV1, surfBoundV2;
			TopoDS_Face currentFace = TopoDS::Face(explorer1Face.Current());
			Handle(Geom_Surface) currentSurf = BRep_Tool::Surface(currentFace);
			currentSurf->Bounds(surfBoundU1, surfBoundU2, surfBoundV1, surfBoundV2);
			
			Standard_Real surfU1, surfV1, lineW1;
			gp_Pnt closestProjPnt;
			Standard_Integer closestProjPntIndex = 1;
			Standard_Real curDist;

			GeomAPI_IntCS pntIntersectBuilder(currentLine, currentSurf);
			if (pntIntersectBuilder.IsDone()) // If intersection was successful
			{
				Standard_Integer numPoints = pntIntersectBuilder.NbPoints();
				Standard_Real closestIntersectPntDist = 1000000;
				for (int ni = 1; ni <= numPoints; ni++) // Grab the closest intersection point to the original point
				{
					gp_Pnt currentIntersectPnt = pntIntersectBuilder.Point(ni);
					Standard_Real currentIntersectPntDist = currentIntersectPnt.Distance(pntIn);
					Standard_Real tempPntParmU, tempSurfBoundV, tempLineBoundW;
					pntIntersectBuilder.Parameters(ni, tempPntParmU, tempSurfBoundV, tempLineBoundW);

					if ((tempPntParmU < surfBoundU1) || (tempPntParmU > surfBoundU2) || (tempSurfBoundV < surfBoundV1) || (tempSurfBoundV > surfBoundV2))
						continue;

					if (currentIntersectPntDist < closestIntersectPntDist)
					{
						closestIntersectPntDist = currentIntersectPntDist;
						closestProjPnt = currentIntersectPnt;
						closestProjPntIndex = ni;
						curDist = currentIntersectPntDist;
						pntIntersectBuilder.Parameters(ni, surfU1, surfV1, lineW1);
					}
				}

				if (curDist <= 0.002)
				{
					closestSurf = currentSurf;
					closestSurfIndex = faceMap.FindIndex(explorer1Face.Current());
					currentPntOnSurf = closestProjPnt;
					pntOnSurfU1 = surfU1;
					pntOnSurfU2 = surfV1;
					break;
				}
				else if (curDist < minDist)
				{
					minDist = curDist;
					closestSurf = currentSurf;
					closestSurfIndex = faceMap.FindIndex(explorer1Face.Current());;
					currentPntOnSurf = closestProjPnt;
					pntOnSurfU1 = surfU1;
					pntOnSurfU2 = surfV1;
				}

				faceIndex++;
			}
			else
			{
				faceIndex++;
				continue;
			}
		}
		closestFace = TopoDS::Face(faceMap(closestSurfIndex));
		surfOut = closestSurf;
		closestProjPntOut = currentPntOnSurf;
		paramU1Out = pntOnSurfU1;
		paramU2Out = pntOnSurfU2;
	}

	void planeIntersecter::getSurfProp(const gp_Pnt &discretizedPntIn, const gp_Pnt &centOfMass, const bool vectPointPosZ, gp_Vec &normalOut,
		float &kappaMax, gp_Vec &kappaMaxDirection, float &kappaMin, gp_Vec &kappaMinDirection, float &kappaMean, float &kappaGaussian)
	{
		std::vector<gp_Pnt> tempPntVecIn = { discretizedPntIn };
		std::vector<gp_Vec> tempPntVecOut;
		std::vector<float> tempKappaMaxOut;
		std::vector<gp_Vec> tempKappaMaxDirectionOut;
		std::vector<float> tempKappaMinOut;
		std::vector<gp_Vec> tempKappaMinDirectionOut;
		std::vector<float> tempKappaMeanOut;
		std::vector<float> tempKappaGaussianOut;

		getAllSurfProps(tempPntVecIn, centOfMass, vectPointPosZ, tempPntVecOut, tempKappaMaxOut, tempKappaMaxDirectionOut, tempKappaMinOut,
			tempKappaMinDirectionOut, tempKappaMeanOut, tempKappaGaussianOut);
		
		normalOut = tempPntVecOut.front();
		kappaMax = tempKappaMaxOut.front();
		kappaMaxDirection = tempKappaMaxDirectionOut.front();
		kappaMin = tempKappaMinOut.front();
		kappaMinDirection = tempKappaMinDirectionOut.front();
		kappaMean = tempKappaMeanOut.front();
		kappaGaussian = tempKappaGaussianOut.front();
	}

	void planeIntersecter::findDiscretePntByWirePercent(const Standard_Real &decimalPercentIn, const std::vector<gp_Pnt> &pntsIn, const Standard_Real intersectLength, const std::vector<float> &distOfAllPntsIn, gp_Pnt &pntOut)
	{
		Standard_Real decimalPercent = decimalPercentIn;

		if (decimalPercent > 1.0)
			decimalPercent = 1.0;
		else if (decimalPercent < 0)
			decimalPercent = 0.0;
		else if (pntsIn.empty())
		{
			pntOut = gp_Pnt(0.0, 0.0, 0.0);
			return;
		}
		else if (distOfAllPntsIn.size() != pntsIn.size())
		{
			pntOut = pntsIn.front();
			return;
		}

		float intersectDistGoal = decimalPercentIn*intersectLength;
		if (abs(intersectDistGoal) < 0.010)
		{
			pntOut = pntsIn.front();
			return;
		}
		else if (abs(intersectDistGoal - intersectLength) < 0.010)
		{
			pntOut = pntsIn.back();
			return;
		}

		gp_Pnt aheadPnt, behindPnt;
		float behindDist, aheadDist;
		for (int pntIndex = 1; pntIndex < pntsIn.size(); pntIndex++)
		{
			behindPnt = pntsIn.at(pntIndex - 1);
			aheadPnt = pntsIn.at(pntIndex);
			behindDist = distOfAllPntsIn.at(pntIndex - 1);
			aheadDist = distOfAllPntsIn.at(pntIndex);

			if (behindPnt.Distance(aheadPnt) < 0.0005)
				continue;

			if (abs(aheadDist - intersectDistGoal) < 0.010)
			{
				pntOut = aheadPnt;
				return;
			}

			if ((aheadDist > intersectDistGoal) && (behindDist < intersectDistGoal))
				break;
		}

		gp_Vec diffVec(behindPnt, aheadPnt);
		float diffVecMag = diffVec.Magnitude();
		float diffDist = intersectDistGoal - behindDist;
		diffVec.Scale(diffDist / diffVecMag);

		gp_Pnt pntInterp(behindPnt.X() + diffVec.X(), behindPnt.Y() + diffVec.Y(), behindPnt.Z() + diffVec.Z());
		pntOut = pntInterp;
	}

	void planeIntersecter::getAllSurfProps(const TopoDS_Shape &shellPartIn, const std::vector<gp_Pnt> &discretizedPntsIn, const gp_Pnt &centOfMass, const bool vectPointPosZ, std::vector<gp_Vec> &normalsOut,
		std::vector<float> &kappaMax, std::vector<gp_Vec> &kappaMaxDirection, std::vector<float> &kappaMin, std::vector<gp_Vec> &kappaMinDirection, std::vector<float> &kappaMean, std::vector<float> &kappaGaussian)
	{
		normalsOut.clear();
		kappaMax.clear();
		kappaMaxDirection.clear();
		kappaMin.clear();
		kappaMinDirection.clear();
		kappaMean.clear();
		kappaGaussian.clear();

		TopoDS_Face closestFace;
		Handle(Geom_Surface) closestSurf = nullptr;
		int closestSurfIndex;
		for (int pntIndex = 0; pntIndex < discretizedPntsIn.size(); pntIndex++)
		{
			gp_Pnt currentPnt = discretizedPntsIn.at(pntIndex);
			gp_Pnt closestProjPnt;
			Standard_Real pntOnSurfU1, pntOnSurfV1;

			if (!closestSurf.IsNull()) // Try to use last known surface first
			{
				Handle(Geom_Surface) currentSurf = closestSurf;
				Standard_Real pntU1, pntV1;
				//gp_Pnt closestProjPnt;
				bool neededCatch = false;

				GeomAPI_ProjectPointOnSurf pntProjectionBuilder(currentPnt, currentSurf, 0.002);
				if (pntProjectionBuilder.IsDone())
				{
					pntProjectionBuilder.LowerDistanceParameters(pntU1, pntV1);
					closestProjPnt = pntProjectionBuilder.NearestPoint(); // currentSurf->Value(pntU1, pntV1);
				}
				else
				{
					neededCatch = true;
					ampl::planeIntersecter::findPointParamOnSurf(shellPartIn, currentPnt, closestSurf, closestProjPnt, pntOnSurfU1, pntOnSurfV1);
				}

				if (!neededCatch)
				{
					Standard_Real curDist = currentPnt.Distance(closestProjPnt);
					if (curDist <= 0.002)
					{
						closestSurf = currentSurf;
						pntOnSurfU1 = pntU1;
						pntOnSurfV1 = pntV1;
					}
					else
						ampl::planeIntersecter::findPointParamOnSurf(shellPartIn, currentPnt, closestSurf, closestProjPnt, pntOnSurfU1, pntOnSurfV1);
				}
			}
			else
				ampl::planeIntersecter::findPointParamOnSurf(shellPartIn, currentPnt, closestSurf, closestProjPnt, pntOnSurfU1, pntOnSurfV1);

			GeomLProp_SLProps closestSurfProps(closestSurf, pntOnSurfU1, pntOnSurfV1, 1, 0.002);

			if (!closestSurfProps.IsNormalDefined())
			{
				normalsOut.push_back(gp_Vec(0, 0, 1));
			}
			else
			{
				gp_Dir surfNormalDir;
				surfNormalDir = closestSurfProps.Normal();
				gp_Vec surfNormalVec(surfNormalDir);

				bool currentVecPointsPosZ = false;
				if (abs(surfNormalVec.Z()) <= 0.001) // Implies that the wall angle is 90deg
				{
					gp_Vec vecCOM(closestProjPnt, centOfMass); // Point the vector towards the CoM, but may not be desired
					vecCOM.Normalize();
					Standard_Real relativeAngle = vecCOM.Angle(surfNormalVec);

					if (abs(relativeAngle) > 3.14159265358979323846 / 2.0)
						surfNormalVec.Reverse();

					normalsOut.push_back(surfNormalVec);
				}
				else
				{
					if (surfNormalVec.Z() > 0)
						currentVecPointsPosZ = true;

					if (currentVecPointsPosZ != vectPointPosZ)
						surfNormalVec.Reverse();

					normalsOut.push_back(surfNormalVec);
				}
			}

			if (!closestSurfProps.IsCurvatureDefined())
			{
				kappaMax.push_back(0.0);
				kappaMin.push_back(0.0);
				kappaMean.push_back(0.0);
				kappaGaussian.push_back(0.0);
				kappaMaxDirection.push_back(normalsOut.back());
				kappaMinDirection.push_back(normalsOut.back());
			}
			else
			{
				kappaMax.push_back(closestSurfProps.MaxCurvature());
				kappaMin.push_back(closestSurfProps.MinCurvature());
				kappaMean.push_back(closestSurfProps.MeanCurvature());
				kappaGaussian.push_back(closestSurfProps.GaussianCurvature());

				gp_Dir kappaMaxDir, kappaMinDir;
				closestSurfProps.CurvatureDirections(kappaMaxDir, kappaMinDir);
				gp_Vec kappaMaxVector(kappaMaxDir);
				gp_Vec kappaMinVector(kappaMinDir);

				kappaMaxDirection.push_back(kappaMaxVector);
				kappaMinDirection.push_back(kappaMinVector);
			}
		}
	}
}