#ifndef IGAMEOFLIFE_H
#define IGAMEOFLIFE_H

#include <vector>

class IGameOfLife
{
public:
    IGameOfLife(){}
    virtual ~IGameOfLife(){}
    virtual void setData(std::vector<std::vector<char>> grid) = 0;
    virtual void enableButtons(int qudrant)=0;
};

#endif // IGAMEOFLIFE_H
