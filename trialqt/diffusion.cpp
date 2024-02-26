#include "diffusion.h"

diffusion::diffusion()
{
}

bool diffusion::ajout(int numSalle, int capacite, QString etat, QString dateRes)
{
    QSqlQuery query;
    query.prepare("insert into DIFFUSION(NUMSALLE,CAPACITE,ETAT,DATERES) values ( :numero , :capacite , :etat, :date)");
    query.bindValue(":numero",numSalle);
    query.bindValue(":capacite",capacite);
    query.bindValue(":etat",etat);
    query.bindValue(":date", dateRes);
    return query.exec();
}
