
#ifndef IDISPLAY_HPP
#define IDISPLAY_HPP

#include "SnakeGame.hpp"

class SnakeGame;

class IDisplay {
public:
	virtual ~IDisplay() = default;
	virtual void tick(void) = 0;
};

typedef IDisplay* (*st_create)(SnakeGame&);
typedef void (*st_destroy)(IDisplay*);

#endif
