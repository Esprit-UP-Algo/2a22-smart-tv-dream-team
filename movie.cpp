#include "movie.h"

MOVIE::MOVIE()
{


}

bool MOVIE::ajout(QByteArray bytep,QString titre , QString desc, int idm)
{
    QSqlQuery query;
    query.prepare("insert into MOVIE(DESCRIPTION , PHOTO , TITRE) values ( :description , :photo , :titre)");
    query.bindValue(":photo", bytep);
    query.bindValue(":titre",titre);
    query.bindValue(":description",desc);
    //query.bindValue(":id", idm);
    return query.exec();
}

bool MOVIE::supp(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM MOVIE WHERE id = :id ;");
    query.bindValue(":id", id);
    return  query.exec();
}

bool MOVIE::updatenoimg(int id , QString titre , QString desc)
{
    QSqlQuery query;
    query.prepare("UPDATE  MOVIE SET  DESCRIPTION=:description , TITRE=:titre WHERE ID=:id");
    query.bindValue(":titre",titre);
    query.bindValue(":description",desc);
    query.bindValue(":id", id);
    return  query.exec();
}


bool MOVIE::updateimg(int id , QString titre , QString desc,QByteArray byte)
{
    QSqlQuery query;
    query.prepare("UPDATE  MOVIE SET  DESCRIPTION=:description , PHOTO=:photo , TITRE=:titre WHERE ID=:id");
    query.bindValue(":photo", byte);
    query.bindValue(":titre",titre);
    query.bindValue(":description",desc);
    query.bindValue(":id",id);
    return query.exec();

}
