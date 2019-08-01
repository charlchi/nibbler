
#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "IDisplay.hpp"
#include "tigr.h"

class Display : public IDisplay
{
    SnakeGame& snakeref;
public:
    Tigr *screen;
    Display(SnakeGame& s);
    Display(void);
    Display(Display const &);
    Display &  operator=(Display const &);
    ~Display(void);

    void tick(void);
};

extern "C" IDisplay* createLink(SnakeGame &);
extern "C" void destroyLink(IDisplay *);

#endif

