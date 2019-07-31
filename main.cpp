
#include <iostream>
#include <dlfcn.h>

int main(int argc, char const *argv[])
{

    SnakeGame();
    return 0;
}



class SnakeGame
{
    void* dl_handle;
public:
    SnakeGame(std::string lib);
    ~SnakeGame();
    
};

SnakeGame::SnakeGame(std::string lib) {
    dl_handle = dlopen(lib, RTLD_LAZY);
    // dl_handle = dlopen("./hello.so", RTLD_LAZY);
    if (!dl_handle) {
        std::cerr << "Cannot open library: " << dlerror() << '\n';
        return 1;
    }
    // reset errors
    dlerror();
    
    // load the symbol
    st_create create = (st_create) dlsym(dl_handle, "windowCreate");
    st_destroy destroy = (st_destroy) dlsym(dl_handle, "windowDestroy");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Cannot load symbol 'hello': " << dlsym_error << '\n';
        dlclose(dl_handle);
        return 1;
    }
    // use it to do the calculation
    std::cout << "Calling hello...\n";
    windowCreate(this);
    // close the library
    std::cout << "Closing library...\n";
    dlclose(dl_handle);
}
