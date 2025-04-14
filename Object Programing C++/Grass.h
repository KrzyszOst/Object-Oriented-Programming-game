#pragma once
#include "Plant.h"
class Grass :
    public Plant
{
public:
    Grass(int x_, int y, int initiative, int strength);
    Organism* create() override;
    void printSymbol() override;
    virtual string get_species() override;
};

