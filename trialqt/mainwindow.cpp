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
#include <QComboBox>
#include <QObject>
#include <QSystemTrayIcon>
#include <QPainter>
#include <QPrinter>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QChart>
#include <QVBoxLayout>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>

MainWindow::MainWindow(QWidget * parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);


      initializeCalendar();
      QTimer *timer = new QTimer(this);

      // Connect the timer's timeout() signal to the refreshCalendar() slot
      connect(timer, &QTimer::timeout, this, &MainWindow::refreshCalendar);

      // Set the interval for the timer (in milliseconds)
      timer->start(10000);
       QSqlQueryModel *model = diff.afficherDiffusions();
       ui->tableView->setModel(model);
       connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(on_comboBox_currentIndexChanged(int)));

          updateTotalStudios();
             notificationTimer = new QTimer(this);

             // Connect the timer's timeout signal to your slot
             connect(notificationTimer, &QTimer::timeout, this, &MainWindow::checkReservationDates);

             notificationTimer->start(20000);

             mSystemTrayIcon = new QSystemTrayIcon(this);

              mSystemTrayIcon->setIcon(QIcon(":/myappico.png"));
          mSystemTrayIcon->setToolTip("Studio Management Application");

          mSystemTrayIcon->setVisible(true);



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


void MainWindow::on_comboBox_currentIndexChanged()
{
    QString sortOption = ui->comboBox->currentText();
    QSqlQueryModel *model = new QSqlQueryModel();

    if (sortOption == "Tri asc by numSalle")
    {
        model->setQuery("SELECT * FROM diffusion ORDER BY numSalle ASC");
    }
    else if (sortOption == "Tri desc by numSalle")
    {
        model->setQuery("SELECT * FROM diffusion ORDER BY numSalle DESC");
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("numSalle"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("capacite"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("dateRes"));
    model->insertColumn(4);
    model->setHeaderData(4, Qt::Horizontal, QObject::tr(""));

    ui->tableView->setModel(model);
}






void MainWindow::on_pushButton_4A_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_pushButton_10A_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_pushButton_16A_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_8A_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}



void MainWindow::on_pushButton_4_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(nullptr, "Export to PDF", "", "PDF files (*.pdf)");
    if (filePath.isEmpty())
        return; // Cancel export if no file is selected

    // Create a QPrinter object to generate the PDF file
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(filePath);

    QPainter painter;
    if (!painter.begin(&printer)) {
        QMessageBox::warning(nullptr, "Error", "Cannot start printing");
        return;
    }

    // Define the size of the table cells
    int cellWidth = 140; // Adjust as needed
    int cellHeight = 30; // Adjust as needed

    // Company logo
    QPixmap logo("C:/Users/amalm/Downloads/vewatchapp.png");
    if (logo.isNull()) {
        QMessageBox::warning(nullptr, "Error", "Failed to load logo image.");
        qDebug() << "Failed to load logo image.";
    } else {
        QRect logoRect(10, 10, 100, 100);
        painter.drawPixmap(logoRect, logo);
        qDebug() << "Logo image loaded successfully.";
    }

    // Background Image
    QPixmap background("C:/Users/amalm/Downloads/backgroundpdf.png");
    QRect backgroundRect(0, 0, printer.pageRect().width(), printer.pageRect().height());
    painter.drawPixmap(backgroundRect, background);

    // Title
    QFont titleFont = painter.font();
    titleFont.setPointSize(24);
    painter.setFont(titleFont);
    QColor originalColor = painter.pen().color();
    painter.setPen(QColor(0, 0, 139));
    QRect titleRect(0, 120, printer.pageRect().width(), 50);
    painter.drawText(titleRect, Qt::AlignCenter, "Studios List");
    painter.setPen(originalColor);

    // Draw column headers in the PDF file
    QStringList headers = {"Studio Number", "State", "Capacity", "Reservation Date"};
    int colCount = headers.size();
    QFont font = painter.font();
    font.setPointSize(12);
    font.setBold(true);
    painter.setFont(font);
    for (int col = 0; col < colCount; ++col) {
        painter.drawText(col * cellWidth, 300, cellWidth, cellHeight, Qt::AlignCenter, headers[col]); // Adjusted position
        painter.drawRect(col * cellWidth, 300, cellWidth, cellHeight);
    }

    // Initialize and execute database query
    QSqlQuery query;
    query.prepare("SELECT NUMSALLE, ETAT, CAPACITE, DATERES FROM DIFFUSION");
    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Error", "Error retrieving data from the database.");
        return;
    }

    // Draw table data in the PDF file
    int row = 0;
    while (query.next()) {
        for (int col = 0; col < colCount; ++col) {
            QString text = query.value(col).toString();
            painter.drawText(col * cellWidth, 330 + (row + 1) * cellHeight, cellWidth, cellHeight, Qt::AlignCenter, text); // Adjusted position
            painter.drawRect(col * cellWidth, 330 + (row + 1) * cellHeight, cellWidth, cellHeight);
        }
        ++row;
    }

    // Export Date
    QDateTime currentDateTime = QDateTime::currentDateTime();
    painter.drawText(printer.pageRect().width() - 150, printer.pageRect().bottom() - 20, currentDateTime.toString("dd.MM.yyyy"));

    // End drawing
    painter.end();

    QMessageBox::information(nullptr, "Success", "Data has been successfully exported to " + filePath);

    }


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{

        QString searchText = arg1.trimmed();
        if (searchText.isEmpty()) {
            // If lineEdit is empty, reset the tableView
            on_pushButton_UPDATE_3_clicked();
            return;
        }

        QString queryText;

        if (searchText.length() == 1) {
            // If only one letter is entered, search for rows starting with that letter
            queryText = "SELECT NUMSALLE, CAPACITE, ETAT, DATERES FROM DIFFUSION WHERE NUMSALLE LIKE '" + searchText + "%'";
        } else {
            // Otherwise, search for rows containing the complete text
            queryText = "SELECT NUMSALLE, CAPACITE, ETAT, DATERES FROM DIFFUSION WHERE NUMSALLE LIKE '%" + searchText + "%'";
        }

        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery(queryText);

        ui->tableView->setModel(model);



}

void MainWindow::on_pushButton_5_clicked()
{
    diffusion d;

            // Récupérer les statistiques depuis la classe diffusion
            QMap<QString, int> statistiques = d.obtenirStatistique();

            // Créer une série de données pour le graphique
            QtCharts::QBarSeries *series = new QtCharts::QBarSeries();

            // Ajouter les données à la série
            for (auto it = statistiques.begin(); it != statistiques.end(); ++it) {
                QtCharts::QBarSet *barSet = new QtCharts::QBarSet(it.key());
                *barSet << it.value();
                series->append(barSet);
            }

            QtCharts::QChart *chart = new QtCharts::QChart();
            chart->addSeries(series);
            chart->setTitle("Statistics by studio state");
            chart->setAnimationOptions(QtCharts::QChart::SeriesAnimations);

            QtCharts::QBarCategoryAxis *axisX = new QtCharts::QBarCategoryAxis();
            axisX->append(statistiques.keys());
            chart->addAxis(axisX, Qt::AlignBottom);
            series->attachAxis(axisX);

            QtCharts::QValueAxis *axisY = new QtCharts::QValueAxis();
            chart->addAxis(axisY, Qt::AlignLeft);
            series->attachAxis(axisY);

            QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
            chartView->setRenderHint(QPainter::Antialiasing);

            QVBoxLayout *layout = new QVBoxLayout(ui->chartContainer);
            layout->addWidget(chartView);
            ui->chartContainer->setLayout(layout);
}

void MainWindow::updateTotalStudios()
{
    QSqlQuery query;
      query.prepare("SELECT COUNT(DISTINCT NUMSALLE) FROM diffusion");

      if (query.exec() && query.next()) {
          int totalStudios = query.value(0).toInt();
          ui->label_6A->setText(QString("Total Studios: %1").arg(totalStudios));
      } else {
          qDebug() << "Error retrieving total number of studios:" << query.lastError().text();
          ui->label_6A->setText("Unable to retrieve total studios");
      }
}


void MainWindow::checkReservationDates()
{
    diffusion d;
    // Retrieve the reservation information from the database
    // You can use your existing methods to fetch reservation data
    QSqlQueryModel *model = d.afficherDiffusions();

    // Get current date
    QDate currentDate = QDate::currentDate();

    // Iterate through the reservation data
    for (int row = 0; row < model->rowCount(); ++row) {
        int numSalle = model->index(row, 0).data().toInt();
        QString etat = model->index(row, 2).data().toString();
        QDate dateRes = model->index(row, 3).data().toDate();

        // Calculate time difference between current date and reservation date
        int daysUntilReservation = currentDate.daysTo(dateRes);

        // Check if reservation date is within notification threshold (e.g., 1 day before)
        if (daysUntilReservation == 1) {
            // Trigger system notification
           mSystemTrayIcon->showMessage("Reservation Reminder",
                                         QString("Reservation for Studio %1 is tomorrow.").arg(numSalle),
                                         QSystemTrayIcon::Information,
                                         5000); // Notification duration (ms)

            // Update reservation status to prevent duplicate notifications
           // diffusion::UpdateSalleDiffusion(numSalle, -1, "Notified", dateRes);
        }
    }

    // Clean up
    delete model;
}

void MainWindow::initializeCalendar() {
    // Initialize the calendar widget
    ui->calendarWidget->setGridVisible(true); // Show grid lines for better visibility

    // Update the calendar with event dates
    updateCalendarWithEvents();
}

void MainWindow::updateCalendarWithEvents() {
    diffusion diffusion;
    QList<QDate> eventDates = diffusion.getEventDates();

    foreach (const QDate &date, eventDates) {
        QTextCharFormat format;

        // Remove any existing format for the date
        ui->calendarWidget->setDateTextFormat(date, QTextCharFormat());

        // Set custom background color for the date
        format.setBackground(Qt::red); // Customize the background color
        ui->calendarWidget->setDateTextFormat(date, format);
    }
}

void MainWindow::refreshCalendar() {
    ui->calendarWidget->setDateTextFormat(QDate(), QTextCharFormat()); // Clear all existing formats
    updateCalendarWithEvents();
}

void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    diffusion d;
       QStringList eventInfo = d.GetSalleInformationForDate(date);

       QString labelText = "Event Information:\n";
       if (!eventInfo.isEmpty()) {
           labelText += "Capacity: " + eventInfo[0] + "\n";
           labelText += "State: " + eventInfo[1] + "\n";
           labelText += "Date: " + eventInfo[2] + "\n";
       } else {
           labelText += "No event scheduled for this date.";
       }
       ui->label_8A->setText(labelText);
}

