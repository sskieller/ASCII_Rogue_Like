#pragma once
#include "player.h"
#include "Monster.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

class Level
{
public:
	Level();
	
	void processLevel(Player &player, Monster &monster);
	void processPlayerMove(char &input, Player &player);

	void processMonsterMove(Monster &monster, Player &player);

	bool monsterCanSeePlayer(int x0, int y0, int x1, int y1);

	bool checkTile(int y, int x);

	void loadLevel(string levelName);
	void clearLevel();
	void saveLevel(string levelName);
	void printLevel();

private:
	ofstream outputFile;
	ifstream inputFile;
	vector<string> levelStrings;
	string input;
	string output;
	char temp = '.';
};

