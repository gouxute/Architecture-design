/********************************************************************************
** Form generated from reading UI file 'fileBrowser.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEBROWSER_H
#define UI_FILEBROWSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_fileBrowser
{
public:
    QVBoxLayout *verticalLayout;
    QTreeView *treeView;
    QLineEdit *lineEdit;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *fileBrowser)
    {
        if (fileBrowser->objectName().isEmpty())
            fileBrowser->setObjectName(QStringLiteral("fileBrowser"));
        fileBrowser->resize(313, 275);
        verticalLayout = new QVBoxLayout(fileBrowser);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        treeView = new QTreeView(fileBrowser);
        treeView->setObjectName(QStringLiteral("treeView"));

        verticalLayout->addWidget(treeView);

        lineEdit = new QLineEdit(fileBrowser);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        okButton = new QPushButton(fileBrowser);
        okButton->setObjectName(QStringLiteral("okButton"));

        hboxLayout->addWidget(okButton);

        cancelButton = new QPushButton(fileBrowser);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        hboxLayout->addWidget(cancelButton);


        verticalLayout->addLayout(hboxLayout);


        retranslateUi(fileBrowser);
        QObject::connect(okButton, SIGNAL(clicked()), fileBrowser, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), fileBrowser, SLOT(reject()));

        QMetaObject::connectSlotsByName(fileBrowser);
    } // setupUi

    void retranslateUi(QDialog *fileBrowser)
    {
        fileBrowser->setWindowTitle(QApplication::translate("fileBrowser", "Dialog", 0));
        okButton->setText(QApplication::translate("fileBrowser", "OK", 0));
        cancelButton->setText(QApplication::translate("fileBrowser", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class fileBrowser: public Ui_fileBrowser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEBROWSER_H
