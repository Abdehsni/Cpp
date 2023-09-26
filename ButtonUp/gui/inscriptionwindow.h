#ifndef INSCRIPTIONWINDOW_H
#define INSCRIPTIONWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "game.h"

namespace Ui {
class InscriptionWindow;
}

class InscriptionWindow : public QMainWindow
{
    Q_OBJECT

public:
     explicit InscriptionWindow(model::Game* game,QWidget *parent = nullptr);
    ~InscriptionWindow();
    string& getNamePlayer1();
    unsigned& getAgePlayer1();
    string& getNamePlayer2();
    unsigned& getAgePlayer2();

private slots:
    void inscriptionFirstPlayer();
    void inscriptionSecondPlayer();
    void launchGame();

private:
    Ui::InscriptionWindow *ui;
    model::Game *game;
    bool isEmpty(QString string);
    string namePlayer1;
    unsigned agePlayer1;
    string namePlayer2;
    unsigned agePlayer2;
};

#endif // INSCRIPTIONWINDOW_H
