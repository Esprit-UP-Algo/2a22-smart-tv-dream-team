#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employer.h"
#include"dialog.h"
#include<QString>
#include <ios>
#include <QMessageBox>
#include <cctype>
#include <QStackedWidget>
#include<QMovie>
#include<QThread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint| Qt::WindowSystemMenuHint);


    ui->label_gif_animation->setVisible(false);
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ok_13_clicked()
{
    employer e;
    e.setuser(ui->lineEdit_Username_11->text());
    e.setpassword(ui->lineEdit_Password_11->text());
    e.Validateuser();
    e.Validatepassword();
    if (e.Validateuser()==true)
    {
        if (e.Validatepassword())
        {
            QMovie *GifAnimation=new QMovie("../veveveve.gif");
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

            close();
            Dialog d;
            d.exec();
        }
        else
        {
            QMessageBox messageBox;
            QMessageBox::critical(this, "Erreur", "your password doesn't match our requirements");
            messageBox.setFixedSize(400,200);
        }

    }
    else
    {
        QMessageBox messageBox;
        QMessageBox::critical(this, "Erreur", "your username must be atleast 4 characters long");
        messageBox.setFixedSize(400,200);
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
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_ok_12_clicked()
{
    employer e;
    e.setuser(ui->lineEdit_Username_10->text());
    e.setpassword(ui->lineEdit_Password_10->text());
    e.Validateuser();
    e.Validatepassword();
    if (e.Validateuser()==true)
    {
        if ((e.Validatepassword()))
        {
            close();
            Dialog d;
            d.exec();
        }
        else
        {
            QMessageBox messageBox;
            QMessageBox::critical(this, "Erreur", "your password doesn't match our requirements");
            messageBox.setFixedSize(400,200);
        }

    }
    else
    {
        QMessageBox messageBox;
        QMessageBox::critical(this, "Erreur", "your username must be atleast 4 characters long");
        messageBox.setFixedSize(400,200);
    }
}
