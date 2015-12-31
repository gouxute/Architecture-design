#ifndef QUERYFORMSURFACE_H
#define QUERYFORMSURFACE_H
#pragma once
#include <QtWidgets/QDialog>
#include "ui_queryFormSurface.h"

class queryFormSurface : public QDialog
{
	Q_OBJECT

public:
	queryFormSurface(QWidget *parent = 0);
	~queryFormSurface();
	Ui::QueryForm getUi(){
		return ui;
	}
	/*public slots:
		void accept();
		void reject();*/
	
protected:
	
private:
	Ui::QueryForm ui;
};

#endif
