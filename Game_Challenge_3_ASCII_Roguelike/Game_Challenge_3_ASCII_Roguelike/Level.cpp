#include "Level.h"



Level::Level()
{

}

void Level::processLevel(Player &player, Monster &monster)
{
	for (int i = 0; i < levelStrings.size() - 1; i++)
	{
		for (int j = 0; j < levelStrings[i].size() - 1; j++)
		{
			if (levelStrings[i][j] == '@')
				player.initPlayer(i, j);
			else if (levelStrings[i][j] == 'G')
				monster.initPlayer(i, j);
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
		if (checkTile(Y, X - 1))
		{
			player.setPlayerY(Y);
			player.setPlayerX(X - 1);
			levelStrings[Y][X] = temp;
			temp = levelStrings[Y][X - 1];
			levelStrings[Y][X - 1] = '@';
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
		if (checkTile(Y, X + 1))
		{
			player.setPlayerY(Y);
			player.setPlayerX(X + 1);
			levelStrings[Y][X] = temp;
			temp = levelStrings[Y][X + 1];
			levelStrings[Y][X + 1] = '@';
		}
		break;
	default:
		break;
	}
}

void Level::processMonsterMove(Monster & monster, Player & player)
{
	int playerX = player.getPlayerX();
	int playerY = player.getPlayerY();
	int monsterX = monster.getPlayerX();
	int monsterY = monster.getPlayerY();

	int Y = monsterY;
	int X = monsterX;

	int dx = abs(playerX - monsterX);
	int dy = abs(playerY - monsterY);

	char input;

	dx *= dx;
	dy *= dy;

	double d = sqrt(dx + dy);

	

	if (d < 5)// && monsterCanSeePlayer(monsterX, monsterY, playerX, playerY))
	{
		if (monsterX < playerX)
			input = 'd';
		else if (monsterY < playerY)
			input = 's';
		else if (monsterX > playerX)
			input = 'a';
		else
			input = 'w';

		switch (input)
		{
		case 'W':
		case 'w':
			if (checkTile(Y - 1, X))
			{
				monster.setPlayerY(Y - 1);
				monster.setPlayerX(X);
				levelStrings[Y][X] = temp;
				temp = levelStrings[Y - 1][X];
				levelStrings[Y - 1][X] = 'G';
			}
			break;

		case 'A':
		case 'a':
			if (checkTile(Y, X - 1))
			{
				monster.setPlayerY(Y);
				monster.setPlayerX(X - 1);
				levelStrings[Y][X] = temp;
				temp = levelStrings[Y][X - 1];
				levelStrings[Y][X - 1] = 'G';
			}
			break;

		case 'S':
		case 's':
			if (checkTile(Y + 1, X))
			{
				monster.setPlayerY(Y + 1);
				monster.setPlayerX(X);
				levelStrings[Y][X] = temp;
				temp = levelStrings[Y + 1][X];
				levelStrings[Y + 1][X] = 'G';
			}
			break;

		case 'D':
		case 'd':
			if (checkTile(Y, X + 1))
			{
				monster.setPlayerY(Y);
				monster.setPlayerX(X + 1);
				levelStrings[Y][X] = temp;
				temp = levelStrings[Y][X + 1];
				levelStrings[Y][X + 1] = 'G';
			}
			break;
		}
	}
}

bool Level::monsterCanSeePlayer(int x1, int y1, int x2, int y2)
{
	/*int x = x1;
	int y = y1;
	int w = x2 - x;
	int h = y2 - y;
	int dx1 = 0, dy1 = 0, dx2 = 0, dy2 = 0;
	if (w<0) dx1 = -1; else if (w>0) dx1 = 1;
	if (h<0) dy1 = -1; else if (h>0) dy1 = 1;
	if (w<0) dx2 = -1; else if (w>0) dx2 = 1;
	int longest = abs(w);
	int shortest = abs(h);
	if (!(longest>shortest)) {
		longest = abs(h);
		shortest = abs(w);
		if (h<0) dy2 = -1; else if (h>0) dy2 = 1;
		dx2 = 0;
	}
	int numerator = longest >> 1;
	for (int i = 0; i <= longest; i++) {
		if (!checkTile(y,x))
			return false;
		numerator += shortest;
		if (!(numerator<longest)) {
			numerator -= longest;
			x += dx1;
			y += dy1;
		}
		else {
			x += dx2;
			y += dy2;
		}
	}
	return true;*/
	//float deltax = x1 - x0;
	//float deltay = y1 - y0;
	//float deltaerr = abs(deltay / deltax);    // Assume deltax != 0 (line is not vertical),
	//											  // note that this division needs to be done in a way that preserves the fractional part
	//float error = deltaerr - 0.5;
	//int y = y0;
	//if (deltax == 0 && y0 < y1)
	//{
	//	for (int i = y0 + 1; i < y1; i++)
	//		if (!checkTile(i, x0))
	//			return false;
	//}
	//else if (deltax == 0 && y0 > y1)
	//{
	//	for (int i = y1 + 1; i < y0; i++)
	//		if (!checkTile(i, x0))
	//			return false;
	//}

	//if (x1 < x0)
	//{
	//	for (int x = x0; x < x1; x++)
	//	{
	//		if (!checkTile(y, x))
	//		{
	//			return false;
	//		}
	//		error = error + deltaerr;
	//		if (error >= 0.5)
	//		{
	//			y = y + 1;
	//			error = error - 1.0;
	//		}
	//	}
	//}
	//else
	//{
	//	for (int x = x1; x < x0; x++)
	//	{
	//		if (!checkTile(y, x))
	//		{
	//			return false;
	//		}
	//		error = error + deltaerr;
	//		if (error >= 0.5)
	//		{
	//			y = y + 1;
	//			error = error - 1.0;
	//		}
	//	}
	//}
	//return true;
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