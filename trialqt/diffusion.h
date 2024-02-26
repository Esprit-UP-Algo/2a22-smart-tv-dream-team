#ifndef DIFFUSION_H
#define DIFFUSION_H
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

class diffusion
{
public:
 diffusion();
    bool ajout(int numSalle, int capacite, QString etat, QString dateRes);
    bool supp(int idS);

    private:

  };

#endif // DIFFUSION_H

