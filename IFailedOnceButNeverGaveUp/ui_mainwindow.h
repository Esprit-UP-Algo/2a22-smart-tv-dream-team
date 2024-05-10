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
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
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
    QWidget *forogtpaasword;
    QLabel *label_36;
    QLineEdit *email;
    QPushButton *ok_16;
    QLabel *label_37;
    QLineEdit *server;
    QLineEdit *port;
    QLineEdit *uname;
    QLineEdit *paswd;
    QLineEdit *subject;
    QPlainTextEdit *msg;
    QWidget *page;
    QWidget *page_2;

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
        widget_2->setGeometry(QRect(410, 50, 811, 651));
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
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
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
        ku_13->setGeometry(QRect(240, 380, 171, 41));
        ku_13->setStyleSheet(QLatin1String("QPushButton#ku_13{\n"
"background-color:transparent;\n"
"color: rgba(0,125,236,255);\n"
"font: 16pt \"MS Shell Dlg 2\";\n"
"}\n"
"QPushButton#ku_13:hover{\n"
"background-color:transparent;\n"
"color: rgba(50,120,236,255);\n"
"font: 16pt \"MS Shell Dlg 2\";\n"
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
        forogtpaasword = new QWidget();
        forogtpaasword->setObjectName(QStringLiteral("forogtpaasword"));
        label_36 = new QLabel(forogtpaasword);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setGeometry(QRect(20, 30, 841, 71));
        label_36->setStyleSheet(QLatin1String("color: rgba(255,255,255,200);\n"
"font: 40pt \"MS Shell Dlg 2\";\n"
"background-color:transparent;"));
        email = new QLineEdit(forogtpaasword);
        email->setObjectName(QStringLiteral("email"));
        email->setGeometry(QRect(200, 320, 731, 51));
        email->setSizeIncrement(QSize(250, 300));
        email->setStyleSheet(QLatin1String("background-color: rgba(0, 0, 0,0);\n"
"font: 18pt \"MS Shell Dlg 2\";\n"
"border: 1px solid rgba(0,0,0,0);\n"
"border-bottom-color:rgba(46,82,101,255);\n"
"color:rgb(255,255,255);\n"
"padding-bottom:7px;\n"
"border-radius:0px;"));
        email->setCursorMoveStyle(Qt::VisualMoveStyle);
        ok_16 = new QPushButton(forogtpaasword);
        ok_16->setObjectName(QStringLiteral("ok_16"));
        ok_16->setGeometry(QRect(320, 510, 521, 71));
        ok_16->setStyleSheet(QLatin1String("QPushButton#ok_16{\n"
"	font: 75 8pt \"Poppins\";\n"
"	font: 24pt \"MS Shell Dlg 2\";\n"
"background-color: rgba(2, 65, 118,255);\n"
"color: rgba(255, 255, 255,200);\n"
"border-radius:8px;\n"
"}\n"
"QPushButton#ok_16:pressed{\n"
"padding-left:5px;\n"
"padding-top:5px;\n"
"background-color: rgba(2, 65, 118,100);\n"
"background-position:calc(100% - 10px)center;\n"
"}\n"
"QPushButton#ok_16{\n"
"background-color: rgba(2, 65, 118,200);\n"
"}\n"
"QPushButton#ok_16:hover{\n"
"background-color: rgba(0,125,236,255);\n"
"}\n"
""));
        label_37 = new QLabel(forogtpaasword);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setGeometry(QRect(210, 360, 481, 71));
        label_37->setStyleSheet(QLatin1String("color: rgba(255,255,255,200);\n"
"font: 9pt \"MS Shell Dlg 2\";\n"
"background-color:transparent;"));
        server = new QLineEdit(forogtpaasword);
        server->setObjectName(QStringLiteral("server"));
        server->setGeometry(QRect(220, 160, 395, 20));
        port = new QLineEdit(forogtpaasword);
        port->setObjectName(QStringLiteral("port"));
        port->setGeometry(QRect(220, 189, 395, 20));
        uname = new QLineEdit(forogtpaasword);
        uname->setObjectName(QStringLiteral("uname"));
        uname->setGeometry(QRect(230, 220, 395, 20));
        paswd = new QLineEdit(forogtpaasword);
        paswd->setObjectName(QStringLiteral("paswd"));
        paswd->setGeometry(QRect(230, 249, 395, 20));
        paswd->setEchoMode(QLineEdit::Password);
        subject = new QLineEdit(forogtpaasword);
        subject->setObjectName(QStringLiteral("subject"));
        subject->setGeometry(QRect(660, 160, 395, 20));
        msg = new QPlainTextEdit(forogtpaasword);
        msg->setObjectName(QStringLiteral("msg"));
        msg->setGeometry(QRect(660, 201, 71, 20));
        stackedWidget->addWidget(forogtpaasword);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Log In", Q_NULLPTR));
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
        ku_13->setText(QApplication::translate("MainWindow", "Forgot password...", Q_NULLPTR));
        ok_15->setText(QApplication::translate("MainWindow", "X", Q_NULLPTR));
        label_33->setText(QApplication::translate("MainWindow", "Welcome ,", Q_NULLPTR));
        label_34->setText(QApplication::translate("MainWindow", "Already have an account ?", Q_NULLPTR));
        label_gif_animation->setText(QString());
        label_36->setText(QApplication::translate("MainWindow", "Please Enter Your Email Address :", Q_NULLPTR));
        email->setText(QString());
        email->setPlaceholderText(QApplication::translate("MainWindow", "Email Address", Q_NULLPTR));
        ok_16->setText(QApplication::translate("MainWindow", "Send", Q_NULLPTR));
        label_37->setText(QApplication::translate("MainWindow", "(Note*) You Will Receive A Mail After A Short Period Of Time That Has Your Password", Q_NULLPTR));
        server->setText(QApplication::translate("MainWindow", "smtp.gmail.com", Q_NULLPTR));
        port->setText(QApplication::translate("MainWindow", "465", Q_NULLPTR));
        uname->setText(QApplication::translate("MainWindow", "souhaib.touaiti@esprit.tn", Q_NULLPTR));
        paswd->setInputMask(QString());
        paswd->setText(QApplication::translate("MainWindow", "221JMT5189", Q_NULLPTR));
        subject->setText(QString());
        msg->setPlainText(QApplication::translate("MainWindow", "7865", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
