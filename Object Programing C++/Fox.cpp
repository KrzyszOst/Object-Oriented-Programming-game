#include "Fox.h"
#include<iostream>
using namespace std;
Fox::Fox(int x, int y, int initiative, int strength) :Animal(x, y, initiative, strength)
{

}

Organism* Fox::create()
{
	Organism* fox = new Fox(0, 0, this->get_initiative(), this->getstrenght());
	return fox;
}
void Fox::printSymbol()
{
	cout << "F";
}

string Fox::get_species()
{
    return "Fox";
} 

bool Fox::has_a_good_sense_of_smell()
{
	return true;
}
