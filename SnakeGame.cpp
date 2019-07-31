
#include "SnakeGame.hpp"

SnakeGame::SnakeGame(int argc, char const *argv[]) {
    

    // load the library
    dl_handle = dlopen(lib1, RTLD_LAZY);
    // dl_handle = dlopen("./hello.so", RTLD_LAZY);
    if (!dl_handle) {
        std::cerr << "Cannot open library: " << dlerror() << '\n';
        return 1;
    }
    // reset errors
    dlerror();
    
    // load the symbol from the library and tie to this object
    create = (st_create) dlsym(dl_handle, "displayCreate");
    destroy = (st_destroy) dlsym(dl_handle, "displayDestroy");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Cannot load symbol 'hello': " << dlsym_error << '\n';
        dlclose(dl_handle);
        return 1;
    }
    // use it to do the calculation
    std::cout << "Calling hello...\n";
    display = create(this);

    // initialize game map here


    while (1) {
        display->tick(); // display and get inital key input
        
        // handle switching to new library, close previous here

    }
    // close the library
    std::cout << "Closing library...\n";
    dlclose(dl_handle);
}
