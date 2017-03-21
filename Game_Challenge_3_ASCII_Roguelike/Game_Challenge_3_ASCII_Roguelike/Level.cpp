#include "Level.h"



Level::Level()
{

}

void Level::loadLevel(string levelName)
{
	string _levelName = levelName;
	inputFile.open(levelName);
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

void Level::saveLevel(string levelName)
{
	string _levelName = levelName;
	outputFile.open(_levelName);
	if (outputFile.fail())
	{
		// perror(_levelName);
		cout << "Perror here " << endl;

		// Chance to create a new file with given file name
		char playerChoice;
		cout << "Do you want to create a new file called " << _levelName << "? (Y/N)";
		cin >> playerChoice;
		// If player chooses no
		if (playerChoice == 'n' || playerChoice == 'N')
		{
			cout << "Saving failed." << endl;
			system("PAUSE");
			return;
		}

		// Create new file with given file name
		outputFile.open(_levelName);
		if (outputFile.fail())
		{
			//perror(_levelName);
			cout << "Perror here" << endl;
			return;
		}
		cout << "The file has been saved as " << _levelName << "." << endl;
		// system("PAUSE");
	}
	// Print currently loaded level to file
	for (int i = 0; i < levelStrings.size(); i++)
	{
		output = levelStrings[i];
		outputFile << output << endl;
	}
	// Clear loaded level
	levelStrings.clear();
	
	cout << "Save finished" << endl;
}

// Prints currently loaded level
void Level::printLevel()
{
	for (int i = 0; i < levelStrings.size(); i++)
	{
		cout << levelStrings[i] << endl;
	}
}