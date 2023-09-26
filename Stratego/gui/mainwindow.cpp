#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
using namespace std;

GuiView::GuiView(Game *game,QWidget *parent)
    :QMainWindow(parent)
    , ui(new Ui::MainWindow),game(game)
{
   ui->setupUi(this);
   displayBoard();
   //startGame();
   //connect(ui->buttonStart,&QPushButton::clicked,this,&MainWindow::initWithFile);
}


GuiView::~GuiView()
{
    delete ui;
    game->removeObserver(this);
}


void GuiView::inscriptionPlayers(){
    string name;
    ui->labelBottomPage->setText("Lorsque vous avez fini d'entrer votre nom, appuyez sur la touche enter");
    //connect(ui->nameInputLayout,&QLineEdit::returnPressed,this,&MainWindow::namePlayer);
    game->setP1(Player(name,ColorPiece::RED));
    ui->labelStart->setText("Joueur 2,entrez votre nom :");
    name=getNamePlayer().toStdString();
    game->setP2(Player(name,ColorPiece::BLUE));
    game->notifyView();
}


//QString MainWindow::namePlayer(){
//    return QString::fromStdString(getNamePlayer());
//}
//C:/Users/Soulivane/Documents/strategoFinal1/stratego/Stratego/metier/config_player1.txt
//C:\Users\Soulivane\Documents\strategoFinal1\stratego\Stratego\metier\config_player1.txt
//C:\Users\Soulivane\Documents\strategoFinal1\stratego\Stratego\metier\config_player1.txt

//void MainWindow::startGame(){
//    ui->buttonStart->setDisabled(true);
//    inscriptionPlayers();
   // configStartButton();
//    bool stillGame(true);
//        while(stillGame){
//    }
//}


void GuiView::configStartButton(){
    connect(ui->buttonStart,&QPushButton::clicked,this,&GuiView::displayBox);
}


QString GuiView::getNamePlayer(){
    QString name(ui->nameInputLayout->text());
    ui->nameInputLayout->clear();
    return name;
}


//void MainWindow::howToInitGame(){

//}

void GuiView::updateLabelPlayers(){
    string name(game->getP1().getName());
    ui->labelPlayer1->setText(QString::fromStdString(name));
    name=game->getP2().getName();
    ui->labelPlayer2->setText(QString::fromStdString(name));
}


void GuiView::update(const observer::Observable * observable){
    if(observable==game){
//        if(game->getGamestate()==GameState::){
//            updateLabelPlayers();
//        }
   }
    displayBoard();
}



void GuiView::displayBoard(){

        this->change=true;
    for (int i =0;i<10 ;i++ ) {
        for (int j =0;j<10 ;j++ ) {
            QPushButton *button = new QPushButton(this);
            button->setStyleSheet("border:1px solid #3B330D;");
            ui->gridLayoutBoard->addWidget(button,i,j);
            ui->gridLayoutBoard->itemAtPosition(i,j)->widget()->setFixedSize(48,41);
            if(game->getBoard().indexPosWater(i,j))   {
                button->setStyleSheet("background-color:#02007A;");

            }
            connect(button,&QPushButton::clicked,this,&GuiView::clickedButtonBoard);
        }
    }

}


void GuiView::displayBox(){

    int iPiece=0;
    string a ;
    if(this->change){
        this->game->nextPlayer();
        a=  game->getBox().getPiecesP2()[iPiece].getSymbol();
    }

        for (int i =0;i<4 ;i++ ) {
            for (int j =0;j<10 ;j++ ) {
                 a=  game->getBox().getPiecesP1()[iPiece].getSymbol();

                QString qstr = QString::fromStdString(a);
                QPushButton *button = new QPushButton(qstr,this);
                if(this->game->getCurrentPlayer().getColorPiece()==ColorPiece::RED)button->setStyleSheet("background-color:RED");
                else button->setStyleSheet("background-color:CYAN");

                if(this->change){
                    connect(button,&QPushButton::clicked,this,&GuiView::clickedButtonBox);
                    ui->gridLayoutBox->addWidget(button,i,j);
                }else{
                    connect(button,&QPushButton::clicked,this,&GuiView::clickedButtonBox2);
                    ui->gridLayoutBox2->addWidget(button,i,j);
               //    button->setDisabled(true);

                }
                iPiece++;
            }
        }

}


void GuiView::clickedButtonBox(){

   QPushButton *button=(QPushButton*) sender();
   QString str=button->text();
   this->pieceSelected=str.toStdString();
   this->placement=ui->gridLayoutBox->indexOf(button);
   this->change=false;
}

void GuiView::clickedButtonBox2(){

   QPushButton *button=(QPushButton*) sender();
   QString str=button->text();
   this->pieceSelected=str.toStdString();
   this->placement=ui->gridLayoutBox2->indexOf(button);
   this->change=true;

}

Pos GuiView::gridPosition(QWidget *widget)
{
    if(!widget->parentWidget()) return{};
    auto layout= qobject_cast<QGridLayout*>(widget->parentWidget()->layout());
    if(!layout) return{};
    int i= layout->indexOf(widget);
    Q_ASSERT(i>=0);
    int _;
    Pos pos;
    layout->getItemPosition(i,&pos.row,&pos.col,&_,&_);
    return pos;
}

void GuiView::clickedButtonBoard(){
    QPushButton *button=(QPushButton*) sender();
    Pos position= gridPosition(button);
    Position pos(position.row,position.col);

    if(game->getBoard().getSquareAt(pos).isEmpty() && this->pieceSelected!=""
            && !this->game->getBoard().indexPosWater(pos.row,pos.column)){

        button->setText(QString::fromStdString(this->pieceSelected));
       // this->game.putPieceOnBoard(Piece(piece()),pos);
        this->game->placePieceOnBoard(this->pieceSelected,pos);

            updateBox();

        this->pieceSelected.clear();
endPlacementPiece();
    }
}



void GuiView::updateBox()
{
    QLayout *layout = ui->gridLayoutBox->layout();
    QLayoutItem* item=ui->gridLayoutBox->layout()->takeAt( this->placement ) ;

    if(this->change){
       layout=ui->gridLayoutBox2->layout();
       item= ui->gridLayoutBox2->layout()->takeAt( this->placement ) ;
    }
    if (layout  != NULL )
    {
        if (  item  != NULL )
        {
            delete item->widget();
            delete item;
        }
    }
}



void GuiView::endPlacementPiece(){


    if(this->game->getBox().getPiecesP1().size()==0){
        QMessageBox::about(this,"Placement End","Next player : place your soldiers");
        QPushButton *button=(QPushButton*) sender();
        button->setDisabled(false);
        //this->game.nextPlayer();
      //  boxPlayer2();
       // ui->buttonEndPlacement->setDisabled(true);

    }
    //else{
      //  QMessageBox::warning(this,"STOP","You need to place all your soldiers");
    //}
}

void GuiView::surrender(){
    QMessageBox::about(this,"Surend","you have surrended");

}

void GuiView::initWithFile(){
    //game->initWithFile();
    for (int i =0;i<10 ;i++ ) {
        for (int j =0;j<10 ;j++ ) {
            QPushButton *button = new QPushButton(this);

            ui->gridLayoutBoard->addWidget(button,i,j);
            ui->gridLayoutBoard->itemAtPosition(i,j)->widget()->setStyleSheet("border:2px solid green;");

            if(!game->getBoard().getSquareAt(i,j).isEmpty()&&game->getBoard().getSquareAt(i,j).isAccessible()){

                string  a= game->getBoard().getPieceAt(i,j).getSymbol();

                button->setText(QString::fromStdString(a));
            }


            if(game->getBoard().indexPosWater(i,j))   {
                button->setStyleSheet("background-color: BLUE");

            }

        }
    }


}

//void GuiView::setController(controllerGui *controller_){
//    this->controller=controller_;
//}

