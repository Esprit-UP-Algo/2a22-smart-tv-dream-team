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
        db.setDatabaseName("projet"); //projet2a
        db.setUserName("yahya"); //sora
        db.setPassword("apolios");//oogabooga
        db.open();

        if (db.isOpen())
        {
            qDebug("clear");
        }
        else
        {
            qDebug("errrrrror");
        }
        Dialog d;
        d.exec();
    //w.show();
    return a.exec();
}
