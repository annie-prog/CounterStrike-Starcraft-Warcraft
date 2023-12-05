#ifndef COUNTER_STRKE_0_1_PISTOL_H
#define COUNTER_STRKE_0_1_PISTOL_H

#include "Defines.h"
#include <memory>
#include <iostream>

class Player;

class Pistol {
public:

    explicit Pistol(PistolVitalData &vitalData);

    virtual ~Pistol() = default;

    virtual bool fire(std::unique_ptr<Player> &defendingPlayer);

    virtual void reload();

    static bool isPistolVitalDataValid(const PistolVitalData& vitalData)
    {
        if(vitalData.damagePerRound < 0 || vitalData.clipSize < 0 || vitalData.remainingAmmo < 0)
        {
            std::cout << "Invalid data for pistol!" << std::endl;
            return false;
        }
        return true;
    }
    static bool isPistolIndexValid(int pistolIndex)
    {
        if(pistolIndex != static_cast<int>(PistolType::GLOCK) && pistolIndex != static_cast<int>(PistolType::DESERT_EAGLE))
        {
            std::cout << "Invalid id for pistol!" << std::endl;
            return false;
        }
        return true;
    }

protected:
    PistolVitalData m_pistolVitalData;
    bool m_isAmmoEmpty{false};

    virtual void printMessageAfterShooting(std::unique_ptr<Player> &defendingPlayer);

    bool isClipEmpty() const;

    virtual void damageApplier(std::unique_ptr<Player> &defendingPlayer) = 0;

    virtual bool isTargetDeath(std::unique_ptr<Player> &defendingPlayer);

    virtual void actionsWhenEnemyHaveArmor(std::unique_ptr<Player> &defendingPlayer, int damageToArmor, int damageToHealth);

private:
    void printNoAmmoMessage() {
        std::cout << "No ammo left" << std::endl;
    }

    void actionsWhenNotEnoughAmmoToFillClip();

    void printAfterReloadMessage() const {
        std::cout << "currClipBullets: " << m_pistolVitalData.currClipBullets << ", remainingAmmo: "
                  << m_pistolVitalData.remainingAmmo << std::endl;
    }
    
};


#endif //COUNTER_STRKE_0_1_PISTOL_H
