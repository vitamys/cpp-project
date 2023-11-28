#include "gamefactory.h"
#include "BlinkerGame.h"
#include "pattern.h"
using namespace std;
std::unique_ptr<GameOfLife> GameFactory::getGame(IGameOfLife *parent,const std::vector<std::vector<char>>& initialPattern, const QString& name) {
    if (name == "beaconButton") {
        return std::unique_ptr<GameOfLife>(new BlinkerGame(parent,Patterns::patternByName(name), 10));
    } else if (name == "gliderButton") {
        return std::unique_ptr<GameOfLife>(new BlinkerGame(parent,Patterns::patternByName(name), 10));
    } else {
        // Handle other patterns or return a default pattern

        return std::unique_ptr<GameOfLife>(new BlinkerGame(parent,Patterns::patternByName(name), 10));
    }
}
