#include "mainwindow.h"
#include "ui_mainwindow.h"

using model::Token;

MainWindow::MainWindow(model::Game* game,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),game{game}
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayTokens()
{

  for(unsigned i=1;i<10;i++){
    resetColorQueueAtIndex(i);
    displayOneCaseWithQueue(i);
  }
}

void MainWindow::displayTabScore()
{
    ui->namePlayer1->setText(QString::fromStdString(game->getNamefirstPlayer()));
    ui->namePlayer2->setText(QString::fromStdString(game->getNameSecondPlayer()));
}

void MainWindow::displayScore()
{
    ui->scorePlayer1->display((int)game->getScoreFirstPlayer());
    ui->scorePlayer2->display((int)game->getScoreSecondPlayer());
}

void MainWindow::displayOneCaseWithQueue(unsigned nbOfTheCase)
{
    queue<Token>copy=game->getOneCaseOfboard(nbOfTheCase-1).getTokens();
    vector<Token>copyV2;
    while(!(copy.empty())){
        copyV2.push_back(copy.front());
        copy.pop();
    }
    if((!copyV2.empty())&&copyV2.back().isBlack()){
        pushButtonOnTheBoard(nbOfTheCase)->setStyleSheet("background-color: rgb(0,0,0);");

    }else if((!copyV2.empty())&&copyV2.back().isWhite()){

        pushButtonOnTheBoard(nbOfTheCase)->setStyleSheet("background-color: rgb(255,255,255);");

    }else if((!copyV2.empty())&&copyV2.back().isRed()){
        pushButtonOnTheBoard(nbOfTheCase)->setStyleSheet("background-color: rgb(255,0,0);");

    }else{
        pushButtonOnTheBoard(nbOfTheCase)->setStyleSheet("background-color: rgb(181,181,181);");
    }

   vector<QPushButton*>file=fileToFill(nbOfTheCase);

   for(unsigned i=0;i<copyV2.size();i++){
        if(copyV2.at(i).isWhite()){
            file.at(i)->setStyleSheet("background-color: rgb(255,255,255);");
        }else if(copyV2.at(i).isRed()){
             file.at(i)->setStyleSheet("background-color: rgb(255,0,0);");
        }else if(copyV2.at(i).isBlack()){
             file.at(i)->setStyleSheet("background-color: rgb(0,0,0);");
        }else{
            file.at(i)->setStyleSheet("background-color: rgb(181,181,181);");
        }
   }

}

void MainWindow::disconnectAllBtnOfBoard()
{
    for(unsigned i=1;i<10;i++){
        disconnect(pushButtonOnTheBoard(i),nullptr,this,nullptr);
    }


}

void MainWindow::resetColorQueueAtIndex(unsigned i)
{
        vector<QPushButton*>btns= fileToFill(i);
        for(auto btn:btns){
            btn->setStyleSheet("background-color: rgb(181,181,181);");
        }

}

void MainWindow::displayMessageEndRound()
{
    string msg;
    unsigned ptP1=game->getTmpScoreFirstPlayer();
    unsigned ptP2=game->getTmpScoreSecondPlayer();
    if(ptP1>ptP2){
        msg= game->getNamefirstPlayer() + " a gagne le round avec " +
             std::to_string(ptP1)+" contre "+std::to_string(ptP2)+
             ". il gagne donc "+std::to_string(ptP1-ptP2)+" point(s). \n";
    }else if(ptP2>ptP1){
        msg= game->getNameSecondPlayer() + " a gagne le round avec " +
             std::to_string(ptP2)+" contre "+std::to_string(ptP1)+
             ". il gagne donc "+std::to_string(ptP2-ptP1)+" point(s). \n";
    }else{
        msg= "il n'y a pas de vainqueur pour ce round .La manche sera rejouee";
    }
    ui->labelMessageGen->setText(QString::fromStdString(msg));
}


void MainWindow::moveGui()
{

   QPushButton* pbtn= qobject_cast<QPushButton*>(sender());
   QString index= pbtn->text();
   int idx= index.toInt()-1;
   disconnectAllBtnOfBoard();
   game->moveGui(idx);
}


void MainWindow::afterError()
{
    game->setGameInProcess();
    ui->pushButtonNext->setText("");
    disconnect(ui->pushButtonNext,nullptr,this,nullptr);
    qDebug()<<"sa vient la1";
    game->notify();
}


void MainWindow::next()
{
    ui->pushButtonNext->setText("");
    disconnect(ui->pushButtonNext,nullptr,this,nullptr);
}

void MainWindow::oui()
{
    disconnect(ui->pushButtonNext,nullptr,this,nullptr);
    disconnect(ui->pushButtonAnswerNo,nullptr,this,nullptr);
}

void MainWindow::no()
{
    game->nextPlayer();
    disconnect(ui->pushButtonNext,nullptr,this,nullptr);
    disconnect(ui->pushButtonAnswerNo,nullptr,this,nullptr);

}


void MainWindow::toContinue(){
    ui->pushButtonNext->setText("cliquez ici pour continuer");
    connect(ui->pushButtonNext,SIGNAL(clicked()),this,SLOT(next()));

}

void MainWindow::winnerChoseFirstPlay()
{
    string winner="";
    string msg="";
   if(game->getTmpScoreFirstPlayer()>game->getTmpScoreSecondPlayer()){
       winner= game->getNamefirstPlayer();
       msg= winner+",voulez-vous commencer la prochaine manche?";
       ui->labelMessageGen->setText(QString::fromStdString(msg));

       connect(ui->pushButtonNext,SIGNAL(clicked()),this,SLOT(oui()));
       connect(ui->pushButtonAnswerNo,SIGNAL(clicked()),this,SLOT(no()));




   }else if(game->getTmpScoreFirstPlayer()<game->getTmpScoreSecondPlayer()){
       winner=game->getNameSecondPlayer();
       msg= winner+",voulez-vous commencer la prochaine manche?";
       ui->labelMessageGen->setText(QString::fromStdString(msg));

       connect(ui->pushButtonNext,SIGNAL(clicked()),this,SLOT(oui()));
       connect(ui->pushButtonAnswerNo,SIGNAL(clicked()),this,SLOT(no()));


   }else{
       ui->labelMessageGen->setText("Cliquez pour rejouer la manche");
       connect(ui->pushButtonNext,SIGNAL(clicked()),this,SLOT(next()));
   }

}

void MainWindow::setSignals()
{
    for(unsigned i=1;i<10;i++){
        if(!(game->getOneCaseOfboard(i-1).isEmpty())){
            connect(pushButtonOnTheBoard(i),SIGNAL(clicked()),this,SLOT(moveGui()));
        }
    }

}



void MainWindow::displayMessageInProcess()
{
    string msg = ""+ game->getCurrentPlayer().getName()+" ,"+"à toi de jouer";
    QString tmp= QString::fromStdString(msg);
    ui->labelMessageGen->setText(tmp);
}





QPushButton* MainWindow::pushButtonOnTheBoard(unsigned index)
{
    switch(index){
    case 1:
        return ui->btn_case1;       
        break;
    case 2:
        return ui->btn_case2;        
        break;
    case 3:
        return ui->btn_case3;        
        break;
    case 4:
        return ui->btn_case4;        
        break;
    case 5:
        return ui->btn_case5;        
        break;
    case 6:
        return ui->btn_case6;
        break;
    case 7:
        return ui->btn_case7;       
        break;
    case 8:
        return ui->btn_case8;        
        break;
    case 9:
        return ui->btn_case9;
        break;
    default:
        return nullptr;
    }
}

vector<QPushButton*> MainWindow::fileToFill(unsigned index)
{
    switch(index){
    case 1:
        return{ui->pbtn1_1,ui->pbtn1_2,ui->pbtn1_3,ui->pbtn1_4,ui->pbtn1_5,ui->pbtn1_6,ui->pbtn1_7,ui->pbtn1_8,ui->pbtn1_9};
        break;
    case 2:
        return {ui->pbtn2_1,ui->pbtn2_2,ui->pbtn2_3,ui->pbtn2_4,ui->pbtn2_5,ui->pbtn2_6,ui->pbtn2_7,ui->pbtn2_8,ui->pbtn2_9};
        break;
    case 3:
        return {ui->pbtn3_1,ui->pbtn3_2,ui->pbtn3_3,ui->pbtn3_4,ui->pbtn3_5,ui->pbtn3_6,ui->pbtn3_7,ui->pbtn3_8,ui->pbtn3_9};
        break;
    case 4:
        return{ui->pbtn4_1,ui->pbtn4_2,ui->pbtn4_3,ui->pbtn4_4,ui->pbtn4_5,ui->pbtn4_6,ui->pbtn4_7,ui->pbtn4_8,ui->pbtn4_9};
        break;
    case 5:
        return{ui->pbtn5_1,ui->pbtn5_2,ui->pbtn5_3,ui->pbtn5_4,ui->pbtn5_5,ui->pbtn5_6,ui->pbtn5_7,ui->pbtn5_8,ui->pbtn5_9};
        break;
    case 6:
        return{ui->pbtn6_1,ui->pbtn6_2,ui->pbtn6_3,ui->pbtn6_4,ui->pbtn6_5,ui->pbtn6_6,ui->pbtn6_7,ui->pbtn6_8,ui->pbtn6_9};
        break;
    case 7:
        return{ui->pbtn7_1,ui->pbtn7_2,ui->pbtn7_3,ui->pbtn7_4,ui->pbtn7_5,ui->pbtn7_6,ui->pbtn7_7,ui->pbtn7_8,ui->pbtn7_9};
        break;
    case 8:
        return{ui->pbtn8_1,ui->pbtn8_2,ui->pbtn8_3,ui->pbtn8_4,ui->pbtn8_5,ui->pbtn8_6,ui->pbtn8_7,ui->pbtn8_8,ui->pbtn8_9};
        break;
    case 9:
        return{ui->pbtn9_1,ui->pbtn9_2,ui->pbtn9_3,ui->pbtn9_4,ui->pbtn9_5,ui->pbtn9_6,ui->pbtn9_7,ui->pbtn9_8,ui->pbtn9_9};
        break;
    default:
        return{};
    }

}

void MainWindow::nextRound()
{
  winnerChoseFirstPlay();
  game->setGameInProcess();
  game->notify();
}

void MainWindow::nextAfterError()
{
 connect(ui->pushButtonNext,SIGNAL(clicked()),this,SLOT(afterError()));
}


void MainWindow::displayErrorMessage(){
    string messagerror = game->getCurrentPlayer().getName()+" , "+game->getMessageError()+"\n, Veuillez jouer correctement";
    QString msgerror= QString::fromStdString(messagerror);
    ui->labelMessageGen->setText(msgerror);
    ui->pushButtonNext->setText("Cliquer ici pour continuer");
}


