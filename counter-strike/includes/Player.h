#ifndef COUNTER_STRKE_0_1_PLAYER_H
#define COUNTER_STRKE_0_1_PLAYER_H

#include "Defines.h"
#include "WeaponsLibraries.h"
#include "pistols/Pistol.h"
#include <iostream>
#include <sstream>


class Player {
public:
    explicit Player(PlayerVitalData vitalData);

    bool buyPistol(std::istream &customStream);

    PlayerVitalData& getVitalData();
    std::unique_ptr<Pistol>& getPistol();

    static bool isPlayerVitalDataValid(const PlayerVitalData& vitalData)
    {
        if(vitalData.health < 0 || vitalData.armor < 0)
        {
            std::cout << "Player data is invalid!" << std::endl;
            return false;
        }
        return true;
    }

private:
    PlayerVitalData m_vitalData;
    std::unique_ptr<Pistol> m_pistol{nullptr};

};


#endif //COUNTER_STRKE_0_1_PLAYER_H
