#include "Animal.h"
#include <cstdlib>
#include "World.h"
Organism* Animal::create()
{
	return nullptr;
}
Animal::Animal(int x, int y, int initiative, int strength) :Organism(x, y, initiative, strength)
{

}

bool Animal::collision(Organism& other)
{
	if (this->get_species() == other.get_species())
	{
		return false;
	}
	return true;
}

void Animal::action(bool& sueside,int range_of_movement)
{
	World* world=getworld();
	int direction = rand() % 4;

	int copyX=get_x();
	int copyY = get_y();

	if (direction == 0)
	{
		copyX+=range_of_movement;

	}
	if (direction == 1)
	{
		copyX-=range_of_movement;
	}
	if (direction == 2)
	{
		copyY+= range_of_movement;
	}
	if (direction == 3)
	{
		copyY-= range_of_movement;
	}
	if (copyX >= 0 && copyX < world->width && copyY >= 0 && copyY < world->height)
	{
		if (world->board[{copyX, copyY}] == nullptr)
		{
			world->board[{get_x(), get_y()}] = nullptr;
			world->board[{copyX, copyY}] = this;
			set_x(copyX);
			set_y(copyY);
		}
		else
		{
			if (this->collision(*world->board[{copyX, copyY}]) == true)//fight
			{
				
				if (world->board[{copyX, copyY}]->deflect_the_atack(this->getstrenght()) == true)
				{
					return;
				}
				if (fight(*world->board[{copyX, copyY}]) == true)
				{
					for (int i = 0; i < world->organisms.size(); i++)
					{
						if (world->board[{copyX, copyY}] == world->organisms[i])
						{
							if (world->board[{copyX, copyY}]->can_escape() == false)
							{
								string log = "Animal:";
								log += this->get_species();
								log+=" won fight with : ";
								log += world->board[{copyX, copyY}]->get_species();
								world->setfirstlog(log);
								int& strenght = this->getstrenght();
								world->board[{copyX, copyY}]->increase_strenght(strenght);
								bool is_toxic = world->board[{copyX, copyY}]->is_toxic();
								delete world->board[{copyX, copyY}];
								world->organisms[i] = nullptr;
								world->board[{copyX, copyY}] = nullptr;
								world->board[{get_x(), get_y()}] = nullptr;
								world->board[{copyX, copyY}] = this;
								set_x(copyX);
								set_y(copyY);
								if (is_toxic == true)
								{
									world->board[{copyX, copyY}] = nullptr;
									sueside = true;
								}
								return;
							}
							else//if escapes
							{
								if (copyX >= 1)
								{
									if (world->board[{copyX - 1, copyY}] == nullptr)
									{
										world->board[{copyX - 1, copyY}] = world->board[{copyX, copyY}];
										world->board[{copyX, copyY}] = this;
										world->board[{copyX - 1, copyY}]->set_x( copyX - 1);
										world->board[{copyX - 1, copyY}]->set_y(copyY);
										set_x(copyX);
										set_y(copyY);
										return;
									}
								}
								if (copyX < world->width - 1)
								{

									if (world->board[{copyX + 1, copyY}] == nullptr)
									{
										world->board[{copyX + 1, copyY}] = world->board[{copyX, copyY}];
										world->board[{copyX, copyY}] = this;
										world->board[{copyX - 1, copyY}]->set_x(  copyX + 1);
										world->board[{copyX + 1, copyY}]->set_y(copyY);
										set_x(copyX);
										set_y(copyY);
										return;
									}
								}
								if (copyY >= 1)
								{

									if (world->board[{copyX, copyY - 1}] == nullptr)
									{
										world->board[{copyX , copyY-1}] = world->board[{copyX, copyY}];
										world->board[{copyX, copyY}] = this;
										world->board[{copyX , copyY-1}]->set_x(copyX );
										world->board[{copyX , copyY-1}]->set_y(copyY-1);
										set_x(copyX);
										set_y(copyY);
										return;
									}
								}
								if (copyY < world->height - 1)
								{

									if (world->board[{copyX, copyY + 1}] == nullptr)
									{
										world->board[{copyX , copyY+1}] = world->board[{copyX, copyY}];
										world->board[{copyX, copyY}] = this;
										world->board[{copyX, copyY+1}]->set_x(copyX );
										world->board[{copyX, copyY+1}]->set_y(copyY+1);
										set_x(copyX);
										set_y(copyY);
										return;
									}
								}
							}
						}
					}

				}
				
				else
				{
					if (has_a_good_sense_of_smell() == false)
					{
						string log = "Animal:";
						log += this->get_species();
						log += " lost fight with : ";
						log += world->board[{get_x(), get_y()}]->get_species();
						world->setfirstlog(log);
						world->board[{get_x(), get_y()}] = nullptr;
						sueside = true;

						return;
					}

				}
			}
			else//romantic time
			{
				
				if (get_x() >= 1)
				{
					if (world->board[{get_x()-1, get_y()}] == nullptr)
					{
						Organism* organism = create();
						organism->setworld ( world);
						organism->set_x(get_x()-1);
						organism->set_y(get_y());
						world->board[{get_x()-1, get_y()}] = organism;
						world->organisms.push_back(organism);
						return;
					}
				}
				if (get_x() < world->width - 1)
				{

					if (world->board[{get_x()+1, get_y()}] == nullptr)
					{
						Organism* organism = create();
						organism->setworld(world);
						organism->set_x(get_x() + 1);
						organism->set_y(get_y());
						world->board[{get_x()+1, get_y()}] = organism;
						world->organisms.push_back(organism);
						return;
					}
				}
				if (get_y() >= 1)
				{

					if (world->board[{get_x(), get_y()-1}] == nullptr)
					{
						Organism* organism = create();
						organism->setworld(world);
						organism->set_x(get_x());
						organism->set_y(get_y()-1);
						world->board[{get_x(), get_y()-1}] = organism;
						world->organisms.push_back(organism);
						return;
					}
				}
				if ( get_y() < world->height - 1)
				{

					if (world->board[{get_x(), get_y()+1}] == nullptr)
					{
						Organism* organism = create();
						organism->setworld(world);
						organism->set_x(get_x());
						organism->set_y(get_y()+1);
						world->board[{get_x(), get_y()+1}] = organism;
						world->organisms.push_back(organism);
						return;
					}
				}
			}
		}
	}

}

bool Animal::fight(Organism& other)
{
	if (this->getstrenght() >= other.getstrenght())
	{
		return true;
	}
	else
	{
		return false;
	}
}

