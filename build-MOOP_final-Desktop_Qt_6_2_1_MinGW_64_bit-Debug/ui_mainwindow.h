/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextBrowser *mainWindow;
    QPushButton *screen_4;
    QPushButton *screen_3;
    QPushButton *screen_2;
    QPushButton *screen_1;
    QPushButton *screen_5;
    QPushButton *screen_6;
    QPushButton *screen_7;
    QPushButton *screen_8;
    QPushButton *button_1;
    QPushButton *button_2;
    QPushButton *button_3;
    QPushButton *button_4;
    QPushButton *button_5;
    QPushButton *button_6;
    QPushButton *button_7;
    QPushButton *button_8;
    QPushButton *button_9;
    QPushButton *ok;
    QPushButton *reset;
    QPushButton *cancel;
    QPushButton *insert_card;
    QTextBrowser *firstWindow;
    QTextBrowser *PIN;
    QTextBrowser *empty;
    QLabel *pins;
    QTextBrowser *cash;
    QPushButton *settings_btn;
    QPushButton *insert_cash;
    QTextBrowser *cards;
    QTextBrowser *addCash;
    QLabel *sum;
    QTextBrowser *other;
    QPushButton *button_0;
    QTextBrowser *info;
    QLabel *image;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(750, 727);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        mainWindow = new QTextBrowser(centralwidget);
        mainWindow->setObjectName(QString::fromUtf8("mainWindow"));
        mainWindow->setGeometry(QRect(100, 80, 341, 251));
        QFont font;
        font.setPointSize(10);
        mainWindow->setFont(font);
        screen_4 = new QPushButton(centralwidget);
        screen_4->setObjectName(QString::fromUtf8("screen_4"));
        screen_4->setGeometry(QRect(20, 290, 75, 31));
        screen_3 = new QPushButton(centralwidget);
        screen_3->setObjectName(QString::fromUtf8("screen_3"));
        screen_3->setGeometry(QRect(20, 220, 75, 31));
        screen_2 = new QPushButton(centralwidget);
        screen_2->setObjectName(QString::fromUtf8("screen_2"));
        screen_2->setGeometry(QRect(20, 150, 75, 31));
        screen_1 = new QPushButton(centralwidget);
        screen_1->setObjectName(QString::fromUtf8("screen_1"));
        screen_1->setGeometry(QRect(20, 90, 75, 31));
        screen_5 = new QPushButton(centralwidget);
        screen_5->setObjectName(QString::fromUtf8("screen_5"));
        screen_5->setGeometry(QRect(450, 90, 75, 31));
        screen_6 = new QPushButton(centralwidget);
        screen_6->setObjectName(QString::fromUtf8("screen_6"));
        screen_6->setGeometry(QRect(450, 150, 75, 31));
        screen_7 = new QPushButton(centralwidget);
        screen_7->setObjectName(QString::fromUtf8("screen_7"));
        screen_7->setGeometry(QRect(450, 220, 75, 31));
        screen_8 = new QPushButton(centralwidget);
        screen_8->setObjectName(QString::fromUtf8("screen_8"));
        screen_8->setGeometry(QRect(450, 290, 75, 31));
        button_1 = new QPushButton(centralwidget);
        button_1->setObjectName(QString::fromUtf8("button_1"));
        button_1->setGeometry(QRect(170, 360, 51, 51));
        button_1->setFont(font);
        button_2 = new QPushButton(centralwidget);
        button_2->setObjectName(QString::fromUtf8("button_2"));
        button_2->setGeometry(QRect(240, 360, 51, 51));
        button_2->setFont(font);
        button_3 = new QPushButton(centralwidget);
        button_3->setObjectName(QString::fromUtf8("button_3"));
        button_3->setGeometry(QRect(310, 360, 51, 51));
        button_3->setFont(font);
        button_4 = new QPushButton(centralwidget);
        button_4->setObjectName(QString::fromUtf8("button_4"));
        button_4->setGeometry(QRect(170, 420, 51, 51));
        button_4->setFont(font);
        button_5 = new QPushButton(centralwidget);
        button_5->setObjectName(QString::fromUtf8("button_5"));
        button_5->setGeometry(QRect(240, 420, 51, 51));
        button_5->setFont(font);
        button_6 = new QPushButton(centralwidget);
        button_6->setObjectName(QString::fromUtf8("button_6"));
        button_6->setGeometry(QRect(310, 420, 51, 51));
        button_6->setFont(font);
        button_7 = new QPushButton(centralwidget);
        button_7->setObjectName(QString::fromUtf8("button_7"));
        button_7->setGeometry(QRect(170, 480, 51, 51));
        button_7->setFont(font);
        button_8 = new QPushButton(centralwidget);
        button_8->setObjectName(QString::fromUtf8("button_8"));
        button_8->setGeometry(QRect(240, 480, 51, 51));
        button_8->setFont(font);
        button_9 = new QPushButton(centralwidget);
        button_9->setObjectName(QString::fromUtf8("button_9"));
        button_9->setGeometry(QRect(310, 480, 51, 51));
        button_9->setFont(font);
        ok = new QPushButton(centralwidget);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(140, 600, 81, 51));
        reset = new QPushButton(centralwidget);
        reset->setObjectName(QString::fromUtf8("reset"));
        reset->setGeometry(QRect(220, 600, 91, 51));
        cancel = new QPushButton(centralwidget);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(310, 600, 81, 51));
        insert_card = new QPushButton(centralwidget);
        insert_card->setObjectName(QString::fromUtf8("insert_card"));
        insert_card->setGeometry(QRect(450, 410, 181, 61));
        insert_card->setFont(font);
        firstWindow = new QTextBrowser(centralwidget);
        firstWindow->setObjectName(QString::fromUtf8("firstWindow"));
        firstWindow->setGeometry(QRect(100, 80, 341, 251));
        firstWindow->setFont(font);
        PIN = new QTextBrowser(centralwidget);
        PIN->setObjectName(QString::fromUtf8("PIN"));
        PIN->setGeometry(QRect(530, 170, 171, 121));
        PIN->setFont(font);
        empty = new QTextBrowser(centralwidget);
        empty->setObjectName(QString::fromUtf8("empty"));
        empty->setGeometry(QRect(100, 80, 341, 251));
        empty->setFont(font);
        pins = new QLabel(centralwidget);
        pins->setObjectName(QString::fromUtf8("pins"));
        pins->setGeometry(QRect(620, 230, 47, 13));
        cash = new QTextBrowser(centralwidget);
        cash->setObjectName(QString::fromUtf8("cash"));
        cash->setGeometry(QRect(100, 80, 341, 251));
        cash->setFont(font);
        cash->setTextInteractionFlags(Qt::NoTextInteraction);
        settings_btn = new QPushButton(centralwidget);
        settings_btn->setObjectName(QString::fromUtf8("settings_btn"));
        settings_btn->setGeometry(QRect(580, 100, 75, 41));
        insert_cash = new QPushButton(centralwidget);
        insert_cash->setObjectName(QString::fromUtf8("insert_cash"));
        insert_cash->setGeometry(QRect(450, 510, 181, 61));
        insert_cash->setFont(font);
        cards = new QTextBrowser(centralwidget);
        cards->setObjectName(QString::fromUtf8("cards"));
        cards->setGeometry(QRect(100, 80, 341, 251));
        cards->setFont(font);
        addCash = new QTextBrowser(centralwidget);
        addCash->setObjectName(QString::fromUtf8("addCash"));
        addCash->setGeometry(QRect(100, 80, 341, 251));
        addCash->setFont(font);
        sum = new QLabel(centralwidget);
        sum->setObjectName(QString::fromUtf8("sum"));
        sum->setGeometry(QRect(640, 200, 47, 13));
        other = new QTextBrowser(centralwidget);
        other->setObjectName(QString::fromUtf8("other"));
        other->setGeometry(QRect(100, 80, 341, 251));
        other->setFont(font);
        button_0 = new QPushButton(centralwidget);
        button_0->setObjectName(QString::fromUtf8("button_0"));
        button_0->setGeometry(QRect(240, 540, 51, 51));
        button_0->setFont(font);
        info = new QTextBrowser(centralwidget);
        info->setObjectName(QString::fromUtf8("info"));
        info->setGeometry(QRect(100, 80, 341, 251));
        info->setFont(font);
        image = new QLabel(centralwidget);
        image->setObjectName(QString::fromUtf8("image"));
        image->setGeometry(QRect(30, 10, 141, 41));
        image->setPixmap(QPixmap(QString::fromUtf8("img/atm.jpg")));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 750, 22));
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
        mainWindow->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8.25pt;\"><br /></p></body></html>", nullptr));
        screen_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        screen_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        screen_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        screen_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        screen_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        screen_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        screen_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        screen_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        button_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        button_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        button_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        button_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        button_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        button_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        button_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        button_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        button_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        ok->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        reset->setText(QCoreApplication::translate("MainWindow", "RESET", nullptr));
        cancel->setText(QCoreApplication::translate("MainWindow", "CANCEL", nullptr));
        insert_card->setText(QCoreApplication::translate("MainWindow", "Insert card", nullptr));
        firstWindow->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8.25pt;\"><br /></p></body></html>", nullptr));
        empty->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8.25pt;\"><br /></p></body></html>", nullptr));
        pins->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        cash->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8.25pt;\"><br /></p></body></html>", nullptr));
        settings_btn->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        insert_cash->setText(QCoreApplication::translate("MainWindow", "Insert cash", nullptr));
        cards->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8.25pt;\"><br /></p></body></html>", nullptr));
        addCash->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8.25pt;\"><br /></p></body></html>", nullptr));
        sum->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        other->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8.25pt;\"><br /></p></body></html>", nullptr));
        button_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        image->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
