
#ifndef DISPLAY_HPP
#define DISPLAY_HPP

# include <SFML/Display.hpp>
# include "IDisplay.hpp"

// put these in IDisplay
typedef IDisplay* (*st_create)(const Snake&);
typedef void (*st_destroy)(IDisplay*);

class Display : public IDisplay
{
    const Snake* snakeref;

public:
    Display(void);
    Display(Display const &);
    Display &  operator=(Display const &);
    Display(const Snake &);
    ~Display(void);

    void    tick(void);
};

extern "C" IDisplay* displayCreate(const Snake &);
extern "C" void displayDestroy(IDisplay *);

#endif

