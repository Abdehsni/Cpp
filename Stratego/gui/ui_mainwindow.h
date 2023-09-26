/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayoutBoard;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayoutBox;
    QLabel *label_2;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *buttonStart;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayoutBox2;
    QLabel *labelBottomPage;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *introLayout;
    QLabel *labelStart;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *nameInputLayout;
    QLabel *labelPlayer1;
    QLabel *labelPlayer2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(981, 653);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(50, 150, 481, 411));
        gridLayoutBoard = new QGridLayout(gridLayoutWidget);
        gridLayoutBoard->setSpacing(0);
        gridLayoutBoard->setObjectName(QString::fromUtf8("gridLayoutBoard"));
        gridLayoutBoard->setContentsMargins(0, 0, 0, 0);
        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(580, 150, 341, 171));
        gridLayoutBox = new QGridLayout(gridLayoutWidget_2);
        gridLayoutBox->setObjectName(QString::fromUtf8("gridLayoutBox"));
        gridLayoutBox->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(270, 120, 47, 14));
        horizontalLayoutWidget_3 = new QWidget(centralwidget);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(270, 60, 431, 41));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        buttonStart = new QPushButton(horizontalLayoutWidget_3);
        buttonStart->setObjectName(QString::fromUtf8("buttonStart"));

        horizontalLayout_3->addWidget(buttonStart);

        gridLayoutWidget_3 = new QWidget(centralwidget);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(580, 370, 341, 191));
        gridLayoutBox2 = new QGridLayout(gridLayoutWidget_3);
        gridLayoutBox2->setObjectName(QString::fromUtf8("gridLayoutBox2"));
        gridLayoutBox2->setContentsMargins(0, 0, 0, 0);
        labelBottomPage = new QLabel(centralwidget);
        labelBottomPage->setObjectName(QString::fromUtf8("labelBottomPage"));
        labelBottomPage->setGeometry(QRect(50, 570, 871, 31));
        QFont font;
        font.setBold(true);
        font.setStrikeOut(false);
        labelBottomPage->setFont(font);
        labelBottomPage->setAutoFillBackground(true);
        labelBottomPage->setAlignment(Qt::AlignCenter);
        labelBottomPage->setWordWrap(false);
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(150, 10, 681, 41));
        introLayout = new QHBoxLayout(horizontalLayoutWidget);
        introLayout->setObjectName(QString::fromUtf8("introLayout"));
        introLayout->setContentsMargins(0, 0, 0, 0);
        labelStart = new QLabel(horizontalLayoutWidget);
        labelStart->setObjectName(QString::fromUtf8("labelStart"));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        labelStart->setFont(font1);

        introLayout->addWidget(labelStart);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        introLayout->addItem(horizontalSpacer_2);

        nameInputLayout = new QLineEdit(horizontalLayoutWidget);
        nameInputLayout->setObjectName(QString::fromUtf8("nameInputLayout"));

        introLayout->addWidget(nameInputLayout);

        labelPlayer1 = new QLabel(centralwidget);
        labelPlayer1->setObjectName(QString::fromUtf8("labelPlayer1"));
        labelPlayer1->setGeometry(QRect(580, 120, 151, 21));
        labelPlayer2 = new QLabel(centralwidget);
        labelPlayer2->setObjectName(QString::fromUtf8("labelPlayer2"));
        labelPlayer2->setGeometry(QRect(580, 336, 141, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 981, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Board", nullptr));
        buttonStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        labelBottomPage->setText(QString());
        labelStart->setText(QCoreApplication::translate("MainWindow", "Joueur 1 ,entrez votre nom :", nullptr));
        labelPlayer1->setText(QCoreApplication::translate("MainWindow", "Joueur 1", nullptr));
        labelPlayer2->setText(QCoreApplication::translate("MainWindow", "Joueur 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
