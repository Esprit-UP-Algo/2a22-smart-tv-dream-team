#include "dialog.h"
#include "ui_dialog.h"
#include "media.h"
#include <QLoggingCategory>

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

ui->stackedWidget->setCurrentIndex(0);

//Media
    //on_statisticsM_clicked();
    connect(ui->imageButtonM, &QPushButton::clicked, this, &Dialog::importImage);
    //connect(ui->imageButtonM_2, &QPushButton::clicked, this, &Dialog::importImage);
    connect(ui->radioButtonM, &QRadioButton::clicked, this, [=]() {
        type = "Radio";
    });
    connect(ui->radioButton_2M, &QRadioButton::clicked, this, [=]() {
        type = "Channel";
    });

    Media media;
    connect(ui->exportButtonM, &QPushButton::clicked, [this]() {
      on_exportButtonM_clicked();
    });
    ui->imagetestms->setVisible(false);
    ui->imagetestms_2->setVisible(false);
    ui->upidms->lower();
    ui->lineEdit_epms->setValidator(new QIntValidator(0,9999999,this));
    ui->lineEdit_8ms->setValidator(new QIntValidator(0,99999999,this));
    ui->upepms->setValidator(new QIntValidator(0,9999999,this));
    ui->nbrvupms->setValidator(new QIntValidator(0,99999999,this));
    byte="";
    connect(ui->comboBoxM, &QComboBox::currentTextChanged, this, &Dialog::on_listM_clicked);
    ui->TitleM->setValidator(new QRegExpValidator(QRegExp("[A-Za-z ]+"), this));
    ui->ProducerM->setValidator(new QRegExpValidator(QRegExp("[A-Za-z ]+"), this));
    //connect(ui->buttonM1, &QPushButton::clicked, this, &Dialog::on_buttonM_clicked);
   // connect(ui->buttonM2, &QPushButton::clicked, this, &Dialog::on_buttonM_clicked);
     //on_statisticsM_clicked();
    /*bool estTextEditActive = ui->textEdit->isEnabled();

        // Activez QTextEdit s'il n'est pas déjà activé
        if (!estTextEditActive) {
            ui->textEdit->setEnabled(true);
            qDebug() << "Aucun producteur inséré.";
        }

    textToSpeech = new QTextToSpeech(this);
    connect(textToSpeech, &QTextToSpeech::stateChanged, this, &Dialog::speechStateChanged);
    connect(ui->voiceInputButton, &QPushButton::clicked, this, &Dialog::startVoiceInput);
    QAudioDeviceInfo info(QAudioDeviceInfo::defaultInputDevice());
    if (info.isFormatSupported(info.preferredFormat())) {
        qDebug() << "Microphone activé.";
    } else {
        qDebug() << "Microphone désactivé ou format audio non pris en charge.";
    }
    connect(ui->TitleM, &QLineEdit::textChanged, this, &Dialog::onTextChanged);*/

    /*QLoggingCategory::setFilterRules(QStringLiteral("qt.speech.tts=true \n qt.speech.tts.*=true"));

          // Populate engine selection list
          ui.engine->addItem("Default", QString("default"));
          foreach (QString engine, QTextToSpeech::availableEngines())
              ui.engine->addItem(engine, engine);
          ui.engine->setCurrentIndex(0);
          engineSelected(0);

          connect(ui.speakButton, &QPushButton::clicked, this, &Dialog::speak);
          connect(ui.pitch, &QSlider::valueChanged, this, &Dialog::setPitch);
          connect(ui.rate, &QSlider::valueChanged, this, &Dialog::setRate);
          connect(ui.volume, &QSlider::valueChanged, this, &Dialog::setVolume);
          connect(ui.engine, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &Dialog::engineSelected);*/
    connect(ui->addButtonM, &QPushButton::clicked, this, &Dialog::addMediaItem);
    // Connectez le bouton cancelButtonM pour effacer les données saisies
    connect(ui->cancelButtonM, &QPushButton::clicked, this, &Dialog::clearInputFields);
    textToSpeech = new QTextToSpeech(this);

    // Initialiser le QTimer typingTimer avec un parent this
        typingTimer = new QTimer(this);

        // Connecter le signal timeout du QTimer au slot onTypingTimerTimeout
        connect(typingTimer, &QTimer::timeout, this, &Dialog::onTypingTimerTimeout);


}

Dialog::~Dialog()
{
    delete ui;

}

/*void Dialog::startVoiceInput() {
    QString spokenText = "Please speak your text.";
    textToSpeech->say(spokenText);
    ui->textEdit->append(spokenText);
}
void Dialog::speechStateChanged(QTextToSpeech::State state) {
   if (state == QTextToSpeech::Speaking) {
        ui->textEdit->append("Listening..."); // Indicate that the application is listening for speech input
   }
}
void Dialog::onSpeechStateChanged(QTextToSpeech::State state)
{
    if (state == QTextToSpeech::Ready && !textToSpeechText.isEmpty()) {
        // Lire le texte à voix haute lorsque le moteur est prêt
        textToSpeech->say(textToSpeechText);
        // Réinitialiser le texte à lire à voix haute après lecture
        textToSpeechText.clear();
    }
}*/
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
        QString display = QString("t");
        butt->setObjectName(name);
        butt->setText(display);

        connect(butt, &QPushButton::clicked, this, [this, j]() {
            Media m;
            QString idm = ui->tableViewM->model()->data(ui->tableViewM->model()->index(j, 0)).toString();
            m.generateQRCode(idm);
        });


        butt->setStyleSheet("color:red;"
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
            ui->stackedWidget->setCurrentIndex(17);
            displayChannelImages();
            displayRadioImages();
            QString up = "Data was updated successfully";
                    textToSpeech->say(up);
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
    QString title = ui->TitleM->text();
        QString producer = ui->ProducerM->text();
        QString description = ui->textEditM->toPlainText();

    ui->stackedWidget->setCurrentIndex(11);
    Media m;
    QString titre = ui->TitleM->text();
    QString producteur = ui->ProducerM->text();
    description = ui->textEditM->toPlainText();


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
    Media m;
    ui->stackedWidget->setCurrentIndex(13);
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
    ui->TitleM_2->clear();
    ui->ProducerM_2->clear();
    ui->textEditM_2->clear();
    ui->labelM_2->clear();
    ui->radioButtonM_2->setChecked(false);
    ui->radioButton_2M_2->setChecked(false);


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
    /*QSqlQueryModel *query = new QSqlQueryModel();
    query->setQuery("select id , titre ,description , photo from SERIE_FILM");
    ui->tableView->setModel(query);*/

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
            ui->upepms->setText(ui->tableViewms->model()->data(ui->tableViewms->model()->index(j,7)).toString());
            QPixmap pixmap=ui->tableViewms->model()->data(ui->tableViewms->model()->index(j,5) , Qt::DecorationRole).value<QPixmap>();
            //QMessageBox :: critical(this,"Error",byte);


            QPixmap scaled=  pixmap.scaled(QSize( 200,200));
            ui->imagetest_2ms->setPixmap(scaled);
            ui->stackedWidget->setCurrentIndex(16);
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
            if(T.updatenoimg(ui->upidms->text().toInt(),ui->upepms->text().toInt(),ui->uptitlems->text(),ui->updescriptionms->toPlainText(),ui->nbrvupms->text().toUInt(),ui->dureupms->time().toString()))
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
}

void Dialog::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);
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

void Dialog::on_cancelButtonM_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
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

void Dialog::on_cancelButtonM_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(13);
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
void Dialog::on_buttonM_clicked() {
    // Récupérer le bouton cliqué
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    if (!clickedButton) {
        return;
    }


    QPixmap buttonImage = clickedButton->icon().pixmap(clickedButton->iconSize());


    QSqlQuery query;
    query.prepare("SELECT DESCRIPTION, IMAGE FROM MEDIA WHERE TYPE = 'Channel'");
    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Error retrieving channel images from database.");
        return;
    }

    bool found = false;
    while (query.next()) {

        QByteArray imageData = query.value(1).toByteArray();
        QPixmap dbImage;
        dbImage.loadFromData(imageData);


        if (buttonImage.toImage() == dbImage.toImage()) {
            found = true;


            QString description = query.value(0).toString();
            ui->textEditDescriptionM->setText(description);
            break;
        }
    }

    if (!found) {
        QMessageBox::warning(this, "Warning", "No description found for this image.");
    }
}

void Dialog::on_listM_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
    on_listM_clicked();

}

void Dialog::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(18);
}

void Dialog::on_radioM_clicked()
{
    ui->stackedWidget->setCurrentIndex(18);
}

void Dialog::on_tvM_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}
void Dialog::on_statisticsM_clicked()
{
    ui->stackedWidget->setCurrentIndex(19);
    Media m; // Instance de la classe Media

    // Récupérer les statistiques depuis la classe Media
    QMap<QString, int> statistiques = m.obtenirStatistique();

    // Créer une série de données pour le graphique
    QPieSeries *series = new QPieSeries(); // Utilisez un pointeur pour la série

    for (auto it = statistiques.begin(); it != statistiques.end(); ++it) {
        series->append(it.key(), it.value());
    }

    QChart *chart = new QChart();
    chart->addSeries(series); // Utilisez la série avec le pointeur

    chart->setTitle("Statistics by the number of views of each type of media");

    // Créer une vue de graphique pour afficher le graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(400, 300); // Ajustez la taille selon vos besoins

    // Afficher le graphique dans le QFrame statM
    QVBoxLayout *layout = new QVBoxLayout(ui->statM);
    layout->addWidget(chartView);
    ui->statM->setLayout(layout);
}

void Dialog::on_statisticsM_2_clicked()
{
    on_statisticsM_clicked();
}

void Dialog::addMediaItem() {
    QString title = ui->TitleM->text();
    QString producer = ui->ProducerM->text();
    QString description = ui->textEditM->toPlainText();

    // Utilisez les données (title, producer, description) comme nécessaire
    // Ajoutez le nouvel élément multimédia à votre base de données ou effectuez d'autres actions
}

void Dialog::clearInputFields() {
    ui->TitleM->clear();
    ui->ProducerM->clear();
    ui->textEditM->clear();
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

