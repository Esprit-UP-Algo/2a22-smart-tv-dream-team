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
    ui->upidms->lower();
    ui->lineEdit_epms->setValidator(new QIntValidator(0,9999999,this));
    ui->lineEdit_8ms->setValidator(new QIntValidator(0,99999999,this));
    ui->upepms->setValidator(new QIntValidator(0,9999999,this));
    ui->nbrvupms->setValidator(new QIntValidator(0,99999999,this));
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
    if (checkuni!=0)
    {
        erreur+="\n-un titre doit etre unique ( ce titre existe deja )";
    }




    if (ui->textEditms->toPlainText().count()<10)
    {
        erreur+="\n-une description de au moins 10 caractére est necessaire";
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
        if(T.ajout(byte,ui->lineEdit_2ms->text(),ui->textEditms->toPlainText(),ui->lineEdit_8ms->text().toInt(),ui->timeEditms->time().toString()/*"2:00:00"*/,ui->comboBoxms_2->currentText(),nb))
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
    query->setQuery("select id , titre ,description , photo from SERIE_FILM");
    ui->tableView->setModel(query);*/

    int ligne(0);
    int row(0);
    QString rech;
    if (ui->lineEditms->text()!="")
    {
        rech=" where TITRE LIKE '%"+ui->lineEditms->text()+"%'";
        bool intyes;
        ui->lineEditms->text().toInt(&intyes);
        qDebug()<<intyes;
        if (intyes)
        {
            rech+=" or id='"+ui->lineEditms->text()+"'";
        }



    }
    QSqlQuery query;
    query.exec("select count(*) from SERIE_FILM"+rech);
    while(query.next() )
    {
        ligne=query.value(0).toInt();
    }
    qDebug()<<ligne;
    //QMessageBox :: warning(this,"",QString::number( ligne));

    QStandardItemModel * model=new QStandardItemModel(ligne , 10);
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
    qDebug()<<"select id ,type, titre ,description ,duree, image,nbrvue,nbrep from SERIE_FILM"+rech +Qs;
    query.exec("select id ,type, titre ,description ,duree, image,nbrvue,nbrep from SERIE_FILM"+rech +Qs);
    while(query.next())
    {
        for (int j=0;j<8;j++)
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
    model->setHeaderData(8, Qt::Horizontal , "delete");
    model->setHeaderData(9, Qt::Horizontal , "update");
    ui->tableViewms->setModel(model);
    ui->tableViewms->horizontalHeader()->setVisible(true);

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
        ui->tableViewms->setIndexWidget(model->index(j, 8), butt);

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
        ui->tableViewms->setIndexWidget(model->index(j, 9), butt);



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


}

void MainWindow::on_returnupms_clicked() //bouton de retour d'update
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_confirmupms_clicked() //bouton de confirmation d'update
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
    if (erreur=="")
    {
        if (byte!="")
        {

            MOVIE T;
            if(T.updateimg(ui->upidms->text().toInt(),ui->upepms->text().toInt(),ui->uptitlems->text(),ui->updescriptionms->toPlainText(),byte,ui->nbrvupms->text().toUInt(),ui->dureupms->time().toString()))
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

            MOVIE T;
            if(T.updatenoimg(ui->upidms->text().toInt(),ui->upepms->text().toInt(),ui->uptitlems->text(),ui->updescriptionms->toPlainText(),ui->nbrvupms->text().toUInt(),ui->dureupms->time().toString()))
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

void MainWindow::on_pushButtonms_clicked()
{
    emit ui->pushButton_12ms->click();
}

void MainWindow::on_comboBoxms_2_currentTextChanged(const QString &arg1)
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

void MainWindow::on_comboBoxms_currentIndexChanged(const QString &arg1)
{
    emit ui->pushButton_12ms->click();
}
