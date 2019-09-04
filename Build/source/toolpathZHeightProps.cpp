#include "stdafx.h"
#include "toolpathZHeightProps.h"

toolpathZHeightProps::toolpathZHeightProps()
{

}

void toolpathZHeightProps::init(const amplToolpath &amplToolpathIn)
{
	localAmplToolpath.copy(amplToolpathIn);
}

void toolpathZHeightProps::copyAllFromOther(const toolpathZHeightProps &other)
{
	localAmplToolpath.copy(other.localAmplToolpath);
	copyZDepthFromOther(other);

	allTopContactPnts = other.allTopContactPnts;
	allBotContactPnts = other.allBotContactPnts;
	allTopToolTipPnts = other.allTopToolTipPnts;
	allBotToolTipPnts = other.allBotToolTipPnts;
	allTopToolTipPntsMod = other.allTopToolTipPntsMod;
	allBotToolTipPntsMod = other.allBotToolTipPntsMod;

	allNormals = other.allNormals;
	allKappaMaxDirections = other.allKappaMaxDirections;
	allKappaMinDirections = other.allKappaMinDirections;
	allKappaMax = other.allKappaMax;
	allKappaMin = other.allKappaMin;
	allKappaMean = other.allKappaMean;
	allKappaGaussian = other.allKappaGaussian;
	allContourIndices = other.allContourIndices;
}

void toolpathZHeightProps::copyZDepthFromOther(const toolpathZHeightProps &other)
{
	currentZDepth = other.currentZDepth;
	zDepthMaxDistanceFromCOM = other.zDepthMaxDistanceFromCOM;
	zDepthAvgCoM = other.zDepthAvgCoM;
	zDepthStartAnglePnt = other.zDepthStartAnglePnt;
	zDepthTotalIntersectLength = other.zDepthTotalIntersectLength;

	zDepthTopContactPnts = other.zDepthTopContactPnts;
	zDepthBotContactPnts = other.zDepthBotContactPnts;
	zDepthTopToolTipPnts = other.zDepthTopToolTipPnts;
	zDepthBotToolTipPnts = other.zDepthBotToolTipPnts;
	zDepthTopToolTipPntsMod = other.zDepthTopToolTipPntsMod;
	zDepthBotToolTipPntsMod = other.zDepthBotToolTipPntsMod;

	zDepthNormals = other.zDepthNormals;
	zDepthKappaMaxDirections = other.zDepthKappaMaxDirections;
	zDepthKappaMinDirections = other.zDepthKappaMinDirections;
	zDepthKappaMax = other.zDepthKappaMax;
	zDepthKappaMin = other.zDepthKappaMin;
	zDepthKappaMean = other.zDepthKappaMean;
	zDepthKappaGaussian = other.zDepthKappaGaussian;
}

void toolpathZHeightProps::resetMembers(bool resetLocalAmplObject)
{
	amplToolpath localAmplCopy;
	localAmplCopy.copy(localAmplToolpath);

	toolpathZHeightProps localToolpathProps;
	copyAllFromOther(localToolpathProps);

	if (!resetLocalAmplObject)
		localAmplToolpath.copy(localAmplCopy);
}

void toolpathZHeightProps::pushBackZDepthTopContactPnts(bool addToLocalAmplToolpath, bool useSineLawOffset, bool useReverseNormal)
{
	float sqzFactorLocal = localAmplToolpath.sqzFactor;
	if (!useSineLawOffset)
	{
		for (int index = 0; index < zDepthTopContactPnts.size(); index++)
		{
			allTopContactPnts.push_back(zDepthTopContactPnts.at(index));
		}
	}
	else
	{
		float origThickness = localAmplToolpath.sheetThickness;
		int pntIndex = 0;
		for (gp_Pnt &contourPnt : zDepthTopContactPnts)
		{
			gp_Vec localNormalVec;
			if (pntIndex < zDepthNormals.size())
				localNormalVec = zDepthNormals.at(pntIndex); // Magnitude is a unit vector
			else
				localNormalVec = gp_Vec(0.0, 0.0, -1.0);

			gp_Pnt offsetContourPnt = contourPnt;
			if (abs(localNormalVec.X()) <= 0.001 && abs(localNormalVec.Y()) <= 0.001)
			{
				float sineLawOffset = origThickness*sqzFactorLocal;
				gp_Vec sineLawOffsetVec = localNormalVec;
				sineLawOffsetVec.Scale(sineLawOffset);

				if (useReverseNormal)
					sineLawOffsetVec.Reverse();

				offsetContourPnt.Translate(sineLawOffsetVec);
			}
			else
			{
				gp_Dir localXYNormalDir(localNormalVec.X(), localNormalVec.Y(), 0.0);
				gp_Vec localXYNormalVec(localXYNormalDir);
				float localWallAngle = (3.14159265358979323846 / 2.0) - localNormalVec.Angle(localXYNormalVec); // localNormalVec.Angle(gp_Vec other) Returns the angle value between 0 and PI in radian
				float sineLawOffset = origThickness*sqzFactorLocal*sinf((3.14159265358979323846 / 2.0) - localWallAngle);
				gp_Vec sineLawOffsetVec = localNormalVec;
				sineLawOffsetVec.Scale(sineLawOffset);

				if (useReverseNormal)
					sineLawOffsetVec.Reverse();

				offsetContourPnt.Translate(sineLawOffsetVec);
			}

			allTopContactPnts.push_back(offsetContourPnt);
			pntIndex++;
		}
	}

	if (addToLocalAmplToolpath)
	{
		for (gp_Pnt &contourPnt : allTopContactPnts) // Fill up amplToolpath object with the contact points
		{
			float nextX, nextY, nextZ;
			nextX = contourPnt.X(); nextY = contourPnt.Y(); nextZ = contourPnt.Z();

			if (!(localAmplToolpath.topContactPntsActive()))
				(localAmplToolpath.topContactPnts).at(0) = { nextX, nextY, nextZ };
			else
				(localAmplToolpath.topContactPnts).push_back({ nextX, nextY, nextZ });
		}
	}
}

void toolpathZHeightProps::pushBackZDepthBotContactPnts(bool addToLocalAmplToolpath, bool useSineLawOffset, bool useReverseNormal)
{
	float sqzFactorLocal = localAmplToolpath.sqzFactor;
	if (!useSineLawOffset)
	{
		for (int index = 0; index < zDepthBotContactPnts.size(); index++)
		{
			allBotContactPnts.push_back(zDepthBotContactPnts.at(index));
		}
	}
	else
	{
		float origThickness = localAmplToolpath.sheetThickness;
		int pntIndex = 0;
		for (gp_Pnt &contourPnt : zDepthBotContactPnts)
		{
			gp_Vec localNormalVec;
			if (pntIndex < zDepthNormals.size())
				localNormalVec = zDepthNormals.at(pntIndex); // Magnitude is a unit vector
			else
				localNormalVec = gp_Vec(0.0, 0.0, -1.0);

			gp_Pnt offsetContourPnt = contourPnt;
			if (abs(localNormalVec.X()) <= 0.001 && abs(localNormalVec.Y()) <= 0.001)
			{
				float sineLawOffset = origThickness*sqzFactorLocal;
				gp_Vec sineLawOffsetVec = localNormalVec;
				sineLawOffsetVec.Scale(sineLawOffset);

				if (useReverseNormal)
					sineLawOffsetVec.Reverse();

				offsetContourPnt.Translate(sineLawOffsetVec);
			}
			else
			{
				gp_Dir localXYNormalDir(localNormalVec.X(), localNormalVec.Y(), 0.0);
				gp_Vec localXYNormalVec(localXYNormalDir);
				float localWallAngle = (3.14159265358979323846 / 2.0) - localNormalVec.Angle(localXYNormalVec); // localNormalVec.Angle(gp_Vec other) Returns the angle value between 0 and PI in radian
				float sineLawOffset = origThickness*sqzFactorLocal*sinf((3.14159265358979323846 / 2.0) - localWallAngle);
				gp_Vec sineLawOffsetVec = localNormalVec;
				sineLawOffsetVec.Scale(sineLawOffset);

				if (useReverseNormal)
					sineLawOffsetVec.Reverse();

				offsetContourPnt.Translate(sineLawOffsetVec);
			}

			allBotContactPnts.push_back(offsetContourPnt);
			pntIndex++;
		}
	}

	if (addToLocalAmplToolpath)
	{
		for (gp_Pnt &contourPnt : allBotContactPnts) // Fill up amplToolpath object with the contact points
		{
			float nextX, nextY, nextZ;
			nextX = contourPnt.X(); nextY = contourPnt.Y(); nextZ = contourPnt.Z();

			if (!(localAmplToolpath.botContactPntsActive()))
				(localAmplToolpath.botContactPnts).at(0) = { nextX, nextY, nextZ };
			else
				(localAmplToolpath.botContactPnts).push_back({ nextX, nextY, nextZ });
		}
	}
}

void toolpathZHeightProps::pushBackZDepthTopToolTipPnts(bool addToLocalAmplToolpath)
{
	for (int index = 0; index < zDepthTopToolTipPnts.size(); index++)
	{
		allTopToolTipPnts.push_back(zDepthTopToolTipPnts.at(index));
	}
	if (addToLocalAmplToolpath)
	{
		for (gp_Pnt &contourPnt : allTopToolTipPnts) // Fill up amplToolpath object with the contact points
		{
			float nextX, nextY, nextZ;
			nextX = contourPnt.X(); nextY = contourPnt.Y(); nextZ = contourPnt.Z();

			if (!(localAmplToolpath.topToolTipPntsActive()))
				(localAmplToolpath.topToolTipPnts).at(0) = { nextX, nextY, nextZ };
			else
				(localAmplToolpath.topToolTipPnts).push_back({ nextX, nextY, nextZ });
		}
	}
}

void toolpathZHeightProps::pushBackZDepthBotToolTipPnts(bool addToLocalAmplToolpath)
{
	for (int index = 0; index < zDepthBotToolTipPnts.size(); index++)
	{
		allBotToolTipPnts.push_back(zDepthBotToolTipPnts.at(index));
	}
	if (addToLocalAmplToolpath)
	{
		for (gp_Pnt &contourPnt : allBotToolTipPnts) // Fill up amplToolpath object with the contact points
		{
			float nextX, nextY, nextZ;
			nextX = contourPnt.X(); nextY = contourPnt.Y(); nextZ = contourPnt.Z();

			if (!(localAmplToolpath.botToolTipPntsActive()))
				(localAmplToolpath.botToolTipPnts).at(0) = { nextX, nextY, nextZ };
			else
				(localAmplToolpath.botToolTipPnts).push_back({ nextX, nextY, nextZ });
		}
	}
}

void toolpathZHeightProps::pushBackZDepthTopToolTipPntsMod(bool addToLocalAmplToolpath)
{
	for (int index = 0; index < zDepthTopToolTipPntsMod.size(); index++)
	{
		allTopToolTipPntsMod.push_back(zDepthTopToolTipPntsMod.at(index));
	}
	if (addToLocalAmplToolpath)
	{
		for (gp_Pnt &contourPnt : allTopToolTipPntsMod) // Fill up amplToolpath object with the contact points
		{
			float nextX, nextY, nextZ;
			nextX = contourPnt.X(); nextY = contourPnt.Y(); nextZ = contourPnt.Z();

			if (!(localAmplToolpath.topToolTipPntsModActive()))
				(localAmplToolpath.topToolTipPntsMod).at(0) = { nextX, nextY, nextZ };
			else
				(localAmplToolpath.topToolTipPntsMod).push_back({ nextX, nextY, nextZ });
		}
	}
}

void toolpathZHeightProps::pushBackZDepthBotToolTipPntsMod(bool addToLocalAmplToolpath)
{
	for (int index = 0; index < zDepthBotToolTipPntsMod.size(); index++)
	{
		allBotToolTipPntsMod.push_back(zDepthBotToolTipPntsMod.at(index));
	}
	if (addToLocalAmplToolpath)
	{
		for (gp_Pnt &contourPnt : allBotToolTipPntsMod) // Fill up amplToolpath object with the contact points
		{
			float nextX, nextY, nextZ;
			nextX = contourPnt.X(); nextY = contourPnt.Y(); nextZ = contourPnt.Z();

			if (!(localAmplToolpath.botToolTipPntsModActive()))
				(localAmplToolpath.botToolTipPntsMod).at(0) = { nextX, nextY, nextZ };
			else
				(localAmplToolpath.botToolTipPntsMod).push_back({ nextX, nextY, nextZ });
		}
	}
}

void toolpathZHeightProps::pushBackZDepthContactPntsSurfProps(bool addToLocalAmplToolpath, int topOrBotContactSurfProps)
{
	for (int index = 0; index < zDepthNormals.size(); index++)
	{
		allNormals.push_back(zDepthNormals.at(index));
		allKappaMaxDirections.push_back(zDepthKappaMaxDirections.at(index));
		allKappaMinDirections.push_back(zDepthKappaMinDirections.at(index));
		allKappaMax.push_back(zDepthKappaMax.at(index));
		allKappaMin.push_back(zDepthKappaMin.at(index));
		allKappaMean.push_back(zDepthKappaMean.at(index));
		allKappaGaussian.push_back(zDepthKappaGaussian.at(index));
	}
	if (addToLocalAmplToolpath)
	{
		for (int index = 0; index < zDepthNormals.size(); index++)
		{
			float normalX, normalY, normalZ, maxKappaX, maxKappaY, maxKappaZ, minKappaX, minKappaY, minKappaZ;
			normalX = (zDepthNormals.at(index)).X(); normalY = (zDepthNormals.at(index)).Y(); normalZ = (zDepthNormals.at(index)).Z();
			maxKappaX = (zDepthKappaMaxDirections.at(index)).X(); maxKappaY = (zDepthKappaMaxDirections.at(index)).Y(); maxKappaZ = (zDepthKappaMaxDirections.at(index)).Z();
			minKappaX = (zDepthKappaMinDirections.at(index)).X(); minKappaY = (zDepthKappaMinDirections.at(index)).Y(); minKappaZ = (zDepthKappaMinDirections.at(index)).Z();

			float localKappaMax, localKappaMin, localKappaMean, localKappaGaussian;
			localKappaMax = zDepthKappaMax.at(index); localKappaMin = zDepthKappaMin.at(index); localKappaMean = zDepthKappaMean.at(index); localKappaGaussian = zDepthKappaGaussian.at(index);

			if (topOrBotContactSurfProps > 0)
			{
				if (!(localAmplToolpath.topContactPntsSurfPropsActive()))
					(localAmplToolpath.topContactPntsSurfProps).at(0) = { normalX, normalY, normalZ,
					localKappaMax, maxKappaX, maxKappaY, maxKappaZ, localKappaMin, minKappaX, minKappaY, minKappaZ, localKappaMean, localKappaGaussian };
				else
					(localAmplToolpath.topContactPntsSurfProps).push_back({ normalX, normalY, normalZ,
						localKappaMax, maxKappaX, maxKappaY, maxKappaZ, localKappaMin, minKappaX, minKappaY, minKappaZ, localKappaMean, localKappaGaussian });
			}
			else if (topOrBotContactSurfProps < 0)
			{
				if (!(localAmplToolpath.botContactPntsSurfPropsActive()))
					(localAmplToolpath.botContactPntsSurfProps).at(0) = { normalX, normalY, normalZ,
					localKappaMax, maxKappaX, maxKappaY, maxKappaZ, localKappaMin, minKappaX, minKappaY, minKappaZ, localKappaMean, localKappaGaussian };
				else
					(localAmplToolpath.botContactPntsSurfProps).push_back({ normalX, normalY, normalZ,
						localKappaMax, maxKappaX, maxKappaY, maxKappaZ, localKappaMin, minKappaX, minKappaY, minKappaZ, localKappaMean, localKappaGaussian });
			}
			else
			{
				if (!(localAmplToolpath.topContactPntsSurfPropsActive()))
					(localAmplToolpath.topContactPntsSurfProps).at(0) = { normalX, normalY, normalZ,
					localKappaMax, maxKappaX, maxKappaY, maxKappaZ, localKappaMin, minKappaX, minKappaY, minKappaZ, localKappaMean, localKappaGaussian };
				else
					(localAmplToolpath.topContactPntsSurfProps).push_back({ normalX, normalY, normalZ,
						localKappaMax, maxKappaX, maxKappaY, maxKappaZ, localKappaMin, minKappaX, minKappaY, minKappaZ, localKappaMean, localKappaGaussian });

				if (!(localAmplToolpath.botContactPntsSurfPropsActive()))
					(localAmplToolpath.botContactPntsSurfProps).at(0) = { normalX, normalY, normalZ,
					localKappaMax, maxKappaX, maxKappaY, maxKappaZ, localKappaMin, minKappaX, minKappaY, minKappaZ, localKappaMean, localKappaGaussian };
				else
					(localAmplToolpath.botContactPntsSurfProps).push_back({ normalX, normalY, normalZ,
						localKappaMax, maxKappaX, maxKappaY, maxKappaZ, localKappaMin, minKappaX, minKappaY, minKappaZ, localKappaMean, localKappaGaussian });
			}
		}
	}
}

void toolpathZHeightProps::copyAllContactPntsToLocalAmpl(void)
{
	float unassignedVal = localAmplToolpath.getUnassignedVal();

	localAmplToolpath.topContactPnts = { { unassignedVal, unassignedVal, unassignedVal } };
	for (gp_Pnt &contourPnt : allTopContactPnts) // Fill up amplToolpath object with the contact points
	{
		float nextX, nextY, nextZ;
		nextX = contourPnt.X(); nextY = contourPnt.Y(); nextZ = contourPnt.Z();

		if (!(localAmplToolpath.topContactPntsActive()))
			(localAmplToolpath.topContactPnts).at(0) = { nextX, nextY, nextZ };
		else
			(localAmplToolpath.topContactPnts).push_back({ nextX, nextY, nextZ });
	}

	localAmplToolpath.botContactPnts = { { unassignedVal, unassignedVal, unassignedVal } };
	for (gp_Pnt &contourPnt : allBotContactPnts) // Fill up amplToolpath object with the contact points
	{
		float nextX, nextY, nextZ;
		nextX = contourPnt.X(); nextY = contourPnt.Y(); nextZ = contourPnt.Z();

		if (!(localAmplToolpath.botContactPntsActive()))
			(localAmplToolpath.botContactPnts).at(0) = { nextX, nextY, nextZ };
		else
			(localAmplToolpath.botContactPnts).push_back({ nextX, nextY, nextZ });
	}

	localAmplToolpath.contourIndices = allContourIndices;
}

void toolpathZHeightProps::copyAllToolTipPntsToLocalAmpl(void)
{
	float unassignedVal = localAmplToolpath.getUnassignedVal();

	localAmplToolpath.topToolTipPnts = { { unassignedVal, unassignedVal, unassignedVal } };
	for (gp_Pnt &contourPnt : allTopToolTipPnts) // Fill up amplToolpath object with the contact points
	{
		float nextX, nextY, nextZ;
		nextX = contourPnt.X(); nextY = contourPnt.Y(); nextZ = contourPnt.Z();

		if (!(localAmplToolpath.topToolTipPntsActive()))
			(localAmplToolpath.topToolTipPnts).at(0) = { nextX, nextY, nextZ };
		else
			(localAmplToolpath.topToolTipPnts).push_back({ nextX, nextY, nextZ });
	}

	localAmplToolpath.botToolTipPnts = { { unassignedVal, unassignedVal, unassignedVal } };
	for (gp_Pnt &contourPnt : allBotToolTipPnts) // Fill up amplToolpath object with the contact points
	{
		float nextX, nextY, nextZ;
		nextX = contourPnt.X(); nextY = contourPnt.Y(); nextZ = contourPnt.Z();

		if (!(localAmplToolpath.botToolTipPntsActive()))
			(localAmplToolpath.botToolTipPnts).at(0) = { nextX, nextY, nextZ };
		else
			(localAmplToolpath.botToolTipPnts).push_back({ nextX, nextY, nextZ });
	}
}

void toolpathZHeightProps::copyAllToolTipPntsModToLocalAmpl(void)
{
	float unassignedVal = localAmplToolpath.getUnassignedVal();

	localAmplToolpath.topToolTipPntsMod = { { unassignedVal, unassignedVal, unassignedVal } };
	for (gp_Pnt &contourPnt : allTopToolTipPntsMod) // Fill up amplToolpath object with the contact points
	{
		float nextX, nextY, nextZ;
		nextX = contourPnt.X(); nextY = contourPnt.Y(); nextZ = contourPnt.Z();

		if (!(localAmplToolpath.topToolTipPntsModActive()))
			(localAmplToolpath.topToolTipPntsMod).at(0) = { nextX, nextY, nextZ };
		else
			(localAmplToolpath.topToolTipPntsMod).push_back({ nextX, nextY, nextZ });
	}

	localAmplToolpath.botToolTipPntsMod = { { unassignedVal, unassignedVal, unassignedVal } };
	for (gp_Pnt &contourPnt : allBotToolTipPntsMod) // Fill up amplToolpath object with the contact points
	{
		float nextX, nextY, nextZ;
		nextX = contourPnt.X(); nextY = contourPnt.Y(); nextZ = contourPnt.Z();

		if (!(localAmplToolpath.botToolTipPntsModActive()))
			(localAmplToolpath.botToolTipPntsMod).at(0) = { nextX, nextY, nextZ };
		else
			(localAmplToolpath.botToolTipPntsMod).push_back({ nextX, nextY, nextZ });
	}
}

void toolpathZHeightProps::copyAllSurfPropsToLocalAmpl(void)
{
	float unassignedVal = localAmplToolpath.getUnassignedVal();

	localAmplToolpath.topContactPntsSurfProps = { { unassignedVal, unassignedVal, unassignedVal, unassignedVal,
		unassignedVal, unassignedVal, unassignedVal, unassignedVal,
		unassignedVal, unassignedVal, unassignedVal, unassignedVal, unassignedVal } };

	localAmplToolpath.botContactPntsSurfProps = { { unassignedVal, unassignedVal, unassignedVal, unassignedVal,
		unassignedVal, unassignedVal, unassignedVal, unassignedVal,
		unassignedVal, unassignedVal, unassignedVal, unassignedVal, unassignedVal } };

	for (int index = 0; index < allNormals.size(); index++)
	{
		float normalX, normalY, normalZ, maxKappaX, maxKappaY, maxKappaZ, minKappaX, minKappaY, minKappaZ;
		normalX = (allNormals.at(index)).X(); normalY = (allNormals.at(index)).Y(); normalZ = (allNormals.at(index)).Z();
		maxKappaX = (allKappaMaxDirections.at(index)).X(); maxKappaY = (allKappaMaxDirections.at(index)).Y(); maxKappaZ = (allKappaMaxDirections.at(index)).Z();
		minKappaX = (allKappaMinDirections.at(index)).X(); minKappaY = (allKappaMinDirections.at(index)).Y(); minKappaZ = (allKappaMinDirections.at(index)).Z();

		float localKappaMax, localKappaMin, localKappaMean, localKappaGaussian;
		localKappaMax = allKappaMax.at(index); localKappaMin = allKappaMin.at(index); localKappaMean = allKappaMean.at(index); localKappaGaussian = allKappaGaussian.at(index);

		if (!(localAmplToolpath.topContactPntsSurfPropsActive()))
			(localAmplToolpath.topContactPntsSurfProps).at(0) = { normalX, normalY, normalZ,
			localKappaMax, maxKappaX, maxKappaY, maxKappaZ, localKappaMin, minKappaX, minKappaY, minKappaZ, localKappaMean, localKappaGaussian };
		else
			(localAmplToolpath.topContactPntsSurfProps).push_back({ normalX, normalY, normalZ,
				localKappaMax, maxKappaX, maxKappaY, maxKappaZ, localKappaMin, minKappaX, minKappaY, minKappaZ, localKappaMean, localKappaGaussian });

		if (!(localAmplToolpath.botContactPntsSurfPropsActive()))
			(localAmplToolpath.botContactPntsSurfProps).at(0) = { normalX, normalY, normalZ,
			localKappaMax, maxKappaX, maxKappaY, maxKappaZ, localKappaMin, minKappaX, minKappaY, minKappaZ, localKappaMean, localKappaGaussian };
		else
			(localAmplToolpath.botContactPntsSurfProps).push_back({ normalX, normalY, normalZ,
				localKappaMax, maxKappaX, maxKappaY, maxKappaZ, localKappaMin, minKappaX, minKappaY, minKappaZ, localKappaMean, localKappaGaussian });
	}
}

void toolpathZHeightProps::copyAmplContactPntsToOther(amplToolpath &other)
{
	other.topContactPnts = localAmplToolpath.topContactPnts;
	other.botContactPnts = localAmplToolpath.botContactPnts;
	other.contourIndices = localAmplToolpath.contourIndices;
}

void toolpathZHeightProps::copyAmplToolTipPntsToOther(amplToolpath &other)
{
	other.topToolTipPnts = localAmplToolpath.topToolTipPnts;
	other.botToolTipPnts = localAmplToolpath.botToolTipPnts;
}

void toolpathZHeightProps::copyAmplToolTipPntsModToOther(amplToolpath &other)
{
	other.topToolTipPntsMod = localAmplToolpath.topToolTipPntsMod;
	other.botToolTipPntsMod = localAmplToolpath.botToolTipPntsMod;
}

void toolpathZHeightProps::copyAmplSurfPropsToOther(amplToolpath &other)
{
	other.topContactPntsSurfProps = localAmplToolpath.topContactPntsSurfProps;
	other.botContactPntsSurfProps = localAmplToolpath.botContactPntsSurfProps;
}

void toolpathZHeightProps::pushBackAllContactPntsToOther(toolpathZHeightProps &other, bool localAmplOnly)
{
	for (gp_Pnt &contourPnt : allTopContactPnts) // Fill up amplToolpath object with the contact points
	{
		if(!localAmplOnly)
			other.allTopContactPnts.push_back(contourPnt);

		float nextX, nextY, nextZ;
		nextX = contourPnt.X(); nextY = contourPnt.Y(); nextZ = contourPnt.Z();

		if (!(other.localAmplToolpath.topContactPntsActive()))
			(other.localAmplToolpath.topContactPnts).at(0) = { nextX, nextY, nextZ };
		else
			(other.localAmplToolpath.topContactPnts).push_back({ nextX, nextY, nextZ });
	}

	for (gp_Pnt &contourPnt : allBotContactPnts) // Fill up amplToolpath object with the contact points
	{
		if (!localAmplOnly)
			other.allBotContactPnts.push_back(contourPnt);

		float nextX, nextY, nextZ;
		nextX = contourPnt.X(); nextY = contourPnt.Y(); nextZ = contourPnt.Z();

		if (!(other.localAmplToolpath.botContactPntsActive()))
			(other.localAmplToolpath.botContactPnts).at(0) = { nextX, nextY, nextZ };
		else
			(other.localAmplToolpath.botContactPnts).push_back({ nextX, nextY, nextZ });
	}

	//for (int &curContourStartInd : allContourIndices)
	//{
	//	if (!localAmplOnly)
	//		other.allContourIndices.push_back(curContourStartInd);
	//}
	//other.localAmplToolpath.contourIndices = allContourIndices;
	
}

void toolpathZHeightProps::pushBackAllToolTipPntsToOther(toolpathZHeightProps &other, bool localAmplOnly)
{
	for (gp_Pnt &contourPnt : allTopToolTipPnts) // Fill up amplToolpath object with the contact points
	{
		if (!localAmplOnly)
			other.allTopToolTipPnts.push_back(contourPnt);

		float nextX, nextY, nextZ;
		nextX = contourPnt.X(); nextY = contourPnt.Y(); nextZ = contourPnt.Z();

		if (!(other.localAmplToolpath.topToolTipPntsActive()))
			(other.localAmplToolpath.topToolTipPnts).at(0) = { nextX, nextY, nextZ };
		else
			(other.localAmplToolpath.topToolTipPnts).push_back({ nextX, nextY, nextZ });
	}

	for (gp_Pnt &contourPnt : allBotToolTipPnts) // Fill up amplToolpath object with the contact points
	{
		if (!localAmplOnly)
			other.allBotToolTipPnts.push_back(contourPnt);

		float nextX, nextY, nextZ;
		nextX = contourPnt.X(); nextY = contourPnt.Y(); nextZ = contourPnt.Z();

		if (!(other.localAmplToolpath.botToolTipPntsActive()))
			(other.localAmplToolpath.botToolTipPnts).at(0) = { nextX, nextY, nextZ };
		else
			(other.localAmplToolpath.botToolTipPnts).push_back({ nextX, nextY, nextZ });
	}
}

void toolpathZHeightProps::pushBackAllToolTipPntsModToOther(toolpathZHeightProps &other, bool localAmplOnly)
{
	for (gp_Pnt &contourPnt : allTopToolTipPntsMod) // Fill up amplToolpath object with the contact points
	{
		if (!localAmplOnly)
			other.allTopToolTipPntsMod.push_back(contourPnt);

		float nextX, nextY, nextZ;
		nextX = contourPnt.X(); nextY = contourPnt.Y(); nextZ = contourPnt.Z();

		if (!(other.localAmplToolpath.topToolTipPntsModActive()))
			(other.localAmplToolpath.topToolTipPntsMod).at(0) = { nextX, nextY, nextZ };
		else
			(other.localAmplToolpath.topToolTipPntsMod).push_back({ nextX, nextY, nextZ });
	}

	for (gp_Pnt &contourPnt : allBotToolTipPntsMod) // Fill up amplToolpath object with the contact points
	{
		if (!localAmplOnly)
			other.allBotToolTipPntsMod.push_back(contourPnt);

		float nextX, nextY, nextZ;
		nextX = contourPnt.X(); nextY = contourPnt.Y(); nextZ = contourPnt.Z();

		if (!(other.localAmplToolpath.botToolTipPntsModActive()))
			(other.localAmplToolpath.botToolTipPntsMod).at(0) = { nextX, nextY, nextZ };
		else
			(other.localAmplToolpath.botToolTipPntsMod).push_back({ nextX, nextY, nextZ });
	}
}

void toolpathZHeightProps::pushBackAllSurfPropsToOther(toolpathZHeightProps &other, int topOrBotContactSurfProps, bool localAmplOnly)
{
	for (int index = 0; index < allNormals.size(); index++)
	{
		if (!localAmplOnly)
		{
			other.allNormals.push_back(allNormals.at(index));
			other.allKappaMaxDirections.push_back(allKappaMaxDirections.at(index));
			other.allKappaMinDirections.push_back(allKappaMinDirections.at(index));
			other.allKappaMax.push_back(allKappaMax.at(index));
			other.allKappaMin.push_back(allKappaMin.at(index));
			other.allKappaMean.push_back(allKappaMean.at(index));
			other.allKappaGaussian.push_back(allKappaGaussian.at(index));
		}

		float normalX, normalY, normalZ, maxKappaX, maxKappaY, maxKappaZ, minKappaX, minKappaY, minKappaZ;
		normalX = (allNormals.at(index)).X(); normalY = (allNormals.at(index)).Y(); normalZ = (allNormals.at(index)).Z();
		maxKappaX = (allKappaMaxDirections.at(index)).X(); maxKappaY = (allKappaMaxDirections.at(index)).Y(); maxKappaZ = (allKappaMaxDirections.at(index)).Z();
		minKappaX = (allKappaMinDirections.at(index)).X(); minKappaY = (allKappaMinDirections.at(index)).Y(); minKappaZ = (allKappaMinDirections.at(index)).Z();

		float localKappaMax, localKappaMin, localKappaMean, localKappaGaussian;
		localKappaMax = zDepthKappaMax.at(index); localKappaMin = zDepthKappaMin.at(index); localKappaMean = zDepthKappaMean.at(index); localKappaGaussian = zDepthKappaGaussian.at(index);

		if (topOrBotContactSurfProps > 0)
		{
			if (!(other.localAmplToolpath.topContactPntsSurfPropsActive()))
				(other.localAmplToolpath.topContactPntsSurfProps).at(0) = { normalX, normalY, normalZ,
				localKappaMax, maxKappaX, maxKappaY, maxKappaZ, localKappaMin, minKappaX, minKappaY, minKappaZ, localKappaMean, localKappaGaussian };
			else
				(other.localAmplToolpath.topContactPntsSurfProps).push_back({ normalX, normalY, normalZ,
					localKappaMax, maxKappaX, maxKappaY, maxKappaZ, localKappaMin, minKappaX, minKappaY, minKappaZ, localKappaMean, localKappaGaussian });
		}
		else if (topOrBotContactSurfProps < 0)
		{
			if (!(other.localAmplToolpath.botContactPntsSurfPropsActive()))
				(other.localAmplToolpath.botContactPntsSurfProps).at(0) = { normalX, normalY, normalZ,
				localKappaMax, maxKappaX, maxKappaY, maxKappaZ, localKappaMin, minKappaX, minKappaY, minKappaZ, localKappaMean, localKappaGaussian };
			else
				(other.localAmplToolpath.botContactPntsSurfProps).push_back({ normalX, normalY, normalZ,
					localKappaMax, maxKappaX, maxKappaY, maxKappaZ, localKappaMin, minKappaX, minKappaY, minKappaZ, localKappaMean, localKappaGaussian });
		}
		else
		{
			if (!(other.localAmplToolpath.topContactPntsSurfPropsActive()))
				(other.localAmplToolpath.topContactPntsSurfProps).at(0) = { normalX, normalY, normalZ,
				localKappaMax, maxKappaX, maxKappaY, maxKappaZ, localKappaMin, minKappaX, minKappaY, minKappaZ, localKappaMean, localKappaGaussian };
			else
				(other.localAmplToolpath.topContactPntsSurfProps).push_back({ normalX, normalY, normalZ,
					localKappaMax, maxKappaX, maxKappaY, maxKappaZ, localKappaMin, minKappaX, minKappaY, minKappaZ, localKappaMean, localKappaGaussian });

			if (!(other.localAmplToolpath.botContactPntsSurfPropsActive()))
				(other.localAmplToolpath.botContactPntsSurfProps).at(0) = { normalX, normalY, normalZ,
				localKappaMax, maxKappaX, maxKappaY, maxKappaZ, localKappaMin, minKappaX, minKappaY, minKappaZ, localKappaMean, localKappaGaussian };
			else
				(other.localAmplToolpath.botContactPntsSurfProps).push_back({ normalX, normalY, normalZ,
					localKappaMax, maxKappaX, maxKappaY, maxKappaZ, localKappaMin, minKappaX, minKappaY, minKappaZ, localKappaMean, localKappaGaussian });
		}
	}
}

void toolpathZHeightProps::resetZDepthContactPnts(void)
{
	zDepthTopContactPnts.clear();  
	zDepthBotContactPnts.clear(); 
}

void toolpathZHeightProps::resetZDepthToolTipPnts(void)
{
	zDepthTopToolTipPnts.clear();
	zDepthBotToolTipPnts.clear();
}

void toolpathZHeightProps::resetZDepthToolTipPntsMod(void)
{
	zDepthTopToolTipPntsMod.clear();
	zDepthBotToolTipPntsMod.clear();
}

void toolpathZHeightProps::resetZDepthLocalSurfProps(void)
{
	zDepthNormals.clear();
	zDepthKappaMaxDirections.clear();
	zDepthKappaMinDirections.clear();
	zDepthKappaMax.clear();
	zDepthKappaMin.clear();
	zDepthKappaMean.clear();
	zDepthKappaGaussian.clear();
}

void toolpathZHeightProps::resetAllContactPnts(bool resetZDepth)
{
	if (resetZDepth)
		resetZDepthContactPnts();

	allTopContactPnts.clear();
	allBotContactPnts.clear();
	allContourIndices.clear();
}

void toolpathZHeightProps::resetAllToolTipPnts(bool resetZDepth)
{
	if (resetZDepth)
		resetZDepthToolTipPnts();

	allTopToolTipPnts.clear();
	allBotToolTipPnts.clear();
}

void toolpathZHeightProps::resetAllToolTipPntsMod(bool resetZDepth)
{
	if (resetZDepth)
		resetZDepthToolTipPntsMod();

	allTopToolTipPntsMod.clear();
	allBotToolTipPntsMod.clear();
}

void toolpathZHeightProps::resetAllLocalSurfProps(bool resetZDepth)
{
	if (resetZDepth)
		resetZDepthLocalSurfProps();

	allNormals.clear();
	allKappaMaxDirections.clear();
	allKappaMinDirections.clear();
	allKappaMax.clear();
	allKappaMin.clear();
	allKappaMean.clear();
	allKappaGaussian.clear();
}

void  toolpathZHeightProps::interpolateZDepthContactContours(const std::vector<gp_Pnt> &pntsIn, const toolpathZHeightProps &lastZHeight, const toolpathZHeightProps &currentZHeight, toolpathZHeightProps &outZHeight)
{
	outZHeight.zDepthNormals.clear();
	outZHeight.zDepthKappaMaxDirections.clear();
	outZHeight.zDepthKappaMinDirections.clear();
	outZHeight.zDepthKappaMax.clear();
	outZHeight.zDepthKappaMin.clear();
	outZHeight.zDepthKappaMean.clear();
	outZHeight.zDepthKappaGaussian.clear();

	std::vector<gp_Pnt> lastZDepthPnts = lastZHeight.zDepthTopContactPnts;
	std::vector<gp_Pnt> curZDepthPnts = currentZHeight.zDepthTopContactPnts;

	std::vector<gp_Vec> lastZDepthNormals = lastZHeight.zDepthNormals; 
	std::vector<gp_Vec> curZDepthNormals = currentZHeight.zDepthNormals;

	std::vector<gp_Vec> lastZDepthKappaMaxDirections = lastZHeight.zDepthKappaMaxDirections;
	std::vector<gp_Vec> curZDepthKappaMaxDirections = currentZHeight.zDepthKappaMaxDirections;

	std::vector<gp_Vec> lastZDepthKappaMinDirections = lastZHeight.zDepthKappaMinDirections;
	std::vector<gp_Vec> curZDepthKappaMinDirections = currentZHeight.zDepthKappaMinDirections;

	std::vector<float> lastZDepthKappaMax = lastZHeight.zDepthKappaMax;
	std::vector<float> curZDepthKappaMax = currentZHeight.zDepthKappaMax;

	std::vector<float> lastZDepthKappaMin = lastZHeight.zDepthKappaMin;
	std::vector<float> curZDepthKappaMin = currentZHeight.zDepthKappaMin;

	std::vector<float> lastZDepthKappaMean = lastZHeight.zDepthKappaMean;
	std::vector<float> curZDepthKappaMean = currentZHeight.zDepthKappaMean;

	std::vector<float> lastZDepthKappaGaussian = lastZHeight.zDepthKappaGaussian;
	std::vector<float> curZDepthKappaGaussian = currentZHeight.zDepthKappaGaussian;

	int pntsInIndex = 0;
	for (const gp_Pnt& curInterpPntIn : pntsIn)
	{
		int lastZDepthPntIndex = 0;
		int curZDepthPntIndex = 0;
		gp_Pnt lastClosestPnt(0.0, 0.0, 0.0);
		gp_Pnt curClosestPnt(0.0, 0.0, 0.0);

		float minDistLast = 1.0E6; // Find the closest point from the last contour
		int count = 0;
		for (const gp_Pnt& lastPnt : lastZDepthPnts)
		{
			float curDist = lastPnt.Distance(curInterpPntIn);
			if (curDist < minDistLast)
			{
				minDistLast = curDist;
				lastZDepthPntIndex = count;
				lastClosestPnt = lastPnt;
			}

			count = count + 1;
		}

		float minDistCur = 1.0E6; // Find the closest point from the current contour
		count = 0;
		for (const gp_Pnt& curPnt : curZDepthPnts)
		{
			float curDist = curPnt.Distance(curInterpPntIn);
			if (curDist < minDistCur)
			{
				minDistCur = curDist;
				curZDepthPntIndex = count;
				curClosestPnt = curPnt;
			}

			count = count + 1;
		}

		float dist_im1 = curInterpPntIn.Distance(lastClosestPnt);
		float dist_i = curInterpPntIn.Distance(curClosestPnt);
		float totalDist = dist_im1 + dist_i;

		float weightLastZDepth = (totalDist - dist_im1) / totalDist;
		float weightCurZDepth = (totalDist - dist_i) / totalDist;

		/* 
		std::vector<gp_Vec> zDepthNormals; // Assumed that these properties hold approximately true for both the top and bottom contacts
		std::vector<gp_Vec> zDepthKappaMaxDirections;
		std::vector<gp_Vec> zDepthKappaMinDirections;
		std::vector<float> zDepthKappaMax;
		std::vector<float> zDepthKappaMin;
		std::vector<float> zDepthKappaMean;
		std::vector<float> zDepthKappaGaussian;
		*/

		// Copy over interpolated values 
		outZHeight.zDepthTopContactPnts.at(pntsInIndex) = curInterpPntIn;

		gp_Vec lastZDepthVecTemp = lastZDepthNormals.at(lastZDepthPntIndex);
		gp_Vec curZDepthVecTemp = curZDepthNormals.at(curZDepthPntIndex);
		gp_Vec interpZDepthVecTemp;
		interpZDepthVecTemp.SetX(lastZDepthVecTemp.X()*weightLastZDepth + curZDepthVecTemp.X()*weightCurZDepth);
		interpZDepthVecTemp.SetY(lastZDepthVecTemp.Y()*weightLastZDepth + curZDepthVecTemp.Y()*weightCurZDepth);
		interpZDepthVecTemp.SetZ(lastZDepthVecTemp.Z()*weightLastZDepth + curZDepthVecTemp.Z()*weightCurZDepth);
		(outZHeight.zDepthNormals).push_back(interpZDepthVecTemp);

		gp_Vec lastZDepthKappaMaxVecTemp = lastZDepthKappaMaxDirections.at(lastZDepthPntIndex);
		gp_Vec curZDepthKappaMaxVecTemp = curZDepthKappaMaxDirections.at(curZDepthPntIndex);
		gp_Vec interpZDepthKappaMaxVecTemp;
		interpZDepthKappaMaxVecTemp.SetX(lastZDepthKappaMaxVecTemp.X()*weightLastZDepth + curZDepthKappaMaxVecTemp.X()*weightCurZDepth);
		interpZDepthKappaMaxVecTemp.SetY(lastZDepthKappaMaxVecTemp.Y()*weightLastZDepth + curZDepthKappaMaxVecTemp.Y()*weightCurZDepth);
		interpZDepthKappaMaxVecTemp.SetZ(lastZDepthKappaMaxVecTemp.Z()*weightLastZDepth + curZDepthKappaMaxVecTemp.Z()*weightCurZDepth);
		(outZHeight.zDepthKappaMaxDirections).push_back(interpZDepthKappaMaxVecTemp);

		gp_Vec lastZDepthKappaMinVecTemp = lastZDepthKappaMinDirections.at(lastZDepthPntIndex);
		gp_Vec curZDepthKappaMinVecTemp = curZDepthKappaMinDirections.at(curZDepthPntIndex);
		gp_Vec interpZDepthKappaMinVecTemp;
		interpZDepthKappaMinVecTemp.SetX(lastZDepthKappaMinVecTemp.X()*weightLastZDepth + curZDepthKappaMinVecTemp.X()*weightCurZDepth);
		interpZDepthKappaMinVecTemp.SetY(lastZDepthKappaMinVecTemp.Y()*weightLastZDepth + curZDepthKappaMinVecTemp.Y()*weightCurZDepth);
		interpZDepthKappaMinVecTemp.SetZ(lastZDepthKappaMinVecTemp.Z()*weightLastZDepth + curZDepthKappaMinVecTemp.Z()*weightCurZDepth);
		(outZHeight.zDepthKappaMinDirections).push_back(interpZDepthKappaMinVecTemp);

		outZHeight.zDepthKappaMax.push_back(weightLastZDepth*lastZDepthKappaMax.at(lastZDepthPntIndex) + weightCurZDepth*curZDepthKappaMax.at(curZDepthPntIndex));
		outZHeight.zDepthKappaMin.push_back(weightLastZDepth*lastZDepthKappaMin.at(lastZDepthPntIndex) + weightCurZDepth*curZDepthKappaMin.at(curZDepthPntIndex));

		outZHeight.zDepthKappaMean.push_back(weightLastZDepth*lastZDepthKappaMean.at(lastZDepthPntIndex) + weightCurZDepth*curZDepthKappaMean.at(curZDepthPntIndex));
		outZHeight.zDepthKappaGaussian.push_back(weightLastZDepth*lastZDepthKappaGaussian.at(lastZDepthPntIndex) + weightCurZDepth*curZDepthKappaGaussian.at(curZDepthPntIndex));

		pntsInIndex = pntsInIndex + 1;
	}
}


