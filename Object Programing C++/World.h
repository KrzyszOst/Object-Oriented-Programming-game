#pragma once
#include <iostream>
#include <vector>
#include<map>

using namespace std;
class Organism;

class World
{
private:
	string firstlog;
	string secondlog;

public:
	World(int width,int height);
	int width;
	int height;
	map<pair<int,int>,Organism*> board;
	std::vector<Organism*> organisms;
	void drawWorld();
	void setfirstlog(string firstlog);
	void setsecondlog(string secondlog);
	void makeTurn();
	void get_random_x_y(int& x, int& y);
};

