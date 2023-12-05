#include "pistols/Pistol.h"
#include "Player.h"
#include <iostream>

Pistol::Pistol(PistolVitalData &vitalData) : m_pistolVitalData(vitalData) {}

bool Pistol::fire(std::unique_ptr<Player> &defendingPlayer) {
    if (isClipEmpty()) {
        reload();
        return false;
    }
    damageApplier(defendingPlayer);
    std::cout << std::endl;
    if (isTargetDeath(defendingPlayer)) {
        return true;
    }
    return false;
}

void Pistol::reload() {
    if (m_isAmmoEmpty) {
        printNoAmmoMessage();
        std::cout << '\n';
        return;
    }
    std::cout << "Reloading..." << std::endl;
    if (m_pistolVitalData.remainingAmmo < m_pistolVitalData.clipSize) {
        actionsWhenNotEnoughAmmoToFillClip();
        printAfterReloadMessage();
        std::cout << '\n';
        return;
    }

    m_pistolVitalData.currClipBullets = m_pistolVitalData.clipSize;
    m_pistolVitalData.remainingAmmo -= m_pistolVitalData.clipSize;
    if (m_pistolVitalData.remainingAmmo == 0) {
        m_isAmmoEmpty = true;
    }
    printAfterReloadMessage();
    std::cout << '\n';
}

bool Pistol::isClipEmpty() const {
    return m_pistolVitalData.currClipBullets == 0;
}

bool Pistol::isTargetDeath(std::unique_ptr<Player> &defendingPlayer) {
    return defendingPlayer->getVitalData().health <= 0;
}

void Pistol::actionsWhenEnemyHaveArmor(std::unique_ptr<Player> &defendingPlayer, const int damageToArmor,
                                       const int damageToHealth) {
    defendingPlayer->getVitalData().armor -= m_pistolVitalData.damagePerRound * damageToArmor / 100;

    if (defendingPlayer->getVitalData().armor < 0) {
        defendingPlayer->getVitalData().health -= std::abs(defendingPlayer->getVitalData().armor);
        defendingPlayer->getVitalData().armor = 0;
    }
    defendingPlayer->getVitalData().health -= m_pistolVitalData.damagePerRound * damageToHealth / 100;
}

inline void Pistol::printMessageAfterShooting(std::unique_ptr<Player> &defendingPlayer) {
    std::cout << "Enemy left with: " << defendingPlayer->getVitalData().health << " health and "
              << defendingPlayer->getVitalData().armor << " armor" << std::endl;
}

void Pistol::actionsWhenNotEnoughAmmoToFillClip() {
    m_pistolVitalData.currClipBullets = m_pistolVitalData.remainingAmmo;
    m_pistolVitalData.remainingAmmo = 0;
    m_isAmmoEmpty = true;
}