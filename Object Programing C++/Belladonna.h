#pragma once
#include "Plant.h"
class Belladonna :
    public Plant
{
public:
    Belladonna(int x_, int y, int initiative, int strength);
    Organism* create() override;
    void printSymbol() override;
    virtual string get_species() override;
    virtual bool is_toxic() override;
};

