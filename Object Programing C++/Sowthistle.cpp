#include "Sowthistle.h"
#include<iostream>
using namespace std;

Sowthistle::Sowthistle(int x, int y, int initiative, int strength):Plant(x, y, initiative, strength)
{

}

Organism* Sowthistle::create()
{
	Organism* sowthistle = new Sowthistle(0, 0, this->get_initiative(), this->getstrenght());
	return sowthistle;
}

void Sowthistle::printSymbol()
{
	cout << "!";
}

string Sowthistle::get_species()
{
	return "Sowthistle";
}

void Sowthistle::action(bool& action, int range_of_movement)
{
	int chances = 3;
	while (chances > 0)
	{
		Plant::action(action, range_of_movement);
		chances--;
	}
}
