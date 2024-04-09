#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "movie.h"
#include <QScrollBar>
#include <QtCharts/QBarSet>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

#include <QPrinter>
#include <QPainter>


#include <QtCharts/QLegend>

QT_CHARTS_USE_NAMESPACE

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
    //timerId = startTimer(500);


    ui->groupBox_2->setLayout(new QHBoxLayout);
    ui->lineEdit->setText("test");
    socket = new QTcpSocket(this);

    /*auto player = new QMediaPlayer;

    QString imageFile = QFileDialog ::getOpenFileName(0,"Select Image","/home/","Image Files (*.mp4)");
    QFile file(imageFile);
    if(file.open(QIODevice::ReadOnly))
    {
        byte = file.readAll();
        //QMessageBox :: critical(this,"Error",byte);
        file.close();
    }

    QBuffer *buffer = new QBuffer(player);
    buffer->setData(byte);
    buffer->open(QIODevice::ReadOnly);


    player->setMedia( QMediaContent(), buffer);//QUrl::fromLocalFile(imageFile));//"..\\assets\\Right-1684791019526.mp4"));
    //playlist->addMedia(QUrl("http://example.com/myclip2.mp4"));

    auto videoWidget = new QVideoWidget;
    player->setVideoOutput(videoWidget);
    videoWidget->show();
    //playlist->setCurrentIndex(1);
    player->setVolume(80);
    player->setMuted(false);
    auto boxl = new QVBoxLayout();
    boxl->addWidget(videoWidget);
    ui->groupBox->setLayout(boxl);
    player->play();
    byte="";
*/




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

void MainWindow::readyRead()
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

void MainWindow::connected()
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
    if (ui->comboBox_3->currentIndex()==0)
    {
        erreur+="\n-une categorie doit etre selectionné";
    }
    if (ui->comboBox_3->currentText()==ui->comboBox_4->currentText())
    {
        erreur+="\n-la categorie primaire et secondaire doit etre different";
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

        QString imageFile = QFileDialog ::getOpenFileName(0,"Select your trailer","/home/","Image Files (*.mp4 & *.m4v)");
        QFile file(imageFile);
        QByteArray byteT;
        if(file.open(QIODevice::ReadOnly))
        {
            byteT = file.readAll();
            //QMessageBox :: critical(this,"Error",byte);
            file.close();
        }
        if(T.ajout(byte,ui->lineEdit_2ms->text(),ui->textEditms->toPlainText(),ui->lineEdit_8ms->text().toInt(),ui->timeEditms->time().toString()/*"2:00:00"*/,ui->comboBoxms_2->currentText(),nb,ui->comboBox_3->currentText(),ui->comboBox_4->currentText(),byteT))
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
            QSqlQuery query;
            query.exec("select trailer from SERIE_FILM where id="+ui->tableViewms->model()->data(ui->tableViewms->model()->index(j,0)).toString());
            query.next();
            QByteArray array= query.value(0).toByteArray();
            auto player = new QMediaPlayer;
            QBuffer *buffer = new QBuffer(player);
            buffer->setData(array);
            buffer->open(QIODevice::ReadOnly);


            player->setMedia( QMediaContent(), buffer);//QUrl::fromLocalFile(imageFile));//"..\\assets\\Right-1684791019526.mp4"));
            //playlist->addMedia(QUrl("http://example.com/myclip2.mp4"));

            auto videoWidget = new QVideoWidget;
            player->setVideoOutput(videoWidget);
            videoWidget->show();
            //playlist->setCurrentIndex(1);
            player->setVolume(80);
            player->setMuted(false);
            auto boxl = new QVBoxLayout();

            QPushButton *buttr;
            buttr = new QPushButton("return");
            connect(buttr, &QPushButton::clicked, this, [this,boxl,player,videoWidget,buttr]() {
                player->stop();
                delete boxl;
                delete player;
                delete videoWidget;
                delete buttr;
                ui->stackedWidget->setCurrentIndex(0);
            });

            boxl->addWidget(buttr);
            boxl->addWidget(videoWidget);

            ui->groupBox->setLayout(boxl);



            player->play();

            ui->stackedWidget->setCurrentIndex(4);

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
            if(T.updatenoimg(ui->upidms->text().toInt(),ui->upepms->text().toInt(),ui->uptitlems->text(),ui->updescriptionms->toPlainText(),ui->nbrvupms->text().toUInt(),ui->dureupms->time().toString(),ui->comboBox->currentText(),ui->comboBox_2->currentText()))
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

void MainWindow::on_pushButton_clicked()
{
    /*if ( ui->textEdit->toPlainText().length()>0)
    {
        QSqlQuery query;
        query.prepare("INSERT into CHATS(MESSAGE , SENDER, TIME) values (:message , :sender,:time )");
        query.bindValue(":time" , QTime::currentTime());
        query.bindValue(":message",ui->textEdit->toPlainText());
        query.bindValue(":sender",7);
        query.exec();
        ui->textEdit->setText("");
    }*/
    QString message = ui->textEdit->toPlainText().trimmed();

    // Only send the text to the chat server if it's not empty:
    if(!message.isEmpty())
    {
        socket->write(QString(message + "\n").toUtf8());
    }

    // Clear out the input box so they can type something else:
    ui->textEdit->clear();

    // Put the focus back into the input box so they can type again:
    ui->textEdit->setFocus();
}

void MainWindow::on_chatterBUTT_clicked()
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
        ui->stackedWidget->setCurrentIndex(5);
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

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_3_clicked()
{
    qDebug() << "test";
    ui->stackedWidget->setCurrentIndex(6);
    QSqlQuery query;

    QBarSet *set0= new QBarSet("total movies");
    query.exec("select count(*) FROM SERIE_FILM");
    query.next();
    *set0 << query.value(0).toInt();

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
    series->append(set0);
    series->append(set1);
    series->append(set2);
    series->append(set3);
    series->append(set4);
    series->append(set5);
    series->append(set6);
    series->append(set7);
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

    connect(ui->pushButton_4, &QPushButton::clicked, this, [this,view]() {
        ui->groupBox_2->layout()->removeWidget(view);


    });



}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_5_clicked()
{
    // Ouvrir une boîte de dialogue pour sélectionner l'emplacement de sauvegarde du fichier PDF
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
    query.exec("SELECT TITRE , MCATE , SCATE , DUREE , NBREP , NBRVUE , IMAGE FROM SERIE_FILM");
    painter.drawText(100,50, "tableau");
    int row=0;
    int nb=1;
    while ( query.next())
    {
        QByteArray array;
        //qDebug()<<"Initial Array Size"<<array.size();
        array = query.value(6).toByteArray();
        //qDebug()<<"ARray Size"<<array.size();
        QPixmap pixmap;
        pixmap.loadFromData(array,"JPG && PNG",Qt::AutoColor);
        QPixmap scaled=  pixmap.scaled(QSize( 170,170));
        //ui->textEdit_2->setText(ui->textEdit_2->toPlainText()+"\n"+query.value(1).toString() + " : " + query.value(0).toString() + "\n" + query.value(2).toString());
        //ui->textEdit_2->append("<font size='5'><b>"+query.value(2).toString() + "</b> : " + query.value(0).toString() + " </font>  <font  size='0.5'>" + query.value(1).toString()+"</font>");
        painter.drawText(30,row*200+100,"titre : "+query.value(0).toString() );
        painter.drawText(130,row*200+100, "categorie : " + query.value(1).toString() + "/" + query.value(2).toString() );
        painter.drawText(30,row*200+120, "durée : " + query.value(3).toString());
        painter.drawText(130,row*200+120,"nombre d'épisode :"+ query.value(4).toString() );
        painter.drawText(30,row*200+140,"nombre de vue : " + query.value(5).toString() );
        painter.drawPixmap(310,row*200-40+100,scaled);
        row++;
        qDebug()<<"check";
        if ( nb==1)
        {
            if ( row*200+100+170>850)
            {
                qDebug()<<"page added";
                printer.newPage();
                nb++;
                row=0;
            }
        }
        else
        {
            if ( row*10>850)
            {
                qDebug()<<"page added";
                printer.newPage();
                nb++;
                row=3;
            }
        }

    }



    // Terminer le dessin
    painter.end();

    QMessageBox::information(nullptr, "Succès", "Les données ont été exportées avec succès vers " + filePath);
}
