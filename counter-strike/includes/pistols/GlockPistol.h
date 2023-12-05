#ifndef COUNTER_STRKE_0_1_GLOCK_PISTOL_H
#define COUNTER_STRKE_0_1_GLOCK_PISTOL_H

#include "Pistol.h"

class GlockPistol : public Pistol {
public:
    explicit GlockPistol(PistolVitalData vitalData);

    void damageApplier(std::unique_ptr<Player> &defendingPlayer) override;

};

#endif //COUNTER_STRKE_0_1_GLOCK_PISTOL_H
