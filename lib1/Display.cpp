
#include <iostream>
#include "IDisplay.hpp"
#include "SnakeGame.hpp"
#include "Display.hpp"

extern "C" {
    #include <curses.h>
}

Display::Display(SnakeGame& s) : snakeref(s) {
    setlocale(LC_ALL, "");
    initscr();
    cbreak();
    curs_set(0);
    keypad(stdscr, TRUE);
    noecho();
    timeout(1);
    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_GREEN);
    init_pair(2, COLOR_CYAN, COLOR_BLUE);
    init_pair(3, COLOR_BLACK, COLOR_WHITE);
    init_pair(4, COLOR_RED, COLOR_MAGENTA);
}

Display::~Display(void) {
    endwin();
}

void Display::tick(void) {
    int ch;
    
    clear();
    while ((ch = getch()) != -1)
    {
        if (ch == 112) snakeref.key = (0);
        if (ch == 258) snakeref.key = (4);
        if (ch == 259) snakeref.key = (5);
        if (ch == 260) snakeref.key = (6);
        if (ch == 261) snakeref.key = (7);
        if (ch == '1') snakeref.key = (1);
        if (ch == '2') snakeref.key = (2);
        if (ch == '3') snakeref.key = (3);
    }

    attron(A_BOLD);

    for (int i=0; i < snakeref.width+2; i++){
        mvprintw(0, (i)*2, "#");
        mvprintw(snakeref.height+1, (i)*2, "#");
    }
    for (int i=0; i < snakeref.height+2; i++){
        mvprintw(i, 0, "#");
        mvprintw(i, (snakeref.width+1)*2, "#");
    }

    attron(COLOR_PAIR(2));
    for (int i=0; i < snakeref.trail; i++){
        mvprintw(snakeref.traily[i]+1, (snakeref.trailx[i]+1)*2,
            i % 2 ? "o" : "+");
    }
    attroff(COLOR_PAIR(2));

    attron(COLOR_PAIR(1));

    mvprintw(snakeref.ay+1, (snakeref.ax+1)*2, "x");
    
    attroff(COLOR_PAIR(1));

    mvprintw(snakeref.height + 3, 1, "Score: %d", snakeref.trail - 4);

    attroff(A_BOLD);

    refresh();
}

IDisplay* createLink(SnakeGame& s) {
    return new Display(s);
}

void destroyLink(IDisplay * g) {
    endwin();
    (void)g;
}
