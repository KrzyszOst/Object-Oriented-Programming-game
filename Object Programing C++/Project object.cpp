#include <iostream>
#include <vector>
#include <windows.h>
#include <ctime>
#include "World.h"

using namespace std;


int main()
{
	int height;
	int width;
	cout << "Enter Height of the board:" << endl;
	cin >> height;
	cout << "Enter Width of the board:" << endl;
	cin >> width;
	srand(time(NULL));
	World world(width,height);
	
	while (true)
	{
		world.drawWorld();
		world.makeTurn();
		system("cls");
	}
}

