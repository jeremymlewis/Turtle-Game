#include "Game.h"

#include <iostream>



int main()
{
    Game game;

    while (game.isRunning())
    {

        game.update();

        game.render();
    }

    return 0;
}