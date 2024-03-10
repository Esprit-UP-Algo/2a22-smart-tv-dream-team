#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTableView>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loM_clicked();

    void on_pushButton_2M_clicked();

    void on_radioM_clicked();

    void on_tvM_clicked();

    void on_tv_2M_clicked();

    void on_deleteButtonM_clicked();

    void on_modifyButtonM_clicked();

    void on_addButtonM_clicked();

    void on_button1_clicked();

    void on_returnButtonM_clicked();

    void on_add_2M_clicked();


    void on_modifyButton_2M_clicked();

    void on_vwatchRadioM_clicked();

    void on_returnButton_2M_clicked();

    void on_trieButtonM_clicked();

    void on_vewatchButtonM_clicked();

    void on_trieButton_2M_clicked();

    void on_statisticsM_clicked();

    void on_statistics_2M_clicked();

    void on_brandsButton_2M_clicked();

    void on_brandsButtonM_clicked();
    QByteArray importImage();
    void on_vewatch_2M_clicked();
    void afficherDonnees();
     void afficherDescription();
     void afficherMedia();
     bool supprimerMedia(QString titre);

     void on_listM_clicked();

     void on_returnM_clicked();

     void on_updatedButtonM_clicked();

    void on_exportButtonM_clicked(QTableView *tableView);

private:
    Ui::MainWindow *ui;
    bool isTrieButtonClicked = false;
    QString type ;
    QList<QPushButton*> buttonsList;
    QByteArray valImage;

};
#endif // MAINWINDOW_H
