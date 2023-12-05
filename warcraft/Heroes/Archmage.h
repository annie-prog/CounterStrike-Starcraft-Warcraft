#ifndef ARCHMAGE_H_
#define ARCHMAGE_H_

#include "Hero.h"

class Archmage : public Hero
{
public:
    Archmage(const std::string& name, size_t maxMana, size_t baseManaRegenRate, size_t manaRegenModifier) 
        : Hero(name, maxMana, baseManaRegenRate, ARCHMAGE_BASIC_SPELL_NAME, ARCHMAGE_BASIC_SPELL_MANA_COST, 
        ARCHMAGE_ULTIMATE_SPELL_NAME, ARCHMAGE_ULTIMATE_SPELL_MANA_COST), m_regen_modifier(manaRegenModifier)
        {};

    void castSpecial(SpellType spellType) override;
    void regenerateMana() override;

private:
    size_t m_regen_modifier;
};

#endif /* ARCHMAGE_H_ */