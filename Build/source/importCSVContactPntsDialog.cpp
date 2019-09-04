#include "stdafx.h"

#include "importCSVContactPntsDialog.h"

importCSVContactPntsDialog::importCSVContactPntsDialog(QWidget *parent) :
	QDialog(parent)
{
	setupUi(this);

	connect(expectedCSVFormatButton, SIGNAL(clicked()), this, SLOT(showInputFormatHelpDialogSlot()));
	connect(surfNormalHelpButton, SIGNAL(clicked()), this, SLOT(showSurfNormalHelpDialogSlot()));

	connect(topContactPickDirectoryButton, SIGNAL(clicked()), this, SLOT(clickedTopContactPickDirectoryButtonSlot()));
	connect(botContactPickDirectoryButton, SIGNAL(clicked()), this, SLOT(clickedBotContactPickDirectoryButtonSlot()));

	myTopFileExplorer->setFileMode(QFileDialog::ExistingFile);
	myTopFileExplorer->setViewMode(QFileDialog::Detail);
	myTopFileExplorer->setWindowTitle("Choose File");
	myBotFileExplorer->setFileMode(QFileDialog::ExistingFile);
	myBotFileExplorer->setViewMode(QFileDialog::Detail);
	myBotFileExplorer->setWindowTitle("Choose File");
}

importCSVContactPntsDialog::~importCSVContactPntsDialog()
{

}

void importCSVContactPntsDialog::clickedTopContactPickDirectoryButtonSlot(void)
{
	myTopFileExplorer->setNameFilter("Text Files (*.txt *.TXT *.csv *.CSV)");

	QString currentFileSelection = topContactFilePathLineEdit->text();

	if (currentFileSelection.isEmpty())
		currentFileSelection = QDir::currentPath();

	myTopFileExplorer->setDirectory(currentFileSelection);
	if (myTopFileExplorer->exec())
	{
		selectedTopFile = myTopFileExplorer->selectedFiles();
		if (selectedTopFile.isEmpty())
		{
		}
		else
		{
			topContactFilePathLineEdit->setText(selectedTopFile.first());
		}
	}
}

void importCSVContactPntsDialog::clickedBotContactPickDirectoryButtonSlot(void)
{
	myBotFileExplorer->setNameFilter("Text Files (*.txt *.TXT *.csv *.CSV)");

	QString currentFileSelection = botContactFilePathLineEdit->text();

	if (currentFileSelection.isEmpty())
		currentFileSelection = QDir::currentPath();

	myBotFileExplorer->setDirectory(currentFileSelection);
	if (myBotFileExplorer->exec())
	{
		selectedBotFile = myBotFileExplorer->selectedFiles();
		if (selectedBotFile.isEmpty())
		{
		}
		else
		{
			botContactFilePathLineEdit->setText(selectedBotFile.first());
		}
	}
}

void importCSVContactPntsDialog::showSurfNormalHelpDialogSlot(void)
{
	surfaceNormalHelpDialog mySurfNormHelpDialog(this);

	mySurfNormHelpDialog.exec();
}

void importCSVContactPntsDialog::showInputFormatHelpDialogSlot(void)
{
	contactFormatHelpDialog myContactFormatHelpDialog(this);

	myContactFormatHelpDialog.exec();
}

QString importCSVContactPntsDialog::getTopFilePath(void)
{
	return topContactFilePathLineEdit->text();
}

QString importCSVContactPntsDialog::getBotFilePath(void)
{
	return botContactFilePathLineEdit->text();
}

bool importCSVContactPntsDialog::getSkipFirstLineTopContacts(void)
{
	return topSkipFirstLineCheckBox->isChecked();
}

bool importCSVContactPntsDialog::getSkipFirstLineBotContacts(void)
{
	return botSkipFirstLineCheckBox->isChecked();
}