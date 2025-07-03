/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *startpage;
    QLabel *label1;
    QPushButton *startbtn;
    QPushButton *jsonbtn;
    QWidget *inputpage;
    QSpinBox *spinBox;
    QLabel *label2;
    QLabel *label3;
    QPushButton *btn2;
    QWidget *mazepage;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *ziyuanlab;
    QPushButton *restartbtn;
    QPushButton *forbtn;
    QPushButton *greedbtn;
    QWidget *lockpage;
    QLabel *flabel;
    QLabel *slabel;
    QLabel *tlabel;
    QPushButton *returnbtn;
    QPushButton *lockbtn;
    QLabel *maplab;
    QWidget *bosspage;
    QPushButton *bossbtn;
    QLabel *ilab;
    QLabel *blab;
    QLabel *bnlab;
    QLabel *bloodlab;
    QLabel *dlab;
    QLabel *lab1;
    QLabel *lab2;
    QLabel *lab3;
    QLabel *vslab;
    QPushButton *returnbtn2;
    QLabel *lab4;
    QLabel *lab5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1041, 791);
        MainWindow->setMinimumSize(QSize(1041, 791));
        MainWindow->setMaximumSize(QSize(1041, 842));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(1041, 791));
        centralwidget->setMaximumSize(QSize(1041, 791));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 10, 1041, 791));
        stackedWidget->setMinimumSize(QSize(1041, 791));
        stackedWidget->setMaximumSize(QSize(1041, 791));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        startpage = new QWidget();
        startpage->setObjectName(QString::fromUtf8("startpage"));
        startpage->setMinimumSize(QSize(1041, 791));
        startpage->setMaximumSize(QSize(1041, 791));
        label1 = new QLabel(startpage);
        label1->setObjectName(QString::fromUtf8("label1"));
        label1->setGeometry(QRect(20, -10, 981, 741));
        startbtn = new QPushButton(startpage);
        startbtn->setObjectName(QString::fromUtf8("startbtn"));
        startbtn->setGeometry(QRect(200, 620, 93, 28));
        jsonbtn = new QPushButton(startpage);
        jsonbtn->setObjectName(QString::fromUtf8("jsonbtn"));
        jsonbtn->setGeometry(QRect(710, 630, 93, 28));
        stackedWidget->addWidget(startpage);
        inputpage = new QWidget();
        inputpage->setObjectName(QString::fromUtf8("inputpage"));
        inputpage->setMinimumSize(QSize(1041, 791));
        inputpage->setMaximumSize(QSize(1041, 791));
        spinBox = new QSpinBox(inputpage);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(320, 600, 391, 22));
        label2 = new QLabel(inputpage);
        label2->setObjectName(QString::fromUtf8("label2"));
        label2->setGeometry(QRect(350, 310, 331, 221));
        label3 = new QLabel(inputpage);
        label3->setObjectName(QString::fromUtf8("label3"));
        label3->setGeometry(QRect(210, 40, 621, 211));
        label3->setStyleSheet(QString::fromUtf8("background-image: url(:/title2.png);"));
        btn2 = new QPushButton(inputpage);
        btn2->setObjectName(QString::fromUtf8("btn2"));
        btn2->setGeometry(QRect(460, 680, 93, 28));
        stackedWidget->addWidget(inputpage);
        mazepage = new QWidget();
        mazepage->setObjectName(QString::fromUtf8("mazepage"));
        mazepage->setMinimumSize(QSize(1041, 791));
        mazepage->setMaximumSize(QSize(1041, 791));
        pushButton = new QPushButton(mazepage);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(840, 630, 93, 28));
        label = new QLabel(mazepage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(810, 70, 72, 15));
        ziyuanlab = new QLabel(mazepage);
        ziyuanlab->setObjectName(QString::fromUtf8("ziyuanlab"));
        ziyuanlab->setGeometry(QRect(771, 260, 161, 41));
        restartbtn = new QPushButton(mazepage);
        restartbtn->setObjectName(QString::fromUtf8("restartbtn"));
        restartbtn->setGeometry(QRect(840, 530, 93, 28));
        forbtn = new QPushButton(mazepage);
        forbtn->setObjectName(QString::fromUtf8("forbtn"));
        forbtn->setGeometry(QRect(840, 440, 93, 28));
        greedbtn = new QPushButton(mazepage);
        greedbtn->setObjectName(QString::fromUtf8("greedbtn"));
        greedbtn->setGeometry(QRect(840, 370, 93, 28));
        stackedWidget->addWidget(mazepage);
        lockpage = new QWidget();
        lockpage->setObjectName(QString::fromUtf8("lockpage"));
        lockpage->setMinimumSize(QSize(1041, 791));
        lockpage->setMaximumSize(QSize(1041, 791));
        lockpage->setStyleSheet(QString::fromUtf8("#lockpage{\n"
"background-image: url(:/ne/lock.png);\n"
"background-position: center;\n"
"background-size: cover; \n"
"}"));
        flabel = new QLabel(lockpage);
        flabel->setObjectName(QString::fromUtf8("flabel"));
        flabel->setGeometry(QRect(180, 450, 81, 151));
        flabel->setStyleSheet(QString::fromUtf8("font: 87 28pt \"Arial Black\";"));
        slabel = new QLabel(lockpage);
        slabel->setObjectName(QString::fromUtf8("slabel"));
        slabel->setGeometry(QRect(370, 464, 81, 131));
        slabel->setStyleSheet(QString::fromUtf8("font: 87 28pt \"Arial Black\";"));
        tlabel = new QLabel(lockpage);
        tlabel->setObjectName(QString::fromUtf8("tlabel"));
        tlabel->setGeometry(QRect(551, 484, 91, 131));
        tlabel->setStyleSheet(QString::fromUtf8("font: 87 28pt \"Arial Black\";"));
        returnbtn = new QPushButton(lockpage);
        returnbtn->setObjectName(QString::fromUtf8("returnbtn"));
        returnbtn->setGeometry(QRect(790, 480, 93, 28));
        lockbtn = new QPushButton(lockpage);
        lockbtn->setObjectName(QString::fromUtf8("lockbtn"));
        lockbtn->setGeometry(QRect(790, 570, 93, 28));
        maplab = new QLabel(lockpage);
        maplab->setObjectName(QString::fromUtf8("maplab"));
        maplab->setGeometry(QRect(751, 140, 191, 211));
        stackedWidget->addWidget(lockpage);
        maplab->raise();
        flabel->raise();
        slabel->raise();
        tlabel->raise();
        returnbtn->raise();
        lockbtn->raise();
        bosspage = new QWidget();
        bosspage->setObjectName(QString::fromUtf8("bosspage"));
        bosspage->setMinimumSize(QSize(1041, 791));
        bosspage->setMaximumSize(QSize(1041, 791));
        bossbtn = new QPushButton(bosspage);
        bossbtn->setObjectName(QString::fromUtf8("bossbtn"));
        bossbtn->setGeometry(QRect(420, 650, 93, 28));
        ilab = new QLabel(bosspage);
        ilab->setObjectName(QString::fromUtf8("ilab"));
        ilab->setGeometry(QRect(450, 30, 221, 31));
        blab = new QLabel(bosspage);
        blab->setObjectName(QString::fromUtf8("blab"));
        blab->setGeometry(QRect(60, 290, 181, 221));
        bnlab = new QLabel(bosspage);
        bnlab->setObjectName(QString::fromUtf8("bnlab"));
        bnlab->setGeometry(QRect(80, 260, 111, 21));
        bloodlab = new QLabel(bosspage);
        bloodlab->setObjectName(QString::fromUtf8("bloodlab"));
        bloodlab->setGeometry(QRect(20, 510, 251, 231));
        dlab = new QLabel(bosspage);
        dlab->setObjectName(QString::fromUtf8("dlab"));
        dlab->setGeometry(QRect(510, 290, 181, 211));
        dlab->setStyleSheet(QString::fromUtf8(""));
        lab1 = new QLabel(bosspage);
        lab1->setObjectName(QString::fromUtf8("lab1"));
        lab1->setGeometry(QRect(790, 30, 72, 71));
        lab2 = new QLabel(bosspage);
        lab2->setObjectName(QString::fromUtf8("lab2"));
        lab2->setGeometry(QRect(790, 180, 72, 81));
        lab3 = new QLabel(bosspage);
        lab3->setObjectName(QString::fromUtf8("lab3"));
        lab3->setGeometry(QRect(790, 310, 72, 91));
        vslab = new QLabel(bosspage);
        vslab->setObjectName(QString::fromUtf8("vslab"));
        vslab->setGeometry(QRect(290, 330, 171, 141));
        vslab->setStyleSheet(QString::fromUtf8("font: 20pt \"Niagara Engraved\";"));
        returnbtn2 = new QPushButton(bosspage);
        returnbtn2->setObjectName(QString::fromUtf8("returnbtn2"));
        returnbtn2->setGeometry(QRect(610, 650, 93, 28));
        lab4 = new QLabel(bosspage);
        lab4->setObjectName(QString::fromUtf8("lab4"));
        lab4->setGeometry(QRect(790, 440, 72, 91));
        lab5 = new QLabel(bosspage);
        lab5->setObjectName(QString::fromUtf8("lab5"));
        lab5->setGeometry(QRect(790, 570, 72, 91));
        stackedWidget->addWidget(bosspage);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1041, 26));
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
        label1->setText(QString());
        startbtn->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
        jsonbtn->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\205\245json", nullptr));
        label2->setText(QString());
        label3->setText(QString());
        btn2->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\347\224\237\346\210\220", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\344\270\213\344\270\200\346\255\245", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        ziyuanlab->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\350\265\204\346\272\220\357\274\2320", nullptr));
        restartbtn->setText(QCoreApplication::translate("MainWindow", "\345\206\215\346\235\245\344\270\200\345\261\200", nullptr));
        forbtn->setText(QCoreApplication::translate("MainWindow", "\347\233\264\350\276\276\347\273\210\347\202\271", nullptr));
        greedbtn->setText(QCoreApplication::translate("MainWindow", "\350\264\252\345\277\203\350\267\257\347\272\277", nullptr));
        flabel->setText(QString());
        slabel->setText(QString());
        tlabel->setText(QString());
        returnbtn->setText(QCoreApplication::translate("MainWindow", "\350\277\224\345\233\236\350\277\267\345\256\253", nullptr));
        lockbtn->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\350\247\243\345\257\206", nullptr));
        maplab->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
        bossbtn->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\344\275\234\346\210\230", nullptr));
        ilab->setText(QCoreApplication::translate("MainWindow", "\347\254\254\345\207\240\345\233\236\345\220\210", nullptr));
        blab->setText(QCoreApplication::translate("MainWindow", "boss\345\233\276\347\211\207", nullptr));
        bnlab->setText(QCoreApplication::translate("MainWindow", "\346\225\260\351\207\217:(a/size)", nullptr));
        bloodlab->setText(QString());
        dlab->setText(QCoreApplication::translate("MainWindow", "d", nullptr));
        lab1->setText(QCoreApplication::translate("MainWindow", "\346\212\200\350\203\2751", nullptr));
        lab2->setText(QCoreApplication::translate("MainWindow", "\346\212\200\350\203\2752", nullptr));
        lab3->setText(QCoreApplication::translate("MainWindow", "\346\212\200\350\203\2753", nullptr));
        vslab->setText(QString());
        returnbtn2->setText(QCoreApplication::translate("MainWindow", "\350\277\224\345\233\236\350\277\267\345\256\253", nullptr));
        lab4->setText(QCoreApplication::translate("MainWindow", "\346\212\200\350\203\2754", nullptr));
        lab5->setText(QCoreApplication::translate("MainWindow", "\346\212\200\350\203\2755", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
