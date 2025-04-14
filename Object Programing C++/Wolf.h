#pragma once
#include "Animal.h"
class Wolf :
    public Animal
{
public:
    Wolf(int x, int y, int initiative, int strength);
    Organism* create() override;
    void printSymbol() override;
    virtual string get_species() override;
};

