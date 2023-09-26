#ifndef GUIVIEW_H
#define GUIVIEW_H
#include <QWidget>
#include "gamestate.h"
#include "observer.h"
#include "inscriptionwindow.h"
#include "mainwindow.h"
#include "game.h"

using model::GameState;

namespace view{

class guiView : public QWidget, public observer::Observer
{

public:
    guiView(model::Game *game, QWidget *parent = nullptr);
    ~guiView();
    void update(const observer::Observable *obs) override;

private:
    InscriptionWindow *i;
    MainWindow *w;
    model::Game *game;
    void updateView(model::Game *game);
};





}


#endif // GUIVIEW_H


