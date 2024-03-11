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

    bool ajout(QByteArray bytep,QString titre , QString desc, int nbv,QString duree,QString t,int nbep);
    bool supp(int id);
    bool updatenoimg(int id ,int nbrep , QString titre , QString desc,int nbv,QString dur);
    bool updateimg(int id, int nbrep, QString titre , QString desc,QByteArray byte,int nbv,QString dur);
private:


};
#endif // MOVIE_H
