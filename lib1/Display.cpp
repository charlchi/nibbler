
# include <iostream>
#include "Display.hpp"
#include "SDrawer.hpp"

extern "C" {
    #include <curses.h>
    #include <unistd.h>
}

Display::Display(const Snake & s) : _snake(s)
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
        if (ch == 112)
            glib_action = PAUSE;
        if (ch == 258)
            glib_action = DOWN;
        if (ch == 259)
            glib_action = UP;
        if (ch == 260)
            glib_action = RIGHT;
        if (ch == 261)
            glib_action = LEFT;
        if (ch == 50)
            glib_action = LIB2;
        if (ch == 51)
            glib_action = LIB3;
    }


    y = 0;
    while (y < _snake.level->height)
    {
        printw("   ");
        x = 0;
        while (x < _snake.level->width)
        {
            switch (_snake.level->map[y][x])
            {
                case BLOCK_NONE:
                    printw(" ");
                    break;
                case BLOCK_WALL:
                    printw("/");
                    break;
                case BLOCK_NOM:
                    printw("x");
                    break;
                case BLOCK_HEAD:
                    printw("O");
                    break;
                default:
                    printw("o");
            }
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
