#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    void on_seriesM_clicked();

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
    void importImage();

    void on_vewatch_2M_clicked();

private:
    Ui::MainWindow *ui;
    bool isTrieButtonClicked = false;


};
#endif // MAINWINDOW_H
