#include "mainwindow.h"
#include "diffusion.h"
#include <QStackedWidget>
#include <QDebug>
#include <QApplication>
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QSqlDatabase db ;
       db = QSqlDatabase::addDatabase("QODBC");
       db.setDatabaseName("amal");
       db.setUserName("Amal");
       db.setPassword("14210802");
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
