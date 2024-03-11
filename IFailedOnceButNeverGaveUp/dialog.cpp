#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint| Qt::WindowSystemMenuHint);
    (ui->comboBox)->view()->window()->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
    (ui->comboBox)->view()->window()->setAttribute(Qt::WA_TranslucentBackground);
    ui->lineEdit_3A_2->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_3A_9->setValidator(new QIntValidator(0,9999999,this));
    ui->lineEdit_3A_8->setValidator(new QIntValidator(0,9999999,this));
    ui->lineEdit_3A_6->setValidator(new QIntValidator(0,9999999,this));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_hihi_6_clicked()//home
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->label_6->setGeometry(15,170,51,20);
    ui->hihi_6->setStyleSheet("font: 30pt 'dripicons-v2';"
                                 " border:none;"
                                  "background-color:transparent;"
                                  "color:rgba(0,125,236,255);");
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
    ui->stackedWidget->setCurrentIndex(1);
    ui->label_6->setGeometry(15,305,51,20);
    ui->hihi_5->setStyleSheet("font: 30pt 'dripicons-v2';"
                                 " border:none;"
                                  "background-color:transparent;"
                                  "color:rgba(0,125,236,255);");
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
        int ligne(0);
        int row(0);
        QSqlQuery query;
        query.exec("select count(*) from EMPLOYE");
        while(query.next() )
        {
            ligne=query.value(0).toInt();
        }
        //QMessageBox :: warning(this,"",QString::number( ligne));

        QStandardItemModel * model=new QStandardItemModel(ligne , 8);
        QString qs;
        qs="select IDE,CIN,TYPE,PHOTO,NOM,PRENOM from EMPLOYE";
        qDebug()<<qs;
        query.exec(qs);
        while(query.next())
        {
            for (int j=0;j<6;j++)
            {

                QStandardItem *item;
                if ( j==3)
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
        model->setHeaderData(5, Qt::Horizontal , "PHOTO");
        model->setHeaderData(6, Qt::Horizontal , "delete");
        model->setHeaderData(7, Qt::Horizontal , "update");
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
            ui->tableViewem->setIndexWidget(model->index(j, 6), butt);

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
            ui->tableViewem->setIndexWidget(model->index(j, 7), butt);
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
        if (erreur=="")
        {
            QSqlQuery query;
                    query.prepare("insert into EMPLOYE (cin , username , password , nom , prenom , type , photo , ids) values (:cin , :username , :password , :nom , :prenom , :type , :photo,:ids)");
                    query.bindValue(":cin",ui->lineEdit_3A_2->text().toInt());
                    query.bindValue(":type",check1);
                    query.bindValue(":username",ui->lineEdit_3A_4->text());
                    query.bindValue(":password",ui->lineEdit_3A_5->text());
                    query.bindValue(":nom",ui->lineEdit_3A_3->text());
                    query.bindValue(":prenom",ui->lineEdit_3A->text());
                    query.bindValue(":photo",byte);
                    query.bindValue(":ids",7);

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
    if (erreur=="")
    {
        QSqlQuery query;
        query.prepare("UPDATE EMPLOYE set cin=:cin , username=:username , password=:password , nom=:nom , prenom=:prenom , type=:type , photo=:photo where ide=:id");
        query.bindValue(":cin",ui->lineEdit_3A_2->text().toInt());
        query.bindValue(":type",check1);
        query.bindValue(":username",ui->lineEdit_3A_4->text());
        query.bindValue(":password",ui->lineEdit_3A_5->text());
        query.bindValue(":nom",ui->lineEdit_3A_3->text());
        query.bindValue(":prenom",ui->lineEdit_3A->text());
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
