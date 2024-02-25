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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_11;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QHBoxLayout *horizontalLayout_16;
    QGroupBox *groupBox_12ms;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_15;
    QLineEdit *lineEditms;
    QPushButton *pushButtonms;
    QGroupBox *groupBoxmsms;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_13ms;
    QHBoxLayout *horizontalLayout;
    QLabel *labelms;
    QComboBox *comboBoxms;
    QGroupBox *groupBox_3ms;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_2ms;
    QPushButton *pushButton_12ms;
    QGroupBox *groupBox_4ms;
    QHBoxLayout *horizontalLayout_14;
    QGroupBox *groupBox_2ms;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_10ms;
    QPushButton *pushButton_6ms;
    QPushButton *pushButton_7ms;
    QPushButton *pushButton_8ms;
    QPushButton *pushButton_9ms;
    QGroupBox *groupBox_7ms;
    QVBoxLayout *verticalLayout_5;
    QTableView *tableViewms;
    QWidget *page_2;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_5ms;
    QHBoxLayout *horizontalLayout_10;
    QGroupBox *groupBox_8ms;
    QVBoxLayout *verticalLayout_7;
    QPushButton *pushButton_4ms;
    QPushButton *pushButton_11ms;
    QGroupBox *groupBox_6ms;
    QHBoxLayout *horizontalLayout_9;
    QGroupBox *groupBoxms;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5ms;
    QComboBox *comboBoxms_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6ms;
    QTextEdit *textEditms;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7ms;
    QLineEdit *lineEdit_2ms;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_8ms;
    QPushButton *pushButton_3ms;
    QVBoxLayout *verticalLayout_2;
    QLabel *imagetestms_2;
    QLabel *imagetestms;
    QWidget *page_4;
    QGroupBox *groupBox_20ms;
    QHBoxLayout *horizontalLayout_17;
    QGroupBox *groupBox_23ms;
    QVBoxLayout *verticalLayout_8;
    QPushButton *returnupms;
    QPushButton *confirmupms;
    QGroupBox *groupBox_21ms;
    QHBoxLayout *horizontalLayout_18;
    QGroupBox *groupBox_22ms;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_19;
    QLabel *ipidlabelms;
    QLineEdit *upidms;
    QHBoxLayout *horizontalLayout_20;
    QLabel *updescms;
    QTextEdit *updescriptionms;
    QHBoxLayout *horizontalLayout_21;
    QLabel *uptitlms;
    QLineEdit *uptitlems;
    QHBoxLayout *horizontalLayout_22;
    QLabel *upimgms;
    QPushButton *upimagems;
    QVBoxLayout *verticalLayout_10;
    QLabel *imagetest_1ms;
    QLabel *imagetest_2ms;
    QWidget *page_3;
    QHBoxLayout *horizontalLayout_11;
    QGroupBox *groupBox_9ms;
    QHBoxLayout *horizontalLayout_13;
    QGroupBox *groupBox_11ms;
    QVBoxLayout *verticalLayout_6;
    QPushButton *pp2ms;
    QPushButton *pushButton_5ms;
    QGroupBox *groupBox_10ms;
    QFormLayout *formLayout;
    QLabel *label_11ms;
    QLineEdit *lineEdit_3ms;
    QLabel *label_10ms;
    QTextEdit *textEdit_2ms;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1920, 1080);
        MainWindow->setMaximumSize(QSize(1920, 1080));
        MainWindow->setStyleSheet(QLatin1String("QPushButton \n"
"{\n"
"		background-color : rgba(125,125,125,0);\n"
"		color : rgba(200,200,200,255);\n"
"		border: 2px solid rgba(200,200,200,255);\n"
"    	border-radius: 15px;\n"
"}\n"
"\n"
"\n"
"QPushButton::hover\n"
"{\n"
"		background-color : rgba(255,255,255,255);\n"
"		border: 2px solid black;\n"
"		color : black;\n"
"    	border-radius: 15px;\n"
"		text-decoration : underline;\n"
"}\n"
"\n"
"QPushButton::checked\n"
"{\n"
"		background-color : rgba(255,255,255,255);\n"
"		border: 2px solid black;\n"
"		color : black;\n"
"    	border-radius: 15px;\n"
"}\n"
"\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"		background-color : rgba(255,255,255,255);\n"
"		border: 1px solid black;\n"
"		color : black;\n"
"    	border-radius: 15px;\n"
"}\n"
"QMainWindow ,QWidget#tab,#page,#page_2,#page_4\n"
"{\n"
"\n"
"		background: black;\n"
"}\n"
"\n"
"QLabel\n"
"{\n"
"		color: rgba(200,200,200,255);\n"
"}\n"
"#pp2ms\n"
"{\n"
"		border-radius:20;\n"
"		border-image: url(\"../assets/st.jpg\");\n"
"}\n"
"\n"
"QLineEdit , QTextEdit"
                        "\n"
"{\n"
"		border-radius:15;\n"
"}\n"
"\n"
"#groupBox_7ms , #groupBox_2ms\n"
"{\n"
"	border : none;\n"
"}\n"
"\n"
"QTableView\n"
"{\n"
"		background : rgba(200,200,200,50);\n"
"\n"
"}\n"
"\n"
"QTableView::item\n"
"{\n"
"		background-color:rgba(49,28,71,100);\n"
"		border : 2px solid white ;\n"
"		font-size : 15px;\n"
"		min-width : 250;\n"
"		min-height : 250;\n"
"		max-width : 400;\n"
"		max-height : 400;\n"
"\n"
"}\n"
"\n"
"              QHeaderView::section {background-color: rgba(49,28,71,120);\n"
"color:white;}\n"
"              QHeaderView {background-color: rgba(49,28,71,100);\n"
"color:white;}\n"
"              QTableCornerButton::section {background-color: rgba(49,28,71,100);}\n"
"\n"
" #groupBox_3ms , #groupBox_4ms , #groupBox_13ms,#groupBox_22ms\n"
"{\n"
"		background : rgba(150,150,150,50);\n"
"		border:1px solid black;\n"
"\n"
"		border-radius : 30%;\n"
"		\n"
"\n"
"}\n"
"\n"
"#groupBoxms\n"
"{\n"
"		background :  rgba(150,150,150,50);\n"
"		border:1px solid black;\n"
"		border-radius : 30%;\n"
""
                        "}\n"
"\n"
"\n"
"#groupBoxmsms ,#groupBox_6ms ,#groupBox_7ms,#groupBox_20ms\n"
"{\n"
"		background : qlineargradient(spread:pad, x1:0.426227, y1:0, x2:0.625, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(49, 21, 78, 255));;\n"
"		border:1px solid black;\n"
"		border-radius : 30%;\n"
"}\n"
"\n"
"#pushButton_3ms ,#upimagems\n"
"{\n"
"		background : white;		\n"
"		border-image : url(\"../assets/icon.png\");\n"
"}\n"
"\n"
"#pushButton_3ms , #upimagems::hover\n"
"{\n"
"		background : rgba(200,200,200,255);		\n"
"		border-image : url(\"../assets/icon.png\");\n"
"}\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_11 = new QVBoxLayout(centralwidget);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setMaximumSize(QSize(1920, 1080));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        horizontalLayout_16 = new QHBoxLayout(page);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        groupBox_12ms = new QGroupBox(page);
        groupBox_12ms->setObjectName(QStringLiteral("groupBox_12ms"));
        groupBox_12ms->setMinimumSize(QSize(200, 0));

        horizontalLayout_16->addWidget(groupBox_12ms);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        lineEditms = new QLineEdit(page);
        lineEditms->setObjectName(QStringLiteral("lineEditms"));
        lineEditms->setMinimumSize(QSize(90, 30));
        lineEditms->setMaximumSize(QSize(200, 30));

        horizontalLayout_15->addWidget(lineEditms);

        pushButtonms = new QPushButton(page);
        pushButtonms->setObjectName(QStringLiteral("pushButtonms"));
        pushButtonms->setMinimumSize(QSize(90, 30));
        pushButtonms->setMaximumSize(QSize(100, 30));
        pushButtonms->setCheckable(false);

        horizontalLayout_15->addWidget(pushButtonms);


        verticalLayout_3->addLayout(horizontalLayout_15);

        groupBoxmsms = new QGroupBox(page);
        groupBoxmsms->setObjectName(QStringLiteral("groupBoxmsms"));
        groupBoxmsms->setMinimumSize(QSize(1000, 160));
        groupBoxmsms->setMaximumSize(QSize(2000, 1000));
        horizontalLayout_3 = new QHBoxLayout(groupBoxmsms);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox_13ms = new QGroupBox(groupBoxmsms);
        groupBox_13ms->setObjectName(QStringLiteral("groupBox_13ms"));
        horizontalLayout = new QHBoxLayout(groupBox_13ms);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelms = new QLabel(groupBox_13ms);
        labelms->setObjectName(QStringLiteral("labelms"));
        labelms->setMinimumSize(QSize(100, 30));
        labelms->setMaximumSize(QSize(100, 30));

        horizontalLayout->addWidget(labelms);

        comboBoxms = new QComboBox(groupBox_13ms);
        comboBoxms->setObjectName(QStringLiteral("comboBoxms"));
        comboBoxms->setMinimumSize(QSize(150, 30));
        comboBoxms->setMaximumSize(QSize(200, 30));

        horizontalLayout->addWidget(comboBoxms);


        horizontalLayout_3->addWidget(groupBox_13ms);

        groupBox_3ms = new QGroupBox(groupBoxmsms);
        groupBox_3ms->setObjectName(QStringLiteral("groupBox_3ms"));
        horizontalLayout_6 = new QHBoxLayout(groupBox_3ms);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        pushButton_2ms = new QPushButton(groupBox_3ms);
        pushButton_2ms->setObjectName(QStringLiteral("pushButton_2ms"));
        pushButton_2ms->setMinimumSize(QSize(90, 30));
        pushButton_2ms->setMaximumSize(QSize(100, 30));

        horizontalLayout_6->addWidget(pushButton_2ms);

        pushButton_12ms = new QPushButton(groupBox_3ms);
        pushButton_12ms->setObjectName(QStringLiteral("pushButton_12ms"));
        pushButton_12ms->setMinimumSize(QSize(90, 30));
        pushButton_12ms->setMaximumSize(QSize(100, 30));
        pushButton_12ms->setCheckable(false);

        horizontalLayout_6->addWidget(pushButton_12ms);


        horizontalLayout_3->addWidget(groupBox_3ms);

        groupBox_4ms = new QGroupBox(groupBoxmsms);
        groupBox_4ms->setObjectName(QStringLiteral("groupBox_4ms"));
        QFont font;
        font.setPointSize(8);
        groupBox_4ms->setFont(font);
        horizontalLayout_14 = new QHBoxLayout(groupBox_4ms);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        groupBox_2ms = new QGroupBox(groupBox_4ms);
        groupBox_2ms->setObjectName(QStringLiteral("groupBox_2ms"));
        groupBox_2ms->setMinimumSize(QSize(500, 50));
        groupBox_2ms->setMaximumSize(QSize(16777215, 70));
        horizontalLayout_2 = new QHBoxLayout(groupBox_2ms);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_10ms = new QPushButton(groupBox_2ms);
        pushButton_10ms->setObjectName(QStringLiteral("pushButton_10ms"));
        pushButton_10ms->setMinimumSize(QSize(90, 30));
        pushButton_10ms->setMaximumSize(QSize(100, 30));
        pushButton_10ms->setCheckable(true);

        horizontalLayout_2->addWidget(pushButton_10ms);

        pushButton_6ms = new QPushButton(groupBox_2ms);
        pushButton_6ms->setObjectName(QStringLiteral("pushButton_6ms"));
        pushButton_6ms->setMinimumSize(QSize(90, 30));
        pushButton_6ms->setMaximumSize(QSize(100, 30));
        pushButton_6ms->setCheckable(true);

        horizontalLayout_2->addWidget(pushButton_6ms);

        pushButton_7ms = new QPushButton(groupBox_2ms);
        pushButton_7ms->setObjectName(QStringLiteral("pushButton_7ms"));
        pushButton_7ms->setMinimumSize(QSize(90, 30));
        pushButton_7ms->setMaximumSize(QSize(100, 30));
        pushButton_7ms->setCheckable(true);

        horizontalLayout_2->addWidget(pushButton_7ms);

        pushButton_8ms = new QPushButton(groupBox_2ms);
        pushButton_8ms->setObjectName(QStringLiteral("pushButton_8ms"));
        pushButton_8ms->setMinimumSize(QSize(90, 30));
        pushButton_8ms->setMaximumSize(QSize(100, 30));
        pushButton_8ms->setCheckable(true);

        horizontalLayout_2->addWidget(pushButton_8ms);

        pushButton_9ms = new QPushButton(groupBox_2ms);
        pushButton_9ms->setObjectName(QStringLiteral("pushButton_9ms"));
        pushButton_9ms->setMinimumSize(QSize(90, 30));
        pushButton_9ms->setMaximumSize(QSize(100, 30));
        pushButton_9ms->setCheckable(true);

        horizontalLayout_2->addWidget(pushButton_9ms);


        horizontalLayout_14->addWidget(groupBox_2ms);


        horizontalLayout_3->addWidget(groupBox_4ms);


        verticalLayout_3->addWidget(groupBoxmsms);


        verticalLayout_4->addLayout(verticalLayout_3);

        groupBox_7ms = new QGroupBox(page);
        groupBox_7ms->setObjectName(QStringLiteral("groupBox_7ms"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_7ms->sizePolicy().hasHeightForWidth());
        groupBox_7ms->setSizePolicy(sizePolicy);
        groupBox_7ms->setMinimumSize(QSize(1, 700));
        groupBox_7ms->setMaximumSize(QSize(2000, 800));
        groupBox_7ms->setAlignment(Qt::AlignCenter);
        verticalLayout_5 = new QVBoxLayout(groupBox_7ms);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setSizeConstraint(QLayout::SetMaximumSize);
        tableViewms = new QTableView(groupBox_7ms);
        tableViewms->setObjectName(QStringLiteral("tableViewms"));
        tableViewms->setMinimumSize(QSize(1200, 800));
        tableViewms->setMaximumSize(QSize(10000007, 100000));
        QFont font1;
        font1.setPointSize(15);
        tableViewms->setFont(font1);
        tableViewms->setLineWidth(11);
        tableViewms->setMidLineWidth(10);
        tableViewms->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableViewms->setAutoScrollMargin(10);
        tableViewms->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableViewms->setAlternatingRowColors(true);
        tableViewms->setSortingEnabled(true);
        tableViewms->horizontalHeader()->setCascadingSectionResizes(true);
        tableViewms->horizontalHeader()->setStretchLastSection(true);
        tableViewms->verticalHeader()->setCascadingSectionResizes(true);
        tableViewms->verticalHeader()->setDefaultSectionSize(300);
        tableViewms->verticalHeader()->setMinimumSectionSize(200);
        tableViewms->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableViewms->verticalHeader()->setStretchLastSection(true);

        verticalLayout_5->addWidget(tableViewms);


        verticalLayout_4->addWidget(groupBox_7ms);


        horizontalLayout_16->addLayout(verticalLayout_4);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        gridLayout_3 = new QGridLayout(page_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        groupBox_5ms = new QGroupBox(page_2);
        groupBox_5ms->setObjectName(QStringLiteral("groupBox_5ms"));
        horizontalLayout_10 = new QHBoxLayout(groupBox_5ms);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        groupBox_8ms = new QGroupBox(groupBox_5ms);
        groupBox_8ms->setObjectName(QStringLiteral("groupBox_8ms"));
        groupBox_8ms->setLayoutDirection(Qt::LeftToRight);
        verticalLayout_7 = new QVBoxLayout(groupBox_8ms);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        pushButton_4ms = new QPushButton(groupBox_8ms);
        pushButton_4ms->setObjectName(QStringLiteral("pushButton_4ms"));
        pushButton_4ms->setMinimumSize(QSize(150, 30));
        pushButton_4ms->setMaximumSize(QSize(150, 30));

        verticalLayout_7->addWidget(pushButton_4ms);

        pushButton_11ms = new QPushButton(groupBox_8ms);
        pushButton_11ms->setObjectName(QStringLiteral("pushButton_11ms"));
        pushButton_11ms->setMinimumSize(QSize(150, 30));
        pushButton_11ms->setMaximumSize(QSize(150, 30));

        verticalLayout_7->addWidget(pushButton_11ms);


        horizontalLayout_10->addWidget(groupBox_8ms);

        groupBox_6ms = new QGroupBox(groupBox_5ms);
        groupBox_6ms->setObjectName(QStringLiteral("groupBox_6ms"));
        groupBox_6ms->setAlignment(Qt::AlignCenter);
        horizontalLayout_9 = new QHBoxLayout(groupBox_6ms);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        groupBoxms = new QGroupBox(groupBox_6ms);
        groupBoxms->setObjectName(QStringLiteral("groupBoxms"));
        groupBoxms->setMinimumSize(QSize(500, 700));
        groupBoxms->setMaximumSize(QSize(1000, 1000));
        verticalLayout = new QVBoxLayout(groupBoxms);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5ms = new QLabel(groupBoxms);
        label_5ms->setObjectName(QStringLiteral("label_5ms"));
        label_5ms->setMinimumSize(QSize(150, 30));
        label_5ms->setMaximumSize(QSize(150, 30));
        QFont font2;
        font2.setPointSize(12);
        label_5ms->setFont(font2);

        horizontalLayout_4->addWidget(label_5ms);

        comboBoxms_2 = new QComboBox(groupBoxms);
        comboBoxms_2->setObjectName(QStringLiteral("comboBoxms_2"));
        comboBoxms_2->setMinimumSize(QSize(150, 30));
        comboBoxms_2->setMaximumSize(QSize(300, 16777215));
        comboBoxms_2->setFont(font2);

        horizontalLayout_4->addWidget(comboBoxms_2);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_6ms = new QLabel(groupBoxms);
        label_6ms->setObjectName(QStringLiteral("label_6ms"));
        label_6ms->setMinimumSize(QSize(150, 30));
        label_6ms->setMaximumSize(QSize(150, 30));
        label_6ms->setFont(font2);

        horizontalLayout_7->addWidget(label_6ms);

        textEditms = new QTextEdit(groupBoxms);
        textEditms->setObjectName(QStringLiteral("textEditms"));
        textEditms->setMinimumSize(QSize(150, 60));
        textEditms->setMaximumSize(QSize(300, 180));

        horizontalLayout_7->addWidget(textEditms);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_7ms = new QLabel(groupBoxms);
        label_7ms->setObjectName(QStringLiteral("label_7ms"));
        label_7ms->setMinimumSize(QSize(150, 30));
        label_7ms->setMaximumSize(QSize(150, 30));
        label_7ms->setFont(font2);

        horizontalLayout_8->addWidget(label_7ms);

        lineEdit_2ms = new QLineEdit(groupBoxms);
        lineEdit_2ms->setObjectName(QStringLiteral("lineEdit_2ms"));
        lineEdit_2ms->setMinimumSize(QSize(150, 30));
        lineEdit_2ms->setMaximumSize(QSize(300, 30));

        horizontalLayout_8->addWidget(lineEdit_2ms);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_8ms = new QLabel(groupBoxms);
        label_8ms->setObjectName(QStringLiteral("label_8ms"));
        label_8ms->setMinimumSize(QSize(150, 30));
        label_8ms->setMaximumSize(QSize(150, 30));
        label_8ms->setFont(font2);

        horizontalLayout_5->addWidget(label_8ms);

        pushButton_3ms = new QPushButton(groupBoxms);
        pushButton_3ms->setObjectName(QStringLiteral("pushButton_3ms"));
        pushButton_3ms->setMinimumSize(QSize(150, 100));
        pushButton_3ms->setMaximumSize(QSize(300, 200));

        horizontalLayout_5->addWidget(pushButton_3ms);


        verticalLayout->addLayout(horizontalLayout_5);


        horizontalLayout_9->addWidget(groupBoxms);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        imagetestms_2 = new QLabel(groupBox_6ms);
        imagetestms_2->setObjectName(QStringLiteral("imagetestms_2"));
        imagetestms_2->setMinimumSize(QSize(300, 100));
        imagetestms_2->setMaximumSize(QSize(300, 200));
        QFont font3;
        font3.setPointSize(20);
        imagetestms_2->setFont(font3);

        verticalLayout_2->addWidget(imagetestms_2);

        imagetestms = new QLabel(groupBox_6ms);
        imagetestms->setObjectName(QStringLiteral("imagetestms"));
        imagetestms->setMinimumSize(QSize(200, 200));
        imagetestms->setMaximumSize(QSize(200, 200));

        verticalLayout_2->addWidget(imagetestms);


        horizontalLayout_9->addLayout(verticalLayout_2);


        horizontalLayout_10->addWidget(groupBox_6ms);


        gridLayout_3->addWidget(groupBox_5ms, 0, 0, 1, 1);

        stackedWidget->addWidget(page_2);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        groupBox_20ms = new QGroupBox(page_4);
        groupBox_20ms->setObjectName(QStringLiteral("groupBox_20ms"));
        groupBox_20ms->setGeometry(QRect(0, 0, 1911, 1071));
        horizontalLayout_17 = new QHBoxLayout(groupBox_20ms);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        groupBox_23ms = new QGroupBox(groupBox_20ms);
        groupBox_23ms->setObjectName(QStringLiteral("groupBox_23ms"));
        groupBox_23ms->setLayoutDirection(Qt::LeftToRight);
        verticalLayout_8 = new QVBoxLayout(groupBox_23ms);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        returnupms = new QPushButton(groupBox_23ms);
        returnupms->setObjectName(QStringLiteral("returnupms"));
        returnupms->setMinimumSize(QSize(150, 30));
        returnupms->setMaximumSize(QSize(150, 30));

        verticalLayout_8->addWidget(returnupms);

        confirmupms = new QPushButton(groupBox_23ms);
        confirmupms->setObjectName(QStringLiteral("confirmupms"));
        confirmupms->setMinimumSize(QSize(150, 30));
        confirmupms->setMaximumSize(QSize(150, 30));

        verticalLayout_8->addWidget(confirmupms);


        horizontalLayout_17->addWidget(groupBox_23ms);

        groupBox_21ms = new QGroupBox(groupBox_20ms);
        groupBox_21ms->setObjectName(QStringLiteral("groupBox_21ms"));
        groupBox_21ms->setAlignment(Qt::AlignCenter);
        horizontalLayout_18 = new QHBoxLayout(groupBox_21ms);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        groupBox_22ms = new QGroupBox(groupBox_21ms);
        groupBox_22ms->setObjectName(QStringLiteral("groupBox_22ms"));
        groupBox_22ms->setMinimumSize(QSize(500, 700));
        groupBox_22ms->setMaximumSize(QSize(1000, 1000));
        verticalLayout_9 = new QVBoxLayout(groupBox_22ms);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        ipidlabelms = new QLabel(groupBox_22ms);
        ipidlabelms->setObjectName(QStringLiteral("ipidlabelms"));
        ipidlabelms->setMinimumSize(QSize(150, 30));
        ipidlabelms->setMaximumSize(QSize(150, 30));
        ipidlabelms->setFont(font2);

        horizontalLayout_19->addWidget(ipidlabelms);

        upidms = new QLineEdit(groupBox_22ms);
        upidms->setObjectName(QStringLiteral("upidms"));
        upidms->setMaximumSize(QSize(300, 30));
        upidms->setReadOnly(true);

        horizontalLayout_19->addWidget(upidms);


        verticalLayout_9->addLayout(horizontalLayout_19);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        updescms = new QLabel(groupBox_22ms);
        updescms->setObjectName(QStringLiteral("updescms"));
        updescms->setMinimumSize(QSize(150, 30));
        updescms->setMaximumSize(QSize(150, 30));
        updescms->setFont(font2);

        horizontalLayout_20->addWidget(updescms);

        updescriptionms = new QTextEdit(groupBox_22ms);
        updescriptionms->setObjectName(QStringLiteral("updescriptionms"));
        updescriptionms->setMinimumSize(QSize(150, 60));
        updescriptionms->setMaximumSize(QSize(300, 180));

        horizontalLayout_20->addWidget(updescriptionms);


        verticalLayout_9->addLayout(horizontalLayout_20);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        uptitlms = new QLabel(groupBox_22ms);
        uptitlms->setObjectName(QStringLiteral("uptitlms"));
        uptitlms->setMinimumSize(QSize(150, 30));
        uptitlms->setMaximumSize(QSize(150, 30));
        uptitlms->setFont(font2);

        horizontalLayout_21->addWidget(uptitlms);

        uptitlems = new QLineEdit(groupBox_22ms);
        uptitlems->setObjectName(QStringLiteral("uptitlems"));
        uptitlems->setMinimumSize(QSize(150, 30));
        uptitlems->setMaximumSize(QSize(300, 30));

        horizontalLayout_21->addWidget(uptitlems);


        verticalLayout_9->addLayout(horizontalLayout_21);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        upimgms = new QLabel(groupBox_22ms);
        upimgms->setObjectName(QStringLiteral("upimgms"));
        upimgms->setMinimumSize(QSize(150, 30));
        upimgms->setMaximumSize(QSize(150, 30));
        upimgms->setFont(font2);

        horizontalLayout_22->addWidget(upimgms);

        upimagems = new QPushButton(groupBox_22ms);
        upimagems->setObjectName(QStringLiteral("upimagems"));
        upimagems->setMinimumSize(QSize(150, 100));
        upimagems->setMaximumSize(QSize(300, 200));

        horizontalLayout_22->addWidget(upimagems);


        verticalLayout_9->addLayout(horizontalLayout_22);


        horizontalLayout_18->addWidget(groupBox_22ms);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        imagetest_1ms = new QLabel(groupBox_21ms);
        imagetest_1ms->setObjectName(QStringLiteral("imagetest_1ms"));
        imagetest_1ms->setMinimumSize(QSize(300, 100));
        imagetest_1ms->setMaximumSize(QSize(300, 200));
        imagetest_1ms->setFont(font3);

        verticalLayout_10->addWidget(imagetest_1ms);

        imagetest_2ms = new QLabel(groupBox_21ms);
        imagetest_2ms->setObjectName(QStringLiteral("imagetest_2ms"));
        imagetest_2ms->setMinimumSize(QSize(200, 200));
        imagetest_2ms->setMaximumSize(QSize(200, 200));

        verticalLayout_10->addWidget(imagetest_2ms);


        horizontalLayout_18->addLayout(verticalLayout_10);


        horizontalLayout_17->addWidget(groupBox_21ms);

        stackedWidget->addWidget(page_4);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        horizontalLayout_11 = new QHBoxLayout(page_3);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        groupBox_9ms = new QGroupBox(page_3);
        groupBox_9ms->setObjectName(QStringLiteral("groupBox_9ms"));
        horizontalLayout_13 = new QHBoxLayout(groupBox_9ms);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        groupBox_11ms = new QGroupBox(groupBox_9ms);
        groupBox_11ms->setObjectName(QStringLiteral("groupBox_11ms"));
        verticalLayout_6 = new QVBoxLayout(groupBox_11ms);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        pp2ms = new QPushButton(groupBox_11ms);
        pp2ms->setObjectName(QStringLiteral("pp2ms"));
        pp2ms->setMinimumSize(QSize(200, 200));

        verticalLayout_6->addWidget(pp2ms);

        pushButton_5ms = new QPushButton(groupBox_11ms);
        pushButton_5ms->setObjectName(QStringLiteral("pushButton_5ms"));
        pushButton_5ms->setMinimumSize(QSize(150, 30));
        pushButton_5ms->setMaximumSize(QSize(300, 30));

        verticalLayout_6->addWidget(pushButton_5ms);


        horizontalLayout_13->addWidget(groupBox_11ms);

        groupBox_10ms = new QGroupBox(groupBox_9ms);
        groupBox_10ms->setObjectName(QStringLiteral("groupBox_10ms"));
        formLayout = new QFormLayout(groupBox_10ms);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_11ms = new QLabel(groupBox_10ms);
        label_11ms->setObjectName(QStringLiteral("label_11ms"));
        label_11ms->setMinimumSize(QSize(150, 30));
        label_11ms->setMaximumSize(QSize(150, 30));
        label_11ms->setFont(font2);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_11ms);

        lineEdit_3ms = new QLineEdit(groupBox_10ms);
        lineEdit_3ms->setObjectName(QStringLiteral("lineEdit_3ms"));
        lineEdit_3ms->setMinimumSize(QSize(150, 30));
        lineEdit_3ms->setMaximumSize(QSize(300, 30));
        lineEdit_3ms->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_3ms);

        label_10ms = new QLabel(groupBox_10ms);
        label_10ms->setObjectName(QStringLiteral("label_10ms"));
        label_10ms->setMinimumSize(QSize(150, 30));
        label_10ms->setMaximumSize(QSize(150, 30));
        label_10ms->setFont(font2);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_10ms);

        textEdit_2ms = new QTextEdit(groupBox_10ms);
        textEdit_2ms->setObjectName(QStringLiteral("textEdit_2ms"));
        textEdit_2ms->setMinimumSize(QSize(150, 60));
        textEdit_2ms->setMaximumSize(QSize(300, 180));
        textEdit_2ms->setReadOnly(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, textEdit_2ms);


        horizontalLayout_13->addWidget(groupBox_10ms);


        horizontalLayout_11->addWidget(groupBox_9ms);

        stackedWidget->addWidget(page_3);

        verticalLayout_11->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        groupBox_12ms->setTitle(QApplication::translate("MainWindow", "GroupBox", Q_NULLPTR));
        pushButtonms->setText(QApplication::translate("MainWindow", "search ", Q_NULLPTR));
        groupBoxmsms->setTitle(QString());
        groupBox_13ms->setTitle(QString());
        labelms->setText(QApplication::translate("MainWindow", "filter by", Q_NULLPTR));
        comboBoxms->clear();
        comboBoxms->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "most views", Q_NULLPTR)
         << QApplication::translate("MainWindow", "least views", Q_NULLPTR)
         << QApplication::translate("MainWindow", "trending ?", Q_NULLPTR)
         << QApplication::translate("MainWindow", "recently added", Q_NULLPTR)
         << QApplication::translate("MainWindow", "oldest", Q_NULLPTR)
        );
        groupBox_3ms->setTitle(QString());
        pushButton_2ms->setText(QApplication::translate("MainWindow", "add", Q_NULLPTR));
        pushButton_12ms->setText(QApplication::translate("MainWindow", "view", Q_NULLPTR));
        groupBox_4ms->setTitle(QApplication::translate("MainWindow", "categories", Q_NULLPTR));
        groupBox_2ms->setTitle(QString());
        pushButton_10ms->setText(QApplication::translate("MainWindow", "horror", Q_NULLPTR));
        pushButton_6ms->setText(QApplication::translate("MainWindow", "sci-fi", Q_NULLPTR));
        pushButton_7ms->setText(QApplication::translate("MainWindow", "drama ", Q_NULLPTR));
        pushButton_8ms->setText(QApplication::translate("MainWindow", "action", Q_NULLPTR));
        pushButton_9ms->setText(QApplication::translate("MainWindow", "a categorie", Q_NULLPTR));
        groupBox_7ms->setTitle(QString());
        groupBox_5ms->setTitle(QString());
        groupBox_8ms->setTitle(QString());
        pushButton_4ms->setText(QApplication::translate("MainWindow", "return ", Q_NULLPTR));
        pushButton_11ms->setText(QApplication::translate("MainWindow", "confirm", Q_NULLPTR));
        groupBox_6ms->setTitle(QString());
        groupBoxms->setTitle(QString());
        label_5ms->setText(QApplication::translate("MainWindow", "Add a new : ", Q_NULLPTR));
        comboBoxms_2->clear();
        comboBoxms_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "movie", Q_NULLPTR)
         << QApplication::translate("MainWindow", "serie", Q_NULLPTR)
        );
        label_6ms->setText(QApplication::translate("MainWindow", "Descripton :", Q_NULLPTR));
        label_7ms->setText(QApplication::translate("MainWindow", "Title :", Q_NULLPTR));
        label_8ms->setText(QApplication::translate("MainWindow", "add a image", Q_NULLPTR));
        pushButton_3ms->setText(QString());
        imagetestms_2->setText(QApplication::translate("MainWindow", "image selected :", Q_NULLPTR));
        imagetestms->setText(QString());
        groupBox_20ms->setTitle(QString());
        groupBox_23ms->setTitle(QString());
        returnupms->setText(QApplication::translate("MainWindow", "return ", Q_NULLPTR));
        confirmupms->setText(QApplication::translate("MainWindow", "update", Q_NULLPTR));
        groupBox_21ms->setTitle(QString());
        groupBox_22ms->setTitle(QString());
        ipidlabelms->setText(QApplication::translate("MainWindow", "ID :", Q_NULLPTR));
        updescms->setText(QApplication::translate("MainWindow", "Descripton :", Q_NULLPTR));
        uptitlms->setText(QApplication::translate("MainWindow", "Title :", Q_NULLPTR));
        upimgms->setText(QApplication::translate("MainWindow", "update image", Q_NULLPTR));
        upimagems->setText(QString());
        imagetest_1ms->setText(QApplication::translate("MainWindow", "image selected :", Q_NULLPTR));
        imagetest_2ms->setText(QString());
        groupBox_9ms->setTitle(QApplication::translate("MainWindow", "GroupBox", Q_NULLPTR));
        groupBox_11ms->setTitle(QApplication::translate("MainWindow", "GroupBox", Q_NULLPTR));
        pp2ms->setText(QString());
        pushButton_5ms->setText(QApplication::translate("MainWindow", "retour", Q_NULLPTR));
        groupBox_10ms->setTitle(QApplication::translate("MainWindow", "GroupBox", Q_NULLPTR));
        label_11ms->setText(QApplication::translate("MainWindow", "Title :", Q_NULLPTR));
        label_10ms->setText(QApplication::translate("MainWindow", "Descripton :", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
