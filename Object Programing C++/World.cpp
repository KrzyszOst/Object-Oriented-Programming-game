#include "World.h"
#include "Organism.h"
#include<iostream>
#include<algorithm>
#include "Human.h"
#include "Grass.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Turtle.h"
#include "Antelope.h"
#include "Sowthistle.h"
#include "Guarana.h"
#include "Belladonna.h"
#include "Sosnowsky_hogweed.h"
#include "Fox.h"

using namespace std;
World::World(int width, int height)
{
	int x;
	int y;
	srand(time(NULL));
	this->width = width;
	this->height = height;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			board[{i, j}] = nullptr;
		}
	}
	Organism* a = nullptr;
	get_random_x_y(x, y);
	a = new Human(x, y , 4, 5);
	organisms.push_back(a);
	a->setworld(this);
	board[{x, y}] = a;

	get_random_x_y(x, y);
	a = new Antelope(x, y, 4, 4);
	organisms.push_back(a);
	a->setworld(this);
	board[{x, y}] = a;

	get_random_x_y(x, y);
	a = new Turtle(x, y, 1, 2);
	organisms.push_back(a);
	a->setworld(this);
	board[{x, y}] = a;

	get_random_x_y(x, y);
	a = new Fox(x, y, 7, 3);
	organisms.push_back(a);
	a->setworld(this);
	board[{x, y}] = a;

	get_random_x_y(x, y);
	a = new Sheep(x, y, 4, 4);
	organisms.push_back(a);
	a->setworld(this);
	board[{x, y}] = a;

	get_random_x_y(x, y);
	a = new Wolf(x, y, 5, 9);
	organisms.push_back(a);
	a->setworld(this);
	board[{x, y}] = a;

	get_random_x_y(x, y);
	a = new Antelope(x, y, 4, 4);
	organisms.push_back(a);
	a->setworld(this);
	board[{x, y}] = a;

	get_random_x_y(x, y);
	a = new Turtle(x, y, 1, 2);
	organisms.push_back(a);
	a->setworld(this);
	board[{x, y}] = a;

	get_random_x_y(x, y);
	a = new Fox(x, y, 7, 3);
	organisms.push_back(a);
	a->setworld(this);
	board[{x, y}] = a;

	get_random_x_y(x, y);
	a = new Sheep(x, y, 4, 4);
	organisms.push_back(a);
	a->setworld(this);
	board[{x, y}] = a;

	get_random_x_y(x, y);
	a = new Wolf(x, y, 5, 9);
	organisms.push_back(a);
	a->setworld(this);
	board[{x, y}] = a;

	get_random_x_y(x, y);
	a = new Grass(x, y, 0, 0);
	organisms.push_back(a);
	a->setworld(this);
	board[{x, y}] = a;

	get_random_x_y(x, y);
	a = new Sowthistle(x, y, 0, 0);
	organisms.push_back(a);
	a->setworld(this);
	board[{x, y}] = a;

	get_random_x_y(x, y);
	a = new Guarana(x, y, 0, 0);
	organisms.push_back(a);
	a->setworld(this);
	board[{x, y}] = a;

	get_random_x_y(x, y);
	a = new Belladonna(x, y, 0, 99);
	organisms.push_back(a);
	a->setworld(this);
	board[{x, y}] = a;

	get_random_x_y(x, y);
	a = new Sosnowsky_hogweed(x, y, 0, 10);
	organisms.push_back(a);
	a->setworld(this);
	board[{x, y}] = a;



	
}
void World::drawWorld()
{
	for (int x = 0; x < width+2; x++)
	{

		cout << "*";

	}
	cout << endl;
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (x == 0)
			{
				cout << "*";
			}

			if (board[{x, y}] != nullptr)
			{
				board[{x, y}]->printSymbol();
			}
			else
			{
				cout << ' ';
			}
			if (x == width - 1)
			{
				cout << "*";
			}
		}

		cout << std::endl;
	}
	for (int x = 0; x < width+2; x++)
	{

		cout << "*";

	}
	cout << endl;
	cout << "log: "<<firstlog;
	firstlog.clear();
	cout << endl;
	cout << secondlog;
	secondlog.clear();
	cout << endl;
	cout << "Krzysztof Ostrzycki index number:193507" << endl;
	cout << "H - human" << endl;
	cout << "Animals:"<<endl;
	cout << "W - wolf" << endl;
	cout << "T - turtle" << endl;
	cout << "S - sheep" << endl;
	cout << "F - fox" << endl;
	cout << "A - antelope" << endl;
	cout << "Plants:" << endl;
	cout << "! = sow thistle" << endl;
	cout << "@ = sosnowsky hogweed " << endl;
	cout << "# = guarana" << endl;
	cout << "$ - grass" << endl;
	cout << "% - belladonna" << endl;

	
}
bool sorting(Organism* first, Organism* second)
{
	if (first == nullptr)
	{
		return false;
	}
	if (second == nullptr)
	{
		return true;
	}
	if (first->get_initiative() > second->get_initiative())
	{
		return true;
	}
	else if (first->get_initiative() == second->get_initiative())
	{
		if (first->get_age() > second->get_age())
		{
			return true;
		}
		return false;
	}
	else
	{
		return false;
	}
}
void World::makeTurn()
{
	int organism_size = organisms.size();
	for (int i = 0; i < organism_size; i++)
	{
		if (organisms[i] != nullptr)
		{
			bool remove = false;
			organisms[i]->action(remove, 1);
			if (remove == true)
			{
				delete organisms[i];
				organisms[i] = nullptr;
			}
			else
			{
				organisms[i]->increaseAge();
			}
		}


	}
	sort(organisms.begin(), organisms.end(), sorting);
}

void World::setfirstlog(string firstlog)
{
	this->firstlog = firstlog;
}

void World::setsecondlog(string secondlog)
{
	this->secondlog = secondlog;
}

void World::get_random_x_y(int& x, int& y)
{
	while (true)
	{
		x = rand() % width;
		y = rand() % height;
		if (board[{x, y}] == nullptr)
		{
			return;
		}
		
	}
	return;
}
