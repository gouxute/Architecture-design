#include"fileBrowser.h"
#include"sharedata.h"
#include<qmessagebox.h>
fileBrowser::fileBrowser(QWidget*parent):
QDialog(parent)
{
	ui.setupUi(this);
	model=new QDirModel;
	model->setReadOnly(false);
	model->setSorting(QDir::DirsFirst|QDir::IgnoreCase|QDir::Name);
	ui.treeView->setModel(model);
	QModelIndex index=model->index(QDir::currentPath());
	ui.treeView->expand(index);
	ui.treeView->scrollTo(index);
	ui.treeView->resizeColumnToContents(0);
}
fileBrowser::~fileBrowser(){
}
void fileBrowser::showPath(QModelIndex index){
	ui.lineEdit->setText((model->fileInfo(index).absoluteFilePath()));
}
string fileBrowser::getPath(){
	return ui.lineEdit->text().toStdString();
}
void fileBrowser::setPath(string tmp){
	ui.lineEdit->setText(QString::fromStdString(tmp));
}
