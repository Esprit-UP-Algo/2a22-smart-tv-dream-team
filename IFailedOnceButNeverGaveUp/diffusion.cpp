#include "diffusion.h"
#include "dialog.h"

diffusion::diffusion()
{

}

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
    query.prepare("insert into SALLE(NUMSALLE,CAPACITE,ETAT,DATERES) values ( :numero , :capacite , :etat, :date)");
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
    query.prepare("Delete from salle where numSalle= :numSalle");
    query.bindValue(":numSalle",res);
    return query.exec();
}

QSqlQueryModel *diffusion::afficherDiffusions()
{
    diffusion diff;
    QSqlQueryModel *model = new QSqlQueryModel();


    model->setQuery("SELECT * FROM salle");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("numSalle"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("capacite"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("dateRes"));
    model->insertColumn(4);
    model->setHeaderData(4, Qt::Horizontal, QObject::tr(""));

    return model;


}

bool diffusion::UpdateSalleDiffusion(int numSalle, int capacite, QString etat, const QDate &date)
{
QSqlQuery query;
            query.prepare("UPDATE diffusion set CAPACITE=:capacite , ETAT=:etat,DATERES=:date where NUMSALLE =:numSalle");
            query.bindValue(":numSalle",numSalle);
            query.bindValue(":capacite",capacite);
            query.bindValue(":etat", etat);
            query.bindValue(":date", date); // Binding QDate directly

            if (!query.exec()) {
                   qDebug() << "Error executing SQL query:" << query.lastError().text();
                   return false;
               }
               return true;

            }
QStringList diffusion::GetSalleInformation(int numSalle)
{
    QStringList salleInfo;
    QSqlQuery query;
    query.prepare("SELECT CAPACITE, ETAT, DATERES FROM diffusion WHERE NUMSALLE = :numSalle");
    query.bindValue(":numSalle", numSalle);
    if (query.exec() && query.next()) {
        int capacite = query.value(0).toInt();
        QString etat = query.value(1).toString();
        QDate dateRes = query.value(2).toDate(); // Assuming the date column is stored as DATE type
                salleInfo << QString::number(capacite) << etat << dateRes.toString(Qt::ISODate);

    }
    return salleInfo;
}



bool diffusion::SalleExists(int numSalle)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM diffusion WHERE NUMSALLE = :numSalle");
    query.bindValue(":numSalle", numSalle);
    if (query.exec() && query.next()) {
        int count = query.value(0).toInt();
        return count > 0;
    }
    return false;
}

QMap<QString, int> diffusion::obtenirStatistique()
{
    QMap<QString, int> statistiques;

       QSqlQuery query;
       query.exec("SELECT ETAT, COUNT(*) AS count FROM SALLE GROUP BY ETAT");
       while (query.next()) {
           QString etat = query.value("ETAT").toString();
           int count = query.value("count").toInt();
           statistiques[etat] = count;
       }

       return statistiques;

    }
bool diffusion::isNumSallRepeated(int num)
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isValid()) {
        qDebug() << "Database connection is invalid";
        return false;
    }

    QSqlQuery query(db);
    query.prepare("SELECT COUNT(*) FROM SALLE WHERE NUMSALLE = ?");
    query.addBindValue(num);

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return false;
    }

    if (query.next()) {
        int count = query.value(0).toInt();
        return count > 0;
    }

    return false;
}

bool diffusion::isStudioReserved(const QDate &dateRes)
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isValid()) {
        qDebug() << "Database connection is invalid";
        return false;
    }

    QSqlQuery query(db);
    query.prepare("SELECT COUNT(*) FROM SALLE WHERE DATERES = ?");
    query.addBindValue(dateRes.toString(Qt::ISODate));

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return false;
    }

    if (query.next()) {
        int count = query.value(0).toInt();
        return count > 0;
    } else {
        qDebug() << "No result found for query";
        return false;
    }
}
QList<QDate> diffusion::getEventDates() {
    QList<QDate> eventDates;

    // Query the database to retrieve event dates
    QSqlQuery query;
    query.prepare("SELECT DATERES FROM SALLE");
    if (query.exec()) {
        while (query.next()) {
            QDate date = query.value("DATERES").toDate();
            qDebug() << "Date retrieved from database:" << date.toString("yyyy-MM-dd");
            eventDates.append(date);
        }
    } else {
        qDebug() << "Error executing SQL query:" << query.lastError().text();
    }

    return eventDates;
}
QStringList diffusion::GetSalleInformationForDate(const QDate &date) {
    QStringList salleInfo;
       QSqlQuery query;
       query.prepare("SELECT CAPACITE, ETAT, DATERES FROM SALLE");

       if (query.exec()) {
           while (query.next()) {
               QDate dbDate = query.value(2).toDate();
               if (dbDate == date) {
                   int capacite = query.value(0).toInt();
                   QString etat = query.value(1).toString();
                   salleInfo << QString::number(capacite) << etat << dbDate.toString(Qt::ISODate);
               }
           }
       } else {
           qDebug() << "Error executing SQL query:" << query.lastError().text();
       }

       return salleInfo;
}

diffusion::~diffusion() {
    //cleanup
}

