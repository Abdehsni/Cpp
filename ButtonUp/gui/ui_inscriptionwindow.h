/********************************************************************************
** Form generated from reading UI file 'inscriptionwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSCRIPTIONWINDOW_H
#define UI_INSCRIPTIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InscriptionWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *mainVLayout;
    QVBoxLayout *verticalLayout;
    QLabel *labelMessageBox;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_name;
    QLineEdit *lineNameEdit;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_age;
    QSpinBox *spinBoxNumber;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_6;
    QVBoxLayout *vLayoutButton;
    QPushButton *entryValidationButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *InscriptionWindow)
    {
        if (InscriptionWindow->objectName().isEmpty())
            InscriptionWindow->setObjectName(QString::fromUtf8("InscriptionWindow"));
        InscriptionWindow->resize(506, 420);
        InscriptionWindow->setMaximumSize(QSize(506, 16777215));
        centralwidget = new QWidget(InscriptionWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setMaximumSize(QSize(10000000, 10000000));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        mainVLayout = new QVBoxLayout();
        mainVLayout->setObjectName(QString::fromUtf8("mainVLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        labelMessageBox = new QLabel(centralwidget);
        labelMessageBox->setObjectName(QString::fromUtf8("labelMessageBox"));
        labelMessageBox->setEnabled(true);
        labelMessageBox->setTextFormat(Qt::PlainText);
        labelMessageBox->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelMessageBox);


        mainVLayout->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Expanding);

        mainVLayout->addItem(verticalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_name = new QLabel(centralwidget);
        label_name->setObjectName(QString::fromUtf8("label_name"));

        verticalLayout_2->addWidget(label_name);

        lineNameEdit = new QLineEdit(centralwidget);
        lineNameEdit->setObjectName(QString::fromUtf8("lineNameEdit"));

        verticalLayout_2->addWidget(lineNameEdit);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        label_age = new QLabel(centralwidget);
        label_age->setObjectName(QString::fromUtf8("label_age"));

        verticalLayout_2->addWidget(label_age);

        spinBoxNumber = new QSpinBox(centralwidget);
        spinBoxNumber->setObjectName(QString::fromUtf8("spinBoxNumber"));
        spinBoxNumber->setMinimum(5);

        verticalLayout_2->addWidget(spinBoxNumber);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_5);


        mainVLayout->addLayout(verticalLayout_2);

        verticalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        mainVLayout->addItem(verticalSpacer_6);

        vLayoutButton = new QVBoxLayout();
        vLayoutButton->setObjectName(QString::fromUtf8("vLayoutButton"));
        entryValidationButton = new QPushButton(centralwidget);
        entryValidationButton->setObjectName(QString::fromUtf8("entryValidationButton"));

        vLayoutButton->addWidget(entryValidationButton);


        mainVLayout->addLayout(vLayoutButton);


        gridLayout->addLayout(mainVLayout, 0, 0, 2, 2);

        InscriptionWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(InscriptionWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 506, 20));
        InscriptionWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(InscriptionWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        InscriptionWindow->setStatusBar(statusbar);

        retranslateUi(InscriptionWindow);

        QMetaObject::connectSlotsByName(InscriptionWindow);
    } // setupUi

    void retranslateUi(QMainWindow *InscriptionWindow)
    {
        InscriptionWindow->setWindowTitle(QCoreApplication::translate("InscriptionWindow", "MainWindow", nullptr));
        labelMessageBox->setText(QCoreApplication::translate("InscriptionWindow", "Bienvenu \303\240 Button Up , vous etes \303\240 la fenetre d' inscription.Joueur 1 ,entrez votre nom et votre age ", nullptr));
        label_name->setText(QCoreApplication::translate("InscriptionWindow", "Nom", nullptr));
        label_age->setText(QCoreApplication::translate("InscriptionWindow", "Age", nullptr));
        entryValidationButton->setText(QCoreApplication::translate("InscriptionWindow", "cliquez ici pour l'inscription du joueur 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InscriptionWindow: public Ui_InscriptionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSCRIPTIONWINDOW_H
