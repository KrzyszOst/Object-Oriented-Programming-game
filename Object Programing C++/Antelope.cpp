#include "Antelope.h"
#include<iostream>
using namespace std;

Antelope::Antelope(int x, int y, int initiative, int strength) :Animal(x, y, initiative, strength)
{

}

Organism* Antelope::create()
{
	Organism* antelope = new Antelope(0, 0, this->get_initiative(), this->getstrenght());
	return antelope;
}

void Antelope::printSymbol()
{
	cout << "A";
}

void Antelope::action(bool& action, int range_of_movement)
{
	Animal::action(action, 2);
}

bool Antelope::can_escape()
{
	int chance_to_escape = rand() % 2;
	if (chance_to_escape == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

string Antelope::get_species()
{
	return "Antelope";
}
