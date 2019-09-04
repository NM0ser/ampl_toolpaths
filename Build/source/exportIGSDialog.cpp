#include "stdafx.h"

#include "exportIGSDialog.h"

exportIGSDialog::exportIGSDialog(QWidget *parent) :
	QDialog(parent)
{
	setupUi(this);

	connect(pickDirectoryButton, SIGNAL(clicked()), this, SLOT(clickedPickDirectoryButtonSlot()));

	directoryLineEdit->setText(currentDirectory);

	myFileExplorer->setFileMode(QFileDialog::Directory);
	myFileExplorer->setOption(QFileDialog::ShowDirsOnly);
	myFileExplorer->setViewMode(QFileDialog::List);
	//myFileExplorer->setNameFilter("CAD Surfaces (*.igs *.IGS *.iges *IGES)");
	//myFileExplorer->setWindowTitle("Choose Directory");
}

exportIGSDialog::~exportIGSDialog()
{

}

void exportIGSDialog::clickedPickDirectoryButtonSlot()
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

QString exportIGSDialog::getDirectory(void)
{
	selectedDirectory = directoryLineEdit->text();

	if (!selectedDirectory.isEmpty())
		return selectedDirectory;
	else
		return currentDirectory;
}

QString exportIGSDialog::getIGSFileName(void)
{
	selectedFileName = fileNameLineEdit->text();

	if (!selectedFileName.isEmpty())
	{
		if (selectedFileName.endsWith(".igs", Qt::CaseInsensitive) || selectedFileName.endsWith(".iges", Qt::CaseInsensitive))
		{
			return selectedFileName;
		}
		else
		{
			selectedFileName.append(".IGS");
			return selectedFileName;
		}
	}
	else
	{
		return "myPart.IGS";
	}
 
}

QString exportIGSDialog::getSTEPFileName(void)
{
	selectedFileName = fileNameLineEdit->text();

	if (!selectedFileName.isEmpty())
	{
		if (selectedFileName.endsWith(".stp", Qt::CaseInsensitive) || selectedFileName.endsWith(".STEP", Qt::CaseInsensitive))
		{
			return selectedFileName;
		}
		else
		{
			selectedFileName.append(".STP");
			return selectedFileName;
		}
	}
	else
	{
		return "myPart.STP";
	}

}

void exportIGSDialog::changeWindowTitle(QString nameIn)
{
	this->setWindowTitle(nameIn);
}

void exportIGSDialog::changeFileNameText(QString nameIn)
{
	fileNameLineEdit->setText(nameIn);
}