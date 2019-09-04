#include "stdafx.h"

#include "openAmplToolpathDialog.h"

openAmplToolpathDialog::openAmplToolpathDialog(QWidget *parent) :
	QDialog(parent)
{
	setupUi(this);

	connect(pickDirectoryButton, SIGNAL(clicked()), this, SLOT(clickedPickDirectoryButtonSlot()));

	myFileExplorer->setFileMode(QFileDialog::ExistingFile);
	myFileExplorer->setViewMode(QFileDialog::Detail);
	myFileExplorer->setNameFilter("AMPL Toolpaths (*.ampl *.AMPL)");
	myFileExplorer->setWindowTitle("Choose File");
}

openAmplToolpathDialog::~openAmplToolpathDialog()
{

}

QString openAmplToolpathDialog::getFilePath(void)
{
	return filePathLineEdit->text();
}

void openAmplToolpathDialog::clickedPickDirectoryButtonSlot()
{
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