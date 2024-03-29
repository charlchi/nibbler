
#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "IDisplay.hpp"

class Display : public IDisplay
{
    SnakeGame& snakeref;

public:
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

