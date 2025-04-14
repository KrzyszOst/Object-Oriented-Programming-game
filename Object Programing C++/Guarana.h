#pragma once
#include "Plant.h"
class Guarana :
    public Plant
{
public:
    Guarana(int x_, int y, int initiative, int strength);
    Organism* create() override;
    void printSymbol() override;
    virtual string get_species() override;
    virtual void increase_strenght(int& strenght) override;
};

