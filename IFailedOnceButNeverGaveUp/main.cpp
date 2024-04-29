#include <QSqlQuery>
#include "mainwindow.h"
#include <QApplication>
#include<QMediaPlayer>
#include"dialog.h"
#include <QSystemTrayIcon>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    MainWindow w;
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QODBC");
        db.setDatabaseName("amal"); //projet2a
        db.setUserName("yahya"); //sora
        db.setPassword("123");//oogabooga
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
