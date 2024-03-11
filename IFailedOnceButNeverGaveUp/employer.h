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




private:
    QString user,password;
};



#endif // EMPLOYER_H
