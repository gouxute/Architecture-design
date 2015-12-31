#ifndef RMMV_H
#define RMMV_H

#include <QtWidgets/QMainWindow>
#include "ui_rmmv.h"

class RMMV : public QMainWindow
{
	Q_OBJECT

public:
	RMMV(QWidget *parent = 0);
	~RMMV();
	private slots:
	void view_change0(bool);
	void view_change1(bool);
	void view_change2(bool);
	void view_change3(bool);
	void enabletoChooseObject();
	void enableLineDrawing();
	void enableSurfaceDrawing();
	void enablePartDrawing();
	void enableBodyDrawing();
	void printGraph();
	void loadGraph();
	void saveGraph();
private:
	Ui::RMMV ui;
};

#endif // RMMV_H
