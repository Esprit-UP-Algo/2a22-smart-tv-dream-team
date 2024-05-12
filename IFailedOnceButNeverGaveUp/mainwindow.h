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


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Arduino A,AM; // objet temporaire
    QString data;
    QString s;


private slots:




    void on_ok_13_clicked();

    void on_ok_15_clicked();

    void on_ok_14_clicked();

    void on_ku_13_clicked();

    int authenticateUser(const QString &Username, const QString &Password, QString &Role);

    void sendMail();
    void mailSent(QString status, Smtp *s);

    void on_ok_16_clicked();

    void confirm_accesss();

private:
    Ui::MainWindow *ui;
    QStringList files;


};
#endif // MAINWINDOW_H
