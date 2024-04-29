#ifndef EMPLOYER_H
#define EMPLOYER_H
#include<QString>

class employer
{
public:
    void setuser(QString n);
    void setpassword(QString n);
    bool Validateuser();
    bool Validatepassword();
    employer();
    QString get_user();
    QString get_password();
    void  generateQRCodeEmploye(QString id);




private:
    QString user,password;
    QByteArray image;

};



#endif // EMPLOYER_H
