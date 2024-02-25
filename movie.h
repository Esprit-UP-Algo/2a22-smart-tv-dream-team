#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>

using namespace std;
#include <string>
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlQuery>
#include<QtSql>
#include <QBuffer>
#include <QString>
#include <QStandardItemModel>
#include <QStyledItemDelegate>
class MOVIE
{
public:
    MOVIE();

    bool ajout(QByteArray bytep,QString titre , QString desc, int idm);
    bool supp(int id);
    bool updatenoimg(int id , QString titre , QString desc);
    bool updateimg(int id , QString titre , QString desc,QByteArray byte);
private:


};

#endif // MOVIE_H
