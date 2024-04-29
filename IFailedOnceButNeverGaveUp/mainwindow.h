#ifndef MAINWINDOW_H
#define MAINWINDOW_H


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
#include"arduino.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void on_ok_clicked();

    void on_ok_2_clicked();


    void on_ok_3_clicked();

    void on_ku_3_clicked();


    void on_ok_12_clicked();

    void on_ku_2_clicked();

    void on_ok_13_clicked();

    void on_ok_15_clicked();

    void on_ok_14_clicked();

    void on_ku_13_clicked();

    bool authenticateUser(const QString &Username, const QString &Password, QString &Role);

    void sendMail();
    void mailSent(QString);

    void on_ok_16_clicked();

private:
    Ui::MainWindow *ui;
    QStringList files;
    Arduino AM;
    QByteArray dataM;
};
#endif // MAINWINDOW_H
