#include "stdafx.h"

#include "importIGSDialog.h"

importIGSDialog::importIGSDialog(QWidget *parent) :
	QDialog(parent)
{
	setupUi(this);

	connect(pickDirectoryButton, SIGNAL(clicked()), this, SLOT(clickedPickDirectoryButtonSlot()));

	myFileExplorer->setFileMode(QFileDialog::ExistingFile);
	myFileExplorer->setViewMode(QFileDialog::Detail);
	
	//myFileExplorer->setWindowTitle("Choose File");
}

importIGSDialog::~importIGSDialog()
{

}

QString importIGSDialog::getFilePath(void)
{
	return filePathLineEdit->text();
}

QString importIGSDialog::getSewingTolStr(void)
{
	return sewingTolLineEdit->text().trimmed();
}

bool importIGSDialog::getCheckBoxState(void)
{
	return checkBox->isChecked();
}

void importIGSDialog::clickedPickDirectoryButtonSlot()
{
	if(!pickSTEPFiles)
		myFileExplorer->setNameFilter("CAD Surfaces (*.igs *.IGS *.iges *IGES)");
	else
		myFileExplorer->setNameFilter("CAD Surfaces (*.stp *.STP *.step *STEP)");

	QString currentFileSelection = filePathLineEdit->text();

	if (currentFileSelection.isEmpty())
		currentFileSelection = QDir::currentPath();

	myFileExplorer->setDirectory(currentFileSelection);
	if (myFileExplorer->exec())
	{
		selectedFile = myFileExplorer->selectedFiles();
		if (selectedFile.isEmpty())
		{
		}
		else
		{
			filePathLineEdit->setText(selectedFile.first());
		}
	}
}

void importIGSDialog::changeWindowTitle(QString nameIn)
{
	this->setWindowTitle(nameIn);
}

void importIGSDialog::setFileFilterToSTEP(bool boolIn)
{
	pickSTEPFiles = boolIn;
}