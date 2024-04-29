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
#include "qrr.h"
#include <cctype>
#include <QSqlQuery>
#include <QSqlError>
#include <QObject>
#include <QImage>
#include <iostream>
#include <QDialog>
#include <QFileDialog>

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
void employer::generateQRCodeEmploye(QString id)
{
    QSqlQuery query;
    query.prepare("SELECT IDE, NOM, PRENOM, CIN, TYPE, TEL, EMAIL FROM EMPLOYE WHERE IDE = ?");
    query.addBindValue(id);

    if (query.exec() && query.next()) {
        int ide = query.value(0).toInt();
        QString nom = query.value(1).toString();
        QString prenom = query.value(2).toString();
        int cin = query.value(3).toInt();
        QString type = query.value(4).toString();
        int tel = query.value(5).toInt();
        QString email = query.value(6).toString();

        QString mediaDetails = "ID: " + QString::number(ide) + "\n"
                               "Name: " + nom + "\n"
                               "Last name: " + prenom + "\n"
                               "CIN: " + QString::number(cin) + "\n"
                               "Post: " + type + "\n"
                               "Phone: " + QString::number(tel) + "\n"
                               "Email: " + email;

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
        QMessageBox::warning(nullptr, "Error", "Employee with ID " + id + " not found in the database.");
    }
}

