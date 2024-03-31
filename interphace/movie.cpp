#include "movie.h"

MOVIE::MOVIE()
{


}

bool MOVIE::ajout(QByteArray bytep,QString titre , QString desc, int nbv,QString duree,QString t,int nbep,QString mcat , QString scat,QByteArray bytet)
{
    QSqlQuery query;
    query.prepare("insert into SERIE_FILM(DESCRIPTION , IMAGE , TITRE , NBRVUE , DUREE , TYPE , NBREP,MCATE , SCATE,TRAILER) values ( :description , :photo , :titre ,:NBV , :DUREE , :TYPE , :NBREP,:MCATE,:SCATE,:TRAILER)");
    query.bindValue(":photo", bytep);
    query.bindValue(":titre",titre);
    query.bindValue(":description",desc);
    query.bindValue(":NBV",nbv);
    query.bindValue(":DUREE",duree);
    query.bindValue(":TYPE",t);
    query.bindValue(":MCATE",mcat);
    query.bindValue(":SCATE",scat);
    query.bindValue(":NBREP",nbep);
    query.bindValue(":TRAILER",bytet);
    //query.bindValue(":id", idm);
    return query.exec();
}

bool MOVIE::supp(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM SERIE_FILM WHERE id = :id ;");
    query.bindValue(":id", id);
    return  query.exec();
}

bool MOVIE::updatenoimg(int id ,int nbrep , QString titre , QString desc,int nbv,QString dur,QString mcat , QString scat)
{
    QSqlQuery query;
    query.prepare("UPDATE  SERIE_FILM SET  DESCRIPTION=:description , NBREP=:nbrep , NBRVUE=:nbv,DUREE=:dur,TITRE=:titre,MCATE=:MCATE , SCATE=:SCATE WHERE ID=:id");
    query.bindValue(":titre",titre);
    query.bindValue(":description",desc);
    query.bindValue(":nbrep", nbrep);
    query.bindValue(":nbv", nbv);
    query.bindValue(":dur", dur);
    query.bindValue(":id", id);
    query.bindValue(":MCATE",mcat);

    query.bindValue(":SCATE",scat);
    return  query.exec();
}


bool MOVIE::updateimg(int id, int nbrep, QString titre , QString desc,QByteArray byte,int nbv,QString dur,QString mcat , QString scat)
{
    QSqlQuery query;
    query.prepare("UPDATE  SERIE_FILM SET  DESCRIPTION=:description , IMAGE=:photo , TITRE=:titre , NBRVUE=:nbv,DUREE=:dur,NBREP=:nbrep ,MCATE=:MCATE , SCATE=:SCATE WHERE ID=:id");
    query.bindValue(":photo", byte);
    query.bindValue(":titre",titre);
    query.bindValue(":description",desc);
    query.bindValue(":nbrep", nbrep);
    query.bindValue(":nbv", nbv);
    query.bindValue(":dur", dur);
    query.bindValue(":id",id);
    query.bindValue(":MCATE",mcat);

    query.bindValue(":SCATE",scat);
    return query.exec();

}
