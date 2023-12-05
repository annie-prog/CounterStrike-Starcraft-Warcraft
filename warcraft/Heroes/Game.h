#include <iostream>
#include <vector>

#include "Defines.h"
#include "Archmage.h"
#include "DeathKnight.h"
#include "DrawRanger.h"

class Game {
public:
    void Play();

private:
    std::vector<int> m_commands;
};