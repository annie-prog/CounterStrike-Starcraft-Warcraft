#ifndef HERO_H_
#define HERO_H_

#include <string>
#include <vector>
#include <map>
#include <memory>
#include <functional>
#include <iostream>
#include "Defines.h"
#include "Spell.h"
#include "SpellBook.h"

class Hero
{
public:
    Hero(const std::string& name, size_t maxMana, size_t baseManaRegenRate, const char* basic_name, const int basic_cost, const char* ultimate_name, int ultimate_cost);

    virtual void castSpecial(SpellType spellType) = 0;
    virtual void regenerateMana();

    const std::string& getName() const;
    size_t getMaxMana() const;
    size_t getMana() const;
    size_t getManaRegenerate() const;

    void setMana(size_t mana);
    void setManaRegenerate(size_t mana_regenerate);

    virtual ~Hero() = default;

    const std::vector<Spell>& getBasicSpells() const;
    const std::vector<Spell>& getUltimateSpells() const;
    void castSpell(const Spell& spell, SpellType spellType);

private:
    std::string m_name;
    size_t m_max_mana;
    size_t m_mana;
    size_t m_mana_regenerate;
    SpellBook m_spells;
};


#endif /* HERO_H_ */