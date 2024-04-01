#ifndef MEDIA_H
#define MEDIA_H


#include <iostream>

using namespace std;
#include <string>
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlQuery>
#include<QtSql>
#include <QBuffer>
#include <QString>
#include <QStandardItemModel>
#include <QStyledItemDelegate>


#include <QSqlQueryModel>
#include <QString>
#include <QDate>
#include <QByteArray>

#include <QSqlQuery>
#include <QDebug>
#include <QtCharts>

#include <QUrl>
#include <QPdfWriter>
#include <QVector>
#include <QPair>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QSqlRecord>
#include <QtMath>
#include <QGridLayout>
#include <QOpenGLContext>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLContext>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLTexture>

class Media
{

public:
    //Constructeurs
    Media(){};
    Media(QString,QString,QString,QString,int,QDate,QByteArray);
    //~Media();

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
    bool ajouterMedia(QString titre,QString description,QByteArray image,QString producteur,QString type);
    QSqlQueryModel * afficherMedia();
    bool modifierMedia(int idM);
    void afficherChannel();
    bool supprimerMedia(QString titre);
    bool isTitleRepeated(QString titre);
    bool isImageInserted(const QByteArray& Image);
    bool isProducerInserted(QString producteur);
    bool isDescriptionValid(QString description);
    QSqlQueryModel *  trier(const QString &critere, const QString &mode );
    void generateQRCode(QString id);
    QMap<QString, int> obtenirStatistique();


private:
    //QSharedDataPointer<mediaData> data;
    QString titre, description, producteur, type;
    int nbrVue;
    QDate date;
    QByteArray image;

};


#endif // MEDIA_H
