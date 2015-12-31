/********************************************************************************
** Form generated from reading UI file 'Dialog_grid.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_GRID_H
#define UI_DIALOG_GRID_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_grid
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QDoubleSpinBox *doubleSpinBox_xpos;
    QDoubleSpinBox *doubleSpinBox_xsize;
    QSpinBox *spinBox_xnum;
    QHBoxLayout *horizontalLayout_3;
    QDoubleSpinBox *doubleSpinBox_ypos;
    QDoubleSpinBox *doubleSpinBox_ysize;
    QSpinBox *spinBox_ynum;
    QHBoxLayout *horizontalLayout_2;
    QDoubleSpinBox *doubleSpinBox_zpos;
    QDoubleSpinBox *doubleSpinBox_zsize;
    QSpinBox *spinBox_znum;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_5;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_7;
    QLabel *label_9;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_2;

    void setupUi(QDialog *Dialog_grid)
    {
        if (Dialog_grid->objectName().isEmpty())
            Dialog_grid->setObjectName(QStringLiteral("Dialog_grid"));
        Dialog_grid->resize(292, 285);
        buttonBox = new QDialogButtonBox(Dialog_grid);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(-30, 240, 301, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(Dialog_grid);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 150, 231, 80));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        doubleSpinBox_xpos = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_xpos->setObjectName(QStringLiteral("doubleSpinBox_xpos"));

        horizontalLayout->addWidget(doubleSpinBox_xpos);

        doubleSpinBox_xsize = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_xsize->setObjectName(QStringLiteral("doubleSpinBox_xsize"));
        doubleSpinBox_xsize->setMinimum(1);

        horizontalLayout->addWidget(doubleSpinBox_xsize);

        spinBox_xnum = new QSpinBox(layoutWidget);
        spinBox_xnum->setObjectName(QStringLiteral("spinBox_xnum"));
        spinBox_xnum->setMinimum(1);

        horizontalLayout->addWidget(spinBox_xnum);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        doubleSpinBox_ypos = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_ypos->setObjectName(QStringLiteral("doubleSpinBox_ypos"));

        horizontalLayout_3->addWidget(doubleSpinBox_ypos);

        doubleSpinBox_ysize = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_ysize->setObjectName(QStringLiteral("doubleSpinBox_ysize"));
        doubleSpinBox_ysize->setMinimum(1);

        horizontalLayout_3->addWidget(doubleSpinBox_ysize);

        spinBox_ynum = new QSpinBox(layoutWidget);
        spinBox_ynum->setObjectName(QStringLiteral("spinBox_ynum"));
        spinBox_ynum->setMinimum(1);

        horizontalLayout_3->addWidget(spinBox_ynum);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        doubleSpinBox_zpos = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_zpos->setObjectName(QStringLiteral("doubleSpinBox_zpos"));

        horizontalLayout_2->addWidget(doubleSpinBox_zpos);

        doubleSpinBox_zsize = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_zsize->setObjectName(QStringLiteral("doubleSpinBox_zsize"));
        doubleSpinBox_zsize->setMinimum(1);

        horizontalLayout_2->addWidget(doubleSpinBox_zsize);

        spinBox_znum = new QSpinBox(layoutWidget);
        spinBox_znum->setObjectName(QStringLiteral("spinBox_znum"));
        spinBox_znum->setMinimum(1);

        horizontalLayout_2->addWidget(spinBox_znum);


        verticalLayout->addLayout(horizontalLayout_2);

        layoutWidget1 = new QWidget(Dialog_grid);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(40, 120, 231, 21));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_6->addWidget(label_4);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_6->addWidget(label_5);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_6->addWidget(label_6);

        layoutWidget2 = new QWidget(Dialog_grid);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 40, 160, 61));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButton = new QPushButton(layoutWidget2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_4->addWidget(pushButton);

        pushButton_3 = new QPushButton(layoutWidget2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_4->addWidget(pushButton_3);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButton_2 = new QPushButton(layoutWidget2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_5->addWidget(pushButton_2);

        pushButton_4 = new QPushButton(layoutWidget2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout_5->addWidget(pushButton_4);


        verticalLayout_2->addLayout(horizontalLayout_5);

        layoutWidget3 = new QWidget(Dialog_grid);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(190, 41, 81, 61));
        verticalLayout_3 = new QVBoxLayout(layoutWidget3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_6 = new QPushButton(layoutWidget3);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        verticalLayout_3->addWidget(pushButton_6);

        pushButton_5 = new QPushButton(layoutWidget3);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        verticalLayout_3->addWidget(pushButton_5);

        layoutWidget4 = new QWidget(Dialog_grid);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(20, 10, 331, 20));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget4);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_9->addWidget(label_7);

        label_9 = new QLabel(layoutWidget4);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_9->addWidget(label_9);

        widget = new QWidget(Dialog_grid);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 150, 20, 81));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_4->addWidget(label);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_4->addWidget(label_3);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_4->addWidget(label_2);

        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        buttonBox->raise();
        layoutWidget->raise();
        label->raise();
        label_2->raise();
        label_3->raise();

        retranslateUi(Dialog_grid);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog_grid, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog_grid, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog_grid);
    } // setupUi

    void retranslateUi(QDialog *Dialog_grid)
    {
        Dialog_grid->setWindowTitle(QApplication::translate("Dialog_grid", "Dialog", 0));
        label_4->setText(QApplication::translate("Dialog_grid", "\350\265\267\345\247\213\344\275\215\347\275\256\357\274\232", 0));
        label_5->setText(QApplication::translate("Dialog_grid", "\345\260\272\345\257\270\357\274\232", 0));
        label_6->setText(QApplication::translate("Dialog_grid", "\345\276\256\345\205\203\357\274\232", 0));
        pushButton->setText(QApplication::translate("Dialog_grid", "\345\275\222\351\233\266", 0));
        pushButton_3->setText(QApplication::translate("Dialog_grid", "\350\276\223\345\207\272\346\225\260\346\215\256", 0));
        pushButton_2->setText(QApplication::translate("Dialog_grid", "\346\270\205\347\251\272\345\206\205\345\255\230", 0));
        pushButton_4->setText(QApplication::translate("Dialog_grid", "\345\257\274\345\205\245/\345\257\274\345\207\272", 0));
        pushButton_6->setText(QApplication::translate("Dialog_grid", "\345\210\206\351\205\215", 0));
        pushButton_5->setText(QApplication::translate("Dialog_grid", "\345\210\240\351\231\244", 0));
        label_7->setText(QApplication::translate("Dialog_grid", "\347\275\221\346\240\274\347\256\241\347\220\206", 0));
        label_9->setText(QApplication::translate("Dialog_grid", "3D\347\274\223\345\206\262", 0));
        label->setText(QApplication::translate("Dialog_grid", "X\357\274\232", 0));
        label_3->setText(QApplication::translate("Dialog_grid", "Y\357\274\232", 0));
        label_2->setText(QApplication::translate("Dialog_grid", "Z\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog_grid: public Ui_Dialog_grid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_GRID_H
