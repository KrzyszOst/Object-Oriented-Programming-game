#pragma once
#include "Animal.h"
class Antelope :
    public Animal
{
public:
    Antelope(int x, int y, int initiative, int strength);
    Organism* create() override;
    void printSymbol() override;
    void action(bool& action, int range_of_movement) override;
    virtual bool can_escape() override;
    virtual string get_species() override;
};
