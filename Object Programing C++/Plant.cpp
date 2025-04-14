#include "Plant.h"
#include <ctime>
#include <cstdlib>
#include "World.h"
Plant::Plant(int x, int y, int initiative, int strength):Organism(x,y, initiative, strength)
{

}
void Plant::action(bool& action, int range_of_movement)
{
	World* world = getworld();
	int x = get_x();
	int y = get_y();
	int chance_to_spawn = rand() % 10;
	if (chance_to_spawn == 0)
	{
		int postion_to_spawn = rand() % 4;
		if (postion_to_spawn == 0&& x>=1)
		{
			if (world->board[{x-1, y}] == nullptr)
			{
				Organism * organism =create();
				organism->setworld ( world);
				organism->set_x( x - 1);
				organism->set_y(  y);
				world->board[{x-1, y}] = organism;
				world->organisms.push_back(organism);
			}
		}
		else if (postion_to_spawn == 1&&x<world->width-1)
		{

			if (world->board[{x+1, y}] == nullptr)
			{
				Organism* organism = create();
				organism->setworld(world);
				organism->set_x(x + 1);
				organism->set_y(y);
				world->board[{x+1, y}] = organism;
				world->organisms.push_back(organism);
			}
		}
		else if (postion_to_spawn == 2 && y>=1)
		{

			if (world->board[{x, y-1}] == nullptr)
			{
				Organism* organism = create();
				organism->setworld(world);
				organism->set_x(x);
				organism->set_y(y-1);
				world->board[{x, y-1}] = organism;
				world->organisms.push_back(organism);
			}
		}
		else if (postion_to_spawn == 3&& y<world->height-1)
		{

			if (world->board[{x, y+1}] == nullptr)
			{
				Organism* organism = create();
				organism->setworld(world);
				organism->set_x(x );
				organism->set_y(y+1);
				world->board[{x, y+1}] = organism;
				world->organisms.push_back(organism);
			}
		}
	}
}

bool Plant::collision(Organism& other)
{
	return false;
}

string Plant::get_species()
{
	return "Plant";
}

