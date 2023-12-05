#include "DrawRanger.h"
#include "Defines.h"
#include <iostream>

void DrawRanger::castSpecial(SpellType spellType)
{
    if(spellType == BASIC)
    {
        std::cout << getName() << " casted " << DRAW_RANGER_BASIC_SPELL_NAME << " for 0 mana\n";
    }
}
