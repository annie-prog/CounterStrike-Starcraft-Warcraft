#include "pistols/DesertEaglePistol.h"
#include "Player.h"

DesertEaglePistol::DesertEaglePistol(PistolVitalData vitalData) : Pistol(vitalData) {};

void DesertEaglePistol::damageApplier(std::unique_ptr<Player> &defendingPlayer) {
    if (defendingPlayer->getVitalData().armor > 0) {
        actionsWhenEnemyHaveArmor(defendingPlayer, DesertEagleInfo::damageToArmorPercentage,
                                  DesertEagleInfo::damageToHealthPercentage);
    } 
    else {
        defendingPlayer->getVitalData().health -= m_pistolVitalData.damagePerRound;
    }
    m_pistolVitalData.currClipBullets--;

    printMessageAfterShooting(defendingPlayer);
}
