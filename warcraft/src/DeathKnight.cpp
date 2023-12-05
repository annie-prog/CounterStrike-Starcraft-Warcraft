#include "DeathKnight.h"
#include "Defines.h"
#include <iostream>

void DeathKnight::castSpecial(SpellType spellType)
{
    if(spellType == ULTIMATE)
    {
        std::cout << getName() << " casted " << DEATH_KNIGHT_BASIC_SPELL_NAME << " for 0 mana\n";
    }
}
