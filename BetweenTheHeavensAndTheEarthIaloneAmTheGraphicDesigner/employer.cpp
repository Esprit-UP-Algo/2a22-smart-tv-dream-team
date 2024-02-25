#include "employer.h"
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
employer::employer()
{
    user="";
    password="";

}
void employer::setuser(QString n) {user=n;}
void employer::setpassword(QString n) {password=n;}
bool employer::Validateuser()
{
    if (user.length() < 4){
        cout << "Username is too short." << endl;
        return false;
    }
    else {
        cout << "Username is strong." << endl;
        return true;
    }
}
bool employer::Validatepassword() {
    if ((password.length() <12)&&(password.length()>6)) {
        return true;
    }
    else
    {
        return false;
    }
}

QString employer::get_user(){return user;}
QString employer::get_password(){return password;}
