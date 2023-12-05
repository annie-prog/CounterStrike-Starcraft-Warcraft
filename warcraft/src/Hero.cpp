#include "Hero.h"

Hero::Hero(const std::string& name, size_t maxMana, size_t baseManaRegenRate,
 const char* basic_name, const int basic_cost, const char* ultimate_name, const int ultimate_cost) : m_name(name), m_max_mana(maxMana), m_mana_regenerate(baseManaRegenRate), 
 m_spells(basic_name, basic_cost, ultimate_name, ultimate_cost)
{
    m_mana = maxMana;
}

const std::string& Hero::getName() const
{
    return m_name;
}

size_t Hero::getMaxMana() const
{
    return m_max_mana;
}

size_t Hero::getMana() const
{
    return m_mana;
}

size_t Hero::getManaRegenerate() const
{
    return m_mana_regenerate;
}

void Hero::regenerateMana()
{
    m_mana += m_mana_regenerate;
    if(m_max_mana < m_mana)
    {
        m_mana = m_max_mana;
    }
}

void Hero::setMana(size_t mana)
{
    m_mana = mana;
}

void Hero::setManaRegenerate(size_t mana_regenerate)
{
    m_mana_regenerate = mana_regenerate;
}

const std::vector<Spell>& Hero::getBasicSpells() const
{
    return m_spells.getBasicSpells();
}

const std::vector<Spell>& Hero::getUltimateSpells() const
{
    return m_spells.getUltimateSpells();
}
void Hero::castSpell(const Spell& spell, SpellType spellType) 
{
    size_t current_mana = getMana();
    if (current_mana < spell.getManaCost()) 
    {
        std::cout << m_name << " - not enough mana to cast " << spell.getName() << '\n';
    } 
    else 
    {
        current_mana -= spell.getManaCost();
        std::cout << m_name << " casted " << spell.getName() << " for " << spell.getManaCost() << " mana\n";
        setMana(current_mana);
        if ((spellType == ULTIMATE || spellType == BASIC)) 
        {
            castSpecial(spellType);
        }
    }
}
