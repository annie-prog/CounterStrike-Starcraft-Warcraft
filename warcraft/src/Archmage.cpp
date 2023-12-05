#include "Archmage.h"
#include "Defines.h"
#include <iostream>

void Archmage::castSpecial(SpellType spellType)
{
    if(spellType == ULTIMATE)
    {
        regenerateMana();
    }
}

void Archmage::regenerateMana()
{
    setManaRegenerate(getManaRegenerate() * m_regen_modifier);
    Hero::regenerateMana();
}