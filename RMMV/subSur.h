#pragma once
#include <QtWidgets/QDialog>
#include "ui_insertSubSurface.h"
#include<string>
using namespace std;
class subSur : public QDialog
{
	Q_OBJECT

public:
	subSur(QWidget *parent = 0);
	~subSur();
	Ui::isubsur getUi(){
		return ui;
	}
	QString getlength();
	QString getheigth();
	QString gethorizon();
	QString getvertical();
	int getType();
	public slots:
		void disableLineEdit(int);
signals:
		void currentIndexChanged(int);
private:
	Ui::isubsur ui;
	int type;
};

