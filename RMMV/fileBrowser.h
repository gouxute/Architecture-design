#pragma once
#include <QtWidgets/QDialog>
#include "ui_fileBrowser.h"
#include<string>
#include<qdirmodel.h>
using namespace std;
class fileBrowser : public QDialog
{
	Q_OBJECT

public:
	fileBrowser(QWidget *parent = 0);
	~fileBrowser();
	Ui::fileBrowser getUi(){
		return ui;
	}
	void setPath(string path);
	string getPath();
	public slots:
		void showPath(QModelIndex);
private:
	Ui::fileBrowser ui;
	QDirModel* model;
	string path;
};

