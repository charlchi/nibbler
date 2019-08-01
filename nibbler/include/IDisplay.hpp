
#ifndef IDISPLAY_HPP
#define IDISPLAY_HPP

#include "SnakeGame.hpp"

class IDisplay
{
public:
    t_action        glib_action;

    virtual ~IDisplay(void) = default;
    virtual void tick(void) = 0;
};

#endif //  IDISPLAY_HPP