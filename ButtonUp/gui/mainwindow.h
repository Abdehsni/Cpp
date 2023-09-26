#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <stdexcept>
#include <string>
#include "observable.h"
#include "game.h"
#include "token.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(model::Game* game,QWidget *parent = nullptr);
    ~MainWindow();
    void displayTokens();
    void displayTabScore();
    void displayScore();
    void displayMessageEndRound();
    void setSignals();
    void displayMessageInProcess();
    void displayErrorMessage();
    void nextAfterError();
    void toContinue();
    void winnerChoseFirstPlay();
    void nextRound();
private slots:
    void moveGui();
    void afterError();
    void next();
    void oui();
    void no();
private:
    Ui::MainWindow *ui;
    model::Game *game;
    unsigned indexCaseSelected{0};
    void displayOneCaseWithQueue(unsigned nbOfTheCase);
    void disconnectAllBtnOfBoard();
    void resetColorQueueAtIndex(unsigned i);
    QPushButton* pushButtonOnTheBoard(unsigned index);
    vector<QPushButton*> fileToFill(unsigned index);


};
#endif // MAINWINDOW_H
