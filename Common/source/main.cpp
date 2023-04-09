#include "game.h"


int main() 
{
    try
    {
        Game game;
        
        if (game.Start())
            throw new std::exception("something was wrong");

        return 0;
    }
    catch(std::exception const & ex) 
    {
        return 1;
    }
}