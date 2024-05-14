#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "smtp.h"
#include <QtWidgets/QMessageBox>
#include <QFileDialog>
#include <QMainWindow>
#include<QString>
#include<QStackedWidget>
#include<qstackedwidget.h>
#include <QtMultimedia>
#include<QtMultimediaWidgets>
#include<QtCore>
#include<QtGui>
#include<QtWidgets>

#include "employer.h"
#include "dialog.h"
#include<QString>
#include "ui_dialog.h"
#include <ios>
#include <QMessageBox>
#include <cctype>
#include <QStackedWidget>
#include<QMovie>
#include<QThread>
#include <QtGlobal>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int ret=A.connect_arduino(); // lancer la connexion à arduino
         switch(ret){
         case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();

             QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(confirm_accesss()));
             break;
         case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
            break;
         case(-1):qDebug() << "arduino is not available";
         }

    setWindowFlags(Qt::FramelessWindowHint| Qt::WindowSystemMenuHint);
    connect(ui->ok_16, SIGNAL(clicked()),this, SLOT(sendMail()));
    ui->stackedWidget->setCurrentIndex(0);
    ui->server->setVisible(false);
    ui->port->setVisible(false);
    ui->uname->setVisible(false);
    ui->paswd->setVisible(false);
    ui->subject->setVisible(false);
    ui->msg->setVisible(false);
    ui->label_gif_animation->setVisible(false);
    /*//Media
        int reta= AM.connect_arduino();
        switch(reta){
        case(0):qDebug()<< "arduino is available and connected to : "<<AM.getarduino_port_name();
            break;
        case(1):qDebug()<< "arduino is available but not connected to : "<<AM.getarduino_port_name();
            break;
        case(-1):qDebug()<< "arduino is not available "<<AM.getarduino_port_name();
            break;

        }*/
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::confirm_accesss()
{
    QSqlQuery query;
    QString fingerprintData;
    QByteArray data = A.read_from_arduino();

    if (!data.isEmpty())
    {
        fingerprintData = QString::fromUtf8(data); // Assuming data is in UTF-8 format
        qDebug() << "Fingerprint data received:" << fingerprintData;
    }

    query.prepare("SELECT IDE ,type ,empreinte FROM EMPLOYE WHERE empreinte = :empreinte");
    query.bindValue(":empreinte", fingerprintData);
    query.exec();

    if (query.next())
    {
        // Fingerprint found in the database
        QMovie *gifAnimation = new QMovie("veveveve.gif");
        ui->label_gif_animation->setMovie(gifAnimation);
        ui->label_gif_animation->setVisible(true);
        ui->label_gif_animation->raise();
        gifAnimation->start();

        for (int i = 0; i < 300; i++)
        {
            QThread::msleep(1);
            qApp->processEvents(QEventLoop::AllEvents);
        }

        ui->label_gif_animation->setVisible(false);
        gifAnimation->stop();
        this->close();
        A.close_arduino();

        // Assuming Role is determined elsewhere
        Dialog *dialog = new Dialog();
        dialog->Role= query.value(1).toString();
        dialog->id=query.value(0).toInt();

        dialog->pfp(dialog->id);
        dialog->trait(dialog->Role);
        dialog->exec();
    }
    else
    {
        // No matching fingerprint found in the database
        QMessageBox::warning(this, "Login Failed", "No fingerprint detected. Please try again.");
    }
}

void MainWindow::sendMail()
{
    QSqlQuery query;
    QString pas;
    QString email = ui->email->text();
    query.prepare("SELECT password FROM EMPLOYE WHERE email = :email");
    query.bindValue(":email",email);
    if (!query.exec())
    {
        QMessageBox::critical(this, "Error", "Query execution failed.");
    }

    else if (query.next())
    {
        pas = query.value(0).toString();
        Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toInt());
        qDebug()<<smtp;
        connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString,*smtp)));

        //if( !files.isEmpty() )
        smtp->sendMail(ui->uname->text(), ui->email->text() , ui->subject->text(),pas, files );
        /*else
            smtp->sendMail(ui->uname->text(), ui->email->text() , ui->subject->text(),pas);
*/

    }
}

void MainWindow::mailSent(QString status, Smtp *s)
{
    if(status == "Message sent")
    {
         delete s;
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    }

}

void MainWindow::on_ok_13_clicked()
{
    QString Username = ui->lineEdit_Username_11->text();
    QString Password = ui->lineEdit_Password_11->text();
    QString Role;
    int id=authenticateUser(Username, Password, Role);
    if (id!=-1)
    { QString welcomeMessage = "Good morning ";

        if (Role == "Admin") {
               welcomeMessage += "Admin";
           } else if (Role == "Financier") {
               welcomeMessage += "Financier";
           } else if (Role == "Media Manager") {
               welcomeMessage += "Media Manager";
           } else if (Role == "HR") {
               welcomeMessage += "HR";
           } else {
               welcomeMessage += "User";
           }

           welcomeMessage += " " + Username + "!";

           // Convert QString to QByteArray
           QByteArray message = welcomeMessage.toUtf8();
                      A.write_to_arduino(message);
        QByteArray command="P3";
        A.write_to_arduino(command);

        QMovie *GifAnimation=new QMovie("veveveve.gif");
        ui->label_gif_animation->setMovie(GifAnimation);
        ui->label_gif_animation->setVisible(true);
        ui->label_gif_animation->raise();
        GifAnimation->start();
        for(int i=0;i<300;i++)
        {
            QThread::msleep(1);
            qApp->processEvents(QEventLoop::AllEvents);

        }
        ui->label_gif_animation->setVisible(false);
       A.close_arduino();
        GifAnimation->stop();
        delete GifAnimation;
        this->close();
        Dialog *dialog = new Dialog();
        dialog->Role=Role;
        dialog->id=id;

        dialog->pfp(dialog->id);
        dialog->trait(Role);
        dialog->exec();
    }
    else
    {
        QMessageBox::warning(this, "Login Failed", "Incorrect username or password. Please try again.");
    }
}

int  MainWindow::authenticateUser(const QString &Username, const QString &Password, QString &Role)
{
    QSqlQuery query;
    query.prepare("SELECT IDE ,type FROM EMPLOYE WHERE username = :username AND password = :password");
    query.bindValue(":username",Username);
    query.bindValue(":password",Password);
    if (!query.exec())
    {
        QMessageBox::critical(this, "Error", "Query execution failed.");
        return false;
    }

    if (query.next())
    {
        Role = query.value(1).toString();
        return query.value(0).toInt();
    }
    else
    {
        return -1;
    }
}


void MainWindow::on_ok_15_clicked()
{
    close();
}

void MainWindow::on_ok_14_clicked()
{
    setWindowState(Qt::WindowMinimized);
}

void MainWindow::on_ku_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_ok_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
