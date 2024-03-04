#include "diffusion.h"
#include "mainwindow.h"

diffusion::diffusion(int numSalle, int capacite, QString etat, QDate dateRes)
{
    this->numSalle=numSalle;
    this->capacite=capacite;
    this->etat=etat;
    this->dateRes=dateRes;
}

bool diffusion::ajoutSalle(int numSalle, int capacite, QString etat, QDate dateRes)
{
    QSqlQuery query;
    query.prepare("insert into DIFFUSION(NUMSALLE,CAPACITE,ETAT,DATERES) values ( :numero , :capacite , :etat, :date)");
    query.bindValue(":numero",numSalle);
    query.bindValue(":capacite",capacite);
    query.bindValue(":etat",etat);
    query.bindValue(":date", dateRes);
    return query.exec();
}
bool diffusion::supprimerSalleDiffusion(int numSalle)
{
    QSqlQuery query;
    int res=numSalle;
    query.prepare("Delete from diffusion where numSalle= :numSalle");
    query.bindValue(":numSalle",res);
    return query.exec();
}

QSqlQueryModel *diffusion::afficherDiffusions()
{
    diffusion diff;
    QSqlQueryModel *model = new QSqlQueryModel();


    model->setQuery("SELECT * FROM diffusion");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("numSalle"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("capacite"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("dateRes"));

    return model;
}

bool diffusion::UpdateSalleDiffusion(int numSalle, int capacite, QString etat)
{
QSqlQuery query;
            query.prepare("UPDATE DIFFUSION se CAPACITE=:capacite , ETAT=:etat where NUMSALLE =:numSalle");
            query.bindValue(":numero",numSalle);
            query.bindValue(":capacite",capacite);
            query.bindValue(":etat",etat);

            return query.exec();

            }

diffusion::~diffusion() {
    //cleanup
}
