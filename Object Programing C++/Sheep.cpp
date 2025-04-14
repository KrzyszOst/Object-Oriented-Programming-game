#include "Sheep.h"
#include<iostream>
using namespace std;
Sheep::Sheep(int x, int y, int initiative, int strength) :Animal(x, y, initiative, strength)
{
}

Organism* Sheep::create()
{
	Organism* sheep = new Sheep(0, 0, this->get_initiative(), this->getstrenght());
	return sheep;
}

void Sheep::printSymbol()
{
	cout << "S";
}

string Sheep::get_species()
{
	return "Sheep";
}


