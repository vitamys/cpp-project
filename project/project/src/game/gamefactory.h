#ifndef GAMEFACTORY_H
#define GAMEFACTORY_H

#include "gameOfLife.h"
#include <memory>
#include <QString>
using namespace std;
class GameFactory
{
public:
    GameFactory(){}
    std::unique_ptr<GameOfLife> getGame(IGameOfLife *parent,const std::vector<std::vector<char>>& initialPattern, const QString& name);
};

#endif // GAMEFACTORY_H
