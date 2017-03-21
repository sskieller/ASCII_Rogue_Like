#include <iostream>
#include <string>
#include <conio.h> // _getch() for input
#include <fstream> // Save to file

#include "Level.h"

using namespace std;


int main()
{
	Level level1;
	level1.loadLevel();
	level1.printLevel();
	//level1.saveLevel();


	system("PAUSE");
	return 0;
}