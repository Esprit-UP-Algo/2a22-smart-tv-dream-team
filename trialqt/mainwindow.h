#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "diffusion.h"

#include <QMainWindow>
#include <QList>
#include <QVariantList>
#include <QPainter>
#include <QSystemTrayIcon>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QSystemTrayIcon;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();





private slots:

    void on_pushButton_3_clicked();



    void on_pushButton_14A_clicked();
    bool isStudioReserved(const QDate &dateRes);
    bool isStudioRepeated(int numSalle);


    void on_pushButton_clicked();

    void on_pushButton_UPDATE_3_clicked();



    void on_pushButton_2_clicked();

    void on_pushButton_UPDATE_2_clicked();
    void on_comboBox_currentIndexChanged();
    //void checkApproachingReservations();




    void on_pushButton_4A_clicked();

    void on_pushButton_10A_clicked();

    void on_pushButton_16A_clicked();

    void on_pushButton_8A_clicked();

    void on_pushButton_4_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_5_clicked();


    


    void updateTotalStudios();
    void checkReservationDates();
    void updateCalendarWithEvents();
    void initializeCalendar();
    void refreshCalendar();





    void on_calendarWidget_clicked(const QDate &date);

private:
   Ui::MainWindow *ui;
   diffusion diff;
     QTimer *timer;
     QTimer *notificationTimer;
     QSystemTrayIcon *mSystemTrayIcon;

};
#endif // MAINWINDOW_H
