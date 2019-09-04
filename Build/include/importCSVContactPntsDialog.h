#pragma once
#include "stdafx.h"
#include "ui_importCSVContactPntsDialog.h"
#include "surfaceNormalHelpDialog.h"
#include "contactFormatHelpDialog.h"
#include <QtWidgets/QDialog>
#include <QFileDialog>
#include <QDir>

class importCSVContactPntsDialog : public QDialog, private Ui::importCSVContactPntsDialog
{
	Q_OBJECT

public:
	importCSVContactPntsDialog(QWidget *parent = Q_NULLPTR); //Constructor
	~importCSVContactPntsDialog(); //Destructor

	QString getTopFilePath(void);
	QString getBotFilePath(void);
	bool getSkipFirstLineTopContacts(void);
	bool getSkipFirstLineBotContacts(void);

protected:
private:
	Ui::importCSVContactPntsDialog ui;

	QStringList selectedTopFile;
	QStringList selectedBotFile;

	QFileDialog *myTopFileExplorer = new QFileDialog(this);
	QFileDialog *myBotFileExplorer = new QFileDialog(this);

private slots:
	void showSurfNormalHelpDialogSlot(void);
	void showInputFormatHelpDialogSlot(void);

	void clickedTopContactPickDirectoryButtonSlot(void);
	void clickedBotContactPickDirectoryButtonSlot(void);
};
