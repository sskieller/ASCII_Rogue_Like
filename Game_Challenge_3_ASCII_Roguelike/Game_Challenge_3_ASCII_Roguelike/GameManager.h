#pragma once
#include <iostream>
#include <string>
#include <conio.h>

#include "player.h"
#include "Level.h"

using namespace std;

class GameManager
{
public:
	GameManager();

	void initGame();
	void playGame();
private:
	Level level;
	Player player1;
};

