/********************************************************************************
** Form generated from reading UI file 'insertSubSurface.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTSUBSURFACE_H
#define UI_INSERTSUBSURFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_isubsur
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *length;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *height;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *horizon;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *vertical;
    QLabel *label_9;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *isubsur)
    {
        if (isubsur->objectName().isEmpty())
            isubsur->setObjectName(QStringLiteral("isubsur"));
        isubsur->resize(313, 193);
        verticalLayout_2 = new QVBoxLayout(isubsur);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(isubsur);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        comboBox = new QComboBox(isubsur);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_5->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(isubsur);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        length = new QLineEdit(isubsur);
        length->setObjectName(QStringLiteral("length"));

        horizontalLayout->addWidget(length);

        label_6 = new QLabel(isubsur);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout->addWidget(label_6);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(isubsur);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        height = new QLineEdit(isubsur);
        height->setObjectName(QStringLiteral("height"));

        horizontalLayout_2->addWidget(height);

        label_7 = new QLabel(isubsur);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_2->addWidget(label_7);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(isubsur);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        horizon = new QLineEdit(isubsur);
        horizon->setObjectName(QStringLiteral("horizon"));

        horizontalLayout_3->addWidget(horizon);

        label_8 = new QLabel(isubsur);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_3->addWidget(label_8);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(isubsur);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        vertical = new QLineEdit(isubsur);
        vertical->setObjectName(QStringLiteral("vertical"));

        horizontalLayout_4->addWidget(vertical);

        label_9 = new QLabel(isubsur);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_4->addWidget(label_9);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        okButton = new QPushButton(isubsur);
        okButton->setObjectName(QStringLiteral("okButton"));

        hboxLayout->addWidget(okButton);

        cancelButton = new QPushButton(isubsur);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        hboxLayout->addWidget(cancelButton);


        verticalLayout_2->addLayout(hboxLayout);


        retranslateUi(isubsur);
        QObject::connect(okButton, SIGNAL(clicked()), isubsur, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), isubsur, SLOT(reject()));

        QMetaObject::connectSlotsByName(isubsur);
    } // setupUi

    void retranslateUi(QDialog *isubsur)
    {
        isubsur->setWindowTitle(QApplication::translate("isubsur", "Dialog", 0));
        label_5->setText(QApplication::translate("isubsur", "\346\240\267\345\274\217", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("isubsur", "\347\252\227\346\210\267", 0)
         << QApplication::translate("isubsur", "\346\264\236", 0)
         << QApplication::translate("isubsur", "\351\225\266\346\235\277", 0)
         << QApplication::translate("isubsur", "\351\227\250", 0)
        );
        label->setText(QApplication::translate("isubsur", "\351\225\277\345\272\246", 0));
        label_6->setText(QApplication::translate("isubsur", "mm", 0));
        label_2->setText(QApplication::translate("isubsur", "\351\253\230\345\272\246", 0));
        label_7->setText(QApplication::translate("isubsur", "mm", 0));
        label_3->setText(QApplication::translate("isubsur", "\346\260\264\345\271\263\345\201\217\347\247\273", 0));
        label_8->setText(QApplication::translate("isubsur", "mm", 0));
        label_4->setText(QApplication::translate("isubsur", "\345\236\202\347\233\264\345\201\217\347\247\273", 0));
        label_9->setText(QApplication::translate("isubsur", "mm", 0));
        okButton->setText(QApplication::translate("isubsur", "OK", 0));
        cancelButton->setText(QApplication::translate("isubsur", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class isubsur: public Ui_isubsur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTSUBSURFACE_H
