#ifndef DEATHKNIGHT_H_
#define DEATHKNIGHT_H_

#include "Hero.h"

class DeathKnight : public Hero
{
public:

    DeathKnight(const std::string& name, size_t maxMana, size_t baseManaRegenRate) 
        : Hero(name, maxMana, baseManaRegenRate, DEATH_KNIGHT_BASIC_SPELL_NAME, DEATH_KNIGHT_BASIC_SPELL_MANA_COST,
         DEATH_KNIGHT_ULTIMATE_SPELL_NAME, DEATH_KNIGHT_ULTIMATE_SPELL_MANA_COST) 
        {};

    void castSpecial(SpellType spellType) override;
    void castFreeBasicSpell();
};

#endif