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
    //Dialog d;

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("test"); //Source_Projet2A
    db.setUserName("yahya"); //sora
    db.setPassword("orro"); //oogabooga
    db.open();


    if (db.isOpen())
    {
        qDebug("clear");
        QTextToSpeech *textToSpeech = new QTextToSpeech();
        // Dire le texte souhaité
        textToSpeech->say("Welcome Amira! Have a great working day");
       //d.displayChannelImages(); // Call the function here
        //d.displayRadioImages();

        w.show();

    }
    else
    {
        qDebug("errrrrror");
    }

    return a.exec();
}
