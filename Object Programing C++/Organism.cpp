#include "Organism.h"

Organism::Organism(int x, int y, int initiative, int strength)
{
	this->x = x;
	this->y = y;
	this->initiative = initiative;
	this->strength = strength;
}

bool Organism::deflect_the_atack(int strenght)
{
	return false;
}

bool Organism::has_a_good_sense_of_smell()
{
	return false;
}

bool Organism::can_escape()
{
	return false;
}

void Organism::increase_strenght(int& strenght)
{
}

bool Organism::is_toxic()
{
	return false;
}

World* Organism::getworld()
{
	return world;
}

void Organism::setworld(World* world)
{
	this->world = world;
}

int Organism::get_age()
{
	return age;
}

int Organism::get_initiative()
{
	return initiative;
}

int Organism::get_x()
{
	return x;
}

void Organism::set_x(int x)
{
	this->x = x;
}

int Organism::get_y()
{
	return y;
}

void Organism::set_y(int y)
{
	this->y = y;
}

int& Organism::getx()
{
	return x;
}

int& Organism::gety()
{
	return y;
}

int& Organism::getstrenght()
{
	return strength;
}

void Organism::increaseAge()
{
	age++;
}

Organism::~Organism()
{
}

