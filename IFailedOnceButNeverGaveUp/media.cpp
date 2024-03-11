#include "media.h"
#include <iostream>
#include <QCoreApplication>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <cctype>
#include <QSqlQuery>
#include <QSqlError>
#include <QObject>

using namespace std;



Media::Media(QString titre,QString description,QString type,QString producteur,int nbrVue,QDate date,QByteArray image)
{
    this->titre=titre;
    this->description=description;
    this->type=type;
    this->producteur=producteur;
    this->nbrVue=nbrVue;
    this->date=date;
    this->image=image;
}
bool Media::ajouterMedia(QString titre,QString description,QByteArray image,QString producteur,QString type )
{
    QSqlQuery query;
    query.prepare("insert into MEDIA(TITRE , DESCRIPTION , IMAGE , PRODUCTEUR , TYPE) VALUES ( :titre , :description , :image , :producteur , :type)");
    query.bindValue(":titre", titre);
    query.bindValue(":description", description);
    query.bindValue(":image", image);
    query.bindValue(":producteur", producteur);
    query.bindValue(":type", type);
    return query.exec();
}


bool Media::supprimerMedia(QString titre)
{
    QSqlQuery query;
    query.prepare("DELETE FROM MEDIA WHERE TITRE = :titre");
    query.bindValue(":titre", titre);
    if(query.exec())
    {
        qDebug() << "Suppression réussie!";
        return true;
    }
    else
    {
        qDebug() << "Erreur lors de la suppression:" << query.lastError().text();
        return false;
    }
}
bool Media::modifierMedia(int idM)
{
    QSqlQuery query;
     query.prepare("UPDATE media SET  description = :description, image = :image, producteur = :producteur,type = :type,titre = :titre WHERE idM = :idM");
     query.bindValue(":idM", idM);
     query.bindValue(":titre", titre);
     query.bindValue(":description", description);
     query.bindValue(":image", image);
     query.bindValue(":producteur", producteur);
     query.bindValue(":type", type);
     return query.exec();

}
bool Media::isTitleRepeated(QString titre)
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isValid()) {
        qDebug() << "Database connection is invalid";
        return false;
    }

    QSqlQuery query(db);
    query.prepare("SELECT COUNT(*) FROM MEDIA WHERE TITRE = ?");
    query.addBindValue(titre);

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

bool Media::isImageInserted(const QByteArray& Image)
{
    // Vérifier si l'image est vide
    if (Image.isEmpty()) {
        qDebug() << "Aucune image insérée.";
        return false;
    }
    else {
        qDebug() << "Image insérée.";
        return true;
    }
}
bool Media::isProducerInserted(QString producteur)
{
    // Vérifier si le producteur est vide
    if (producteur.isEmpty()) {
        qDebug() << "Aucun producteur inséré.";
        return false;
    }
    else {
        qDebug() << "Producteur inséré.";
        return true;
    }
}
bool Media::isDescriptionValid(QString description) {
    return description.length() < 200;
}
QSqlQueryModel *  Media::trier(const QString &critere, const QString &mode )
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from EMPLOYEE order by "+critere+" "+mode+"");

    return model;
}
