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
            QString rech;
        int row(0);
        QSqlQuery query;

        if (ui->textEdit_2->toPlainText()!="")
            {
                rech=" where username LIKE '%"+ui->textEdit_2->toPlainText()+"%'";
                bool intyes;
                ui->textEdit_2->toPlainText().toInt(&intyes);
                qDebug()<<intyes;
                if (intyes)
                {
                    rech+=" or id="+ui->textEdit_2->toPlainText();
                }



            }


        query.exec("select count(*) from employe"+rech);
        while(query.next() )
        {
            ligne=query.value(0).toInt();
        }
        //QMessageBox :: warning(this,"",QString::number( ligne));
        QString Qs;


            if (ui->comboBox_3->currentText()== "Usernames from A to Z" )
            {
                Qs=" order by username ASC";
                qDebug()<<"test";
            }
            else if (ui->comboBox_3->currentText()== "Usernames from Z to A" )
            {
                Qs=" order by username DESC";
                qDebug()<<"test";
            }
            else if (ui->comboBox_3->currentText()== "Id Descendant" )
            {
                Qs=" order by id DESC";
                qDebug()<<"test";
            }
            else if (ui->comboBox_3->currentText()== "Id Ascendant" )
            {
                Qs=" order by id ASC";
                qDebug()<<"test";
            }


        QStandardItemModel * model=new QStandardItemModel(ligne , 7);
        query.exec("select id , username , password , type , photo from employe"+rech+Qs);
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



        model->setHeaderData(0, Qt::Horizontal , "ID");
        model->setHeaderData(1, Qt::Horizontal , "USERNAME");
        model->setHeaderData(2, Qt::Horizontal , "PASSWORD");
        model->setHeaderData(3, Qt::Horizontal , "TYPE");
        model->setHeaderData(4, Qt::Horizontal , "PHOTO");
        model->setHeaderData(5, Qt::Horizontal , "DELETE");
        model->setHeaderData(6, Qt::Horizontal , "UPDATE");
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
                //QMessageBox :: critical(this,"Error",byte);
                ui->stackedWidget->setCurrentIndex(3);
                ui->lineEdit_10->setText(ui->tableViewem->model()->data(ui->tableViewem->model()->index(j,0)).toString());
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
void Dialog::on_hihi_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
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
        ui->label_73->setVisible(false);
       } else {
        ui->label_11->setVisible(true);
        ui->label_13->setVisible(true);
        ui->label_65->setVisible(true);
        ui->pushButton_8->setVisible(true);
        ui->pushButton_9M->setVisible(true);
        ui->label_71->setVisible(true);
        ui->label_72->setVisible(true);
        ui->label_73->setVisible(true);

        ui->label_11->raise();
        ui->label_13->raise();
        ui->label_65->raise();
        ui->pushButton_8->raise();
        ui->pushButton_9M->raise();
        ui->label_71->raise();
        ui->label_72->raise();
        ui->label_73->raise();
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
void Dialog::on_vewatchButtonM_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}



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

void Dialog::on_hihi_10tr_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
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
    ui->stackedWidget->setCurrentIndex(13);
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
            query.prepare("insert into employe (username,password,type,photo) values (:username,:password,:type,:photo)");
            query.bindValue(":username",ui->lineEdit_5->text());
            query.bindValue(":password",ui->lineEdit_6->text());
            query.bindValue(":type",ui->lineEdit_7->text());
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
            query.bindValue(":type",ui->lineEdit_7->text());
            query.bindValue(":photo",byte);
            query.bindValue(":id",ui->lineEdit_10->text().toInt());
            qDebug()<<ui->lineEdit_7->text();
            qDebug()<<ui->lineEdit_10->text().toInt();
            qDebug()<<ui->lineEdit_6->text();
            qDebug()<<ui->lineEdit_5->text();
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

void Dialog::on_hihi_35_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void Dialog::on_hihi_37_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void Dialog::on_hihi_10tr_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void Dialog::on_gg_3_clicked()
{
    emit ui->hihi_5->click();
}
