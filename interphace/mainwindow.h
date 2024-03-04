#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <qstackedwidget.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QByteArray byte;

private slots:
    void on_pushButton_2ms_clicked();

    void on_pushButton_4ms_clicked();

    void on_pushButton_5ms_clicked();

    void on_pushButton_11ms_clicked();

    void on_pushButton_3ms_clicked();

    void on_pushButton_12ms_clicked();



    void on_returnupms_clicked();

    void on_confirmupms_clicked();

    void on_upimagems_clicked();

    void on_pushButtonms_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
