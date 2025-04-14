#include "Grass.h"
#include<iostream>
using namespace std;

Grass::Grass(int x, int y, int initiative, int strength) :Plant(x, y, initiative, strength)
{

}

Organism* Grass::create()
{
	Organism* grass = new Grass(0, 0, this->get_initiative(), this->getstrenght());
		return grass;
}

void Grass::printSymbol()
{
	cout << "$";
}

string Grass::get_species()
{
	return "Grass";
}
