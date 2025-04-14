#pragma once
#include "Animal.h"
class Fox :
    public Animal
{
public:
    Fox(int x, int y, int initiative, int strength);
    Organism* create() override;
    void printSymbol() override;
    virtual string get_species() override;
    virtual bool has_a_good_sense_of_smell() override;
};


