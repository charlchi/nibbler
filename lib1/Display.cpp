
#include <iostream>
#include "Display.hpp"

extern "C" {
    #include <curses.h>
    #include <unistd.h>
}

Display::Display(const Snake & s) : snakeref(s)
{
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    timeout(1);
}

Display::~Display(void)
{
    endwin();
}

void Display::tick(void)
{
    clear();
    unsigned    x;
    unsigned    y;

    int ch;

    while ((ch = getch()) != -1)
    {
        if (ch == 112) key = 0;
        if (ch == 258) key = 4;
        if (ch == 259) key = 5;
        if (ch == 260) key = 6;
        if (ch == 261) key = 7;
        if (ch == 50) key = 1;
        if (ch == 51) key = 2;
        if (ch == 51) key = 3;
    }


    y = 0;
    while (y < snakeref->getHeight())
    {
        printw("   ");
        x = 0;
        while (x < snakeref->getWidth())
        {
            // print map
            printw(" ");
            x++;
        }

        printw("\n");
        y++;
    }

    refresh();
    usleep(50000);
}

IDisplay* displayCreate(const Snake & s)
{
    return new Display(s);
}

void displayDestroy(IDisplay * g)
{
    delete w;
}
