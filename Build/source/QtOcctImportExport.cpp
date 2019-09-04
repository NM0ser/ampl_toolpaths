#include "stdafx.h"

#include "QtOcct.h"


void QtOcct::showExportAmplToolpathDialogSlot(void)
{
	exportAmplToolpathDialog myExportAmplToolpathDialog(this);

	if (myExportAmplToolpathDialog.exec())
	{
		QString activeDirectory = myExportAmplToolpathDialog.getDirectory();
		QString activePrefixName = myExportAmplToolpathDialog.getPrefixName();
		//QString fullExportPath = activeDirectory + "/" + activeFileName;
		//std::string fullSavePathString = fullExportPath.toStdString();

		bool writeTopTips = myExportAmplToolpathDialog.topToolTipPointsCheckBoxChecked();
		bool writeBotTips = myExportAmplToolpathDialog.botToolTipPointsCheckBoxChecked();
		bool writeTopContacts = myExportAmplToolpathDialog.topContactPointsCheckBoxChecked();
		bool writeBotContacts = myExportAmplToolpathDialog.botContactPointsCheckBoxChecked();
		bool writeNormals = myExportAmplToolpathDialog.normalVectorCheckBoxChecked();
		bool writeGenInfo = myExportAmplToolpathDialog.genToolpathInfoCheckBoxChecked();

		if (!myCurrentToolpath.toolpathIsActive)
		{
			textEdit->insertPlainText("Error: No active toolpath found. Nothing to be exported.\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			textEdit->repaint();
		}

		if (writeTopTips && myCurrentToolpath.topToolTipPntsActive())
		{
			if (myCurrentToolpath.topToolTipPntsModActive())
			{
				QString fileName = activePrefixName + "_modTopToolTipPnts.csv";
				QString filePath = activeDirectory + "/" + fileName;

				textEdit->insertPlainText("Writing Modified Top Tool-Tip Points to: " + filePath + "\n");
				textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
				textEdit->repaint();

				ofstream myfile;
				myfile.open(filePath.toStdString(), std::ios::out | std::ios::trunc);

				// Loop that writes the points to a file //
				if (myfile.is_open())
				{
					myfile << "X,Y,Z" << std::endl;
					myfile << std::fixed << std::setprecision(4);
					for (const std::vector<float> &i : myCurrentToolpath.topToolTipPntsMod)
					{
						int jCount = 0;
						for (const float &j : i)
						{
							if (jCount < 2)
							{
								myfile << j << ",";
							}
							else
							{
								myfile << j << std::endl;
							}
							jCount = jCount + 1;
						}
					}
					myfile.close();
				}
				else
				{
					textEdit->insertPlainText("ERROR: Could not open file.\n");
					textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
					textEdit->repaint();
				}

			}

			QString fileName = activePrefixName + "_topToolTipPnts.csv";
			QString filePath = activeDirectory + "/" + fileName;

			textEdit->insertPlainText("Writing Top Tool-Tip Points to: " + filePath + "\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			textEdit->repaint();

			ofstream myfile;
			myfile.open(filePath.toStdString(), std::ios::out | std::ios::trunc);

			// Loop that writes the points to a file //
			if (myfile.is_open())
			{
				myfile << "X,Y,Z" << std::endl;
				myfile << std::fixed << std::setprecision(4);
				for (const std::vector<float> &i : myCurrentToolpath.topToolTipPnts)
				{
					int jCount = 0;
					for (const float &j : i)
					{
						if (jCount < 2)
						{
							myfile << j << ",";
						}
						else
						{
							myfile << j << std::endl;
						}
						jCount = jCount + 1;
					}
				}
				myfile.close();
			}
			else
			{
				textEdit->insertPlainText("ERROR: Could not open file.\n");
				textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
				textEdit->repaint();
			}

		}

		if (writeBotTips && myCurrentToolpath.botToolTipPntsActive())
		{
			if (myCurrentToolpath.botToolTipPntsModActive())
			{
				QString fileName = activePrefixName + "_modBotToolTipPnts.csv";
				QString filePath = activeDirectory + "/" + fileName;

				textEdit->insertPlainText("Writing Modified Bottom Tool-Tip Points to: " + filePath + "\n");
				textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
				textEdit->repaint();

				ofstream myfile;
				myfile.open(filePath.toStdString(), std::ios::out | std::ios::trunc);

				// Loop that writes the points to a file //
				if (myfile.is_open())
				{
					myfile << "X,Y,Z" << std::endl;
					myfile << std::fixed << std::setprecision(4);
					for (const std::vector<float> &i : myCurrentToolpath.botToolTipPntsMod)
					{
						int jCount = 0;
						for (const float &j : i)
						{
							if (jCount < 2)
							{
								myfile << j << ",";
							}
							else
							{
								myfile << j << std::endl;
							}
							jCount = jCount + 1;
						}
					}
					myfile.close();
				}
				else
				{
					textEdit->insertPlainText("ERROR: Could not open file.\n");
					textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
					textEdit->repaint();
				}

			}

			QString fileName = activePrefixName + "_botToolTipPnts.csv";
			QString filePath = activeDirectory + "/" + fileName;

			textEdit->insertPlainText("Writing Bottom Tool-Tip Points to: " + filePath + "\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			textEdit->repaint();

			ofstream myfile;
			myfile.open(filePath.toStdString(), std::ios::out | std::ios::trunc);

			// Loop that writes the points to a file //
			if (myfile.is_open())
			{
				myfile << "X,Y,Z" << std::endl;
				myfile << std::fixed << std::setprecision(4);
				for (const std::vector<float> &i : myCurrentToolpath.botToolTipPnts)
				{
					int jCount = 0;
					for (const float &j : i)
					{
						if (jCount < 2)
						{
							myfile << j << ",";
						}
						else
						{
							myfile << j << std::endl;
						}
						jCount = jCount + 1;
					}
				}
				myfile.close();
			}
			else
			{
				textEdit->insertPlainText("ERROR: Could not open file.\n");
				textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
				textEdit->repaint();
			}

		}

		if (writeTopContacts && myCurrentToolpath.topContactPntsActive())
		{
			if (writeNormals && myCurrentToolpath.topContactPntsSurfPropsActive())
			{
				QString fileName = activePrefixName + "_topContactPnts.csv";
				QString filePath = activeDirectory + "/" + fileName;

				textEdit->insertPlainText("Writing Top Tool Contact Points with Surface Properties to: " + filePath + "\n");
				textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
				textEdit->repaint();

				ofstream myfile;
				myfile.open(filePath.toStdString(), std::ios::out | std::ios::trunc);

				// Loop that writes the points to a file //
				if (myfile.is_open())
				{
					myfile << "contactPntX,contactPntY,contactPntZ,normalX,normalY,normalZ,maxCurvature,maxCurvDirectionX,maxCurvDirectionY,maxCurvDirectionZ,minCurvature,minCurvDirectionX,minCurvDirectionY,minCurvDirectionZ,meanCurvature,GaussianCurvature,endOfRevolution(T/F)" << std::endl;
					myfile << std::fixed << std::setprecision(4);
					if (myCurrentToolpath.topContactPnts.size() == myCurrentToolpath.topContactPntsSurfProps.size())
					{
						int curPntIndex = 0;
						int contourCount = 0;
						for (const std::vector<float> &i : myCurrentToolpath.topContactPnts)
						{
							int lastContourPntIndex;
							if (contourCount < myCurrentToolpath.contourIndices.size())
								lastContourPntIndex = myCurrentToolpath.contourIndices.at(contourCount);
							else
								lastContourPntIndex = myCurrentToolpath.contourIndices.back();

							int kCount = 0;
							for (const float &j : i)
							{
								myfile << j << ",";
							}
							for (const float &k : myCurrentToolpath.topContactPntsSurfProps.at(curPntIndex))
							{
								myfile << k << ",";
								kCount = kCount + 1;
							}

							if (curPntIndex == lastContourPntIndex)
							{
								myfile << 1 << std::endl;
								contourCount++;
							}
							else
								myfile << 0 << std::endl;

							curPntIndex++;
						}
						myfile.close();
					}
					else
					{
						myfile.close();
						textEdit->insertPlainText("ERROR: Could not write Top Contact points with Surface Properties due to differently sized arrays.\n");
						textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
						textEdit->repaint();

						QString fileName2 = activePrefixName + "_topContactPntsSurfProps.csv";
						QString filePath2 = activeDirectory + "/" + fileName2;

						ofstream myfile2;
						myfile2.open(filePath2.toStdString(), std::ios::out | std::ios::trunc);

						// Loop that writes the points to a file //
						if (myfile2.is_open())
						{
							myfile2 << "normalX,normalY,normalZ,maxCurvature,maxCurvDirectionX,maxCurvDirectionY,maxCurvDirectionZ,minCurvature,minCurvDirectionX,minCurvDirectionY,minCurvDirectionZ,meanCurvature,GaussianCurvature" << std::endl;
							myfile2 << std::fixed << std::setprecision(4);
							for (const std::vector<float> &i : myCurrentToolpath.topContactPntsSurfProps)
							{
								int jCount = 0;
								for (const float &j : i)
								{
									if (jCount < 12)
									{
										myfile2 << j << ",";
									}
									else
									{
										myfile2 << j << std::endl;
									}
									jCount = jCount + 1;
								}
							}
						}
						else
						{
							textEdit->insertPlainText("ERROR: Could not open file.\n");
							textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum()); 
							textEdit->repaint();
						}
						myfile2.close();
					}
				}
				else
				{
					textEdit->insertPlainText("ERROR: Could not open file.\n");
					textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
					textEdit->repaint();
				}

			}
			else
			{
				QString fileName = activePrefixName + "_topContactPnts.csv";
				QString filePath = activeDirectory + "/" + fileName;

				textEdit->insertPlainText("Writing Top Tool Contact Points to: " + filePath + "\n");
				textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
				textEdit->repaint();

				ofstream myfile;
				myfile.open(filePath.toStdString(), std::ios::out | std::ios::trunc);

				// Loop that writes the points to a file //
				if (myfile.is_open())
				{
					myfile << "X,Y,Z,endOfRevolution(T/F)" << std::endl;
					myfile << std::fixed << std::setprecision(4);
					int curPntIndex = 0;
					int contourCount = 0;
					for (const std::vector<float> &i : myCurrentToolpath.topContactPnts)
					{
						int lastContourPntIndex;
						if (contourCount < myCurrentToolpath.contourIndices.size())
							lastContourPntIndex = myCurrentToolpath.contourIndices.at(contourCount);
						else
							lastContourPntIndex = myCurrentToolpath.contourIndices.back();

						int jCount = 0;
						for (const float &j : i)
						{
							myfile << j << ",";
							jCount = jCount + 1;
						}

						if (curPntIndex == lastContourPntIndex)
						{
							myfile << 1 << std::endl;
							contourCount++;
						}
						else
							myfile << 0 << std::endl;
						
						curPntIndex++;
					}
					myfile.close();
				}
				else
				{
					textEdit->insertPlainText("ERROR: Could not open file.\n");
					textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
					textEdit->repaint();
				}
			}
		}

		if (writeBotContacts && myCurrentToolpath.botContactPntsActive())
		{
			if (writeNormals && myCurrentToolpath.botContactPntsSurfPropsActive())
			{
				QString fileName = activePrefixName + "_botContactPnts.csv";
				QString filePath = activeDirectory + "/" + fileName;

				textEdit->insertPlainText("Writing Bottom Tool Contact Points with Surface Properties to: " + filePath + "\n");
				textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
				textEdit->repaint();

				ofstream myfile;
				myfile.open(filePath.toStdString(), std::ios::out | std::ios::trunc);

				// Loop that writes the points to a file //
				if (myfile.is_open())
				{
					myfile << "contactPntX,contactPntY,contactPntZ,normalX,normalY,normalZ,maxCurvature,maxCurvDirectionX,maxCurvDirectionY,maxCurvDirectionZ,minCurvature,minCurvDirectionX,minCurvDirectionY,minCurvDirectionZ,meanCurvature,GaussianCurvature,endOfRevolution(T/F)" << std::endl;
					myfile << std::fixed << std::setprecision(4);
					if (myCurrentToolpath.botContactPnts.size() == myCurrentToolpath.botContactPntsSurfProps.size())
					{
						int curPntIndex = 0;
						int contourCount = 0;
						for (const std::vector<float> &i : myCurrentToolpath.botContactPnts)
						{
							int lastContourPntIndex;
							if (contourCount < myCurrentToolpath.contourIndices.size())
								lastContourPntIndex = myCurrentToolpath.contourIndices.at(contourCount);
							else
								lastContourPntIndex = myCurrentToolpath.contourIndices.back();

							int kCount = 0;
							for (const float &j : i)
							{
								myfile << j << ",";
							}
							for (const float &k : myCurrentToolpath.botContactPntsSurfProps.at(curPntIndex))
							{
								myfile << k << ",";
								kCount = kCount + 1;
							}

							if (curPntIndex == lastContourPntIndex)
							{
								myfile << 1 << std::endl;
								contourCount++;
							}
							else
								myfile << 0 << std::endl;

							curPntIndex++;
						}
						myfile.close();
					}
					else
					{
						myfile.close();
						textEdit->insertPlainText("ERROR: Could not write Bottom Contact points with Surface Properties due to differently sized arrays.\n");
						textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
						textEdit->repaint();

						QString fileName2 = activePrefixName + "_botContactPntsSurfProps.csv";
						QString filePath2 = activeDirectory + "/" + fileName2;

						ofstream myfile2;
						myfile2.open(filePath2.toStdString(), std::ios::out | std::ios::trunc);

						// Loop that writes the points to a file //
						if (myfile2.is_open())
						{
							myfile2 << "normalX,normalY,normalZ,maxCurvature,maxCurvDirectionX,maxCurvDirectionY,maxCurvDirectionZ,minCurvature,minCurvDirectionX,minCurvDirectionY,minCurvDirectionZ,meanCurvature,GaussianCurvature" << std::endl;
							myfile2 << std::fixed << std::setprecision(4);
							for (const std::vector<float> &i : myCurrentToolpath.botContactPntsSurfProps)
							{
								int jCount = 0;
								for (const float &j : i)
								{
									if (jCount < 12)
									{
										myfile2 << j << ",";
									}
									else
									{
										myfile2 << j << std::endl;
									}
									jCount = jCount + 1;
								}
							}
						}
						else
						{
							textEdit->insertPlainText("ERROR: Could not open file.\n");
							textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
							textEdit->repaint();
						}
						myfile2.close();
					}
				}
				else
				{
					textEdit->insertPlainText("ERROR: Could not open file.\n");
					textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
					textEdit->repaint();
				}

			}
			else
			{
				QString fileName = activePrefixName + "_botContactPnts.csv";
				QString filePath = activeDirectory + "/" + fileName;

				textEdit->insertPlainText("Writing Bottom Tool Contact Points to: " + filePath + "\n");
				textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
				textEdit->repaint();

				ofstream myfile;
				myfile.open(filePath.toStdString(), std::ios::out | std::ios::trunc);

				// Loop that writes the points to a file //
				if (myfile.is_open())
				{
					myfile << "X,Y,Z,endOfRevolution(T/F)" << std::endl;
					myfile << std::fixed << std::setprecision(4);

					int curPntIndex = 0;
					int contourCount = 0;
					for (const std::vector<float> &i : myCurrentToolpath.botContactPnts)
					{
						int lastContourPntIndex;
						if (contourCount < myCurrentToolpath.contourIndices.size())
							lastContourPntIndex = myCurrentToolpath.contourIndices.at(contourCount);
						else
							lastContourPntIndex = myCurrentToolpath.contourIndices.back();

						int jCount = 0;
						for (const float &j : i)
						{
							myfile << j << ",";
							jCount = jCount + 1;
						}

						if (curPntIndex == lastContourPntIndex)
						{
							myfile << 1 << std::endl;
							contourCount++;
						}
						else
							myfile << 0 << std::endl;

						curPntIndex++;
					}
					myfile.close();
				}
				else
				{
					textEdit->insertPlainText("ERROR: Could not open file.\n");
					textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
					textEdit->repaint();
				}

			}
		}

		if (writeGenInfo && myCurrentToolpath.toolpathIsActive)
		{
			QString fileName = activePrefixName + "_genInfo.txt";
			QString filePath = activeDirectory + "/" + fileName;

			textEdit->insertPlainText("Writing General Toolpath Information to: " + filePath + "\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			textEdit->repaint();

			// Write information to the file //
			ofstream myfile;
			myfile.open(filePath.toStdString(), std::ios::out | std::ios::trunc);

			if (myfile.is_open())
			{
				myfile << std::fixed << std::setprecision(4);
				if (myCurrentToolpath.myIncFormingMethodType == amplToolpath::incFormingMethodType::SPIF)
				{
					myfile << "Incremental Forming Method: Single-Point Incremental Forming" << std::endl;
				}
				else if (myCurrentToolpath.myIncFormingMethodType == amplToolpath::incFormingMethodType::TPIF)
				{
					myfile << "Incremental Forming Method: Two-Point Incremental Forming" << std::endl;
					if (myCurrentToolpath.myTpifDieType == amplToolpath::tpifDieType::male)
					{
						myfile << "TPIF Die Type: male" << std::endl;
					}
					else if (myCurrentToolpath.myTpifDieType == amplToolpath::tpifDieType::female)
					{
						myfile << "TPIF Die Type: female" << std::endl;
					}
				}
				else if (myCurrentToolpath.myIncFormingMethodType == amplToolpath::incFormingMethodType::DSIF)
				{
					myfile << "Incremental Forming Method: Double-Sided Incremental Forming" << std::endl;
				}
				else if (myCurrentToolpath.myIncFormingMethodType == amplToolpath::incFormingMethodType::ADSIF)
				{
					myfile << "Incremental Forming Method: Accumulated Double-Sided Incremental Forming" << std::endl;
				}

				if (myCurrentToolpath.myFormingDirectionType == amplToolpath::formingDirectionType::posZDir)
				{
					myfile << "Forming Direction: Positive Z-Direction" << std::endl;
					if (myCurrentToolpath.myIncFormingMethodType == amplToolpath::incFormingMethodType::TPIF ||
						myCurrentToolpath.myIncFormingMethodType == amplToolpath::incFormingMethodType::SPIF)
					{
						myfile << "Bottom Tool Diameter: " << myCurrentToolpath.botToolDiam << " [mm]" << std::endl;
						if (myCurrentToolpath.botToolCornerRadiusActive())
							myfile << "Bottom Tool Corner Radius: " << myCurrentToolpath.botToolCornerRad << " [mm]" << std::endl;
					}
					else
					{
						myfile << "Top Tool Diameter: " << myCurrentToolpath.topToolDiam << " [mm]" << std::endl;
						if (myCurrentToolpath.topToolCornerRadiusActive())
							myfile << "Top Tool Corner Radius: " << myCurrentToolpath.topToolCornerRad << " [mm]" << std::endl;

						myfile << "Bottom Tool Diameter: " << myCurrentToolpath.botToolDiam << " [mm]" << std::endl;
						if (myCurrentToolpath.botToolCornerRadiusActive())
							myfile << "Bottom Tool Corner Radius: " << myCurrentToolpath.botToolCornerRad << " [mm]" << std::endl;
					}

					float accum = 0;
					std::vector< std::vector<float> > toolTipsLocal;
					if (myCurrentToolpath.botToolTipPntsModActive())
						toolTipsLocal = myCurrentToolpath.botToolTipPntsMod;
					else
						toolTipsLocal = myCurrentToolpath.botToolTipPnts;

					int iCount = 0;
					for (const std::vector<float> &i : toolTipsLocal)
					{
						float diffInc;
						if (iCount > 0)
						{
							std::vector<float> curr = toolTipsLocal.at(iCount);
							std::vector<float> last = toolTipsLocal.at(iCount - 1);
							diffInc = sqrtf(pow(curr.at(0)-last.at(0), 2) + pow(curr.at(1) - last.at(1), 2) + pow(curr.at(2) - last.at(2), 2));
							accum = accum + diffInc;
						}
						iCount = iCount + 1;
					}
					myfile << "Toolpath Length Along Bottom Tool Tip Points: " << accum << " [mm]" << std::endl;
				}
				else if (myCurrentToolpath.myFormingDirectionType == amplToolpath::formingDirectionType::negZDir)
				{
					myfile << "Forming Direction: Negative Z-Direction" << std::endl;
					if (myCurrentToolpath.myIncFormingMethodType == amplToolpath::incFormingMethodType::TPIF ||
						myCurrentToolpath.myIncFormingMethodType == amplToolpath::incFormingMethodType::SPIF)
					{
						myfile << "Top Tool Diameter: " << myCurrentToolpath.topToolDiam << " [mm]" << std::endl;
						if (myCurrentToolpath.topToolCornerRadiusActive())
							myfile << "Top Tool Corner Radius: " << myCurrentToolpath.topToolCornerRad << " [mm]" << std::endl;
					}
					else
					{
						myfile << "Top Tool Diameter: " << myCurrentToolpath.topToolDiam << " [mm]" << std::endl;
						if (myCurrentToolpath.topToolCornerRadiusActive())
							myfile << "Top Tool Corner Radius: " << myCurrentToolpath.topToolCornerRad << " [mm]" << std::endl;

						myfile << "Bottom Tool Diameter: " << myCurrentToolpath.botToolDiam << " [mm]" << std::endl;
						if (myCurrentToolpath.botToolCornerRadiusActive())
							myfile << "Bottom Tool Corner Radius: " << myCurrentToolpath.botToolCornerRad << " [mm]" << std::endl;
					}

					float accum = 0;
					std::vector< std::vector<float> > toolTipsLocal;
					if (myCurrentToolpath.topToolTipPntsModActive())
						toolTipsLocal = myCurrentToolpath.topToolTipPntsMod;
					else
						toolTipsLocal = myCurrentToolpath.topToolTipPnts;

					int iCount = 0;
					for (const std::vector<float> &i : toolTipsLocal)
					{
						float diffInc;
						if (iCount > 0)
						{
							std::vector<float> curr = toolTipsLocal.at(iCount);
							std::vector<float> last = toolTipsLocal.at(iCount - 1);
							diffInc = sqrtf(pow(curr.at(0) - last.at(0), 2) + pow(curr.at(1) - last.at(1), 2) + pow(curr.at(2) - last.at(2), 2));
							accum = accum + diffInc;
						}
						iCount = iCount + 1;
					}
					myfile << "Toolpath Length Along Top Tool Tip Points: " << accum << " [mm]" << std::endl;
				}

				if (myCurrentToolpath.mytoolpathMethodType == amplToolpath::toolpathMethodType::contour)
				{
					myfile << "Toolpath Method: Z-Level Contour Slicing" << std::endl;
				}
				else if (myCurrentToolpath.mytoolpathMethodType == amplToolpath::toolpathMethodType::spiral)
				{
					myfile << "Toolpath Method: Continuous Spiral" << std::endl;
				}

				if(myCurrentToolpath.adaptiveSlicingOn)
					myfile << "Maximum Increment Along Surface (Adaptive Z-Slicing): " << myCurrentToolpath.incDepth << " [mm]" << std::endl;
				else
					myfile << "Incremental Depth (contour) or Pitch (spiral): " << myCurrentToolpath.incDepth << " [mm]" << std::endl;

				myfile << "Start Z-Height of Algorithm: " << myCurrentToolpath.startDepth << " [mm]" << std::endl;
				myfile << "End Z-Height of Algorithm: " << myCurrentToolpath.endDepth << " [mm]" << std::endl;
				myfile << "Sheet Thickness: " << myCurrentToolpath.sheetThickness << " [mm]" << std::endl;

				if (myCurrentToolpath.myIncFormingMethodType == amplToolpath::incFormingMethodType::TPIF ||
					myCurrentToolpath.myIncFormingMethodType == amplToolpath::incFormingMethodType::DSIF ||
					myCurrentToolpath.myIncFormingMethodType == amplToolpath::incFormingMethodType::ADSIF)
				{
					myfile << "Squeeze Factor: " << myCurrentToolpath.sqzFactor << std::endl;
				}

				myfile << "Resolution Along Toolpath Curve: " << myCurrentToolpath.incToolpathCurve << " [mm]" << std::endl;

				if (myCurrentToolpath.goingCCW)
					myfile << "Toolpath Direction: Counter-Clockwise (CCW)" << std::endl;
				else
					myfile << "Toolpath Direction: Clockwise (CW)" << std::endl;

				myfile << "Angle (CCW from X-axis in XY-Plane) and Radial Distance of the Starting Construction Point: " << myCurrentToolpath.startAngleFromXAxisDeg << " [deg]    " << myCurrentToolpath.startRadialDistance << " [mm]" << std::endl;

				myfile.close();
			}
			else
			{
				textEdit->insertPlainText("ERROR: Could not open file.\n");
				textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
				textEdit->repaint();
			}

		}
	}
}

void QtOcct::showSaveAmplToolpathDialogSlot(void)
{
	saveAmplToolpathDialog mySaveAmplToolpathDialog(this);

	if (mySaveAmplToolpathDialog.exec())
	{
		if (!myCurrentToolpath.toolpathIsActive)
		{
			textEdit->insertPlainText("Warning: No active toolpath found.\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		}

		QString activeDirectory = mySaveAmplToolpathDialog.getDirectory();
		QString activeFileName = mySaveAmplToolpathDialog.getFileName();
		QString fullSavePath = activeDirectory + "/" + activeFileName;
		std::string fullSavePathString = fullSavePath.toStdString();

		textEdit->insertPlainText("Saving to: ");
		textEdit->insertPlainText(fullSavePath);
		textEdit->insertPlainText("\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());

		{
			std::ofstream saveAmplFileStream(fullSavePathString, std::ios::binary);
			cereal::BinaryOutputArchive archive(saveAmplFileStream);
			//cereal::XMLOutputArchive archive( saveAmplFileSteram );

			//myCurrentToolpath.toolpathIsActive = true;
			//myCurrentToolpath.topContactPnts.front() = {0.0, 0.0, 0.0};

			archive(myCurrentToolpath);
		}
	}
}

void QtOcct::showOpenAmplToolpathDialogSlot(void)
{
	openAmplToolpathDialog myOpenAmplToolpathDialog(this);

	if (myOpenAmplToolpathDialog.exec())
	{
		QString fullLoadPath = myOpenAmplToolpathDialog.getFilePath();
		std::string fullLoadPathString = fullLoadPath.toStdString();

		textEdit->insertPlainText("Opening: ");
		textEdit->insertPlainText(fullLoadPath);
		textEdit->insertPlainText("\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());

		//amplToolpath localAmplToolpath;
		{
			std::ifstream loadAmplFileStream(fullLoadPathString, std::ios::binary);
			cereal::BinaryInputArchive archive(loadAmplFileStream);

			archive(myCurrentToolpath);
		}
		//myCurrentToolpath.copy(localAmplToolpath);

		if (!myCurrentToolpath.toolpathIsActive)
		{
			textEdit->insertPlainText("Warning: No active toolpath found.\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		}
		if (myCurrentToolpath.topContactPntsActive() || myCurrentToolpath.botContactPntsActive())
		{
			textEdit->insertPlainText("Loaded contact points.\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		}
		if (myCurrentToolpath.topToolTipPntsModActive() || myCurrentToolpath.botToolTipPntsModActive())
		{
			textEdit->insertPlainText("Loaded modified and original tool tip points.\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		}
		else if (myCurrentToolpath.topToolTipPntsActive() || myCurrentToolpath.botToolTipPntsActive())
		{
			textEdit->insertPlainText("Loaded tool tip points.\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		}

		setToolpathVisibilitySlot(true);
		setToolpathVisibilitySlot(false);
	}
}

void QtOcct::setToolpathVisibilitySlot(bool hideAll)
{
	if (hideAll)
	{
		myContext->Remove(myAisTopContactPnts);
		myContext->Remove(myAisBotContactPnts);
		myContext->Remove(myAisTopToolTips);
		myContext->Remove(myAisBotToolTips);
		
		myAisTopContactPnts.Nullify();
		myAisBotContactPnts.Nullify();
		myAisTopToolTips.Nullify();
		myAisBotToolTips.Nullify();

		myCurrentTopContactPnts.Nullify();
		myCurrentBotContactPnts.Nullify();
		myCurrentTopToolTips.Nullify();
		myCurrentBotToolTips.Nullify();

		//textEdit->insertPlainText("All toolpaths hidden.\n");
		//textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
	}
	else
	{
		if (myCurrentToolpath.topContactPntsActive())
		{
			//textEdit->insertPlainText("Changing visualization of the top contact points...");
			//textEdit->repaint();
			toolpathVisibilityDialog::toolpathName pathType = toolpathVisibilityDialog::toolpathName::TOP_CONTACT;
			myToolpathVisibilityDialog->buildToolpathRenderObject(pathType, myCurrentToolpath.topContactPnts, myCurrentTopContactPnts, myAisTopContactPnts, myContext);
			//textEdit->insertPlainText(" Success!\n");
			//textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			//textEdit->repaint();
		}

		if (myCurrentToolpath.botContactPntsActive())
		{
			//textEdit->insertPlainText("Changing visualization of the bottom contact points...");
			//textEdit->repaint();
			toolpathVisibilityDialog::toolpathName pathType = toolpathVisibilityDialog::toolpathName::BOT_CONTACT;
			myToolpathVisibilityDialog->buildToolpathRenderObject(pathType, myCurrentToolpath.botContactPnts, myCurrentBotContactPnts, myAisBotContactPnts, myContext);
			//textEdit->insertPlainText(" Success!\n");
			//textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			//textEdit->repaint();
		}

		if (myCurrentToolpath.topToolTipPntsModActive())
		{
			toolpathVisibilityDialog::toolpathName pathType = toolpathVisibilityDialog::toolpathName::TOP_TIP;
			if (myToolpathVisibilityDialog->showModPointsChecked(pathType))
			{
				//textEdit->insertPlainText("Changing visualization of the modified top tool tip points...");
				//textEdit->repaint();
				myToolpathVisibilityDialog->buildToolpathRenderObject(pathType, myCurrentToolpath.topToolTipPntsMod, myCurrentTopToolTips, myAisTopToolTips, myContext);
				//textEdit->insertPlainText(" Success!\n");
				//textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
				//textEdit->repaint();
			}
			else
			{
				//textEdit->insertPlainText("Changing visualization of the top tool tip points...");
				//textEdit->repaint();
				myToolpathVisibilityDialog->buildToolpathRenderObject(pathType, myCurrentToolpath.topToolTipPnts, myCurrentTopToolTips, myAisTopToolTips, myContext);
				//textEdit->insertPlainText(" Success!\n");
				//textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
				//textEdit->repaint();
			}
		}
		else if (myCurrentToolpath.topToolTipPntsActive())
		{
			//textEdit->insertPlainText("Changing visualization of the top tool tip points...");
			//textEdit->repaint();
			toolpathVisibilityDialog::toolpathName pathType = toolpathVisibilityDialog::toolpathName::TOP_TIP;
			myToolpathVisibilityDialog->buildToolpathRenderObject(pathType, myCurrentToolpath.topToolTipPnts, myCurrentTopToolTips, myAisTopToolTips, myContext);
			//textEdit->insertPlainText(" Success!\n");
			//textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			//textEdit->repaint();
		}

		if (myCurrentToolpath.botToolTipPntsModActive())
		{
			toolpathVisibilityDialog::toolpathName pathType = toolpathVisibilityDialog::toolpathName::BOT_TIP;
			if (myToolpathVisibilityDialog->showModPointsChecked(pathType))
			{
				//textEdit->insertPlainText("Changing visualization of the modified bottom tool tip points...");
				//textEdit->repaint();
				myToolpathVisibilityDialog->buildToolpathRenderObject(pathType, myCurrentToolpath.botToolTipPntsMod, myCurrentBotToolTips, myAisBotToolTips, myContext);
				//textEdit->insertPlainText(" Success!\n");
				//textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
				//textEdit->repaint();
			}
			else
			{
				//textEdit->insertPlainText("Changing visualization of the bottom tool tip points...");
				//textEdit->repaint();
				myToolpathVisibilityDialog->buildToolpathRenderObject(pathType, myCurrentToolpath.botToolTipPnts, myCurrentBotToolTips, myAisBotToolTips, myContext);
				//textEdit->insertPlainText(" Success!\n");
				//textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
				//textEdit->repaint();
			}
		}
		else if (myCurrentToolpath.botToolTipPntsActive())
		{
			//textEdit->insertPlainText("Changing visualization of the bottom tool tip points...");
			//textEdit->repaint();
			toolpathVisibilityDialog::toolpathName pathType = toolpathVisibilityDialog::toolpathName::BOT_TIP;
			myToolpathVisibilityDialog->buildToolpathRenderObject(pathType, myCurrentToolpath.botToolTipPnts, myCurrentBotToolTips, myAisBotToolTips, myContext);
			//textEdit->insertPlainText(" Success!\n");
			//textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			//textEdit->repaint();
		}
	}
}

void QtOcct::showImportIGSDialogSlot()
{
	importIGSDialog myImportIgsDialog(this);

	if (myImportIgsDialog.exec())
	{
		bool performShapeHealing = myImportIgsDialog.getCheckBoxState();
		QString fullImportPath = myImportIgsDialog.getFilePath();
		QString sewTolStr = myImportIgsDialog.getSewingTolStr();

		bool str2floatOK1 = false;

		sewTolStr.toFloat(&str2floatOK1);
		if (!str2floatOK1)
		{
			textEdit->insertPlainText("ERROR: Could not parse user input. Are you sure you entered only numbers?\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			return;
		}

		Standard_Real sewTol = abs(sewTolStr.toFloat());

		if (fullImportPath.isEmpty())
		{
			textEdit->insertPlainText("ERROR: Empty path, could not find the file to import.\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			return;
		}

		textEdit->insertPlainText("Opening: ");
		textEdit->insertPlainText(fullImportPath);
		textEdit->insertPlainText("\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		textEdit->repaint();

		// Perform OpenCASCADE Import Functions
		std::string fullImportPathTemp = fullImportPath.toStdString();
		const char *fullImportPathTempPtr = fullImportPathTemp.c_str();
		IGESControl_Reader IGESReader;
		IFSelect_ReturnStatus igesReaderStatus = IGESReader.ReadFile(fullImportPathTempPtr);
		if (igesReaderStatus != IFSelect_ReturnStatus::IFSelect_RetDone)
		{
			textEdit->insertPlainText("ERROR: Could not read/find file.\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			return;
		}

		if (!Interface_Static::SetIVal("read.precision.mode", 1))
		{
		} // Handle error

		if (!Interface_Static::SetRVal("read.precision.val", 0.001))
		{
		} // Handle error

		Handle(TColStd_HSequenceOfTransient)  faceListFromReader = IGESReader.GiveList("iges-faces");
		textEdit->insertPlainText("Translating all face entities... ");

		Standard_Integer listIter;
		Standard_Integer listLength = faceListFromReader->Length();
		for (listIter = 1; listIter <= listLength; listIter++)
		{
			Handle(Standard_Transient) faceEntity = faceListFromReader->Value(listIter);
			Standard_Boolean OK = IGESReader.TransferEntity(faceEntity);
			if (!OK)
			{
				textEdit->insertPlainText("\nERROR: A face failed to translate successfully into the OpenCASCADE library.\n");
				textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
				return;
			}
		}
		TopoDS_Shape importedShapeRaw = IGESReader.OneShape();
		if (importedShapeRaw.IsNull())
		{
			textEdit->insertPlainText("\nERROR: Imported shape is NULL.\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			return;
		}
		textEdit->insertPlainText("Success!\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		textEdit->repaint();

		// Now sew surfaces together
		BRepBuilderAPI_Sewing sewBuilder;
		sewBuilder.SetTolerance(sewTol*1.0);
		sewBuilder.SetMaxTolerance(sewTol*3.0);
		sewBuilder.SetMinTolerance(sewTol / 2.0);
		TopExp_Explorer explorerFace(importedShapeRaw, TopAbs_ShapeEnum::TopAbs_FACE);
		for (; explorerFace.More(); explorerFace.Next())
		{
			sewBuilder.Add(TopoDS::Face(explorerFace.Current()));
		}
		sewBuilder.Perform();
		TopoDS_Shape importedShapeSewn = sewBuilder.SewedShape();
		if (importedShapeSewn.IsNull())
		{
			textEdit->insertPlainText("ERROR: Imported faces could not be sewn together.\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			return;
		}
		textEdit->insertPlainText("Imported faces have been successfully sewn together.\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		textEdit->repaint();

		// Rebuild shape as a single shell entity
		TopoDS_Shell importedShapeShell;
		BRep_Builder TopoDsShellBuilder;
		TopoDsShellBuilder.MakeShell(importedShapeShell);

		explorerFace.Init(importedShapeSewn, TopAbs_ShapeEnum::TopAbs_FACE);
		while (explorerFace.More())
		{
			TopoDsShellBuilder.Add(importedShapeShell, TopoDS::Face(explorerFace.Current()));
			explorerFace.Next();
		}

		if (importedShapeShell.IsNull())
		{
			textEdit->insertPlainText("ERROR: Resultant shape failed to be cast into a single shell type.\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			return;
		}

		TopoDS_Shape importedShapeFixed;
		if (performShapeHealing)
		{
			// Perform shape healing and fixing small edges
			Handle(ShapeFix_Shape) sfs = new ShapeFix_Shape;
			sfs->Init(importedShapeShell);
			sfs->SetPrecision(sewTol);
			sfs->SetMaxTolerance(sewTol*3.0);
			sfs->SetMinTolerance(sewTol / 2.0);
			sfs->Perform();
			TopoDS_Shape importedShapeHealed = sfs->Shape();

			Handle(ShapeFix_Wireframe) SFWF = new ShapeFix_Wireframe(importedShapeHealed);
			SFWF->SetPrecision(sewTol);
			SFWF->SetMaxTolerance(sewTol*3.0);
			SFWF->ModeDropSmallEdges() = Standard_True;
			SFWF->FixSmallEdges();
			SFWF->FixWireGaps();
			importedShapeFixed = SFWF->Shape();

			textEdit->insertPlainText("Completed face healing and edge fixing.\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			textEdit->repaint();
		}
		else
		{
			importedShapeFixed = importedShapeRaw;
		}

		if (partIsActive)
			myContext->Remove(myAisShape); // A new part will be active, delete old one from viewer context
		else
			partIsActive = true; // First time a part has been added to context

		TopoDS_Compound tempTopoDsCompound;
		BRep_Builder TopoDsCompoundBuilder;
		TopoDsCompoundBuilder.MakeCompound(tempTopoDsCompound);
		TopoDsCompoundBuilder.Add(tempTopoDsCompound, importedShapeFixed);
		myCurrentPart = tempTopoDsCompound;

		if (myAisShape.IsNull())
			myAisShape = new AIS_Shape(myCurrentPart);
		else
		{
			myAisShape.Nullify();
			myAisShape = new AIS_Shape(myCurrentPart);
		}

		myContext->Display(myAisShape);
		textEdit->insertPlainText("Visualizing imported surface... Success!\n");
		textEdit->insertPlainText("NOTE: Check that there are no unwanted free edges (visualized in green) by clicking 'Wireframe' mode. If there are, increase Sewing Tolerance.\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
	}
}

void QtOcct::showExportAsIGSDialogSlot()
{
	if (partIsActive)
	{
		exportIGSDialog myExportIgsDialog(this);

		if (myExportIgsDialog.exec())
		{
			QString activeDirectory = myExportIgsDialog.getDirectory();
			QString activeFileName = myExportIgsDialog.getIGSFileName();
			QString fullExportPath = activeDirectory + "/" + activeFileName;

			textEdit->insertPlainText("Saving to: ");
			textEdit->insertPlainText(fullExportPath);
			textEdit->insertPlainText("\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());

			// Perform OpenCASCADE Export Functions
			IGESControl_Controller IGESController;
			if (!IGESController.Init())
			{
				textEdit->insertPlainText("ERROR: Could not initialize IGES controller.\n");
				textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
				return;
			}
			IGESControl_Writer IGESWriter("MM", 0);

			TopExp_Explorer explorerFace(myCurrentPart, TopAbs_ShapeEnum::TopAbs_FACE);
			while (explorerFace.More())
			{
				if (!IGESWriter.AddShape(TopoDS::Face(explorerFace.Current())))
				{
					textEdit->insertPlainText("ERROR: Could not export all of the faces in your current part.\n");
					textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
					return;
				}
				explorerFace.Next();
			}
			IGESWriter.ComputeModel();

			std::string fullExportPathTemp = fullExportPath.toStdString();
			const char *fullExportPathTempPtr = fullExportPathTemp.c_str();

			if (!IGESWriter.Write(fullExportPathTempPtr))
			{
				textEdit->insertPlainText("ERROR: Failed to write .IGS file.\n");
				textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
				return;
			}

			textEdit->insertPlainText("Success!\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		}
	}
	else
	{
		textEdit->insertPlainText("ERROR: Must have an active part\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
	}
}

void QtOcct::showExportAsSTEPDialogSlot(void)
{
	if (partIsActive)
	{
		exportIGSDialog myExportStepDialog(this);
		myExportStepDialog.changeWindowTitle("Export as STEP");
		myExportStepDialog.changeFileNameText("myPart.STP");

		if (myExportStepDialog.exec())
		{
			QString activeDirectory = myExportStepDialog.getDirectory();
			QString activeFileName = myExportStepDialog.getSTEPFileName();
			QString fullExportPath = activeDirectory + "/" + activeFileName;

			textEdit->insertPlainText("Saving to: ");
			textEdit->insertPlainText(fullExportPath);
			textEdit->insertPlainText("\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());

			// Perform OpenCASCADE Export functions
			STEPControl_Writer stepWriter;

			IFSelect_ReturnStatus transferStatus = stepWriter.Transfer(myCurrentPart, STEPControl_StepModelType::STEPControl_ShellBasedSurfaceModel);

			if (transferStatus != IFSelect_ReturnStatus::IFSelect_RetDone)
			{
				textEdit->insertPlainText("ERROR: Part could not be translated into STEP format.\n");
				textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
				return;
			}

			std::string fullExportPathTemp = fullExportPath.toStdString();
			const char *fullExportPathTempPtr = fullExportPathTemp.c_str();
			transferStatus = stepWriter.Write(fullExportPathTempPtr);

			if (transferStatus != IFSelect_ReturnStatus::IFSelect_RetDone)
			{
				textEdit->insertPlainText("ERROR: Part was translated into STEP format but could not be written to the text file.\n");
				textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
				return;
			}
		}
	}
	else
	{
		textEdit->insertPlainText("ERROR: Must have an active part\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
	}
}

void QtOcct::showImportSTEPDialogSlot(void)
{
	importIGSDialog myImportIgsDialog(this);
	myImportIgsDialog.changeWindowTitle("Import as STEP");
	myImportIgsDialog.setFileFilterToSTEP(true);

	if (myImportIgsDialog.exec())
	{
		bool performShapeHealing = myImportIgsDialog.getCheckBoxState();
		QString fullImportPath = myImportIgsDialog.getFilePath();
		QString sewTolStr = myImportIgsDialog.getSewingTolStr();

		bool str2floatOK1 = false;

		sewTolStr.toFloat(&str2floatOK1);
		if (!str2floatOK1)
		{
			textEdit->insertPlainText("ERROR: Could not parse user input. Are you sure you entered only numbers?\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			return;
		}

		Standard_Real sewTol = abs(sewTolStr.toFloat());

		if (fullImportPath.isEmpty())
		{
			textEdit->insertPlainText("ERROR: Empty path, could not find the file to import.\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			return;
		}

		textEdit->insertPlainText("Opening: ");
		textEdit->insertPlainText(fullImportPath);
		textEdit->insertPlainText("\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		textEdit->repaint();

		// Perform OpenCASCADE Import Functions
		std::string fullImportPathTemp = fullImportPath.toStdString();
		const char *fullImportPathTempPtr = fullImportPathTemp.c_str();
		STEPControl_Reader stepReader;
		IFSelect_ReturnStatus readStatus = stepReader.ReadFile(fullImportPathTempPtr);
		if (readStatus != IFSelect_ReturnStatus::IFSelect_RetDone)
		{
			textEdit->insertPlainText("ERROR: Could not read/find file.\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			return;
		}

		Standard_Integer NbRoots = stepReader.NbRootsForTransfer();
		Standard_Integer numRootsTransferred = stepReader.TransferRoots();

		TopoDS_Shape importedShapeRaw = stepReader.OneShape();
		if (importedShapeRaw.IsNull())
		{
			textEdit->insertPlainText("ERROR: Translation of the STEP file into OpenCASCADE objects failed.\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			return;
		}
		else
		{
			textEdit->insertPlainText("Translating the surfaces from the STEP file into OpenCASCADE objects... Success!\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			textEdit->repaint();
		}

		// Now sew surfaces together
		BRepBuilderAPI_Sewing sewBuilder;
		sewBuilder.SetTolerance(sewTol*1.0);
		sewBuilder.SetMaxTolerance(sewTol*3.0);
		sewBuilder.SetMinTolerance(sewTol / 2.0);
		TopExp_Explorer explorerFace(importedShapeRaw, TopAbs_ShapeEnum::TopAbs_FACE);
		for (; explorerFace.More(); explorerFace.Next())
		{
			sewBuilder.Add(TopoDS::Face(explorerFace.Current()));
		}
		sewBuilder.Perform();
		TopoDS_Shape importedShapeSewn = sewBuilder.SewedShape();
		if (importedShapeSewn.IsNull())
		{
			textEdit->insertPlainText("ERROR: Imported faces could not be sewn together.\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			return;
		}
		textEdit->insertPlainText("Imported faces have been successfully sewn together.\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		textEdit->repaint();

		// Rebuild shape as a single shell entity
		TopoDS_Shell importedShapeShell;
		BRep_Builder TopoDsShellBuilder;
		TopoDsShellBuilder.MakeShell(importedShapeShell);

		explorerFace.Init(importedShapeSewn, TopAbs_ShapeEnum::TopAbs_FACE);
		while (explorerFace.More())
		{
			TopoDsShellBuilder.Add(importedShapeShell, TopoDS::Face(explorerFace.Current()));
			explorerFace.Next();
		}

		if (importedShapeShell.IsNull())
		{
			textEdit->insertPlainText("ERROR: Resultant shape failed to be cast into a single shell type.\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			return;
		}

		TopoDS_Shape importedShapeFixed;
		if (performShapeHealing)
		{
			// Perform shape healing and fixing small edges
			Handle(ShapeFix_Shape) sfs = new ShapeFix_Shape;
			sfs->Init(importedShapeShell);
			sfs->SetPrecision(sewTol);
			sfs->SetMaxTolerance(sewTol*3.0);
			sfs->SetMinTolerance(sewTol / 2.0);
			sfs->Perform();
			TopoDS_Shape importedShapeHealed = sfs->Shape();

			Handle(ShapeFix_Wireframe) SFWF = new ShapeFix_Wireframe(importedShapeHealed);
			SFWF->SetPrecision(sewTol);
			SFWF->SetMaxTolerance(sewTol*3.0);
			SFWF->ModeDropSmallEdges() = Standard_True;
			SFWF->FixSmallEdges();
			SFWF->FixWireGaps();
			importedShapeFixed = SFWF->Shape();

			textEdit->insertPlainText("Completed face healing and edge fixing.\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			textEdit->repaint();
		}
		else
		{
			importedShapeFixed = importedShapeRaw;
		}

		if (partIsActive)
			myContext->Remove(myAisShape); // A new part will be active, delete old one from viewer context
		else
			partIsActive = true; // First time a part has been added to context

		TopoDS_Compound tempTopoDsCompound;
		BRep_Builder TopoDsCompoundBuilder;
		TopoDsCompoundBuilder.MakeCompound(tempTopoDsCompound);
		TopoDsCompoundBuilder.Add(tempTopoDsCompound, importedShapeFixed);
		myCurrentPart = tempTopoDsCompound;

		if (myAisShape.IsNull())
			myAisShape = new AIS_Shape(myCurrentPart);
		else
		{
			myAisShape.Nullify();
			myAisShape = new AIS_Shape(myCurrentPart);
		}

		myContext->Display(myAisShape);
		textEdit->insertPlainText("Visualizing imported surface... Success!\n");
		textEdit->insertPlainText("NOTE: Check that there are no unwanted free edges (visualized in green) by clicking 'Wireframe' mode. If there are, increase Sewing Tolerance.\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
	}
}

void QtOcct::showImportContactPntsDialogSlot(void)
{
	importCSVContactPntsDialog myImportPntsDialog(this);

	if (myImportPntsDialog.exec())
	{
		int importTopBotFiles = 2;
		QString fullTopImportPath = myImportPntsDialog.getTopFilePath();
		QString fullBotImportPath = myImportPntsDialog.getBotFilePath();
		bool skipFirstLineTop = myImportPntsDialog.getSkipFirstLineTopContacts();
		bool skipFirstLineBot = myImportPntsDialog.getSkipFirstLineBotContacts();

		if (fullTopImportPath.isEmpty() && fullBotImportPath.isEmpty())
		{
			textEdit->insertPlainText("ERROR: Empty file paths, could not find the top nor bottom contact points to import.\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			return;
		}
		else if (fullTopImportPath.isEmpty())
		{
			textEdit->insertPlainText("WARNING: Empty file path found, will set the top contact points equal to the bottom contact points.\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			importTopBotFiles = -1;
		}
		else if (fullBotImportPath.isEmpty())
		{
			textEdit->insertPlainText("WARNING: Empty file path found, will set the bottom contact points equal to the top contact points.\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			importTopBotFiles = 1;
		}

		// PARSE CSV FILES; If successful and top + bottom points are equal in length, continue to gather toolpath information
		std::vector< std::vector<float> > topContactPntsCSV;
		std::vector< std::vector<float> > botContactPntsCSV;
		std::vector< std::vector<float> > topContactPntsSurfPropsCSV;
		std::vector< std::vector<float> > botContactPntsSurfPropsCSV;
		std::vector<int> topContourIndicesCSV;
		std::vector<int> botContourIndicesCSV;

		if (importTopBotFiles == 2 || importTopBotFiles == 1) // Parse top contact points
		{
			try { io::CSVReader<17> testIn(fullTopImportPath.toStdString()); }
			catch (io::error::can_not_open_file exception)
			{
				textEdit->insertPlainText("ERROR: Could not open top contact points file.\n");
				textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
				return;
			}

			io::CSVReader<17> topCSVin(fullTopImportPath.toStdString());
			if (skipFirstLineTop)
				topCSVin.next_line();

			topCSVin.set_header("contactPntX", "contactPntY", "contactPntZ", "normalX", "normalY", "normalZ",
				"maxCurvature", "maxCurvDirectionX", "maxCurvDirectionY", "maxCurvDirectionZ",
				"minCurvature", "minCurvDirectionX", "minCurvDirectionY", "minCurvDirectionZ",
				"meanCurvature", "GaussianCurvature", "endOfRevolution");

			float contactPntX = 0.0; float contactPntY = 0.0; float contactPntZ = 0.0;
			float normalX = 0.0; float normalY = 0.0; float normalZ = 1.0;
			float maxCurvature = 0.0; float maxCurvDirectionX = 0.0; float maxCurvDirectionY = 0.0; float maxCurvDirectionZ = 0.0;
			float minCurvature = 0.0; float minCurvDirectionX = 0.0; float minCurvDirectionY = 0.0; float minCurvDirectionZ = 0.0;
			float meanCurvature = 0.0; float GaussianCurvature = 0.0;
			int endOfRevolution = 0;	

			bool notEOF = true;
			while (notEOF)
			{
				try {
					notEOF = topCSVin.read_row(contactPntX, contactPntY, contactPntZ, normalX, normalY, normalZ,
						maxCurvature, maxCurvDirectionX, maxCurvDirectionY, maxCurvDirectionZ,
						minCurvature, minCurvDirectionX, minCurvDirectionY, minCurvDirectionZ,
						meanCurvature, GaussianCurvature, endOfRevolution);
				}
				catch (io::error::too_few_columns exception)
				{
					textEdit->insertPlainText("ERROR: Too few columns in top contacts file.\n");
					textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
					return;
				}
				catch (io::error::too_many_columns exception)
				{
					textEdit->insertPlainText("ERROR: Too many columns in top contacts file.\n");
					textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
					return;
				}
				catch (io::error::no_digit exception)
				{
					textEdit->insertPlainText("ERROR: Expecting numbers but found characters in the top contacts file.\n");
					textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
					return;
				}

				if (notEOF == false) // Current line is End-of-File so not data to store
					break;

				std::vector<float> tempPnt = { contactPntX, contactPntY, contactPntZ };
				std::vector<float> tempProps = { normalX, normalY, normalZ,
					maxCurvature, maxCurvDirectionX, maxCurvDirectionY, maxCurvDirectionZ,
					minCurvature, minCurvDirectionX, minCurvDirectionY, minCurvDirectionZ,
					meanCurvature, GaussianCurvature };

				topContactPntsCSV.push_back(tempPnt);
				topContactPntsSurfPropsCSV.push_back(tempProps);
				topContourIndicesCSV.push_back(endOfRevolution);
			}
		}
		
		if (importTopBotFiles == 2 || importTopBotFiles == -1) // Parse bottom contact points
		{
			try { io::CSVReader<17> testIn(fullBotImportPath.toStdString()); }
			catch (io::error::can_not_open_file exception)
			{
				textEdit->insertPlainText("ERROR: Could not open bottom contact points file.\n");
				textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
				return;
			}

			io::CSVReader<17> botCSVin(fullBotImportPath.toStdString());
			if (skipFirstLineBot)
				botCSVin.next_line();

			botCSVin.set_header("contactPntX", "contactPntY", "contactPntZ", "normalX", "normalY", "normalZ",
				"maxCurvature", "maxCurvDirectionX", "maxCurvDirectionY", "maxCurvDirectionZ",
				"minCurvature", "minCurvDirectionX", "minCurvDirectionY", "minCurvDirectionZ",
				"meanCurvature", "GaussianCurvature", "endOfRevolution");

			float contactPntX = 0.0; float contactPntY = 0.0; float contactPntZ = 0.0;
			float normalX = 0.0; float normalY = 0.0; float normalZ = 1.0;
			float maxCurvature = 0.0; float maxCurvDirectionX = 0.0; float maxCurvDirectionY = 0.0; float maxCurvDirectionZ = 0.0;
			float minCurvature = 0.0; float minCurvDirectionX = 0.0; float minCurvDirectionY = 0.0; float minCurvDirectionZ = 0.0;
			float meanCurvature = 0.0; float GaussianCurvature = 0.0;
			int endOfRevolution = 0;

			bool notEOF = true;
			while (notEOF)
			{
				try {
					notEOF = botCSVin.read_row(contactPntX, contactPntY, contactPntZ, normalX, normalY, normalZ,
						maxCurvature, maxCurvDirectionX, maxCurvDirectionY, maxCurvDirectionZ,
						minCurvature, minCurvDirectionX, minCurvDirectionY, minCurvDirectionZ,
						meanCurvature, GaussianCurvature, endOfRevolution);
				}
				catch (io::error::too_few_columns exception)
				{
					textEdit->insertPlainText("ERROR: Too few columns in bottom contacts file.\n");
					textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
					return;
				}
				catch (io::error::too_many_columns exception)
				{
					textEdit->insertPlainText("ERROR: Too many columns in bottom contacts file.\n");
					textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
					return;
				}
				catch (io::error::no_digit exception)
				{
					textEdit->insertPlainText("ERROR: Expecting numbers but found characters in the bottom contacts file.\n");
					textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
					return;
				}

				if (notEOF == false) // Current line is End-of-File so not data to store
					break;

				std::vector<float> tempPnt = { contactPntX, contactPntY, contactPntZ };
				std::vector<float> tempProps = { normalX, normalY, normalZ,
					maxCurvature, maxCurvDirectionX, maxCurvDirectionY, maxCurvDirectionZ,
					minCurvature, minCurvDirectionX, minCurvDirectionY, minCurvDirectionZ,
					meanCurvature, GaussianCurvature };

				botContactPntsCSV.push_back(tempPnt);
				botContactPntsSurfPropsCSV.push_back(tempProps);
				botContourIndicesCSV.push_back(endOfRevolution);
			}
		}

		if (importTopBotFiles == 1)
		{
			botContactPntsCSV = topContactPntsCSV;
			botContactPntsSurfPropsCSV = topContactPntsSurfPropsCSV;
			botContourIndicesCSV = topContourIndicesCSV;

			QString msg1 = QString("Successfully parsed: ") + fullTopImportPath + QString("\n");
			textEdit->insertPlainText(msg1);
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		}
		else if (importTopBotFiles == -1)
		{
			topContactPntsCSV = botContactPntsCSV;
			topContactPntsSurfPropsCSV = botContactPntsSurfPropsCSV;
			topContourIndicesCSV = botContourIndicesCSV;

			QString msg1 = QString("Successfully parsed: ") + fullBotImportPath + QString("\n");
			textEdit->insertPlainText(msg1);
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		}
		else
		{
			QString msg1 = QString("Successfully parsed: ") + fullTopImportPath + QString("\n");
			textEdit->insertPlainText(msg1);
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());

			QString msg2 = QString("Successfully parsed: ") + fullBotImportPath + QString("\n");
			textEdit->insertPlainText(msg2);
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		}

		gp_Pnt startTopPnt((topContactPntsCSV.front()).at(0), (topContactPntsCSV.front()).at(1), (topContactPntsCSV.front()).at(2));
		gp_Pnt endTopPnt((topContactPntsCSV.back()).at(0), (topContactPntsCSV.back()).at(1), (topContactPntsCSV.back()).at(2));
		gp_Pnt startBotPnt((botContactPntsCSV.front()).at(0), (botContactPntsCSV.front()).at(1), (botContactPntsCSV.front()).at(2));
		gp_Pnt endBotPnt((botContactPntsCSV.back()).at(0), (botContactPntsCSV.back()).at(1), (botContactPntsCSV.back()).at(2));

		// Collect remaining toolpath information using the typical input dialog
		singFeatureToolpathInputDialog importContactToolpathDialog(this);
		(importContactToolpathDialog.startPushButton)->setText(QString("Import"));

		// Update these manually from the imported contact points: Doing this outside of the class because of its public inheritance - Use caution
		(importContactToolpathDialog.startHeightSpinBox)->setEnabled(false);
		(importContactToolpathDialog.endHeightSpinBox)->setEnabled(false);
		(importContactToolpathDialog.negZFormingDirRadioButton)->setEnabled(false);
		(importContactToolpathDialog.posZFormingDirRadioButton)->setEnabled(false);
		((importContactToolpathDialog.myToolpathParamAdvancedDialog)->startAngleSpinBox)->setEnabled(false);
		((importContactToolpathDialog.myToolpathParamAdvancedDialog)->startingDistanceSpinBox)->setEnabled(false);
		importContactToolpathDialog.advToolpathParamAccepted = true;

		(importContactToolpathDialog.startHeightSpinBox)->setValue(startTopPnt.Z());
		(importContactToolpathDialog.endHeightSpinBox)->setValue(endTopPnt.Z());

		bool directionDown;
		if (endTopPnt.Z() > startTopPnt.Z())
		{
			directionDown = false;
			(importContactToolpathDialog.posZFormingDirRadioButton)->setChecked(true);
		}
		else
		{
			directionDown = true;
			(importContactToolpathDialog.negZFormingDirRadioButton)->setChecked(true);
		}

		float xTemp = startTopPnt.X();
		float yTemp = startTopPnt.Y();
		float rPnt = sqrt(xTemp*xTemp + yTemp*yTemp);
		float angleDeg = atan2(yTemp, xTemp) * 180 / PI; // -180 to 180 deg

		if (angleDeg < 0.0)
			angleDeg = angleDeg + 359.9;

		((importContactToolpathDialog.myToolpathParamAdvancedDialog)->startAngleSpinBox)->setValue(angleDeg);
		((importContactToolpathDialog.myToolpathParamAdvancedDialog)->startingDistanceSpinBox)->setValue(rPnt);

		if (importContactToolpathDialog.exec())
		{
			std::vector<int> contoursCSVSave = topContourIndicesCSV;
			std::vector<int> contoursIndexed = { 0 };

			if (importContactToolpathDialog.tpifRadioButton->isChecked() && directionDown) // Start point is in bottom contact points for this case
			{
				float xTemp = startBotPnt.X();
				float yTemp = startBotPnt.Y();
				float rPnt = sqrt(xTemp*xTemp + yTemp*yTemp);
				float angleDeg = atan2(yTemp, xTemp) * 180 / PI; // -180 to 180 deg

				if (angleDeg < 0.0)
					angleDeg = angleDeg + 359.9;

				((importContactToolpathDialog.myToolpathParamAdvancedDialog)->startAngleSpinBox)->setValue(angleDeg);
				((importContactToolpathDialog.myToolpathParamAdvancedDialog)->startingDistanceSpinBox)->setValue(rPnt);
				contoursCSVSave = botContourIndicesCSV;
			}

			for (int m = 0; m < contoursCSVSave.size(); ++m)
			{
				int curVal = contoursCSVSave.at(m);
				if (curVal == 1)
				{
					contoursIndexed.push_back(m);
				}
			}

			importContactToolpathDialog.fillLocalAmplToolpathClass();
			importContactToolpathDialog.getLocalAmplToolpathClass(myCurrentToolpath);

			myCurrentToolpath.contourIndices = contoursIndexed;
			myCurrentToolpath.topContactPnts = topContactPntsCSV;
			myCurrentToolpath.topContactPntsSurfProps = topContactPntsSurfPropsCSV;
			myCurrentToolpath.botContactPnts = botContactPntsCSV;
			myCurrentToolpath.botContactPntsSurfProps = botContactPntsSurfPropsCSV;

			textEdit->insertPlainText(QString("Success! Contact points and toolpath parameters imported.\n"));
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());

			setToolpathVisibilitySlot(false);
		}
	}
}