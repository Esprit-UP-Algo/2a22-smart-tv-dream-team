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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page_0;
    QPushButton *loM;
    QPushButton *seriesM;
    QPushButton *modifyButtonM;
    QLabel *label_3M;
    QPushButton *returnButtonM;
    QLabel *label_5M;
    QPushButton *deleteButtonM;
    QPushButton *trieButtonM;
    QGroupBox *barreTrieM;
    QLabel *label_2M;
    QLabel *label_8M;
    QPushButton *vewatchButtonM;
    QPushButton *tvM;
    QPushButton *radioM;
    QLabel *labelM;
    QLabel *label_16M;
    QTextEdit *textEdit_2M;
    QPushButton *series_2M;
    QPushButton *statisticsM;
    QWidget *page_1;
    QPushButton *vewatch_2M;
    QLabel *label_13M;
    QLabel *formM;
    QLineEdit *ProducerM;
    QPushButton *imageButtonM;
    QLineEdit *TitleM;
    QTextEdit *textEditM;
    QPushButton *addButtonM;
    QLabel *addChannelM;
    QRadioButton *radioButtonM;
    QRadioButton *radioButton_2M;
    QTextEdit *textEdit_5M;
    QWidget *page_2;
    QPushButton *radio_2M;
    QPushButton *modifyButton_2M;
    QPushButton *add_2M;
    QPushButton *vwatchRadioM;
    QLabel *descriptionRM;
    QPushButton *returnButton_2M;
    QLabel *label_6M;
    QPushButton *tv_2M;
    QPushButton *vewatchButton_2M;
    QLabel *label_17M;
    QGroupBox *barreTrie_2M;
    QLabel *label_18M;
    QLabel *label_19M;
    QPushButton *trieButton_2M;
    QLabel *label_20M;
    QPushButton *deleteButton_2M;
    QTextEdit *textEdit_3M;
    QPushButton *statistics_2M;
    QWidget *page_3;
    QLabel *label_4M;
    QPushButton *exportButtonM;
    QPushButton *brandsButton_2M;
    QWidget *page_4;
    QPushButton *brandsButtonM;
    QPushButton *vewatchButton_3M;
    QLineEdit *lineEditM;
    QPushButton *pushButtonM;
    QLabel *label_7M;
    QTextEdit *textEdit_4M;
    QTextEdit *textEdit_6M;
    QLabel *label_9M;
    QLabel *label_10M;
    QLabel *label_11;
    QLabel *label_12M;
    QLabel *label_13M_2;
    QLabel *label_14M;
    QWidget *page_5;
    QWidget *page;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1920, 1080);
        MainWindow->setStyleSheet(QLatin1String("#loM{\n"
"	/*border-image:url(../images/logo.png);*/\n"
"	border: 2px solid black;\n"
"    border-radius: 30px;\n"
"	color:white;\n"
"	font-size: 20px;\n"
"/*background-color:qlineargradient(spread:pad, x1:0.858, y1:0.375, x2:0, y2:0, stop:0 rgba(0, 1, 145, 255), stop:1 rgba(16, 30, 41, 200));*/\n"
"background-color:rgba(65,105,225,100);\n"
"}\n"
"QMainWindow{\n"
"background-color: black;\n"
"	\n"
"}\n"
"#vewatchM{\n"
"	border-image:url(../images/logo.png);\n"
"    color: white;\n"
"    font-family: Ms Shell Dlg; /* Famille de police */\n"
"    font-size: 16px; \n"
"    font-weight: bold;\n"
"    /*text-transform: uppercase; /* Transformation du texte en majuscules */\n"
"	padding-left: 20px;\n"
"}\n"
"#vewatch_2M{\n"
"	border-image:url(../images/logo.png);\n"
"    color: white;\n"
"    font-family: Ms Shell Dlg; /* Famille de police */\n"
"    font-size: 16px; \n"
"    font-weight: bold;\n"
"    /*text-transform: uppercase; /* Transformation du texte en majuscules */\n"
"	padding-left: 20px;\n"
"}\n"
"\n"
"#f"
                        "ormM{\n"
"border-radius:15px;\n"
"  /*background-color: rgba(16,30,41,240);*/\n"
"background-image: url(../images/form.jpg);\n"
"\n"
"}\n"
"#labelM{\n"
"background-color:qlineargradient(spread:pad, x1:0.858, y1:0.375, x2:0, y2:0, stop:0 rgba(0, 1, 145, 255), stop:1 rgba(16, 30, 41, 200));\n"
"border-top-right-radius:70px;\n"
"}\n"
"#label_2M{\n"
"background-color:qlineargradient(spread:pad, x1:0.858, y1:0.375, x2:0, y2:0, stop:0 rgba(0, 1, 145, 255), stop:1 rgba(16, 30, 41, 200));\n"
"border-top-right-radius:70px;\n"
"}\n"
"\n"
"#tv_2 M{\n"
"	border-radius: none;\n"
"    background-color: none;\n"
"	 color: white;\n"
"	\n"
"}\n"
"\n"
"#radio_2M{\n"
"	border-radius: none;\n"
"    background-color: none;\n"
"	 color: white;\n"
"	\n"
"}\n"
"#searchM{\n"
"	border-radius:10;\n"
"    background-color: rgba(0,0,0,150);\n"
"	 color: white;\n"
"	\n"
"}\n"
"#lineSearchM{\n"
"	border-radius:10;\n"
"    background-color: rgba(0,0,0,150);\n"
"	 color: white;\n"
"}\n"
"#seriesM{\n"
"	border-image:url(../images/vseries.png);"
                        "\n"
"	border: transparent;\n"
"    border-radius: 16px;\n"
"background-color:transparent}\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setStyleSheet(QStringLiteral("background-colo:white;"));
        stackedWidget->setFrameShadow(QFrame::Sunken);
        page_0 = new QWidget();
        page_0->setObjectName(QStringLiteral("page_0"));
        loM = new QPushButton(page_0);
        loM->setObjectName(QStringLiteral("loM"));
        loM->setGeometry(QRect(1520, 0, 151, 81));
        loM->setStyleSheet(QLatin1String("    #loM{color: white;\n"
"    font-family: Ms Shell Dlg;\n"
"    font-size: 20px; \n"
" \n"
"    /*text-transform: uppercase; /* Transformation du texte en majuscules */\n"
"	padding-left: 20px;\n"
"background:transparent;\n"
"border:transparent;}\n"
"#loM:hover {\n"
"   text-decoration: underline;\n"
"}\n"
"\n"
""));
        QIcon icon;
        QString iconThemeName = QStringLiteral("a");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        loM->setIcon(icon);
        seriesM = new QPushButton(page_0);
        seriesM->setObjectName(QStringLiteral("seriesM"));
        seriesM->setGeometry(QRect(50, 550, 341, 281));
        modifyButtonM = new QPushButton(page_0);
        modifyButtonM->setObjectName(QStringLiteral("modifyButtonM"));
        modifyButtonM->setGeometry(QRect(1630, 910, 61, 51));
        modifyButtonM->setStyleSheet(QLatin1String("font-size: 35px; \n"
"    font-weight: bold; \n"
"  border-radius: 10;\n"
" font-family:DRIPICONS-V2;\n"
"color:qlineargradient(spread:pad, x1:0.858, y1:0.375, x2:0, y2:0, stop:0 rgba(0, 1, 145, 255), stop:1 rgba(16, 30, 41, 200));\n"
""));
        QIcon icon1;
        iconThemeName = QStringLiteral(":");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        modifyButtonM->setIcon(icon1);
        label_3M = new QLabel(page_0);
        label_3M->setObjectName(QStringLiteral("label_3M"));
        label_3M->setGeometry(QRect(440, 550, 1261, 431));
        label_3M->setStyleSheet(QLatin1String("background-color:rgb(166,166,166);\n"
"border-radius: 20px;"));
        returnButtonM = new QPushButton(page_0);
        returnButtonM->setObjectName(QStringLiteral("returnButtonM"));
        returnButtonM->setGeometry(QRect(1620, 550, 93, 28));
        returnButtonM->setStyleSheet(QLatin1String("font-size: 35px; \n"
"    font-weight: bold; \n"
"  border-radius: 10;\n"
" font-family:DRIPICONS-V2;\n"
"color:qlineargradient(spread:pad, x1:0.858, y1:0.375, x2:0, y2:0, stop:0 rgba(0, 1, 145, 255), stop:1 rgba(16, 30, 41, 200));\n"
""));
        label_5M = new QLabel(page_0);
        label_5M->setObjectName(QStringLiteral("label_5M"));
        label_5M->setGeometry(QRect(-20, 110, 1931, 371));
        label_5M->setStyleSheet(QLatin1String("background:url(../images/vwatch.png);\n"
"border-radius:20;"));
        label_5M->setPixmap(QPixmap(QString::fromUtf8("../images/vewatch.png")));
        deleteButtonM = new QPushButton(page_0);
        deleteButtonM->setObjectName(QStringLiteral("deleteButtonM"));
        deleteButtonM->setGeometry(QRect(1590, 910, 61, 51));
        deleteButtonM->setStyleSheet(QLatin1String("font-size: 35px; \n"
"    font-weight: bold; \n"
"  border-radius: 10;\n"
" font-family:DRIPICONS-V2;\n"
"color:qlineargradient(spread:pad, x1:0.858, y1:0.375, x2:0, y2:0, stop:0 rgba(0, 1, 145, 255), stop:1 rgba(16, 30, 41, 200));\n"
""));
        trieButtonM = new QPushButton(page_0);
        trieButtonM->setObjectName(QStringLiteral("trieButtonM"));
        trieButtonM->setGeometry(QRect(1860, 30, 41, 41));
        trieButtonM->setStyleSheet(QLatin1String("font-size: 20px; \n"
"    font-weight: bold; \n"
"  border-radius: 10;\n"
" font-family:DRIPICONS-V2;\n"
"color:white;\n"
"background-color:rgb(166,166,166);"));
        barreTrieM = new QGroupBox(page_0);
        barreTrieM->setObjectName(QStringLiteral("barreTrieM"));
        barreTrieM->setGeometry(QRect(1660, 60, 241, 121));
        barreTrieM->setStyleSheet(QLatin1String("border: 2px solid none;\n"
"    border-radius: 0px;\n"
"	color:none;\n"
"	font-size: 20px;\n"
"/*background-color:qlineargradient(spread:pad, x1:0.858, y1:0.375, x2:0, y2:0, stop:0 rgba(0, 1, 145, 255), stop:1 rgba(16, 30, 41, 200));*/\n"
"background-color:rgb(166,166,166);"));
        label_2M = new QLabel(barreTrieM);
        label_2M->setObjectName(QStringLiteral("label_2M"));
        label_2M->setGeometry(QRect(-20, 10, 121, 20));
        label_2M->setStyleSheet(QLatin1String("\n"
"    color: white;\n"
"    font-family: Ms Shell Dlg; \n"
"    font-size: 16px; \n"
"    font-weight: none;\n"
"	padding-left: 20px;\n"
"    border-color:transparent;"));
        label_8M = new QLabel(barreTrieM);
        label_8M->setObjectName(QStringLiteral("label_8M"));
        label_8M->setGeometry(QRect(-10, 40, 71, 16));
        label_8M->setStyleSheet(QLatin1String("\n"
"    color: white;\n"
"    font-family: Ms Shell Dlg; \n"
"    font-size: 16px; \n"
"    font-weight: none;\n"
"	padding-left: 20px;\n"
"    border-color:transparent;"));
        vewatchButtonM = new QPushButton(page_0);
        vewatchButtonM->setObjectName(QStringLiteral("vewatchButtonM"));
        vewatchButtonM->setGeometry(QRect(-10, -10, 221, 121));
        vewatchButtonM->setStyleSheet(QLatin1String("\n"
"	border-image:url(../images/logo.png);\n"
"    color: white;\n"
"    font-family: Ms Shell Dlg; /* Famille de police */\n"
"    font-size: 16px; \n"
"    font-weight: bold;\n"
"    /*text-transform: uppercase; /* Transformation du texte en majuscules */\n"
"	padding-left: 20px;"));
        tvM = new QPushButton(page_0);
        tvM->setObjectName(QStringLiteral("tvM"));
        tvM->setGeometry(QRect(710, 20, 241, 51));
        tvM->setStyleSheet(QLatin1String("    color: blue;\n"
"    font-family: Ms Shell Dlg;\n"
"    font-size: 20px; \n"
" \n"
"    /*text-transform: uppercase; /* Transformation du texte en majuscules */\n"
"	padding-left: 20px;\n"
"background:transparent;\n"
"border:transparent;\n"
""));
        radioM = new QPushButton(page_0);
        radioM->setObjectName(QStringLiteral("radioM"));
        radioM->setGeometry(QRect(920, 20, 181, 51));
        radioM->setStyleSheet(QLatin1String("    #radioM{color: white;\n"
"    font-family: Ms Shell Dlg;\n"
"    font-size: 20px; \n"
" \n"
"    /*text-transform: uppercase; /* Transformation du texte en majuscules */\n"
"	padding-left: 20px;\n"
"background:transparent;\n"
"border:transparent;}\n"
"#radioM:hover {\n"
"   text-decoration: underline;\n"
"}\n"
"\n"
""));
        labelM = new QLabel(page_0);
        labelM->setObjectName(QStringLiteral("labelM"));
        labelM->setGeometry(QRect(1740, 30, 91, 31));
        labelM->setStyleSheet(QLatin1String("    color: white;\n"
"    font-family: Ms Shell Dlg;\n"
"    font-size: 20px; \n"
" \n"
"    /*text-transform: uppercase; /* Transformation du texte en majuscules */\n"
"	padding-left: 20px;\n"
"background:transparent;\n"
"border:transparent;\n"
""));
        label_16M = new QLabel(page_0);
        label_16M->setObjectName(QStringLiteral("label_16M"));
        label_16M->setGeometry(QRect(-10, 490, 171, 51));
        label_16M->setStyleSheet(QLatin1String("    color: white;\n"
"    font-family: Ms Shell Dlg;\n"
"    font-size: 20px; \n"
" \n"
"    /*text-transform: uppercase; /* Transformation du texte en majuscules */\n"
"	padding-left: 20px;\n"
"background:transparent;\n"
"border:transparent;\n"
""));
        textEdit_2M = new QTextEdit(page_0);
        textEdit_2M->setObjectName(QStringLiteral("textEdit_2M"));
        textEdit_2M->setGeometry(QRect(10, 140, 411, 211));
        textEdit_2M->setStyleSheet(QLatin1String("background:transparent;\n"
"color:white;\n"
"border:transparent;"));
        series_2M = new QPushButton(page_0);
        series_2M->setObjectName(QStringLiteral("series_2M"));
        series_2M->setGeometry(QRect(460, 530, 341, 281));
        series_2M->setStyleSheet(QLatin1String("	border-image:url(../images/vactions.png);\n"
"	border: transparent;\n"
"    border-radius: 16px;\n"
"background-color:transparent"));
        statisticsM = new QPushButton(page_0);
        statisticsM->setObjectName(QStringLiteral("statisticsM"));
        statisticsM->setGeometry(QRect(1430, 0, 151, 81));
        statisticsM->setStyleSheet(QLatin1String("    #statisticsM{color: white;\n"
"    font-family: Ms Shell Dlg;\n"
"    font-size: 20px; \n"
" \n"
"    /*text-transform: uppercase; /* Transformation du texte en majuscules */\n"
"	padding-left: 20px;\n"
"background:transparent;\n"
"border:transparent;}\n"
"#statisticsM:hover {\n"
"   text-decoration: underline;\n"
"}\n"
"\n"
""));
        statisticsM->setIcon(icon);
        stackedWidget->addWidget(page_0);
        label_5M->raise();
        label_3M->raise();
        returnButtonM->raise();
        loM->raise();
        seriesM->raise();
        modifyButtonM->raise();
        deleteButtonM->raise();
        trieButtonM->raise();
        barreTrieM->raise();
        vewatchButtonM->raise();
        tvM->raise();
        radioM->raise();
        labelM->raise();
        label_16M->raise();
        textEdit_2M->raise();
        series_2M->raise();
        statisticsM->raise();
        page_1 = new QWidget();
        page_1->setObjectName(QStringLiteral("page_1"));
        page_1->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:pad, x1:0.426227, y1:0, x2:0.625, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(49, 21, 78, 255));"));
        vewatch_2M = new QPushButton(page_1);
        vewatch_2M->setObjectName(QStringLiteral("vewatch_2M"));
        vewatch_2M->setGeometry(QRect(0, 0, 221, 141));
        vewatch_2M->setStyleSheet(QLatin1String("border-image:url(../images/logo.png);\n"
"    color: white;\n"
"    font-family: Ms Shell Dlg; /* Famille de police */\n"
"    font-size: 16px; \n"
"    font-weight: bold;\n"
"    /*text-transform: uppercase; /* Transformation du texte en majuscules */\n"
"	padding-left: 20px;\n"
"background-color:transparent;"));
        label_13M = new QLabel(page_1);
        label_13M->setObjectName(QStringLiteral("label_13M"));
        label_13M->setGeometry(QRect(910, 170, 611, 781));
        label_13M->setStyleSheet(QLatin1String("  border: 10px solid white;\n"
"border-radius:50px;\n"
"border-color:white;\n"
"background-color:white;"));
        formM = new QLabel(page_1);
        formM->setObjectName(QStringLiteral("formM"));
        formM->setGeometry(QRect(490, 170, 511, 781));
        formM->setContextMenuPolicy(Qt::NoContextMenu);
        formM->setStyleSheet(QLatin1String("\n"
"\n"
"border-radius:50px;\n"
"border-color:white;\n"
"background-color:white;\n"
"\n"
""));
        formM->setScaledContents(true);
        ProducerM = new QLineEdit(page_1);
        ProducerM->setObjectName(QStringLiteral("ProducerM"));
        ProducerM->setGeometry(QRect(1050, 380, 391, 31));
        ProducerM->setStyleSheet(QLatin1String("\n"
" font-family: Ms Shell Dlg;\n"
"color:black;\n"
"\n"
"                     font-size: 15px; \n"
"                     font-weight: bold; \n"
"                     \n"
"                     background-color: transparent;\n"
"                     color: black;\n"
"                     border: 1px solid black;\n"
"border-radius:none;\n"
""));
        imageButtonM = new QPushButton(page_1);
        imageButtonM->setObjectName(QStringLiteral("imageButtonM"));
        imageButtonM->setGeometry(QRect(1030, 720, 101, 91));
        imageButtonM->setStyleSheet(QLatin1String("\n"
"                     font-size: 35px; \n"
"                     font-weight: bold; \n"
"                     font-family: DRIPICONS-V2;\n"
"                     background-color: transparent;\n"
"                     color: black;\n"
"                     border: 1px solid black;\n"
"border-radius:20px;\n"
"\n"
""));
        TitleM = new QLineEdit(page_1);
        TitleM->setObjectName(QStringLiteral("TitleM"));
        TitleM->setGeometry(QRect(1050, 320, 391, 31));
        TitleM->setStyleSheet(QLatin1String("\n"
" font-family: Ms Shell Dlg;\n"
"color:black;\n"
"\n"
"                     font-size: 15px; \n"
"                     font-weight: bold; \n"
"                     \n"
"                     background-color: transparent;\n"
"                     \n"
"                     border: 1px solid black;\n"
"border-color:black;\n"
"\n"
"border-radius:none;\n"
""));
        textEditM = new QTextEdit(page_1);
        textEditM->setObjectName(QStringLiteral("textEditM"));
        textEditM->setGeometry(QRect(1050, 430, 391, 261));
        textEditM->setStyleSheet(QLatin1String("\n"
" font-family: Ms Shell Dlg;\n"
"color:black;\n"
"\n"
"                     font-size: 15px; \n"
"                     font-weight: bold; \n"
"                     \n"
"                     background-color: transparent;\n"
"                     color: black;\n"
"                     border: 1px solid black;\n"
"border-radius:0;\n"
"\n"
""));
        addButtonM = new QPushButton(page_1);
        addButtonM->setObjectName(QStringLiteral("addButtonM"));
        addButtonM->setGeometry(QRect(1140, 860, 221, 71));
        addButtonM->setStyleSheet(QLatin1String("#addButtonM {\n"
"    font-family: \"Ms Shell Dlg\";\n"
"    font-size: 35px; \n"
"    font-weight: bold; \n"
"    background-color: black;\n"
"    color: white;\n"
"    border: 1px solid black;\n"
"    border-radius: 20px;\n"
"}\n"
"\n"
"#addButtonM:hover {\n"
"    background-color: #03224c ;\n"
"}\n"
""));
        addChannelM = new QLabel(page_1);
        addChannelM->setObjectName(QStringLiteral("addChannelM"));
        addChannelM->setGeometry(QRect(1170, 200, 301, 71));
        addChannelM->setStyleSheet(QLatin1String("  color: black;\n"
"    font-family: Ms Shell Dlg;\n"
"    font-size: 16px; \n"
"    font-weight: bold;\n"
"    /*text-transform: uppercase; /* Transformation du texte en majuscules */\n"
"	padding-left: 20px;\n"
"font-size:30px;\n"
"background-color:none;"));
        radioButtonM = new QRadioButton(page_1);
        radioButtonM->setObjectName(QStringLiteral("radioButtonM"));
        radioButtonM->setGeometry(QRect(1180, 750, 97, 20));
        radioButtonM->setStyleSheet(QLatin1String(" background-color: transparent;\n"
"    border: none;"));
        radioButton_2M = new QRadioButton(page_1);
        radioButton_2M->setObjectName(QStringLiteral("radioButton_2M"));
        radioButton_2M->setGeometry(QRect(1300, 750, 97, 20));
        radioButton_2M->setStyleSheet(QLatin1String(" background-color: transparent;\n"
"    border: none;"));
        textEdit_5M = new QTextEdit(page_1);
        textEdit_5M->setObjectName(QStringLiteral("textEdit_5M"));
        textEdit_5M->setGeometry(QRect(510, 400, 571, 481));
        textEdit_5M->setStyleSheet(QLatin1String(" background-color: transparent;\n"
"    border: none;\n"
"   font-family: CONSOLA;\n"
"font-size:50px\n"
" \n"
"\n"
""));
        stackedWidget->addWidget(page_1);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        radio_2M = new QPushButton(page_2);
        radio_2M->setObjectName(QStringLiteral("radio_2M"));
        radio_2M->setGeometry(QRect(930, 20, 181, 51));
        radio_2M->setStyleSheet(QLatin1String("    color: blue;\n"
"    font-family: Ms Shell Dlg;\n"
"    font-size: 20px; \n"
" \n"
"    /*text-transform: uppercase; /* Transformation du texte en majuscules */\n"
"	padding-left: 20px;\n"
"background:transparent;\n"
"border:transparent;"));
        modifyButton_2M = new QPushButton(page_2);
        modifyButton_2M->setObjectName(QStringLiteral("modifyButton_2M"));
        modifyButton_2M->setGeometry(QRect(1560, 930, 71, 51));
        modifyButton_2M->setStyleSheet(QLatin1String("font-size: 35px; \n"
"    font-weight: bold; \n"
"  border-radius: 10;\n"
" font-family:DRIPICONS-V2;\n"
"color:qlineargradient(spread:pad, x1:0.858, y1:0.375, x2:0, y2:0, stop:0 rgba(0, 1, 145, 255), stop:1 rgba(16, 30, 41, 200));"));
        add_2M = new QPushButton(page_2);
        add_2M->setObjectName(QStringLiteral("add_2M"));
        add_2M->setGeometry(QRect(1540, -10, 101, 111));
        add_2M->setStyleSheet(QLatin1String("    #add_2M{color: white;\n"
"    font-family: Ms Shell Dlg;\n"
"    font-size: 20px; \n"
" \n"
"    /*text-transform: uppercase; /* Transformation du texte en majuscules */\n"
"	padding-left: 20px;\n"
"background:transparent;\n"
"border:transparent;}\n"
"#add_2M:hover {\n"
"   text-decoration: underline;\n"
"}\n"
"\n"
""));
        add_2M->setIcon(icon);
        vwatchRadioM = new QPushButton(page_2);
        vwatchRadioM->setObjectName(QStringLiteral("vwatchRadioM"));
        vwatchRadioM->setGeometry(QRect(10, 560, 341, 281));
        vwatchRadioM->setStyleSheet(QLatin1String("border-image:url(../images/vRadio.png);\n"
"	border: 2px solid black;\n"
"    border-radius: 16px;\n"
"background-color:qlineargradient(spread:pad, x1:0.858, y1:0.375, x2:0, y2:0, stop:0 rgba(0, 1, 145, 255), stop:1 rgba(16, 30, 41, 200));"));
        descriptionRM = new QLabel(page_2);
        descriptionRM->setObjectName(QStringLiteral("descriptionRM"));
        descriptionRM->setGeometry(QRect(440, 570, 1201, 411));
        descriptionRM->setStyleSheet(QLatin1String("background-color:white;\n"
"border-radius: 20px;"));
        returnButton_2M = new QPushButton(page_2);
        returnButton_2M->setObjectName(QStringLiteral("returnButton_2M"));
        returnButton_2M->setGeometry(QRect(1550, 580, 93, 28));
        returnButton_2M->setStyleSheet(QLatin1String("font-size: 35px; \n"
"    font-weight: bold; \n"
"  border-radius: 10;\n"
" font-family:DRIPICONS-V2;\n"
"color:qlineargradient(spread:pad, x1:0.858, y1:0.375, x2:0, y2:0, stop:0 rgba(0, 1, 145, 255), stop:1 rgba(16, 30, 41, 200));\n"
""));
        label_6M = new QLabel(page_2);
        label_6M->setObjectName(QStringLiteral("label_6M"));
        label_6M->setGeometry(QRect(-30, 110, 1931, 371));
        label_6M->setStyleSheet(QLatin1String("background:url(../images/vwatch.png);\n"
"border-radius:20;"));
        label_6M->setPixmap(QPixmap(QString::fromUtf8("../images/vewatch.png")));
        tv_2M = new QPushButton(page_2);
        tv_2M->setObjectName(QStringLiteral("tv_2M"));
        tv_2M->setGeometry(QRect(710, 20, 241, 51));
        tv_2M->setStyleSheet(QLatin1String("    #tv_2M{color: white;\n"
"    font-family: Ms Shell Dlg;\n"
"    font-size: 20px; \n"
" \n"
"    /*text-transform: uppercase; /* Transformation du texte en majuscules */\n"
"	padding-left: 20px;\n"
"background:transparent;\n"
"border:transparent;}\n"
"#tv_2M:hover {\n"
"   text-decoration: underline;\n"
"}\n"
"\n"
""));
        vewatchButton_2M = new QPushButton(page_2);
        vewatchButton_2M->setObjectName(QStringLiteral("vewatchButton_2M"));
        vewatchButton_2M->setGeometry(QRect(-20, -10, 221, 121));
        vewatchButton_2M->setStyleSheet(QLatin1String("\n"
"	border-image:url(../images/logo.png);\n"
"    color: white;\n"
"    font-family: Ms Shell Dlg; /* Famille de police */\n"
"    font-size: 16px; \n"
"    font-weight: bold;\n"
"    /*text-transform: uppercase; /* Transformation du texte en majuscules */\n"
"	padding-left: 20px;"));
        label_17M = new QLabel(page_2);
        label_17M->setObjectName(QStringLiteral("label_17M"));
        label_17M->setGeometry(QRect(1730, 30, 91, 31));
        label_17M->setStyleSheet(QLatin1String("    color: white;\n"
"    font-family: Ms Shell Dlg;\n"
"    font-size: 20px; \n"
" \n"
"    /*text-transform: uppercase; /* Transformation du texte en majuscules */\n"
"	padding-left: 20px;\n"
"background:transparent;\n"
"border:transparent;\n"
""));
        barreTrie_2M = new QGroupBox(page_2);
        barreTrie_2M->setObjectName(QStringLiteral("barreTrie_2M"));
        barreTrie_2M->setGeometry(QRect(1650, 60, 241, 121));
        barreTrie_2M->setStyleSheet(QLatin1String("border: 2px solid none;\n"
"    border-radius: 0px;\n"
"	color:none;\n"
"	font-size: 20px;\n"
"/*background-color:qlineargradient(spread:pad, x1:0.858, y1:0.375, x2:0, y2:0, stop:0 rgba(0, 1, 145, 255), stop:1 rgba(16, 30, 41, 200));*/\n"
"background-color:rgb(166,166,166);"));
        label_18M = new QLabel(barreTrie_2M);
        label_18M->setObjectName(QStringLiteral("label_18M"));
        label_18M->setGeometry(QRect(-20, 10, 121, 20));
        label_18M->setStyleSheet(QLatin1String("\n"
"    color: white;\n"
"    font-family: Ms Shell Dlg; \n"
"    font-size: 16px; \n"
"    font-weight: none;\n"
"	padding-left: 20px;\n"
"    border-color:transparent;"));
        label_19M = new QLabel(barreTrie_2M);
        label_19M->setObjectName(QStringLiteral("label_19M"));
        label_19M->setGeometry(QRect(-10, 40, 71, 16));
        label_19M->setStyleSheet(QLatin1String("\n"
"    color: white;\n"
"    font-family: Ms Shell Dlg; \n"
"    font-size: 16px; \n"
"    font-weight: none;\n"
"	padding-left: 20px;\n"
"    border-color:transparent;"));
        trieButton_2M = new QPushButton(page_2);
        trieButton_2M->setObjectName(QStringLiteral("trieButton_2M"));
        trieButton_2M->setGeometry(QRect(1850, 30, 41, 41));
        trieButton_2M->setStyleSheet(QLatin1String("font-size: 20px; \n"
"    font-weight: bold; \n"
"  border-radius: 10;\n"
" font-family:DRIPICONS-V2;\n"
"color:white;\n"
"background-color:rgb(166,166,166);"));
        label_20M = new QLabel(page_2);
        label_20M->setObjectName(QStringLiteral("label_20M"));
        label_20M->setGeometry(QRect(-20, 490, 171, 51));
        label_20M->setStyleSheet(QLatin1String("    color: white;\n"
"    font-family: Ms Shell Dlg;\n"
"    font-size: 20px; \n"
" \n"
"    /*text-transform: uppercase; /* Transformation du texte en majuscules */\n"
"	padding-left: 20px;\n"
"background:transparent;\n"
"border:transparent;\n"
""));
        deleteButton_2M = new QPushButton(page_2);
        deleteButton_2M->setObjectName(QStringLiteral("deleteButton_2M"));
        deleteButton_2M->setGeometry(QRect(1530, 930, 51, 51));
        deleteButton_2M->setStyleSheet(QLatin1String("font-size: 35px; \n"
"    font-weight: bold; \n"
"  border-radius: 10;\n"
" font-family:DRIPICONS-V2;\n"
"color:qlineargradient(spread:pad, x1:0.858, y1:0.375, x2:0, y2:0, stop:0 rgba(0, 1, 145, 255), stop:1 rgba(16, 30, 41, 200));"));
        textEdit_3M = new QTextEdit(page_2);
        textEdit_3M->setObjectName(QStringLiteral("textEdit_3M"));
        textEdit_3M->setGeometry(QRect(10, 150, 411, 211));
        textEdit_3M->setStyleSheet(QLatin1String("background:transparent;\n"
"color:white;\n"
"border:transparent;"));
        statistics_2M = new QPushButton(page_2);
        statistics_2M->setObjectName(QStringLiteral("statistics_2M"));
        statistics_2M->setGeometry(QRect(1470, -10, 101, 111));
        statistics_2M->setStyleSheet(QLatin1String("    #statistics_2M{color: white;\n"
"    font-family: Ms Shell Dlg;\n"
"    font-size: 20px; \n"
" \n"
"    /*text-transform: uppercase; /* Transformation du texte en majuscules */\n"
"	padding-left: 20px;\n"
"background:transparent;\n"
"border:transparent;}\n"
"#statistics_2M:hover {\n"
"   text-decoration: underline;\n"
"}\n"
"\n"
""));
        statistics_2M->setIcon(icon);
        stackedWidget->addWidget(page_2);
        descriptionRM->raise();
        radio_2M->raise();
        modifyButton_2M->raise();
        add_2M->raise();
        vwatchRadioM->raise();
        returnButton_2M->raise();
        label_6M->raise();
        tv_2M->raise();
        vewatchButton_2M->raise();
        label_17M->raise();
        barreTrie_2M->raise();
        trieButton_2M->raise();
        label_20M->raise();
        deleteButton_2M->raise();
        textEdit_3M->raise();
        statistics_2M->raise();
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        label_4M = new QLabel(page_3);
        label_4M->setObjectName(QStringLiteral("label_4M"));
        label_4M->setGeometry(QRect(0, -10, 381, 71));
        label_4M->setStyleSheet(QLatin1String("border-radius: none;\n"
"    background-color: none;\n"
"	 color: white;\n"
"font-family:ARIALNOVA-LIGHT;\n"
"font-size:50px;"));
        exportButtonM = new QPushButton(page_3);
        exportButtonM->setObjectName(QStringLiteral("exportButtonM"));
        exportButtonM->setGeometry(QRect(10, 920, 71, 51));
        exportButtonM->setStyleSheet(QLatin1String("font-size: 35px; \n"
"    font-weight: bold; \n"
"  border-radius: 10;\n"
" font-family:DRIPICONS-V2;\n"
"background-color:qlineargradient(spread:pad, x1:0.858, y1:0.375, x2:0, y2:0, stop:0 rgba(0, 1, 145, 255), stop:1 rgba(16, 30, 41, 200));\n"
"color:white"));
        QIcon icon2;
        iconThemeName = QStringLiteral("test");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon2 = QIcon::fromTheme(iconThemeName);
        } else {
            icon2.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        exportButtonM->setIcon(icon2);
        brandsButton_2M = new QPushButton(page_3);
        brandsButton_2M->setObjectName(QStringLiteral("brandsButton_2M"));
        brandsButton_2M->setGeometry(QRect(1680, 0, 241, 51));
        brandsButton_2M->setStyleSheet(QLatin1String("    #brandsButton_2M{color: white;\n"
"    font-family: Ms Shell Dlg;\n"
"    font-size: 20px; \n"
" \n"
"    /*text-transform: uppercase; /* Transformation du texte en majuscules */\n"
"	padding-left: 20px;\n"
"background:transparent;\n"
"border:transparent;}\n"
"#brandsButton_2M:hover {\n"
"   text-decoration: underline;\n"
"}\n"
"\n"
""));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        page_4->setStyleSheet(QStringLiteral(""));
        brandsButtonM = new QPushButton(page_4);
        brandsButtonM->setObjectName(QStringLiteral("brandsButtonM"));
        brandsButtonM->setGeometry(QRect(720, 30, 241, 51));
        brandsButtonM->setStyleSheet(QLatin1String("    #brandsButtonM{color: white;\n"
"    font-family: Ms Shell Dlg;\n"
"    font-size: 20px; \n"
" \n"
"    /*text-transform: uppercase; /* Transformation du texte en majuscules */\n"
"	padding-left: 20px;\n"
"background:transparent;\n"
"border:transparent;}\n"
"#brandsButtonM:hover {\n"
"   text-decoration: underline;\n"
"}\n"
"\n"
""));
        vewatchButton_3M = new QPushButton(page_4);
        vewatchButton_3M->setObjectName(QStringLiteral("vewatchButton_3M"));
        vewatchButton_3M->setGeometry(QRect(0, 0, 221, 121));
        vewatchButton_3M->setStyleSheet(QLatin1String("\n"
"	border-image:url(../images/logo.png);\n"
"    color: white;\n"
"    font-family: Ms Shell Dlg; /* Famille de police */\n"
"    font-size: 16px; \n"
"    font-weight: bold;\n"
"    /*text-transform: uppercase; /* Transformation du texte en majuscules */\n"
"	padding-left: 20px;"));
        lineEditM = new QLineEdit(page_4);
        lineEditM->setObjectName(QStringLiteral("lineEditM"));
        lineEditM->setGeometry(QRect(1580, 40, 271, 31));
        lineEditM->setStyleSheet(QString::fromUtf8(" font-size: 10px; /* Taille de la police */\n"
"    font-weight: bold; /* Gras */\n"
"    font-family:Ms Shell Dlg; /* Police de caract\303\250res */\n"
"    padding: 8px 12px; /* Espacement int\303\251rieur */\n"
"    border: 2px solid blue; /* Bordure */\n"
"    border-radius: 4px; /* Arrondi des coins */\n"
"    background-color: transparent; /* Couleur de fond */\n"
"    color: white; /* Couleur du texte */\n"
"    cursor: pointer; /* Curseur de souris */"));
        pushButtonM = new QPushButton(page_4);
        pushButtonM->setObjectName(QStringLiteral("pushButtonM"));
        pushButtonM->setGeometry(QRect(1810, 40, 41, 31));
        pushButtonM->setStyleSheet(QString::fromUtf8(" font-size: 35px; /* Taille de la police */\n"
"    font-weight: bold; /* Gras */\n"
"    font-family: DRIPICONS-V2; /* Police de caract\303\250res */\n"
"    padding: 8px 12px; /* Espacement int\303\251rieur */\n"
"    border: 2px solid blue; /* Bordure */\n"
"    border-radius: 4px; /* Arrondi des coins */\n"
"    background-color: none; /* Couleur de fond */\n"
"    color: white; /* Couleur du texte */\n"
"    cursor: pointer; /* Curseur de souris */"));
        label_7M = new QLabel(page_4);
        label_7M->setObjectName(QStringLiteral("label_7M"));
        label_7M->setGeometry(QRect(-70, 120, 1951, 271));
        label_7M->setStyleSheet(QStringLiteral("background:url(../images/homeMedia.png)"));
        textEdit_4M = new QTextEdit(page_4);
        textEdit_4M->setObjectName(QStringLiteral("textEdit_4M"));
        textEdit_4M->setGeometry(QRect(10, 250, 391, 211));
        textEdit_4M->setStyleSheet(QLatin1String("background:transparent;\n"
"color:white;\n"
"border:transparent;"));
        textEdit_6M = new QTextEdit(page_4);
        textEdit_6M->setObjectName(QStringLiteral("textEdit_6M"));
        textEdit_6M->setGeometry(QRect(670, 410, 491, 211));
        textEdit_6M->setStyleSheet(QLatin1String("background:transparent;\n"
"color:purple;\n"
"border:transparent;"));
        label_9M = new QLabel(page_4);
        label_9M->setObjectName(QStringLiteral("label_9M"));
        label_9M->setGeometry(QRect(30, 590, 281, 371));
        label_9M->setStyleSheet(QStringLiteral("background-color:white;"));
        label_10M = new QLabel(page_4);
        label_10M->setObjectName(QStringLiteral("label_10M"));
        label_10M->setGeometry(QRect(380, 590, 281, 371));
        label_10M->setStyleSheet(QStringLiteral("background-color:white;"));
        label_11 = new QLabel(page_4);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(740, 940, 281, 371));
        label_12M = new QLabel(page_4);
        label_12M->setObjectName(QStringLiteral("label_12M"));
        label_12M->setGeometry(QRect(780, 590, 271, 381));
        label_12M->setStyleSheet(QLatin1String("background-color:white;\n"
""));
        label_13M_2 = new QLabel(page_4);
        label_13M_2->setObjectName(QStringLiteral("label_13M_2"));
        label_13M_2->setGeometry(QRect(1210, 590, 281, 371));
        label_13M_2->setStyleSheet(QStringLiteral("background-color:white;"));
        label_14M = new QLabel(page_4);
        label_14M->setObjectName(QStringLiteral("label_14M"));
        label_14M->setGeometry(QRect(1580, 590, 281, 371));
        label_14M->setStyleSheet(QStringLiteral("background-color:white;"));
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        stackedWidget->addWidget(page_5);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        stackedWidget->addWidget(page);

        horizontalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1920, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        loM->setText(QApplication::translate("MainWindow", "Add", Q_NULLPTR));
        seriesM->setText(QString());
        modifyButtonM->setText(QApplication::translate("MainWindow", "*", Q_NULLPTR));
        label_3M->setText(QString());
        returnButtonM->setText(QApplication::translate("MainWindow", "9", Q_NULLPTR));
        label_5M->setText(QString());
        deleteButtonM->setText(QApplication::translate("MainWindow", ")", Q_NULLPTR));
        trieButtonM->setText(QApplication::translate("MainWindow", "T", Q_NULLPTR));
        barreTrieM->setTitle(QString());
        label_2M->setText(QApplication::translate("MainWindow", "Most view", Q_NULLPTR));
        label_8M->setText(QApplication::translate("MainWindow", "A/Z", Q_NULLPTR));
        vewatchButtonM->setText(QString());
        tvM->setText(QApplication::translate("MainWindow", " Channels TV", Q_NULLPTR));
        radioM->setText(QApplication::translate("MainWindow", " Radio", Q_NULLPTR));
        labelM->setText(QApplication::translate("MainWindow", "sort by:", Q_NULLPTR));
        label_16M->setText(QApplication::translate("MainWindow", "Brands:", Q_NULLPTR));
        textEdit_2M->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:16pt; font-weight:600;\">We see hope</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:16pt; font-weight:600;\">         everywhere</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:10pt;\">Welcome to VWATCH GROUP - th"
                        "e largest and leadind media company in the north of Africa.</span></p></body></html>", Q_NULLPTR));
        series_2M->setText(QString());
        statisticsM->setText(QApplication::translate("MainWindow", "statistics", Q_NULLPTR));
        vewatch_2M->setText(QString());
        label_13M->setText(QString());
        formM->setText(QString());
        ProducerM->setText(QString());
        ProducerM->setPlaceholderText(QApplication::translate("MainWindow", "Producer", Q_NULLPTR));
        imageButtonM->setText(QApplication::translate("MainWindow", ":", Q_NULLPTR));
        TitleM->setText(QString());
        TitleM->setPlaceholderText(QApplication::translate("MainWindow", "Title", Q_NULLPTR));
        textEditM->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ms Shell Dlg'; font-size:15px; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400;\"><br /></p></body></html>", Q_NULLPTR));
        textEditM->setPlaceholderText(QApplication::translate("MainWindow", "Description", Q_NULLPTR));
        addButtonM->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        addChannelM->setText(QApplication::translate("MainWindow", "Media", Q_NULLPTR));
        radioButtonM->setText(QApplication::translate("MainWindow", "Radio", Q_NULLPTR));
        radioButton_2M->setText(QApplication::translate("MainWindow", "Channel", Q_NULLPTR));
        textEdit_5M->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'CONSOLA'; font-size:50px; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:26pt; font-weight:600; color:#ffffff;\">CREAT YOUR </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:26pt; font-weight:600; color:#ffffff;\"> </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:26pt; font-weight:600; color:#ffffff;\""
                        ">       OWN CHANNEL</span></p></body></html>", Q_NULLPTR));
        radio_2M->setText(QApplication::translate("MainWindow", "Radio", Q_NULLPTR));
        modifyButton_2M->setText(QApplication::translate("MainWindow", "*", Q_NULLPTR));
        add_2M->setText(QApplication::translate("MainWindow", "Add", Q_NULLPTR));
        vwatchRadioM->setText(QString());
        descriptionRM->setText(QString());
        returnButton_2M->setText(QApplication::translate("MainWindow", "9", Q_NULLPTR));
        label_6M->setText(QString());
        tv_2M->setText(QApplication::translate("MainWindow", " Channels TV", Q_NULLPTR));
        vewatchButton_2M->setText(QString());
        label_17M->setText(QApplication::translate("MainWindow", "sort by:", Q_NULLPTR));
        barreTrie_2M->setTitle(QString());
        label_18M->setText(QApplication::translate("MainWindow", "Most view", Q_NULLPTR));
        label_19M->setText(QApplication::translate("MainWindow", "A/Z", Q_NULLPTR));
        trieButton_2M->setText(QApplication::translate("MainWindow", "T", Q_NULLPTR));
        label_20M->setText(QApplication::translate("MainWindow", "Brands:", Q_NULLPTR));
        deleteButton_2M->setText(QApplication::translate("MainWindow", ")", Q_NULLPTR));
        textEdit_3M->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:16pt; font-weight:600;\">We see hope</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:16pt; font-weight:600;\">         everywhere</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:10pt;\">Welcome to VWATCH GROUP - th"
                        "e largest and leadind media company in the north of Africa.</span></p></body></html>", Q_NULLPTR));
        statistics_2M->setText(QApplication::translate("MainWindow", "statistics", Q_NULLPTR));
        label_4M->setText(QApplication::translate("MainWindow", "Statistics:", Q_NULLPTR));
        exportButtonM->setText(QApplication::translate("MainWindow", "=", Q_NULLPTR));
        brandsButton_2M->setText(QApplication::translate("MainWindow", "Brands", Q_NULLPTR));
        brandsButtonM->setText(QApplication::translate("MainWindow", "Brands", Q_NULLPTR));
        vewatchButton_3M->setText(QString());
        lineEditM->setText(QString());
        lineEditM->setPlaceholderText(QApplication::translate("MainWindow", "Search", Q_NULLPTR));
        pushButtonM->setText(QApplication::translate("MainWindow", "\302\244", Q_NULLPTR));
        label_7M->setText(QString());
        textEdit_4M->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:12pt; font-weight:600;\">congratulation for our employees </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:12pt; font-weight:600;\">           of the month</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:12pt;\""
                        "><br /></p></body></html>", Q_NULLPTR));
        textEdit_6M->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:18pt; font-weight:600;\">Our channels in direct broadcast</span></p></body></html>", Q_NULLPTR));
        label_9M->setText(QString());
        label_10M->setText(QString());
        label_11->setText(QString());
        label_12M->setText(QString());
        label_13M_2->setText(QString());
        label_14M->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
