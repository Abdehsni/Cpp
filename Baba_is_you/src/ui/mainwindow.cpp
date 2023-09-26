#include "mainwindow.h"
#include "ui_mainwindow.h"
#define sticker_size 20
#define nbr_of_case 18  //usully defined by the width and  height of each board of levels,but for the five first levels, it's always 18*18


MainWindow::MainWindow(ControllerGui *controller,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),controller(controller)
{
    initialiseStickers();
    ui->setupUi(this);
    // the two first parameter are 0,0 because the first coordinate at the top left of the board is always 0,0( x=0,y=0)
    ui->graphicsView->setFocusPolicy(Qt::NoFocus);
    ui->reloadLevelButton->setFocusPolicy(Qt::NoFocus);
    ui->inputText->setFocusPolicy(Qt::NoFocus);
    ui->noButton->setFocusPolicy(Qt::NoFocus);
    ui->yesButton->setFocusPolicy(Qt::NoFocus);
    ui->saveAndLeaveButton->setFocusPolicy(Qt::NoFocus);
    scene = new QGraphicsScene(0,0,(sticker_size*nbr_of_case+sticker_size),(sticker_size*nbr_of_case+sticker_size));
    ui->graphicsView->setScene(scene);
    this->setFocusPolicy(Qt::StrongFocus);

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::update(const Observable * subject){
    const model::Game* game = dynamic_cast<const model::Game*>(subject);
    if (game != nullptr) {
        displayGame(*game);
    }

}


void MainWindow::beginning(){
    ui->reloadLevelButton->hide();
    ui->saveAndLeaveButton->hide();
    ui->loadOrSaveButton->hide();
    ui->messageBoxLabel->setText(" Do you want to load a game? ");
    QObject::connect(ui->yesButton,SIGNAL(clicked()),
                     this, SLOT(onTheWayToLoadAFile()));

    QObject::connect(ui->noButton,SIGNAL(clicked()),
                     this, SLOT(beginTheGame()));

    QObject::connect(ui->loadOrSaveButton,SIGNAL(clicked()),this,SLOT(loadOrSaveAFile()));

    QObject::connect(ui->reloadLevelButton,SIGNAL(clicked()),this,SLOT(reloadLevel()));

    QObject::connect(ui->saveAndLeaveButton,SIGNAL(clicked()),this,SLOT(onTheWayToSaveAGame()));

}




void MainWindow::beginTheGame(){
    ui->yesButton->hide();
    ui->noButton->hide();
    ui->inputText->hide();
    ui->messageBoxLabel->clear();
    ui->saveAndLeaveButton->show();
    ui->reloadLevelButton->show();
    controller->startGameWithoutFile();
}


void MainWindow::loadOrSaveAFile()
{
    if(controller->isLoadingGame()){
        bool loadingSuccess{false};
        auto filename= ui->inputText->text().toStdString();

        if(!controller->verifyFilename(filename)){
            ui->inputText->clear();
            ui->messageBoxLabel->setText("Wrong FileName ,try again ( must finish with .txt) ");
        }

        try{
            controller->loadGame(filename);
            loadingSuccess=true;
        }catch (const std::invalid_argument& e) {
            ui->messageBoxLabel->setText(e.what());
            ui->inputText->clear();
        }

        if(loadingSuccess){
            ui->inputText->setFocusPolicy(Qt::NoFocus);
            ui->inputText->hide();
            ui->messageBoxLabel->clear();
            ui->loadOrSaveButton->hide();
            ui->reloadLevelButton->show();
            ui->saveAndLeaveButton->show();
        }
    }else{
        bool savingSuccess{false};
        auto filename= ui->inputText->text().toStdString();

        if(!controller->verifyFilename(filename)){
            ui->inputText->clear();
            ui->messageBoxLabel->setText("Wrong FileName ,try again ( must finish with .txt) ");
        }
        try{
            controller->saveGame(filename);
            savingSuccess=true;
        }catch (const std::invalid_argument& e) {
            ui->messageBoxLabel->setText(e.what());
            ui->inputText->clear();
        }

        if(savingSuccess){
            QApplication::quit();
        }
    }
}

void MainWindow::reloadLevel()
{
    controller->reloadLevelGame();
}


void MainWindow::initialiseStickers()
{
    QPixmap you("./../../Baba_is_you/resources/text_you.png");
    auto you_resized=you.scaled(sticker_size,sticker_size);
    stickers["text_you"]= you_resized;
    QPixmap stop("./../../Baba_is_you/resources/text_stop.png");
    auto stop_resized=stop.scaled(sticker_size,sticker_size);
    stickers["text_stop"] =stop_resized;
    QPixmap push("./../../Baba_is_you/resources/text_push.png");
    auto push_resized=push.scaled(sticker_size,sticker_size);
    stickers["text_push"] =push_resized;
    QPixmap win("./../../Baba_is_you/resources/text_win.png");
    auto win_resized=win.scaled(sticker_size,sticker_size);
    stickers["text_win"] = win_resized;
    QPixmap sink("./../../Baba_is_you/resources/text_sink.png");
    auto sink_resized=sink.scaled(sticker_size,sticker_size);
    stickers["text_sink"] = sink_resized;
    QPixmap kill("./../../Baba_is_you/resources/text_kill.png");
    auto kill_resized=kill.scaled(sticker_size,sticker_size);
    stickers["text_kill"] = kill_resized;
    QPixmap text_wall("./../../Baba_is_you/resources/text_wall.png");
    auto text_wall_resized=text_wall.scaled(sticker_size,sticker_size);
    stickers["text_wall"] =text_wall_resized;
    QPixmap text_rock("./../../Baba_is_you/resources/text_rock.png");
    auto text_rock_resized=text_rock.scaled(sticker_size,sticker_size);
    stickers["text_rock"] = text_rock_resized;
    QPixmap text_baba("./../../Baba_is_you/resources/text_baba.png");
    auto text_baba_resized =text_baba.scaled(sticker_size,sticker_size);
    stickers["text_baba"] = text_baba_resized;
    QPixmap text_flag("./../../Baba_is_you/resources/text_flag.png");
    auto text_flag_resized = text_flag.scaled(sticker_size,sticker_size);
    stickers["text_flag"] = text_flag_resized;
    QPixmap text_lava("./../../Baba_is_you/resources/text_lava.png");
    auto text_lava_resized = text_lava.scaled(sticker_size,sticker_size);
    stickers["text_lava"] = text_lava_resized;
    QPixmap text_grass("./../../Baba_is_you/resources/text_grass.png");
    auto text_grass_resized = text_grass.scaled(sticker_size,sticker_size);
    stickers["text_grass"] = text_grass_resized;
    QPixmap text_metal("./../../Baba_is_you/resources/text_metal.png");
    auto text_metal_resized = text_metal.scaled(sticker_size,sticker_size);
    stickers["text_metal"] = text_metal_resized;
    QPixmap text_water("./../../Baba_is_you/resources/text_water.png");
    auto text_water_resized = text_water.scaled(sticker_size,sticker_size);
    stickers["text_water"] = text_water_resized;
    QPixmap is("./../../Baba_is_you/resources/is.png");
    auto is_resized= is.scaled(sticker_size,sticker_size);
    stickers["is"]= is_resized;
    QPixmap wall("./../../Baba_is_you/resources/wall.png");
    auto wall_resized=wall.scaled(sticker_size,sticker_size);
    stickers["wall"] = wall_resized;
    QPixmap rock("./../../Baba_is_you/resources/rock.png");
    auto rock_resized = rock.scaled(sticker_size,sticker_size);
    stickers["rock"] = rock_resized;
    QPixmap baba("./../../Baba_is_you/resources/baba.png");
    auto baba_resized=baba.scaled(sticker_size,sticker_size);
    stickers["baba"]= baba_resized;
    QPixmap metal("./../../Baba_is_you/resources/metal.png");
    auto metal_resized = metal.scaled(sticker_size,sticker_size);
    stickers["metal"] = metal_resized;
    QPixmap grass("./../../Baba_is_you/resources/grass.png");
    auto grass_resized = grass.scaled(sticker_size,sticker_size);
    stickers["grass"] = grass_resized;
    QPixmap flag("./../../Baba_is_you/resources/flag.png");
    auto flag_resized = flag.scaled(sticker_size,sticker_size);
    stickers["flag"] = flag_resized;
    QPixmap water("./../../Baba_is_you/resources/water.png");
    auto water_resized = water.scaled(sticker_size,sticker_size);
    stickers["water"] = water_resized;
    QPixmap lava("./../../Baba_is_you/resources/lava.png");
    auto lava_resized = lava.scaled(sticker_size,sticker_size);
    stickers["lava"] = lava_resized;
}


void MainWindow::displayGame(const model::Game &game)
{
    clearScene(ui->graphicsView->scene());
    auto cases= game.getBoard().getCases();
       for(int x=0;x<game.getBoard().getLength();x++){
           for(int y=0;y<game.getBoard().getWidth();y++){
            auto range = cases.equal_range(model::Coordinate(x,y));
            for (auto iteration = range.first; iteration != range.second; ++iteration) {
                auto gameObject=iteration->second;
                //stikers is one attribute of mainwindow class
                std::string objectName=convertTheObjectToStickersKey(gameObject);
                auto pixmapObject= new QGraphicsPixmapItem(stickers.find(objectName)->second);
                int gameObjectCoordinateX=gameObject.getCoordinate().getX()*sticker_size;
                int gameObjectCoordinateY=gameObject.getCoordinate().getY()*sticker_size;
                pixmapObject->setPos(gameObjectCoordinateX,gameObjectCoordinateY);
                ui->graphicsView->scene()->addItem(pixmapObject);
            }


        }
    }



}

void MainWindow::clearScene(QGraphicsScene *scene)
{
    if (scene) {
        QList<QGraphicsItem*> items = scene->items();
        for (QGraphicsItem* item : items) {
            scene->removeItem(item);
            delete item;
        }
    }
}




void MainWindow::onTheWayToLoadAFile(){
    ui->inputText->setFocusPolicy(Qt::StrongFocus);
    ui->messageBoxLabel->setText(" Enter the name of your file in the input line text (.txt existing file only) ");
    ui->yesButton->hide();
    ui->noButton->hide();
    ui->loadOrSaveButton->setText("Load");
    ui->loadOrSaveButton->show();

}

void MainWindow::onTheWayToSaveAGame()
{
    ui->inputText->setFocusPolicy(Qt::StrongFocus);
    ui->messageBoxLabel->setText(" Enter the name of your file in the input line text (.txt existing file only) ");
    ui->saveAndLeaveButton->hide();
    ui->reloadLevelButton->hide();
    ui->inputText->show();
    ui->loadOrSaveButton->setText("Save");
    ui->loadOrSaveButton->show();
}


std::string MainWindow::convertTheObjectToStickersKey(const model::GameObject &gameObject)
{
    std::string result{};
    auto element=gameObject.getElement();
    if(gameObject.isConnector()){
        switch(element){
        case model::Elements::IS: result="is";break;
        default:break;
        }
    }else if(gameObject.isText()){
        switch(element){
        case model::Elements::YOU: result="text_you";break;
        case model::Elements::STOP: result="text_stop";break;
        case model::Elements::PUSH: result="text_push";break;
        case model::Elements::WIN: result="text_win";break;
        case model::Elements::SINK: result="text_sink";break;
        case model::Elements::KILL:result="text_kill";break;
        case model::Elements::WALL:result="text_wall";break;
        case model::Elements::ROCK:result="text_rock";break;
        case model::Elements::BABA:result="text_baba";break;
        case model::Elements::METAL:result="text_metal";break;
        case model::Elements::GRASS:result="text_grass";break;
        case model::Elements::FLAG:result="text_flag";break;
        case model::Elements::WATER:result="text_water";break;
        case model::Elements::LAVA:result="text_lava";break;
        default:break;
        }
    }else if(gameObject.isElement()){
        switch(element){
        case model::Elements::WALL:result="wall";break;
        case model::Elements::ROCK:result="rock";break;
        case model::Elements::BABA:result="baba";break;
        case model::Elements::METAL:result="metal";break;
        case model::Elements::GRASS:result="grass";break;
        case model::Elements::FLAG:result="flag";break;
        case model::Elements::WATER:result="water";break;
        case model::Elements::LAVA:result="lava";break;
        default:break;
        }
    }else{
        std::invalid_argument("gameobject to display not recognized ");
    }
    return result;

}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(controller->isGameStarded()){
        if(event->key()== Qt::Key_Up){
            controller->move(model::Direction::NORTH);
        }else if(event->key()== Qt::Key_Down){
            controller->move(model::Direction::SOUTH);
        }else if(event->key()== Qt::Key_Right){
            controller->move(model::Direction::EAST);
        }else if(event->key()== Qt::Key_Left){
            controller->move(model::Direction::WEST);
        }
    }
}
