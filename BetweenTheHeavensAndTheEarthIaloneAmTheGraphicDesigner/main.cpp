#include <QSqlQuery>
#include "mainwindow.h"
#include <QApplication>
#include<QMediaPlayer>
#include"dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QSqlDatabase db ;
    db = QSqlDatabase::addDatabase("QODBC");
        db.setDatabaseName("projet2a"); //projet2a
        db.setUserName("sora"); //sora
        db.setPassword("oogabooga");//oogabooga
        db.open();

        if (db.isOpen())
        {
            qDebug("clear");
        }
        else
        {
            qDebug("errrrrror");
        }
    w.show();
    return a.exec();
}
