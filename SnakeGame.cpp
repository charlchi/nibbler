
#include "SnakeGame.hpp"

SnakeGame::loadLib(std::string lib) {

    // load the library
    dl_handle = dlopen(lib, RTLD_LAZY);
    // dl_handle = dlopen("./hello.so", RTLD_LAZY);
    if (!dl_handle) {
        std::cerr << "Cannot open library: " << dlerror() << '\n';
        return 1;
    }
    // reset errors
    dlerror();
    
    // load the creation and destruction symbols
    create = (st_create) dlsym(dl_handle, "displayCreate");
    destroy = (st_destroy) dlsym(dl_handle, "displayDestroy");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Cannot load symbol 'hello': " << dlsym_error << '\n';
        dlclose(dl_handle);
        return 1;
    }
    display = create(this);
}

SnakeGame::closeLib() {
    // free old display resources
    destroy(display);
    // unlink and close lib
    dlclose(dl_handle);
}

SnakeGame::switchLib(std::string lib) {
    closeLib();
    loadLib(lib);
}

SnakeGame::SnakeGame(int argc, char const *argv[]) {
    
    loadLib(lib1);

    while (1) {

         // display and get inital key input
        display->tick();

        // handle switching to new library, close previous here
        if (someKey1) {
            switchLib(lib1);
        } else if (someKey2) {
            switchLib(lib2);
        } else if (someKey3) {
            switchLib(lib3);
        }

        // handle input and update game here
        

    }
    closeLib();
}
