#ifndef SPELLBOOK_H_
#define SPELLBOOK_H_

#include <string>
#include <vector>
#include <map>
#include "Defines.h"
#include "Spell.h"


class SpellBook
{
public:
    SpellBook(const std::vector<Spell>& basic_spells, const std::vector<Spell>& ultimate_spells)
    {
        m_spells[BASIC] = basic_spells;
        m_spells[ULTIMATE] = ultimate_spells;
    }
    
    SpellBook(const char* basic_name, const int basic_cost, const char* ultimate_name, int ultimate_cost)
    {
        m_spells.emplace(BASIC, std::vector<Spell>{Spell(basic_name, basic_cost)});
        m_spells.emplace(ULTIMATE, std::vector<Spell>{Spell(ultimate_name, ultimate_cost)});
    }
    // additional functionality can be added  e.g. unlocking spells
    const std::vector<Spell>& getBasicSpells() const
    {
        return m_spells.at(BASIC);
    }
    const std::vector<Spell>& getUltimateSpells() const
    {
        return m_spells.at(ULTIMATE);
    }

private:
    std::map<SpellType, std::vector<Spell>> m_spells;
};



#endif /* SPELLBOOK_H_ */