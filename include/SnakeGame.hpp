
#ifndef SNAKE_GAME_HPP
#define SNAKE_GAME_HPP

#include <string>
#include <iostream>
#include <dlfcn.h>
#include "IDisplay.hpp"

class IDisplay;
class SnakeGame;
typedef IDisplay* (*st_create)(SnakeGame&);
typedef void (*st_destroy)(IDisplay*);

class SnakeGame
{
public:
	int width;
	int height;
	int px;
	int py;
	int ax;
	int ay;
	int dir;
	int key;
	int* trailx;
	int* traily;
	int trail;

    std::string lib1;
    std::string lib2;
    std::string lib3;

    void* dl_handle;
	st_create create;
	st_destroy destroy;

	IDisplay* display;

	void loadLib(std::string);
	void switchLib(std::string);
	void closeLib();
	void setKey(int);
	int getPy(void);
	int getPx(void);
	int getAy(void);
	int getAx(void);
    SnakeGame(void);
    SnakeGame(SnakeGame&);
    SnakeGame &  operator=(SnakeGame&);
    SnakeGame(int argc, char const *argv[]);
    ~SnakeGame();
    
};

#endif // SNAKE_GAME_HPP
