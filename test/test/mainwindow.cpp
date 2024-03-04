#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QPushButton>
#include <QString>
#include <QDate>
#include <QByteArray>
#include "media.h"
#include <QMessageBox>
#include <QSqlTableModel>
#include <QSqlQuery>


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
     connect(ui->radioButtonM, &QRadioButton::clicked, this, [=]() {
         type = "Radio";
     });

     connect(ui->radioButton_2M, &QRadioButton::clicked, this, [=]() {
         type = "Channel";
     });

     Media media;
     //ui->tableViewM->setModel(media.afficherMedia());


// connect(ui->afficherButton, &QPushButton::clicked, this, &MainWindow::afficherMedia);

}

void MainWindow::afficherDonnees() {
    QSqlQuery query;
    query.prepare("SELECT IMAGE, DESCRIPTION FROM MEDIA WHERE TYPE = 'Channel'");
    if (query.exec()) {
        int i = 1; // Index de bouton commence à 1
        while (query.next()) {
            QByteArray imageData = query.value(0).toByteArray();
            QString description = query.value(1).toString();

            // Créer le nom du bouton
            QString buttonName = "button" + QString::number(i);

            // Convertir les données d'image en QIcon
            QIcon icon;
            QPixmap pixmap;
            pixmap.loadFromData(imageData);
            icon.addPixmap(pixmap);

            // Assigner l'image au bouton correspondant
            QPushButton *button = findChild<QPushButton *>(buttonName);
            if (button) {
                button->setIcon(icon);
                button->setIconSize(pixmap.size());
                button->setProperty("description", description);

                // Connecter le signal clicked de chaque bouton à la fonction afficherDescription
                connect(button, &QPushButton::clicked, this, &MainWindow::afficherDescription);
            }

            i++; // Incrémenter l'index de bouton
        }
    }
}

void MainWindow::afficherDescription() {
    // Récupérer le bouton qui a été cliqué
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button)
        return;

    // Récupérer la description associée au bouton
    QString description = button->property("description").toString();

    // Afficher la description dans le label
    ui->label_3M->setText(description);
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
    Media m;
    QString titre = ui->TitleM->text();
    QString producteur = ui->ProducerM->text();
    QString description = ui->textEditM->toPlainText();

    // Vérifier si le titre existe déjà dans la base de données
    if (m.isTitleRepeated(titre)) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("This title already exists.\n"
                                          "Please enter another title."),
                              QMessageBox::Ok);
        return; // Arrêter l'exécution de la fonction si le titre est répété
    }

    QByteArray image = importImage();

    // Vérifier si une image a été insérée
    if (!m.isImageInserted(image)) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Please insert an image."),
                              QMessageBox::Ok);
        return; // Arrêter l'exécution de la fonction si aucune image n'a été insérée
    }

    // Vérifier si un producteur a été inséré
    if (!m.isProducerInserted(producteur)) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Please insert a producer."),
                              QMessageBox::Ok);
        return; // Arrêter l'exécution de la fonction si aucun producteur n'a été inséré
    }
    // Vérifier si la description est valide
        if (!m.isDescriptionValid(description)) {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                  QObject::tr("Description should be less than 200 characters."),
                                  QMessageBox::Ok);
            return; // Arrêter l'exécution de la fonction si la description est trop longue
        }

    // Ajouter le média si toutes les vérifications sont passées avec succès
    bool test = m.ajouterMedia(titre, description, image, producteur, type);
    if (!test) {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("The addition was not made.\n"
                                          "Please try again."),
                              QMessageBox::Ok);
        return; // Arrêter l'exécution de la fonction si l'ajout n'est pas réussi
    }

    QMessageBox::information(nullptr, QObject::tr("OK"),
                             QObject::tr("Addition is validated.\n"
                                         "Click OK to exit."),
                             QMessageBox::Ok);
}






void MainWindow::on_button1_clicked()
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
QByteArray MainWindow::importImage()
{
    // Ouvrir une boîte de dialogue pour sélectionner un fichier
    QString imagePath = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));

    // Vérifier si un fichier a été sélectionné
    if (!imagePath.isEmpty()) {
        QFile file(imagePath);
        if (file.open(QIODevice::ReadOnly)) {
            // Lire les données de l'image
            QByteArray imageData = file.readAll();
            file.close();
            return imageData;
        } else {
            qDebug() << "Erreur: Impossible d'ouvrir le fichier image.";
        }
    } else {
        qDebug() << "Erreur: Aucun fichier image sélectionné.";
    }

    return QByteArray(); // Retourner un QByteArray vide en cas d'erreur
}
void MainWindow::on_vewatch_2M_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


bool MainWindow::supprimerMedia(QString titre)
{
    QSqlQuery query;
    QString res = titre;
    query.prepare("delete from MEDIA where TITRE= :titre");
    query.bindValue(":titre", res);
    return query.exec();
}

void MainWindow::on_listM_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    int ligne(0);
    int row(0);
    QSqlQuery query;
    query.exec("SELECT COUNT(*) FROM MOVIE");
    while(query.next())
    {
        ligne = query.value(0).toInt();
    }

    QStandardItemModel *model = new QStandardItemModel(ligne, 6);
    query.exec("SELECT TITRE, DESCRIPTION, IMAGE, PRODUCTEUR, TYPE FROM MEDIA");
    while(query.next())
    {
        for (int j = 0; j < 4; j++)
        {
            QStandardItem *item;

            if (j == 3)
            {
                QByteArray array;
                array = query.value(j).toByteArray();
                QPixmap pixmap;
                pixmap.loadFromData(array, "JPG && PNG", Qt::AutoColor);
                QPixmap scaled = pixmap.scaled(QSize(250, 250));
                item = new QStandardItem();
                item->setData(scaled, Qt::DecorationRole);
            }
            else if (j < 3)
            {
                item = new QStandardItem(query.value(j).toString());
            }

            if (j < 4)
            {
                item->setTextAlignment(Qt::AlignCenter);
                model->setItem(row, j, item);
            }
        }
        row++;
    }

    model->setHeaderData(0, Qt::Horizontal, "id");
    model->setHeaderData(1, Qt::Horizontal, "titre");
    model->setHeaderData(2, Qt::Horizontal, "description");
    model->setHeaderData(3, Qt::Horizontal, "photo");
    model->setHeaderData(4, Qt::Horizontal, "delete");
    model->setHeaderData(5, Qt::Horizontal, "update");
    ui->tableViewM->setModel(model);

    for (int j = 0; j < row; j++)
    {
        QPushButton *butt;
        butt = new QPushButton(")");
        QString name = QString("buttondel%1").arg(j);
        QString display = QString(")");
        butt->setObjectName(name);
        butt->setText(display);

        connect(butt, &QPushButton::clicked, this, [this, j]() {
            Media m;
            if (m.supprimerMedia(ui->tableViewM->model()->data(ui->tableViewM->model()->index(j, 0)).toString()))
            {
                QMessageBox::information(this, ")", "Data Deleted successfully", QMessageBox::Ok);
            }
            else
            {
                QMessageBox::critical(this, "Error", "Couldn't delete data");
            }
        });
        butt->setStyleSheet("color:red;"
                            "background:transparent;"
                            "border:none;"
                            "font-size: 35px;"
                            " font-weight: bold; "
                            "border-radius: 10;"
                            "font-family:DRIPICONS-V2;"
                            "font: 15pt;");




        ui->tableViewM->setIndexWidget(model->index(j, 4), butt);

        butt = new QPushButton("*");
        name = QString("buttonup%1").arg(j);
        display = QString("*");
        butt->setObjectName(name);
        butt->setText(display);

        connect(butt, &QPushButton::clicked, this, [this, j]() {
            ui->TitleM->setText(ui->tableViewM->model()->data(ui->tableViewM->model()->index(j, 0)).toString());
            ui->textEditM->setText(ui->tableViewM->model()->data(ui->tableViewM->model()->index(j, 1)).toString());
            ui->ProducerM->setText(ui->tableViewM->model()->data(ui->tableViewM->model()->index(j, 2)).toString());
            QPixmap pixmap = ui->tableViewM->model()->data(ui->tableViewM->model()->index(j, 3), Qt::DecorationRole).value<QPixmap>();
        });

        butt->setStyleSheet("color:green;"
                            "background:transparent;"
                            "border:none;"
                            "font-size: 35px;"
                            " font-weight: bold; "
                            "border-radius: 10;"
                            "font-family:DRIPICONS-V2;"
                            "font: 15pt;");
        ui->tableViewM->setIndexWidget(model->index(j, 5), butt);
    }

    ui->tableViewM->verticalHeader()->setVisible(false);
    ui->tableViewM->viewport()->setStyleSheet("background: rgb(255, 255, 255);"
                                              "border: 1px solid white;"
                                              "border-radius: 10px;"
                                              "color: black;");
    QRect rect = ui->tableViewM->viewport()->rect();
    QPainterPath path;
    rect.adjust(+1, +1, -1, -1);
    path.addRoundedRect(rect, 25, 25);
    QRegion mask = QRegion(path.toFillPolygon().toPolygon());
    ui->tableViewM->viewport()->setMask(mask);
    ui->tableViewM->resize(ui->tableViewM->rowHeight(0) * row, ui->tableViewM->columnWidth(3) * 4);
    ui->tableViewM->resizeRowsToContents();
    ui->tableViewM->resizeColumnsToContents();
}
