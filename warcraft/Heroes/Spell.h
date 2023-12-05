#ifndef SPELL_H
#define SPELL_H

class Spell 
{
public:
    Spell(const char* name, int manaCost) : m_name(name), m_manaCost(manaCost) {}

    const char* getName() const
    {
        return m_name;
    }
    int getManaCost() const
    {
        return m_manaCost;
    }

private:
    const char* m_name;
    int m_manaCost;
};

#endif