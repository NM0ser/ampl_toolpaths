#pragma once
#include "stdafx.h"
#include "ui_funnelDialog.h"
#include <QtWidgets/QDialog>

class funnelDialog : public QDialog, private Ui::funnelDialog
{
	Q_OBJECT

public:
	funnelDialog(QWidget *parent = Q_NULLPTR); //Constructor
	~funnelDialog(); //Destructor

	QString getBaseDiamLineEdit(void);
	QString getInitWallAngleLineEdit(void);
	QString getDepthLineEdit(void);
	QString getRadOfArcLineEdit(void);
	QString getFilletRadLineEdit(void);

protected:

private:
	Ui::funnelDialog ui;

	public slots:
	void funnelCreateSlotDialog(void);

signals:
	void funnelCreateButtonClicked(void);

};