#include <iostream>
#include <cctype>
#include "game.h"
#include "protoss.h"
#include "terran.h"

std::string toUpperCase(const std::string& str) {
    std::string result;
    for (char c : str) {
        result += static_cast<char>(std::toupper(c));
    }
    return result;
}

Game::Game() {
    m_races.emplace_back(new Terran);
    m_races.emplace_back(new Protoss);
}

int Game::playGame() {
    printMenu();
    generateRacesFleets();
    startBattle();
    return 0;
}

void Game::printMenu() {
    std::cout << MessagesTexts::WELCOME_MESSAGE << std::endl;

}

void Game::printLastAttackedShipStats(Race &defendingRace, size_t lastShipInFleetId) {
    std::cout << MessagesTexts::LAST_STRING << defendingRace.GetName() << MessagesTexts::AIRSHIP_ID_STRING << lastShipInFleetId
              << MessagesTexts::HAS_STRING << defendingRace.m_fleet[lastShipInFleetId]->returnStatsString();
}

void Game::generateRacesFleets() {
    for (auto &race: m_races) {
        std::string currentRaceComposition;
        std::cout << MessagesTexts::ENTER_COMPOSITION_STRING << race->GetName() << std::endl;
        std::cin >> currentRaceComposition;
        race->generateFleet(currentRaceComposition);
    }
}

void Game::printWinMessage(std::unique_ptr<Race> &winningRace) {
    std::string winningRaceCapitalLetters = toUpperCase(winningRace->GetName());
    std::cout << winningRaceCapitalLetters << MessagesTexts::HAS_WON_STRING << std::endl;

}

int Game::startBattle() {
    while (true) {
        for (size_t attackingRaceId = 0; attackingRaceId < m_races.size(); attackingRaceId++) {
            auto &attackingRace = m_races[attackingRaceId];
            for (size_t defendingRaceId = 0; defendingRaceId < m_races.size(); defendingRaceId++) {

                if (defendingRaceId == attackingRaceId) {
                    continue;
                }

                auto &defendingFleet = m_races[defendingRaceId]->m_fleet;
                attackingRace->attackEnemy(defendingFleet);

                if (defendingFleet.empty()) {
                    printWinMessage(attackingRace);
                    return 0;
                }
                printLastAttackedShipStats(*m_races[defendingRaceId], defendingFleet.size() - 1);
            }
        }
    }
}