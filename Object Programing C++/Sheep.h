#pragma once
#include "Animal.h"
class Sheep :
    public Animal
{
public:
    Sheep(int x, int y, int initiative, int strength);
    Organism* create() override;
    void printSymbol() override;
    virtual string get_species() override;
};

