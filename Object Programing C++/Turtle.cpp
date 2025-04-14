#include "Turtle.h"
#include<iostream>
using namespace std;

Turtle::Turtle(int x, int y, int initiative, int strength) :Animal(x, y, initiative, strength)
{

}

Organism* Turtle::create()
{
	Organism* turtle = new Turtle(0, 0, this->get_initiative(), this->getstrenght());
	return turtle;
}

void Turtle::printSymbol()
{
	cout << "T";
}

void Turtle::action(bool& action,int range_of_moves)
{
	int chance_to_move = rand()%4;
	if (chance_to_move == 1)
	{
		Animal::action(action,1);
	}

}

string Turtle::get_species()
{
	return "Turtle";
}

bool Turtle::deflect_the_atack(int strenght)
{
	if (strenght < 5)
	{
		return true;
	}
	else
	{
		return false;
	}
}

