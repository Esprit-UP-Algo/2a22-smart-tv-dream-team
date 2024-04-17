#include <QSqlQuery>
#include "mainwindow.h"
#include <QApplication>
#include <QMediaPlayer>
#include "dialog.h"
#include <QSystemTrayIcon>
#include <QTextToSpeech>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");

    MainWindow w;
    Dialog d;

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A"); //projet2a
    db.setUserName("yahya"); //sora
    db.setPassword("123"); //oogabooga
    db.open();


    if (db.isOpen())
    {
        qDebug("clear");

    }
    else
    {
        qDebug("errrrrror");
    }
    QTextToSpeech *textToSpeech = new QTextToSpeech();
    // Dire le texte souhaité
    textToSpeech->say("Welcome Amira! Have a great working day");


    w.show();
    return a.exec();
}
