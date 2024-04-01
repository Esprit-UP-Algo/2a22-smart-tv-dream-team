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

#include <QVBoxLayout>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
#include <string>
#include <QTextToSpeech>
#include <QAudioDeviceInfo>
#include <iostream>
using namespace std;
#include "string.h"
#include <QTimer>
#include <QtWidgets/qmainwindow.h>

#include "ui_dialog.h"



namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    QByteArray byte;
    ~Dialog();
    QByteArray importImage();
    void displayChannelImages();
    void displayRadioImages();void createPieChartM(const QMap<QString, int>& data);
   //void onSpeechRecognized(QTextToSpeech::State state);
    //QTextToSpeech *textToSpeech;
    //void startVoiceInput();
   // void speechStateChanged(QTextToSpeech::State state);
    //speech
        void onSpeechStateChanged(QTextToSpeech::State state);

        void speak();
              void stop();

              void setRate(int);
              void setPitch(int);
              void setVolume(int volume);

              void stateChanged(QTextToSpeech::State state);
              void engineSelected(int index);
              void languageSelected(int language);
              void voiceSelected(int index);

              void localeChanged(const QLocale &locale);

              void addMediaItem();
              void clearInputFields();
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

    //void on_pushButton_4A_2_clicked();

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

    void on_cancelButtonM_clicked();

    void on_searchLineEditM_textChanged(const QString &arg1);

    void on_cancelButtonM_2_clicked();

    void generateStatisticsChart();
    void on_buttonM_clicked();

    void on_listM_2_clicked();

    void on_pushButton_3_clicked();

    void on_radioM_clicked();

    void on_tvM_2_clicked();


    void on_statisticsM_clicked();

    void on_statisticsM_2_clicked();
   // void onTextChanged(const QString &text);


   string on_TitleM_textChanged();
    void onTypingTimerTimeout();
    void readText();
   void on_TitleM_textChanged(const QString &arg1);
    void startTimer();
    void readTextProducer();
    void on_ProducerM_textChanged(const QString &arg1);

    void on_textEditM_textChanged();
    void readTextDescrption();
    void initializeTextToSpeech() ;
    void startProducerTimer();

private:
    Ui::Dialog *ui;
    bool isTrieButtonClicked = false;
    QString type ;
    QList<QPushButton*> buttonsList;
    QByteArray valImage;
    QTextToSpeech *speechRecognizer;
     QString textToSpeechText;

     //QTextToSpeech *m_speech;
     QVector<QVoice> m_voices;
      QTextToSpeech *textToSpeech;
      QTimer *typingTimer,*producerTimer;
      QString lastText;
};

#endif // DIALOG_H
