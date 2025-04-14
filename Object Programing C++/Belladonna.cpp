#include "Belladonna.h"
#include<iostream>
using namespace std;
Belladonna::Belladonna(int x, int y, int initiative, int strength) :Plant(x, y, initiative, strength)
{
}

Organism* Belladonna::create()
{
	Organism* belladona = new Belladonna(0, 0, this->get_initiative(), this->getstrenght());
	return belladona;
}

void Belladonna::printSymbol()
{
	cout << "%";
}

string Belladonna::get_species()
{
	return "Belladona";
}

bool Belladonna::is_toxic()
{
	return true;
}
