#pragma once

#include "stdafx.h"
#include "amplWireIntersection.h"

namespace ampl
{
	class planeIntersecter
	{
	public:
		planeIntersecter::planeIntersecter(const TopoDS_Shape &S1, const TopoDS_Shape &S2);
		planeIntersecter::planeIntersecter(const TopoDS_Shape &S1, const gp_Pln &Pl);
		planeIntersecter::~planeIntersecter();

		void init(const TopoDS_Shape &S1, const TopoDS_Shape &S2);
		void init(const TopoDS_Shape &S1, const gp_Pln &Pl);

		void resetWireArray(void);

		bool performIntersect(void);
		void getUnsortedIntersection(TopoDS_Shape &S1);

		bool sortIntersection(void);
		void getNumClosedWires(Standard_Integer &numContours, std::vector<int> &intersectIndices);
		void getNumWires(Standard_Integer &numContours);
		void getWireIntersection(Standard_Integer intersectIndex, amplWireIntersection &wireOut);
		bool isIntersectClosed(Standard_Integer intersectIndex);

		void getCenterOfMass(Standard_Integer intersectIndex, gp_Pnt &centOfMass);
		void getMaxDistFromPoint(Standard_Integer intersectIndex, const gp_Pnt &centMassPnt, Standard_Real &maxXYDist);
		void getWireLength(Standard_Integer intersectIndex, Standard_Real &wireLength);

		void discretizeIntersection(Standard_Integer intersectIndex, Standard_Real stepDist, std::vector<gp_Pnt> &pntsOut);
		void discretizeIntersection(Standard_Integer intersectIndex, Standard_Real stepDist, const gp_Pnt startPnt, amplWireIntersection::pointsXYDirection direction, std::vector<gp_Pnt> &pntsOut);
		
		void orderDiscretization(const gp_Pnt startPnt, amplWireIntersection::pointsXYDirection direction, std::vector<gp_Pnt> &pntsInOut);
		static void findDiscretePntByWirePercent(const Standard_Real &decimalPercentIn, const std::vector<gp_Pnt> &pntsIn, const Standard_Real intersectLength, const std::vector<float> &distOfAllPntsIn, gp_Pnt &pntOut);
		
		void toOcctWire(Standard_Integer intersectIndex, TopoDS_Wire &wireOut);
		
		void getAllSurfProps(const std::vector<gp_Pnt> &discretizedPntsIn, const gp_Pnt &centOfMass, const bool vectPointPosZ, std::vector<gp_Vec> &normalsOut, 
			std::vector<float> &kappaMax, std::vector<gp_Vec> &kappaMaxDirection, std::vector<float> &kappaMin, std::vector<gp_Vec> &kappaMinDirection, 
			std::vector<float> &kappaMean, std::vector<float> &kappaGaussian);

		static void getAllSurfProps(const TopoDS_Shape &shellPartIn, const std::vector<gp_Pnt> &discretizedPntsIn, const gp_Pnt &centOfMass, const bool vectPointPosZ, std::vector<gp_Vec> &normalsOut,
			std::vector<float> &kappaMax, std::vector<gp_Vec> &kappaMaxDirection, std::vector<float> &kappaMin, std::vector<gp_Vec> &kappaMinDirection, std::vector<float> &kappaMean, std::vector<float> &kappaGaussian);

		void getSurfProp(const gp_Pnt &discretizedPntIn, const gp_Pnt &centOfMass, const bool vectPointPosZ, gp_Vec &normalOut, 
			float &kappaMax, gp_Vec &kappaMaxDirection, float &kappaMin, gp_Vec &kappaMinDirection, float &kappaMean, float &kappaGaussian);

		void setEdgeToEdgeTol(Standard_Real edgeToEdgeTol);
		Standard_Real getEdgeToEdgeTol(void);

		static void findPointParamOnSurf(const TopoDS_Shape &shellPartIn, const gp_Pnt &pntIn, Handle(Geom_Surface) &surfOut, gp_Pnt &closestProjPntOut, Standard_Real &paramU1Out, Standard_Real &paramU2Out);
		static void findPointParamOnSurfAlongVec(const TopoDS_Shape &shellPartIn, const gp_Pnt &pntIn, const gp_Vec &vecIn, Handle(Geom_Surface) &surfOut, gp_Pnt &closestProjPntOut, Standard_Real &paramU1Out, Standard_Real &paramU2Out);

		static void getAllIntersectPntsOnSurfAlongVec(const TopoDS_Shape &shellPartIn, const std::vector<gp_Pnt> &discretizedPntsIn, const std::vector<gp_Vec> &pntNormalsIn, std::vector<gp_Pnt> &projPntsOut);
		static void getAllProjectedPntsOnSurfAlongVec(const TopoDS_Shape &shellPartIn, const std::vector<gp_Pnt> &discretizedPntsIn, std::vector<gp_Pnt> &projPntsOut);
		//static void getAllProjectPntsOnSurfWithProps(const TopoDS_Shape &shellPartIn, const std::vector<gp_Pnt> &discretizedPntsIn, std::vector<gp_Pnt> &projPntsOut, const gp_Pnt &centOfMass, const bool vectPointPosZ, 
		//	std::vector<gp_Vec> &normalsOut, std::vector<float> &kappaMax, std::vector<gp_Vec> &kappaMaxDirection, std::vector<float> &kappaMin, std::vector<gp_Vec> &kappaMinDirection,
		//	std::vector<float> &kappaMean, std::vector<float> &kappaGaussian);

	protected:

	private:

		bool intersectSuccess = false;
		std::string message = "";
		Standard_Real myEdgeToEdgeTol;

		std::vector<amplWireIntersection> wireArr;
		BRepAlgoAPI_Section *sectionBuilder = nullptr;
		TopoDS_Shape shellPart;
		TopoDS_Shape intersectShape;
	};
}
