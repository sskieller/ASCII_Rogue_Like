#include <iostream>
#include <string>
#include <conio.h> // _getch() for input
#include <fstream> // Save to file

#include "GameManager.h"


using namespace std;


int main()
{
	GameManager gameManager;

	gameManager.playGame();


	system("PAUSE");
	return 0;
}