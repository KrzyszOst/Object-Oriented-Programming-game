#pragma once
#include <string>
using namespace std;
class World;

class Organism
{
private:
	int age = 0;
	int initiative;
	int x;
	int y;
	World* world;
	int strength;
public:
	virtual void action(bool& action,int range_of_movement) = 0;	// czysto wirtualna to taka ktora nie ma ciala
	virtual bool collision(Organism & other) = 0;

	Organism(int x, int y, int initiative, int strength);
	virtual Organism* create() = 0;
	virtual void printSymbol() = 0;
	virtual string get_species() = 0;
	virtual bool deflect_the_atack(int strenght);
	virtual bool has_a_good_sense_of_smell();
	virtual bool can_escape();
	virtual void increase_strenght(int &strenght);
	virtual bool is_toxic();
	World* getworld();
	void  setworld(World* world);
	int get_age();
	int get_initiative();
	int get_x();
	void set_x(int x);
	int get_y();
	void set_y(int y);
	int& getx();
	int& gety();
	int& getstrenght();
	void increaseAge();
	virtual ~Organism();

};
