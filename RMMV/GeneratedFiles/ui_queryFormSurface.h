/********************************************************************************
** Form generated from reading UI file 'queryFormSurface.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUERYFORMSURFACE_H
#define UI_QUERYFORMSURFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QueryForm
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *QueryForm)
    {
        if (QueryForm->objectName().isEmpty())
            QueryForm->setObjectName(QStringLiteral("QueryForm"));
        QueryForm->resize(306, 84);
        verticalLayout = new QVBoxLayout(QueryForm);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(QueryForm);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(QueryForm);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        okButton = new QPushButton(QueryForm);
        okButton->setObjectName(QStringLiteral("okButton"));

        horizontalLayout->addWidget(okButton);

        cancelButton = new QPushButton(QueryForm);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(QueryForm);
        QObject::connect(okButton, SIGNAL(clicked()), QueryForm, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), QueryForm, SLOT(reject()));

        QMetaObject::connectSlotsByName(QueryForm);
    } // setupUi

    void retranslateUi(QDialog *QueryForm)
    {
        QueryForm->setWindowTitle(QApplication::translate("QueryForm", "\346\217\220\347\244\272", 0));
        label->setText(QApplication::translate("QueryForm", "\346\202\250\345\267\262\347\273\217\345\260\206\345\275\223\345\211\215\347\211\251\344\275\223\345\220\210\345\271\266\343\200\202", 0));
        label_2->setText(QApplication::translate("QueryForm", "\346\202\250\346\203\263\350\246\201\345\260\206\345\256\203\345\217\230\344\270\272\344\270\200\344\270\252\345\260\201\351\227\255\347\232\204\345\233\276\345\275\242\345\220\227?", 0));
        okButton->setText(QApplication::translate("QueryForm", "\346\230\257", 0));
        cancelButton->setText(QApplication::translate("QueryForm", "\345\220\246", 0));
    } // retranslateUi

};

namespace Ui {
    class QueryForm: public Ui_QueryForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUERYFORMSURFACE_H
