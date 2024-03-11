#ifndef DIALOG_H
#define DIALOG_H
#include <QSqlQuery>
#include <QDialog>
#include"employer.h"
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtMultimedia>
#include<QtMultimediaWidgets>
#include<QtCore>
#include<QtGui>
#include<QString>
#include<QtWidgets>
#include <QFileDialog>
#include <QMessageBox>
#include<QtSql>
#include <QBuffer>
#include <QString>
#include <QStandardItemModel>
#include <QStyledItemDelegate>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    QByteArray byte;
    ~Dialog();

private slots:
    void on_hihi_6_clicked();

    void on_hihi_5_clicked();

    void on_hihi_15_clicked();

    void on_hihi_33_clicked();

    void on_gg_clicked();

    void on_hihi_35_clicked();

    void on_hihi_37_clicked();

    void on_hihi_20_clicked();

    void on_pushButton_14A_4_clicked();

    void on_pushButton_14A_6_clicked();

    void on_pushButton_14A_5_clicked();

    void on_pushButton_14A_7_clicked();

    void on_hihi_17_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_3A_clicked();

    void on_pushButton_4A_clicked();

    void on_pushButton_14A_clicked();

    void on_pushButton_14A_3_clicked();

    void on_pushButton_14A_2_clicked();

    void on_label_omek_clicked();

    void on_pushButton_4A_2_clicked();

    void on_pushButtonA_clicked();

    void on_pushButton_2A_clicked();

    void on_hihi_43_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
