#pragma once
#include "Animal.h"
class Turtle :
    public Animal
{
public:
    Turtle(int x, int y, int initiative, int strength);
    Organism* create() override;
    void printSymbol() override;
    void action(bool& action,int range_of_moves) override;
    virtual string get_species() override;
    virtual bool deflect_the_atack(int strenght) override;
};

