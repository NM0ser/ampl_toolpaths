#include "stdafx.h"

#include "saveAmplToolpathDialog.h"

saveAmplToolpathDialog::saveAmplToolpathDialog(QWidget *parent) :
	QDialog(parent)
{
	setupUi(this);

	connect(pickDirectoryButton, SIGNAL(clicked()), this, SLOT(clickedPickDirectoryButtonSlot()));

	directoryLineEdit->setText(currentDirectory);

	myFileExplorer->setFileMode(QFileDialog::Directory);
	myFileExplorer->setOption(QFileDialog::ShowDirsOnly);
	myFileExplorer->setViewMode(QFileDialog::List);
	myFileExplorer->setNameFilter("AMPL Toolpaths (*.ampl *.AMPL)");
	myFileExplorer->setWindowTitle("Choose Directory");
}

saveAmplToolpathDialog::~saveAmplToolpathDialog()
{

}

void saveAmplToolpathDialog::clickedPickDirectoryButtonSlot()
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

QString saveAmplToolpathDialog::getDirectory(void)
{
	selectedDirectory = directoryLineEdit->text();

	if (!selectedDirectory.isEmpty())
		return selectedDirectory;
	else
		return currentDirectory;
}

QString saveAmplToolpathDialog::getFileName(void)
{
	selectedFileName = fileNameLineEdit->text();

	if (!selectedFileName.isEmpty())
	{
		if (selectedFileName.endsWith(".ampl", Qt::CaseInsensitive))
		{
			return selectedFileName;
		}
		else
		{
			selectedFileName.append(".ampl");
			return selectedFileName;
		}
	}
	else
	{
		return "myToolpath.ampl";
	}

}