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
#include <QMap>
#include <QSystemTrayIcon>

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
         void setNumSalle(int num){numSalle=num;};
         void setCapacite(int cap){capacite=cap;};
         void setEtat(QString state){etat=state;};
         void setDateRes(QDate date){dateRes=date;};

           bool ajoutSalle(int numSalle, int capacite, QString etat, QDate dateRes);
           QSqlQueryModel * afficherDiffusions();
           bool supprimerSalleDiffusion(int numSalle);
           bool UpdateSalleDiffusion(int numSalle, int capacite, QString etat,const QDate &date);
           QStringList GetSalleInformation(int numSalle);
           bool SalleExists(int numSalle);
           bool isNumSallRepeated(int num);
           bool isStudioReserved(const QDate &dateRes);
           QMap<QString, int> obtenirStatistique();
           QList<QDate> getEventDates();
           QStringList GetSalleInformationForDate(const QDate &date);




    private:
       int numSalle;
          int capacite;
          QString etat;
          QDate dateRes;


  };


#endif // DIFFUSION_H
