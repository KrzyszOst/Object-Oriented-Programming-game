#include "Human.h"
#include <iostream>
#include "World.h"
#include<conio.h>
#include<cstdio>
using namespace std;
Human::Human(int x, int y, int initiative, int strength) :Animal(x, y, initiative, strength)
{

}
void Human::printSymbol()
{
	cout << "H";
}

Organism* Human::create()
{
	return nullptr;
}

void Human::action(bool& sueside, int range_of_movement)
{
	World* world = getworld();
	int& x = getx();
	int& y = gety();
	int copyX =get_x();
	int copyY = get_y();
	super_ability_counter--;
	if (super_ability_counter > 0)
	{
		string log = "Human:";
		log += " Ability active  ";
		world->setsecondlog(log);
	}
	while (true)
	{
		int n = _getch();
		if (n == 's')
		{

			if (super_ability_counter <= -5)
			{
				string log = "Human:";
				log += " Used superability  ";
				world->setsecondlog(log);
				super_ability_counter = 5;
			}
			else
			{
				string log = "Human:";
				log += " Ability not read";
				world->setsecondlog(log);
			}
		}
		if (n == 0 || n == 224)
		{
			n = _getch();
			if (n == 72)
			{
				if (y >= 1)
				{
					copyY-= range_of_movement;
					break;
				}

			}
			else if (n == 77)
			{
				if (x < world->width - 1)
				{
					copyX+= range_of_movement;
					break;
				}
			}
			else if (n == 75)
			{
				if (x >= 1)
				{
					copyX-= range_of_movement;
					break;
				}
			}
			else if (n == 80)
			{
				if (y < world->height - 1)
				{
					copyY+= range_of_movement;
					break;
				}
			}
		}

	}

	if (world->board[{copyX, copyY}] == nullptr)
	{
		world->board[{x, y}] = nullptr;
		world->board[{copyX, copyY}] = this;
		x = copyX;
		y = copyY;
	}
	else
	{
		Organism& organism = *world->board[{copyX, copyY}];
		if (organism.deflect_the_atack(this->getstrenght()) == true)
		{
			return;
		}
		if (fight(organism) == true)
		{
			for (int i = 0; i < world->organisms.size(); i++)
			{
				if (world->board[{copyX, copyY}] == world->organisms[i])
				{
					string log = "Human:";
					log += "won fight with : ";
					log += world->board[{copyX, copyY}]->get_species();
					world->setfirstlog(log);
					int& strenght = this->getstrenght();
					organism.increase_strenght(strenght);
					bool is_toxic = world->board[{copyX, copyY}]->is_toxic();
					delete world->board[{copyX, copyY}];
					world->organisms[i] = nullptr;
					world->board[{copyX, copyY}] = nullptr;
					world->board[{x, y}] = nullptr;
					world->board[{copyX, copyY}] = this;

					x = copyX;
					y = copyY;
					if (is_toxic == true)
					{
						string log = "Human:";
						log += "ate toxic plant : ";
						log += world->board[{copyX, copyY}]->get_species();
						world->setfirstlog(log);
						world->board[{copyX, copyY}] = nullptr;
						sueside = true;
					}
					return;

				}
			}

		}
		else
		{
			world->board[{x, y}] = nullptr;
			sueside = true;
			return;


		}
	}


}


string Human::get_species()
{
	return "Human";

}

bool Human::deflect_the_atack(int strenght)
{
	if (super_ability_counter > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
