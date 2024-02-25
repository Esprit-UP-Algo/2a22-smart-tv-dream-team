#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "movie.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    QVector<QPushButton*> anonymousStorage ;    // Access buttons through their index.
    ui->imagetestms->setVisible(false);
    ui->imagetestms_2->setVisible(false);

    byte="";


    /*for (auto but_index = 1 ; but_index < 3 ; but_index++) {
        // Build the two required strings: internal name + display name.
        // "extfunc1" and "extfunc2" should return something suitable: string, integer, ... according to the current index.
        QString name = QString("button%1").arg(but_index) ;
        QString display = QString("Button%1").arg(but_index) ;

        // Create the button.
        auto newbut = new QPushButton() ;
        newbut->setObjectName(name) ;
        newbut->setText(display) ;
        // Insert here any call to "connect" or other customization functions.

        // Store the new button inside ONE of these containers.
        anonymousStorage.push_back(newbut) ;

    }*/

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2ms_clicked() //bouton add
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_4ms_clicked() //bouton retour de l'ajout
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->lineEdit_2ms->setText("");
    ui->textEditms->setText("");
    //ui->imagetest->setStyleSheet("border-image : none;");
    ui->imagetestms->setVisible(false);
    ui->imagetestms_2->setVisible(false);
}





void MainWindow::on_pushButton_5ms_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_11ms_clicked() //bouton confirm ajout
{

    //QMessageBox :: critical(this,"Error",byte);
    if (byte!="")
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
        if(T.ajout(byte,ui->lineEdit_2ms->text(),ui->textEditms->toPlainText(),9))
        {
             QMessageBox :: information(this,"Save","Data Inserted successfully", QMessageBox ::Ok);
             ui->lineEdit_2ms->setText("");
             ui->textEditms->setText("");
             byte="";
             //ui->imagetest->setStyleSheet("border-image : none;");
             ui->imagetestms->setVisible(false);
             ui->imagetestms_2->setVisible(false);
             ui->stackedWidget->setCurrentIndex(0);
             emit ui->pushButton_12ms->click();
        }
        else
        {
             QMessageBox :: critical(this,"Error","Couldn't insert data");
        }
    }
    else
        QMessageBox :: information(this,"Save","insert a image", QMessageBox ::Ok);
}

void MainWindow::on_pushButton_3ms_clicked() //bouton saisie d'image s'ajout
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








void MainWindow::on_pushButton_12ms_clicked() //bouton d'affichage
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
    //QMessageBox :: warning(this,"",QString::number( ligne));

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
                QPixmap scaled=  pixmap.scaled(QSize( 250,250));
                item = new QStandardItem();
                item->setData(scaled,Qt::DecorationRole);


            }
            else if (j<3)
            {
                item = new QStandardItem(query.value(j).toString());
            }

            if ( j<4)
            {
                item->setTextAlignment(Qt::AlignCenter);

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
    ui->tableViewms->setModel(model);

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
        ui->tableViewms->setIndexWidget(model->index(j, 4), butt);

        butt = new QPushButton("update");
        name = QString("buttonup%1").arg(j) ;
        display = QString("update") ;
        butt->setObjectName(name) ;
        butt->setText(display) ;

        connect(butt, &QPushButton::clicked, this, [this, j]() {
            ui->upidms->setText(QString::number(ui->tableViewms->model()->data(ui->tableViewms->model()->index(j,0)).toInt()   ));
            ui->uptitlems->setText(ui->tableViewms->model()->data(ui->tableViewms->model()->index(j,1)).toString());
            ui->updescriptionms->setText(ui->tableViewms->model()->data(ui->tableViewms->model()->index(j,2)).toString());
            QPixmap pixmap=ui->tableViewms->model()->data(ui->tableViewms->model()->index(j,3) , Qt::DecorationRole).value<QPixmap>();
            //QMessageBox :: critical(this,"Error",byte);


            QPixmap scaled=  pixmap.scaled(QSize( 200,200));
            ui->imagetest_2ms->setPixmap(scaled);
            ui->stackedWidget->setCurrentIndex(2);
        });
        butt->setStyleSheet("color:green;"
                            "background:transparent;"
                            "border:none;"
                            "font : 15pt;");
        ui->tableViewms->setIndexWidget(model->index(j, 5), butt);



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
    ui->tableViewms->resize(ui->tableViewms->rowHeight(0)*row,ui->tableViewms->columnWidth(3)*4);
    ui->tableViewms->resizeRowsToContents();
    ui->tableViewms->resizeColumnsToContents();


}

void MainWindow::on_returnupms_clicked() //bouton de retour d'update
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_confirmupms_clicked() //bouton de confirmation d'update
{

    if (byte!="")
    {
        /*QByteArray byte;
        QFile file(photo);
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
        /*QSqlQuery query;
        query.prepare("UPDATE  MOVIE SET  DESCRIPTION=:description , PHOTO=:photo , TITRE=:titre WHERE ID=:id");
        query.bindValue(":photo", byte);
        query.bindValue(":titre",ui->uptitlems->text());
        query.bindValue(":description",ui->updescriptionms->toPlainText());
        query.bindValue(":id", ui->upidms->text());*/
        MOVIE T;
        if(T.updateimg(ui->upidms->text().toInt(),ui->uptitlems->text(),ui->updescriptionms->toPlainText(),byte))
        {
             QMessageBox :: information(this,"Save","Data updated successfully", QMessageBox ::Ok);
             ui->lineEdit_2ms->setText("");
             ui->textEditms->setText("");
             byte="";
             //ui->imagetest->setStyleSheet("border-image : none;");

             ui->stackedWidget->setCurrentIndex(0);
             emit ui->pushButton_12ms->click();

        }
        else
        {
             QMessageBox :: critical(this,"Error","Couldn't update data");
        }
      }
    else
    {
        //QMessageBox :: critical(this,"Error",photo);
        /*QSqlQuery query;
        query.prepare("UPDATE  MOVIE SET  DESCRIPTION=:description , TITRE=:titre WHERE ID=:id");
        query.bindValue(":titre",ui->uptitlems->text());
        query.bindValue(":description",ui->updescriptionms->toPlainText());
        query.bindValue(":id", ui->upidms->text());*/
        MOVIE T;
        if(T.updatenoimg(ui->upidms->text().toInt(),ui->uptitlems->text(),ui->updescriptionms->toPlainText()))
        {
             QMessageBox :: information(this,"Save","Data updated successfully", QMessageBox ::Ok);
             ui->uptitlems->setText("");
             ui->upidms->setText("");
             ui->updescriptionms->setText("");
             //ui->imagetest->setStyleSheet("border-image : none;");

             ui->stackedWidget->setCurrentIndex(0);
             emit ui->pushButton_12ms->click();
        }
        else
        {
             QMessageBox :: critical(this,"Error","Couldn't updated data");
        }
    }

}

void MainWindow::on_upimagems_clicked() //bouton de saisie d'image d'update
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
