
#include <iostream>
#include "IDisplay.hpp"
#include "SnakeGame.hpp"
#include "Display.hpp"
#define GL_SILENCE_DEPRECATION

extern "C" {
    #include "tigr.h"
}

Display::Display(SnakeGame& s) : snakeref(s) {
    screen = tigrWindow((snakeref.width+2) * 10, (snakeref.height+5) * 10, "Hello", 0);
}

Display::~Display(void) {
    tigrFree(screen);
}

void Display::tick(void) {

    // input
    if (tigrKeyDown(screen, TK_LEFT)) snakeref.key = 6;
    if (tigrKeyDown(screen, TK_UP)) snakeref.key = 5;
    if (tigrKeyDown(screen, TK_RIGHT)) snakeref.key = 7;
    if (tigrKeyDown(screen, TK_DOWN)) snakeref.key = 4;
    if (tigrKeyDown(screen, '1')) snakeref.key = 1;
    if (tigrKeyDown(screen, '2')) snakeref.key = 2;
    if (tigrKeyDown(screen, '3')) snakeref.key = 3;

    // display
    tigrClear(screen, tigrRGB(0x00, 0x00, 0x00));
    
    for (int i=0; i < snakeref.width+2; i++){
        tigrPrint(screen, tfont, 0, (i)*10,
            tigrRGB(0xff, 0xff, 0xff), "#");
        tigrPrint(screen, tfont, (snakeref.height+1)*10, (i)*10,
            tigrRGB(0xff, 0xff, 0xff), "#");
    }
    for (int i=0; i < snakeref.height+2; i++){
        tigrPrint(screen, tfont, i*10, 0,
            tigrRGB(0xff, 0xff, 0xff), "#");
        tigrPrint(screen, tfont, i*10, (snakeref.width+1)*10,
            tigrRGB(0xff, 0xff, 0xff), "#");
    }

    for (int i=0; i < snakeref.trail; i++){
        tigrPrint(screen, tfont, (snakeref.traily[i]+1)*10, (snakeref.trailx[i]+1)*10,
            tigrRGB(0x00, 0x00, 0xff),
            i % 2 ? "o" : "+");
    }
    tigrPrint(screen, tfont, (snakeref.ay+1)*10, (snakeref.ax+1)*10,
        tigrRGB(0x00, 0xff, 0x00), "x");
    tigrPrint(screen, tfont, (snakeref.height+3)*10, 1*10, 
        tigrRGB(0xff, 0xff, 0xff), "Score: ");

    tigrUpdate(screen);
}

IDisplay* createLink(SnakeGame& s) {
    return new Display(s);
}

void destroyLink(IDisplay * g) {
    Display* current = (Display*) g;
    //tigrError(current->screen, "test");
    tigrFree(current->screen);
    (void)g;
}
