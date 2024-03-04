#include "mainwindow.h"
#include "diffusion.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QPushButton>
#include <QString>
#include <QDate>
#include <QByteArray>
#include <QStackedWidget>
#include <QTableView>
#include <QWidget>
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QLineEdit>

MainWindow::MainWindow(QWidget * parent):
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlQueryModel *model = diff.afficherDiffusions();

      ui->tableView->setModel(model);

}


MainWindow::~MainWindow()
{
    delete ui;
}
diffusion::diffusion() {
    // Constructor implementation, if needed
}
void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}
void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
bool MainWindow::isStudioReserved(const QDate &dateRes)
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isValid()) {
        qDebug() << "Database connection is invalid";
        return false;
    }


    QSqlQuery query(db);
    query.prepare("SELECT COUNT(*) FROM diffusion WHERE dateRes = :dateRes");
    query.bindValue(":dateRes", dateRes);

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return false;
    }
    if (query.next()) {
        int count = query.value(0).toInt();
        return count > 0;
    } else {
        qDebug() << "No result found for query";
        return false;
    }
}

bool MainWindow::isStudioRepeated(int numSalle)
{
    QSqlDatabase db = QSqlDatabase::database(); // Get the default database connection
    if (!db.isValid()) {
        qDebug() << "Database connection is invalid";
        return false;
    }
    QSqlQuery query(db);
    query.prepare("SELECT COUNT(*) FROM diffusion WHERE numSalle = :numSalle");
    query.bindValue(":numSalle", numSalle);

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return false;
    }
    if (query.next()) {
        int count = query.value(0).toInt();
        return count > 0;
    } else {
        qDebug() << "No result found for query";
        return false;
    }
}

void MainWindow::on_pushButton_14A_clicked()
{
    diffusion diff;
    QString numSalleText = ui->lineEdit_2A->text();
    QString capaciteText = ui->lineEdit_3A->text();
    QString etat = ui->lineEdit4A->text();
    QString dateString = ui->dateEdit->text();


    if (numSalleText.isEmpty() || capaciteText.isEmpty() || etat.isEmpty() || dateString.isEmpty()) {
        QMessageBox msgBox;
                msgBox.setStyleSheet("QMessageBox { background-color:  qlineargradient(spread: pad, x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 rgba(24, 27, 32, 255), stop: 1 rgba(24, 27, 32, 255)), border-radius:30px; }"
                                     "QMessageBox QPushButton { color: white; }");
                msgBox.warning(this, "Error", "Please fill all the fields", QMessageBox::Ok);
                return;
            }

    int numSalle = numSalleText.toInt();


    if (isStudioRepeated(numSalle)) {
        QMessageBox::warning(this, "Error", "Studio number is already in use. Please choose another number.", QMessageBox::Ok);
        return;
    }


    QDate dateRes = QDate::fromString(dateString, "dd/MM/yyyy");

    qDebug() << dateRes;

    qDebug() << dateString;
    if (isStudioReserved(dateRes)) {
        QMessageBox::warning(this, "Error", "Studio is already reserved at that time", QMessageBox::Ok);
        return;
    }

    if (etat != "empty" && etat != "reserved" && etat != "full") {
           QMessageBox::warning(this, "Error", "Invalid value for etat. Please enter 'empty', 'reserved', or 'full'.", QMessageBox::Ok);
           return;
       }

    int capacite = capaciteText.toInt();

    diffusion data(numSalle, capacite, etat, dateRes);
    bool test = data.ajoutSalle(numSalle, capacite, etat, dateRes);

    if (test) {
         //QSqlQueryModel *model = diff.afficherDiffusions();
        QMessageBox :: information(this,"Save","Data Inserted successfully", QMessageBox ::Ok);
    } else {
        QMessageBox::warning(this, "Error", "Failed to insert data", QMessageBox::Ok);
    }
}



void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}







void MainWindow::on_pushButton_UPDATE_3_clicked()
{
    QSqlQueryModel *model = diff.afficherDiffusions();
       ui->tableView->setModel(model);


}

void MainWindow::on_pushButton_UPDATE_clicked()
{
    int num= ui->lineEdit->text().toInt();
    bool test=diff.supprimerSalleDiffusion(num);
    if (test) {
    QMessageBox::information(nullptr, QObject::tr("OK"),
            QObject::tr("Suppression effectuee\n" "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical
                (nullptr, QObject::tr("Not OK"),
                QObject::tr("Suppression non effectuee\n" "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pushButton_UPDATE_2_clicked()
{
    diffusion diff;
    bool test=diff.UpdateSalleDiffusion(int numSalle, int capacite, QString etat);
    QString numSalleText = ui->lineEdit_2->text();
    QString capaciteText = ui->lineEdit_3->text();
    QString etat = ui->lineEdit_4->text();
    if (numSalleText.isEmpty() || capaciteText.isEmpty() || etat.isEmpty()) {
        QMessageBox msgBox;
                msgBox.setStyleSheet("QMessageBox { background-color:  qlineargradient(spread: pad, x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 rgba(24, 27, 32, 255), stop: 1 rgba(24, 27, 32, 255)), border-radius:30px; }"
                                     "QMessageBox QPushButton { color: white; }");
                msgBox.warning(this, "Error", "Please fill all the fields", QMessageBox::Ok);
                return;
            }
    if (test) {
    QMessageBox::information(nullptr, QObject::tr("OK"),
            QObject::tr("Mise a jour effectuee\n" "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical
                (nullptr, QObject::tr("Not OK"),
                QObject::tr("Mise a jour non effectuee\n" "Click Cancel to exit."), QMessageBox::Cancel);


}
