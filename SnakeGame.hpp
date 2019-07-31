
#ifndef SNAKE_GAME_HPP
#define SNAKE_GAME_HPP

#include <iostream>
#include <dlfcn.h>

class SnakeGame
{
	int width;
	int height;
	int** map;
	int dir;

    std::string lib1;
    std::string lib2;
    std::string lib3;

    void* dl_handle;
	st_create create;
	st_destroy destroy;

	Display* display;

public:
    SnakeGame(void);
    SnakeGame(SnakeGame const &);
    SnakeGame &  operator=(SnakeGame const &);
    SnakeGame(int argc, char const *argv[]);
    ~SnakeGame();
    
};

#endif // SNAKE_GAME_HPP
