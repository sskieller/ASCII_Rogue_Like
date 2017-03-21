#include <iostream>
#include <string>
#include <conio.h> // _getch() for input
#include <fstream> // Save to file

#include "Level.h"

using namespace std;


int main()
{
	Level level;
	level.loadLevel("Level1.txt");
	level.printLevel();
	level.saveLevel("Level2.txt");


	system("PAUSE");
	return 0;
}