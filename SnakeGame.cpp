
#include "SnakeGame.hpp"
#include <iostream>
#include <dlfcn.h>
#include <unistd.h>
#include <cstdlib>

void SnakeGame::loadLib(std::string lib) {

    // load the library
    std::cout << "Attempting load \"" << lib << "\"\n";
    dl_handle = dlopen(lib.c_str(), RTLD_LAZY);
    // dl_handle = dlopen("./hello.so", RTLD_LAZY);
    if (!dl_handle) {
        std::cerr << "Cannot open library: " << dlerror() << '\n';
    }
    // reset errors
    dlerror();
    
    // load the creation and destruction symbols
    create = (st_create) dlsym(dl_handle, "createLink");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Cannot load symbol: " << dlsym_error << '\n';
        dlclose(dl_handle);
    }
    destroy = (st_destroy) dlsym(dl_handle, "destroyLink");
    dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Cannot load symbol: " << dlsym_error << '\n';
        dlclose(dl_handle);
    }
    display = create(*this);
}

void SnakeGame::closeLib() {
    // free old display resources
    destroy(display);
    // unlink and close lib
    dlclose(dl_handle);
}

void SnakeGame::switchLib(std::string lib) {
    closeLib();
    loadLib(lib);
}

SnakeGame::SnakeGame(int argc, char const *argv[]) {
    
    (void)argc;
    (void)argv;
    loadLib("lib1/lib.so");
    //loadLib(lib1);

    trailx = new int[1000];
    traily = new int[1000];
    trail = 4;
    width = 20;
    height = 20;
    px = 5;
    py = 5;
    ax = 2;
    ay = 2;
    dir = 0;

    int running = 1;
    while (running) {

         // display and get inital key input
        display->tick();

        // handle input and update game here

        // handle switching to new library, close previous here
        if (key == 1)      switchLib("lib1/lib.so");
        else if (key == 2) switchLib("lib2/lib.so");
        else if (key == 3) switchLib("lib3/lib.so");

        // changing direction
        if (key == 4 && dir != 1)      dir = 0;
        else if (key == 5 && dir != 0) dir = 1;
        else if (key == 6 && dir != 3) dir = 2;
        else if (key == 7 && dir != 2) dir = 3;
        if (dir == 0)      { py++;}
        else if (dir == 1) { py--;}
        else if (dir == 2) { px--;}
        else if (dir == 3) { px++;}

        // game over, exit
        if (key == 0) running = 0;
        if (px < 0 || px >= width) running = 0;
        if (py < 0 || py >= height) running = 0;

        // trail and apple pickup
        for (int i=trail; i>0; i--) {
            trailx[i] = trailx[i - 1];
            traily[i] = traily[i - 1];
            if (trailx[i] == ax && traily[i] == ay) {
                ax = rand() % width;
                ay = rand() % height;
                trail++;
            }
            if (trailx[i] == px && traily[i] == py) {
                running = 0;
            }

        }
        trailx[0] = px;
        traily[0] = py;

        usleep(1000000/10);
    }
    closeLib();
}

void SnakeGame::setKey(int kk) {
    key = kk;
}


int SnakeGame::getPy(void) {
    return py;
}


int SnakeGame::getPx(void) {
    return px;
}


int SnakeGame::getAy(void) {
    return ay;
}


int SnakeGame::getAx(void) {
    return ax;
}
