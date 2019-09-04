#include "stdafx.h"

#include "QtOcct.h"

void QtOcct::showSingFeatureToolpathInputDialogSlot(void)
{
	if (myCurrentPart.IsNull()) // Cannot start toolpath generation on an empty part
	{
		textEdit->insertPlainText("No current part active for toolpath generation\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		return;
	}

	if (myToolpathInputDialog->exec())
	{
		textEdit->insertPlainText("Collecting user toolpath input... ");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());

		// Grab all information from input dialog and fill up the amplToolpath class
		myToolpathInputDialog->fillLocalAmplToolpathClass();
		myToolpathInputDialog->getLocalAmplToolpathClass(myCurrentToolpath);

		textEdit->insertPlainText("Success!\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		textEdit->repaint();

		setToolpathVisibilitySlot(true);
		startSingFeatureToolpathInput();
	}
}

void QtOcct::startSingFeatureToolpathInput(void)
{
	QEventLoop myEventLoop(this);

	// Verify user input as well as determine what algorithm to call
	if (myCurrentToolpath.myIncFormingMethodTypeActive())
	{
		if (myCurrentToolpath.sheetThicknessActive() &&
			myCurrentToolpath.topToolDiamActive() &&
			myCurrentToolpath.botToolDiamActive() &&
			myCurrentToolpath.formingDirectionTypeActive() &&
			myCurrentToolpath.tpifDieTypeActive())
		{
			if (myCurrentToolpath.mytoolpathMethodTypeActive() &&
				myCurrentToolpath.startDepthActive() &&
				myCurrentToolpath.incDepthActive() &&
				myCurrentToolpath.sqzFactorActive() &&
				myCurrentToolpath.incToolpathCurveActive())
			{
				if (myCurrentToolpath.myIncFormingMethodType == amplToolpath::incFormingMethodType::SPIF)
				{
					SPIF mySpifObject;
					bool initSuccess = mySpifObject.initContactPnts(myCurrentToolpath, myCurrentTopContactPnts, myCurrentBotContactPnts, myAisTopContactPnts, myAisBotContactPnts,
						myCurrentPart, myViewer, myView, myContext, myAisShape, textEdit, myEventLoop);
					bool toolpathSuccess = mySpifObject.calcContactPnts();
				}
				else if (myCurrentToolpath.myIncFormingMethodType == amplToolpath::incFormingMethodType::TPIF)
				{
					TPIF myTpifObject;
					bool initSuccess = myTpifObject.initContactPnts(myCurrentToolpath, myCurrentTopContactPnts, myCurrentBotContactPnts, myAisTopContactPnts, myAisBotContactPnts,
						myCurrentPart, myViewer, myView, myContext, myAisShape, textEdit, myEventLoop);
					bool toolpathSuccess = myTpifObject.calcContactPnts();
				}
				else if (myCurrentToolpath.myIncFormingMethodType == amplToolpath::incFormingMethodType::DSIF)
				{
					DSIF myDsifObject;
					bool initSuccess = myDsifObject.initContactPnts(myCurrentToolpath, myCurrentTopContactPnts, myCurrentBotContactPnts, myAisTopContactPnts, myAisBotContactPnts,
						myCurrentPart, myViewer, myView, myContext, myAisShape, textEdit, myEventLoop);
					bool toolpathSuccess = myDsifObject.calcContactPnts();
				}
				else if (myCurrentToolpath.myIncFormingMethodType == amplToolpath::incFormingMethodType::ADSIF)
				{
					ADSIF myAdsifObject;
					bool initSuccess = myAdsifObject.initContactPnts(myCurrentToolpath, myCurrentTopContactPnts, myCurrentBotContactPnts, myAisTopContactPnts, myAisBotContactPnts,
						myCurrentPart, myViewer, myView, myContext, myAisShape, textEdit, myEventLoop);
					bool toolpathSuccess = myAdsifObject.calcContactPnts();
				}

				setToolpathVisibilitySlot(false);
			}
			else
			{
				textEdit->insertPlainText("ERROR: Could not process parameters in: 3) Toolpath Parameters\n");
				textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
				return;
			}
		}
		else
		{
			textEdit->insertPlainText("ERROR: Could not process parameters in: 2) Tooling and Sheet Metal Parameters\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			return;
		}
	}
	else
	{
		textEdit->insertPlainText("ERROR: Could not process parameters in: 1) Incremental Sheet Forming Setup\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		return;
	}

}

void QtOcct::showSingFeatureCalcToolTipsDialogSlot(void)
{
	if (!myCurrentToolpath.toolpathIsActive) // Cannot start toolpath generation on an empty part
	{
		textEdit->insertPlainText("No current toolpath containing contact points is active for tool tip generation\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		return;
	}

	myToolTipGenerationDialog->initializeDialog(myCurrentToolpath);
	bool performSelfIntersectionCheck;
	int toolTipConstZHeightCheck;
	if (myToolTipGenerationDialog->exec())
	{
		textEdit->insertPlainText("Collecting user toolpath input... ");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());

		myToolTipGenerationDialog->updateAmplToolpath(myCurrentToolpath, performSelfIntersectionCheck, toolTipConstZHeightCheck);

		textEdit->insertPlainText("Success!\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		textEdit->repaint();

		startSingFeatureToolTipCalculation(performSelfIntersectionCheck, toolTipConstZHeightCheck);
	}
}

void QtOcct::startSingFeatureToolTipCalculation(const bool checkSelfIntersectingToolpath, const int performConstZHeightTips)
{
	QEventLoop myEventLoop(this);

	if (myCurrentToolpath.myIncFormingMethodType == amplToolpath::incFormingMethodType::SPIF)
	{
		SPIF mySpifObject;
		bool initSuccess = mySpifObject.initToolTipPnts(myCurrentToolpath, myCurrentTopToolTips, myCurrentBotToolTips, myAisTopToolTips, myAisBotToolTips,
			myCurrentPart, myViewer, myView, myContext, myAisShape, textEdit, myEventLoop);
		bool toolpathSuccess = mySpifObject.calcToolTipPnts(checkSelfIntersectingToolpath, performConstZHeightTips);
	}
	else if (myCurrentToolpath.myIncFormingMethodType == amplToolpath::incFormingMethodType::TPIF)
	{
		TPIF myTpifObject;
		bool initSuccess = myTpifObject.initToolTipPnts(myCurrentToolpath, myCurrentTopToolTips, myCurrentBotToolTips, myAisTopToolTips, myAisBotToolTips,
			myCurrentPart, myViewer, myView, myContext, myAisShape, textEdit, myEventLoop);
		bool toolpathSuccess = myTpifObject.calcToolTipPnts(checkSelfIntersectingToolpath, performConstZHeightTips);
	}
	else if (myCurrentToolpath.myIncFormingMethodType == amplToolpath::incFormingMethodType::DSIF)
	{
		DSIF myDsifObject;
		bool initSuccess = myDsifObject.initToolTipPnts(myCurrentToolpath, myCurrentTopToolTips, myCurrentBotToolTips, myAisTopToolTips, myAisBotToolTips,
			myCurrentPart, myViewer, myView, myContext, myAisShape, textEdit, myEventLoop);
		bool toolpathSuccess = myDsifObject.calcToolTipPnts(checkSelfIntersectingToolpath, performConstZHeightTips);
	}
	else if (myCurrentToolpath.myIncFormingMethodType == amplToolpath::incFormingMethodType::ADSIF)
	{
		ADSIF myAdsifObject;
		bool initSuccess = myAdsifObject.initToolTipPnts(myCurrentToolpath, myCurrentTopToolTips, myCurrentBotToolTips, myAisTopToolTips, myAisBotToolTips,
			myCurrentPart, myViewer, myView, myContext, myAisShape, textEdit, myEventLoop);
		bool toolpathSuccess = myAdsifObject.calcToolTipPnts(checkSelfIntersectingToolpath, performConstZHeightTips);
	}

	setToolpathVisibilitySlot(false);
}

void QtOcct::showExportToGen1MachineCodeDialogSlot(void)
{
	exportToGen1MachineCodeDialog myGen1CodeDialog(this);

	if (!myCurrentToolpath.topToolTipPntsActive() && !myCurrentToolpath.botToolTipPntsActive() && 
		!myCurrentToolpath.topToolTipPntsModActive() && !myCurrentToolpath.botToolTipPntsModActive())
	{
		textEdit->insertPlainText("ERROR: No active toolpath containing tool-tip points is present.\n");
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		return;
	}

	if (myGen1CodeDialog.exec())
	{
		QString currentDirectory = myGen1CodeDialog.getDirectory();
		QString currentPrefix = myGen1CodeDialog.getPrefixName();
		QString currentFileName = currentPrefix + QString("_1.txt");
		QString fullFilePath = currentDirectory + QString("/") + currentFileName;

		float maxNumLines = myGen1CodeDialog.getMaxNumLinesPerFile();
		float feedRate = myGen1CodeDialog.getFeedRate();
		bool useModToolTips = myGen1CodeDialog.useModToolTipPoints();

		float topToolSafeHeight, botToolSafeHeight;
		if (!myGen1CodeDialog.getTopToolSafeHeight(topToolSafeHeight))
		{
			textEdit->insertPlainText("ERROR: Could not parse Top Tool Safe Z-Height.\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			return;
		}
		if (!myGen1CodeDialog.getBotToolSafeHeight(botToolSafeHeight))
		{
			textEdit->insertPlainText("ERROR: Could not parse Bottom Tool Safe Z-Height.\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			return;
		}

		bool topTipsActive = false;
		bool botTipsActive = false;
		int numTopTipPnts = 0;
		int numBotTipPnts = 0;
		int toolpathNumPnts;
		std::vector< std::vector<float> > topTips;
		std::vector< std::vector<float> > botTips;
		if (useModToolTips)
		{
			if (myCurrentToolpath.topToolTipPntsModActive())
			{
				topTips = myCurrentToolpath.topToolTipPntsMod;
				topTipsActive = true;
				numTopTipPnts = topTips.size();
			}
			else if (myCurrentToolpath.topToolTipPntsActive())
			{
				topTips = myCurrentToolpath.topToolTipPnts;
				topTipsActive = true;
				numTopTipPnts = topTips.size();
			}

			if (myCurrentToolpath.botToolTipPntsModActive())
			{
				botTips = myCurrentToolpath.botToolTipPntsMod;
				botTipsActive = true;
				numBotTipPnts = botTips.size();
			}
			else if (myCurrentToolpath.botToolTipPntsActive())
			{
				botTips = myCurrentToolpath.botToolTipPnts;
				botTipsActive = true;
				numBotTipPnts = botTips.size();
			}
		}
		else
		{
			if (myCurrentToolpath.topToolTipPntsActive())
			{
				topTips = myCurrentToolpath.topToolTipPnts;
				topTipsActive = true;
				numTopTipPnts = topTips.size();
			}

			if (myCurrentToolpath.botToolTipPntsActive())
			{
				botTips = myCurrentToolpath.botToolTipPnts;
				botTipsActive = true;
				numBotTipPnts = botTips.size();
			}
		}

		if ((topTipsActive == false) && (botTipsActive == false))
		{
			textEdit->insertPlainText("ERROR: No active toolpath containing tool-tip points is present.\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			return;
		}

		if (topTipsActive && botTipsActive)
		{
			if (numBotTipPnts != numTopTipPnts)
			{
				textEdit->insertPlainText("ERROR: The number of top tool-tip points does not equal the number of bottom tool-tip points.\n");
				textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
				return;
			}
			else
			{
				toolpathNumPnts = numTopTipPnts;
			}
		}
		else if (topTipsActive && !botTipsActive)
		{
			toolpathNumPnts = numTopTipPnts;
		}
		else if (!topTipsActive && botTipsActive)
		{
			toolpathNumPnts = numBotTipPnts;
		}

		QString tempMsg = currentDirectory + QString("/") + currentPrefix + QString("_##.txt");
		textEdit->insertPlainText(QString("Writing Machine Code to: ") + tempMsg + QString("\n"));
		textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
		textEdit->repaint();

		QString header1("DELGAT\n");
		QString header2("UNDEFINE ALL\n");
		QString header3("&1\n");
		QString header4("CLOSE\n");
		QString header5("#1->-16000X\n");
		QString header6("#2->-16000X\n");
		QString header7("#3->16000Y\n");
		QString header8("#4->16000Y\n");
		QString header9("#5->16000Z\n");
		QString header10("#6->-16000U\n");
		QString header11("#7->-16000U\n");
		QString header12("#8->16000V\n");
		QString header13("#9->16000V\n");
		QString header14("#10->-16000W\n");
		QString header15("OPEN PROG 2\n");
		QString header16("CLEAR\n");
		QString header17("FRAX(X,Y,Z)\n");
		QString header18("ABS\n");
		QString header19("TA 100.0\n");
		QString header20("TS 50");
		QString headerStr = header1 + header2 + header3 + header4 + header5 + header6 + header7 + header8 + header9 + header10 +
					      header11 + header12 + header13 + header14 + header15 + header16 + header17 + header18 + header19 + header20;

		QString footerStr("CLOSE ALL");
		
		int fileCountInt = 1;
		std::string fileCountStr = std::to_string(fileCountInt);

		ofstream myfile;
		myfile.open(fullFilePath.toStdString(), std::ios::out | std::ios::trunc);
		if (myfile.is_open())
		{
			myfile << std::fixed << std::setprecision(4);
			myfile << headerStr.toStdString() << std::endl;

			int lineCount = 23;
			float curTopX, curTopY, curTopZ, curBotX, curBotY, curBotZ;
			if (topTipsActive)
			{
				curTopX = topTips.at(0).at(0); curTopY = topTips.at(0).at(1); curTopZ = topTips.at(0).at(2);
			}
			else
			{
				curTopX = 0.0; curTopY = 0.0; curTopZ = topToolSafeHeight;
			}

			if (botTipsActive)
			{
				curBotX = botTips.at(0).at(0); curBotY = botTips.at(0).at(1); curBotZ = botTips.at(0).at(2);
			}
			else
			{
				curBotX = 0.0; curBotY = 0.0; curBotZ = botToolSafeHeight;
			}

			myfile << "X 0.0 Y 0.0 Z " << topToolSafeHeight << " U 0.0 V 0.0 W " << botToolSafeHeight << " F " << feedRate / 2.0 << std::endl;
			myfile << "X " << curTopX << " Y " << curTopY << " Z " << topToolSafeHeight << " U " << curBotX << " V " << curBotY << " W " << botToolSafeHeight << std::endl;
			
			for (int m = 0; m < toolpathNumPnts; m++)
			{
				lineCount++;

				if (topTipsActive)
				{
					curTopX = topTips.at(m).at(0); curTopY = topTips.at(m).at(1); curTopZ = topTips.at(m).at(2);
				}
				else
				{
					curTopX = 0.0; curTopY = 0.0; curTopZ = topToolSafeHeight;
				}

				if (botTipsActive)
				{
					curBotX = botTips.at(m).at(0); curBotY = botTips.at(m).at(1); curBotZ = botTips.at(m).at(2);
				}
				else
				{
					curBotX = 0.0; curBotY = 0.0; curBotZ = botToolSafeHeight;
				}

				if (m == 1)
					myfile << "X " << curTopX << " Y " << curTopY << " Z " << curTopZ << " U " << curBotX << " V " << curBotY << " W " << curBotZ << " F " << feedRate << std::endl;
				else
					myfile << "X " << curTopX << " Y " << curTopY << " Z " << curTopZ << " U " << curBotX << " V " << curBotY << " W " << curBotZ << std::endl;

				if (lineCount >= maxNumLines)
				{
					myfile << footerStr.toStdString() << std::endl;
					myfile.close();

					lineCount = 21;
					fileCountInt = fileCountInt + 1;
					fileCountStr = std::to_string(fileCountInt);
					currentFileName = currentPrefix + QString("_") + QString::fromUtf8(fileCountStr.c_str()) + QString(".txt");
					fullFilePath = currentDirectory + QString("/") + currentFileName;

					myfile.open(fullFilePath.toStdString(), std::ios::out | std::ios::trunc);
					if (!myfile.is_open())
					{
						textEdit->insertPlainText("ERROR: Could not partition the toolpath into a new file; file could not be opened.\n");
						textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
						return;
					}

					myfile << std::fixed << std::setprecision(4);
					myfile << headerStr.toStdString() << std::endl;

					lineCount++;
					myfile << "X " << curTopX << " Y " << curTopY << " Z " << curTopZ << " U " << curBotX << " V " << curBotY << " W " << curBotZ << " F " << feedRate << std::endl;
				}
			}

			myfile << "X " << curTopX << " Y " << curTopY << " Z " << topToolSafeHeight << " U " << curBotX << " V " << curBotY << " W " << botToolSafeHeight << std::endl;
			myfile << footerStr.toStdString() << std::endl;
			myfile.close();
		}
		else
		{
			textEdit->insertPlainText("ERROR: Could not open file.\n");
			textEdit->verticalScrollBar()->setSliderPosition(textEdit->verticalScrollBar()->maximum());
			return;
		}
	}
}

void QtOcct::showExportToGen2MachineCodeDialogSlot(void)
{
	QMessageBox::about(this, QString("Research and Development"), QString("This feature is currently being researched and is still under development."));
}
