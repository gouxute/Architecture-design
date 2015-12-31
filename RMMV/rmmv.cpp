#include "rmmv.h"

RMMV::RMMV(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QActionGroup *toolBarGroup = new QActionGroup(ui.toolBar);
	ui.action_M_4->setCheckable(true);
	ui.action_O_7->setCheckable(true);
	ui.action_I_4->setCheckable(true);
	ui.action_P_3->setCheckable(true);
	ui.action_R_5->setCheckable(true);
	ui.action_Z_6->setCheckable(true);
	ui.action_Y_5->setCheckable(true);
	toolBarGroup->addAction(ui.action_M_4);
	toolBarGroup->addAction(ui.action_O_7);
	toolBarGroup->addAction(ui.action_I_4);
	toolBarGroup->addAction(ui.action_P_3);
	toolBarGroup->addAction(ui.action_R_5);
	toolBarGroup->addAction(ui.action_Z_6);
	toolBarGroup->addAction(ui.action_Y_5);
	//ui.action_M_4->setChecked(true);
	ui.distance1->setText("R: 0");
	ui.distance2->setText("Y: 0");
	connect(ui.pushButton_gridManage, SIGNAL(clicked()), this, SLOT(Dialog_grid_open()));
	connect(ui.pushButton_gridEnable, SIGNAL(clicked()), this, SLOT(Grid_Enable()));
	connect(ui.action_O_3, SIGNAL(triggered(bool)), this, SLOT(view_change0(bool)));
	connect(ui.action_P_xy, SIGNAL(triggered(bool)), this, SLOT(view_change1(bool)));
	connect(ui.action_S_yz, SIGNAL(triggered(bool)), this, SLOT(view_change2(bool)));
	connect(ui.action_F_xz, SIGNAL(triggered(bool)), this, SLOT(view_change3(bool)));
	connect(ui.action_OpenTextureLib, SIGNAL(triggered(bool)), this, SLOT(Dialog_TextureLib_open()));
	connect(ui.radioButton_grid_xy, SIGNAL(clicked()), this, SLOT(grid_direction_change1()));
	connect(ui.radioButton_grid_yz, SIGNAL(clicked()), this, SLOT(grid_direction_change2()));
	connect(ui.radioButton_grid_xz, SIGNAL(clicked()), this, SLOT(grid_direction_change3()));
	connect(ui.doubleSpinBox_tran_xyz, SIGNAL(valueChanged(double)), this, SLOT(grid_tran_change(double)));
	connect(ui.comboBox_TextureFirst, SIGNAL(currentIndexChanged(int)), this, SLOT(TextureFirst(int)));
	connect(ui.comboBox_TextureFirst, SIGNAL(currentIndexChanged(int)), this, SLOT(TextureID_change1(int)));
	connect(ui.comboBox_TextureSecond, SIGNAL(currentIndexChanged(int)), this, SLOT(TextureID_change2(int)));
	connect(ui.action_M_4, SIGNAL(changed()), this, SLOT(enabletoChooseObject()));
	connect(ui.action_I_4, SIGNAL(changed()), this, SLOT(enableLineDrawing()));
	connect(ui.action_P_3, SIGNAL(changed()), this, SLOT(enableSurfaceDrawing()));
	connect(ui.action_R_5, SIGNAL(changed()), this, SLOT(enablePartDrawing()));
	connect(ui.action_Z_6, SIGNAL(changed()), this, SLOT(enableBodyDrawing()));
	connect(ui.action_P, SIGNAL(triggered()), this, SLOT(printGraph()));
	connect(ui.action_S, SIGNAL(triggered()), this, SLOT(saveGraph()));
	connect(ui.action_O, SIGNAL(triggered()), this, SLOT(loadGraph()));
	ui.radioButton_grid_xy->setChecked(true);
}

RMMV::~RMMV()
{

}
void RMMV::view_change0(bool flag){
	ui.graphicsView->view_choice = 0;
	ui.graphicsView->update();
}
void RMMV::view_change1(bool flag){
	ui.graphicsView->view_choice = 1;
	ui.graphicsView->update();
}
void RMMV::view_change2(bool flag){
	ui.graphicsView->view_choice = 2;
	ui.graphicsView->update();
}
void RMMV::view_change3(bool flag){
	ui.graphicsView->view_choice = 3;
	ui.graphicsView->update();
}

void RMMV::enabletoChooseObject(){
	if (ui.graphicsView->isToSelect){
		ui.graphicsView->isToSelect = false;
		return;
	}
	ui.graphicsView->isToSelect = true;
}
void RMMV::enableLineDrawing(){
	if (ui.graphicsView->enableLineDrawing){
		ui.graphicsView->enableLineDrawing = false;
		return;
	}
	ui.graphicsView->enableLineDrawing = true;
}
void RMMV::enableSurfaceDrawing(){
	if (ui.graphicsView->enableSurfaceDrawing){
		ui.graphicsView->enableSurfaceDrawing = false;
		return;
	}
	ui.graphicsView->enableSurfaceDrawing = true;
}
void RMMV::enablePartDrawing(){
	if (ui.graphicsView->enablePartDrawing){
		ui.graphicsView->enablePartDrawing = false;
		return;
	}
	ui.graphicsView->enablePartDrawing = true;
}
void RMMV::enableBodyDrawing(){
	if (ui.graphicsView->enableBodyDrawing){
		ui.graphicsView->enableBodyDrawing = false;
		return;
	}
	ui.graphicsView->enableBodyDrawing = true;
}
void RMMV::printGraph(){
	QPrinter printer;
	QRect ur = ui.graphicsView->rect();
	QPixmap pix(ur.size());
	pix.fill(ui.graphicsView, ur.topLeft());
	QImage image = ui.graphicsView->grabFrameBuffer();
	pix = QPixmap::fromImage(image);
	QPrintDialog *pPrintDlg = new QPrintDialog(&printer, ui.graphicsView);
	if (pPrintDlg->exec()){
		QPainter printPainter(&printer);
		// 打印机的视窗大小
		QRect rect = printPainter.viewport();
		// 图片的大小
		QSize size = pix.size();
		// 将图片缩小到打印机视窗的大小
		size.scale(rect.size(), Qt::KeepAspectRatio);
		printPainter.setViewport(rect.x(), rect.y(), size.width(), size.height());
		printPainter.setWindow(pix.rect());
		printPainter.drawPixmap(0, 0, pix.width(), pix.height(), pix);
	}
	pix.save("graph.jpg", "JPG");
}
void RMMV::loadGraph(){
	ui.graphicsView->loadGraph();
}
void RMMV::saveGraph(){
	ui.graphicsView->saveGraph();
}