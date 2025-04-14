#include "Wolf.h"
#include<iostream>
using namespace std;

Wolf::Wolf(int x, int y, int initiative, int strength):Animal(x,y,initiative,strength)
{

}

Organism* Wolf::create()
{
	Organism* wolf = new Wolf(0, 0, this->get_initiative(), this->getstrenght());
	return wolf;
}

void Wolf::printSymbol()
{
	cout << "W";
}

string Wolf::get_species()
{
	return "Wolf";
}
