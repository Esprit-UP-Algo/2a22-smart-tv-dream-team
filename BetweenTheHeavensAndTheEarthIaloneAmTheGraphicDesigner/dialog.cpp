#include "dialog.h"
#include "ui_dialog.h"
#include"employer.h"
#include <cctype>
#include <iostream>

using namespace std;
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint| Qt::WindowSystemMenuHint);
    ui->lineEdit_2->setValidator(new QIntValidator(0,1000000000,this));
    ui->lineEdit_4->setValidator(new QIntValidator(0,1000000000,this));
    ui->lineEdit_15->setValidator(new QIntValidator(0,1000000000,this));
    (ui->comboBox)->view()->window()->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
    (ui->comboBox)->view()->window()->setAttribute(Qt::WA_TranslucentBackground);
    (ui->comboBox_2)->view()->window()->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
    (ui->comboBox_2)->view()->window()->setAttribute(Qt::WA_TranslucentBackground);
    (ui->comboBox_3)->view()->window()->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
    (ui->comboBox_3)->view()->window()->setAttribute(Qt::WA_TranslucentBackground);
    ui->label_49->setVisible(true);
    ui->label_11->setVisible(false);
    ui->label_13->setVisible(false);
    ui->label_65->setVisible(false);
    ui->pushButton_8->setVisible(false);
    ui->pushButton_9M->setVisible(false);
    ui->label_71->setVisible(false);
    ui->label_72->setVisible(false);
    ui->label_73->setVisible(false);
    ui->imagetestms_3->setVisible(false);
    ui->imagetestms_4->setVisible(false);
    ui->formM_2->raise();
    ui->textEdit_5M_2->raise();
    ui->label_13M_3->lower();
    ui->label_3M_2->setVisible(false);
    ui->returnButtonM_2->setVisible(false);
    ui->deleteButtonM_2->setVisible(false);
    ui->modifyButtonM_2->setVisible(false);

    /*ui->descriptionRM_2->setVisible(false);
    ui->returnButton_2M_2->setVisible(false);
    ui->deleteButton_2M_2->setVisible(false);
    ui->modifyButton_2M_2->setVisible(false);*/

     ui->barreTrieM_2->setVisible(false);
     //ui->barreTrie_2M_2->setVisible(false);
}

Dialog::~Dialog()
{
    delete ui;

}

void Dialog::on_gg_clicked()
{
    close();
}

void Dialog::on_hihi_5_clicked()
{
    //tableViewem
    int ligne(0);
        int row(0);
        QSqlQuery query;
        query.exec("select count(*) from employe");
        while(query.next() )
        {
            ligne=query.value(0).toInt();
        }
        //QMessageBox :: warning(this,"",QString::number( ligne));

        QStandardItemModel * model=new QStandardItemModel(ligne , 7);
        query.exec("select id , username , password , type , photo from employe");
        while(query.next())
        {
            for (int j=0;j<5;j++)
            {
                QStandardItem *item;

                if ( j==4)
                {
                    QByteArray array;
                    //qDebug()<<"Initial Array Size"<<array.size();
                    array = query.value(j).toByteArray();
                    //qDebug()<<"ARray Size"<<array.size();
                    QPixmap pixmap;
                    pixmap.loadFromData(array,"JPG && PNG",Qt::AutoColor);
                    QPixmap scaled=  pixmap.scaled(QSize( 250,250));
                    item = new QStandardItem();
                    item->setData(scaled,Qt::DecorationRole);


                }
                else if (j<5)
                {
                    item = new QStandardItem(query.value(j).toString());
                }

                if ( j<5)
                {
                    item->setTextAlignment(Qt::AlignCenter);

                    model->setItem(row,j,item);

                }
            }
            row++;
        }




        model->setHeaderData(0, Qt::Horizontal , "id");
        model->setHeaderData(1, Qt::Horizontal , "username");
        model->setHeaderData(2, Qt::Horizontal , "password");
        model->setHeaderData(3, Qt::Horizontal , "type");
        model->setHeaderData(4, Qt::Horizontal , "photo");
        model->setHeaderData(5, Qt::Horizontal , "delete");
        model->setHeaderData(6, Qt::Horizontal , "update");
        ui->tableViewem->setModel(model);

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
                query.prepare("delete from employe where id=:id");
                query.bindValue(":id",ui->tableViewem->model()->data(ui->tableViewem->model()->index(j,0)).toInt());
                query.exec();
                emit ui->hihi_5->click();
            });
            butt->setStyleSheet("color:red;"
                                "background:transparent;"
                                "border:none;"
                                "font : 15pt;");
            ui->tableViewem->setIndexWidget(model->index(j, 5), butt);

            butt = new QPushButton("update");
            name = QString("buttonup%1").arg(j) ;
            display = QString("update") ;
            butt->setObjectName(name) ;
            butt->setText(display) ;

            connect(butt, &QPushButton::clicked, this, [this, j]() {
                ui->lineEdit_8->setText(QString::number(ui->tableViewem->model()->data(ui->tableViewem->model()->index(j,0)).toInt()));
                //QMessageBox :: critical(this,"Error",byte);
                ui->stackedWidget->setCurrentIndex(3);
            });
            butt->setStyleSheet("color:green;"
                                "background:transparent;"
                                "border:none;"
                                "font : 15pt;");
            ui->tableViewem->setIndexWidget(model->index(j, 6), butt);



        }



        ui->tableViewem->verticalHeader()->setVisible(false);
        QRect rect = ui->tableViewem->viewport()->rect();
        QPainterPath path;
        rect.adjust(+1,+1,-1,-1);
        path.addRoundedRect(rect,25,25);
        QRegion mask = QRegion(path.toFillPolygon().toPolygon());
        ui->tableViewem->viewport()->setMask(mask);
        //ui->tableViewem->resize(ui->tableViewem->rowHeight(0)*row,ui->tableViewem->columnWidth(3)*7);
        ui->tableViewem->resizeRowsToContents();
        ui->tableViewem->resizeColumnsToContents();

    ui->stackedWidget->setCurrentIndex(2);
}

void Dialog::on_gg_4_clicked()
{
    close();
}

void Dialog::on_hihi_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}




void Dialog::on_pushButton_clicked()
{
    ui->pushButton->lower();
    ui->mainbox->lower();
}




void Dialog::on_gg_5_clicked()
{
    if (ui->label_49->isVisible()) {
           ui->label_49->setVisible(false);
       } else {
           ui->label_49->setVisible(true);
           ui->label_49->raise();
       }
}

void Dialog::on_gg_6_clicked()
{
    if (ui->label_54->isVisible()) {
           ui->label_54->setVisible(false);
       } else {
           ui->label_54->setVisible(true);
           ui->label_54->raise();
       }
}

void Dialog::on_hihi_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Dialog::on_hihi_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Dialog::on_gg_7_clicked()
{
    close();
}


void Dialog::on_hihi_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Dialog::on_hihi_20_clicked()
{
    if (ui->label_11->isVisible() && ui->label_13->isVisible() && ui->label_65->isVisible() && ui->pushButton_8->isVisible() && ui->label_71->isVisible() && ui->label_72->isVisible() && ui->label_73->isVisible()) {
        ui->label_11->setVisible(false);
        ui->label_13->setVisible(false);
        ui->label_65->setVisible(false);
        ui->pushButton_8->setVisible(false);
        ui->pushButton_9M->setVisible(false);
        ui->label_71->setVisible(false);
        ui->label_72->setVisible(false);
        //ui->label_73->setVisible(false);
       } else {
        ui->label_11->setVisible(true);
        ui->label_13->setVisible(true);
        ui->label_65->setVisible(true);
        ui->pushButton_8->setVisible(true);
        ui->pushButton_9M->setVisible(true);
        ui->label_71->setVisible(true);
        ui->label_72->setVisible(true);
        //ui->label_73->setVisible(true);

        ui->label_11->raise();
        ui->label_13->raise();
        ui->label_65->raise();
        ui->pushButton_8->raise();
        ui->pushButton_9M->raise();
        ui->label_71->raise();
        ui->label_72->raise();
        //ui->label_73->raise();
       }
}

void Dialog::on_hihi_17_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void Dialog::on_pushButton_2_clicked()
{
    ui->pushButton_2->lower();
    ui->mainbox->lower();
}

void Dialog::on_pushButton_3_clicked()
{
    ui->pushButton_3->lower();
    ui->mainbox->lower();
}

void Dialog::on_pushButton_4_clicked()
{
    ui->pushButton_4->lower();
    ui->mainbox->lower();
}

void Dialog::on_pushButton_5_clicked()
{
    ui->pushButton_5->lower();
    ui->mainbox->lower();
}


void Dialog::on_pushButton_6_clicked()
{
    ui->pushButton_6->lower();
    ui->mainbox->lower();
}

void Dialog::on_pushButton_7_clicked()
{
    ui->pushButton_7->lower();
    ui->mainbox->lower();
}

void Dialog::on_pushButton_4A_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void Dialog::on_pushButton_4A_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void Dialog::on_pushButton_5A_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void Dialog::on_pushButton_5A_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void Dialog::on_pushButton_4A_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void Dialog::on_pushButton_5A_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void Dialog::on_gg_10_clicked()
{
    close();
}

void Dialog::on_hihi_32_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Dialog::on_hihi_29_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void Dialog::on_hihi_31_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Dialog::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

//              movie part

void Dialog::on_pushButton_2ms_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void Dialog::on_pushButton_4ms_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
    ui->lineEdit_2ms_2->setText("");
    ui->textEditms_2->setText("");
    //ui->imagetest->setStyleSheet("border-image : none;");
    ui->imagetestms_3->setVisible(false);
    ui->imagetestms_4->setVisible(false);
}


void Dialog::on_pushButton_11ms_2_clicked()
{

    QByteArray byte;
    QFile file(photo);
    /*QPixmap img(photo);
    QBuffer imgdata;
    if (imgdata.open(QIODevice::ReadWrite))
    {
        img.save(&imgdata,"PNG");
    }
    byte=imgdata.buffer().toBase64();*/
    if(file.open(QIODevice::ReadOnly))
    {
        byte = file.readAll();
        QMessageBox :: critical(this,"Error",byte);
        file.close();
    }
    QMessageBox :: critical(this,"Error",photo);
    QSqlQuery query;
    query.prepare("insert into MOVIE values (:id , :description , :photo , :titre)");
    query.bindValue(":photo", byte);
    query.bindValue(":titre",ui->lineEdit_2ms_2->text());
    query.bindValue(":description",ui->textEditms_2->toPlainText());
    query.bindValue(":id", 8);
    if(query.exec())
    {
         QMessageBox :: information(this,"Save","Data Inserted successfully", QMessageBox ::Ok);
         ui->lineEdit_2ms_2->setText("");
         ui->textEditms_2->setText("");
         //ui->imagetest->setStyleSheet("border-image : none;");
         ui->imagetestms_3->setVisible(false);
         ui->imagetestms_4->setVisible(false);
    }
    else
    {
         QMessageBox :: critical(this,"Error","Couldn't insert data");
    }
}

void Dialog::on_pushButton_3ms_2_clicked()
{
    QString imageFile = QFileDialog ::getOpenFileName(0,"Select Image","/home/","Image Files (*.png && *.jpg)");

      QFileInfo info(imageFile);
      ui->imagetestms_3->setVisible(true);
      ui->imagetestms_4->setVisible(true);
      ui->imagetestms_4->setStyleSheet("border-image : url("+imageFile+");");
      photo = imageFile;
}

void Dialog::deleteftable(int j)
{
    QMessageBox::warning( this,"","test del");
    int id =ui->tableViewms_2->model()->data(ui->tableViewms_2->model()->index(j,0)).toInt();
    QSqlQuery query;
    query.prepare("DELETE FROM MOVIE WHERE id = :id ;");
    query.bindValue(":id", id);
    if(query.exec())
    {
         QMessageBox :: information(this,"delete","Data Deleted successfully", QMessageBox ::Ok);
         emit ui->pushButton_12ms_2->click();

    }
    else
    {
         QMessageBox :: critical(this,"Error","Couldn't insert data");
    }

}

void Dialog::on_pushButton_12ms_2_clicked()
{
    /*QSqlQueryModel *query = new QSqlQueryModel();
    query->setQuery("select id , titre ,description , photo from MOVIE");
    ui->tableView->setModel(query);*/

    int ligne(0);
    int row(0);
    QSqlQuery query;
    query.exec("select count(*) from MOVIE");
    while(query.next() )
    {
        ligne=query.value(0).toInt();
    }
    QMessageBox :: warning(this,"",QString::number( ligne));

    QStandardItemModel * model=new QStandardItemModel(ligne , 6);
    query.exec("select id , titre ,description , photo from MOVIE");
    while(query.next())
    {
        for (int j=0;j<4;j++)
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
                QPixmap scaled=  pixmap.scaled(QSize( 200,200));
                item = new QStandardItem();
                item->setData(scaled,Qt::DecorationRole);

            }
            else if (j<3)
            {
                item = new QStandardItem(query.value(j).toString());
            }

            if ( j<4)
            {
                model->setItem(row,j,item);
            }
        }
        row++;
    }




    model->setHeaderData(0, Qt::Horizontal , "id");
    model->setHeaderData(1, Qt::Horizontal , "titre");
    model->setHeaderData(2, Qt::Horizontal , "description");
    model->setHeaderData(3, Qt::Horizontal , "photo");
    model->setHeaderData(4, Qt::Horizontal , "delete");
    model->setHeaderData(5, Qt::Horizontal , "update");
    ui->tableViewms_2->setModel(model);

    for (int j=0;j<row ; j++)
    {
        QPushButton *butt;
        butt = new QPushButton("delete");
        QString name = QString("buttondel%1").arg(j) ;
        QString display = QString("delete") ;
        butt->setObjectName(name) ;
        butt->setText(display) ;

        //connect(butt, SIGNAL(clicked()),this,SLOT(deleteftable(const(j))) );
        connect(butt, &QPushButton::clicked, this, [this, j]() {
            deleteftable(j);
        });
        butt->setStyleSheet("color:red;"
                            "background:transparent;"
                            "border:none;"
                            "font : 15pt;");
        ui->tableViewms_2->setIndexWidget(model->index(j, 4), butt);

        butt = new QPushButton("delete");
        name = QString("buttonup%1").arg(j) ;
        display = QString("update") ;
        butt->setObjectName(name) ;
        butt->setText(display) ;

        connect(butt, &QPushButton::clicked, this, [this, j]() {
            deleteftable(j);
        });
        butt->setStyleSheet("color:green;"
                            "background:transparent;"
                            "border:none;"
                            "font : 15pt;");
        ui->tableViewms_2->setIndexWidget(model->index(j, 5), butt);



    }



    ui->tableViewms_2->verticalHeader()->setVisible(false);
    ui->tableViewms_2->viewport()->setStyleSheet("background: rgb(255, 255, 255);"
                                             "border: 1px solid white;"
                                             "border-radius: 10px;"
                                             "color: black;");
    QRect rect = ui->tableViewms_2->viewport()->rect();
    QPainterPath path;
    rect.adjust(+1,+1,-1,-1);
    path.addRoundedRect(rect,25,25);
    QRegion mask = QRegion(path.toFillPolygon().toPolygon());
    ui->tableViewms_2->viewport()->setMask(mask);
    ui->tableViewms_2->resize(ui->tableViewms_2->rowHeight(0)*row,ui->tableViewms_2->columnWidth(3)*4);
    ui->tableViewms_2->resizeRowsToContents();
    ui->tableViewms_2->resizeColumnsToContents();


}

void Dialog::on_pushButton_9M_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void Dialog::on_loM_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void Dialog::on_pushButton_2M_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}


void Dialog::on_tvM_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void Dialog::on_tv_2M_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}


void Dialog::on_radioM_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void Dialog::on_deleteButtonM_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void Dialog::on_modifyButtonM_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void Dialog::on_addButtonM_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Dialog::on_seriesM_2_clicked()
{
    if (ui->label_3M_2->isVisible()) {
            ui->label_3M_2->setVisible(false);
            ui->returnButtonM_2->setVisible(false);
            ui->deleteButtonM_2->setVisible(false);
            ui->modifyButtonM_2->setVisible(false);
        } else {
            ui->label_3M_2->setVisible(true);
            ui->label_3M_2->raise();
            ui->returnButtonM_2->setVisible(true);
            ui->returnButtonM_2->raise();
            ui->deleteButtonM_2->setVisible(true);
            ui->deleteButtonM_2->raise();
            ui->modifyButtonM_2->setVisible(true);
            ui->modifyButtonM_2->raise();
        }
}


void Dialog::on_returnButtonM_2_clicked()
{
    if (ui->label_3M_2->isVisible()) {
            ui->label_3M_2->setVisible(false);
            ui->returnButtonM_2->setVisible(false);
            ui->deleteButtonM_2->setVisible(false);
            ui->modifyButtonM_2->setVisible(false);
        } if (ui->label_3M_2->isVisible()) {
            ui->label_3M_2->setVisible(true);
            ui->label_3M_2->raise();
            ui->returnButtonM_2->setVisible(true);
            ui->returnButtonM_2->raise();
        }
}

void Dialog::on_add_2M_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void Dialog::on_modifyButton_2M_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(9);
}


/*void Dialog::on_vwatchRadioM_2_clicked()
{
    if (ui->descriptionRM_2->isVisible()) {
            ui->descriptionRM_2->setVisible(false);
            ui->returnButtonM_2->setVisible(false);
            ui->deleteButtonM_2->setVisible(false);
            ui->modifyButtonM_2->setVisible(false);
        } else {
            ui->descriptionRM_2->setVisible(true);
            ui->descriptionRM_2->raise();
            ui->returnButton_2M_2->setVisible(true);
            ui->returnButton_2M_2->raise();
            ui->deleteButton_2M_2->setVisible(true);
            ui->deleteButton_2M_2->raise();
            ui->modifyButton_2M_2->setVisible(true);
            ui->modifyButton_2M_2->raise();
        }

}*/
/*
void Dialog::on_returnButton_2M_2_clicked()
{
    if (ui->descriptionRM_2->isVisible()) {
            ui->descriptionRM->setVisible(false);
            ui->returnButton_2M->setVisible(false);
            ui->deleteButton_2M->setVisible(false);
            ui->modifyButton_2M->setVisible(false);
        } if (ui->descriptionRM->isVisible()) {
            ui->descriptionRM->setVisible(true);
            ui->descriptionRM->raise();
            ui->returnButton_2M->setVisible(true);
            ui->returnButton_2M->raise();
        }

}*/

/*void Dialog::on_trieButtonM_2_clicked()

{
    if (!isTrieButtonClicked) {
            ui->barreTrieM_2->setVisible(true);
            isTrieButtonClicked = true;
        } else {
             ui->barreTrieM_2->setVisible(false);
            isTrieButtonClicked = false;
        }
}
*/
void Dialog::on_vewatchButtonM_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

/*
void Dialog::on_trieButton_2M_2_clicked()
{
    if (!isTrieButtonClicked) {
            ui->barreTrie_2M_2->setVisible(true);
            isTrieButtonClicked = true;
        } else {
             ui->barreTrie_2M_2->setVisible(false);
            isTrieButtonClicked = false;
        }

}*/

void Dialog::on_statisticsM_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void Dialog::on_statistics_2M_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void Dialog::on_brandsButton_2M_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void Dialog::on_brandsButtonM_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}
void Dialog::importImage()
{
    // Ouvrir une boîte de dialogue pour sélectionner un fichier
    QString imagePath = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));
 }

void Dialog::on_vewatch_2M_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void Dialog::on_hihi_10tr_clicked()
{
     ui->stackedWidget->setCurrentIndex(11);
}

void Dialog::on_hihi_10tr_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void Dialog::on_hihi_15_clicked()
{
        ui->stackedWidget->setCurrentIndex(1);
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
        if(ui->textEdittr_3->toPlainText()!="")
        {

           qs="select IDTRANSACTION , DATET ,TYPE , MONTANT from TRANSACTION where IDTRANSACTION="+ui->textEdittr_3->toPlainText() ;
        }

        else if(ui->comboBox_5->currentText()=="date transaction from newest to oldest")
        {
           qs="select IDTRANSACTION , DATET ,TYPE , MONTANT from TRANSACTION order by DATET DESC";
        }
        else if(ui->comboBox_5->currentText()=="default")
        {
            qs="select IDTRANSACTION , DATET ,TYPE , MONTANT from TRANSACTION";
        }
        else if(ui->comboBox_5->currentText()=="date transaction from oldest to newest ")
        {
            qs="select IDTRANSACTION , DATET ,TYPE , MONTANT from TRANSACTION order by DATET";
        }
        else if(ui->comboBox_5->currentText()=="montant from highest to lowest")
        {
            qs="select IDTRANSACTION , DATET ,TYPE , MONTANT from TRANSACTION order by MONTANT DESC ";
        }
        else if(ui->comboBox_5->currentText()=="montant from lowest to highest")
        {
            qs="select IDTRANSACTION , DATET ,TYPE , MONTANT from TRANSACTION order by MONTANT";
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
        ui->tableViewtr->setModel(model);

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
                query.bindValue(":id",ui->tableViewtr->model()->data(ui->tableViewtr->model()->index(j,0)).toInt());
                query.exec();
                int idt=ui->tableViewtr->model()->data(ui->tableViewtr->model()->index(j,0)).toInt();
                QSqlQuery query1;
                query1.prepare("insert into HISTORIQUE (ide , description , datet) values (:ide , :description , :date)");
                query1.bindValue(":date",QTime::currentTime());
                query1.bindValue(":description","deleted transaction numero: " +  QString::number(idt));
                query1.bindValue(":ide",6);
                query1.exec();
                emit ui->hihi_15->click();
            });
            butt->setStyleSheet("color:red;"
                                "background:transparent;"
                                "border:none;"
                                "font : 15pt;");
            ui->tableViewtr->setIndexWidget(model->index(j, 4), butt);

            butt = new QPushButton("update");
            name = QString("buttonup%1").arg(j) ;
            display = QString("update") ;
            butt->setObjectName(name) ;
            butt->setText(display) ;

            connect(butt, &QPushButton::clicked, this, [this, j]() {
                ui->lineEdit_2->setText(QString::number(ui->tableViewtr->model()->data(ui->tableViewtr->model()->index(j,3)).toInt()   ));
                ui->dateTimeEdit_2->setDateTime(ui->tableViewtr->model()->data(ui->tableViewtr->model()->index(j,1)).toDateTime());
                if (ui->tableViewtr->model()->data(ui->tableViewtr->model()->index(j,2)).toString()=="cheque")
                {
                    ui->radioButton_2->setChecked(true);
                }
                if (ui->tableViewtr->model()->data(ui->tableViewtr->model()->index(j,2)).toString()=="carte bancaire")
                {
                    ui->radioButton_3->setChecked(true);
                }
                if (ui->tableViewtr->model()->data(ui->tableViewtr->model()->index(j,2)).toString()=="especes")
                {
                    ui->radioButton->setChecked(true);
                }

                ui->lineEdit_15->setText(QString::number(ui->tableViewtr->model()->data(ui->tableViewtr->model()->index(j,0)).toInt()   ));
                ui->stackedWidget->setCurrentIndex(12);
            });
            butt->setStyleSheet("color:green;"
                                "background:transparent;"
                                "border:none;"
                                "font : 15pt;");
            ui->tableViewtr->setIndexWidget(model->index(j, 5), butt);
        }
        ui->tableViewtr->verticalHeader()->setVisible(false);
            //QRect rect = ui->tableViewtr->viewport()->rect();
           // QPainterPath path;
            //rect.adjust(+1,+1,-1,-1);
            //path.addRoundedRect(rect,25,25);
           // QRegion mask = QRegion(path.toFillPolygon().toPolygon());
            //ui->tableViewtr->viewport()->setMask(mask);
            //ui->tableViewtr->resize(ui->tableViewtr->columnWidth(3)*4,ui->tableViewtr->rowHeight(0)*row);
            ui->tableViewtr->resizeRowsToContents();
            ui->tableViewtr->resizeColumnsToContents();
            ui->tableViewtr->show();
    }


void Dialog::on_pushButton_63_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Dialog::on_pushButton_24_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Dialog::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Dialog::on_pushButton_9_clicked()
{
    QString erreur="";
        QString check1;
        bool intyes2;
        ui->lineEdit_4->text().toInt(&intyes2);
        if((ui->radioButton_7->isChecked()==false)&&(ui->radioButton_8->isChecked()==false)&&(ui->radioButton_9->isChecked()==false))
        {
            erreur+="\n- pls select one ";
        }

        if (ui->radioButton_7->isChecked())
            {
                check1=("especes");
            }
        if (ui->radioButton_8->isChecked())
        {
            check1=("carte bancaire");
        }
        if (ui->radioButton_9->isChecked())
        {
            check1=("cheque");
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
                            query.bindValue(":montant",ui->lineEdit_4->text().toInt());
                            query.bindValue(":ide",6);

                    if(query.exec())
                    {
                         QMessageBox :: information(this,"Save","Data Inserted successfully", QMessageBox ::Ok);
                         QSqlQuery query;
                         query.exec("select max(IDTRANSACTION) from TRANSACTION");
                         query.next();
                         int idt=query.value(0).toInt();
                         int s=ui->lineEdit_4->text().toInt();

                         QSqlQuery query1;
                         query1.prepare("insert into HISTORIQUE (ide , description , datet) values (:ide , :description , :date)");
                         query1.bindValue(":date",QTime::currentTime());
                         query1.bindValue(":description","ajout transaction numero: " +  QString::number(idt)  + " de type: " + check1+ " " +" montant: " + QString::number(s) );
                         query1.bindValue(":ide",6);

                         query1.exec();
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

void Dialog::on_pushButton_23_clicked()
{
        QString erreur="";
        bool intyes;
        QString check1;
        bool intyes2;
        ui->lineEdit_2->text().toInt(&intyes);
        ui->lineEdit_15->text().toInt(&intyes2);
        qDebug()<<intyes;
        if (intyes==false)
        {
            erreur+="\n-id doit etre nombre";
        }
        if (ui->radioButton->isChecked())
            {
                check1=("especes");
            }
        if((ui->radioButton->isChecked()==false)&&(ui->radioButton_2->isChecked()==false)&&(ui->radioButton_3->isChecked()==false))
        {
            erreur+="\n- pls select one ";
        }

        if (ui->radioButton_3->isChecked())
        {
            check1=("carte bancaire");
        }
        if (ui->radioButton_2->isChecked())
        {
            check1=("cheque");
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
            query.bindValue(":montant",ui->lineEdit_2->text().toInt());
            query.bindValue(":id",ui->lineEdit_15->text().toInt());
            if(query.exec())
            {
                 int idt=ui->lineEdit_15->text().toInt();
                 int s=ui->lineEdit_2->text().toInt();

                 QSqlQuery query1;
                 query1.prepare("insert into HISTORIQUE (ide , description , datet) values (:ide , :description , :date)");
                 query1.bindValue(":date",QTime::currentTime());
                 query1.bindValue(":description","updated transaction numero: " +  QString::number(idt)  + " de type: " + check1+ " " +" montant: " + QString::number(s) );
                 query1.bindValue(":ide",6);

                 query1.exec();
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



void Dialog::on_hihi_33_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void Dialog::on_pushButton_26_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Dialog::on_pushButton_25_clicked()
{
    QSqlQuery query;
            query.prepare("insert into employe values (:id , :username , :password , :type,:photo)");
            query.bindValue(":username",ui->lineEdit_5->text());
            query.bindValue(":password",ui->lineEdit_6->text());
            query.bindValue(":type",ui->lineEdit_7->text().toInt());
            query.bindValue(":id",ui->lineEdit_8->text().toInt());
            query.bindValue(":photo",byte);
            if(query.exec())
            {
                 QMessageBox :: information(this,"Save","employe Inserted successfully", QMessageBox ::Ok);
                 ui->stackedWidget->setCurrentIndex(1);
            }
            else
            {
                 QMessageBox :: critical(this,"Error","Couldn't insert data");
            }
    emit ui->hihi_5->click();
}

void Dialog::on_addphotemp_clicked()
{
    QString imageFile = QFileDialog ::getOpenFileName(0,"Select Image","/home/","Image Files (*.png && *.jpg)");

          QFileInfo info(imageFile);
          ui->addphotemp->setStyleSheet("border-image : url("+imageFile+");");
          QFile file(imageFile);
          if(file.open(QIODevice::ReadOnly))
          {
              byte = file.readAll();
              //QMessageBox :: critical(this,"Error",byte);
              file.close();
          }
}

void Dialog::on_pushButton_27_clicked()
{
    QSqlQuery query;
            query.prepare("UPDATE employe set username=:username , password=:password , type=:type , photo=:photo where id=:id ");
            query.bindValue(":username",ui->lineEdit_5->text());
            query.bindValue(":password",ui->lineEdit_6->text());
            query.bindValue(":type",ui->lineEdit_7->text().toInt());
            query.bindValue(":photo",byte);
            query.bindValue(":id",ui->lineEdit_8->text().toInt());
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

void Dialog::on_gg_2tr_3_clicked()
{
    emit ui->hihi_15->click();
    ui->textEdittr_3->setPlainText("");

}

void Dialog::on_hihi_143_clicked()
{
    emit ui->hihi_15->click();
}

void Dialog::on_hihi_10tr_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
    int ligne(0);
    int row(0);
    QSqlQuery query;
    query.exec("select count(*) from HISTORIQUE");
    while(query.next() )
    {
        ligne=query.value(0).toInt();
    }
    //QMessageBox :: warning(this,"",QString::number( ligne));
    QString qs;
    qs="select IDH , IDE ,DESCRIPTION , DATET from HISTORIQUE";
    qDebug()<<qs;
    query.exec(qs);

    QStandardItemModel * model=new QStandardItemModel(ligne , 4);
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
    model->setHeaderData(0, Qt::Horizontal , "IDTLOGS");
    model->setHeaderData(1, Qt::Horizontal , "IDE");
    model->setHeaderData(2, Qt::Horizontal , "DESCRIPTION");
    model->setHeaderData(3, Qt::Horizontal , "DATET");
    ui->tableViewtr_2->setModel(model);
    ui->tableViewtr_2->verticalHeader()->setVisible(false);
        //QRect rect = ui->tableViewtr->viewport()->rect();
       // QPainterPath path;
        //rect.adjust(+1,+1,-1,-1);
        //path.addRoundedRect(rect,25,25);
       // QRegion mask = QRegion(path.toFillPolygon().toPolygon());
        //ui->tableViewtr->viewport()->setMask(mask);
        //ui->tableViewtr->resize(ui->tableViewtr->columnWidth(3)*4,ui->tableViewtr->rowHeight(0)*row);
        ui->tableViewtr_2->resizeRowsToContents();
        ui->tableViewtr_2->resizeColumnsToContents();
        ui->tableViewtr_2->show();
}

void Dialog::on_hihi_8tr_clicked()
{

    QStandardItemModel *model = qobject_cast<QStandardItemModel*>(ui->tableViewtr->model());
           if (!model) {
               QMessageBox::warning(nullptr, "Erreur", "Impossible d'exporter les données : modèle non trouvé.");
               return;
           }

           // Ouvrir une boîte de dialogue pour sélectionner l'emplacement de sauvegarde du fichier PDF
           QString filePath = QFileDialog::getSaveFileName(nullptr, "Exporter vers PDF", "", "Fichiers PDF (&.pdf)");
           if (filePath.isEmpty())
               return; // Annuler l'exportation si aucun fichier n'a été sélectionné

           // Créer un objet QPrinter pour générer le fichier PDF
           QPrinter printer(QPrinter::PrinterResolution);
           printer.setOutputFormat(QPrinter::PdfFormat);
           printer.setPaperSize(QPrinter::A4);
           printer.setOutputFileName(filePath);

           // Créer un objet QPainter pour dessiner sur le périphérique d'impression
           QPainter painter;
           if (!painter.begin((&printer))) {
               QMessageBox::warning(nullptr, "Erreur", "Impossible d'initialiser le périphérique d'impression.");
               return;
           }

           // Dessiner les en-têtes de colonne
           for (int col = 0; col < model->columnCount(); ++col) {
               QString text = model->headerData(col, Qt::Horizontal).toString();
               painter.drawText(col * 100, 50, text);
           }

           // Dessiner les données de la table
           for (int row = 0; row < model->rowCount(); ++row) {
               for (int col = 0; col < model->columnCount(); ++col) {
                   QString text = model->data(model->index(row, col), Qt::DisplayRole).toString();
                   painter.drawText(col * 100, (row + 2) * 50, text);
               }
           }

           // Terminer le dessin
           painter.end();
}
void Dialog::on_pushButton_28_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Dialog::on_hihi_8tr_2_clicked()
{
    QStandardItemModel *model = qobject_cast<QStandardItemModel*>(ui->tableViewtr_2->model());
           if (!model) {
               QMessageBox::warning(nullptr, "Erreur", "Impossible d'exporter les données : modèle non trouvé.");
               return;
           }

           // Ouvrir une boîte de dialogue pour sélectionner l'emplacement de sauvegarde du fichier PDF
           QString filePath = QFileDialog::getSaveFileName(nullptr, "Exporter vers PDF", "", "Fichiers PDF (&.pdf)");
           if (filePath.isEmpty())
               return; // Annuler l'exportation si aucun fichier n'a été sélectionné

           // Créer un objet QPrinter pour générer le fichier PDF
           QPrinter printer(QPrinter::PrinterResolution);
           printer.setOutputFormat(QPrinter::PdfFormat);
           printer.setPaperSize(QPrinter::A4);
           printer.setOutputFileName(filePath);

           // Créer un objet QPainter pour dessiner sur le périphérique d'impression
           QPainter painter;
           if (!painter.begin((&printer))) {
               QMessageBox::warning(nullptr, "Erreur", "Impossible d'initialiser le périphérique d'impression.");
               return;
           }

           // Dessiner les en-têtes de colonne
           for (int col = 0; col < model->columnCount(); ++col) {
               QString text = model->headerData(col, Qt::Horizontal).toString();
               painter.drawText(col * 140, 20, text);
           }

           // Dessiner les données de la table
           for (int row = 0; row < model->rowCount(); ++row) {
               for (int col = 0; col < model->columnCount(); ++col) {
                   QString text = model->data(model->index(row, col), Qt::DisplayRole).toString();
                   painter.drawText(col * 140, (row + 2) * 20, text);
               }
           }

           // Terminer le dessin
           painter.end();
}
