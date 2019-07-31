
#ifndef DISPLAY_HPP
#define DISPLAY_HPP

# include <SFML/Display.hpp>
# include "IDisplay.hpp"


typedef IDisplay* (*st_create)(const Snake&);
typedef void (*st_destroy)(IDisplay*);

class Display : public IDisplay
{
    const Snake &       _snake;

    Display(void);
    Display(Display const &);
    Display &  operator=(Display const &);
public:
    Display(const Snake &);
    ~Display(void);

    void    update(void);
};

extern "C" IDisplay* windowCreate(const Snake &);
extern "C" void windowDestroy(IDisplay *);

#endif

