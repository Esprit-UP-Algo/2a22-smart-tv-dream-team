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

/*QSqlQueryModel* Media::afficherMedia()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM MEDIA");

    // Ajout des boutons "Supprimer" et "Modifier" à chaque ligne
    for (int j = 0; j < model->rowCount(); j++) {
        QPushButton *deleteButton = new QPushButton("Supprimer");
        QPushButton *updateButton = new QPushButton("Modifier");

        connect(deleteButton, &QPushButton::clicked, this, [this, j, model]() {
            QString titre = model->index(j, 0).data().toString(); // Supposons que le titre est dans la colonne 0
            if (supprimerMedia(titre)) {
                // Rafraîchir l'affichage après la suppression
                model->setQuery("SELECT * FROM MEDIA");
            }
        });

        connect(updateButton, &QPushButton::clicked, this, [this, j, model]() {
            // Mettez votre logique pour la modification ici
        });

        QWidget *widget = new QWidget();
        QHBoxLayout *layout = new QHBoxLayout(widget);
        layout->addWidget(deleteButton);
        layout->addWidget(updateButton);
        layout->setAlignment(Qt::AlignCenter);
        layout->setContentsMargins(0, 0, 0, 0);
        widget->setLayout(layout);

            }

    return model;
}*/
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
