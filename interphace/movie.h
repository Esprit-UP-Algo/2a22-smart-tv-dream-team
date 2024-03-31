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

    bool ajout(QByteArray bytep,QString titre , QString desc, int nbv,QString duree,QString t,int nbep,QString mcat , QString scat,QByteArray bytet);
    bool supp(int id);
    bool updatenoimg(int id ,int nbrep , QString titre , QString desc,int nbv,QString dur,QString mcat , QString scat);
    bool updateimg(int id, int nbrep, QString titre , QString desc,QByteArray byte,int nbv,QString dur,QString mcat , QString scat);
private:


};

#endif // MOVIE_H
