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
        db.setDatabaseName("test"); //projet2a
        db.setUserName("yahya"); //sora
        db.setPassword("orro");//oogabooga
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
