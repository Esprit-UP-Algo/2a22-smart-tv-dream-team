#include "mainwindow.h"
#include "ui_mainwindow.h"
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
}
MainWindow::~MainWindow()
{
    delete ui;
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
        connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

        if( !files.isEmpty() )
            smtp->sendMail(ui->uname->text(), ui->email->text() , ui->subject->text(),pas, files );
        else
            smtp->sendMail(ui->uname->text(), ui->email->text() , ui->subject->text(),pas);
        delete smtp;
    }
}

void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}

void MainWindow::on_ok_13_clicked()
{
    QString Username = ui->lineEdit_Username_11->text();
    QString Password = ui->lineEdit_Password_11->text();
    QString Role;
    if (authenticateUser(Username, Password, Role))
    {
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
        GifAnimation->stop();
        delete GifAnimation;
        this->close();
        Dialog *dialog = new Dialog();
        dialog->Role=Role;
        dialog->trait(Role);
        dialog->exec();
    }
    else
    {
        QMessageBox::warning(this, "Login Failed", "Incorrect username or password. Please try again.");
    }
}

bool MainWindow::authenticateUser(const QString &Username, const QString &Password, QString &Role)
{
    QSqlQuery query;
    query.prepare("SELECT type FROM EMPLOYE WHERE username = :username AND password = :password");
    query.bindValue(":username",Username);
    query.bindValue(":password",Password);
    if (!query.exec())
    {
        QMessageBox::critical(this, "Error", "Query execution failed.");
        return false;
    }

    if (query.next())
    {
        Role = query.value(0).toString();
        return true;
    }
    else
    {
        return false;
    }
}


void MainWindow::on_ok_2_clicked()
{
    close();
}

void MainWindow::on_ok_3_clicked()
{
    setWindowState(Qt::WindowMinimized);
}

void MainWindow::on_ku_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
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
