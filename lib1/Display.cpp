
#include <iostream>
#include "../IDisplay.hpp"
#include "../SnakeGame.hpp"
#include "Display.hpp"

extern "C" {
    #include <curses.h>
    #include <unistd.h>
}

Display::Display(SnakeGame& s) : snakeref(s) {
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    timeout(1);
}

Display::~Display(void) {
    endwin();
}

void Display::tick(void) {
    clear();
    unsigned    x;
    unsigned    y;

    int ch;

    while ((ch = getch()) != -1)
    {
        if (ch == 112) snakeref.setKey(0);
        if (ch == 258) snakeref.setKey(4);
        if (ch == 259) snakeref.setKey(5);
        if (ch == 260) snakeref.setKey(6);
        if (ch == 261) snakeref.setKey(7);
        if (ch == 50) snakeref.setKey(1);
        if (ch == 51) snakeref.setKey(2);
        if (ch == 51) snakeref.setKey(3);
    }

    mvprintw(snakeref.getPy(), snakeref.getPx(), "o");
    mvprintw(snakeref.getAy(), snakeref.getAx(), "x");

    refresh();
    usleep(500000);
}

IDisplay* createLink(SnakeGame& s) {
    return new Display(s);
}

void destroyLink(IDisplay * g) {
    
}
