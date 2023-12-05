#ifndef COUNTER_STRKE_0_1_GAME_H
#define COUNTER_STRKE_0_1_GAME_H

#include <vector>
#include "Player.h"
#include "Defines.h"
#include <memory>
#include <iostream>

class Game {
public:
    Game() = default;

    bool playGame();

private:
    std::vector<std::unique_ptr<Player>> m_players;

    bool generatePlayers(std::istream &stream);

    bool buyWeaponsPhase();

    void startBattle();

};

#endif //COUNTER_STRKE_0_1_GAME_H
