#include <QSqlQuery>
#include "mainwindow.h"
#include <QApplication>
#include<QMediaPlayer>
#include"dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Dialog d;
    QSqlDatabase db ;
    db = QSqlDatabase::addDatabase("QODBC");
        db.setDatabaseName("Source_Projet2A"); //projet2a
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
    //w.show();
        d.show();
    return a.exec();
}
