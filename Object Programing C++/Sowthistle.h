#pragma once
#include "Plant.h"
class Sowthistle :
    public Plant
{
public:
    Sowthistle(int x_, int y, int initiative, int strength);
    Organism* create() override;
    void printSymbol() override;
    virtual string get_species() override;
    void action(bool& action, int range_of_movement) override;
    
};

