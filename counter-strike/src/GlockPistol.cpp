#include "pistols/DesertEaglePistol.h"
#include "Player.h"

GlockPistol::GlockPistol(PistolVitalData vitalData) : Pistol(vitalData) {}

void GlockPistol::damageApplier(std::unique_ptr<Player> &defendingPlayer) {
    for (size_t shotsFired = 1; shotsFired <= GlockInfo::numberOfBulletsToFireAtOneTime; shotsFired++) {

        if (defendingPlayer->getVitalData().armor > 0) {
            actionsWhenEnemyHaveArmor(defendingPlayer, GlockInfo::damageToArmorPercentage, GlockInfo::damageToHealthPercentage);
        } 
        else {
            defendingPlayer->getVitalData().health -= m_pistolVitalData.damagePerRound;
        }

        m_pistolVitalData.currClipBullets--;
        printMessageAfterShooting(defendingPlayer);

        if (isTargetDeath(defendingPlayer)) {
            break;
        }
        if (isClipEmpty() && shotsFired != GlockInfo::numberOfBulletsToFireAtOneTime) {
            reload();
            break;
        }
    }
}