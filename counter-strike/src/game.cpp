#include "Game.h"

bool Game::generatePlayers(std::istream &stream) {
    PlayerVitalData vitalData;
    for (size_t i = 0; i < PLAYERS_COUNT; i++) {
        if(!(stream >> vitalData.health >> vitalData.armor))
        {
            std::cout << "Player data is invalid!" << std::endl;
            return false;
        }
        if(!(Player::isPlayerVitalDataValid(vitalData)))
        {
            return false;
        }

        stream.ignore();
        m_players.emplace_back(std::make_unique<Player>(vitalData));
    }
    return true;
}

bool Game::buyWeaponsPhase() {
    for (auto &player: m_players) {
        if(!(player->buyPistol(std::cin)))
        {
            return false;
        }
    }
    return true;
}

void Game::startBattle() {
    /*
        the logic behing this method is made like this, because if we add more players, we don't need to change much of the code.
    */
    while (true) {
        for (size_t attackingPlayerId = 0; attackingPlayerId < m_players.size(); attackingPlayerId++) {
            auto &attackingPlayer = m_players[attackingPlayerId];
            std::cout << "PlayerID " << attackingPlayerId << " turn:" << std::endl;
            for (size_t defendingPlayerId = 0; defendingPlayerId < m_players.size(); defendingPlayerId++) {
                if (attackingPlayerId == defendingPlayerId) {
                    continue;
                }
                auto &defendingPlayer = m_players[defendingPlayerId];

                if (attackingPlayer->getPistol()->fire(defendingPlayer)) {
                    std::cout << "Player with ID: " << attackingPlayerId << " wins!" << std::endl;
                    return;
                }
            }
        }
    }
}

bool Game::playGame() {
    if(!generatePlayers(std::cin))
    {
        return false;
    }
    if(!buyWeaponsPhase())
    {
        return false;
    }
    startBattle();
    return true;
}

