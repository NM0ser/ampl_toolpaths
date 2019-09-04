#include "stdafx.h"
#include "exportToGen1MachineCodeDialog.h"

exportToGen1MachineCodeDialog::exportToGen1MachineCodeDialog(QWidget *parent) :
	QDialog(parent)
{
	setupUi(this);

	connect(pickDirectoryButton, SIGNAL(clicked()), this, SLOT(clickedPickDirectoryButtonSlot()));

	directoryLineEdit->setText(currentDirectory);

	myFileExplorer->setFileMode(QFileDialog::Directory);
	myFileExplorer->setOption(QFileDialog::ShowDirsOnly);
	myFileExplorer->setViewMode(QFileDialog::List);
}

exportToGen1MachineCodeDialog::~exportToGen1MachineCodeDialog()
{

}

QString exportToGen1MachineCodeDialog::getDirectory(void)
{
	selectedDirectory = directoryLineEdit->text();

	if (!selectedDirectory.isEmpty())
		return selectedDirectory;
	else
		return currentDirectory;
}

QString exportToGen1MachineCodeDialog::getPrefixName(void)
{
	selectedPrefixName = filePrefixLineEdit->text();

	if (!selectedPrefixName.isEmpty())
	{
		return selectedPrefixName;
	}
	else
	{
		return "myGen1Toolpath";
	}
}

void exportToGen1MachineCodeDialog::clickedPickDirectoryButtonSlot()
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

float exportToGen1MachineCodeDialog::getMaxNumLinesPerFile(void)
{
	return maxNumLinesSpinBox->value();
}

float exportToGen1MachineCodeDialog::getFeedRate(void)
{
	return feedRateSpinBox->value();
}

bool exportToGen1MachineCodeDialog::getTopToolSafeHeight(float &topToolSafeHeightOut)
{
	QString topToolSafeHeightStr = (topToolSafeHeightLineEdit->text()).trimmed();

	bool str2floatOK1 = false;
	topToolSafeHeightStr.toFloat(&str2floatOK1);

	if (!str2floatOK1)
	{
		return false;
	}
	
	topToolSafeHeightOut = topToolSafeHeightStr.toFloat();
	return true;
}

bool exportToGen1MachineCodeDialog::getBotToolSafeHeight(float &botToolSafeHeightOut)
{
	QString botToolSafeHeightStr = (botToolSafeHeightLineEdit->text()).trimmed();

	bool str2floatOK1 = false;
	botToolSafeHeightStr.toFloat(&str2floatOK1);

	if (!str2floatOK1)
	{
		return false;
	}

	botToolSafeHeightOut = botToolSafeHeightStr.toFloat();
	return true;
}

bool exportToGen1MachineCodeDialog::useModToolTipPoints(void)
{
	return useModifiedTipPointsCheckBox->isChecked();
}