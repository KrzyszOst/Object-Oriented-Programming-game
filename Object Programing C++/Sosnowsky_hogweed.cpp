#include "Sosnowsky_hogweed.h"
#include<iostream>
#include "World.h"
using namespace std;

Sosnowsky_hogweed::Sosnowsky_hogweed(int x, int y, int initiative, int strength) :Plant(x, y, initiative, strength)
{
}

Organism* Sosnowsky_hogweed::create()
{
	Organism* sosnowsky_hogweed = new Sosnowsky_hogweed(0, 0, this->get_initiative(), this->getstrenght());
	return sosnowsky_hogweed;
}

void Sosnowsky_hogweed::printSymbol()
{
	cout << "@";
}

string Sosnowsky_hogweed::get_species()
{
	return "Sosnowsky_hogweed";
}

void Sosnowsky_hogweed::action(bool& action, int range_of_movement)
{
	World* world = getworld();
	int x = get_x();
	int y = get_y();
	Plant::action(action, range_of_movement);
	if (x >= 1)
	{
		if (world->board[{x - 1, y}] != nullptr)
		{
			if (dynamic_cast<Plant*>(world->board[{x - 1, y}]) == nullptr)
			{

				for (int i = 0; i < world->organisms.size(); i++)
				{
					if (world->board[{x - 1, y}] == world->organisms[i])
					{
						world->organisms[i] = nullptr;
						delete world->board[{x - 1, y}];
						world->board[{x - 1, y}] = nullptr;
					}
				}
			}
		}
	}
	if (x < world->width - 1)
	{

		if (world->board[{x + 1, y}] != nullptr)
		{
			if (dynamic_cast<Plant*>(world->board[{x + 1, y}]) == nullptr)
			{

				for (int i = 0; i < world->organisms.size(); i++)
				{
					if (world->board[{x + 1, y}] == world->organisms[i])
					{
						world->organisms[i] = nullptr;
						delete world->board[{x + 1, y}];
						world->board[{x + 1, y}] = nullptr;
					}
				}
			}

		}
	}
	if (y >= 1)
	{

		if (world->board[{x, y - 1}] != nullptr)
		{
			if (dynamic_cast<Plant*>(world->board[{x, y - 1}]) == nullptr)
			{

				for (int i = 0; i < world->organisms.size(); i++)
				{
					if (world->board[{x, y-1}] == world->organisms[i])
					{
						world->organisms[i] = nullptr;
						delete world->board[{x, y - 1}];
						world->board[{x, y - 1}] = nullptr;
					}
				}
			}
		}
	}
	if (y < world->height - 1)
	{

		if (world->board[{x, y + 1}] != nullptr)
		{
			if (dynamic_cast<Plant*>(world->board[{x, y + 1}]) == nullptr)
			{

				for (int i = 0; i < world->organisms.size(); i++)
				{
					if (world->board[{x, y+1}] == world->organisms[i])
					{
						world->organisms[i] = nullptr;
						delete world->board[{x, y + 1}];
						world->board[{x, y + 1}] = nullptr;
					}
				}
			}

		}
	}
}

bool Sosnowsky_hogweed::is_toxic()
{
	return true;
}
