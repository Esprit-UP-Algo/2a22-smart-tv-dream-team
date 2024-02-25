#include "mainwindow.h"
#include "movie.h"
#include <QApplication>
#include <QDebug>
#include <QSqlDatabase>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QSqlDatabase db ;
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("test");
    db.setUserName("omar");
    db.setPassword("orro");
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
