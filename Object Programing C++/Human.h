#pragma once
#include "Animal.h"

class Human :
    public Animal
{

public:
    int super_ability_counter = -5;
    Human(int x, int y, int initiative, int strength);
    void printSymbol();
    Organism* create() override;
    void action(bool& action, int range_of_movement) override;
    virtual string get_species() override;
    virtual bool deflect_the_atack(int strenght) override;
};

