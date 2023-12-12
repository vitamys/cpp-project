#include "gamefactory.h"
#include "BlinkerGame.h"
#include "SpaceshipGame.h"
#include "RandomGame.h"
#include "StaticGame.h"
#include "MethuselahGame.h"
#include "pattern.h"
using namespace std;
std::unique_ptr<GameOfLife> GameFactory::getGame(IGameOfLife *parent,const QString& name) {
    if(name=="blockButton" ||name=="beehiveButton" ||name=="loafButton"|| name=="boatButton"||name=="tubButton"){
        return std::unique_ptr<GameOfLife>(new StaticGame(parent,Patterns::patternByName(name), 10));

    }
    else if (name == "beaconButton" || name =="blinkerButton" || name == "toadButton") {
        return std::unique_ptr<GameOfLife>(new BlinkerGame(parent,Patterns::patternByName(name), 10));
    } else if (name == "gliderButton" || name =="lwssButton"|| name =="mwssButton") {
        return std::unique_ptr<GameOfLife>(new SpaceshipGame(parent,Patterns::patternByName(name), 10));
    } else if(name=="rpentominoButton" || name== "diehardButton" || name== "acornButton"){
        return std::unique_ptr<GameOfLife>(new MethuselahGame(parent,Patterns::patternByName(name), 10));
    }
    else if (name == "randomButton"){
        return std::unique_ptr<GameOfLife>(new RandomGame(parent, 10));
    }else{
        return std::unique_ptr<GameOfLife>(new RandomGame(parent, 10));
    }
}
