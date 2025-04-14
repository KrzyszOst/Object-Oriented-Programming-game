#include "Guarana.h"
#include<iostream>
using namespace std;
Guarana::Guarana(int x, int y, int initiative, int strength) :Plant(x, y, initiative, strength)
{
}

Organism* Guarana::create()
{
	Organism* guarana = new Guarana(0, 0, this->get_initiative(), this->getstrenght());
	return guarana;
}

void Guarana::printSymbol()
{
	cout << "#";
}

string Guarana::get_species()
{
	return "Guarana";
}

void Guarana::increase_strenght(int& strenght)
{
	strenght += 3;
}
