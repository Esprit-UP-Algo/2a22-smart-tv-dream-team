#ifndef DIALOG_H
#define DIALOG_H
#include"employer.h"
#include <QDialog>
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
#include <QSqlQuery>
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
    char setkeyboard();
    ~Dialog();
    QString photo;
    QByteArray byte;
    void deleteftable(int j);

private slots:
    void on_gg_clicked();

    void on_hihi_5_clicked();

    void on_gg_4_clicked();

    void on_hihi_6_clicked();

    void on_pushButton_clicked();

    void on_gg_2_clicked();

    void on_gg_5_clicked();

    void on_gg_6_clicked();

    void on_hihi_14_clicked();

    void on_hihi_13_clicked();
    
    void on_hihi_16_clicked();
    
    void on_hihi_15_clicked();
    
    void on_gg_7_clicked();
    
    void on_hihi_20_clicked();

    void on_hihi_17_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_4A_clicked();

    void on_pushButton_4A_2_clicked();

    void on_pushButton_5A_2_clicked();

    void on_pushButton_5A_3_clicked();

    void on_pushButton_4A_3_clicked();

    void on_pushButton_5A_clicked();

    void on_gg_10_clicked();

    void on_hihi_32_clicked();

    void on_hihi_29_clicked();

    void on_hihi_31_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_2ms_2_clicked();

    void on_pushButton_4ms_2_clicked();

    void on_pushButton_11ms_2_clicked();

    void on_pushButton_3ms_2_clicked();

    void on_pushButton_12ms_2_clicked();

    void on_pushButton_9M_clicked();

    void on_loM_2_clicked();

    void on_pushButton_2M_2_clicked();

    void on_radioM_2_clicked();

    void on_tvM_2_clicked();

    void on_tv_2M_2_clicked();

    void on_deleteButtonM_2_clicked();

    void on_modifyButtonM_2_clicked();

    void on_addButtonM_2_clicked();

    void on_seriesM_2_clicked();

    void on_returnButtonM_2_clicked();

    void on_add_2M_2_clicked();


    void on_modifyButton_2M_2_clicked();

    //void on_vwatchRadioM_2_clicked();

    //void on_returnButton_2M_2_clicked();

    //void on_trieButtonM_2_clicked();

    void on_vewatchButtonM_2_clicked();

    void on_trieButton_2M_2_clicked();

    void on_statisticsM_2_clicked();

    void on_statistics_2M_2_clicked();

    void on_brandsButton_2M_2_clicked();

    void on_brandsButtonM_2_clicked();
    void importImage();

    void on_vewatch_2M_2_clicked();

    void on_hihi_10tr_clicked();

    void on_hihi_10tr_2_clicked();

    void on_hihi_10tr_3_clicked();

    void on_pushButton_63_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_23_clicked();

    void on_hihi_33_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_25_clicked();

    void on_addphotemp_clicked();

    void on_pushButton_27_clicked();

private:
    Ui::Dialog *ui;
    bool isTrieButtonClicked = false;
};

#endif // DIALOG_H
