#include "inscriptionwindow.h"
#include "ui_inscriptionwindow.h"

InscriptionWindow::InscriptionWindow(model::Game* game,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InscriptionWindow),game{game}
{
    ui->setupUi(this);
    connect(ui->entryValidationButton,SIGNAL(clicked()),this,
            SLOT(inscriptionFirstPlayer()),Qt::UniqueConnection);
}

InscriptionWindow::~InscriptionWindow()
{
    delete ui;
}

string &InscriptionWindow::getNamePlayer1()
{
    return this->namePlayer1;
}

unsigned &InscriptionWindow::getAgePlayer1()
{
    return this->agePlayer1;
}

string &InscriptionWindow::getNamePlayer2()
{
    return this->namePlayer2;
}

unsigned &InscriptionWindow::getAgePlayer2()
{
    return this->agePlayer2;
}


void InscriptionWindow::inscriptionFirstPlayer()
{
  QString text= ui->lineNameEdit->text();
  if(isEmpty(text)){
      ui->labelMessageBox->setText("Entrez un nom !");
  }else{
      namePlayer1= text.toStdString();
      agePlayer1=ui->spinBoxNumber->value();
      ui->lineNameEdit->clear();
      ui->entryValidationButton->disconnect();
      connect(ui->entryValidationButton,SIGNAL(clicked()),this,
              SLOT(inscriptionSecondPlayer()),Qt::UniqueConnection);
      ui->labelMessageBox->setText("Joueur 2, inscris toi");
      ui->entryValidationButton->setText("Valider l'inscription");
  }
}

void InscriptionWindow::inscriptionSecondPlayer()
{
    QString text= ui->lineNameEdit->text();
    if(isEmpty(text)){
        ui->labelMessageBox->setText("Entrez un nom !");
    }else{
        ui->labelMessageBox->setText("Inscription reussie, cliquez pour commencer la partie");
        namePlayer2=text.toStdString();
        agePlayer2=ui->spinBoxNumber->value();
        ui->entryValidationButton->disconnect();
        ui->entryValidationButton->setText("Cliquez ici");
        connect(ui->entryValidationButton,SIGNAL(clicked()),this,
                SLOT(launchGame()),Qt::UniqueConnection);
    }

}

void InscriptionWindow::launchGame()
{
  ui->entryValidationButton->disconnect();
  game->realInscription(namePlayer1,agePlayer1,namePlayer2,agePlayer2);
}


bool InscriptionWindow::isEmpty(QString string){
    if(string==""||string=="")return true;
    else return false;
}
