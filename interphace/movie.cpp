#include "movie.h"

MOVIE::MOVIE()
{


}

bool MOVIE::ajout(QByteArray bytep,QString titre , QString desc, int nbv,QString duree,QString t,int nbep)
{
    QSqlQuery query;
    query.prepare("insert into SERIE_FILM(DESCRIPTION , IMAGE , TITRE , NBRVUE , DUREE , TYPE , NBREP) values ( :description , :photo , :titre ,:NBV , :DUREE , :TYPE , :NBREP)");
    query.bindValue(":photo", bytep);
    query.bindValue(":titre",titre);
    query.bindValue(":description",desc);
    query.bindValue(":NBV",nbv);
    query.bindValue(":DUREE",duree);
    query.bindValue(":TYPE",t);

    query.bindValue(":NBREP",nbep);
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

bool MOVIE::updatenoimg(int id ,int nbrep , QString titre , QString desc,int nbv,QString dur)
{
    QSqlQuery query;
    query.prepare("UPDATE  SERIE_FILM SET  DESCRIPTION=:description , NBREP=:nbrep , NBRVUE=:nbv,DUREE=:dur,TITRE=:titre WHERE ID=:id");
    query.bindValue(":titre",titre);
    query.bindValue(":description",desc);
    query.bindValue(":nbrep", nbrep);
    query.bindValue(":nbv", nbv);
    query.bindValue(":dur", dur);
    query.bindValue(":id", id);
    return  query.exec();
}


bool MOVIE::updateimg(int id, int nbrep, QString titre , QString desc,QByteArray byte,int nbv,QString dur)
{
    QSqlQuery query;
    query.prepare("UPDATE  SERIE_FILM SET  DESCRIPTION=:description , IMAGE=:photo , TITRE=:titre , NBRVUE=:nbv,DUREE=:dur,NBREP=:nbrep WHERE ID=:id");
    query.bindValue(":photo", byte);
    query.bindValue(":titre",titre);
    query.bindValue(":description",desc);
    query.bindValue(":nbrep", nbrep);
    query.bindValue(":nbv", nbv);
    query.bindValue(":dur", dur);
    query.bindValue(":id",id);
    return query.exec();

}
