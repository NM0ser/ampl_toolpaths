#include "stdafx.h"
#include "exportCrossSectionDialog.h"

exportCrossSectionDialog::exportCrossSectionDialog(QWidget *parent) :
	QDialog(parent)
{
	setupUi(this);

	connect(pickDirectoryButton, SIGNAL(clicked()), this, SLOT(clickedPickDirectoryButtonSlot()));

	directoryLineEdit->setText(currentDirectory);

	myFileExplorer->setFileMode(QFileDialog::Directory);
	myFileExplorer->setOption(QFileDialog::ShowDirsOnly);
	myFileExplorer->setViewMode(QFileDialog::List);
}

exportCrossSectionDialog::~exportCrossSectionDialog()
{

}

QString exportCrossSectionDialog::getDirectory(void)
{
	selectedDirectory = directoryLineEdit->text();

	if (!selectedDirectory.isEmpty())
		return selectedDirectory;
	else
		return currentDirectory;
}

QString exportCrossSectionDialog::getFileName(void)
{
	selectedFileName = fileNameLineEdit->text();

	if (!selectedFileName.isEmpty())
	{
		if (selectedFileName.endsWith(".csv", Qt::CaseInsensitive))
		{
			return selectedFileName;
		}
		else
		{
			selectedFileName.append(".csv");
			return selectedFileName;
		}
	}
	else
	{
		return "myCrossSection.csv";
	}
}

void exportCrossSectionDialog::clickedPickDirectoryButtonSlot()
{
	myFileExplorer->setDirectory(directoryLineEdit->text());
	if (myFileExplorer->exec())
	{
		selectedDirectoryList = myFileExplorer->selectedFiles();
		if (selectedDirectoryList.isEmpty())
		{
		}
		else
		{
			directoryLineEdit->setText(selectedDirectoryList.first());
		}
	}
}

bool exportCrossSectionDialog::getBasePntOfPlane(gp_Pnt &basePntOut)
{
	QString xBasePntStr = (xBasePntLineEdit->text()).trimmed();
	QString yBasePntStr = (yBasePntLineEdit->text()).trimmed();
	QString zBasePntStr = (zBasePntLineEdit->text()).trimmed();

	bool str2floatOK1 = false;
	bool str2floatOK2 = false;
	bool str2floatOK3 = false;

	xBasePntStr.toFloat(&str2floatOK1);
	yBasePntStr.toFloat(&str2floatOK2);
	zBasePntStr.toFloat(&str2floatOK3);

	if (!str2floatOK1 || !str2floatOK2 || !str2floatOK3)
	{
		return false;
	}

	float xBasePnt = xBasePntStr.toFloat();
	float yBasePnt = yBasePntStr.toFloat();
	float zBasePnt = zBasePntStr.toFloat();

	basePntOut = gp_Pnt(xBasePnt, yBasePnt, zBasePnt);
	return true;
}

bool exportCrossSectionDialog::getNormalDirOfPlane(gp_Dir &normalDirOut)
{
	QString xNormalStr = (xNormalDirLineEdit->text()).trimmed();
	QString yNormalStr = (yNormalDirLineEdit->text()).trimmed();
	QString zNormalStr = (zNormalDirLineEdit->text()).trimmed();

	bool str2floatOK1 = false;
	bool str2floatOK2 = false;
	bool str2floatOK3 = false;

	xNormalStr.toFloat(&str2floatOK1);
	yNormalStr.toFloat(&str2floatOK2);
	zNormalStr.toFloat(&str2floatOK3);

	if (!str2floatOK1 || !str2floatOK2 || !str2floatOK3)
	{
		return false;
	}

	float xNormal = xNormalStr.toFloat();
	float yNormal = yNormalStr.toFloat();
	float zNormal = zNormalStr.toFloat();
	float magnitude = sqrt(xNormal*xNormal + yNormal*yNormal + zNormal*zNormal);

	if (magnitude <= 0.002)
	{
		return false;
	}

	normalDirOut = gp_Dir(xNormal, yNormal, zNormal);
	return true;
}

bool exportCrossSectionDialog::getStartingPnt(gp_Pnt &startingPntOut)
{
	QString xStartPntStr = (xStartingPntLineEdit->text()).trimmed();
	QString yStartPntStr = (yStartingPntLineEdit->text()).trimmed();
	QString zStartPntStr = (zStartingPntLineEdit->text()).trimmed();

	bool str2floatOK1 = false;
	bool str2floatOK2 = false;
	bool str2floatOK3 = false;

	xStartPntStr.toFloat(&str2floatOK1);
	yStartPntStr.toFloat(&str2floatOK2);
	zStartPntStr.toFloat(&str2floatOK3);

	if (!str2floatOK1 || !str2floatOK2 || !str2floatOK3)
	{
		return false;
	}

	float xStartPnt = xStartPntStr.toFloat();
	float yStartPnt = yStartPntStr.toFloat();
	float zStartPnt = zStartPntStr.toFloat();

	startingPntOut = gp_Pnt(xStartPnt, yStartPnt, zStartPnt);
	return true;
}

float exportCrossSectionDialog::getMaxDistBetweenPnts(void)
{
	return distBetweenPntsSpinBox->value();
}