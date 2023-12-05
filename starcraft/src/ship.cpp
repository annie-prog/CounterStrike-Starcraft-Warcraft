#include <utility>

#include "ship.h"
#include "constants.h"

Ship::Ship(std::string name, int damage, int healthPoints) : m_name(std::move(name)), m_damage(damage),
                                                             m_healthPoints(healthPoints) {}

std::string Ship::returnStatsString() {
    std::string statsString = std::to_string(m_healthPoints) + MessagesTexts::HEALTH_LEFT_STRING;
    return statsString;
}