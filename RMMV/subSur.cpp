#include"subSur.h"
#include"sharedata.h"
#include<qmessagebox.h>
subSur::subSur(QWidget*parent):
QDialog(parent)
{
	ui.setupUi(this);
	ui.length->setText("0");
	ui.height->setText("0");
	ui.horizon->setText("0");
	ui.vertical->setText("0");
	ui.comboBox->setCurrentIndex(0);
}
subSur::~subSur(){
}
QString subSur::getlength(){
	return ui.length->text();
}
QString subSur::getheigth(){
	return ui.height->text();
}
QString subSur::gethorizon(){
	return ui.horizon->text();
}
QString subSur::getvertical(){
	return ui.vertical->text();
}
int subSur::getType(){
	return ui.comboBox->currentIndex();
}
void subSur::disableLineEdit(int num){
	if(num==3){
		ui.vertical->setEnabled(false);
		ui.vertical->setText("0");
	}else{
		ui.vertical->setEnabled(true);
	}
}