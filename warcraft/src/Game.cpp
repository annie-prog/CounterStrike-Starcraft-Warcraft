#include "Game.h"
#include <stdexcept>

void validateData(int maxMana, int baseManaRegenRate, int manaRegenModifier = 1)
{
    if(maxMana <= 0 || baseManaRegenRate <= 0 || manaRegenModifier < 0)
    {
        throw std::invalid_argument("Mana values need to be bigger than 0!");
    }
}

void Game::Play() 
{
    std::string name;
    int maxMana = 0;
    int baseManaRegenRate = 0;
    int manaRegenModifier = 0;

    std::vector<std::unique_ptr<Hero>> heroes;

    std::cin >> name >> maxMana >> baseManaRegenRate >> manaRegenModifier;
    validateData(maxMana, baseManaRegenRate, manaRegenModifier);
    heroes.emplace_back(std::make_unique<Archmage>(name, maxMana, baseManaRegenRate, manaRegenModifier));

    std::cin >> name >> maxMana >> baseManaRegenRate;
    validateData(maxMana, baseManaRegenRate);
    heroes.emplace_back(std::make_unique<DeathKnight>(name, maxMana, baseManaRegenRate));
    
    std::cin >> name >> maxMana >> baseManaRegenRate;
    validateData(maxMana, baseManaRegenRate);
    heroes.emplace_back(std::make_unique<DrawRanger>(name, maxMana, baseManaRegenRate));

    int commandCount = 0;
    std::cin >> commandCount;
    std::cin.ignore();

    m_commands.reserve(commandCount);
    for (int i = 0; i < commandCount; i++) {
        int command;
        std::cin >> command;
        m_commands.push_back(command);
    }

    for (int j = 0; j < commandCount; j++) {
        int currentCommand = m_commands[j];
        switch (currentCommand) {
            case ActionType::CAST_BASIC_SPELL:
                for(size_t i = 0; i < heroes.size(); i++)
                {
                    (*heroes[i]).castSpell((*heroes[i]).getBasicSpells()[0], BASIC);
                }
                break;

            case ActionType::CAST_ULTIMATE_SPELL:
                for(size_t i = 0; i < heroes.size(); i++)
                {
                    (*heroes[i]).castSpell((*heroes[i]).getUltimateSpells()[0], ULTIMATE);
                }
                break;

            case ActionType::REGENERATE_MANA:
                for(size_t i = 0; i < heroes.size(); i++)
                {
                    (*heroes[i]).regenerateMana();
                }
                break;
        }
    }
}