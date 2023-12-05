#ifndef DRAWRANGER_H_
#define DRAWRANGER_H_

#include "Hero.h"

class DrawRanger : public Hero
{
public:
    DrawRanger(const std::string& name, int maxMana, int baseManaRegenRate) 
        : Hero(name, maxMana, baseManaRegenRate, DRAW_RANGER_BASIC_SPELL_NAME, DRAW_RANGER_BASIC_SPELL_MANA_COST,
        DRAW_RANGER_ULTIMATE_SPELL_NAME, DRAW_RANGER_ULTIMATE_SPELL_MANA_COST) 
        {};

    void castSpecial(SpellType spellType) override;
    void castFreeBasicSpell();
};

#endif