#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <utility/Observer.h>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QDebug>
#include "controllergui.h"
#include "qgraphicsscene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow,public Observer
{
    Q_OBJECT

public:
    MainWindow(ControllerGui *controller,QWidget *parent = nullptr);
    ~MainWindow();
    void update(const Observable * subject)override;
    void beginning();
    //void startTheGame();


public slots:
    void onTheWayToLoadAFile();
    void onTheWayToSaveAGame();
    void beginTheGame();
    void loadOrSaveAFile();
    void reloadLevel();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    ControllerGui *controller;
    std::map<std::string,QPixmap> stickers;


    void initialiseStickers();
    void displayGame(const model::Game &game);
    void clearScene(QGraphicsScene* scene);
    std::string convertTheObjectToStickersKey(const model::GameObject &gameObject);
    void keyPressEvent(QKeyEvent *event)override;
};

#endif // MAINWINDOW_H
