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
#include <QRegularExpression>



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
    QSqlDatabase db = QSqlDatabase::database();
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


    int rowCount = model->rowCount();
    for (int row = 0; row < rowCount; ++row)
    {
        QPushButton *deleteButton = new QPushButton("Delete");
        deleteButton->setStyleSheet("color: red;");


        connect(deleteButton, &QPushButton::clicked, this, [this, row]() {
            QModelIndex index = ui->tableView->model()->index(row, 0); // Assuming numSalle is in the first column
            if (index.isValid()) {
                int numSalle = index.data().toInt();
                if (QMessageBox::question(this, "Confirmation", "Are you sure you want to delete this row?", QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
                    diffusion diff;
                    if (diff.supprimerSalleDiffusion(numSalle)) {
                        QMessageBox::information(this, "Success", "Row deleted successfully.");
                        on_pushButton_UPDATE_3_clicked(); // Refresh the table view
                    } else {
                        QMessageBox::critical(this, "Error", "Failed to delete row.");
                    }
                }
            }
        });

        ui->tableView->setIndexWidget(model->index(row, 4), deleteButton); // Place delete button in the new column
    }
}


void MainWindow::on_pushButton_3_clicked()
{
        diffusion diff;
        QString numSalleText = ui->lineEdit_2->text();

        if (numSalleText.isEmpty()) {
            QMessageBox msgBox;
            msgBox.setStyleSheet("QMessageBox { background-color: qlineargradient(spread: pad, x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 rgba(24, 27, 32, 255), stop: 1 rgba(24, 27, 32, 255)), border-radius:30px; }"
                                 "QMessageBox QPushButton { color: white; }");
            msgBox.warning(this, "Error", "Please fill the Salle Number field", QMessageBox::Ok);
            return;
        }

        bool conversionOK;
        int numSalle = numSalleText.toInt(&conversionOK);
        if (!conversionOK) {
            QMessageBox::critical(nullptr, QObject::tr("Invalid Input"),
                                  QObject::tr("Please enter a valid number for Salle Number"), QMessageBox::Cancel);
            return;
        }

        QStringList salleInfo = diff.GetSalleInformation(numSalle);
        if (salleInfo.isEmpty()) {
            QMessageBox::critical(nullptr, QObject::tr("Invalid Salle Number"),
                                  QObject::tr("Salle with number %1 not found").arg(numSalle), QMessageBox::Cancel);
        } else {
            ui->lineEdit_3->setText(salleInfo[0]);
            ui->lineEdit_4->setText(salleInfo[1]);
            QDate date = QDate::fromString(salleInfo[2], Qt::ISODate);
               ui->dateEdit1->setDate(date);        }

}





void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_UPDATE_2_clicked()
{
    QString numSalleText = ui->lineEdit_2->text();
    QString capaciteText = ui->lineEdit_3->text();
    QString etat = ui->lineEdit_4->text();
    QDate dateRes = ui->dateEdit->date();

    if (numSalleText.isEmpty() || capaciteText.isEmpty() || etat.isEmpty()) {
        QMessageBox msgBox;
        msgBox.setStyleSheet("QMessageBox { background-color: qlineargradient(spread: pad, x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 rgba(24, 27, 32, 255), stop: 1 rgba(24, 27, 32, 255)), border-radius:30px; }"
                             "QMessageBox QPushButton { color: white; }");
        msgBox.warning(this, "Error", "Please fill all the fields", QMessageBox::Ok);
        return;
    }

    bool conversionOK;
    int numSalle = numSalleText.toInt(&conversionOK);
    if (!conversionOK) {
        QMessageBox::critical(nullptr, QObject::tr("Invalid Input"),
                              QObject::tr("Please enter a valid number for Salle Number"), QMessageBox::Cancel);
        return;
    }

    int capacite = capaciteText.toInt(&conversionOK);
    if (!conversionOK) {
        QMessageBox::critical(nullptr, QObject::tr("Invalid Input"),
                              QObject::tr("Please enter a valid number for Capacite"), QMessageBox::Cancel);
        return;
    }

    diffusion diff;

    bool test = diff.UpdateSalleDiffusion(numSalle, capacite, etat, dateRes);

    if (test) {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Mise à jour effectuée\nClick Cancel to exit."), QMessageBox::Cancel);

        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
        ui->dateEdit1->setDate(QDate::currentDate()); // Corrected the line to set dateEdit
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Mise à jour non effectuée\nClick Cancel to exit."), QMessageBox::Cancel);
    }
}

connect(ui->comboBox, &QComboBox::currentIndexChanged, this, &MainWindow::sortByNumSalle);

// Slot to sort the data in the QTableView based on the selected numSalle
void MainWindow::sortByNumSalle(const QString &selectedNumSalle) {
    if (selectedNumSalle == "NumSalle") {
        ui->tableView->sortByColumn(0, Qt::AscendingOrder);
    }
    // Add more conditions for other sorting options if needed
}

