#include "dialog.h"
#include "ui_dialog.h"
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
using namespace QtCharts;
QPieSeries *seriesE;
QChart *chartE;
QChartView *chartViewE;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{

    ui->setupUi(this);
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
    ui->comboBox_2->setVisible(false);
ui->stackedWidget->setCurrentIndex(0);
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
    //Media
    connect(ui->imageButtonM, &QPushButton::clicked, this, &Dialog::importImage);
    connect(ui->radioButtonM, &QRadioButton::clicked, this, [=]() {
        type = "Radio";
    });

/*<<<<<<< HEAD
=======

>>>>>>> d265fca64f07effaee8f719cf8afeb9a3d75cd6a*/
    connect(ui->radioButton_2M, &QRadioButton::clicked, this, [=]() {
        type = "Channel";
    });
    //connect(ui->addButtonM, &QPushButton::clicked, this, &MainWindow::importImage);

    Media media;
    statistiqueMedia();
    //ui->tableViewM->setModel(media.afficherMedia());
    connect(ui->exportButtonM, &QPushButton::clicked, [this]() {
      on_exportButtonM_clicked();
    });
    connect(ui->comboBoxM, &QComboBox::currentTextChanged, this, &Dialog::on_listM_clicked);
    ui->TitleM->setValidator(new QRegExpValidator(QRegExp("[A-Za-z ]+"), this));
    ui->ProducerM->setValidator(new QRegExpValidator(QRegExp("[A-Za-z ]+"), this));
    textToSpeech = new QTextToSpeech(this);
    typingTimer = new QTimer(this);
    vcmode=0;

    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(vcommand())); // permet de lancer
        vcmode=1;
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }


}



void Dialog::vcommand()
{
    data=A.read_from_arduino();
    qDebug()<<data;


    if(data=="1")
    {
        if (vcmode==1)
            ui->stackedWidget->setCurrentIndex(1);

    }

        //ui->label_3->setText("ON"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON

    else if (data=="2")
     {
        if (vcmode==1)
            ui->stackedWidget->setCurrentIndex(2);

     }
    else if (data=="3")
    {
        if (vcmode==1)
            ui->stackedWidget->setCurrentIndex(6);
    }
    else if (data=="4")
    {
        if (vcmode==1)
            ui->stackedWidget->setCurrentIndex(7);
    }
    else if (data=="5")
    {
        if (vcmode==1)
            close();
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
        chartE->setTitle("Statistique des Employes par types");
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
        ui->textEdit->setVisible(true);
        ui->gg_5->setVisible(true);
        ui->gg_2->setVisible(true);
        ui->label_47->setVisible(true);
        ui->label_48->setVisible(true);
}

void Dialog::on_hihi_5_clicked()//crud employe
{
    int ligne(0);
            QString rech;
        int row(0);
        QSqlQuery query;
    ui->stackedWidget->setCurrentIndex(1);
    ui->label_6->setGeometry(15,305,51,20);
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

        QStandardItemModel * model=new QStandardItemModel(ligne , 11);
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
        model->setHeaderData(8, Qt::Horizontal , "QR code");
        model->setHeaderData(9, Qt::Horizontal , "delete");
        model->setHeaderData(10, Qt::Horizontal , "update");
        ui->tableViewem->setModel(model);

        for (int j=0;j<row ; j++)
        {
            QPushButton *butt;
            butt = new QPushButton("QR code");
            QString name = QString("buttondel%1").arg(j) ;
            QString display = QString("QR code") ;
            butt->setObjectName(name) ;
            butt->setText(display) ;

            connect(butt, &QPushButton::clicked, this, [this, j]() {
                employer e;
                QString idme = ui->tableViewem->model()->data(ui->tableViewM->model()->index(j, 0)).toString();
                e.generateQRCodeEmploye(idme);
            });

            butt->setStyleSheet("color:red;"
                                "background:transparent;"
                                "border:none;"
                                "font : 15pt;");
            ui->tableViewem->setIndexWidget(model->index(j, 8), butt);
            butt = new QPushButton("delete");
            name = QString("buttondel%1").arg(j) ;
            display = QString("delete") ;
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
            ui->tableViewem->setIndexWidget(model->index(j, 9), butt);

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
            ui->tableViewem->setIndexWidget(model->index(j, 10), butt);
        }
        ui->tableViewem->verticalHeader()->setVisible(false);
            ui->tableViewem->resizeRowsToContents();
            ui->tableViewem->resizeColumnsToContents();
            ui->tableViewem->show();

}

void Dialog::on_hihi_15_clicked()//crud transaction
{

    ui->stackedWidget->setCurrentIndex(2);
    ui->label_6->setGeometry(15,370,51,20);
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
        qs="select IDTRANSACTION , DATET ,TYPE , MONTANT from TRANSACTION";
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

}

void Dialog::on_hihi_37_clicked()//modifytransaction button
{
    ui->stackedWidget->setCurrentIndex(5);
    ui->textEdit->setVisible(false);
    ui->gg_5->setVisible(false);
    ui->gg_2->setVisible(false);
    ui->label_47->setVisible(false);
    ui->label_48->setVisible(false);
}

void Dialog::on_hihi_20_clicked()//tvmoviesidfk
{
    ui->stackedWidget->setCurrentIndex(6);
    ui->label_6->setGeometry(15,430,51,20);
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
                    query.bindValue(":date",ui->dateTimeEdit->dateTime());
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
        query.bindValue(":date",ui->dateTimeEdit_2->dateTime());
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
}

void Dialog::on_pushButton_14A_7_clicked()//another cancel button trans(update trans)
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Dialog::on_hihi_17_clicked()//reservation
{
    ui->label_6->setGeometry(15,490,51,20);
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

}

void Dialog::on_pushButton_10_clicked()//calender
{
    ui->pushButton_10->lower();
    ui->mainbox->lower();
}

void Dialog::on_pushButton_7_clicked()
{
    ui->pushButton_7->lower();
    ui->mainbox->lower();
}

void Dialog::on_pushButton_5_clicked()
{
    ui->pushButton_5->lower();
    ui->mainbox->lower();
}
void Dialog::on_pushButton_9_clicked()
{
    ui->pushButton_9->lower();
    ui->mainbox->lower();
}

void Dialog::on_pushButton_11_clicked()
{
    ui->pushButton_11->lower();
    ui->mainbox->lower();
}

void Dialog::on_pushButton_8_clicked()
{
    ui->pushButton_8->lower();
    ui->mainbox->lower();
}

void Dialog::on_pushButton_6_clicked()
{
    ui->pushButton_6->lower();
    ui->mainbox->lower();
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
                    query.prepare("insert into EMPLOYE (cin , username , password , nom , prenom , type , photo , ids , tel , email) values (:cin , :username , :password , :nom , :prenom , :type , :photo,:ids, :tel , :email)");
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
    ui->stackedWidget->setCurrentIndex(1);
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
        query.prepare("UPDATE EMPLOYE set cin=:cin , username=:username , password=:password , nom=:nom , prenom=:prenom , type=:type , photo=:photo , tel=:tel , email=:email where ide=:id");
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
    ui->gg_5->setVisible(true);
    ui->gg_2->setVisible(true);
    ui->label_47->setVisible(true);
    ui->label_48->setVisible(true);
}

void Dialog::on_pushButton_2A_clicked()//crud reservation
{
    ui->stackedWidget->setCurrentIndex(9);
    ui->label_15->setVisible(false);
    ui->comboBox->setVisible(false);
    ui->textEdit->setVisible(true);
    ui->gg_5->setVisible(true);
    ui->gg_2->setVisible(true);
    ui->label_47->setVisible(true);
    ui->label_48->setVisible(true);
}

void Dialog::on_hihi_43_clicked()//add reservation
{
    ui->stackedWidget->setCurrentIndex(10);
    ui->label_15->setVisible(false);
    ui->comboBox->setVisible(false);
    ui->textEdit->setVisible(false);
    ui->gg_5->setVisible(false);
    ui->gg_2->setVisible(false);
    ui->label_47->setVisible(false);
    ui->label_48->setVisible(false);
}

void Dialog::on_listM_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
    int ligne(0);
    int row(0);
    QSqlQuery query;
    query.exec("SELECT COUNT(*) FROM MEDIA");
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

    query.exec("SELECT IDM,TITRE, DESCRIPTION, IMAGE, PRODUCTEUR, TYPE FROM MEDIA"+Qs);
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
        ui->IDM->setText(ui->tableViewM->model()->data(ui->tableViewM->model()->index(j, 0)).toString());
        ui->TitleM->setText(ui->tableViewM->model()->data(ui->tableViewM->model()->index(j, 1)).toString());
        ui->textEditM->setText(ui->tableViewM->model()->data(ui->tableViewM->model()->index(j, 2)).toString());
        ui->ProducerM->setText(ui->tableViewM->model()->data(ui->tableViewM->model()->index(j, 4)).toString());
        QPixmap pixmap = ui->tableViewM->model()->data(ui->tableViewM->model()->index(j, 3), Qt::DecorationRole).value<QPixmap>();
         ui->labelM->setPixmap(pixmap);
         if (ui->tableViewM->model()->data(ui->tableViewM->model()->index(j, 5)).toString()=="Radio")
                 ui->radioButtonM->setChecked(true);
          if (ui->tableViewM->model()->data(ui->tableViewM->model()->index(j, 5)).toString()=="Channel")
                        ui->radioButton_2M->setChecked(true);
          ui->stackedWidget->setCurrentIndex(12);

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
    QString titre = ui->TitleM->text();
    QString producteur = ui->ProducerM->text();
    QString description = ui->textEditM->toPlainText();


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
    m.setTitre(ui->TitleM->text());
    m.setProducteur(ui->ProducerM->text());
    m.setDescription(ui->textEditM->toPlainText());
    if (ui->radioButtonM->isChecked())
    {
        m.setType("Radio");
    }
    if (ui->radioButton_2M->isChecked())
    {
        m.setType("Channel");
    }
    m.setImage(imageByteArray);

    // Ajouter le média si toutes les vérifications sont passées avec succès
    bool test = m.modifierMedia(ui->IDM->text().toInt());
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
    // Ouvrir une boîte de dialogue pour sélectionner l'emplacement de sauvegarde du fichier PDF
    QString filePath = QFileDialog::getSaveFileName(nullptr, "Export to PDF", "", "PDF files (*.pdf)");
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

    // Récupérer les données de la table Media depuis la base de données
    QSqlQuery query;
    query.prepare("SELECT IDM, TITRE, DESCRIPTION, IMAGE, PRODUCTEUR, TYPE, DATEM FROM MEDIA");
    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Error", "Error retrieving data from database.");
        return;
    }

    // Définir la taille des cellules du tableau
    int cellWidth = 80;
    int cellHeight = 50;
    int row = 0;

    QFont titleFont = painter.font();
    painter.drawText(250, 10, "Media list"); // Dessiner le titre à la position spécifiée

    // Dessiner les en-têtes de colonne dans le fichier PDF
    QStringList headers = {"IDM", "Title", "Description", "Image", "Producer", "Type", "Date of creation"};
    int colCount = headers.size();
    QFont font = painter.font(); // Récupérer la police par défaut pour le texte
    font.setBold(true);
    painter.setFont(font);
    for (int col = 0; col < colCount; ++col) {
        painter.drawText(col * cellWidth, 50, cellWidth, cellHeight, Qt::AlignCenter, headers[col]);
        painter.drawRect(col * cellWidth, 50, cellWidth, cellHeight);
    }

    // Dessiner les données de la table dans le fichier PDF
    while (query.next()) {
        for (int col = 0; col < colCount; ++col) {
            QString text = query.value(col).toString();
            if (col == 5) { // Colonne du type
                painter.drawText(col * cellWidth, (row + 2) * cellHeight, cellWidth, cellHeight, Qt::AlignCenter, text);
            } else if (col == 3) { // Colonne de l'image
                QByteArray imageData = query.value(col).toByteArray();
                QPixmap pixmap;
                pixmap.loadFromData(imageData);
                painter.drawPixmap(col * cellWidth, (row + 2) * cellHeight, cellWidth, cellHeight, pixmap);
            } else {
                painter.drawText(col * cellWidth, (row + 2) * cellHeight, cellWidth, cellHeight, Qt::AlignCenter, text);
            }
            painter.drawRect(col * cellWidth, (row + 2) * cellHeight, cellWidth, cellHeight);
        }
        ++row;
    }

    // Ajouter le logo en bas du PDF
    QPixmap logo("logo.png"); // Remplacez "path_to_your_logo.png" par le chemin de votre logo
    painter.drawPixmap(0, printer.pageRect().bottom() - 50, logo.scaledToHeight(100));

    // Ajouter la signature et la date
    QString signature = "Signature: [amira]\nDate: " + QDate::currentDate().toString("dd/MM/yyyy");
    painter.drawText(0, printer.pageRect().bottom() - 20, signature);

    // Terminer le dessin
    painter.end();

    QMessageBox::information(nullptr, "success", "Data has been successfully exported to " + filePath);
}


void Dialog::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
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
    int ligne(0);
    int row(0);
    QString rech;
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
    if ((!ui->dramacate->isChecked())&&(!ui->horrorcate->isChecked())&&(!ui->comedycate->isChecked())&&(!ui->romancecate->isChecked())&&(!ui->scificate->isChecked())&&(!ui->actioncate->isChecked())&&(!ui->sportscate->isChecked()))
    {
        categorie="";
    }
    else
    {
        int cc=0;
        categorie="in (";
        if ( ui->actioncate->isChecked())
        {
            if (cc!=0)
            {
                categorie+=",";
            }
            cc++;
            categorie+="'action'";
        }
        if ( ui->horrorcate->isChecked())
        {
            if (cc!=0)
            {
                categorie+=",";
            }
            cc++;
            categorie+="'horror'";
        }
        if ( ui->comedycate->isChecked())
        {
            if (cc!=0)
            {
                categorie+=",";
            }
            cc++;
            categorie+="'comedy'";
        }
        if ( ui->romancecate->isChecked())
        {
            if (cc!=0)
            {
                categorie+=",";
            }
            cc++;
            categorie+="'romance'";
        }
        if ( ui->scificate->isChecked())
        {
            if (cc!=0)
            {
                categorie+=",";
            }
            cc++;
            categorie+="'sci-fi'";
        }
        if ( ui->dramacate->isChecked())
        {
            if (cc!=0)
            {
                categorie+=",";
            }
            cc++;
            categorie+="'drama'";
        }
        if ( ui->sportscate->isChecked())
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
    if (ui->comboBoxms->currentText()== "recently added" )
    {
        Qs=" order by id DESC";
        qDebug()<<"test";
    }
    else if (ui->comboBoxms->currentText()== "most views" )
    {
        Qs=" order by nbrvue DESC";
        qDebug()<<"test";
    }
    else if (ui->comboBoxms->currentText()== "least views" )
    {
        Qs=" order by nbrvue ASC";
        qDebug()<<"test";
    }
    else if (ui->comboBoxms->currentText()== "oldest" )
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
    ui->tableViewms->setModel(model);
    ui->tableViewms->horizontalHeader()->setVisible(true);

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
            query.bindValue(":id",ui->tableViewms->model()->data(ui->tableViewms->model()->index(j,0)).toString());
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
        ui->tableViewms->setIndexWidget(model->index(j, 9), buttt);
        QPushButton *butt;
        butt = new QPushButton("delete");
        QString name = QString("buttondel%1").arg(j) ;
        QString display = QString("delete") ;
        butt->setObjectName(name) ;
        butt->setText(display) ;

        //connect(butt, SIGNAL(clicked()),this,SLOT(deleteftable(const(j))) );
        connect(butt, &QPushButton::clicked, this, [this, j]() {
            MOVIE T;
            if(T.supp(ui->tableViewms->model()->data(ui->tableViewms->model()->index(j,0)).toInt()))
            {
                 QMessageBox :: information(this,"delete","Data Deleted successfully", QMessageBox ::Ok);
                 emit ui->pushButton_12ms->click();

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
        ui->tableViewms->setIndexWidget(model->index(j, 10), butt);

        butt = new QPushButton("update");
        name = QString("buttonup%1").arg(j) ;
        display = QString("update") ;
        butt->setObjectName(name) ;
        butt->setText(display) ;

        connect(butt, &QPushButton::clicked, this, [this, j]() {
            ui->upidms->setText(ui->tableViewms->model()->data(ui->tableViewms->model()->index(j,0)).toString()   );
            ui->typeupms->setText(ui->tableViewms->model()->data(ui->tableViewms->model()->index(j,1)).toString());
            ui->uptitlems->setText(ui->tableViewms->model()->data(ui->tableViewms->model()->index(j,2)).toString());
            ui->updescriptionms->setText(ui->tableViewms->model()->data(ui->tableViewms->model()->index(j,3)).toString());
            ui->dureupms->setTime(QTime::fromString(ui->tableViewms->model()->data(ui->tableViewms->model()->index(j,4)).toString(),"hh:mm:ss") );
            ui->nbrvupms->setText(ui->tableViewms->model()->data(ui->tableViewms->model()->index(j,6)).toString());
            QPixmap pixmap=ui->tableViewms->model()->data(ui->tableViewms->model()->index(j,5) , Qt::DecorationRole).value<QPixmap>();
            //QMessageBox :: critical(this,"Error",byte);


            QPixmap scaled=  pixmap.scaled(QSize( 200,200));
            ui->imagetest_2ms->setPixmap(scaled);
            ui->stackedWidget->setCurrentIndex(2);
        });
        butt->setStyleSheet("color:green;"
                            "background:transparent;"
                            "border:none;"
                            "font : 15pt;");
        ui->tableViewms->setIndexWidget(model->index(j, 11), butt);



    }



    ui->tableViewms->verticalHeader()->setVisible(false);
    ui->tableViewms->viewport()->setStyleSheet("background: rgb(255, 255, 255);"
                                             "border: 1px solid white;"
                                             "border-radius: 10px;"
                                             "color: black;");
    QRect rect = ui->tableViewms->viewport()->rect();
    QPainterPath path;
    rect.adjust(+1,+1,-1,-1);
    path.addRoundedRect(rect,25,25);
    QRegion mask = QRegion(path.toFillPolygon().toPolygon());
    ui->tableViewms->viewport()->setMask(mask);
    //ui->tableViewms->resize(ui->tableViewms->rowHeight(0)*row,ui->tableViewms->columnWidth(3)*4);
    ui->tableViewms->resizeRowsToContents();
    ui->tableViewms->resizeColumnsToContents();
    ui->tableViewms->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


}




void Dialog::on_comboBoxms_currentTextChanged(const QString &arg1)
{
     emit ui->pushButton_12ms->click();
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
             emit ui->pushButton_12ms->click();
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
                 emit ui->pushButton_12ms->click();

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
                 emit ui->pushButton_12ms->click();
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
    ui->comboBox->setVisible(true);
    ui->textEdit->setVisible(true);
    ui->gg_5->setVisible(true);
    ui->gg_2->setVisible(true);
    ui->label_47->setVisible(true);
    ui->label_48->setVisible(true);
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
        QSqlQuery query;
        query.exec("SELECT IDE,CIN,TYPE,NOM,PRENOM,TEL,EMAIL,PHOTO from EMPLOYE");


        QFont titleFont = painter.font();
        // Set font for the title
        titleFont.setFamily("CENTURY");// Change the font family
        painter.setPen(Qt::darkRed);
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
    if (ui->stackedWidget->currentIndex()==1)
    {
        emit ui->hihi_5->click();
    }
    else if (ui->stackedWidget->currentIndex()==14)
    {
        emit ui->pushButton_12ms->click();
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
}

void Dialog::on_searchLineEditM_textChanged(const QString &arg1)
{
    QString searchText = arg1.trimmed();
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
        queryText = "SELECT IDM, TITRE, DESCRIPTION, IMAGE, PRODUCTEUR, TYPE FROM MEDIA WHERE TITRE LIKE '" + searchText + "%'";
    }

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(queryText);

    ui->tableViewM->setModel(model);
}
void Dialog:: statistiqueMedia() {
    QPieSeries *seriesM;
    QChart *chartM;
    QChartView *chartViewM;
    QSqlQuery query;

    // Modifier la requête SQL pour calculer le nombre de vues par type (Radio/Channel)
    if (!query.exec("SELECT type, SUM(nbrvue) FROM MEDIA  GROUP BY type")) {
        qDebug() << "Query execution failed:" << query.lastError().text();
        return;
    }

    seriesM = new QPieSeries();
    while (query.next()) {
        qreal y = query.value(1).toDouble(); // Nombre de vues
        QString mediaType = query.value(0).toString(); // Type de média (Radio/Channel)
        QString label = QString("%1: %2 views").arg(mediaType).arg(y); // Label avec le nombre de vues
        seriesM->append(label, y);
    }
    qDebug() << "Data count:" << seriesM->count();

    if (seriesM->count() == 0) {
        qDebug() << "No data found for chart.";
        return;
    }

    QFont title;
    title.setPointSize(12);

    chartM = new QChart();
    chartM->addSeries(seriesM);
    chartM->setTitleFont(title);
    chartM->setTitle("Statistics by the number of views of each type of media ");

    chartViewM = new QChartView(chartM);
    QGraphicsScene *scene = new QGraphicsScene();
    scene->addWidget(chartViewM);
    chartViewM->setFixedSize(800, 600);
    scene->setSceneRect(QRectF(chartViewM->rect()));

    QPixmap pixmap(scene->sceneRect().size().toSize());
    pixmap.fill(Qt::white);
    QPainter painter(&pixmap);
    chartViewM->render(&painter);

    if (pixmap.isNull()) {
        qDebug() << "Pixmap creation failed.";
        return;
    }

    //ui->StatMedia->setPixmap(pixmap);
    qDebug() << "Chart displayed successfully.";
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

void Dialog::on_stackedWidget_currentChanged(int arg1)
{
    qDebug()<<arg1;
    if (ui->stackedWidget->currentIndex()==1)
    {
        qDebug()<<"ok to vc";
        ui->textEdit->setFocus();
    }
}
