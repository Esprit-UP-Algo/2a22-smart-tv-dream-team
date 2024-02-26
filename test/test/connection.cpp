#include "connection.h"

Connection::Connection(){}

bool Connection::createconnect()
{

    QSqlDatabase db = QSqlDatabase:: addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("amira");
    db.setPassword("26052003");

    if(db.open())
        test=true;



    return test;

}
void Connection::closeconnect(){ db.close(); }
