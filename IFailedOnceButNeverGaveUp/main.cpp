#include <QApplication>
#include <QDebug>
#include <QSqlDatabase>
#include "mainwindow.h"
#include "dialog.h"

#include <QTextToSpeech>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("yahya");
    db.setPassword("123");
    if (!db.open()) {
        qDebug() << "Error: Unable to open database";
        return 1;
    }

    MainWindow w;
    Dialog d;
    QTextToSpeech *textToSpeech = new QTextToSpeech();

        // Dire le texte souhaité
        textToSpeech->say("Welcome Amira! Have a great working day");
    d.displayChannelImages(); // Call the function here
    d.displayRadioImages();
    d.show();

    return a.exec();
}

