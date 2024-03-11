/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *register_2;
    QPushButton *ok_3;
    QPushButton *ku_2;
    QLabel *label_8;
    QLabel *label_4;
    QLabel *label_10;
    QLabel *label_3;
    QLabel *label_11;
    QPushButton *ok_2;
    QWidget *widget;
    QLineEdit *lineEdit_Username_10;
    QLineEdit *lineEdit_Password_10;
    QPushButton *ok_12;
    QLabel *label_24;
    QPushButton *twitter_10;
    QPushButton *face_10;
    QPushButton *youtube_10;
    QPushButton *insta_10;
    QLineEdit *lineEdit_Password_12;
    QLabel *label_36;
    QLabel *label_26;
    QWidget *login;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QWidget *widget_2;
    QLineEdit *lineEdit_Username_11;
    QLineEdit *lineEdit_Password_11;
    QPushButton *ok_13;
    QLabel *label_31;
    QLabel *label_32;
    QPushButton *ku_12;
    QPushButton *twitter_11;
    QPushButton *face_11;
    QPushButton *youtube_11;
    QPushButton *insta_11;
    QLabel *label_35;
    QPushButton *ok_14;
    QPushButton *ku_13;
    QPushButton *ok_15;
    QLabel *label_33;
    QLabel *label_34;
    QLabel *label_gif_animation;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(1221, 719);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(2000, 731));
        MainWindow->setSizeIncrement(QSize(815, 731));
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        MainWindow->setMouseTracking(true);
        MainWindow->setTabletTracking(true);
        MainWindow->setFocusPolicy(Qt::ClickFocus);
        MainWindow->setContextMenuPolicy(Qt::NoContextMenu);
        QIcon icon;
        icon.addFile(QStringLiteral("D:/JUST ANOTHER W.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setWindowOpacity(0.98);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QLatin1String("background-color:rgba(16,30,41,240);\n"
"color:rgba(255,255,255,150);\n"
"border-radius:30px;\n"
"border-color:rgba(255,255,255,255);\n"
"font: 12pt \"MS Shell Dlg 2\";"));
        MainWindow->setIconSize(QSize(26, 26));
        MainWindow->setTabShape(QTabWidget::Rounded);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(-1, -1, 1251, 741));
        register_2 = new QWidget();
        register_2->setObjectName(QStringLiteral("register_2"));
        ok_3 = new QPushButton(register_2);
        ok_3->setObjectName(QStringLiteral("ok_3"));
        ok_3->setGeometry(QRect(1160, 10, 21, 21));
        ok_3->setStyleSheet(QLatin1String("QPushButton#ok_3{\n"
"background-color:rgba(0,125,236,255);\n"
"color: rgb(0, 0, 0);\n"
"font: 15pt \"Permanent Marker\";\n"
"border-radius:10px;\n"
"}\n"
"QPushButton#ok_3:hover{\n"
"background-color:rgba(236,125,0,255);\n"
"color: rgb(255,255, 255);\n"
"font: 15pt \"Permanent Marker\";\n"
"border-radius:10px;\n"
"}"));
        ku_2 = new QPushButton(register_2);
        ku_2->setObjectName(QStringLiteral("ku_2"));
        ku_2->setGeometry(QRect(230, 380, 201, 41));
        ku_2->setStyleSheet(QLatin1String("QPushButton#ku_2{\n"
"background-color:transparent;\n"
"color: rgba(0,125,236,255);\n"
"font: 22pt \"MS Shell Dlg 2\";\n"
"}\n"
"QPushButton#ku_2:hover{\n"
"background-color:transparent;\n"
"color: rgba(50,120,236,255);\n"
"font: 22pt \"MS Shell Dlg 2\";\n"
"text-decoration:underline;\n"
"}"));
        label_8 = new QLabel(register_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(40, 340, 381, 41));
        label_8->setStyleSheet(QLatin1String("color: rgba(255,255,255,200);\n"
"font: 24pt \"MS Shell Dlg 2\";\n"
"background-color:transparent;"));
        label_4 = new QLabel(register_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(-10, 20, 1251, 20));
        label_4->setStyleSheet(QLatin1String("background-color: rgba(0, 0, 0,0);\n"
"font: 12pt \"MS Shell Dlg 2\";\n"
"border: 2px solid rgba(0,0,0,0);\n"
"border-bottom-color:rgba(46,82,101,255);\n"
"color:rgb(255,255,255);\n"
"padding-bottom:7px;\n"
"border-radius:0px;"));
        label_10 = new QLabel(register_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(100, 120, 71, 101));
        label_10->setStyleSheet(QLatin1String("font: 42pt \"MS Shell Dlg 2\";\n"
"background-color:transparent;\n"
"color: rgba(35,125,236,255);"));
        label_3 = new QLabel(register_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, -10, 431, 731));
        label_3->setStyleSheet(QLatin1String("\n"
"border-radius:10px;\n"
"background-color:qlineargradient(spread:pad, x1:0.858, y1:0.375, x2:0, y2:0, stop:0 rgba(16, 30, 41, 200), stop:1 rgba(0, 1, 145, 255));\n"
""));
        label_11 = new QLabel(register_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(170, 120, 201, 101));
        label_11->setStyleSheet(QLatin1String("color: rgba(255,255,255,200);\n"
"font: 42pt \"MS Shell Dlg 2\";\n"
"background-color:transparent;"));
        ok_2 = new QPushButton(register_2);
        ok_2->setObjectName(QStringLiteral("ok_2"));
        ok_2->setGeometry(QRect(1190, 10, 21, 21));
        ok_2->setStyleSheet(QLatin1String("QPushButton#ok_2{\n"
"background-color:rgba(0,125,236,255);\n"
"color: rgb(0, 0, 0);\n"
"font: 10pt \"Permanent Marker\";\n"
"border-radius:10px;\n"
"}\n"
"QPushButton#ok_2:hover{\n"
"background-color:rgba(236,125,0,255);\n"
"color: rgb(255,255, 255);\n"
"font: 10pt \"Permanent Marker\";\n"
"border-radius:10px;\n"
"}"));
        widget = new QWidget(register_2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(400, 50, 811, 651));
        widget->setMinimumSize(QSize(811, 631));
        widget->setMaximumSize(QSize(242424, 242424));
        widget->setSizeIncrement(QSize(811, 631));
        widget->setStyleSheet(QLatin1String("background-color:rgba(16,30,41,240);\n"
"color:rgba(255,255,255,150);\n"
"border-radius:10px;\n"
"font: 12pt \"MS Shell Dlg 2\";"));
        lineEdit_Username_10 = new QLineEdit(widget);
        lineEdit_Username_10->setObjectName(QStringLiteral("lineEdit_Username_10"));
        lineEdit_Username_10->setGeometry(QRect(130, 270, 521, 51));
        lineEdit_Username_10->setSizeIncrement(QSize(250, 300));
        lineEdit_Username_10->setStyleSheet(QLatin1String("background-color: rgba(0, 0, 0,0);\n"
"font: 12pt \"MS Shell Dlg 2\";\n"
"border: 1px solid rgba(0,0,0,0);\n"
"border-bottom-color:rgba(46,82,101,255);\n"
"color:rgb(255,255,255);\n"
"padding-bottom:7px;\n"
"border-radius:0px;"));
        lineEdit_Username_10->setCursorMoveStyle(Qt::VisualMoveStyle);
        lineEdit_Password_10 = new QLineEdit(widget);
        lineEdit_Password_10->setObjectName(QStringLiteral("lineEdit_Password_10"));
        lineEdit_Password_10->setGeometry(QRect(130, 340, 521, 41));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_Password_10->sizePolicy().hasHeightForWidth());
        lineEdit_Password_10->setSizePolicy(sizePolicy);
        lineEdit_Password_10->setMaximumSize(QSize(16777215, 16777215));
        lineEdit_Password_10->setSizeIncrement(QSize(250, 0));
        lineEdit_Password_10->setStyleSheet(QLatin1String("background-color: rgba(0, 0, 0,0);\n"
"font: 12pt \"MS Shell Dlg 2\";\n"
"border: 1px solid rgba(0,0,0,0);\n"
"border-bottom-color:rgba(46,82,101,255);\n"
"color:rgb(255,255,255);\n"
"padding-bottom:7px;\n"
"border-radius:0px;"));
        lineEdit_Password_10->setEchoMode(QLineEdit::Password);
        ok_12 = new QPushButton(widget);
        ok_12->setObjectName(QStringLiteral("ok_12"));
        ok_12->setGeometry(QRect(130, 490, 521, 71));
        ok_12->setStyleSheet(QLatin1String("QPushButton#ok_12{\n"
"	font: 75 8pt \"Poppins\";\n"
"	font: 24pt \"MS Shell Dlg 2\";\n"
"background-color: rgba(2, 65, 118,255);\n"
"color: rgba(255, 255, 255,200);\n"
"border-radius:8px;\n"
"}\n"
"QPushButton#ok_12:pressed{\n"
"padding-left:5px;\n"
"padding-top:5px;\n"
"background-color: rgba(2, 65, 118,100);\n"
"background-position:calc(100% - 10px)center;\n"
"}\n"
"QPushButton#ok_12{\n"
"background-color: rgba(2, 65, 118,200);\n"
"}\n"
"QPushButton#ok_12:hover{\n"
"background-color: rgba(0,125,236,255);\n"
"}\n"
""));
        label_24 = new QLabel(widget);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(270, 110, 271, 141));
        label_24->setStyleSheet(QLatin1String("font: 90pt \"MS Shell Dlg 2\";\n"
"color:rgba(0,125,236,255);"));
        label_24->setAlignment(Qt::AlignCenter);
        twitter_10 = new QPushButton(widget);
        twitter_10->setObjectName(QStringLiteral("twitter_10"));
        twitter_10->setGeometry(QRect(250, 590, 51, 51));
        twitter_10->setStyleSheet(QLatin1String("QPushButton#twitter_10{\n"
"font: 24pt \"Social Media Circled\";\n"
"color: rgba(50,120,236,255);\n"
"border-color:rgba(50,120,236,255);\n"
"border:2px solid rgba(50,120,236,255) ;\n"
"border-radius:10px;\n"
"background-color:rgba(16,30,41,240);\n"
"}\n"
"QPushButton#twitter_10:hover{\n"
"background-color: rgba(50,120,236,200);\n"
"font: 24pt \"Social Media Circled\";\n"
"color: rgba(16,30,41,240);\n"
"border-color:rgba(50,120,236,255);\n"
"border:2px solid rgba(50,120,236,255) ;\n"
"border-radius:10px;\n"
"}"));
        face_10 = new QPushButton(widget);
        face_10->setObjectName(QStringLiteral("face_10"));
        face_10->setGeometry(QRect(320, 590, 51, 51));
        face_10->setStyleSheet(QLatin1String("QPushButton#face_10{\n"
"font: 24pt \"Social Media Circled\";\n"
"color: rgba(50,120,236,255);\n"
"border-color:rgba(50,120,236,255);\n"
"border:2px solid rgba(50,120,236,255) ;\n"
"border-radius:10px;\n"
"background-color:rgba(16,30,41,240);\n"
"}\n"
"QPushButton#face_10:hover{\n"
"background-color: rgba(50,120,236,200);\n"
"font: 24pt \"Social Media Circled\";\n"
"color: rgba(16,30,41,240);\n"
"border-color:rgba(50,120,236,255);\n"
"border:2px solid rgba(50,120,236,255) ;\n"
"border-radius:10px;\n"
"}"));
        youtube_10 = new QPushButton(widget);
        youtube_10->setObjectName(QStringLiteral("youtube_10"));
        youtube_10->setGeometry(QRect(460, 590, 51, 51));
        youtube_10->setStyleSheet(QLatin1String("QPushButton#youtube_10{\n"
"font: 24pt \"Social Media Circled\";\n"
"color: rgba(50,120,236,255);\n"
"border-color:rgba(50,120,236,255);\n"
"border:2px solid rgba(50,120,236,255) ;\n"
"border-radius:10px;\n"
"background-color:rgba(16,30,41,240);\n"
"}\n"
"QPushButton#youtube_10:hover{\n"
"background-color: rgba(50,120,236,200);\n"
"font: 24pt \"Social Media Circled\";\n"
"color: rgba(16,30,41,240);\n"
"border-color:rgba(50,120,236,255);\n"
"border:2px solid rgba(50,120,236,255) ;\n"
"border-radius:10px;\n"
"}"));
        insta_10 = new QPushButton(widget);
        insta_10->setObjectName(QStringLiteral("insta_10"));
        insta_10->setGeometry(QRect(390, 590, 51, 51));
        insta_10->setStyleSheet(QLatin1String("QPushButton#insta_10{\n"
"font: 24pt \"Social Media Circled\";\n"
"color: rgba(50,120,236,255);\n"
"border-color:rgba(50,120,236,255);\n"
"border:2px solid rgba(50,120,236,255) ;\n"
"border-radius:10px;\n"
"background-color:rgba(16,30,41,240);\n"
"}\n"
"QPushButton#insta_10:hover{\n"
"background-color: rgba(50,120,236,200);\n"
"font: 24pt \"Social Media Circled\";\n"
"color: rgba(16,30,41,240);\n"
"border-color:rgba(50,120,236,255);\n"
"border:2px solid rgba(50,120,236,255) ;\n"
"border-radius:10px;\n"
"}"));
        lineEdit_Password_12 = new QLineEdit(widget);
        lineEdit_Password_12->setObjectName(QStringLiteral("lineEdit_Password_12"));
        lineEdit_Password_12->setGeometry(QRect(130, 400, 521, 41));
        sizePolicy.setHeightForWidth(lineEdit_Password_12->sizePolicy().hasHeightForWidth());
        lineEdit_Password_12->setSizePolicy(sizePolicy);
        lineEdit_Password_12->setMaximumSize(QSize(16777215, 16777215));
        lineEdit_Password_12->setSizeIncrement(QSize(250, 0));
        lineEdit_Password_12->setStyleSheet(QLatin1String("background-color: rgba(0, 0, 0,0);\n"
"font: 12pt \"MS Shell Dlg 2\";\n"
"border: 1px solid rgba(0,0,0,0);\n"
"border-bottom-color:rgba(46,82,101,255);\n"
"color:rgb(255,255,255);\n"
"padding-bottom:7px;\n"
"border-radius:0px;"));
        lineEdit_Password_12->setEchoMode(QLineEdit::Password);
        label_36 = new QLabel(widget);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setGeometry(QRect(110, 590, 131, 31));
        label_36->setStyleSheet(QLatin1String("color: rgba(0,125,236,255);\n"
"font: 18pt \"MS Shell Dlg 2\";"));
        label_26 = new QLabel(register_2);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(40, 40, 391, 101));
        label_26->setStyleSheet(QLatin1String("color: rgba(255,255,255,200);\n"
"font: 42pt \"MS Shell Dlg 2\";\n"
"background-color:transparent;"));
        stackedWidget->addWidget(register_2);
        ok_3->raise();
        label_3->raise();
        ok_2->raise();
        widget->raise();
        label_26->raise();
        ku_2->raise();
        label_10->raise();
        label_11->raise();
        label_4->raise();
        label_8->raise();
        login = new QWidget();
        login->setObjectName(QStringLiteral("login"));
        label_27 = new QLabel(login);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(170, 120, 201, 101));
        label_27->setStyleSheet(QLatin1String("color: rgba(255,255,255,200);\n"
"font: 42pt \"MS Shell Dlg 2\";\n"
"background-color:transparent;"));
        label_28 = new QLabel(login);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(-10, 0, 431, 731));
        label_28->setStyleSheet(QLatin1String("\n"
"border-radius:10px;\n"
"background-color:qlineargradient(spread:pad, x1:0.858, y1:0.375, x2:0, y2:0, stop:0 rgba(16, 30, 41, 200), stop:1 rgba(0, 1, 145, 255));\n"
""));
        label_29 = new QLabel(login);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(-10, 20, 1251, 20));
        label_29->setStyleSheet(QLatin1String("background-color: rgba(0, 0, 0,0);\n"
"font: 12pt \"MS Shell Dlg 2\";\n"
"border: 2px solid rgba(0,0,0,0);\n"
"border-bottom-color:rgba(46,82,101,255);\n"
"color:rgb(255,255,255);\n"
"padding-bottom:7px;\n"
"border-radius:0px;"));
        label_30 = new QLabel(login);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(100, 120, 71, 101));
        label_30->setStyleSheet(QLatin1String("font: 42pt \"MS Shell Dlg 2\";\n"
"background-color:transparent;\n"
"color: rgba(35,125,236,255);"));
        widget_2 = new QWidget(login);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(400, 50, 811, 651));
        widget_2->setMinimumSize(QSize(811, 631));
        widget_2->setMaximumSize(QSize(242424, 242424));
        widget_2->setSizeIncrement(QSize(811, 631));
        widget_2->setStyleSheet(QLatin1String("background-color:rgba(16,30,41,240);\n"
"color:rgba(255,255,255,150);\n"
"border-radius:10px;\n"
"font: 12pt \"MS Shell Dlg 2\";"));
        lineEdit_Username_11 = new QLineEdit(widget_2);
        lineEdit_Username_11->setObjectName(QStringLiteral("lineEdit_Username_11"));
        lineEdit_Username_11->setGeometry(QRect(130, 270, 521, 51));
        lineEdit_Username_11->setSizeIncrement(QSize(250, 300));
        lineEdit_Username_11->setStyleSheet(QLatin1String("background-color: rgba(0, 0, 0,0);\n"
"font: 12pt \"MS Shell Dlg 2\";\n"
"border: 1px solid rgba(0,0,0,0);\n"
"border-bottom-color:rgba(46,82,101,255);\n"
"color:rgb(255,255,255);\n"
"padding-bottom:7px;\n"
"border-radius:0px;"));
        lineEdit_Username_11->setCursorMoveStyle(Qt::VisualMoveStyle);
        lineEdit_Password_11 = new QLineEdit(widget_2);
        lineEdit_Password_11->setObjectName(QStringLiteral("lineEdit_Password_11"));
        lineEdit_Password_11->setGeometry(QRect(130, 340, 521, 41));
        sizePolicy.setHeightForWidth(lineEdit_Password_11->sizePolicy().hasHeightForWidth());
        lineEdit_Password_11->setSizePolicy(sizePolicy);
        lineEdit_Password_11->setMaximumSize(QSize(16777215, 16777215));
        lineEdit_Password_11->setSizeIncrement(QSize(250, 0));
        lineEdit_Password_11->setStyleSheet(QLatin1String("background-color: rgba(0, 0, 0,0);\n"
"font: 12pt \"MS Shell Dlg 2\";\n"
"border: 1px solid rgba(0,0,0,0);\n"
"border-bottom-color:rgba(46,82,101,255);\n"
"color:rgb(255,255,255);\n"
"padding-bottom:7px;\n"
"border-radius:0px;"));
        lineEdit_Password_11->setEchoMode(QLineEdit::Password);
        ok_13 = new QPushButton(widget_2);
        ok_13->setObjectName(QStringLiteral("ok_13"));
        ok_13->setGeometry(QRect(130, 450, 521, 71));
        ok_13->setStyleSheet(QLatin1String("QPushButton#ok_13{\n"
"	font: 75 8pt \"Poppins\";\n"
"	font: 24pt \"MS Shell Dlg 2\";\n"
"background-color: rgba(2, 65, 118,255);\n"
"color: rgba(255, 255, 255,200);\n"
"border-radius:8px;\n"
"}\n"
"QPushButton#ok_13:pressed{\n"
"padding-left:5px;\n"
"padding-top:5px;\n"
"background-color: rgba(2, 65, 118,100);\n"
"background-position:calc(100% - 10px)center;\n"
"}\n"
"QPushButton#ok_13{\n"
"background-color: rgba(2, 65, 118,200);\n"
"}\n"
"QPushButton#ok_13:hover{\n"
"background-color: rgba(0,125,236,255);\n"
"}\n"
""));
        label_31 = new QLabel(widget_2);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(270, 110, 271, 141));
        label_31->setStyleSheet(QLatin1String("font: 90pt \"MS Shell Dlg 2\";\n"
"color:rgba(0,125,236,255);"));
        label_31->setAlignment(Qt::AlignCenter);
        label_32 = new QLabel(widget_2);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(210, 550, 251, 20));
        label_32->setStyleSheet(QLatin1String("color: rgba(255,255,255,150);\n"
"font: 11pt \"MS Shell Dlg 2\";"));
        ku_12 = new QPushButton(widget_2);
        ku_12->setObjectName(QStringLiteral("ku_12"));
        ku_12->setGeometry(QRect(460, 550, 75, 20));
        ku_12->setStyleSheet(QLatin1String("QPushButton#ku_12{\n"
"background-color:transparent;\n"
"color: rgba(0,125,236,255);\n"
"}\n"
"QPushButton#ku_12:hover{\n"
"background-color:transparent;\n"
"color: rgba(50,120,236,255);\n"
"text-decoration:underline;\n"
"}"));
        twitter_11 = new QPushButton(widget_2);
        twitter_11->setObjectName(QStringLiteral("twitter_11"));
        twitter_11->setGeometry(QRect(250, 590, 51, 51));
        twitter_11->setStyleSheet(QLatin1String("QPushButton#twitter_11{\n"
"font: 24pt \"Social Media Circled\";\n"
"color: rgba(50,120,236,255);\n"
"border-color:rgba(50,120,236,255);\n"
"border:2px solid rgba(50,120,236,255) ;\n"
"border-radius:10px;\n"
"background-color:rgba(16,30,41,240);\n"
"}\n"
"QPushButton#twitter_11:hover{\n"
"background-color: rgba(50,120,236,200);\n"
"font: 24pt \"Social Media Circled\";\n"
"color: rgba(16,30,41,240);\n"
"border-color:rgba(50,120,236,255);\n"
"border:2px solid rgba(50,120,236,255) ;\n"
"border-radius:10px;\n"
"}"));
        face_11 = new QPushButton(widget_2);
        face_11->setObjectName(QStringLiteral("face_11"));
        face_11->setGeometry(QRect(320, 590, 51, 51));
        face_11->setStyleSheet(QLatin1String("QPushButton#face_11{\n"
"font: 24pt \"Social Media Circled\";\n"
"color: rgba(50,120,236,255);\n"
"border-color:rgba(50,120,236,255);\n"
"border:2px solid rgba(50,120,236,255) ;\n"
"border-radius:10px;\n"
"background-color:rgba(16,30,41,240);\n"
"}\n"
"QPushButton#face_11:hover{\n"
"background-color: rgba(50,120,236,200);\n"
"font: 24pt \"Social Media Circled\";\n"
"color: rgba(16,30,41,240);\n"
"border-color:rgba(50,120,236,255);\n"
"border:2px solid rgba(50,120,236,255) ;\n"
"border-radius:10px;\n"
"}"));
        youtube_11 = new QPushButton(widget_2);
        youtube_11->setObjectName(QStringLiteral("youtube_11"));
        youtube_11->setGeometry(QRect(460, 590, 51, 51));
        youtube_11->setStyleSheet(QLatin1String("QPushButton#youtube_11{\n"
"font: 24pt \"Social Media Circled\";\n"
"color: rgba(50,120,236,255);\n"
"border-color:rgba(50,120,236,255);\n"
"border:2px solid rgba(50,120,236,255) ;\n"
"border-radius:10px;\n"
"background-color:rgba(16,30,41,240);\n"
"}\n"
"QPushButton#youtube_11:hover{\n"
"background-color: rgba(50,120,236,200);\n"
"font: 24pt \"Social Media Circled\";\n"
"color: rgba(16,30,41,240);\n"
"border-color:rgba(50,120,236,255);\n"
"border:2px solid rgba(50,120,236,255) ;\n"
"border-radius:10px;\n"
"}"));
        insta_11 = new QPushButton(widget_2);
        insta_11->setObjectName(QStringLiteral("insta_11"));
        insta_11->setGeometry(QRect(390, 590, 51, 51));
        insta_11->setStyleSheet(QLatin1String("QPushButton#insta_11{\n"
"font: 24pt \"Social Media Circled\";\n"
"color: rgba(50,120,236,255);\n"
"border-color:rgba(50,120,236,255);\n"
"border:2px solid rgba(50,120,236,255) ;\n"
"border-radius:10px;\n"
"background-color:rgba(16,30,41,240);\n"
"}\n"
"QPushButton#insta_11:hover{\n"
"background-color: rgba(50,120,236,200);\n"
"font: 24pt \"Social Media Circled\";\n"
"color: rgba(16,30,41,240);\n"
"border-color:rgba(50,120,236,255);\n"
"border:2px solid rgba(50,120,236,255) ;\n"
"border-radius:10px;\n"
"}"));
        label_35 = new QLabel(widget_2);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setGeometry(QRect(110, 590, 131, 31));
        label_35->setStyleSheet(QLatin1String("color: rgba(0,125,236,255);\n"
"font: 18pt \"MS Shell Dlg 2\";"));
        ok_14 = new QPushButton(login);
        ok_14->setObjectName(QStringLiteral("ok_14"));
        ok_14->setGeometry(QRect(1160, 10, 21, 21));
        ok_14->setStyleSheet(QLatin1String("QPushButton#ok_14{\n"
"background-color:rgba(0,125,236,255);\n"
"color: rgb(0, 0, 0);\n"
"font: 15pt \"Permanent Marker\";\n"
"border-radius:10px;\n"
"}\n"
"QPushButton#ok_14:hover{\n"
"background-color:rgba(236,125,0,255);\n"
"color: rgb(255,255, 255);\n"
"font: 15pt \"Permanent Marker\";\n"
"border-radius:10px;\n"
"}"));
        ku_13 = new QPushButton(login);
        ku_13->setObjectName(QStringLiteral("ku_13"));
        ku_13->setGeometry(QRect(260, 380, 141, 41));
        ku_13->setStyleSheet(QLatin1String("QPushButton#ku_13{\n"
"background-color:transparent;\n"
"color: rgba(0,125,236,255);\n"
"font: 22pt \"MS Shell Dlg 2\";\n"
"}\n"
"QPushButton#ku_13:hover{\n"
"background-color:transparent;\n"
"color: rgba(50,120,236,255);\n"
"font: 22pt \"MS Shell Dlg 2\";\n"
"text-decoration:underline;\n"
"}"));
        ok_15 = new QPushButton(login);
        ok_15->setObjectName(QStringLiteral("ok_15"));
        ok_15->setGeometry(QRect(1190, 10, 21, 21));
        ok_15->setStyleSheet(QLatin1String("QPushButton#ok_15{\n"
"background-color:rgba(0,125,236,255);\n"
"color: rgb(0, 0, 0);\n"
"font: 10pt \"Permanent Marker\";\n"
"border-radius:10px;\n"
"}\n"
"QPushButton#ok_15:hover{\n"
"background-color:rgba(236,125,0,255);\n"
"color: rgb(255,255, 255);\n"
"font: 10pt \"Permanent Marker\";\n"
"border-radius:10px;\n"
"}"));
        label_33 = new QLabel(login);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setGeometry(QRect(40, 40, 391, 101));
        label_33->setStyleSheet(QLatin1String("color: rgba(255,255,255,200);\n"
"font: 42pt \"MS Shell Dlg 2\";\n"
"background-color:transparent;"));
        label_34 = new QLabel(login);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setGeometry(QRect(40, 340, 381, 41));
        label_34->setStyleSheet(QLatin1String("color: rgba(255,255,255,200);\n"
"font: 24pt \"MS Shell Dlg 2\";\n"
"background-color:transparent;"));
        label_gif_animation = new QLabel(login);
        label_gif_animation->setObjectName(QStringLiteral("label_gif_animation"));
        label_gif_animation->setGeometry(QRect(-40, -20, 1271, 751));
        label_gif_animation->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        stackedWidget->addWidget(login);
        label_gif_animation->raise();
        label_28->raise();
        widget_2->raise();
        ok_15->raise();
        label_34->raise();
        ku_13->raise();
        label_27->raise();
        label_29->raise();
        label_30->raise();
        label_33->raise();
        ok_14->raise();
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Log In", Q_NULLPTR));
        ok_3->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        ku_2->setText(QApplication::translate("MainWindow", "Login...", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Already have an account ?", Q_NULLPTR));
        label_4->setText(QString());
        label_10->setText(QApplication::translate("MainWindow", "VE", Q_NULLPTR));
        label_3->setText(QString());
        label_11->setText(QApplication::translate("MainWindow", "WATCH", Q_NULLPTR));
        ok_2->setText(QApplication::translate("MainWindow", "X", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        widget->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        lineEdit_Username_10->setPlaceholderText(QApplication::translate("MainWindow", "User Name", Q_NULLPTR));
        lineEdit_Password_10->setPlaceholderText(QApplication::translate("MainWindow", "Password", Q_NULLPTR));
        ok_12->setText(QApplication::translate("MainWindow", "Register", Q_NULLPTR));
        label_24->setText(QApplication::translate("MainWindow", "+\356\201\226", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        twitter_10->setWhatsThis(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Social Media Circled'; font-size:24pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"https://twitter.com/home\"><span style=\" text-decoration: underline; color:#0000ff;\">twitter</span></a></p></body></html>", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        twitter_10->setText(QApplication::translate("MainWindow", "D", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        face_10->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p><a href=\"https://facebook.com\"><span style=\" text-decoration: underline; color:#0000ff;\">facebook</span></a></p></body></html>", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        face_10->setText(QApplication::translate("MainWindow", "E", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        youtube_10->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p><a href=\"https://youtube.com\"><span style=\" text-decoration: underline; color:#0000ff;\">youtube</span></a></p></body></html>", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        youtube_10->setText(QApplication::translate("MainWindow", "M", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        insta_10->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p><a href=\"https://instagram.com\"><span style=\" text-decoration: underline; color:#0000ff;\">insta</span></a></p></body></html>", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        insta_10->setText(QApplication::translate("MainWindow", "Q", Q_NULLPTR));
        lineEdit_Password_12->setPlaceholderText(QApplication::translate("MainWindow", "Confirm Password", Q_NULLPTR));
        label_36->setText(QApplication::translate("MainWindow", "Find us on :", Q_NULLPTR));
        label_26->setText(QApplication::translate("MainWindow", "Welcome ,", Q_NULLPTR));
        label_27->setText(QApplication::translate("MainWindow", "WATCH", Q_NULLPTR));
        label_28->setText(QString());
        label_29->setText(QString());
        label_30->setText(QApplication::translate("MainWindow", "VE", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        widget_2->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        lineEdit_Username_11->setText(QString());
        lineEdit_Username_11->setPlaceholderText(QApplication::translate("MainWindow", "User Name", Q_NULLPTR));
        lineEdit_Password_11->setPlaceholderText(QApplication::translate("MainWindow", "Password", Q_NULLPTR));
        ok_13->setText(QApplication::translate("MainWindow", "Login", Q_NULLPTR));
        label_31->setText(QApplication::translate("MainWindow", "\356\201\226", Q_NULLPTR));
        label_32->setText(QApplication::translate("MainWindow", "Forgot your Username or Password ?", Q_NULLPTR));
        ku_12->setText(QApplication::translate("MainWindow", "Click Here", Q_NULLPTR));
        twitter_11->setText(QApplication::translate("MainWindow", "D", Q_NULLPTR));
        face_11->setText(QApplication::translate("MainWindow", "E", Q_NULLPTR));
        youtube_11->setText(QApplication::translate("MainWindow", "M", Q_NULLPTR));
        insta_11->setText(QApplication::translate("MainWindow", "Q", Q_NULLPTR));
        label_35->setText(QApplication::translate("MainWindow", "Find us on :", Q_NULLPTR));
        ok_14->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        ku_13->setText(QApplication::translate("MainWindow", "Register...", Q_NULLPTR));
        ok_15->setText(QApplication::translate("MainWindow", "X", Q_NULLPTR));
        label_33->setText(QApplication::translate("MainWindow", "Welcome ,", Q_NULLPTR));
        label_34->setText(QApplication::translate("MainWindow", "Don't have an account ?", Q_NULLPTR));
        label_gif_animation->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
