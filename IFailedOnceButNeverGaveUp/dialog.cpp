#include "dialog.h"
#include "ui_dialog.h"
#include"sms.h"
#include "diffusion.h"
#include <regex>
#include <string>
#include <iostream>
#include <QStandardItemModel>
#include <QPrinter>
#include <QPainter>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QMessageBox>
#include <QApplication>
#include <QString>
#include <QFileDialog>
#include <QDesktopServices>
#include <QDebug>
#include <QtCharts/QLineSeries>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>
#include <QtSql>
#include <QStandardItemModel>
#include <QTableView>
#include <QSystemTrayIcon>

using namespace QtCharts;
QPieSeries *seriesE;
QChart *chartE;
QChartView *chartViewE;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{

    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lance
    ui->setupUi(this);
    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(vcommand())); // permet de lancer
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(confirm_access())); // permet de l\\nce
    updateChartEmploye();
    setWindowFlags(Qt::FramelessWindowHint| Qt::WindowSystemMenuHint);
    (ui->comboBox_2)->view()->window()->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
    (ui->comboBox_2)->view()->window()->setAttribute(Qt::WA_TranslucentBackground);
    (ui->comboBox)->view()->window()->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
    (ui->comboBox)->view()->window()->setAttribute(Qt::WA_TranslucentBackground);
    ui->lineEdit_3A_2->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_3A_9->setValidator(new QIntValidator(0,9999999,this));
    ui->lineEdit_3A_8->setValidator(new QIntValidator(0,9999999,this));
    ui->lineEdit_3A_6->setValidator(new QIntValidator(0,9999999,this));
    ui->lineEdit_3A_13->setValidator(new QIntValidator(0,99999999,this));
    ui->comboBox_7->setVisible(false);
    ui->comboBox_2->setVisible(false);
    ui->comboBoxM->setVisible(false);
ui->stackedWidget->setCurrentIndex(0);
ui->StatMedia->setLayout(new QHBoxLayout);
ui->chartContainer->setLayout(new QHBoxLayout);
    ui->imagetestms->setVisible(false);
    ui->imagetestms_2->setVisible(false);
    ui->upidms->lower();
    ui->lineEdit_epms->setValidator(new QIntValidator(0,9999999,this));
    ui->lineEdit_8ms->setValidator(new QIntValidator(0,99999999,this));
    ui->upepms->setValidator(new QIntValidator(0,9999999,this));
    ui->nbrvupms->setValidator(new QIntValidator(0,99999999,this));
    byte="";

    socket = new QTcpSocket(this);

    ui->groupBox_2->setLayout(new QHBoxLayout);
    ui->groupBox_3->setLayout(new QHBoxLayout);
    ui->comboBoxM_2->setVisible(false);
    ui->comboBoxM_3->setVisible(false);
    //Media
    connect(ui->imageButtonM, &QPushButton::clicked, this, &Dialog::importImage);
    connect(ui->imageButtonM_2, &QPushButton::clicked, this, &Dialog::importImage2);
    connect(ui->radioButtonM, &QRadioButton::clicked, this, [=]() {
        type = "Radio";
    });
/*<<<<<<< HEAD
=======

>>>>>>> d265fca64f07effaee8f719cf8afeb9a3d75cd6a*/
    connect(ui->radioButton_2M, &QRadioButton::clicked, this, [=]() {
        type = "Channel";
    });
    //connect(ui->addButtonM, &QPushButton::clicked, this, &Dialog::importImage);

    Media media;
    //ui->tableViewM->setModel(media.afficherMedia());
    connect(ui->exportButtonM, &QPushButton::clicked, [this]() {
      on_exportButtonM_clicked();
    });
    connect(ui->comboBoxM, &QComboBox::currentTextChanged, this, &Dialog::on_listM_clicked);
    ui->TitleM->setValidator(new QRegExpValidator(QRegExp("[A-Za-z ]+"), this));
    ui->ProducerM->setValidator(new QRegExpValidator(QRegExp("[A-Za-z ]+"), this));
    ui->TitleM_2->setValidator(new QRegExpValidator(QRegExp("[A-Za-z ]+"), this));
    ui->ProducerM_2->setValidator(new QRegExpValidator(QRegExp("[A-Za-z ]+"), this));
    textToSpeech = new QTextToSpeech(this);
    typingTimer = new QTimer(this);
    //updateChartMedia();
    displayChannelImages();
    displayRadioImages();
    //Diffusion
    ui->lineEdit_3A_10->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_3A_7->setValidator(new QIntValidator(0,99999999,this));
    connect(ui->full, &QRadioButton::clicked, this, [=]() {
        etat = "Full";
    });
    connect(ui->reserved, &QRadioButton::clicked, this, [=]() {
        etat = "Reserved";
    });

    connect(ui->empty, &QRadioButton::clicked, this, [=]() {
        etat = "Empty";
    });

    notificationTimer = new QTimer(this);
    // Connect the timer's timeout signal to your slot
    connect(notificationTimer, &QTimer::timeout, this, &Dialog::checkReservationDates);
    notificationTimer->start(20000);
    mSystemTrayIcon = new QSystemTrayIcon(this);
    mSystemTrayIcon->setIcon(QIcon(":/myappico.png"));
    mSystemTrayIcon->setToolTip("Studio Management Application");
    mSystemTrayIcon->setVisible(true);
    checkReservationDates();
   // initializeCalendar();
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Dialog::refreshCalendar);
    timer->start(10000);
}



void Dialog::vcommand()
{
    data=A.read_from_arduino();
    qDebug()<<data;


    if(data=="1")
    {
        switch(ui->stackedWidget->currentIndex())
        {
        case 1: case 14: case 2: case 13: case 9:
            if (ui->textEdit->toPlainText()=="")
            {
                ui->textEdit->setFocus();
            }
            else
            {
                emit ui->gg_2->clicked();
            }
            break;

        }

    }

        //ui->label_3->setText("ON"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON

    else if (data=="2") //add
     {
        switch(ui->stackedWidget->currentIndex())
        {
        case 1:

            emit ui->hihi_33->clicked();
            break;
        case 3:

            emit ui->pushButton_14A->clicked();
            break;
        case 2:

            emit ui->hihi_35->clicked();
            break;
        case 4:

            emit ui->pushButton_14A_4->clicked();
            break;
        case 9:

            emit ui->hihi_43->clicked();
            break;
        case 10:

            emit ui->pushButton_14A_8->clicked();
            break;
        case 12:

            emit ui->addButtonM->clicked();
            break;
        case 13:

            emit ui->loM->clicked();
            break;
        case 14:

            emit ui->loM_2->clicked();
            break;
        case 15:

            emit ui->pushButton_11ms->clicked();
            break;

        }

     }
    else if (data=="3") //return
    {
        switch(ui->stackedWidget->currentIndex())
        {
        case 1: case 2 : case 26: case 17: case 6: case 7: case 19:
            emit ui->hihi_6->clicked();
            break;
        case 3:

            emit ui->pushButton_14A_3->clicked();
            break;
        case 4: case 21:
            emit ui->pushButton_14A_6->clicked();
            break;
        case 5 :
            emit ui->pushButton_14A_7->clicked();
            break;
        case 8 : case 9:
            emit ui->hihi_17->clicked();
            break;
        case 10: case 23:
            emit ui->pushButton_14A_10->clicked();
            break;
        case 11: case 14: case 25:
            emit ui->hihi_20->clicked();
            break;
        case 12: case 24:
            emit ui->listM->clicked();
            break;
        case 13: case 22:
            emit ui->pushButton_4->clicked();
            break;
        case 15: case 16: case 18: case 20:
            emit ui->pushButton_2->clicked();
            break;

        }
    }
    else if (data=="4")
    {
        switch(ui->stackedWidget->currentIndex())
        {
        case 3:

            emit ui->pushButton_14A_2->clicked();
            break;
        case 5:

            emit ui->pushButton_14A_5->clicked();
            break;
        case 16:

            emit ui->confirmupms->clicked();
            break;
        case 23:

            emit ui->pushButton_14A_9->clicked();
            break;
        case 24:

            emit ui->updatedButtonM->clicked();
            break;
        }
    }
    else if (data=="5")
    {
            //close();
    }

//        ui->label_3->setText("OFF");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher ON
}



void Dialog::trait(QString Role)//authentification
{
    if (Role == "HR")
            {
                ui->hihi_15->setVisible(false);
                ui->hihi_20->setVisible(false);
                ui->hihi_17->setVisible(false);
                ui->label_12->setVisible(false);
                ui->label_6->setVisible(false);
            }
            else if (Role == "Financier")
            {
        ui->hihi_5->setVisible(false);
        ui->hihi_20->setVisible(false);
        ui->hihi_17->setVisible(false);
        ui->label_12->setVisible(false);
        ui->hihi_15->setGeometry(20,280,41,41);
        ui->label_6->setVisible(false);
            }
            else if (Role == "Media Manager")
            {
        ui->hihi_15->setVisible(false);
        ui->hihi_5->setVisible(false);
        ui->label_12->setVisible(false);
        ui->hihi_20->setGeometry(20,280,41,41);
        ui->hihi_17->setGeometry(20,340,41,41);
        ui->label_6->setVisible(false);

            }
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::updateChartEmploye() {
    {
        QSqlQuery query;
        query.prepare("SELECT type, COUNT(*) FROM EMPLOYE GROUP BY type");
        query.exec();
        qreal totalCount = 0; // Total count of all data points

        while (query.next())
        {
            qreal y = query.value(1).toDouble();
            totalCount += y;
        }

        seriesE = new QPieSeries();
        query.prepare("SELECT type, COUNT(*) FROM EMPLOYE GROUP BY type");
        query.exec();

        while (query.next())
        {
            qreal y = query.value(1).toDouble();
            qreal percentage = (y / totalCount) * 100;
            QString Role = query.value(0).toString();
            QString label = QString("%1: %2%").arg(Role).arg(QString::number(percentage, 'f', 2)); // Rounded to 2 decimal places
            QPieSlice *slice = seriesE->append(label, y);
            slice->setLabelVisible(true);
            slice->setLabelColor(Qt::black); // Set label color
        }

        qDebug() << "Data count:" << seriesE->count();
        QFont title;
        title.setPointSize(16);
        chartE = new QChart();
        chartE->addSeries(seriesE);
        chartE->setTitleFont(title);
        chartE->setTitle("Employment statistics by type");
        chartViewE = new QChartView(chartE);
        chartViewE->setRenderHint(QPainter::Antialiasing); // Improve rendering quality
        chartViewE->resize(800, 600); // Resize the chart view

        // Set up the layout
        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(chartViewE);
        ui->StatEmploye->setLayout(layout);
    }
}

void Dialog::on_hihi_6_clicked()//home
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->label_6->setGeometry(15,170,51,20);
    ui->hihi_6->setStyleSheet("font: 30pt 'dripicons-v2';"
                                 " border:none;"
                                  "background-color:transparent;"
                                  "color:rgba(0,125,236,255);");
    ui->hihi_18->setStyleSheet( "QPushButton"
                                "{"
                                "font: 30pt 'dripicons-v2';"
                                "border:none;"
                                "background-color:transparent;"
                                "color:rgba(255,255,255,150);"
                                "}"
                                "QPushButton:hover"
                                "{"
                                "font: 30pt 'dripicons-v2';"
                                "border:none;"
                                "background-color:transparent;"
                                "color:rgba(255,255,255,255);"
                                "}");
    ui->hihi_7->setStyleSheet( "QPushButton"
                                "{"
                                "font: 30pt 'dripicons-v2';"
                                "border:none;"
                                "background-color:transparent;"
                                "color:rgba(255,255,255,150);"
                                "}"
                                "QPushButton:hover"
                                "{"
                                "font: 30pt 'dripicons-v2';"
                                "border:none;"
                                "background-color:transparent;"
                                "color:rgba(255,255,255,255);"
                                "}");
    ui->hihi_17->setStyleSheet( "QPushButton"
                                "{"
                                "font: 30pt 'dripicons-v2';"
                                "border:none;"
                                "background-color:transparent;"
                                "color:rgba(255,255,255,150);"
                                "}"
                                "QPushButton:hover"
                                "{"
                                "font: 30pt 'dripicons-v2';"
                                "border:none;"
                                "background-color:transparent;"
                                "color:rgba(255,255,255,255);"
                                "}");
        ui->hihi_5->setStyleSheet( "QPushButton"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,150);"
                                    "}"
                                    "QPushButton:hover"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,255);"
                                    "}");
        ui->hihi_15->setStyleSheet( "QPushButton"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,150);"
                                    "}"
                                    "QPushButton:hover"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,255);"
                                    "}");
        ui->hihi_20->setStyleSheet( "QPushButton"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,150);"
                                    "}"
                                    "QPushButton:hover"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,255);"
                                    "}");
        ui->label_15->setVisible(true);
        ui->comboBox->setVisible(true);
        ui->comboBoxM_2->setVisible(false);
        ui->comboBoxM_3->setVisible(false);
        ui->textEdit->setVisible(true);
        ui->gg_5->setVisible(true);
        ui->gg_2->setVisible(true);
        ui->label_47->setVisible(true);
        ui->label_48->setVisible(true);
}
void Dialog::confirm_access()
{


    // alors afficher ON
    if(ui->stackedWidget->currentIndex()==26)
    {
        data=A.read_from_arduino();
        if(!data.isEmpty())
        {
            s+=data;
        }
        qDebug()<<s;
        if (s>=12)
        {
        qDebug()<<s;
        QSqlQuery query;
        QString qs;
        qs="select count(*) from employe where cardid="+s;
        query.exec(qs);
        qDebug()<<qs;
        query.next();
        if((query.value(0).toInt()>=1))
        {
            ui->stackedWidget->setCurrentIndex(2);
        }
        else if(query.value(0).toInt()==0)
        {
            ui->label_44->setText("wrong id");
        }
        if (s.length()>=12)
        {
            s="";
        }
        }
    }
    if(ui->stackedWidget->currentIndex()==3)
    {
        data=A.read_from_arduino();
        qDebug()<<s;
        if(!data.isEmpty())
        {
            s+=data;
            qDebug()<<s;
        }
        ui->label_46->setText(s);
        qDebug()<<s;
        qDebug()<<ui->label_46->text();

    }
    if (s.length()>=12)
    {
        s="";
    }



}
void Dialog::on_hihi_5_clicked()//crud employe
{
    int ligne(0);
            QString rech;
        int row(0);
        QSqlQuery query;
    ui->stackedWidget->setCurrentIndex(1);
    ui->label_6->setGeometry(15,305,51,20);

    ui->comboBoxM->setVisible(false);
    ui->comboBoxM_2->setVisible(false);
    ui->comboBoxM_3->setVisible(false);
    ui->hihi_5->setStyleSheet("font: 30pt 'dripicons-v2';"
                                 " border:none;"
                                  "background-color:transparent;"
                                  "color:rgba(0,125,236,255);");
    ui->hihi_18->setStyleSheet( "QPushButton"
                                "{"
                                "font: 30pt 'dripicons-v2';"
                                "border:none;"
                                "background-color:transparent;"
                                "color:rgba(255,255,255,150);"
                                "}"
                                "QPushButton:hover"
                                "{"
                                "font: 30pt 'dripicons-v2';"
                                "border:none;"
                                "background-color:transparent;"
                                "color:rgba(255,255,255,255);"
                                "}");
    ui->hihi_7->setStyleSheet( "QPushButton"
                                "{"
                                "font: 30pt 'dripicons-v2';"
                                "border:none;"
                                "background-color:transparent;"
                                "color:rgba(255,255,255,150);"
                                "}"
                                "QPushButton:hover"
                                "{"
                                "font: 30pt 'dripicons-v2';"
                                "border:none;"
                                "background-color:transparent;"
                                "color:rgba(255,255,255,255);"
                                "}");
    ui->hihi_17->setStyleSheet( "QPushButton"
                                "{"
                                "font: 30pt 'dripicons-v2';"
                                "border:none;"
                                "background-color:transparent;"
                                "color:rgba(255,255,255,150);"
                                "}"
                                "QPushButton:hover"
                                "{"
                                "font: 30pt 'dripicons-v2';"
                                "border:none;"
                                "background-color:transparent;"
                                "color:rgba(255,255,255,255);"
                                "}");
        ui->hihi_6->setStyleSheet( "QPushButton"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,150);"
                                    "}"
                                    "QPushButton:hover"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,255);"
                                    "}");
        ui->hihi_15->setStyleSheet( "QPushButton"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,150);"
                                    "}"
                                    "QPushButton:hover"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,255);"
                                    "}");
        ui->hihi_20->setStyleSheet( "QPushButton"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,150);"
                                    "}"
                                    "QPushButton:hover"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,255);"
                                    "}");
        ui->label_15->setVisible(false);
        ui->comboBox->setVisible(false);
        ui->textEdit->setVisible(true);
        ui->gg_5->setVisible(true);
        ui->gg_2->setVisible(true);
        ui->label_47->setVisible(true);
        ui->label_48->setVisible(true);

        if (ui->textEdit->toPlainText()!="")
            {
                rech=" where CIN LIKE '%"+ui->textEdit->toPlainText()+"%' OR TYPE LIKE '%"+ui->textEdit->toPlainText()+"%' ";
                bool intyes;
                ui->textEdit->toPlainText().toInt(&intyes);
                qDebug()<<intyes;
                if (intyes)
                {
                    rech+=" or ide="+ui->textEdit->toPlainText();
                }
            }

        QString Qs;


            if (ui->comboBox_2->currentText()== "First Name from A to Z" )
            {
                Qs=" order by prenom ASC";
                qDebug()<<"test";
            }
            if (ui->comboBox_2->currentText()== "First Name from Z to A" )
            {
                Qs=" order by prenom DESC";
                qDebug()<<"test";
            }
            else if (ui->comboBox_2->currentText()== "Last Name from A to Z" )
            {
                Qs=" order by nom ASC";
                qDebug()<<"test";
            }
            if (ui->comboBox_2->currentText()== "Last Name from Z to A" )
            {
                Qs=" order by nom DESC";
                qDebug()<<"test";
            }
            else if (ui->comboBox_2->currentText()== "Id Descendant" )
            {
                Qs=" order by ide DESC";
                qDebug()<<"test";
            }
            else if (ui->comboBox_2->currentText()== "Id Ascendant" )
            {
                Qs=" order by ide ASC";
                qDebug()<<"test";
            }

        query.exec("select count(*) from employe"+rech+Qs);

        while(query.next() )
        {
            ligne=query.value(0).toInt();
        }
        //QMessageBox :: warning(this,"",QString::number( ligne));

        QStandardItemModel * model=new QStandardItemModel(ligne , 10);
        QString qs;
        qs="select IDE,CIN,TYPE,NOM,PRENOM,TEL,EMAIL,PHOTO from EMPLOYE"+rech+Qs;
        qDebug()<<qs;
        query.exec(qs);
        while(query.next())
        {
            for (int j=0;j<8;j++)
            {

                QStandardItem *item;
                if (j==7)
                            {
                                QByteArray array;
                                //qDebug()<<"Initial Array Size"<<array.size();
                                array = query.value(j).toByteArray();
                                //qDebug()<<"ARray Size"<<array.size();
                                QPixmap pixmap;
                                pixmap.loadFromData(array,"JPG && PNG",Qt::AutoColor);
                                QPixmap scaled=  pixmap.scaled(QSize( 170,170));
                                item = new QStandardItem();
                                item->setData(scaled,Qt::DecorationRole);


                            }
                            else
                            {
                                item = new QStandardItem(query.value(j).toString());
                            }


                                item->setTextAlignment(Qt::AlignCenter);

                                model->setItem(row,j,item);

            }
            row++;
        }




        model->setHeaderData(0, Qt::Horizontal , "IDE");
        model->setHeaderData(1, Qt::Horizontal , "CIN");
        model->setHeaderData(2, Qt::Horizontal , "PRENOM");
        model->setHeaderData(3, Qt::Horizontal , "NOM");
        model->setHeaderData(4, Qt::Horizontal , "TYPE");
        model->setHeaderData(5, Qt::Horizontal , "TEL");
        model->setHeaderData(6, Qt::Horizontal , "EMAIL");
        model->setHeaderData(7, Qt::Horizontal , "PHOTO");
        model->setHeaderData(8, Qt::Horizontal , "delete");
        model->setHeaderData(9, Qt::Horizontal , "update");
        ui->tableViewem->setModel(model);

        for (int j=0;j<row ; j++)
        {
            QPushButton *butt;
            butt = new QPushButton("delete");
            QString name = QString("buttondel%1").arg(j) ;
            QString display = QString("delete") ;
            butt->setObjectName(name) ;
            butt->setText(display) ;

            connect(butt, &QPushButton::clicked, this, [this, j]()
            {
                QSqlQuery query;
                query.prepare("delete from EMPLOYE where IDE=:id");
                query.bindValue(":id",ui->tableViewem->model()->data(ui->tableViewem->model()->index(j,0)).toInt());
                query.exec();
                emit ui->hihi_5->click();
            });
            butt->setStyleSheet("color:red;"
                                "background:transparent;"
                                "border:none;"
                                "font : 15pt;");
            ui->tableViewem->setIndexWidget(model->index(j, 8), butt);

            butt = new QPushButton("update");
            name = QString("buttonup%1").arg(j) ;
            display = QString("update") ;
            butt->setObjectName(name) ;
            butt->setText(display) ;

            connect(butt, &QPushButton::clicked, this, [this, j]() {
                ui->lineEdit_10->setText(ui->tableViewem->model()->data(ui->tableViewem->model()->index(j,0)).toString());
                ui->lineEdit_3A_2->setText(QString::number(ui->tableViewem->model()->data(ui->tableViewem->model()->index(j,1)).toInt()   ));
                ui->lineEdit_3A->setText(ui->tableViewem->model()->data(ui->tableViewem->model()->index(j,5)).toString());
                ui->lineEdit_3A_3->setText(ui->tableViewem->model()->data(ui->tableViewem->model()->index(j,4)).toString());

                if (ui->tableViewem->model()->data(ui->tableViewem->model()->index(j,2)).toString()=="Admin")
                {
                    ui->radioButton_7->setChecked(true);
                }

                if (ui->tableViewem->model()->data(ui->tableViewem->model()->index(j,2)).toString()=="Financier")
                {
                    ui->radioButton_8->setChecked(true);
                }
                if (ui->tableViewem->model()->data(ui->tableViewem->model()->index(j,2)).toString()=="Media Manager")
                {
                    ui->radioButton_9->setChecked(true);
                }
                if (ui->tableViewem->model()->data(ui->tableViewem->model()->index(j,2)).toString()=="HR")
                {
                    ui->radioButton_10->setChecked(true);
                }
                ui->stackedWidget->setCurrentIndex(3);
            });
            butt->setStyleSheet("color:green;"
                                "background:transparent;"
                                "border:none;"
                                "font : 15pt;"
                                "min-width : 289px");
            ui->tableViewem->setIndexWidget(model->index(j, 9), butt);
        }
        ui->tableViewem->verticalHeader()->setVisible(false);
            ui->tableViewem->resizeRowsToContents();
            ui->tableViewem->resizeColumnsToContents();
            ui->tableViewem->show();

}

void Dialog::on_hihi_15_clicked()//crud transaction
{
    qDebug()<<s;
     if((s.isEmpty()))
     {

         qDebug()<<s;
         ui->stackedWidget->setCurrentIndex(26);
     }

     qDebug()<<s;
     s="";
    ui->label_6->setGeometry(15,370,51,20);
    ui->comboBoxM->setVisible(false);
    ui->comboBoxM_2->setVisible(false);
    ui->comboBoxM_3->setVisible(false);
    ui->hihi_15->setStyleSheet("font: 30pt 'dripicons-v2';"
                                 " border:none;"
                                  "background-color:transparent;"
                                  "color:rgba(0,125,236,255);");
    ui->hihi_18->setStyleSheet( "QPushButton"
                                "{"
                                "font: 30pt 'dripicons-v2';"
                                "border:none;"
                                "background-color:transparent;"
                                "color:rgba(255,255,255,150);"
                                "}"
                                "QPushButton:hover"
                                "{"
                                "font: 30pt 'dripicons-v2';"
                                "border:none;"
                                "background-color:transparent;"
                                "color:rgba(255,255,255,255);"
                                "}");
    ui->hihi_7->setStyleSheet( "QPushButton"
                                "{"
                                "font: 30pt 'dripicons-v2';"
                                "border:none;"
                                "background-color:transparent;"
                                "color:rgba(255,255,255,150);"
                                "}"
                                "QPushButton:hover"
                                "{"
                                "font: 30pt 'dripicons-v2';"
                                "border:none;"
                                "background-color:transparent;"
                                "color:rgba(255,255,255,255);"
                                "}");
    ui->hihi_17->setStyleSheet( "QPushButton"
                                "{"
                                "font: 30pt 'dripicons-v2';"
                                "border:none;"
                                "background-color:transparent;"
                                "color:rgba(255,255,255,150);"
                                "}"
                                "QPushButton:hover"
                                "{"
                                "font: 30pt 'dripicons-v2';"
                                "border:none;"
                                "background-color:transparent;"
                                "color:rgba(255,255,255,255);"
                                "}");
        ui->hihi_6->setStyleSheet( "QPushButton"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,150);"
                                    "}"
                                    "QPushButton:hover"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,255);"
                                    "}");
        ui->hihi_5->setStyleSheet( "QPushButton"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,150);"
                                    "}"
                                    "QPushButton:hover"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,255);"
                                    "}");
        ui->hihi_20->setStyleSheet( "QPushButton"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,150);"
                                    "}"
                                    "QPushButton:hover"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,255);"
                                    "}");
        ui->label_15->setVisible(false);
        ui->comboBox->setVisible(false);
        ui->textEdit->setVisible(true);
        ui->gg_5->setVisible(true);
        ui->gg_2->setVisible(true);
        ui->label_47->setVisible(true);
        ui->label_48->setVisible(true);
        ui->comboBox_7->setVisible(true);
        connect(ui->stackedWidget, &QStackedWidget::currentChanged,this , [this]()
            {
                 ui->comboBox_7->setVisible(false);
            });
        int ligne(0);
        int row(0);
        QSqlQuery query;
        query.exec("select count(*) from TRANSACTION");
        while(query.next() )
        {
            ligne=query.value(0).toInt();
        }
        //QMessageBox :: warning(this,"",QString::number( ligne));

        QStandardItemModel * model=new QStandardItemModel(ligne , 6);
        QString qs;
        if(ui->textEdit->toPlainText()!="")
        {

           qs="select IDTRANSACTION , DATET ,TYPE , MONTANT from TRANSACTION where IDTRANSACTION="+ui->textEdit->toPlainText() ;
        }

        else if(ui->comboBox_7->currentText()=="date transaction from newest to oldest")
        {
           qs="select IDTRANSACTION , DATET ,TYPE , MONTANT from TRANSACTION order by DATET DESC";
        }
        else if(ui->comboBox_7->currentText()=="default")
        {
            qs="select IDTRANSACTION , DATET ,TYPE , MONTANT from TRANSACTION";
        }
        else if(ui->comboBox_7->currentText()=="date transaction from oldest to newest")
        {
            qs="select IDTRANSACTION , DATET ,TYPE , MONTANT from TRANSACTION order by DATET ASC";
        }
        else if(ui->comboBox_7->currentText()=="montant from highest to lowest")
        {
            qs="select IDTRANSACTION , DATET ,TYPE , MONTANT from TRANSACTION order by MONTANT DESC";
        }
        else if(ui->comboBox_7->currentText()=="montant from lowest to highest")
        {
            qs="select IDTRANSACTION , DATET ,TYPE , MONTANT from TRANSACTION order by MONTANT ASC";
        }
        qDebug()<<qs;
        query.exec(qs);
        while(query.next())
        {
            for (int j=0;j<4;j++)
            {
                QStandardItem *item;
                item = new QStandardItem(query.value(j).toString());
                item->setTextAlignment(Qt::AlignCenter);
                model->setItem(row,j,item);

            }
            row++;
        }




        model->setHeaderData(0, Qt::Horizontal , "IDTRANSACTION");
        model->setHeaderData(1, Qt::Horizontal , "DATE");
        model->setHeaderData(2, Qt::Horizontal , "TYPE");
        model->setHeaderData(3, Qt::Horizontal , "MONTANT");
        model->setHeaderData(4, Qt::Horizontal , "delete");
        model->setHeaderData(5, Qt::Horizontal , "update");
        ui->tableviewtr->setModel(model);

        for (int j=0;j<row ; j++)
        {
            QPushButton *butt;
            butt = new QPushButton("delete");
            QString name = QString("buttondel%1").arg(j) ;
            QString display = QString("delete") ;
            butt->setObjectName(name) ;
            butt->setText(display) ;

            //connect(butt, SIGNAL(clicked()),this,SLOT(deleteftable(const(j))) );
            connect(butt, &QPushButton::clicked, this, [this, j]()
            {
                QSqlQuery query;
                query.prepare("delete from TRANSACTION where IDTRANSACTION=:id");
                query.bindValue(":id",ui->tableviewtr->model()->data(ui->tableviewtr->model()->index(j,0)).toInt());
                query.exec();
                QString filePath = "C:/Users/yahya/Downloads/Compressed/project/integration/IFailedOnceButNeverGaveUp/logs.txt";

                    // Ouvrir le fichier en mode écriture
                    QFile file(filePath);
                    if (!file.open(QIODevice::Append | QIODevice::Text)) {
                        qDebug() << "Erreur lors de l'ouverture du fichier d'historique:" << file.errorString();
                        return;
                    }

                    QTextStream out(&file);
                    out << "deleted transactions\n";
                    out << "ID: " <<ui->tableviewtr->model()->data(ui->tableviewtr->model()->index(j,0)).toInt()<< "\n";

                    // Fermer le fichier
                    file.close();
                emit ui->hihi_15->click();
            });
            butt->setStyleSheet("color:red;"
                                "background:transparent;"
                                "border:none;"
                                "font : 15pt;");
            ui->tableviewtr->setIndexWidget(model->index(j, 4), butt);

            butt = new QPushButton("update");
            name = QString("buttonup%1").arg(j) ;
            display = QString("update") ;
            butt->setObjectName(name) ;
            butt->setText(display) ;

            connect(butt, &QPushButton::clicked, this, [this, j]() {
                ui->lineEdit_3A_8->setText(QString::number(ui->tableviewtr->model()->data(ui->tableviewtr->model()->index(j,3)).toInt()   ));
                ui->dateTimeEdit_2->setDateTime(ui->tableviewtr->model()->data(ui->tableviewtr->model()->index(j,1)).toDateTime());
                if (ui->tableviewtr->model()->data(ui->tableviewtr->model()->index(j,2)).toString()=="Cash")
                {
                    ui->radioButton_4->setChecked(true);
                }
                if (ui->tableviewtr->model()->data(ui->tableviewtr->model()->index(j,2)).toString()=="Checks")
                {
                    ui->radioButton_5->setChecked(true);
                }
                if (ui->tableviewtr->model()->data(ui->tableviewtr->model()->index(j,2)).toString()=="Card/Visa")
                {
                    ui->radioButton_6->setChecked(true);
                }

                ui->lineEdit_3A_9->setText(QString::number(ui->tableviewtr->model()->data(ui->tableviewtr->model()->index(j,0)).toInt()   ));
                ui->stackedWidget->setCurrentIndex(5);
            });
            butt->setStyleSheet("color:green;"
                                "background:transparent;"
                                "border:none;"
                                "font : 15pt;"
                                "min-width : 289px");
            ui->tableviewtr->setIndexWidget(model->index(j, 5), butt);
        }
        ui->tableviewtr->verticalHeader()->setVisible(false);
            ui->tableviewtr->resizeRowsToContents();
            ui->tableviewtr->resizeColumnsToContents();
            ui->tableviewtr->show();

}

void Dialog::on_hihi_33_clicked()//adduser
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->textEdit->setVisible(false);
    ui->gg_5->setVisible(false);
    ui->gg_2->setVisible(false);
    ui->label_47->setVisible(false);
    ui->label_48->setVisible(false);
    ui->comboBoxM_2->setVisible(false);
    ui->comboBoxM_3->setVisible(false);

    ui->comboBoxM->setVisible(false);
}

void Dialog::on_gg_clicked()
{
    close();
}

void Dialog::on_hihi_35_clicked()//addtransaction button
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->textEdit->setVisible(false);
    ui->gg_5->setVisible(false);
    ui->gg_2->setVisible(false);
    ui->label_47->setVisible(false);
    ui->label_48->setVisible(false);

    ui->comboBoxM_2->setVisible(false);
    ui->comboBoxM_3->setVisible(false);

}

void Dialog::on_hihi_37_clicked()//modifytransaction button
{
    ui->stackedWidget->setCurrentIndex(5);
    ui->textEdit->setVisible(false);
    ui->gg_5->setVisible(false);
    ui->gg_2->setVisible(false);
    ui->label_47->setVisible(false);
    ui->label_48->setVisible(false);

    ui->comboBoxM_2->setVisible(false);
    ui->comboBoxM_3->setVisible(false);
}

void Dialog::on_hihi_20_clicked()//tvmoviesidfk
{
    ui->stackedWidget->setCurrentIndex(6);
    ui->label_6->setGeometry(15,430,51,20);

    ui->comboBoxM_2->setVisible(false);
    ui->comboBoxM_3->setVisible(false);

    ui->comboBoxM->setVisible(false);
    ui->hihi_20->setStyleSheet("font: 30pt 'dripicons-v2';"
                                 " border:none;"
                                  "background-color:transparent;"
                                  "color:rgba(0,125,236,255);");
    ui->hihi_18->setStyleSheet( "QPushButton"
                                "{"
                                "font: 30pt 'dripicons-v2';"
                                "border:none;"
                                "background-color:transparent;"
                                "color:rgba(255,255,255,150);"
                                "}"
                                "QPushButton:hover"
                                "{"
                                "font: 30pt 'dripicons-v2';"
                                "border:none;"
                                "background-color:transparent;"
                                "color:rgba(255,255,255,255);"
                                "}");
    ui->hihi_7->setStyleSheet( "QPushButton"
                                "{"
                                "font: 30pt 'dripicons-v2';"
                                "border:none;"
                                "background-color:transparent;"
                                "color:rgba(255,255,255,150);"
                                "}"
                                "QPushButton:hover"
                                "{"
                                "font: 30pt 'dripicons-v2';"
                                "border:none;"
                                "background-color:transparent;"
                                "color:rgba(255,255,255,255);"
                                "}");
        ui->hihi_6->setStyleSheet( "QPushButton"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,150);"
                                    "}"
                                    "QPushButton:hover"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,255);"
                                    "}");
        ui->hihi_5->setStyleSheet( "QPushButton"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,150);"
                                    "}"
                                    "QPushButton:hover"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,255);"
                                    "}");
        ui->hihi_15->setStyleSheet( "QPushButton"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,150);"
                                    "}"
                                    "QPushButton:hover"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,255);"
                                    "}");
        ui->hihi_17->setStyleSheet( "QPushButton"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,150);"
                                    "}"
                                    "QPushButton:hover"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,255);"
                                    "}");
        ui->label_15->setVisible(false);
        ui->comboBox->setVisible(false);
        ui->textEdit->setVisible(false);
        ui->gg_5->setVisible(false);
        ui->gg_2->setVisible(false);
        ui->label_47->setVisible(false);
        ui->label_48->setVisible(false);
}

void Dialog::on_pushButton_14A_4_clicked()//insert transaction
{
    QString erreur="";
        QString check1;
        bool intyes2;
        ui->lineEdit_3A_6->text().toInt(&intyes2);
        if((ui->radioButton->isChecked()==false)&&(ui->radioButton_2->isChecked()==false)&&(ui->radioButton_3->isChecked()==false))
        {
            erreur+="\n- pls select one ";
        }

        if (ui->radioButton->isChecked())
            {
                check1=("Cash");
            }
        if (ui->radioButton_2->isChecked())
        {
            check1=("Checks");
        }
        if (ui->radioButton_3->isChecked())
        {
            check1=("Card/Visa");
        }
        if (intyes2==false)
        {
            erreur+="\n- montant doit etre nombre";
        }
        if (erreur=="")
        {
            QSqlQuery query;
                    query.prepare("insert into TRANSACTION (datet , type , montant , ide) values (:date , :type , :montant , :ide)");
                    query.bindValue(":date",ui->dateTimeEdit_2->dateTime());
                    query.bindValue(":type",check1);
                    query.bindValue(":montant",ui->lineEdit_3A_6->text().toInt());
                    query.bindValue(":ide",7);

                    if(query.exec())
                    {
                         QMessageBox :: information(this,"Save","Data Inserted successfully", QMessageBox ::Ok);
                         emit ui->hihi_15->click();
                    }
                    else
                    {
                         QMessageBox :: critical(this,"Error","Couldn't insert data");
                    }
                    QString filePath = "logs.txt";

                        // Ouvrir le fichier en mode écriture
                        QFile file(filePath);
                        if (!file.open(QIODevice::Append | QIODevice::Text)) {
                            qDebug() << "Erreur lors de l'ouverture du fichier d'historique:" << file.errorString();
                            return;
                        }
                        QSqlQuery query1;
                        query1.exec("select max(IDTRANSACTION) from TRANSACTION");
                        query1.next();
                        int idt=query1.value(0).toInt();
                        // Écrire les détails de l'événement ajouté dans le fichier
                        QTextStream out(&file);

                        out <<"added transactions \n";


                        out << "idt: " <<idt << "\n";
                        out << "IDE: " <<  7 << "\n";
                        out << "type: " << check1 << "\n";
                        out << "montant: " << ui->lineEdit_3A_6->text().toInt() << "\n";
                        out << "Date: " << ui->dateTimeEdit_2->dateTime().toString("yyyy-MM-dd") << "\n\n";

                        // Fermer le fichier
                        file.close();
        }



    else
    {
        QMessageBox msgbox;
        msgbox.setText(" ERREUR DE SASIE ");
        msgbox.setInformativeText("erreurs : \n"+erreur);
        msgbox.setIcon(QMessageBox::Critical);
        msgbox.setStandardButtons(QMessageBox::Ok);
        msgbox.setStyleSheet("QMessageBox { background-color: qlineargradient(spread:pad, x1:0.426227, y1:0, x2:0.625, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(49, 21, 78, 255));}"
                             "QMessageBox QLabel"
                             "{"
                             " color : #DDD ;"
                             "font-size:15px;}"
                             "QMessageBox QPushButton"
                             "{"
                             "background-color:rgba(255,255,255,150);"
                             "min-width : 100;"
                             "min-height : 30;"
                             "border-radius: 15px;"
                             "}"
        );
        msgbox.exec();
    }
    int id=6;
    QSqlQuery query;
    query.prepare("select tel from EMPLOYE where ide = :id ;");
    query.bindValue(":id", id);
    query.exec();
    query.first();
    sms s;
    s.sendSMS(6,query.value(0).toInt());
}

void Dialog::on_pushButton_14A_6_clicked()//cancel button trans(add trans)
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Dialog::on_pushButton_14A_5_clicked()//update transaction
{
    QString erreur="";
    bool intyes;
    QString check1;
    bool intyes2;

    ui->lineEdit_3A_9->text().toInt(&intyes);
    ui->lineEdit_3A_8->text().toInt(&intyes2);

    qDebug()<<intyes;
    if (intyes==false)
    {
        erreur+="\n-id doit etre nombre";
    }
    if (ui->radioButton_4->isChecked())
        {
            check1=("Cash");
        }
    if((ui->radioButton_4->isChecked()==false)&&(ui->radioButton_5->isChecked()==false)&&(ui->radioButton_6->isChecked()==false))
    {
        erreur+="\n- pls select one ";
    }

    if (ui->radioButton_5->isChecked())
    {
        check1=("Checks");
    }
    if (ui->radioButton_6->isChecked())
    {
        check1=("Card/Visa");
    }
    if (intyes2==false)
    {
        erreur+="\n- montant doit etre nombre";
    }
    if (erreur=="")
    {
        QSqlQuery query;
        query.prepare("UPDATE TRANSACTION set DATET=:date , TYPE=:type , MONTANT=:montant where IDTRANSACTION=:id ");
        query.bindValue(":date",ui->dateTimeEdit->dateTime());
        query.bindValue(":type",check1);
        query.bindValue(":montant",ui->lineEdit_3A_8->text().toInt());
        query.bindValue(":id",ui->lineEdit_3A_9->text().toInt());
        if(query.exec())
        {
             QMessageBox :: information(this,"Save","Data updated successfully", QMessageBox ::Ok);
             emit ui->hihi_15->click();
        }
        else
        {
             QMessageBox :: critical(this,"Error","Couldn't update data");
        }
    }
    else
        {
            QMessageBox msgbox;
            msgbox.setText(" ERREUR DE SASIE ");
            msgbox.setInformativeText("erreurs : \n"+erreur);
            msgbox.setIcon(QMessageBox::Critical);
            msgbox.setStandardButtons(QMessageBox::Ok);
            msgbox.setStyleSheet("QMessageBox { background-color: qlineargradient(spread:pad, x1:0.426227, y1:0, x2:0.625, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(49, 21, 78, 255));}"
                                 "QMessageBox QLabel"
                                 "{"
                                 " color : #DDD ;"
                                 "font-size:15px;}"
                                 "QMessageBox QPushButton"
                                 "{"
                                 "background-color:rgba(255,255,255,150);"
                                 "min-width : 100;"
                                 "min-height : 30;"
                                 "border-radius: 15px;"
                                 "}"
            );
            msgbox.exec();
        }
        QString filePath = "logs.txt";

            // Ouvrir le fichier en mode écriture
            QFile file(filePath);
            if (!file.open(QIODevice::Append | QIODevice::Text)) {
                qDebug() << "Erreur lors de l'ouverture du fichier d'historique:" << file.errorString();
                return;
            }


            QTextStream out(&file);
            out << "modified  transaction : "  << "\n";
            out << " ID: " << ui->lineEdit_3A_9->text().toInt() << "\n";
            out << "Ancien type: " << check1 << "\n";
            out << "Ancien montant: " << ui->lineEdit_3A_8->text().toInt() << "\n";
            out << "Ancienne Date: " << ui->dateTimeEdit->dateTime().toString("yyyy-MM-dd") << "\n\n";

            // Fermer le fichier
            file.close();
}

void Dialog::on_pushButton_14A_7_clicked()//another cancel button trans(update trans)
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Dialog::on_hihi_17_clicked()//reservation
{
    ui->label_6->setGeometry(15,490,51,20);

    ui->comboBoxM_2->setVisible(false);
    ui->comboBoxM_3->setVisible(false);

    ui->comboBoxM->setVisible(false);
    ui->hihi_17->setStyleSheet("font: 30pt 'dripicons-v2';"
                                 " border:none;"
                                  "background-color:transparent;"
                                  "color:rgba(0,125,236,255);");
    ui->hihi_18->setStyleSheet( "QPushButton"
                                "{"
                                "font: 30pt 'dripicons-v2';"
                                "border:none;"
                                "background-color:transparent;"
                                "color:rgba(255,255,255,150);"
                                "}"
                                "QPushButton:hover"
                                "{"
                                "font: 30pt 'dripicons-v2';"
                                "border:none;"
                                "background-color:transparent;"
                                "color:rgba(255,255,255,255);"
                                "}");
    ui->hihi_7->setStyleSheet( "QPushButton"
                                "{"
                                "font: 30pt 'dripicons-v2';"
                                "border:none;"
                                "background-color:transparent;"
                                "color:rgba(255,255,255,150);"
                                "}"
                                "QPushButton:hover"
                                "{"
                                "font: 30pt 'dripicons-v2';"
                                "border:none;"
                                "background-color:transparent;"
                                "color:rgba(255,255,255,255);"
                                "}");
        ui->hihi_6->setStyleSheet( "QPushButton"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,150);"
                                    "}"
                                    "QPushButton:hover"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,255);"
                                    "}");
        ui->hihi_20->setStyleSheet( "QPushButton"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,150);"
                                    "}"
                                    "QPushButton:hover"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,255);"
                                    "}");
        ui->hihi_5->setStyleSheet( "QPushButton"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,150);"
                                    "}"
                                    "QPushButton:hover"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,255);"
                                    "}");
        ui->hihi_15->setStyleSheet( "QPushButton"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,150);"
                                    "}"
                                    "QPushButton:hover"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,255);"
                                    "}");
    ui->stackedWidget->setCurrentIndex(7);
    ui->label_15->setVisible(false);
    ui->comboBox->setVisible(false);
    ui->textEdit->setVisible(true);
    ui->gg_5->setVisible(true);
    ui->gg_2->setVisible(true);
    ui->label_47->setVisible(true);
    ui->label_48->setVisible(true);
    afficherDateActuelle();
    afficherHeureActuelle();
    calculerNombreSalles();
}



void Dialog::on_pushButton_3A_clicked()//dashboard button
{
   ui->stackedWidget->setCurrentIndex(7);
}
void Dialog::on_pushButton_4A_clicked()//statistics button reservation
{
    ui->stackedWidget->setCurrentIndex(8);
}

void Dialog::on_pushButton_14A_clicked()//insert employe
{
    QString erreur="";
        QString check1;
        if((ui->radioButton_7->isChecked()==false)&&(ui->radioButton_8->isChecked()==false)&&(ui->radioButton_9->isChecked()==false)&&(ui->radioButton_10->isChecked()==false))
        {
            erreur+="\n- pls select one ";
        }

        if (ui->radioButton_7->isChecked())
            {
                check1=("Admin");
            }
        if (ui->radioButton_8->isChecked())
        {
            check1=("Financier");
        }
        if (ui->radioButton_9->isChecked())
        {
            check1=("Media Manager");
        }
        if (ui->radioButton_10->isChecked())
        {
            check1=("HR");
        }
        ui->lineEdit_3A_2->setMaxLength(8);
        if(ui->lineEdit_3A_2->text().length()<8)
        {
             erreur+="\n- Cin is an 8 digit code ";
        }
        ui->lineEdit_3A_13->setMaxLength(8);
        if(ui->lineEdit_3A_13->text().length()<8)
        {
             erreur+="\n- telephone is an 8 digit code ";
        }

        QString email = ui->lineEdit_3A_12->text();

        std::regex email_regex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");

        if (std::regex_match(email.toStdString(), email_regex)) {
            qDebug() << "Valid email address.";
        } else {
            erreur+="\n- wrong email form ";
        }
        if (erreur=="")
        {
            QSqlQuery query;
                    query.prepare("insert into EMPLOYE (cin , username , password , nom , prenom , type , photo , ids , tel , email, cardid) values (:cin , :username , :password , :nom , :prenom , :type , :photo,:ids, :tel , :email,:cardid)");
                    query.bindValue(":cin",ui->lineEdit_3A_2->text().toInt());
                    query.bindValue(":type",check1);
                    query.bindValue(":username",ui->lineEdit_3A_4->text());
                    query.bindValue(":password",ui->lineEdit_3A_5->text());
                    query.bindValue(":nom",ui->lineEdit_3A_3->text());
                    query.bindValue(":prenom",ui->lineEdit_3A->text());
                    query.bindValue(":photo",byte);
                    query.bindValue(":ids",7);
                    query.bindValue(":tel",ui->lineEdit_3A_13->text().toInt());
                    query.bindValue(":email",ui->lineEdit_3A_12->text());
                    qDebug()<<s;
                    //ui->label_46->text();
                    query.bindValue(":cardid",ui->label_46->text());
                    if(query.exec())
                    {
                         QMessageBox :: information(this,"Save","Data Inserted successfully", QMessageBox ::Ok);
                         emit ui->hihi_5->click();
                    }
                    else
                    {
                         QMessageBox :: critical(this,"Error","Couldn't insert data");
                    }
        }



    else
    {
        QMessageBox msgbox;
        msgbox.setText(" ERREUR DE SASIE ");
        msgbox.setInformativeText("erreurs : \n"+erreur);
        msgbox.setIcon(QMessageBox::Critical);
        msgbox.setStandardButtons(QMessageBox::Ok);
        msgbox.setStyleSheet("QMessageBox { background-color: qlineargradient(spread:pad, x1:0.426227, y1:0, x2:0.625, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(49, 21, 78, 255));}"
                             "QMessageBox QLabel"
                             "{"
                             " color : #DDD ;"
                             "font-size:15px;}"
                             "QMessageBox QPushButton"
                             "{"
                             "background-color:rgba(255,255,255,150);"
                             "min-width : 100;"
                             "min-height : 30;"
                             "border-radius: 15px;"
                             "}"
        );
        msgbox.exec();
    }
}

void Dialog::on_pushButton_14A_3_clicked()//cancel button employe
{
    //ui->stackedWidget->setCurrentIndex(1);
    emit ui->hihi_5->clicked();
}

void Dialog::on_pushButton_14A_2_clicked()//update button employe
{
    QString erreur="";
    QString check1;
    if((ui->radioButton_7->isChecked()==false)&&(ui->radioButton_8->isChecked()==false)&&(ui->radioButton_9->isChecked()==false)&&(ui->radioButton_10->isChecked()==false))
    {
        erreur+="\n- pls select one ";
    }

    if (ui->radioButton_7->isChecked())
        {
            check1=("Admin");
        }
    if (ui->radioButton_8->isChecked())
    {
        check1=("Financier");
    }
    if (ui->radioButton_9->isChecked())
    {
        check1=("Media Manager");
    }
    if (ui->radioButton_10->isChecked())
    {
        check1=("HR");
    }
    ui->lineEdit_3A_2->setMaxLength(8);
    if(ui->lineEdit_3A_2->text().length()<8)
    {
         erreur+="\n- Cin is an 8 digit code ";
    }

    ui->lineEdit_3A_13->setMaxLength(8);

    if(ui->lineEdit_3A_13->text().length()<8)
    {
         erreur+="\n- telephone is an 8 digit code ";
    }

    QString email = ui->lineEdit_3A_12->text();

    std::regex email_regex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");

    if (std::regex_match(email.toStdString(), email_regex)) {
        qDebug() << "Valid email address.";
    } else {
        erreur+="\n- wrong email form ";
    }

    if (erreur=="")
    {
        QSqlQuery query;
        query.prepare("UPDATE EMPLOYE set cin=:cin , username=:username , password=:password , nom=:nom , prenom=:prenom , type=:type , photo=:photo , tel=:tel , email=:email,cardid=:cardid where ide=:id");
        query.bindValue(":cin",ui->lineEdit_3A_2->text().toInt());
        query.bindValue(":type",check1);
        query.bindValue(":username",ui->lineEdit_3A_4->text());
        query.bindValue(":password",ui->lineEdit_3A_5->text());
        query.bindValue(":nom",ui->lineEdit_3A_3->text());
        query.bindValue(":prenom",ui->lineEdit_3A->text());
        query.bindValue(":tel",ui->lineEdit_3A_13->text().toInt());
        query.bindValue(":email",ui->lineEdit_3A_12->text());
        query.bindValue(":photo",byte);
        query.bindValue(":id",ui->lineEdit_10->text().toInt());
        query.bindValue(":cardid",ui->label_46->text());
        if(query.exec())
        {
             QMessageBox :: information(this,"Save","Data updated successfully", QMessageBox ::Ok);
             emit ui->hihi_5->click();
        }
        else
        {
             QMessageBox :: critical(this,"Error","Couldn't update data");
        }
    }
    else
        {
            QMessageBox msgbox;
            msgbox.setText(" ERREUR DE SASIE ");
            msgbox.setInformativeText("erreurs : \n"+erreur);
            msgbox.setIcon(QMessageBox::Critical);
            msgbox.setStandardButtons(QMessageBox::Ok);
            msgbox.setStyleSheet("QMessageBox { background-color: qlineargradient(spread:pad, x1:0.426227, y1:0, x2:0.625, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(49, 21, 78, 255));}"
                                 "QMessageBox QLabel"
                                 "{"
                                 " color : #DDD ;"
                                 "font-size:15px;}"
                                 "QMessageBox QPushButton"
                                 "{"
                                 "background-color:rgba(255,255,255,150);"
                                 "min-width : 100;"
                                 "min-height : 30;"
                                 "border-radius: 15px;"
                                 "}"
            );
            msgbox.exec();
        }
}

void Dialog::on_label_omek_clicked()
{
    QString imageFile = QFileDialog ::getOpenFileName(0,"Select Image","/home/","Image Files (*.png && *.jpg)");

          QFileInfo info(imageFile);
          ui->label_omek->setStyleSheet("border-image : url("+imageFile+");");
          QFile file(imageFile);
          if(file.open(QIODevice::ReadOnly))
          {
              byte = file.readAll();
              //QMessageBox :: critical(this,"Error",byte);
              file.close();
          }
}


void Dialog::on_pushButtonA_clicked()//stats reservation
{
    ui->stackedWidget->setCurrentIndex(8);
    ui->label_15->setVisible(false);
    ui->comboBox->setVisible(false);
    ui->textEdit->setVisible(true);
    ui->comboBoxM->setVisible(false);
    ui->gg_5->setVisible(true);
    ui->gg_2->setVisible(true);
    ui->label_47->setVisible(true);
    ui->label_48->setVisible(true);

    ui->comboBoxM_2->setVisible(false);
    ui->comboBoxM_3->setVisible(false);
}

void Dialog::on_pushButton_2A_clicked() // CRUD reservation
{    checkReservationDates();
    ui->gg_5->setVisible(false);
    ui->textEdit->setVisible(false);
    ui->gg_2->setVisible(false);
    ui->comboBox_7->setVisible(false);
    ui->comboBox->setVisible(false);
     ui->comboBoxM->setVisible(false);
    ui->stackedWidget->setCurrentIndex(9);
    ui->label_15->setVisible(false);
    ui->comboBox->setVisible(false);
    ui->textEdit->setVisible(true);
    ui->gg_5->setVisible(true);
    ui->gg_2->setVisible(true);
    ui->label_13->setVisible(true);
    ui->label_41->setVisible(true);
    ui->comboBoxM_2->setVisible(true);
     ui->comboBoxM_3->setVisible(false);

    int ligne = 0;
    int row = 0;
     QString rech ;
     if (ui->textEdit->toPlainText()!="")
     {
         bool intyes;
         ui->textEdit->toPlainText().toInt(&intyes);
         qDebug()<<intyes;
         if (intyes)
         {
             rech+=" WHERE NUMSALLE like '%"+ui->textEdit->toPlainText()+"%'";
         }
     }
    QSqlQuery query;
    query.exec("select count(*) from SALLE"+rech);
    while (query.next())
    {
        ligne = query.value(0).toInt();
    }

     QStandardItemModel *model = new QStandardItemModel(ligne, 6);
     QString Qs;
     if (ui->comboBoxM_2->currentText() == "Sorting DESC by studio number")
     {
         Qs = " ORDER BY NUMSALLE DESC";
         qDebug() << "test";
     }

    qDebug()<<"SELECT NUMSALLE,ETAT, CAPACITE, DATERES FROM SALLE"+rech+Qs;
     query.exec("SELECT NUMSALLE,ETAT, CAPACITE, DATERES FROM SALLE"+rech+Qs);
    while (query.next())
    {
        for (int j = 0; j < 4; j++)
        {
            QStandardItem *item = new QStandardItem(query.value(j).toString());
            item->setTextAlignment(Qt::AlignCenter);
            model->setItem(row, j, item);
        }
        row++;
    }

    model->setHeaderData(0, Qt::Horizontal, "Studio number");
    model->setHeaderData(1, Qt::Horizontal, "State");
    model->setHeaderData(2, Qt::Horizontal, "Capacity");
    model->setHeaderData(3, Qt::Horizontal, "Date");
    model->setHeaderData(4, Qt::Horizontal, "Delete");
    model->setHeaderData(5, Qt::Horizontal, "Update");
    ui->tableviewrr->setModel(model);

    for (int j = 0; j < row; j++)
    {
        QPushButton *butt = new QPushButton("delete");
        QString name = QString("buttondel%1").arg(j);
        QString display = QString("delete");
        butt->setObjectName(name);
        butt->setText(display);
        connect(butt, &QPushButton::clicked, this, [this, j]() {
            diffusion d;
            if (d.supprimerSalleDiffusion(ui->tableviewrr->model()->data(ui->tableviewrr->model()->index(j, 0)).toInt()))
            {
                QString ch = "Data Deleted successfully";
                textToSpeech->say(ch);
                QMessageBox::information(this, ")", "Data Deleted successfully", QMessageBox::Ok);

                emit ui->pushButton_2A->click();

            }
            else
            {
                QMessageBox::critical(this, "Error", "Couldn't delete data");
            }
        });

        butt->setStyleSheet("color:red;"
                             "background:transparent;"
                             "border:none;"
                             "font : 15pt;");
        ui->tableviewrr->setIndexWidget(model->index(j, 4), butt);

        butt = new QPushButton("update");
        name = QString("buttonup%1").arg(j);
        display = QString("update");
        butt->setObjectName(name);
        butt->setText(display);
        connect(butt, &QPushButton::clicked, this, [this, j]() {
            ui->lineEdit_3A_14->setText(QString::number(ui->tableviewrr->model()->data(ui->tableviewrr->model()->index(j, 0)).toInt()));
            ui->lineEdit_3A_11->setText(QString::number(ui->tableviewrr->model()->data(ui->tableviewrr->model()->index(j, 1)).toInt()));
            ui->dateTimeEdit_4->setDateTime(ui->tableviewrr->model()->data(ui->tableviewrr->model()->index(j, 4)).toDateTime());

            QString state = ui->tableviewrr->model()->data(ui->tableviewrr->model()->index(j, 2)).toString();
            if (state == "Full")
                ui->full_2->setChecked(true);
            else if (state == "Reserved")
                ui->reserved_2->setChecked(true);
            else if (state == "Empty")
                ui->empty_2->setChecked(true);

            ui->stackedWidget->setCurrentIndex(23);
        });
        butt->setStyleSheet("color:green;"
                             "background:transparent;"
                             "border:none;"
                             "font : 15pt;"
                             "min-width : 289px");
        ui->tableviewrr->setIndexWidget(model->index(j, 5), butt);
    }

    ui->tableviewrr->verticalHeader()->setVisible(false);
    ui->tableviewrr->resizeRowsToContents();
    ui->tableviewrr->resizeColumnsToContents();
    ui->tableviewrr->show();
}


void Dialog::on_hihi_43_clicked()//add reservation
{
    ui->stackedWidget->setCurrentIndex(10);
    ui->label_15->setVisible(false);
    ui->comboBoxM->setVisible(false);
    ui->comboBox->setVisible(false);
    ui->textEdit->setVisible(false);
    ui->gg_5->setVisible(false);
    ui->gg_2->setVisible(false);
    ui->label_47->setVisible(false);
    ui->label_48->setVisible(false);

    ui->comboBoxM_2->setVisible(false);
    ui->comboBoxM_3->setVisible(false);
    checkReservationDates();
}

void Dialog::on_listM_clicked()
{

    ui->comboBoxM->setVisible(true);
    ui->stackedWidget->setCurrentIndex(13);
    int ligne(0);
    int row(0);
    QString rech;
    if (ui->textEdit->toPlainText()!="")
    {
        rech=" where TITRE LIKE '%"+ui->textEdit->toPlainText()+"%'";

    }
    QSqlQuery query;
    query.exec("SELECT COUNT(*) FROM MEDIA"+rech);
    while(query.next())
    {
        ligne = query.value(0).toInt();
    }

    QStandardItemModel *model = new QStandardItemModel(ligne, 9);
    QString Qs;
    if (ui->comboBoxM->currentText() == "A/Z")
    {
        Qs = " ORDER BY titre ASC"; // ASC pour ordre alphabétique croissant
        qDebug() << "test";
    }
    if (ui->comboBoxM->currentText() == "Z/A")
    {
        Qs = " ORDER BY titre DESC"; // DESC pour ordre alphabétique décroissant
        qDebug() << "test";
    }
    if (ui->comboBoxM->currentText() == "Channel")
    {
        Qs = " ORDER BY CASE WHEN TYPE = 'Channel' THEN 0 ELSE 1 END, titre DESC";
        qDebug() << "test";
    }
    if (ui->comboBoxM->currentText() == "Radio")
    {
        Qs = " ORDER BY CASE WHEN TYPE = 'Radio' THEN 0 ELSE 1 END, titre DESC";
        qDebug() << "test";
    }
    qDebug()<<"SELECT IDM,TITRE, DESCRIPTION, IMAGE, PRODUCTEUR, TYPE FROM MEDIA"+rech+Qs;
    query.exec("SELECT IDM,TITRE, DESCRIPTION, IMAGE, PRODUCTEUR, TYPE FROM MEDIA"+rech+Qs);
    while(query.next())
    {
        for (int j = 0; j < 6; j++)
        {
            QStandardItem *item;

            if (j == 3)
            {
                QByteArray array;
                array = query.value(j).toByteArray();
                QPixmap pixmap;
                pixmap.loadFromData(array, "JPG && PNG", Qt::AutoColor);
                QPixmap scaled = pixmap.scaled(QSize(250, 250));
                item = new QStandardItem();
                item->setData(scaled, Qt::DecorationRole);
            }
            else
            {
                item = new QStandardItem(query.value(j).toString());
            }

                item->setTextAlignment(Qt::AlignCenter);
                model->setItem(row, j, item);

        }
        row++;
    }
    model->setHeaderData(0, Qt::Horizontal, "IDM");
    model->setHeaderData(1, Qt::Horizontal, "Title");
    model->setHeaderData(2, Qt::Horizontal, "Description");
    model->setHeaderData(3, Qt::Horizontal, "Image");
    model->setHeaderData(4, Qt::Horizontal, "Producer");
    model->setHeaderData(5, Qt::Horizontal, "Type");
    model->setHeaderData(6, Qt::Horizontal, "QR Code");
    model->setHeaderData(7, Qt::Horizontal, "delete");
    model->setHeaderData(8, Qt::Horizontal, "update");
    ui->tableViewM->setModel(model);
    for (int j = 0; j < row; j++)
    {
        QPushButton *butt;
        butt = new QPushButton("QRCode");
        QString name = QString("buttondel%1").arg(j);
        QString display = QString("*");
        butt->setObjectName(name);
        butt->setText(display);

        connect(butt, &QPushButton::clicked, this, [this, j]() {
            Media m;
            QString idm = ui->tableViewM->model()->data(ui->tableViewM->model()->index(j, 0)).toString();
            m.generateQRCode(idm);
        });


        butt->setStyleSheet("color:green;"
                            "background:transparent;"
                            "border:none;"
                            "font-size: 35px;"
                            " font-weight: bold; "
                            "border-radius: 10;"
                            "font-family:DRIPICONS-V2;"
                            "font: 15pt;");




        ui->tableViewM->setIndexWidget(model->index(j, 6), butt);
        butt = new QPushButton(")");
         name = QString("buttondel%1").arg(j);
         display = QString(")");
        butt->setObjectName(name);
        butt->setText(display);

        connect(butt, &QPushButton::clicked, this, [this, j]() {
            Media m;
            if (m.supprimerMedia(ui->tableViewM->model()->data(ui->tableViewM->model()->index(j, 1)).toString()))
            {
                QString ch = "Data Deleted successfully";
                textToSpeech->say(ch);
                QMessageBox::information(this, ")", "Data Deleted successfully", QMessageBox::Ok);
                displayChannelImages();
                displayRadioImages();

                emit ui->listM->click();

            }
            else
            {
                QMessageBox::critical(this, "Error", "Couldn't delete data");
            }
        });
        butt->setStyleSheet("color:red;"
                            "background:transparent;"
                            "border:none;"
                            "font-size: 35px;"
                            " font-weight: bold; "
                            "border-radius: 10;"
                            "font-family:DRIPICONS-V2;"
                            "font: 15pt;");




        ui->tableViewM->setIndexWidget(model->index(j, 7), butt);

        butt = new QPushButton("*");
        name = QString("buttonup%1").arg(j);
        display = QString("*");
        butt->setObjectName(name);
        butt->setText(display);

        butt = new QPushButton("*");
                name = QString("buttonup%1").arg(j);
                display = QString("*");
                butt->setObjectName(name);
                butt->setText(display);

       connect(butt, &QPushButton::clicked, this, [this, j]() {
        ui->IDM_2->setText(ui->tableViewM->model()->data(ui->tableViewM->model()->index(j, 0)).toString());
        ui->TitleM_2->setText(ui->tableViewM->model()->data(ui->tableViewM->model()->index(j, 1)).toString());
        ui->textEditM_2->setText(ui->tableViewM->model()->data(ui->tableViewM->model()->index(j, 2)).toString());
        ui->ProducerM_2->setText(ui->tableViewM->model()->data(ui->tableViewM->model()->index(j, 4)).toString());
        QPixmap pixmap = ui->tableViewM->model()->data(ui->tableViewM->model()->index(j, 3), Qt::DecorationRole).value<QPixmap>();
         ui->labelM_2->setPixmap(pixmap);
         if (ui->tableViewM->model()->data(ui->tableViewM->model()->index(j, 5)).toString()=="Radio")
                 ui->radioButtonM_2->setChecked(true);
          if (ui->tableViewM->model()->data(ui->tableViewM->model()->index(j, 5)).toString()=="Channel")
                        ui->radioButton_2M_2->setChecked(true);
          ui->stackedWidget->setCurrentIndex(24);

                });

        butt->setStyleSheet("color:green;"
                            "background:transparent;"
                            "border:none;"
                            "font-size: 35px;"
                            " font-weight: bold; "
                            "border-radius: 10;"
                            "font-family:DRIPICONS-V2;"
                            "font: 15pt;");
        ui->tableViewM->setIndexWidget(model->index(j,8), butt);
    }

    ui->tableViewM->verticalHeader()->setVisible(false);
    ui->tableViewM->viewport()->setStyleSheet("background: rgb(255, 255, 255);"
                                              "border: 1px solid white;"
                                              "border-radius: 10px;"
                                              "color: black;");
    QRect rect = ui->tableViewM->viewport()->rect();
    QPainterPath path;
    rect.adjust(+1, +1, -1, -1);
    path.addRoundedRect(rect, 25, 25);
    QRegion mask = QRegion(path.toFillPolygon().toPolygon());
    ui->tableViewM->viewport()->setMask(mask);
    //ui->tableViewM->resize(ui->tableViewM->rowHeight(0) * row, ui->tableViewM->columnWidth(3) * 4);
    ui->tableViewM->resizeRowsToContents();
    ui->tableViewM->resizeColumnsToContents();

}


void Dialog::on_loM_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

QByteArray Dialog::importImage()
{
    // Ouvrir une boîte de dialogue pour sélectionner un fichier
    QString imagePath = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));

    // Vérifier si un fichier a été sélectionné
    if (!imagePath.isEmpty()) {
        QFile file(imagePath);
        if (file.open(QIODevice::ReadOnly)) {
            // Lire les données de l'image
            QByteArray imageData = file.readAll();
            file.close();
            QPixmap pixmap ;
            pixmap.loadFromData(imageData,"JPG && PNG",Qt::AutoColor);
            ui->labelM->setPixmap(pixmap);
            return imageData;
        } else {
            qDebug() << "Erreur: Impossible d'ouvrir le fichier image.";
        }
    } else {
        qDebug() << "Erreur: Aucun fichier image sélectionné.";
    }

    return QByteArray(); // Retourner un QByteArray vide en cas d'erreur
}
QByteArray Dialog::importImage2()
{
    // Ouvrir une boîte de dialogue pour sélectionner un fichier
    QString imagePath = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));

    // Vérifier si un fichier a été sélectionné
    if (!imagePath.isEmpty()) {
        QFile file(imagePath);
        if (file.open(QIODevice::ReadOnly)) {
            // Lire les données de l'image
            QByteArray imageData = file.readAll();
            file.close();
            QPixmap pixmap ;
            pixmap.loadFromData(imageData,"JPG && PNG",Qt::AutoColor);
            ui->labelM_2->setPixmap(pixmap);
            return imageData;
        } else {
            qDebug() << "Erreur: Impossible d'ouvrir le fichier image.";
        }
    } else {
        qDebug() << "Erreur: Aucun fichier image sélectionné.";
    }

    return QByteArray(); // Retourner un QByteArray vide en cas d'erreur
}

void Dialog::on_addButtonM_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
    Media m;
    QString titre = ui->TitleM->text();
    QString producteur = ui->ProducerM->text();
    QString description = ui->textEditM->toPlainText();


    // Vérifier si le titre existe déjà dans la base de données
    if (m.isTitleRepeated(titre)) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("This title already exists.\n"
                                          "Please enter another title."),
                              QMessageBox::Ok);
        return; // Arrêter l'exécution de la fonction si le titre est répété
    }
    const QPixmap *pixmap = ui->labelM->pixmap();

        // Vérifier si la pixmap est valide
        if (!pixmap) {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                  QObject::tr("Veuillez insérer une image dans l'étiquette."),
                                  QMessageBox::Ok);
            return; // Arrêter l'exécution de la fonction si aucune image n'a été insérée
        }

        // Convertir la pixmap en QByteArray
        QByteArray imageByteArray;
        QBuffer buffer(&imageByteArray);
        buffer.open(QIODevice::WriteOnly);
        pixmap->save(&buffer, "PNG");

    if (!m.isProducerInserted(producteur)) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Please insert a producer."),
                              QMessageBox::Ok);
        return; // Arrêter l'exécution de la fonction si aucun producteur n'a été inséré
    }
    // Vérifier si la description est valide
        if (!m.isDescriptionValid(description)) {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                  QObject::tr("Description should be less than 200 characters."),
                                  QMessageBox::Ok);
            return; // Arrêter l'exécution de la fonction si la description est trop longue
        }
        // Vérifier si une image a été insérée
       if (!m.isImageInserted(imageByteArray)) {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                  QObject::tr("Please insert an image."),
                                  QMessageBox::Ok);
            return; // Arrêter l'exécution de la fonction si aucune image n'a été insérée
        }


    // Ajouter le média si toutes les vérifications sont passées avec succès
    bool test = m.ajouterMedia(titre, description,imageByteArray, producteur, type);
    if (!test) {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("The addition was not made.\n"
                                          "Please try again."),
                              QMessageBox::Ok);
        return; // Arrêter l'exécution de la fonction si l'ajout n'est pas réussi
    }

    QMessageBox::information(nullptr, QObject::tr("OK"),
                             QObject::tr("Addition is validated.\n"
                                         "Click OK to exit."),
                             QMessageBox::Ok);
}

void Dialog::on_updatedButtonM_clicked()
{
    //modifierMedia(QString titre);
    Media m;
    ui->stackedWidget->setCurrentIndex(11);
    QString titre = ui->TitleM_2->text();
    QString producteur = ui->ProducerM_2->text();
    QString description = ui->textEditM_2->toPlainText();


    const QPixmap *pixmap = ui->labelM_2->pixmap();

        // Vérifier si la pixmap est valide
        if (!pixmap) {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                  QObject::tr("Veuillez insérer une image dans l'étiquette."),
                                  QMessageBox::Ok);
            return; // Arrêter l'exécution de la fonction si aucune image n'a été insérée
        }

        // Convertir la pixmap en QByteArray
        QByteArray imageByteArray;
        QBuffer buffer(&imageByteArray);
        buffer.open(QIODevice::WriteOnly);
        pixmap->save(&buffer, "PNG");

    // Vérifier si un producteur a été inséré
    if (!m.isProducerInserted(producteur)) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Please insert a producer."),
                              QMessageBox::Ok);
        return; // Arrêter l'exécution de la fonction si aucun producteur n'a été inséré
    }
    // Vérifier si la description est valide
        if (!m.isDescriptionValid(description)) {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                  QObject::tr("Description should be less than 200 characters."),
                                  QMessageBox::Ok);
            return; // Arrêter l'exécution de la fonction si la description est trop longue
        }
    m.setTitre(ui->TitleM_2->text());
    m.setProducteur(ui->ProducerM_2->text());
    m.setDescription(ui->textEditM_2->toPlainText());
    if (ui->radioButtonM_2->isChecked())
    {
        m.setType("Radio");
    }
    if (ui->radioButton_2M_2->isChecked())
    {
        m.setType("Channel");
    }
    m.setImage(imageByteArray);

    // Ajouter le média si toutes les vérifications sont passées avec succès
    bool test = m.modifierMedia(ui->IDM_2->text().toInt());
    if (!test) {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("The addition was not made.\n"
                                          "Please try again."),
                              QMessageBox::Ok);
    }

    QMessageBox::information(nullptr, QObject::tr("OK"),
                             QObject::tr("Addition is validated.\n"
                                         "Click OK to exit."),
                             QMessageBox::Ok);


    emit ui->listM->click();
    if (!m.isImageInserted(imageByteArray)) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Please insert an image."),
                              QMessageBox::Ok);
        return; // Arrêter l'exécution de la fonction si aucune image n'a été insérée
    }
}





void Dialog::on_exportButtonM_clicked() {
    int xStart = 20; // Starting x-coordinate for the table
    int yStart = 100; // Starting y-coordinate for the table
    int rowHeight = 200; // Height of each row
    int colWidth = 280; // Width of each column
    int rowCount = 0;

    QString filePath = QFileDialog::getSaveFileName(nullptr, "Exporter vers PDF", "", "Fichiers PDF (*.pdf)");
    if (filePath.isEmpty())
        return; // Annuler l'exportation si aucun fichier n'a été sélectionné

    // Créer un objet QPrinter pour générer le fichier PDF
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(filePath);

    // Créer un objet QPainter pour dessiner sur le périphérique d'impression
    QPainter painter;
    if (!painter.begin(&printer)) {
        QMessageBox::warning(nullptr, "Erreur", "Cannot initialize the print device.");
        return;
    }

    QPixmap background("backgroundpdf.png");
    QRect backgroundRect(0, 0, printer.pageRect().width(), printer.pageRect().height());
    painter.drawPixmap(backgroundRect, background);

    QSqlQuery query;
    query.exec("SELECT IDM,TITRE,TYPE,DESCRIPTION,PRODUCTEUR, DATEM,NBRVUE,IMAGE from MEDIA");

    QFont titleFont = painter.font();
    titleFont.setFamily("CENTURY");
    painter.setPen(Qt::darkBlue);
    titleFont.setPointSize(24);
    painter.setFont(titleFont);

    QString ch = "List Of Media";
    painter.drawText(220, 50, ch);
    ch.resize(500);

    QFont defaultFont = painter.font();
    defaultFont.setFamily("ARIAL");
    painter.setPen(Qt::black);
    defaultFont.setPointSize(12);
    painter.setFont(defaultFont);

    while (query.next())
    {
        QByteArray array;
        array = query.value(7).toByteArray();
        QPixmap pixmap;
        pixmap.loadFromData(array, "JPG && PNG", Qt::AutoColor);

        painter.drawLine(xStart, yStart + rowCount * rowHeight, xStart + 2 * colWidth, yStart + rowCount * rowHeight);
        painter.drawLine(xStart, yStart + (rowCount + 1) * rowHeight, xStart + 2 * colWidth, yStart + (rowCount + 1) * rowHeight);
        painter.drawLine(xStart + colWidth, yStart + rowCount * rowHeight, xStart + colWidth, yStart + (rowCount + 1) * rowHeight);
        painter.drawLine(xStart + 2 * colWidth, yStart + rowCount * rowHeight, xStart + 2 * colWidth, yStart + (rowCount + 1) * rowHeight);

        QPixmap scaled = pixmap.scaled(QSize(180, 180));
        painter.drawText(xStart + 10, yStart + rowCount * rowHeight + 30, "IDM: " + query.value(0).toString());
        painter.drawText(xStart + 10, yStart + rowCount * rowHeight + 50, "Title: " + query.value(1).toString() + " " + query.value(4).toString());
        painter.drawText(xStart + 10, yStart + rowCount * rowHeight + 70, "Type: " + query.value(2).toString());
        painter.drawText(xStart + 10, yStart + rowCount * rowHeight + 90, "Description:" + query.value(3).toString());
        painter.drawText(xStart + 10, yStart + rowCount * rowHeight + 110, "Producer: " + query.value(4).toString());
        painter.drawText(xStart + 10, yStart + rowCount * rowHeight + 130, "Date of creation: " + query.value(5).toString());
        painter.drawText(xStart + 10, yStart + rowCount * rowHeight + 150, "Number of views: " + query.value(6).toString());
        painter.drawPixmap(xStart + colWidth + 20, yStart + rowCount * rowHeight + 15, scaled);

        rowCount++;

        if (rowCount * rowHeight + yStart + 100 + 170 > 850)
        {
            qDebug() << "Page added";
            printer.newPage();
            rowCount = 0;
            painter.drawPixmap(backgroundRect, background); // Redraw background on new page
            QPixmap background("backgroundpdf.png");
            QRect backgroundRect(0, 0, printer.pageRect().width(), printer.pageRect().height());
            painter.drawPixmap(backgroundRect, background);

        }
    }

    QString signature = "Date:" + QDate::currentDate().toString("dd/MM/yyyy");
    painter.drawText(0, printer.pageRect().bottom() - 20, signature);

    painter.end();

    QMessageBox::information(nullptr, "Successful", "Data has been successfully exported to " + filePath);
}


void Dialog::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
    ui->textEdit->setVisible(true);
}

void Dialog::on_imageButtonM_clicked()
{

}

void Dialog::on_pushButton_2ms_clicked()
{
     ui->stackedWidget->setCurrentIndex(15);
}

void Dialog::on_pushButton_12ms_clicked()
{



}




void Dialog::on_comboBoxms_currentTextChanged(const QString &arg1)
{
     emit ui->pushButton_2->click();
}

void Dialog::on_pushButton_3ms_clicked()
{
    QString imageFile = QFileDialog ::getOpenFileName(0,"Select Image","/home/","Image Files (*.png && *.jpg)");

      QFileInfo info(imageFile);
      ui->imagetestms->setVisible(true);
      ui->imagetestms_2->setVisible(true);
      ui->imagetestms->setStyleSheet("border-image : url("+imageFile+");");
      QFile file(imageFile);
      if(file.open(QIODevice::ReadOnly))
      {
          byte = file.readAll();
          //QMessageBox :: critical(this,"Error",byte);
          file.close();
      }
}



void Dialog::on_pushButton_11ms_clicked()
{
    //QMessageBox :: critical(this,"Error",byte);
    QString erreur="";
    bool intyes;
    ui->lineEdit_8ms->text().toInt(&intyes);
    qDebug()<<intyes;
    if (intyes==false)
    {
        erreur+="\n-nombre de vues doit etre un NOMBRE";
    }
    if (byte=="")
    {
        erreur+="\n-une image doit etre inserer";
    }
    if (ui->lineEdit_2ms->text()=="")
    {
        erreur+="\n-un titre ne doit pas etre vide";
    }

    QSqlQuery queury;
    queury.prepare("select count(*) from SERIE_FILM where TITRE=:titre");
    queury.bindValue(":titre",ui->lineEdit_2ms->text());
    queury.exec();
    int  checkuni;
    while (queury.next())
    {
        checkuni=queury.value(0).toInt();
    }

    qDebug()<<checkuni;
    if (checkuni!=0)
    {
        erreur+="\n-un titre doit etre unique ( ce titre existe deja )";
    }




    if (ui->textEditms->toPlainText().count()<10)
    {
        erreur+="\n-une description de au moins 10 caractére est necessaire";
    }
    if (ui->comboBox_3->currentIndex()==0)
    {
        erreur+="\n-une categorie doit etre selectionné";
    }
    if (ui->comboBox_3->currentText()==ui->comboBox_4->currentText())
    {
        erreur+="\n-la categorie primaire et secondaire doit etre different";
    }
    QString imageFile="";
    QByteArray byteT;
    imageFile= QFileDialog ::getOpenFileName(0,"Select your trailer","/home/","Image Files (*.mp4  *.m4v)");
    if (!imageFile.isEmpty())
    {
        QFileInfo fileInfo(imageFile);
        qint64 maxSizeInBytes = 50 * 1024 * 1024; // 50 MB

        if (fileInfo.size() > maxSizeInBytes) {
            erreur+="Selected file is larger than 50 MB.";
            //QMessageBox::warning(nullptr, "File Size Exceeded", "Selected file is larger than 50 MB.");
            // Handle size limit exceeded (e.g., show an error message)
        } else {
            // File size is within the allowed limit; proceed with the selected file
            qDebug() << "Selected File:" << imageFile;
            QFile file(imageFile);

            if(file.open(QIODevice::ReadOnly))
            {
                byteT = file.readAll();
                //QMessageBox :: critical(this,"Error",byte);
                file.close();
            }
            // Perform further actions with the selected file
        }
    }


    if (erreur=="")
    {
        /*
        QPixmap img(photo);
        QBuffer imgdata;
        if (imgdata.open(QIODevice::ReadWrite))
        {
            img.save(&imgdata,"PNG");
        }
        byte=imgdata.buffer().toBase64();
        if(file.open(QIODevice::ReadOnly))
        {
            byte = file.readAll();
            QMessageBox :: critical(this,"Error",byte);
            file.close();
        }*/
        //QMessageBox :: critical(this,"Error",photo);



        MOVIE T;
        int nb;

        if (ui->comboBoxms_2->currentText()=="movie")
        {
            nb=1;
        }
        else
        {
            nb=ui->lineEdit_epms->text().toInt();
        }



            // Customize the file view to apply size filter


        if(T.ajout(byte,ui->lineEdit_2ms->text(),ui->textEditms->toPlainText(),ui->lineEdit_8ms->text().toInt(),ui->timeEditms->time().toString()/*"2:00:00"*/,ui->comboBoxms_2->currentText(),nb,ui->comboBox_3->currentText(),ui->comboBox_4->currentText(),byteT))
        {
             QMessageBox :: information(this,"Save","Data Inserted successfully", QMessageBox ::Ok);
             ui->lineEdit_2ms->setText("");
             ui->textEditms->setText("");
             byte="";
             //ui->imagetest->setStyleSheet("border-image : none;");
             ui->imagetestms->setVisible(false);
             ui->imagetestms_2->setVisible(false);
             ui->stackedWidget->setCurrentIndex(14);
             emit ui->pushButton_2->click();
        }
        else
        {
             QMessageBox :: critical(this,"Error","Couldn't insert data");
        }
    }
    else
    {
        QMessageBox msgbox;
        msgbox.setText("!!!! ERREUR DE SASIE !!!!");
        msgbox.setInformativeText("erreurs : \n"+erreur);
        msgbox.setIcon(QMessageBox::Critical);
        msgbox.setStandardButtons(QMessageBox::Ok);
        msgbox.setStyleSheet("QMessageBox { background-color: qlineargradient(spread:pad, x1:0.426227, y1:0, x2:0.625, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(49, 21, 78, 255));}"
                             "QMessageBox QLabel"
                             "{"
                             " color : #DDD ;"
                             "font-size:15px;}"
                             "QMessageBox QPushButton"
                             "{"
                             "background-color:rgba(255,255,255,150);"
                             "min-width : 100;"
                             "min-height : 30;"
                             "border-radius: 15px;"
                             "}"
        );
        msgbox.exec();


        //QMessageBox :: critical(this,"Save","erreurs : "+erreur, QMessageBox ::Ok);
    }
}



void Dialog::on_pushButton_4ms_clicked()
{
     ui->stackedWidget->setCurrentIndex(14);
}

void Dialog::on_upimagems_clicked()
{
    QString imageFile = QFileDialog ::getOpenFileName(0,"Select Image","/home/","Image Files (*.png && *.jpg)");

      QFileInfo info(imageFile);
      ui->imagetest_2ms->clear();
      ui->imagetest_2ms->setStyleSheet("border-image : url("+imageFile+");");

      QFile file(imageFile);
      if(file.open(QIODevice::ReadOnly))
      {
          byte = file.readAll();
          //QMessageBox :: critical(this,"Error",byte);
          file.close();
      }
}

void Dialog::on_confirmupms_clicked()
{
    QString erreur="";
    bool intyes;
    ui->nbrvupms->text().toInt(&intyes);
    qDebug()<<intyes;
    if (intyes==false)
    {
        erreur+="\n-nombre de vues doit etre un NOMBRE";
    }
    if (ui->uptitlems->text()=="")
    {
        erreur+="\n-un titre ne doit pas etre vide";
    }
    QSqlQuery queury;
    queury.prepare("select count(*) from SERIE_FILM where TITRE=:titre AND ID!=:id");
    queury.bindValue(":titre",ui->uptitlems->text());
    queury.bindValue(":id",ui->upidms->text().toInt());
    queury.exec();
    int  checkuni;
    while (queury.next())
    {
        checkuni=queury.value(0).toInt();
    }
    if (checkuni!=0)
    {
        erreur+="\n-un titre doit etre unique ( ce titre existe deja )";
    }
    if (ui->updescriptionms->toPlainText().count()<10)
    {
        erreur+="\n-une description de au moins 10 caractére est necessaire";
    }
    if (ui->comboBox->currentIndex()==0)
    {
        erreur+="\n-une categorie doit etre selectionné";
    }
    if (ui->comboBox->currentText()==ui->comboBox_2->currentText())
    {
        erreur+="\n-la categorie primaire et secondaire doit etre different";
    }
    if (erreur=="")
    {
        if (byte!="")
        {

            MOVIE T;
            if(T.updateimg(ui->upidms->text().toInt(),ui->upepms->text().toInt(),ui->uptitlems->text(),ui->updescriptionms->toPlainText(),byte,ui->nbrvupms->text().toUInt(),ui->dureupms->time().toString(),ui->comboBox->currentText(),ui->comboBox_2->currentText()))
            {
                 QMessageBox :: information(this,"Save","Data updated successfully", QMessageBox ::Ok);
                 ui->lineEdit_2ms->setText("");
                 ui->textEditms->setText("");
                 byte="";
                 //ui->imagetest->setStyleSheet("border-image : none;");

                 ui->stackedWidget->setCurrentIndex(14);
                 emit ui->pushButton_2->click();

            }
            else
            {
                 QMessageBox :: critical(this,"Error","Couldn't update data");
            }
          }
        else
        {

            MOVIE T;
            if(T.updatenoimg(ui->upidms->text().toInt(),ui->upepms->text().toInt(),ui->uptitlems->text(),ui->updescriptionms->toPlainText(),ui->nbrvupms->text().toUInt(),ui->dureupms->time().toString(),ui->comboBox->currentText(),ui->comboBox_2->currentText()))
            {
                 QMessageBox :: information(this,"Save","Data updated successfully", QMessageBox ::Ok);
                 ui->uptitlems->setText("");
                 ui->upidms->setText("");
                 ui->updescriptionms->setText("");
                 //ui->imagetest->setStyleSheet("border-image : none;");

                 ui->stackedWidget->setCurrentIndex(14);
                 emit ui->pushButton_2->click();
            }
            else
            {
                 QMessageBox :: critical(this,"Error","Couldn't updated data");
            }
        }
    }
    else
    {
        QMessageBox msgbox;
        msgbox.setText("!!!! ERREUR DE SASIE !!!!");
        msgbox.setInformativeText("erreurs : \n"+erreur);
        msgbox.setIcon(QMessageBox::Critical);
        msgbox.setStandardButtons(QMessageBox::Ok);
        msgbox.setStyleSheet("QMessageBox { background-color: qlineargradient(spread:pad, x1:0.426227, y1:0, x2:0.625, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(49, 21, 78, 255));}"
                             "QMessageBox QLabel"
                             "{"
                             " color : #DDD ;"
                             "font-size:15px;}"
                             "QMessageBox QPushButton"
                             "{"
                             "background-color:rgba(255,255,255,150);"
                             "min-width : 100;"
                             "min-height : 30;"
                             "border-radius: 15px;"
                             "}"
        );
        msgbox.exec();
    }
}

void Dialog::on_returnupms_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);
}

void Dialog::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);
    ui->label_15->setVisible(true);
    //ui->comboBox->setVisible(true);
    ui->comboBoxM->setVisible(false);
    ui->textEdit->setVisible(true);
    ui->gg_5->setVisible(true);
    ui->gg_2->setVisible(true);
    ui->label_47->setVisible(true);
    ui->label_48->setVisible(true);

    ui->comboBoxM_2->setVisible(false);
    ui->comboBoxM_3->setVisible(true);
    int ligne(0);
    int row(0);
    QString rech ;
    if (ui->textEdit->toPlainText()!="")
    {
        rech=" where TITRE LIKE '%"+ui->textEdit->toPlainText()+"%'";
        bool intyes;
        ui->textEdit->toPlainText().toInt(&intyes);
        qDebug()<<intyes;
        if (intyes)
        {
            rech+=" or id='"+ui->textEdit->toPlainText()+"'";
        }
    }
    QString categorie;
    if ((!ui->dramacate_2->isChecked())&&(!ui->horrorcate_2->isChecked())&&(!ui->comedycate_2->isChecked())&&(!ui->romancecate_2->isChecked())&&(!ui->scificate_2->isChecked())&&(!ui->actioncate_2->isChecked())&&(!ui->sportscate_2->isChecked()))
    {
        categorie="";
    }
    else
    {
        int cc=0;
        categorie="in (";
        if ( ui->actioncate_2->isChecked())
        {
            if (cc!=0)
            {
                categorie+=",";
            }
            cc++;
            categorie+="'action'";
        }
        if ( ui->horrorcate_2->isChecked())
        {
            if (cc!=0)
            {
                categorie+=",";
            }
            cc++;
            categorie+="'horror'";
        }
        if ( ui->comedycate_2->isChecked())
        {
            if (cc!=0)
            {
                categorie+=",";
            }
            cc++;
            categorie+="'comedy'";
        }
        if ( ui->romancecate_2->isChecked())
        {
            if (cc!=0)
            {
                categorie+=",";
            }
            cc++;
            categorie+="'romance'";
        }
        if ( ui->scificate_2->isChecked())
        {
            if (cc!=0)
            {
                categorie+=",";
            }
            cc++;
            categorie+="'sci-fi'";
        }
        if ( ui->dramacate_2->isChecked())
        {
            if (cc!=0)
            {
                categorie+=",";
            }
            cc++;
            categorie+="'drama'";
        }
        if ( ui->sportscate_2->isChecked())
        {
            if (cc!=0)
            {
                categorie+=",";
            }
            cc++;
            categorie+="'sports'";
        }
        categorie=" MCATE " + categorie+" ) OR SCATE "+categorie +")";
    }
    if ((rech=="")&&(categorie!=""))
    {
        categorie="where "+categorie;
    }
    else if ((rech!="")&&(categorie!=""))
    {
        categorie="&& "+categorie;
    }
    qDebug()<<categorie;
    QSqlQuery query;
    query.exec("select count(*) from SERIE_FILM "+rech+categorie);
    while(query.next() )
    {
        ligne=query.value(0).toInt();
    }
    qDebug()<<ligne;
    //QMessageBox :: warning(this,"",QString::number( ligne));

    QStandardItemModel * model=new QStandardItemModel(ligne , 12);
    QString Qs;
    if (ui->comboBoxM_3->currentText()== "recently added" )
    {
        Qs=" order by id DESC";
        qDebug()<<"test";
    }
    else if (ui->comboBoxM_3->currentText()== "most views" )
    {
        Qs=" order by nbrvue DESC";
        qDebug()<<"test";
    }
    else if (ui->comboBoxM_3->currentText()== "least views" )
    {
        Qs=" order by nbrvue ASC";
        qDebug()<<"test";
    }
    else if (ui->comboBoxM_3->currentText()== "oldest" )
    {
        Qs=" order by id ASC";
        qDebug()<<"test";
    }
    qDebug()<<"select id ,type, titre ,description ,duree, image,nbrvue,nbrep,mcate,scate from SERIE_FILM "+rech+categorie +Qs;
    query.exec("select id ,type, titre ,description ,duree, image,nbrvue,nbrep,mcate,scate from SERIE_FILM "+rech +categorie+Qs);
    while(query.next())
    {
        for (int j=0;j<9;j++)
        {
            QStandardItem *item;

            if ( j==5)
            {
                QByteArray array;
                //qDebug()<<"Initial Array Size"<<array.size();
                array = query.value(j).toByteArray();
                //qDebug()<<"ARray Size"<<array.size();
                QPixmap pixmap;
                pixmap.loadFromData(array,"JPG && PNG",Qt::AutoColor);
                QPixmap scaled=  pixmap.scaled(QSize( 170,170));
                item = new QStandardItem();
                item->setData(scaled,Qt::DecorationRole);


            }
            else if (j==8)
            {
                QString itemcat=query.value(j).toString();
                if (query.value(j+1).toString()!="...")
                {
                    itemcat+=+","+query.value(j+1).toString();
                }
                item = new QStandardItem(itemcat);
            }
            else
            {
                item = new QStandardItem(query.value(j).toString());
            }


                item->setTextAlignment(Qt::AlignCenter);

                model->setItem(row,j,item);


        }
        row++;
    }



    model->setHeaderData(0, Qt::Horizontal , "id");
    model->setHeaderData(1, Qt::Horizontal , "type");
    model->setHeaderData(2, Qt::Horizontal , "titre");
    model->setHeaderData(3, Qt::Horizontal , "description");
    model->setHeaderData(4, Qt::Horizontal , "duree");
    model->setHeaderData(5, Qt::Horizontal , "photo");
    model->setHeaderData(6, Qt::Horizontal , "nombre de vue");
    model->setHeaderData(7, Qt::Horizontal , "nombre d'episode");
    model->setHeaderData(8, Qt::Horizontal , "categorie");
    model->setHeaderData(9, Qt::Horizontal , "trailer");
    model->setHeaderData(10, Qt::Horizontal , "delete");
    model->setHeaderData(11, Qt::Horizontal , "update");
    ui->tableViewM_2->setModel(model);
    ui->tableViewM_2->horizontalHeader()->setVisible(true);

    for (int j=0;j<row ; j++)
    {
        QPushButton *buttt;
        buttt = new QPushButton("View");
        QString namet = QString("buttonview%1").arg(j) ;
        QString displayt = QString("View") ;
        buttt->setObjectName(namet) ;
        buttt->setText(displayt) ;

        //connect(butt, SIGNAL(clicked()),this,SLOT(deleteftable(const(j))) );
        connect(buttt, &QPushButton::clicked, this, [this, j]() {
            qDebug() << "checks0";
            QSqlQuery query;
            qDebug() << "checks1";
            query.prepare("select trailer from SERIE_FILM where id=:id");
            query.bindValue(":id",ui->tableViewM_2->model()->data(ui->tableViewM_2->model()->index(j,0)).toString());
            qDebug() << "checks2";
            query.exec();
            qDebug() << "checks3";
            query.first();
            QByteArray array= query.value(0).toByteArray();
            if (!((array.isEmpty())||(array.isNull())))
            {
                qDebug() << "check0";
                auto player = new QMediaPlayer;
                qDebug() << "check1";
                QBuffer *buffer = new QBuffer(player);
                qDebug() << "check2";
                buffer->setData(array);
                qDebug() << "check3";
                if ( buffer->open(QIODevice::ReadOnly))
                {
                    qDebug() << "check4";
                }



                player->setMedia( QMediaContent(), buffer);//QUrl::fromLocalFile(imageFile));//"..\\assets\\Right-1684791019526.mp4"));
                qDebug() << "check5";
                //playlist->addMedia(QUrl("http://example.com/myclip2.mp4"));

                QVideoWidget * vid = new QVideoWidget;

                qDebug() << "check6";
                player->setVideoOutput(vid);
                qDebug() << "check7";
                //vid->show();
                //vid->setStyleSheet("border : 5px gray;");
                //playlist->setCurrentIndex(1);

                auto boxl = new QVBoxLayout();

                qDebug() << "check8";

                QPushButton *buttr;
                buttr = new QPushButton("return");
                connect(buttr, &QPushButton::clicked, this, [this,buffer,array,vid,boxl,player,buttr]() {
                    player->stop();
                    boxl->removeWidget(vid);
                    ui->stackedWidget->setCurrentIndex(14);

                    delete boxl;
                    qDebug() << "checkd0";

                    delete buffer;
                    qDebug() << "checkd1";
                    delete player;
                    qDebug() << "checkd2";


                    delete buttr;
                });

                qDebug() << "check9";
                boxl->addWidget(buttr);

                qDebug() << "check10";
                boxl->addWidget(vid);

                qDebug() << "check11";
               ui->groupBox->setLayout(boxl);

               qDebug() << "check12";

               ui->stackedWidget->setCurrentIndex(18);
               player->setVolume(80);
               player->setMuted(false);
               player->play();
               qDebug()<<player->isVideoAvailable();
            }
            else
            {
                QMessageBox msgbox;
                msgbox.setText("!!!! ERREUR  !!!!");
                msgbox.setInformativeText(" Trailer inexistant  \n");
                msgbox.setIcon(QMessageBox::Critical);
                msgbox.setStandardButtons(QMessageBox::Ok);
                msgbox.setStyleSheet("QMessageBox { background-color: qlineargradient(spread:pad, x1:0.426227, y1:0, x2:0.625, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(49, 21, 78, 255));}"
                                     "QMessageBox QLabel"
                                     "{"
                                     " color : #DDD ;"
                                     "font-size:15px;}"
                                     "QMessageBox QPushButton"
                                     "{"
                                     "background-color:rgba(255,255,255,150);"
                                     "min-width : 100;"
                                     "min-height : 30;"
                                     "border-radius: 15px;"
                                     "}"
                );
                msgbox.exec();
            }


        });
        buttt->setStyleSheet("color:blue;"
                            "background:transparent;"
                            "border:none;"
                            "font : 15pt;");
        ui->tableViewM_2->setIndexWidget(model->index(j, 9), buttt);
        QPushButton *butt;
        butt = new QPushButton("delete");
        QString name = QString("buttondel%1").arg(j) ;
        QString display = QString("delete") ;
        butt->setObjectName(name) ;
        butt->setText(display) ;

        //connect(butt, SIGNAL(clicked()),this,SLOT(deleteftable(const(j))) );
        connect(butt, &QPushButton::clicked, this, [this, j]() {
            MOVIE T;
            if(T.supp(ui->tableViewM_2->model()->data(ui->tableViewM_2->model()->index(j,0)).toInt()))
            {
                 QMessageBox :: information(this,"delete","Data Deleted successfully", QMessageBox ::Ok);
                 emit ui->pushButton_2->click();

            }
            else
            {
                 QMessageBox :: critical(this,"Error","Couldn't delete data");
            }


        });
        butt->setStyleSheet("color:red;"
                            "background:transparent;"
                            "border:none;"
                            "font : 15pt;");
        ui->tableViewM_2->setIndexWidget(model->index(j, 10), butt);

        butt = new QPushButton("update");
        name = QString("buttonup%1").arg(j) ;
        display = QString("update") ;
        butt->setObjectName(name) ;
        butt->setText(display) ;

        connect(butt, &QPushButton::clicked, this, [this, j]() {
            ui->upidms->setText(ui->tableViewM_2->model()->data(ui->tableViewM_2->model()->index(j,0)).toString()   );
            ui->typeupms->setText(ui->tableViewM_2->model()->data(ui->tableViewM_2->model()->index(j,1)).toString());
            ui->uptitlems->setText(ui->tableViewM_2->model()->data(ui->tableViewM_2->model()->index(j,2)).toString());
            ui->updescriptionms->setText(ui->tableViewM_2->model()->data(ui->tableViewM_2->model()->index(j,3)).toString());
            ui->dureupms->setTime(QTime::fromString(ui->tableViewM_2->model()->data(ui->tableViewM_2->model()->index(j,4)).toString(),"hh:mm:ss") );
            ui->nbrvupms->setText(ui->tableViewM_2->model()->data(ui->tableViewM_2->model()->index(j,6)).toString());
            ui->upepms->setText(ui->tableViewM_2->model()->data(ui->tableViewM_2->model()->index(j,7)).toString());
            QPixmap pixmap=ui->tableViewM_2->model()->data(ui->tableViewM_2->model()->index(j,5) , Qt::DecorationRole).value<QPixmap>();
            //QMessageBox :: critical(this,"Error",byte);


            QPixmap scaled=  pixmap.scaled(QSize( 200,200));
            ui->imagetest_2ms->setPixmap(scaled);
            ui->stackedWidget->setCurrentIndex(16);
        });
        butt->setStyleSheet("color:green;"
                            "background:transparent;"
                            "border:none;"
                            "font : 15pt;");
        ui->tableViewM_2->setIndexWidget(model->index(j, 11), butt);



    }



    ui->tableViewM_2->verticalHeader()->setVisible(false);
    ui->tableViewM_2->viewport()->setStyleSheet("background: rgb(255, 255, 255);"
                                             "border: 1px solid white;"
                                             "border-radius: 10px;"
                                             "color: black;");
    QRect rect = ui->tableViewM_2->viewport()->rect();
    QPainterPath path;
    rect.adjust(+1,+1,-1,-1);
    path.addRoundedRect(rect,25,25);
    QRegion mask = QRegion(path.toFillPolygon().toPolygon());
    ui->tableViewM_2->viewport()->setMask(mask);
    //ui->tableViewms->resize(ui->tableViewms->rowHeight(0)*row,ui->tableViewms->columnWidth(3)*4);
    ui->tableViewM_2->resizeRowsToContents();
    ui->tableViewM_2->resizeColumnsToContents();
    ui->tableViewM_2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);



}

void Dialog::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);
    ui->label_15->setVisible(true);
    ui->comboBox->setVisible(true);
    ui->textEdit->setVisible(true);
    ui->gg_5->setVisible(true);
    ui->gg_2->setVisible(true);
    ui->label_47->setVisible(true);
    ui->label_48->setVisible(true);
    ui->comboBoxM_2->setVisible(false);
    ui->comboBoxM_3->setVisible(false);
}

void Dialog::on_comboBoxms_2_currentTextChanged(const QString &arg1)
{
    if (arg1=="serie")
    {
        ui->lineEdit_epms->setVisible(true);
        ui->label_7ms_4->setVisible(true);
    }
    else if ( arg1=="movie")
    {
        ui->lineEdit_epms->setVisible(false);
        ui->label_7ms_4->setVisible(false);
    }
}

void Dialog::on_hihi_8_clicked() // generate pdf employee
{
    int xStart = 20; // Starting x-coordinate for the table
    int yStart = 100; // Starting y-coordinate for the table
    int rowHeight = 200; // Height of each row
    int colWidth = 280; // Width of each column
    int rowCount = 0;

    QString filePath = QFileDialog::getSaveFileName(nullptr, "Exporter vers PDF", "", "Fichiers PDF (*.pdf)");
        if (filePath.isEmpty())
            return; // Annuler l'exportation si aucun fichier n'a été sélectionné

        // Créer un objet QPrinter pour générer le fichier PDF
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(filePath);



        // Créer un objet QPainter pour dessiner sur le périphérique d'impression
        QPainter painter;

        if (!painter.begin(&printer)) {
            QMessageBox::warning(nullptr, "Erreur", "Impossible d'initialiser le périphérique d'impression.");
            return;
        }
        QPixmap background("backgroundpdf.png");
        QRect backgroundRect(0, 0, printer.pageRect().width(), printer.pageRect().height());
        painter.drawPixmap(backgroundRect, background);
        QSqlQuery query;
        query.exec("SELECT IDE,CIN,TYPE,NOM,PRENOM,TEL,EMAIL,PHOTO from EMPLOYE");


        QFont titleFont = painter.font();
        // Set font for the title
        titleFont.setFamily("CENTURY");// Change the font family
        painter.setPen(Qt::darkBlue);
        titleFont.setPointSize(24); // Change the font size
        painter.setFont(titleFont);

        // Draw the title
        QString ch = "List Of Employes";
        painter.drawText(220, 50, ch);
        ch.resize(500);

        // Reset font for other text
        QFont defaultFont = painter.font();
        defaultFont.setFamily("ARIAL");
        painter.setPen(Qt::black);
        defaultFont.setPointSize(12);
        painter.setFont(defaultFont);


        while ( query.next())
        {
            QByteArray array;
            //qDebug()<<"Initial Array Size"<<array.size();
            array = query.value(7).toByteArray();
            //qDebug()<<"ARray Size"<<array.size();
            QPixmap pixmap;
            pixmap.loadFromData(array,"JPG && PNG",Qt::AutoColor);
            // Draw horizontal lines
            painter.drawLine(xStart, yStart + rowCount * rowHeight, xStart + 2 * colWidth, yStart + rowCount * rowHeight); // Top line
            painter.drawLine(xStart, yStart + (rowCount + 1) * rowHeight, xStart + 2 * colWidth, yStart + (rowCount + 1) * rowHeight); // Bottom line

            // Draw vertical lines
            painter.drawLine(xStart + colWidth, yStart + rowCount * rowHeight, xStart + colWidth, yStart + (rowCount + 1) * rowHeight); // Left line
            painter.drawLine(xStart + 2 * colWidth, yStart + rowCount * rowHeight, xStart + 2 * colWidth, yStart + (rowCount + 1) * rowHeight); // Right line

            // Draw text and images within the cells
            QPixmap scaled = pixmap.scaled(QSize(180, 180));
            painter.drawText(xStart + 10, yStart + rowCount * rowHeight + 30, "ID : " + query.value(0).toString());
            painter.drawText(xStart + 10, yStart + rowCount * rowHeight + 50, "FULL NAME : " + query.value(3).toString() + " " + query.value(4).toString());
            painter.drawText(xStart + 10, yStart + rowCount * rowHeight + 70, "CIN : " + query.value(1).toString());
            painter.drawText(xStart + 10, yStart + rowCount * rowHeight + 90, "TYPE:" + query.value(2).toString());
            painter.drawText(xStart + 10, yStart + rowCount * rowHeight + 110, "EMAIL : " + query.value(6).toString());
            painter.drawText(xStart + 10, yStart + rowCount * rowHeight + 130, "TELEPHONE : " + query.value(5).toString());
            painter.drawPixmap(xStart + colWidth + 20, yStart + rowCount * rowHeight + 15, scaled);

            // Increment row count
            rowCount++;

            // Check if a new page needs to be added
            if (rowCount * rowHeight + yStart + 100 + 170 > 850)
            {
                qDebug() << "Page added";
                printer.newPage();
                rowCount = 0;
                QPixmap background("backgroundpdf.png");
                QRect backgroundRect(0, 0, printer.pageRect().width(), printer.pageRect().height());
                painter.drawPixmap(backgroundRect, background);

            }

        }




        // Ajouter la signature et la date
        QString signature ="Date:"+QDate::currentDate().toString("dd/MM/yyyy");
        painter.drawText(0, printer.pageRect().bottom() - 20, signature);
        // Terminer le dessin
        painter.end();

        QMessageBox::information(nullptr, "Succès", "Les données ont été exportées avec succès vers " + filePath);
}

void Dialog::on_gg_2_clicked()
{
    switch (ui->stackedWidget->currentIndex()) {
    case 1:
        emit ui->hihi_5->click();
        break;
    case 2:
        emit ui->hihi_15->click();
        break;
    case 13:
        emit ui->listM->clicked();
        break;
    case 14:
        emit ui->pushButton_2->clicked();
        break;
    case 9:
        emit ui->pushButton_2A->clicked();
        break;

    }
}

void Dialog::on_gg_5_clicked()
{
    if (ui->stackedWidget->currentIndex()==1)
    {
        emit ui->hihi_5->click();
        if(ui->comboBox_2->isVisible())
        {
            ui->comboBox_2->setVisible(false);
        }
        else
        {
            ui->comboBox_2->setVisible(true);
        }
    }
}

void Dialog::on_hihi_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);
    ui->label_6->setGeometry(15,245,51,20);
    ui->hihi_7->setStyleSheet("font: 30pt 'dripicons-v2';"
                                 " border:none;"
                                  "background-color:transparent;"
                                  "color:rgba(0,125,236,255);");
    ui->hihi_18->setStyleSheet( "QPushButton"
                                "{"
                                "font: 30pt 'dripicons-v2';"
                                "border:none;"
                                "background-color:transparent;"
                                "color:rgba(255,255,255,150);"
                                "}"
                                "QPushButton:hover"
                                "{"
                                "font: 30pt 'dripicons-v2';"
                                "border:none;"
                                "background-color:transparent;"
                                "color:rgba(255,255,255,255);"
                                "}");
    ui->hihi_6->setStyleSheet( "QPushButton"
                                "{"
                                "font: 30pt 'dripicons-v2';"
                                "border:none;"
                                "background-color:transparent;"
                                "color:rgba(255,255,255,150);"
                                "}"
                                "QPushButton:hover"
                                "{"
                                "font: 30pt 'dripicons-v2';"
                                "border:none;"
                                "background-color:transparent;"
                                "color:rgba(255,255,255,255);"
                                "}");
    ui->hihi_17->setStyleSheet( "QPushButton"
                                "{"
                                "font: 30pt 'dripicons-v2';"
                                "border:none;"
                                "background-color:transparent;"
                                "color:rgba(255,255,255,150);"
                                "}"
                                "QPushButton:hover"
                                "{"
                                "font: 30pt 'dripicons-v2';"
                                "border:none;"
                                "background-color:transparent;"
                                "color:rgba(255,255,255,255);"
                                "}");
        ui->hihi_5->setStyleSheet( "QPushButton"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,150);"
                                    "}"
                                    "QPushButton:hover"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,255);"
                                    "}");
        ui->hihi_15->setStyleSheet( "QPushButton"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,150);"
                                    "}"
                                    "QPushButton:hover"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,255);"
                                    "}");
        ui->hihi_20->setStyleSheet( "QPushButton"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,150);"
                                    "}"
                                    "QPushButton:hover"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,255);"
                                    "}");
        ui->label_15->setVisible(true);
        ui->comboBox->setVisible(true);
        ui->textEdit->setVisible(true);
        ui->gg_5->setVisible(true);
        ui->gg_2->setVisible(true);
        ui->label_47->setVisible(true);
        ui->label_48->setVisible(true);

        ui->comboBoxM_2->setVisible(false);
        ui->comboBoxM_3->setVisible(false);
}

void Dialog::on_searchLineEditM_textChanged(const QString &arg1)
{
    /*QString searchText = arg1.trimmed();
    if (searchText.isEmpty()) {
        // If lineEdit is empty, reset the tableView
        on_listM_clicked();
        return;
    }

    QString queryText;

    if (searchText.length() == 1) {
        // If only one letter is entered, search for rows starting with that letter
        queryText = "SELECT IDM, TITRE, DESCRIPTION, IMAGE, PRODUCTEUR FROM MEDIA WHERE TITRE LIKE '" + searchText + "%'";
    } else {
        // Otherwise, search for rows containing the complete text
        queryText = "SELECT IDM, TITRE, DESCRIPTION, IMAGE, PRODUCTEUR, TYPE FROM MEDIA WHERE TITRE LIKE '%" + searchText + "%'";
    }

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(queryText);

    // Set up the image delegate for column 4
    QStandardItemModel *imageModel = new QStandardItemModel(model->rowCount(), model->columnCount());
    for (int row = 0; row < model->rowCount(); ++row) {
        QModelIndex index = model->index(row, 3); // Assuming IMAGE is in column 4
        QString imagePath = index.data().toString();
        QPixmap pixmap(imagePath);
        if (!pixmap.isNull()) {
            QStandardItem *item = new QStandardItem(QIcon(pixmap.scaledToHeight(50)), "");
            imageModel->setItem(row, 3, item);
        }
    }
    ui->tableViewM->setModel(imageModel);
    ui->tableViewM->setItemDelegateForColumn(3, new QStyledItemDelegate());

    // Set the main model after setting up the image delegate
    ui->tableViewM->setModel(model);*/
}


void Dialog::displayChannelImages()
{

    QSqlQuery query;
    query.prepare("SELECT IMAGE FROM MEDIA WHERE TYPE = 'Channel'");
    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Error", "Error retrieving channel images from database.");
        return;
    }

    int buttonIndex = 1;

    while (query.next()) {
        QByteArray imageData = query.value(0).toByteArray();


        QPixmap pixmap;
        pixmap.loadFromData(imageData);

        QString buttonName = QString("buttonM%1").arg(buttonIndex);
        QPushButton* button = findChild<QPushButton*>(buttonName);

        if (button) {

            QSize buttonSize = button->size();
            QPixmap scaledPixmap = pixmap.scaled(buttonSize, Qt::KeepAspectRatio);


            button->setIcon(QIcon(scaledPixmap));
            button->setIconSize(buttonSize);
        }

        buttonIndex++;
    }
}
void Dialog::displayRadioImages()
{
    // Récupérer les images de la table Media avec le type "Channel"
    QSqlQuery query;
    query.prepare("SELECT IMAGE FROM MEDIA WHERE TYPE = 'Radio'");
    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Error", "Error retrieving Radio images from database.");
        return;
    }

    int buttonIndex = 1;

    while (query.next()) {
        QByteArray imageData = query.value(0).toByteArray(); // Récupérer l'image en tant que QByteArray

        // Convertir le QByteArray en QPixmap pour l'afficher dans le QPushButton correspondant
        QPixmap pixmap;
        pixmap.loadFromData(imageData);

        // Trouver le nom du QPushButton correspondant
        QString buttonName = QString("buttonMR%1").arg(buttonIndex);
        QPushButton* button = findChild<QPushButton*>(buttonName);

        if (button) {
            // Redimensionner l'image pour s'adapter au QPushButton si nécessaire
            QSize buttonSize = button->size();
            QPixmap scaledPixmap = pixmap.scaled(buttonSize, Qt::KeepAspectRatio);

            // Afficher l'image dans le QPushButton
            button->setIcon(QIcon(scaledPixmap));
            button->setIconSize(buttonSize);
        }

        buttonIndex++; // Passer au QPushButton suivant
    }
}

void Dialog::on_hihi_18_clicked()
{
    if(socket->state() == QAbstractSocket::UnconnectedState)
    {
        socket->connectToHost("localhost", 4200) ;
        connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
        connect(socket, SIGNAL(connected()), this, SLOT(connected()));
        socket->waitForConnected(2000);
    }
    if((socket->state() == QAbstractSocket::ConnectingState)||(socket->state() == QAbstractSocket::ConnectedState))
    {
        ui->stackedWidget->setCurrentIndex(19);
        ui->hihi_18->setStyleSheet("font: 30pt 'dripicons-v2';"
                                     " border:none;"
                                      "background-color:transparent;"
                                      "color:rgba(0,125,236,255);");
        ui->hihi_15->setStyleSheet( "QPushButton"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,150);"
                                    "}"
                                    "QPushButton:hover"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,255);"
                                    "}");
        ui->hihi_7->setStyleSheet( "QPushButton"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,150);"
                                    "}"
                                    "QPushButton:hover"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,255);"
                                    "}");
        ui->hihi_17->setStyleSheet( "QPushButton"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,150);"
                                    "}"
                                    "QPushButton:hover"
                                    "{"
                                    "font: 30pt 'dripicons-v2';"
                                    "border:none;"
                                    "background-color:transparent;"
                                    "color:rgba(255,255,255,255);"
                                    "}");
            ui->hihi_6->setStyleSheet( "QPushButton"
                                        "{"
                                        "font: 30pt 'dripicons-v2';"
                                        "border:none;"
                                        "background-color:transparent;"
                                        "color:rgba(255,255,255,150);"
                                        "}"
                                        "QPushButton:hover"
                                        "{"
                                        "font: 30pt 'dripicons-v2';"
                                        "border:none;"
                                        "background-color:transparent;"
                                        "color:rgba(255,255,255,255);"
                                        "}");
            ui->hihi_5->setStyleSheet( "QPushButton"
                                        "{"
                                        "font: 30pt 'dripicons-v2';"
                                        "border:none;"
                                        "background-color:transparent;"
                                        "color:rgba(255,255,255,150);"
                                        "}"
                                        "QPushButton:hover"
                                        "{"
                                        "font: 30pt 'dripicons-v2';"
                                        "border:none;"
                                        "background-color:transparent;"
                                        "color:rgba(255,255,255,255);"
                                        "}");
            ui->hihi_20->setStyleSheet( "QPushButton"
                                        "{"
                                        "font: 30pt 'dripicons-v2';"
                                        "border:none;"
                                        "background-color:transparent;"
                                        "color:rgba(255,255,255,150);"
                                        "}"
                                        "QPushButton:hover"
                                        "{"
                                        "font: 30pt 'dripicons-v2';"
                                        "border:none;"
                                        "background-color:transparent;"
                                        "color:rgba(255,255,255,255);"
                                        "}");
    }
    else
    {
        QMessageBox msgbox;
        msgbox.setText("!!!! connection a echouée !!!!");
        msgbox.setInformativeText("erreurs : \n impossible de connecter au server , chatterbox est desactiver");
        msgbox.setIcon(QMessageBox::Critical);
        msgbox.setStandardButtons(QMessageBox::Ok);
        msgbox.setStyleSheet("QMessageBox { background-color: qlineargradient(spread:pad, x1:0.426227, y1:0, x2:0.625, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(49, 21, 78, 255));}"
                             "QMessageBox QLabel"
                             "{"
                             " color : #DDD ;"
                             "font-size:15px;}"
                             "QMessageBox QPushButton"
                             "{"
                             "background-color:rgba(255,255,255,150);"
                             "min-width : 100;"
                             "min-height : 30;"
                             "border-radius: 15px;"
                             "}"
        );
        msgbox.exec();
    }
}

void Dialog::on_pushButton_13_clicked()
{
    QString message = ui->textEdit_3->toPlainText().trimmed();

    // Only send the text to the chat server if it's not empty:
    if(!message.isEmpty())
    {
        socket->write(QString(message + "\n").toUtf8());
    }

    // Clear out the input box so they can type something else:
    ui->textEdit_3->clear();

    // Put the focus back into the input box so they can type again:
    ui->textEdit->setFocus();
}


void Dialog::readyRead()
{
    // We'll loop over every (complete) line of text that the server has sent us:
    while(socket->canReadLine())
    {
        // Here's the line the of text the server sent us (we use UTF-8 so
        // that non-English speakers can chat in their native language)
        QString line = QString::fromUtf8(socket->readLine()).trimmed();

        // These two regular expressions describe the kinds of messages
        // the server can send us:

        //  Normal messges look like this: "username:The message"
        QRegExp messageRegex("^([^:]+):(.*)$");

        // Any message that starts with "/users:" is the server sending us a
        // list of users so we can show that list in our GUI:
        //QRegExp usersRegex("^/users:(.*)$");

        // Is this a users message:
        if(messageRegex.indexIn(line) != -1)
        {
            // If so, append this message to our chat box:
            QString user = messageRegex.cap(1);
            QString message = messageRegex.cap(2);

            ui->textEdit_2->append("<b>" + user + "</b>: " + message);
        }
    }
}

void Dialog::connected()
{
    // Flip over to the chat page:
    //stackedWidget->setCurrentWidget(chatPage);

    // And send our username to the chat server.
    QSqlQuery query;
    query.prepare("SELECT USERNAME FROM EMPLOYE WHERE IDE=:ide");
    query.bindValue(":ide",7);
    query.exec();
    query.next();
    socket->write(QString("/me:" + query.value(0).toString() + "\n").toUtf8());
}

void Dialog::on_pushButton_2ms_2_clicked()
{
    qDebug() << "test";
    ui->stackedWidget->setCurrentIndex(20);

    QSqlQuery query;

    query.exec("select count(*) FROM SERIE_FILM");
    query.next();
    //*set0 << query.value(0).toInt();
    int totalSum =query.value(0).toInt();



    QBarSet *set1= new QBarSet("HORROR");
    query.exec("select count(*) FROM SERIE_FILM where MCATE = 'horror' OR SCATE = 'horror'");
    query.next();
    *set1 << query.value(0).toInt();



    QBarSet *set2= new QBarSet("sci-fi");
    query.exec("select count(*) FROM SERIE_FILM where MCATE = 'sci-fi' OR SCATE = 'sci-fi'");
    query.next();
    *set2 << query.value(0).toInt();

    QBarSet *set3= new QBarSet("romance");
    query.exec("select count(*) FROM SERIE_FILM where MCATE = 'romance' OR SCATE = 'romance'");
    query.next();
    *set3 << query.value(0).toInt();

    QBarSet *set4= new QBarSet("sports");
    query.exec("select count(*) FROM SERIE_FILM where MCATE = 'sports' OR SCATE = 'sports'");
    query.next();
    *set4 << query.value(0).toInt();

    QBarSet *set5= new QBarSet("action");
    query.exec("select count(*) FROM SERIE_FILM where MCATE = 'action' OR SCATE = 'action'");
    query.next();
    *set5 << query.value(0).toInt();

    QBarSet *set6= new QBarSet("comedy");
    query.exec("select count(*) FROM SERIE_FILM where MCATE = 'comedy' OR SCATE = 'comedy'");
    query.next();
    *set6 << query.value(0).toInt();

    QBarSet *set7= new QBarSet("drama");
    query.exec("select count(*) FROM SERIE_FILM where MCATE = 'drama' OR SCATE = 'drama'");
    query.next();
    *set7 << query.value(0).toInt();

    QBarSeries *series= new QBarSeries();
    //series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);
    series->append(set5);
    series->append(set6);
    series->append(set7);
    series->setLabelsFormat("@value test");
    for (QBarSet *barSet : series->barSets()) {
        for (int i = 0; i < barSet->count(); ++i) {
            // Calculate percentage
            float percentage = (barSet->at(i) / totalSum) * 100.0;
            // Set the percentage value
            /*for (int j = 0; j < barSet->count(); ++j) {
            qreal value = barSet->at(j);
            QString label = QString::number(value);
            QBarSetItem *barItem = barSet->at(j);
            QPointF point = barSet-> //barItem->geometry().center();
            chart->addAxis(axisY, Qt::AlignLeft); // Attach Y-axis to the chart
            QGraphicsSimpleTextItem *textItem = chart->scene()->addSimpleText(label);
            textItem->setPos(point.x() - textItem->boundingRect().width() / 2, point.y() - 20); // Position text above the bar
*/
            barSet->replace(i,floor( percentage*10)/10);
            QString label = QString::number(barSet->at(i)); // Assuming values are numeric
            barSet->setLabel(barSet->label() + " "+label+"%");
        }
    }
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("test");
    chart->setAnimationOptions(QChart::AllAnimations);
    QStringList categories;
    categories<<"all    movies";
    QBarCategoryAxis *axis=new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis,series);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    QChartView *view = new QChartView(chart,this);

    view->setRenderHint(QPainter::Antialiasing);
    ui->groupBox_2->layout()->addWidget(view);

    connect(ui->stackedWidget, &QStackedWidget::currentChanged,this , [this,view]()
    {
         ui->groupBox_2->layout()->removeWidget(view);
    });
    /*connect(ui->pushButton_4, &QPushButton::clicked, this, [this,view]() {
        ui->groupBox_2->layout()->removeWidget(view);


    });*/
}

void Dialog::on_hihi_36_clicked()//pdf transaction
{
    QString filePath = QFileDialog::getSaveFileName(nullptr, "Export to PDF", "", "PDF files (*.pdf)");
        if (filePath.isEmpty())
            return; // Cancel export if no file is selected

        // Create a QPrinter object to generate the PDF file
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(filePath);

        QPainter painter;
        if (!painter.begin(&printer)) {
            QMessageBox::warning(nullptr, "Error", "Cannot start printing");
            return;
        }

        // Define the size of the table cells
        int cellWidth = 140; // Adjust as needed
        int cellHeight = 30; // Adjust as needed

        // Background Image
        QPixmap background("backgroundpdf.png");
        QRect backgroundRect(0, 0, printer.pageRect().width(), printer.pageRect().height());
        painter.drawPixmap(backgroundRect, background);

        // Title
        QFont titleFont = painter.font();
        titleFont.setPointSize(24);
        painter.setFont(titleFont);
        QColor originalColor = painter.pen().color();
        painter.setPen(QColor(0, 0, 139));
        QRect titleRect(0, 120, printer.pageRect().width(), 50);
        painter.drawText(titleRect, Qt::AlignCenter, "Transaction List");
        painter.setPen(originalColor);

        // Draw column headers in the PDF file
        QStringList headers = {"Transaction number", "Type", "Amount", "Transaction Date"};
        int colCount = headers.size();
        QFont font = painter.font();
        font.setPointSize(12);
        font.setBold(true);
        painter.setFont(font);
        for (int col = 0; col < colCount; ++col) {
            painter.drawText(col * cellWidth, 300, cellWidth, cellHeight, Qt::AlignCenter, headers[col]); // Adjusted position
            painter.drawRect(col * cellWidth, 300, cellWidth, cellHeight);
        }

        // Initialize and execute database query
        QSqlQuery query;
        query.prepare("SELECT IDTRANSACTION, TYPE, MONTANT, DATET FROM TRANSACTION");
        if (!query.exec()) {
            QMessageBox::critical(nullptr, "Error", "Error retrieving data from the database.");
            return;
        }

        // Draw table data in the PDF file
        int row = 0;
        while (query.next()) {
            for (int col = 0; col < colCount; ++col) {
                QString text = query.value(col).toString();
                painter.drawText(col * cellWidth, 330 + (row + 1) * cellHeight, cellWidth, cellHeight, Qt::AlignCenter, text); // Adjusted position
                painter.drawRect(col * cellWidth, 330 + (row + 1) * cellHeight, cellWidth, cellHeight);
            }
            ++row;
        }

        // Export Date
        QDateTime currentDateTime = QDateTime::currentDateTime();
        painter.drawText(printer.pageRect().width() - 150, printer.pageRect().bottom() - 20, currentDateTime.toString("dd.MM.yyyy"));

        // End drawing
        painter.end();

        QMessageBox::information(nullptr, "Success", "Data has been successfully exported to " + filePath);
}


void Dialog::on_hihi_10tr_4_clicked()//stats trans
{
    QSqlQuery query;

        QBarSet *set0= new QBarSet("total transactions");
        query.exec("select count(*) FROM TRANSACTION");
        query.next();
        *set0 << query.value(0).toInt();

        QBarSet*set1= new QBarSet("Checks");
        query.exec("select count(*) FROM TRANSACTION where TYPE = 'Checks'");
        query.next();
        *set1 << query.value(0).toInt();



        QBarSet*set2= new QBarSet("carte bancaire");
        query.exec("select count(*) FROM TRANSACTION where TYPE = 'Card/Visa'");
        query.next();
        *set2 << query.value(0).toInt();

        QBarSet*set3= new QBarSet("Cash");
        query.exec("select count(*) FROM TRANSACTION where TYPE = 'Cash'");
        query.next();
        *set3 << query.value(0).toInt();


        QBarSeries*series= new QBarSeries();
        series->append(set0);
        series->append(set1);
        series->append(set2);
        series->append(set3);
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Statistics by transaction type");
        chart->setAnimationOptions(QChart::AllAnimations);
        QStringList categories;
        categories<<"";
        QBarCategoryAxis*axis=new QBarCategoryAxis();
        axis->append(categories);
        chart->createDefaultAxes();
        chart->setAxisX(axis,series);
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);
        QChartView *view = new QChartView(chart,this);

        view->setRenderHint(QPainter::Antialiasing);
        ui->groupBox_3->layout()->addWidget(view);

        ui->stackedWidget->setCurrentIndex(21);
        connect(ui->stackedWidget, &QStackedWidget::currentChanged,this , [this,view]()
            {
                 ui->groupBox_3->layout()->removeWidget(view);
            });
}




void Dialog::on_pushButton_12_clicked()
{
    emit ui->hihi_15->click();
}

void Dialog::on_hihi_10tr_3_clicked()
{
    // Spécifiez le chemin complet du fichier
     QString filePath = "logs.txt";

     QFile file(filePath);
     if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
         // Afficher un message d'erreur si l'ouverture du fichier échoue
         QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir le fichier historique : " + file.errorString());
         return;
     }

     // Lire le contenu du fichier historique
     QString historique = file.readAll();

     file.close();

     // Créer un widget QTextEdit pour afficher le contenu
     QTextEdit *textEdit_4 = new QTextEdit(this);
     textEdit_4->setText(historique);

     // Définir la taille du QTextEdit
     textEdit_4->setMinimumSize(1200, 800);

     // Afficher le contenu dans une boîte de dialogue
     QMessageBox messageBox;
     messageBox.setWindowTitle("transaction logs");
     messageBox.setIcon(QMessageBox::Information);
     messageBox.setText("transaction logs");
     messageBox.setInformativeText("this is the transaction logs");
     messageBox.setStandardButtons(QMessageBox::Ok);
     messageBox.setDefaultButton(QMessageBox::Ok);
     messageBox.setDetailedText(historique);
     messageBox.setSizeIncrement(1200, 800);

     QVBoxLayout *layout = new QVBoxLayout;
     layout->addWidget(textEdit_4);
     messageBox.setLayout(layout);

     messageBox.exec();
}

void Dialog::on_statisticsM_clicked()
{
     ui->stackedWidget->setCurrentIndex(22);
     updateChartMedia();
}

void Dialog::on_pushButton_14A_8_clicked()
{
     diffusion d;
    int numSalle = ui->lineEdit_3A_10->text().toInt();
    int capacite = ui->lineEdit_3A_7->text().toInt();
    QDate date = ui->dateTimeEdit_3->date();

    if (d.isNumSallRepeated(numSalle)) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("This number already exists.\n"
                                          "Please enter another number."),
                              QMessageBox::Ok);
        return;
    }

        if (d.isStudioReserved(date)) {
            QMessageBox::warning(this, "Error", "Studio is already reserved at that time", QMessageBox::Ok);
            return;
        }

    bool test = d.ajoutSalle(numSalle, capacite,etat, date);
    if (!test) {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("The addition was not made.\n"
                                          "Please try again."),
                              QMessageBox::Ok);
        return; // Arrêter l'exécution de la fonction si l'ajout n'est pas réussi
    }

    QMessageBox::information(nullptr, QObject::tr("OK"),
                             QObject::tr("Addition is validated.\n"
                                         "Click OK to exit."),
                             QMessageBox::Ok);

    emit ui->pushButton_2A->click();
}
void Dialog::checkReservationDates()
{
    diffusion d;
    // Retrieve the reservation information from the database
    // You can use your existing methods to fetch reservation data
    QSqlQueryModel *model = d.afficherDiffusions();

    // Get current date
    QDate currentDate = QDate::currentDate();

    // Iterate through the reservation data
    for (int row = 0; row < model->rowCount(); ++row) {
        int numSalle = model->index(row, 0).data().toInt();
        QString etat = model->index(row, 2).data().toString();
        QDate dateRes = model->index(row, 3).data().toDate();

        // Calculate time difference between current date and reservation date
        int daysUntilReservation = currentDate.daysTo(dateRes);

        // Check if reservation date is within notification threshold (e.g., 1 day before)
        if (daysUntilReservation == 1) {
            // Trigger system notification
           mSystemTrayIcon->showMessage("Reservation Reminder",
                                         QString("Reservation for Studio %1 is tomorrow.").arg(numSalle),
                                         QSystemTrayIcon::Information,
                                         5000); // Notification duration (ms)

            // Update reservation status to prevent duplicate notifications
           // diffusion::UpdateSalleDiffusion(numSalle, -1, "Notified", dateRes);
        }
    }

    // Clean up
    delete model;
}

void Dialog::on_pushButton_14A_9_clicked()
{
     ui->gg_5->setVisible(false);
     ui->textEdit->setVisible(false);
     ui->gg_2->setVisible(false);
     ui->comboBox_7->setVisible(false);
     ui->comboBox->setVisible(false);
     ui->comboBoxM->setVisible(false);
     ui->label_13->setVisible(false);
     ui->label_41->setVisible(false);
     ui->comboBoxM_2->setVisible(false);
     ui->comboBoxM_3->setVisible(false);
    ui->stackedWidget->setCurrentIndex(9);
    //modifierMedia(QString titre);
    diffusion d;
    int numSalle = ui->lineEdit_3A_14->text().toInt();
    int capacite= ui->lineEdit_3A_11->text().toInt();
    QDate date = ui->dateTimeEdit_4->date();

    // Vérifier si un producteur a été inséré
   /* if (!m.isProducerInserted(producteur)) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Please insert a producer."),
                              QMessageBox::Ok);
        return; // Arrêter l'exécution de la fonction si aucun producteur n'a été inséré
    }
    // Vérifier si la description est valide
        if (!m.isDescriptionValid(description)) {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                  QObject::tr("Description should be less than 200 characters."),
                                  QMessageBox::Ok);
            return; // Arrêter l'exécution de la fonction si la description est trop longue
        }*/
    d.setNumSalle(ui->lineEdit_3A_14->text().toInt());
    d.setCapacite(ui->lineEdit_3A_7->text().toInt());
    d.setDateRes(ui->dateTimeEdit_3->date());
    if (ui->full_2->isChecked())
    {
        d.setEtat("Full");
    }
    if (ui->reserved_2->isChecked())
    {
       d.setEtat("Reserved");
    }
    if (ui->empty_2->isChecked())
    {
       d.setEtat("Empty");
    }

    bool test = d.UpdateSalleDiffusion(numSalle, capacite,etat, date);
    if (!test) {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("The addition was not made.\n"
                                          "Please try again."),
                              QMessageBox::Ok);
    }

    QMessageBox::information(nullptr, QObject::tr("OK"),
                             QObject::tr("Addition is validated.\n"
                                         "Click OK to exit."),
                             QMessageBox::Ok);


    emit ui->pushButton_2A->click();
}

void Dialog::on_searchLineEditM_2_textChanged(const QString &arg1)
{
    QString searchText = arg1.trimmed();
            if (searchText.isEmpty()) {
                // If lineEdit is empty, reset the tableView
                on_pushButton_2A_clicked();
                return;
            }

            QString queryText;

            if (searchText.length() == 1) {
                // If only one letter is entered, search for rows starting with that letter
                queryText = "SELECT NUMSALLE, CAPACITE, ETAT, DATERES FROM SALLE WHERE NUMSALLE LIKE '" + searchText + "%'";
            } else {
                // Otherwise, search for rows containing the complete text
                queryText = "SELECT NUMSALLE, CAPACITE, ETAT, DATERES FROM SALLE WHERE NUMSALLE LIKE '%" + searchText + "%'";
            }

            QSqlQueryModel *model = new QSqlQueryModel();
            model->setQuery(queryText);

            ui->tableviewrr->setModel(model);

}

void Dialog::on_pushButton_14A_10_clicked()
{
    emit ui->pushButton_2A->click();
}

void Dialog::on_pushButton_14A_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}



void Dialog::on_cancelButtonM_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}

void Dialog::on_cancelButtonM_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(13);
}

void Dialog::afficherDateActuelle()
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString formattedDateTime = currentDateTime.toString("dd/MM/yyyy"); // Format de date personnalisé

    // Supposons que vous avez une QLabel nommée labelDate dans votre interface
    ui->label_5A_4->setText(formattedDateTime);
}
void Dialog::afficherHeureActuelle()
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString formattedTime = currentDateTime.toString("h:mm AP"); // Format de l'heure avec AM/PM

    // Supposons que vous avez une QLabel nommée labelHeure dans votre interface
    ui->label_5A_3->setText(formattedTime);
}
void Dialog::calculerNombreSalles()
{
    // Exécutez une requête SQL pour compter le nombre de lignes dans la table "SALLE"
    QSqlQuery query("SELECT COUNT(*) FROM SALLE");

    if (query.exec() && query.next()) {
        int nombreSalles = query.value(0).toInt();
        QString texteNombreSalles = QString::number(nombreSalles);

        // Supposons que vous avez une QLabel nommée labelNombreSalles dans votre interface
        ui->label_6A->setText(texteNombreSalles);
    } else {
        // Gestion de l'erreur si la requête échoue
        qDebug() << "Erreur lors du calcul du nombre de salles : " << query.lastError().text();
    }
}

void Dialog::on_pushButton_3A_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void Dialog::on_pushButton_5A_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void Dialog::on_comboBox_2_currentIndexChanged()
{
    /*QString sortOption = ui->comboBox_2->currentText();
        QSqlQueryModel model = new QSqlQueryModel();

        if (sortOption == "Sorting ASC by studio number")
        {
            model->setQuery("SELECT FROM SALLE ORDER BY numSalle ASC");
        }
        else if (sortOption == "Sorting DESC by studio number")
        {
            model->setQuery("SELECT * FROM SALLE ORDER BY numSalle DESC");
        }

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("numSalle"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("capacite"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("dateRes"));
        model->insertColumn(4);
        model->setHeaderData(4, Qt::Horizontal, QObject::tr(""));

        ui->tableviewrr->setModel(model);*/

}

void Dialog::on_hihi_42_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(nullptr, "Export to PDF", "", "PDF files (*.pdf)");
        if (filePath.isEmpty())
            return; // Cancel export if no file is selected

        // Create a QPrinter object to generate the PDF file
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(filePath);

        QPainter painter;
        if (!painter.begin(&printer)) {
            QMessageBox::warning(nullptr, "Error", "Cannot start printing");
            return;
        }

        // Define the size of the table cells
        int cellWidth = 140; // Adjust as needed
        int cellHeight = 30; // Adjust as needed

        // Background Image
        QPixmap background("backgroundpdf.png");
        QRect backgroundRect(0, 0, printer.pageRect().width(), printer.pageRect().height());
        painter.drawPixmap(backgroundRect, background);

        // Title
        QFont titleFont = painter.font();
        titleFont.setPointSize(24);
        painter.setFont(titleFont);
        QColor originalColor = painter.pen().color();
        painter.setPen(QColor(0, 0, 139));
        QRect titleRect(0, 120, printer.pageRect().width(), 50);
        painter.drawText(titleRect, Qt::AlignCenter, "Studios List");
        painter.setPen(originalColor);

        // Draw column headers in the PDF file
        QStringList headers = {"Studio Number", "State", "Capacity", "Reservation Date"};
        int colCount = headers.size();
        QFont font = painter.font();
        font.setPointSize(12);
        font.setBold(true);
        painter.setFont(font);
        for (int col = 0; col < colCount; ++col) {
            painter.drawText(col * cellWidth, 300, cellWidth, cellHeight, Qt::AlignCenter, headers[col]); // Adjusted position
            painter.drawRect(col * cellWidth, 300, cellWidth, cellHeight);
        }

        // Initialize and execute database query
        QSqlQuery query;
        query.prepare("SELECT NUMSALLE, ETAT, CAPACITE, DATERES FROM SALLE");
        if (!query.exec()) {
            QMessageBox::critical(nullptr, "Error", "Error retrieving data from the database.");
            return;
        }

        // Draw table data in the PDF file
        int row = 0;
        while (query.next()) {
            for (int col = 0; col < colCount; ++col) {
                QString text = query.value(col).toString();
                painter.drawText(col * cellWidth, 330 + (row + 1) * cellHeight, cellWidth, cellHeight, Qt::AlignCenter, text); // Adjusted position
                painter.drawRect(col * cellWidth, 330 + (row + 1) * cellHeight, cellWidth, cellHeight);
            }
            ++row;
        }

        // Export Date
        QDateTime currentDateTime = QDateTime::currentDateTime();
        painter.drawText(printer.pageRect().width() - 150, printer.pageRect().bottom() - 20, currentDateTime.toString("dd.MM.yyyy"));

        // End drawing
        painter.end();

        QMessageBox::information(nullptr, "Success", "Data has been successfully exported to " + filePath);
}

void Dialog::on_hihi_10tr_5_clicked()
{
    QSqlQuery query;

    QBarSet *set0 = new QBarSet("total reservations");
    if (query.exec("SELECT COUNT(*) FROM SALLE"))
    {
        query.next();
        *set0 << query.value(0).toInt();
    }

    QBarSet *set1 = new QBarSet("Empty");
    if (query.exec("SELECT COUNT(*) FROM SALLE WHERE ETAT = 'Empty'"))
    {
        query.next();
        *set1 << query.value(0).toInt();
    }

    QBarSet *set2 = new QBarSet("Full");
    if (query.exec("SELECT COUNT(*) FROM SALLE WHERE ETAT = 'Full'"))
    {
        query.next();
        *set2 << query.value(0).toInt();
    }

    QBarSet *set3 = new QBarSet("Reserved");
    if (query.exec("SELECT COUNT(*) FROM SALLE WHERE ETAT = 'Reserved'"))
    {
        query.next();
        *set3 << query.value(0).toInt();
    }

    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistics by studio state");
    chart->setAnimationOptions(QChart::AllAnimations);

    QStringList categories;
    categories << "";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis, series);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *view = new QChartView(chart, this);
    view->setRenderHint(QPainter::Antialiasing);
    ui->chartContainer->layout()->addWidget(view);

    ui->stackedWidget->setCurrentIndex(8);

    connect(ui->stackedWidget, &QStackedWidget::currentChanged, this, [this, view]() {
        ui->chartContainer->layout()->removeWidget(view);
    });
}
/*void Dialog::initializeCalendar() {
    // Initialize the calendar widget
    ui->calendarWidget->setGridVisible(true); // Show grid lines for better visibility

    // Update the calendar with event dates
    updateCalendarWithEvents();
}*/

void Dialog::updateCalendarWithEvents() {
    diffusion diffusion;
    QList<QDate> eventDates = diffusion.getEventDates();

    foreach (const QDate &date, eventDates) {
        QTextCharFormat format;

        // Remove any existing format for the date
        ui->calendarWidget->setDateTextFormat(date, QTextCharFormat());

        // Set custom background color for the date
        format.setBackground(Qt::red); // Customize the background color
        ui->calendarWidget->setDateTextFormat(date, format);
    }
}

void Dialog::refreshCalendar() {
    ui->calendarWidget->setDateTextFormat(QDate(), QTextCharFormat()); // Clear all existing formats
    updateCalendarWithEvents();
}

void Dialog::on_calendarWidget_clicked(const QDate &date)
{
    diffusion d;
           QStringList eventInfo = d.GetSalleInformationForDate(date);

           QString labelText = "Event Information:\n";
           if (!eventInfo.isEmpty()) {
               labelText += "Capacity: " + eventInfo[0] + "\n";
               labelText += "State: " + eventInfo[1] + "\n";
               labelText += "Date: " + eventInfo[2] + "\n";
           } else {
               labelText += "No event scheduled for this date.";
           }
           ui->label_8A->setText(labelText);
}
void Dialog::updateChartMedia() {
    QSqlQuery query;

    // Récupérer le nombre total de médias pour le calcul des pourcentages
    query.prepare("SELECT COUNT(*) FROM MEDIA");
    if (query.exec() && query.next()) {
        qreal totalCount = query.value(0).toDouble(); // Total count of all media items

        // Sélectionner les types de médias et compter leur nombre
        query.prepare("SELECT type, COUNT(*) FROM MEDIA GROUP BY type");
        if (query.exec()) {
            seriesE = new QPieSeries();

            while (query.next()) {
                qreal mediaCount = query.value(1).toDouble();
                qreal percentage = (mediaCount / totalCount) * 100;
                QString mediaType = query.value(0).toString();
                QString label = QString("%1: %2%").arg(mediaType).arg(QString::number(percentage, 'f', 2)); // Rounded to 2 decimal places
                QPieSlice *slice = seriesE->append(label, mediaCount);
                slice->setLabelVisible(true);
                slice->setLabelColor(Qt::black); // Set label color
            }

            qDebug() << "Data count:" << seriesE->count();

            // Créer et configurer le graphique pie
            QFont titleFont;
            titleFont.setPointSize(16);
            chartE = new QChart();
            chartE->addSeries(seriesE);
            chartE->setTitleFont(titleFont);
            chartE->setTitle("Media statistics by type");

            // Créer la vue du graphique
            auto chartViewM = new QChartView(chartE);
            chartViewM->setRenderHint(QPainter::Antialiasing); // Improve rendering quality
            chartViewM->resize(800, 600); // Resize the chart view

            // Définir la disposition de la vue du graphique dans le widget
            //QVBoxLayout *layout = new QVBoxLayout;

            ui->StatMedia->layout()->addWidget(chartViewM);
            //ui->StatMedia->setLayout(layout);
            connect(ui->stackedWidget, &QStackedWidget::currentChanged, this, [this ,chartViewM]() {
                ui->StatMedia->layout()->removeWidget(chartViewM);
            });
        } else {
            qDebug() << "Error executing query for media types count.";
        }
    } else {
        qDebug() << "Error executing query for total media count.";
    }
}
void Dialog::afficherGifDansLabel() {
    QString cheminGif = "gifM.gif"; // Remplacez par le chemin de votre GIF
    QLabel *gifLabel = ui->gifLabel; // Supposons que vous ayez une QLabel nommée "gifLabel" dans votre interface utilisateur

    // Appeler la fonction pour afficher le GIF dans la QLabel
    afficherGifDansLabel(cheminGif, gifLabel);
}

void Dialog::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(25);
    ui->textEdit->setVisible(true);
}
void Dialog::onTypingTimerTimeout()
{
    // Arrêter le timer s'il est actif
    typingTimer->stop();

    // Récupérer le texte depuis le QLineEdit TitleM
    QString spokenText = ui->TitleM->text();

    // Appeler la fonction say() du QTextToSpeech pour lire le texte
    textToSpeech->say(spokenText);
}
void Dialog::startTimer() {
    typingTimer->start(3000);  // 1 minute (60000 ms)
}

// Ajoutez cette fonction pour lire le texte après que le timer expire
void Dialog::readText() {
    QString spokenText = ui->TitleM->text();
    textToSpeech->say(spokenText);
}

// Modifiez la fonction on_TitleM_textChanged comme suit
void Dialog::on_TitleM_textChanged(const QString &arg1)
{
    // Arrêter le timer s'il est actif
    typingTimer->stop();

    // Démarrer le timer avec un délai de 1 minute
    startTimer();
}
void Dialog::readTextProducer() {
    QString spokenText = ui->ProducerM->text();
    textToSpeech->say(spokenText);
}
void Dialog::on_ProducerM_textChanged(const QString &arg1)
{
    // Arrêter le timer s'il est actif
    typingTimer->stop();

    // Démarrer le timer avec un délai de 1 minute
    startTimer();
}
void Dialog::readTextDescrption() {
    QString spokenText = ui->textEditM->toPlainText();
    textToSpeech->say(spokenText);
}
void Dialog::on_textEditM_textChanged()
{
    // Arrêter le timer s'il est actif
    typingTimer->stop();

    // Démarrer le timer avec un délai de 1 minute
    startTimer();
}

void Dialog::on_listM_2_clicked()
{
    on_listM_clicked();
}





void Dialog::on_comboBoxM_2_currentIndexChanged(const QString &arg1)
{
    emit ui->pushButton_2A->clicked();
}

void Dialog::on_exportButtonM_2_clicked()
{
    int xStart = 20; // Starting x-coordinate for the table
    int yStart = 100; // Starting y-coordinate for the table
    int rowHeight = 200; // Height of each row
    int colWidth = 280; // Width of each column
    int rowCount = 0;

    QString filePath = QFileDialog::getSaveFileName(nullptr, "Exporter vers PDF", "", "Fichiers PDF (*.pdf)");
    if (filePath.isEmpty())
        return; // Annuler l'exportation si aucun fichier n'a été sélectionné

    // Créer un objet QPrinter pour générer le fichier PDF
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(filePath);

    // Créer un objet QPainter pour dessiner sur le périphérique d'impression
    QPainter painter;
    if (!painter.begin(&printer)) {
        QMessageBox::warning(nullptr, "Erreur", "Cannot initialize the print device.");
        return;
    }

    QPixmap background("backgroundpdf.png");
    QRect backgroundRect(0, 0, printer.pageRect().width(), printer.pageRect().height());
    painter.drawPixmap(backgroundRect, background);

    QSqlQuery query;
    query.exec("SELECT ID,TITRE,TYPE,DESCRIPTION,DUREE, NBREP,NBRVUE,MCATE , SCATE, IMAGE from SERIE_FILM");

    QFont titleFont = painter.font();
    titleFont.setFamily("CENTURY");
    painter.setPen(Qt::darkBlue);
    titleFont.setPointSize(24);
    painter.setFont(titleFont);

    QString ch = "List Of Movies/Series";
    painter.drawText(220, 50, ch);
    ch.resize(500);

    QFont defaultFont = painter.font();
    defaultFont.setFamily("ARIAL");
    painter.setPen(Qt::black);
    defaultFont.setPointSize(12);
    painter.setFont(defaultFont);

    while (query.next())
    {


        painter.drawLine(xStart, yStart + rowCount * rowHeight, xStart + 2 * colWidth, yStart + rowCount * rowHeight);
        painter.drawLine(xStart, yStart + (rowCount + 1) * rowHeight, xStart + 2 * colWidth, yStart + (rowCount + 1) * rowHeight);
        painter.drawLine(xStart + colWidth, yStart + rowCount * rowHeight, xStart + colWidth, yStart + (rowCount + 1) * rowHeight);
        painter.drawLine(xStart + 2 * colWidth, yStart + rowCount * rowHeight, xStart + 2 * colWidth, yStart + (rowCount + 1) * rowHeight);

        painter.drawText(xStart + 10, yStart + rowCount * rowHeight + 30, "ID: " + query.value(0).toString());
        painter.drawText(xStart + 10, yStart + rowCount * rowHeight + 50, "Title: " + query.value(1).toString());
        painter.drawText(xStart + 10, yStart + rowCount * rowHeight + 70, "Type: " + query.value(2).toString());
        painter.drawText(xStart + 10, yStart + rowCount * rowHeight + 90, "Description:" + query.value(3).toString());
        painter.drawText(xStart + 10, yStart + rowCount * rowHeight + 110, "Duration : " + query.value(4).toString());
        painter.drawText(xStart + 10, yStart + rowCount * rowHeight + 130, "Numbre of episodes: " + query.value(5).toString());
        painter.drawText(xStart + 10, yStart + rowCount * rowHeight + 150, "Number of views: " + query.value(6).toString());
        painter.drawText(xStart + 10, yStart + rowCount * rowHeight + 170, "Categorie: " + query.value(7).toString() + " " + query.value(8).toString());

        if (!query.value(9).isNull())
        {
            QByteArray array;
            array = query.value(9).toByteArray();
            QPixmap pixmap;
            pixmap.loadFromData(array, "JPG && PNG", Qt::AutoColor);

            QPixmap scaled = pixmap.scaled(QSize(180, 180));
            painter.drawPixmap(xStart + colWidth + 20, yStart + rowCount * rowHeight + 15, scaled);
        }


        rowCount++;


        if (rowCount * rowHeight + yStart + 100 + 170 > 850)
        {
            qDebug() << "Page added";
            printer.newPage();
            rowCount = 0;
            painter.drawPixmap(backgroundRect, background); // Redraw background on new page
            QPixmap background("backgroundpdf.png");
            QRect backgroundRect(0, 0, printer.pageRect().width(), printer.pageRect().height());
            painter.drawPixmap(backgroundRect, background);

        }
    }

    QString signature = "Date:" + QDate::currentDate().toString("dd/MM/yyyy");
    painter.drawText(0, printer.pageRect().bottom() - 20, signature);

    painter.end();

    QMessageBox::information(nullptr, "Successful", "Data has been successfully exported to " + filePath);
}

void Dialog::on_loM_2_clicked()
{
    qDebug()<<"click";
    ui->stackedWidget->setCurrentIndex(15);
}

void Dialog::on_hihi_10tr_6_clicked()
{
    qDebug() << "test";
    ui->stackedWidget->setCurrentIndex(20);

    QSqlQuery query;

    query.exec("select count(*) FROM SERIE_FILM");
    query.next();
    //*set0 << query.value(0).toInt();
    int totalSum =query.value(0).toInt();



    QBarSet *set1= new QBarSet("HORROR");
    query.exec("select count(*) FROM SERIE_FILM where MCATE = 'horror' OR SCATE = 'horror'");
    query.next();
    *set1 << query.value(0).toInt();



    QBarSet *set2= new QBarSet("sci-fi");
    query.exec("select count(*) FROM SERIE_FILM where MCATE = 'sci-fi' OR SCATE = 'sci-fi'");
    query.next();
    *set2 << query.value(0).toInt();

    QBarSet *set3= new QBarSet("romance");
    query.exec("select count(*) FROM SERIE_FILM where MCATE = 'romance' OR SCATE = 'romance'");
    query.next();
    *set3 << query.value(0).toInt();

    QBarSet *set4= new QBarSet("sports");
    query.exec("select count(*) FROM SERIE_FILM where MCATE = 'sports' OR SCATE = 'sports'");
    query.next();
    *set4 << query.value(0).toInt();

    QBarSet *set5= new QBarSet("action");
    query.exec("select count(*) FROM SERIE_FILM where MCATE = 'action' OR SCATE = 'action'");
    query.next();
    *set5 << query.value(0).toInt();

    QBarSet *set6= new QBarSet("comedy");
    query.exec("select count(*) FROM SERIE_FILM where MCATE = 'comedy' OR SCATE = 'comedy'");
    query.next();
    *set6 << query.value(0).toInt();

    QBarSet *set7= new QBarSet("drama");
    query.exec("select count(*) FROM SERIE_FILM where MCATE = 'drama' OR SCATE = 'drama'");
    query.next();
    *set7 << query.value(0).toInt();

    QBarSeries *series= new QBarSeries();
    //series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);
    series->append(set5);
    series->append(set6);
    series->append(set7);
    series->setLabelsFormat("@value test");
    for (QBarSet *barSet : series->barSets()) {
        for (int i = 0; i < barSet->count(); ++i) {
            // Calculate percentage
            float percentage = (barSet->at(i) / totalSum) * 100.0;
            // Set the percentage value
            /*for (int j = 0; j < barSet->count(); ++j) {
            qreal value = barSet->at(j);
            QString label = QString::number(value);
            QBarSetItem *barItem = barSet->at(j);
            QPointF point = barSet-> //barItem->geometry().center();
            chart->addAxis(axisY, Qt::AlignLeft); // Attach Y-axis to the chart
            QGraphicsSimpleTextItem *textItem = chart->scene()->addSimpleText(label);
            textItem->setPos(point.x() - textItem->boundingRect().width() / 2, point.y() - 20); // Position text above the bar
*/
            barSet->replace(i,floor( percentage*10)/10);
            QString label = QString::number(barSet->at(i)); // Assuming values are numeric
            barSet->setLabel(barSet->label() + " "+label+"%");
        }
    }
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("test");
    chart->setAnimationOptions(QChart::AllAnimations);
    QStringList categories;
    categories<<"all    movies";
    QBarCategoryAxis *axis=new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis,series);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    QChartView *view = new QChartView(chart,this);

    view->setRenderHint(QPainter::Antialiasing);
    ui->groupBox_2->layout()->addWidget(view);

    connect(ui->stackedWidget, &QStackedWidget::currentChanged,this , [this,view]()
    {
         ui->groupBox_2->layout()->removeWidget(view);
    });
}
