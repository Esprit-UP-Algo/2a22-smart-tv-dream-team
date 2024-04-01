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
#include <QImage>
#include <QByteArray>
#include <QBuffer>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
//#include <QZXing>

#include "qr.h"
#include"qr.cpp"
#include <QMessageBox>
#include <QImage>


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
QSqlQueryModel *Media::afficherMedia()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Media");
    if (model->lastError().isValid()) {
        qDebug() << "Erreur SQL:" << model->lastError().text();
        delete model;
        return nullptr;
    }
    return model;
}

void Media::generateQRCode(QString id)
{
    QSqlQuery query;
    query.prepare("SELECT IDM, TYPE, DESCRIPTION, DATEM, TITRE, PRODUCTEUR FROM MEDIA WHERE IDM = ?");
    query.addBindValue(id);

    if (query.exec() && query.next()) {
        int idm = query.value(0).toInt();
        QString type = query.value(1).toString();
        QString description = query.value(2).toString();
        QString datem = query.value(3).toString();
        QString titre = query.value(4).toString();
        QString producteur = query.value(5).toString();

        QString mediaDetails = "Media details:\n"
                               "IDM: " + QString::number(idm) + "\n"
                               "Type: " + type + "\n"
                               "Description: " + description + "\n"
                               "Date: " + datem + "\n"
                               "Title: " + titre + "\n"
                               "Producer: " + producteur;

        using namespace qrcodegen;
        QrCode qr = QrCode::encodeText(mediaDetails.toUtf8().data(), QrCode::Ecc::MEDIUM);
        int scale = 10;
        int qrSize = qr.getSize() * scale;
        QImage qrImage(qrSize, qrSize, QImage::Format_RGB32);
        QRgb black = qRgb(0, 0, 0);
        QRgb white = qRgb(255, 255, 255);

        for (int y = 0; y < qrSize; ++y) {
            for (int x = 0; x < qrSize; ++x) {
                int moduleX = x / scale;
                int moduleY = y / scale;
                qrImage.setPixel(x, y, qr.getModule(moduleX, moduleY) ? black : white);
            }
        }

        QMessageBox msgBox;
        msgBox.setWindowTitle("QR Code Generated");
        msgBox.setIconPixmap(QPixmap::fromImage(qrImage).scaledToWidth(300)); // Adapté pour afficher un QR code plus grand

        QPushButton *downloadButton = msgBox.addButton("Download QR Code", QMessageBox::ActionRole);
        msgBox.exec();

        if (msgBox.clickedButton() == downloadButton) {
            QString fileName = QFileDialog::getSaveFileName(nullptr, "Save QR Code", QDir::homePath(), "PNG Files (*.png)");
            if (!fileName.isEmpty()) {
                if (qrImage.save(fileName, "PNG")) {
                    QMessageBox::information(nullptr, "Success", "QR Code saved successfully!");
                } else {
                    QMessageBox::warning(nullptr, "Error", "Failed to save QR Code.");
                }
            }
        }
    } else {
        QMessageBox::warning(nullptr, "Error", "Media with ID " + id + " not found in the database.");
    }
}
QMap<QString, int> Media::obtenirStatistique()
{
    QMap<QString, int> statistiques;

    QSqlQuery query;
    query.exec("SELECT TYPE, SUM(NBRVUE) AS nombre_vues FROM MEDIA GROUP BY TYPE");
    while (query.next()) {
        QString type = query.value("TYPE").toString();
        int nombre_vues = query.value("nombre_vues").toInt();
        statistiques[type] = nombre_vues;
    }

    return statistiques;
}

