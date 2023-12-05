#include "Player.h"

Player::Player(PlayerVitalData vitalData) : m_vitalData(vitalData) {};

bool Player::buyPistol(std::istream &customStream) {
    std::string inputData;
    PistolVitalData curPistolVitalData;
    int pistolIndex = 0;

    std::getline(customStream, inputData);
    std::istringstream ss(inputData);

    if(!(ss >> pistolIndex >> curPistolVitalData.damagePerRound >> curPistolVitalData.clipSize >> curPistolVitalData.remainingAmmo))
    {
        std::cout << "Invalid data for pistol!" << std::endl;
        return false;
    }
    if(!(Pistol::isPistolIndexValid(pistolIndex)))
    {
        return false;
    }
    if(!(Pistol::isPistolVitalDataValid(curPistolVitalData)))
    {
        return false;
    }
    curPistolVitalData.currClipBullets = curPistolVitalData.clipSize;

    m_pistol = weaponsLibrary.at(pistolIndex)(curPistolVitalData);
    return true;
};

PlayerVitalData& Player::getVitalData()
{
    return m_vitalData;
}

std::unique_ptr<Pistol>& Player::getPistol()
{
    return m_pistol;
}