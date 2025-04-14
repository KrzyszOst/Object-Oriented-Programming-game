#pragma once
#include "Organism.h"
class Plant :
    public Organism
{
public:
    Plant(int x_, int y, int initiative, int strength);
    void action(bool &action, int range_of_movement);

    bool collision(Organism& other) override;
    virtual string get_species()  override;
};

