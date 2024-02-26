#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QPushButton>
#include <QString>
#include <QDate>
#include <QByteArray>
#include "media.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_3M->setVisible(false);
    ui->returnButtonM->setVisible(false);
    ui->deleteButtonM->setVisible(false);
    ui->modifyButtonM->setVisible(false);

    ui->descriptionRM->setVisible(false);
    ui->returnButton_2M->setVisible(false);
    ui->deleteButton_2M->setVisible(false);
    ui->modifyButton_2M->setVisible(false);

     ui->barreTrieM->setVisible(false);
     ui->barreTrie_2M->setVisible(false);

     connect(ui->imageButtonM, &QPushButton::clicked, this, &MainWindow::importImage);




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loM_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_2M_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_radioM_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_tvM_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_tv_2M_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_deleteButtonM_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_modifyButtonM_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_addButtonM_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

    QString titre=ui->TitleM->text();
    QString producteur=ui->ProducerM->text();
    QString description=ui->textEditM->toPlainText();
    //QByteArray image=ui->imageButtonM->text();
    Media m;//(titre,description,"",producteur,0,"","");
    bool test=m.ajouterMedia();
    if(test)
    { QMessageBox::information(nullptr, QObject::tr("ok"),
                              QObject::tr("Ajout effectué.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);}
    else
    {QMessageBox::critical(nullptr, QObject::tr(" Not ok"),
                                      QObject::tr("Ajout non effectué.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);}


}

void MainWindow::on_seriesM_clicked()
{
    if (ui->label_3M->isVisible()) {
            ui->label_3M->setVisible(false);
            ui->returnButtonM->setVisible(false);
            ui->deleteButtonM->setVisible(false);
            ui->modifyButtonM->setVisible(false);
        } else {
            ui->label_3M->setVisible(true);
            ui->label_3M->raise();
            ui->returnButtonM->setVisible(true);
            ui->returnButtonM->raise();
            ui->deleteButtonM->setVisible(true);
            ui->deleteButtonM->raise();
            ui->modifyButtonM->setVisible(true);
            ui->modifyButtonM->raise();
        }
}

void MainWindow::on_returnButtonM_clicked()
{
    if (ui->label_3M->isVisible()) {
            ui->label_3M->setVisible(false);
            ui->returnButtonM->setVisible(false);
            ui->deleteButtonM->setVisible(false);
            ui->modifyButtonM->setVisible(false);
        } if (ui->label_3M->isVisible()) {
            ui->label_3M->setVisible(true);
            ui->label_3M->raise();
            ui->returnButtonM->setVisible(true);
            ui->returnButtonM->raise();
        }
}

void MainWindow::on_add_2M_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_modifyButton_2M_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_vwatchRadioM_clicked()
{
    if (ui->descriptionRM->isVisible()) {
            ui->descriptionRM->setVisible(false);
            ui->returnButtonM->setVisible(false);
            ui->deleteButtonM->setVisible(false);
            ui->modifyButtonM->setVisible(false);
        } else {
            ui->descriptionRM->setVisible(true);
            ui->descriptionRM->raise();
            ui->returnButton_2M->setVisible(true);
            ui->returnButton_2M->raise();
            ui->deleteButton_2M->setVisible(true);
            ui->deleteButton_2M->raise();
            ui->modifyButton_2M->setVisible(true);
            ui->modifyButton_2M->raise();
        }

}

void MainWindow::on_returnButton_2M_clicked()
{
    if (ui->descriptionRM->isVisible()) {
            ui->descriptionRM->setVisible(false);
            ui->returnButton_2M->setVisible(false);
            ui->deleteButton_2M->setVisible(false);
            ui->modifyButton_2M->setVisible(false);
        } if (ui->descriptionRM->isVisible()) {
            ui->descriptionRM->setVisible(true);
            ui->descriptionRM->raise();
            ui->returnButton_2M->setVisible(true);
            ui->returnButton_2M->raise();
        }

}

void MainWindow::on_trieButtonM_clicked()

{
    if (!isTrieButtonClicked) {
            ui->barreTrieM->setVisible(true);
            isTrieButtonClicked = true;
        } else {
             ui->barreTrieM->setVisible(false);
            isTrieButtonClicked = false;
        }
}

void MainWindow::on_vewatchButtonM_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_trieButton_2M_clicked()
{
    if (!isTrieButtonClicked) {
            ui->barreTrie_2M->setVisible(true);
            isTrieButtonClicked = true;
        } else {
             ui->barreTrie_2M->setVisible(false);
            isTrieButtonClicked = false;
        }

}

void MainWindow::on_statisticsM_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_statistics_2M_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_brandsButton_2M_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_brandsButtonM_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::importImage()
{
    // Ouvrir une boîte de dialogue pour sélectionner un fichier
    QString imagePath = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));
 }

void MainWindow::on_vewatch_2M_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}
