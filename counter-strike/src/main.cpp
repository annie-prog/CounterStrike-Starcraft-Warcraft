#include <iostream>
#include "pistols/Pistol.h"
#include "Game.h"

int main() {
    Game testGame;
    if(!testGame.playGame())
    {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
