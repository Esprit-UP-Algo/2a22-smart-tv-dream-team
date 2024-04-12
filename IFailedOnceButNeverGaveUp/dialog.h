#ifndef DIALOG_H
#define DIALOG_H
#include <QSqlQuery>
#include <QDialog>
#include"employer.h"
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtMultimedia>
#include<QtMultimediaWidgets>
#include<QtCore>
#include<QtGui>
#include<QString>
#include<QtWidgets>
#include <QFileDialog>
#include <QMessageBox>
#include<QtSql>
#include <QBuffer>
#include <QString>
#include <QStandardItemModel>
#include <QStyledItemDelegate>
#include "media.h"
#include "movie.h"
#include <QPrinter>
#include <QPainter>
#include <QTextToSpeech>
#include <QAudioDeviceInfo>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    QString Role;
    explicit Dialog(QWidget *parent = nullptr);
    QByteArray byte;
    ~Dialog();
    QByteArray importImage();
    void trait(QString Role);
    void updateChartEmploye();
    void statistiqueMedia();
    void displayChannelImages();
    void displayRadioImages();

    QTcpSocket *socket;

private slots:
    void on_hihi_6_clicked();

    void on_hihi_5_clicked();

    void on_hihi_15_clicked();

    void on_hihi_33_clicked();

    void on_gg_clicked();

    void on_hihi_35_clicked();

    void on_hihi_37_clicked();

    void on_hihi_20_clicked();

    void on_pushButton_14A_4_clicked();

    void on_pushButton_14A_6_clicked();

    void on_pushButton_14A_5_clicked();

    void on_pushButton_14A_7_clicked();

    void on_hihi_17_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_3A_clicked();

    void on_pushButton_4A_clicked();

    void on_pushButton_14A_clicked();

    void on_pushButton_14A_3_clicked();

    void on_pushButton_14A_2_clicked();

    void on_label_omek_clicked();

    void on_pushButton_4A_2_clicked();

    void on_pushButtonA_clicked();

    void on_pushButton_2A_clicked();

    void on_hihi_43_clicked();

    void on_listM_clicked();

    void on_loM_clicked();

    void on_addButtonM_clicked();

    void on_updatedButtonM_clicked();

    void on_exportButtonM_clicked();

    void on_pushButton_4_clicked();

    void on_imageButtonM_clicked();

    void on_pushButton_2ms_clicked();

    void on_pushButton_12ms_clicked();

    void on_comboBoxms_currentTextChanged(const QString &arg1);

    void on_pushButton_3ms_clicked();

    void on_pushButton_11ms_clicked();

    void on_pushButton_4ms_clicked();

    void on_upimagems_clicked();

    void on_confirmupms_clicked();

    void on_returnupms_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_comboBoxms_2_currentTextChanged(const QString &arg1);

    void on_hihi_8_clicked();

    void on_gg_2_clicked();

    void on_gg_5_clicked();

    void on_hihi_7_clicked();

    void on_searchLineEditM_textChanged(const QString &arg1);

    void on_hihi_18_clicked();

    void on_pushButton_13_clicked();

    void connected();

    void readyRead();

    void on_pushButton_2ms_2_clicked();

private:
    Ui::Dialog *ui;
    bool isTrieButtonClicked = false;
    QString type ;
    QList<QPushButton*> buttonsList;
    QByteArray valImage;
    QVector<QVoice> m_voices;
     QTextToSpeech *textToSpeech;
     QTimer *typingTimer,*producerTimer;
     QString lastText;
};

#endif // DIALOG_H
