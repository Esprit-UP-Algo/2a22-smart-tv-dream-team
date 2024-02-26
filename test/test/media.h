#ifndef MEDIA_H
#define MEDIA_H

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QDate>
#include <QByteArray>

//class mediaData;

class Media
{

public:
    Media(){};
    Media(QString,QString,QString,QString,int,QDate,QByteArray);
    ~Media();

    //Getters
    QString getTitre(){return  titre;};
    QString getDescription(){return  description;};
    QString getProducteur(){return  producteur;};
    QString getType(){return  type;};
    int getnbrVue(){return  nbrVue;};
    QByteArray getImage(){return  image;};
    QDate getDate(){return  date;};

    //Setters
    void setTitre(QString t ){titre=t;};
    void setDescription(QString d){description=d;};
    void setProducteur(QString p){producteur=p;};
    void setType(QString x){type=x;};
    void setnbrVue(int n){ nbrVue=n;};
    void setImage(QByteArray img){ image=img;};
    void setDate( QDate d){date=d;};

    //fct
    bool ajouterMedia();
    QSqlQueryModel * afficherMedia();
    bool supprimerMedia(QString);
    bool modifierMedia(QString);

private:
    //QSharedDataPointer<mediaData> data;
    QString titre,description,producteur,type;
    int nbrVue;
    QDate date;
    QByteArray image;

};

#endif // MEDIA_H
