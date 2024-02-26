#include "mainwindow.h"
#include "diffusion.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}
void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_14A_clicked()
{
       int numSalle=ui->lineEdit_2A->text().toInt();
        int capacite =ui->lineEdit_3A->text().toInt();
        QString etat=ui->lineEdit_4A->text();
         QString dateString = ui->dateEdit->text();
QDate dateRes = QDate::fromString(dateString, "dd-MM-yyyy");

diffusion D(numSalle,capacite,etat,dateRes);
bool test=D.ajout();
if(test)
{
    QMessageBox :: information(this,"Save","Data Inserted successfully", QMessageBox ::Ok);
}


}
