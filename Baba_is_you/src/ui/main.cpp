#include <iostream>


////main of console mode game
//#include "controller.h"
//#include "view.h"


//int main()
//{
//    std::unique_ptr<view::View> view = std::make_unique<view::View>();
//    Controller controller(std::move(view));
//    controller.playGame();
//}


/// main of gui mode game


#include <QApplication>
#include "controllergui.h"
#include "mainwindow.h"

int main(int argc,char*argv[]){

    QApplication application(argc,argv);
    model::Game game;
    ControllerGui controllergui(game);
    std::unique_ptr<MainWindow> myWindow= std::make_unique<MainWindow>(&controllergui);
    myWindow->show();
    controllergui.setView(std::move(myWindow));
    controllergui.launchGame();
    return application.exec();;

}
