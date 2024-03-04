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
            diffusion(); // constructeur par defaut
             diffusion(int numSalle, int capacite, QString etat, QDate dateRes);
             ~diffusion();
    //getters
         int getNumSalle(){return  numSalle;};
         int getCapacite(){return  capacite;};
         QString getEtat(){return  etat;};
         QDate getDateRes(){return  dateRes;};
    //setters
         void setNumSalle(int num);
         void setCapacite(int cap);
         void setEtat(QString state);
         void setDateRes(QDate date);

           bool ajoutSalle(int numSalle, int capacite, QString etat, QDate dateRes);
           QSqlQueryModel * afficherDiffusions();
           bool supprimerSalleDiffusion(int numSalle);
           bool UpdateSalleDiffusion(int numSalle, int capacite, QString etat);


    private:
       int numSalle;
          int capacite;
          QString etat;
          QDate dateRes;

  };

#endif // DIFFUSION_H

