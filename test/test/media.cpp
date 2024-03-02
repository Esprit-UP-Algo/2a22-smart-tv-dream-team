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

using namespace std;

/*class mediaData : public QSharedData
{
public:

};*/



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



QSqlQueryModel * Media::afficherMedia()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from etudiant");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("titre"));
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("description"));
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("image"));
       model->setHeaderData(0,Qt::Horizontal,QObject::tr("producteur"));
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("type"));
         model->setHeaderData(0,Qt::Horizontal,QObject::tr("nbrVue"));
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("date"));
          return model;
}



bool Media::supprimerMedia(QString titre)
{
    QSqlQuery query;
    QString res=titre;
    query.prepare("Delete from media where titre= :titre");
    query.bindValue(":titre",res);
    return query.exec();
}
bool Media::modifierMedia(QString titre)
{
    QSqlQuery query;
     query.prepare("UPDATE media SET titre = :titre, description = :description, image = :image, producteur = :producteur,type = :type WHERE titre = :titre");
     query.bindValue(":titre", titre);
     query.bindValue(":description", description);
     query.bindValue(":image", image);
     query.bindValue(":producteur", producteur);
     query.bindValue(":type", type);
     return query.exec();

}

