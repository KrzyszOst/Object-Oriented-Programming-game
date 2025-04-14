#pragma once
#include "Organism.h"
class Animal :
    public Organism
{
public:
	virtual Organism* create() override;
	Animal(int x, int y, int initiative, int strength);
	
	bool collision(Organism& other) override;
	virtual void action(bool& action, int range_of_movement) override;
	virtual bool fight(Organism & other);
	
};

