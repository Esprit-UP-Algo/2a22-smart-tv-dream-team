#include "sms.h"
#include <QUrlQuery>
#include <QNetworkRequest>
#include <QByteArray>
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QDebug>
#include <QObject>
#include <QProcess>
#include <QSqlQueryModel>
#include <QSqlQuery>
sms::sms(QObject *parent) : QObject(parent)
{
    networkManager = new QNetworkAccessManager(this);
}




void sms::handleResponse(QNetworkReply *reply)
{
    qDebug() << "HTTP Status Code:" << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();


    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        qDebug() << "Response from Twilio API:" << QString::fromUtf8(responseData);
        // Emit a signal or handle success here
    } else {
        qDebug() << "Error:" << reply->errorString();
        // Emit a signal or handle failure here
    }
}
void sms::sendSMS(int val,int tel)
{
        QString fromNumber="+17577859519";
        QString toNumber="+216"+QString::number(tel);
        QSqlQuery query;
        QString body;
        query.prepare("select IDE,USERNAME from EMPLOYE where IDE=:ide");
        query.bindValue(":ide",val);
        query.exec();
        qDebug();
        if(query.next())
        {

            body="Bonjour Monsieur, "+query.value(1).toString()+" avec id: "+query.value(0).toString()+" votre salaire a ete envoyee.";
        }
        QProcess process;
        process.start("curl", QStringList() <<
                                "-X" << "POST" <<
                                "https://api.twilio.com/2010-04-01/Accounts/ACffff5fc6743e04e36f80b59f2db35314/Messages.json" <<
                                "--data-urlencode" << "To= " + toNumber <<
                                "--data-urlencode" << "From= " + fromNumber <<
                                "--data-urlencode" << "Body= " + body <<
                                "-u" << "ACffff5fc6743e04e36f80b59f2db35314:b8fc0dd03274934088efb45c3b078484");

        process.waitForFinished();



}
