#include "GameManager.h"



GameManager::GameManager()
{
}


void GameManager::initGame()
{
	level.loadLevel("Level1.txt");
	level.processLevel(player1);
	level.printLevel();
}

void GameManager::playGame()
{
	initGame();
	char input = '0';

	do
	{
		input = _getch();
		level.processPlayerMove(input, player1);
		level.printLevel();
	} while (input != 'p' && input != 'P');
	return;
}