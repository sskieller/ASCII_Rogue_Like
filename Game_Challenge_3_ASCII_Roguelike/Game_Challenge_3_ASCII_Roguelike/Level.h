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

	void loadLevel();
	void clearLevel();
	void saveLevel();
	void printLevel();

private:
	ofstream outputFile;
	ifstream inputFile;
	vector<string> levelStrings;
	string input;
	string output;
};

