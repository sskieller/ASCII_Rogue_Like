#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Level
{
public:
	Level();

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
};

