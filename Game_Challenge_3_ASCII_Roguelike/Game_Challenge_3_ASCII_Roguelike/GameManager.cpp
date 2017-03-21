#include "GameManager.h"



GameManager::GameManager()
{
}


void GameManager::playGame()
{
	Level level;
	level.loadLevel("Level1.txt");
	level.printLevel();
	level.saveLevel("Level2.txt");
}