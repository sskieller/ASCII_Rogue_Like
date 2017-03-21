#include "Level.h"



Level::Level()
{

}

void Level::loadLevel()
{
	inputFile.open("Level1.txt");
	if (inputFile.fail())
	{
		perror("Level1.txt");
		return;
	}
	// Get string from file
	while (getline(inputFile, input))
	{
		// Push back string from input
		levelStrings.push_back(input);
	}
}

void Level::clearLevel()
{

}

void Level::saveLevel()
{
	outputFile.open("Level1.txt");
	if (outputFile.fail())
	{
		perror("Level1.txt");
		return;
	}
}

void Level::printLevel()
{
	for (int i = 0; i < levelStrings.size(); i++)
	{
		cout << levelStrings[i] << endl;
	}
}