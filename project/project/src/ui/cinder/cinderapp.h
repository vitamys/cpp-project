#ifndef CINDERAPP_H
#define CINDERAPP_H
//#include "cinder/app/AppQt.h"
#include "gameOfLife.h"


class CinderApp : /*public cinder::app::AppQt*/
{
public:
    CinderApp();
//    void setup();
//    void update();
//    void draw();

private:
    GameOfLife mGameOfLife;
    const int mMaxGenerations = 50;
};

#endif // CINDERAPP_H
