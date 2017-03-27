#include "Level.h"



Level::Level()
{

}

void Level::processLevel(Player &player)
{
	for (int i = 0; i < levelStrings.size()-1; i++)
	{
		for (int j = 0; j < levelStrings[i].size()-1; j++)
		{
			if (levelStrings[i][j] == '@')
				player.initPlayer(i, j);
					//indsæt flere ting, eventuelt enemies
		}
	}
}

void Level::processPlayerMove(char &input, Player & player)
{
	int X = player.getPlayerX();
	int Y = player.getPlayerY();

	switch (input)
	{
	case 'W':
	case 'w':
		if (checkTile(Y - 1, X))
		{
			player.setPlayerY(Y - 1);
			player.setPlayerX(X);
			levelStrings[Y][X] = temp;
			temp = levelStrings[Y - 1][X];
			levelStrings[Y - 1][X] = '@';
		}
		break;

	case 'A':
	case 'a':
		if (checkTile(Y, X-1))
		{
			player.setPlayerY(Y);
			player.setPlayerX(X-1);
			levelStrings[Y][X] = temp;
			temp = levelStrings[Y][X - 1];
			levelStrings[Y][X-1] = '@';
		}
		break;

	case 'S':
	case 's':
		if (checkTile(Y + 1, X))
		{
			player.setPlayerY(Y + 1);
			player.setPlayerX(X);
			levelStrings[Y][X] = temp;
			temp = levelStrings[Y + 1][X];
			levelStrings[Y + 1][X] = '@';
		}
		break;

	case 'D':
	case 'd':
		if (checkTile(Y, X+1))
		{
			player.setPlayerY(Y);
			player.setPlayerX(X+1);
			levelStrings[Y][X] = temp;
			temp = levelStrings[Y][X + 1];
			levelStrings[Y][X+1] = '@';
		}
		break;
	default:
		break;
	}
}

bool Level::checkTile(int y, int x)
{
	if (levelStrings[y][x] == '.' || levelStrings[y][x] == '~')
		return true;
	//else if(levelStrings[y][x] == 'G')

	return false;
}

void Level::loadLevel(string levelName)
{
	string _levelName = levelName;
	inputFile.open(levelName);
	if (inputFile.fail())
	{
		perror("Level.txt");
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
	system("CLS");
	for (int i = 0; i < levelStrings.size(); i++)
	{
		cout << levelStrings[i] << endl;
	}
}