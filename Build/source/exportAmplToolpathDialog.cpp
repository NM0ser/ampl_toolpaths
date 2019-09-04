#include "stdafx.h"

#include "exportAmplToolpathDialog.h"

exportAmplToolpathDialog::exportAmplToolpathDialog(QWidget *parent) :
	QDialog(parent)
{
	setupUi(this);

	connect(pickDirectoryButton, SIGNAL(clicked()), this, SLOT(clickedPickDirectoryButtonSlot()));

	directoryLineEdit->setText(currentDirectory);

	myFileExplorer->setFileMode(QFileDialog::Directory);
	myFileExplorer->setOption(QFileDialog::ShowDirsOnly);
	myFileExplorer->setViewMode(QFileDialog::List);
	myFileExplorer->setWindowTitle("Choose Directory");
}

exportAmplToolpathDialog::~exportAmplToolpathDialog()
{

}

void exportAmplToolpathDialog::clickedPickDirectoryButtonSlot()
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

QString exportAmplToolpathDialog::getDirectory(void)
{
	selectedDirectory = directoryLineEdit->text();

	if (!selectedDirectory.isEmpty())
		return selectedDirectory;
	else
		return currentDirectory;
}

QString exportAmplToolpathDialog::getPrefixName(void)
{
	selectedFileName = filePrefixLineEdit->text();

	if (!selectedFileName.isEmpty())
	{
		return selectedFileName;
	}
	else
	{
		return "myToolpath";
	}
}

bool exportAmplToolpathDialog::topToolTipPointsCheckBoxChecked(void)
{
	return topToolTipPointsCheckBox->isChecked();
}

bool exportAmplToolpathDialog::botToolTipPointsCheckBoxChecked(void)
{
	return botToolTipPointsCheckBox->isChecked();
}

bool exportAmplToolpathDialog::topContactPointsCheckBoxChecked(void)
{
	return topContactPointsCheckBox->isChecked();
}

bool exportAmplToolpathDialog::botContactPointsCheckBoxChecked(void)
{
	return botContactPointsCheckBox->isChecked();
}

bool exportAmplToolpathDialog::normalVectorCheckBoxChecked(void)
{
	return normalVectorCheckBox->isChecked();
}

bool exportAmplToolpathDialog::genToolpathInfoCheckBoxChecked(void)
{
	return genToolpathInfoCheckBox->isChecked();
}
