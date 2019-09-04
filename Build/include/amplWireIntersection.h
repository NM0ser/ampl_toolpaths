#pragma once
#include "stdafx.h"

namespace ampl
{
	class amplWireIntersection
	{
	public:
		amplWireIntersection::amplWireIntersection();
		
		enum pointsXYDirection {CW, CCW};

		void addEdge(const TopoDS_Edge &edgeIn, bool pushBack);
		void addEdgePnts(const gp_Pnt &pntU1, const gp_Pnt &pntU2, bool pushBack);
		void addReverseFlag(bool reverse, bool pushBack);

		void getOrderedEdgePnts(Standard_Integer edgeIndex, gp_Pnt &firstPnt, gp_Pnt &lastPnt);
		void getEdge(Standard_Integer edgeIndex, TopoDS_Edge &edge);
		void revEdge(Standard_Integer edgeIndex, TopoDS_Edge &edgeOut);
		bool containsEdge(const TopoDS_Edge &edge, Standard_Integer &edgeIndexOut);
		bool isClosedContour(Standard_Real edgeToEdgeTol);
		void toOccWire(TopoDS_Wire &wireOut);
		size_t getSizeEdgeArray(void);

		void discretizeWire(Standard_Real stepDist, Standard_Real edgeToEdgeTol, std::vector<gp_Pnt> &pntsOut);
		static void sequentialSortDiscretizedPnts(gp_Pnt firstWirePnt, std::vector<gp_Pnt> &pntsInOut);
		static void setDiscretizedPntsDirection(pointsXYDirection direction, std::vector<gp_Pnt> &pntsInOut);

		void getCenterOfMass(gp_Pnt &centerOut);
		void getWireLength(Standard_Real &distOut);

		void copy(const amplWireIntersection &other);

	protected:

	private:
		std::vector<TopoDS_Edge> edgeArr;
		std::vector< std::vector<gp_Pnt> > edgePoints;
		std::vector<bool> edgeReverseArr;
	};
}