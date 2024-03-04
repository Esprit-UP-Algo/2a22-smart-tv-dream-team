#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "diffusion.h"

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
    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();



    void on_pushButton_14A_clicked();
    bool isStudioReserved(const QDate &dateRes);
    bool isStudioRepeated(int numSalle);
   //  void displayDiffusions();


    void on_pushButton_clicked();



    void on_pushButton_UPDATE_3_clicked();

    void on_pushButton_UPDATE_clicked();

    void on_pushButton_UPDATE_2_clicked();

private:
    Ui::MainWindow *ui;
   diffusion diff;
};
#endif // MAINWINDOW_H
