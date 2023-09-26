#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Game.h"
#include "guiController.h"
#include "Position.h"
#include "Piece.h"
#include "ColorPiece.h"
#include "Board.h"
#include "Player.h"
#include "gameState.h"
#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QLayout>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;}

using model::Game;
using model::Position;
using model::Piece;
using model::ColorPiece;
using model::Player;
using model::GameState;

QT_END_NAMESPACE

struct Pos{int row;
           int col;};
class GuiView : public QMainWindow, public observer::Observer
{
    Q_OBJECT

public:
    GuiView(Game *game,QWidget *parent = nullptr);
    ~GuiView();
    void update(const observer::Observable * observable)override;
    Pos gridPosition(QWidget * widget);
    void updateBox();
    void updateBox2();

    Piece piece();
    void affichagePiece();
    void configStartButton();
    QString getNamePlayer();

private slots:
    void displayBoard();
    void displayBox();
    void surrender();
    void clickedButtonBox();
    void clickedButtonBox2();

    void clickedButtonBoard();
    void endPlacementPiece();
   // void howToInitGame();
  //  void boxPlayer2();
    void initWithFile();
   // void startGame();
    //QString namePlayer();
    //void namePlayer2();

private:
    Ui::MainWindow *ui;
    Game *game;
    string pieceSelected ;
    Position positionStart;
    Position positionEnd;
    int placement ;//meme utilisation que change
    bool change=false ;//utilisation dans selection de piece et la poser sur le board

    void inscriptionPlayers();
    void updateLabelPlayers();
};


#endif // MAINWINDOW_H
