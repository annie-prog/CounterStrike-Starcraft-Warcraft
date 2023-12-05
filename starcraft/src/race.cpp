#include <utility>
#include <iostream>

#include "race.h"
#include "constants.h"

Race::Race(std::string name) : m_name(std::move(name)) {}

void Race::generateFleet(const std::string &fleetComposition) {
    m_fleet.reserve(fleetComposition.size());
    for (auto const shipFlag:fleetComposition) {
        m_shipsBuilderMapper[shipFlag]();
    }
}

void Race::printMsgWhenEnemyKilled(Ship &killer, size_t index, size_t killedEnemyID) {
    std::cout << killer.GetName() << MessagesTexts::WITH_ID_STRING << index << MessagesTexts::KILLED_ENEMY_SHIP_STRING << killedEnemyID
              << std::endl;
}

