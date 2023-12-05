#ifndef COUNTER_STRKE_0_1_DESERT_EAGLE_PISTOL_H
#define COUNTER_STRKE_0_1_DESERT_EAGLE_PISTOL_H

#include "Pistol.h"

class DesertEaglePistol : public Pistol {
public:
    explicit DesertEaglePistol(PistolVitalData vitalData);

    void damageApplier(std::unique_ptr<Player> &defendingPlayer) override;

};

#endif //COUNTER_STRKE_0_1_DESERT_EAGLE_PISTOL_H
