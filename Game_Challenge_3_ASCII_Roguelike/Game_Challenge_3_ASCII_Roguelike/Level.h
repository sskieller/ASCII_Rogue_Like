#pragma once
#include "player.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Level
{
public:
	Level();
	
	void processLevel(Player &player);
	void processPlayerMove(char &input, Player &player);

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

