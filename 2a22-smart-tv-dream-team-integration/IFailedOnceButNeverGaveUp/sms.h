#ifndef SMS_H
#define SMS_H
#include <QObject>
#include <QNetworkReply>
#include <QUrl>

class sms:public QObject
{
public:
    Q_OBJECT

   public:
       explicit sms(QObject *parent = nullptr);


       void sendSMS(int val,int tel);

   private slots:
       void handleResponse(QNetworkReply*reply);

   private:
       QNetworkAccessManager *networkManager;
};

#endif // SMS_H
