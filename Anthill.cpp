// Anthill.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <stack>

using namespace std;

/*
This method is used in when a
red army ant and a blue army ant
might end up in the same position.
It uses a random number generator
to decide which ant should land in
that position.
*/

string mover(string first, string next)
{
	int random = rand() % 2;
	if (random == 0)
	{
		return first;
	}
	else if (random == 1)
	{
		return next;
	}
}

/*
Method to find the width when the 
ant is at the left side of the array
*/

int leftWidth(int width)
{
	int random = rand() % 2;
	if (random == 0)
		return width;
	if (random == 1)
		return width + 1;

}

/*
Method to find the length when the ant
is at the top edge of the array
*/

int topLength(int length)
{
	int random = rand() % 2;
	if (random == 0)
		return length;
	if (random == 1)
		return length + 1;
}

/*
Method to find the width when the ant
is at the right edge of the array
*/

int rightWidth(int width)
{
	int random = rand() % 2;
	if (random == 0)
		return width;
	if (random == 1)
		return width - 1;
}

/*
Method to find the length when the ant is
at the bottom edge of the of the array
*/

int bottomLength(int length)
{
	int random = rand() % 2;
	if (random == 0)
		return length;
	if (random == 1)
		return length - 1;
}

/*
Method to find the new width of
the ant when it is on the top
or bottom edge of the array, but 
not on the corners.
*/

int edgeWidth(int width)
{
	int random = rand() % 3;
	if (random == 0)
		return width;
	if (random == 1)
		return width + 1;
	if (random == 2)
		return width - 1;
}

/*
Method to find the new length of
the ant when it is on the left
or right edge of the array, but 
not on the corners.
*/

int edgeLength(int length)
{
	int random = rand() % 3;
	if (random == 0)
		return length;
	if (random == 1)
		return length + 1;
	if (random == 2)
		return length - 1;
}

void tempDecrement(int counter)
{
	counter--;
}

void main()
{
	/*
	Creates the array where all the
	ants will be located. You can
	change the length and width in
	order to change the size of the
	array and also change the number
	of ants that will be present if
	the array works.
	*/

	int const length = 30;
	int const width = 30;
	int redCounter, blueCounter;
	redCounter = blueCounter = 30;
	int daysCount = 0;

	string kitchen[length][width];
	string temp;

	system("pause");

	for (int x = 0; x < length; x++)
	{
		for (int y = 0; y < width; y++)
			kitchen[x][y] = "X";
	}
	for (int x = 0; x < length; x++)
	{
		for (int y = 0; y < width; y++)
			cout << kitchen[x][y] << " ";
		cout << "\n";
	}
	system("pause");

	/*
	Places the ants where they should be,
	randomly puts them where they'll go.
	The red tend to end up on the left side
	and the right tend to end up on the left
	side.
	*/

	int r = 0;
	int b = 0;
	int lengthPlace;
	int widthPlace;

	while (r < redCounter)
	{
		int rand1 = rand() % width;
		int rand2 = rand() % (length / 2);
		if (kitchen[rand1][rand2] == "X")
		{
			kitchen[rand1][rand2] = "R";
			r++;
		}
	}

	while (b < blueCounter)
	{
		int rand1 = rand() % width;
		int rand2 = (length / 2) + rand() % (length / 2);
		if (kitchen[rand1][rand2] != "B")
		{
			kitchen[rand1][rand2] = "B";
			b++;
		}
	}
	while (redCounter != 0 || blueCounter != 0)
	{
		for (int x = 0; x < width; x++)
		{
			for (int y = 0; y < length; y++)
				cout << kitchen[x][y] << " ";
			cout << "\n";
		}
		system("pause");


		for (int x = 0; x < length; x++)
		{
			for (int y = 0; y < width; y++)
			{
				//cout << x << " " << y << "\n";

				/*
				Checks if the ant is in the red army
				and moves it accordingly
				*/

				if (kitchen[x][y] == "R")
				{
					if (x == 0 && y == 0)
					{
						lengthPlace = topLength(x);
						widthPlace = leftWidth(y);
						temp = kitchen[x][y];
						cout << "left corner "
							<< widthPlace << " "
							<< lengthPlace << "\n";
						if (kitchen[lengthPlace][widthPlace] == "B")
						{
							kitchen[lengthPlace][widthPlace] = mover("R", "B");
							if (kitchen[lengthPlace][widthPlace] == "R")
								blueCounter--;
							else if (kitchen[lengthPlace][widthPlace] == "B")
								redCounter--;
							kitchen[x][y] = "X";
						}
						else if (kitchen[lengthPlace][widthPlace] == "X")
						{
							kitchen[lengthPlace][widthPlace] == temp;
							kitchen[x][y] = "X";
						}

					}
					else if (x == 0 && y == width - 1)
					{
						lengthPlace = topLength(x);
						widthPlace = rightWidth(y);
						cout << "In right corner "
							<< widthPlace << " "
							<< lengthPlace << "\n";
						if (kitchen[lengthPlace][widthPlace] == "B")
						{
							kitchen[lengthPlace][widthPlace] = mover("R", "B");
							if (kitchen[lengthPlace][widthPlace] == "R")
								blueCounter--;
							else if (kitchen[lengthPlace][widthPlace] == "B")
								redCounter--;
							kitchen[x][y] = "X";
						}
						else if (kitchen[lengthPlace][widthPlace] == "X")
						{
							kitchen[lengthPlace][widthPlace] == temp;
							kitchen[x][y] = "X";
						}
					}
					else if (x == 0 && (y != 0 || y != width - 1))
					{
						lengthPlace = topLength(x);
						widthPlace = edgeWidth(y);
						cout << "On the top edge "
							<< widthPlace << " "
							<< lengthPlace << "\n";
						if (kitchen[lengthPlace][widthPlace] == "B")
						{
							kitchen[lengthPlace][widthPlace] = mover("R", "B");
							if (kitchen[lengthPlace][widthPlace] == "R")
								blueCounter--;
							else if (kitchen[lengthPlace][widthPlace] == "B")
								redCounter--;
							kitchen[x][y] = "X";
						}
						else if (kitchen[lengthPlace][widthPlace] == "X")
						{
							kitchen[lengthPlace][widthPlace] == temp;
							kitchen[x][y] = "X";
						}
					}
					else if (x == length - 1 && y == 0)
					{
						lengthPlace = bottomLength(x);
						widthPlace = leftWidth(y);
						cout << "On the bottom left "
							<< widthPlace << " "
							<< lengthPlace << "\n";
						if (kitchen[lengthPlace][widthPlace] == "B")
						{
							kitchen[lengthPlace][widthPlace] = mover("R", "B");
							if (kitchen[lengthPlace][widthPlace] == "R")
								blueCounter--;
							else if (kitchen[lengthPlace][widthPlace] == "B")
								redCounter--;
							kitchen[x][y] = "X";
						}
						else if (kitchen[lengthPlace][widthPlace] == "X")
						{
							kitchen[lengthPlace][widthPlace] == temp;
							kitchen[x][y] = "X";
						}
					}
					else if (x == length - 1 && y == width - 1)
					{
						lengthPlace = bottomLength(x);
						widthPlace = leftWidth(y);
						cout << "on the bottom right "
							<< widthPlace << " "
							<< lengthPlace << "\n";
						if (kitchen[lengthPlace][widthPlace] == "B")
						{
							kitchen[lengthPlace][widthPlace] = mover("R", "B");
							if (kitchen[lengthPlace][widthPlace] == "R")
								blueCounter--;
							else if (kitchen[lengthPlace][widthPlace] == "B")
								redCounter--;
							kitchen[x][y] = "X";
						}
						else if (kitchen[lengthPlace][widthPlace] == "X")
						{
							kitchen[lengthPlace][widthPlace] == temp;
							kitchen[x][y] = "X";
						}
					}
					else if (x == length - 1 && (y != 0 || y != width - 1))
					{
						lengthPlace = bottomLength(x);
						widthPlace = edgeWidth(y);
						cout << "on the bottom edge "
							<< widthPlace << " "
							<< lengthPlace << "\n";
						if (kitchen[lengthPlace][widthPlace] == "B")
						{
							kitchen[lengthPlace][widthPlace] = mover("R", "B");
							if (kitchen[lengthPlace][widthPlace] == "R")
								blueCounter--;
							else if (kitchen[lengthPlace][widthPlace] == "B")
								redCounter--;
							kitchen[x][y] = "X";
							blueCounter--;
						}
						else if (kitchen[lengthPlace][widthPlace] == "X")
						{
							kitchen[lengthPlace][widthPlace] == temp;
							kitchen[x][y] = "X";
						}
					}
					else if (y = 0 && (x != 0 || x != length - 1))
					{
						lengthPlace = edgeLength(x);
						widthPlace = leftWidth(y);
						cout << "On the left side "
							<< widthPlace << " "
							<< lengthPlace << "\n";
						if (kitchen[lengthPlace][widthPlace] == "B")
						{
							kitchen[lengthPlace][widthPlace] = mover("R", "B");
							if (kitchen[lengthPlace][widthPlace] == "R")
								blueCounter--;
							else if (kitchen[lengthPlace][widthPlace] == "B")
								redCounter--;
							kitchen[x][y] = "X";
						}
						else if (kitchen[lengthPlace][widthPlace] == "X")
						{
							kitchen[lengthPlace][widthPlace] == temp;
							kitchen[x][y] = "X";
						}
					}
					else if (y = width - 1 && (x != 0 || x != length - 1))
					{
						lengthPlace = edgeLength(x);
						widthPlace = rightWidth(y);
						cout << "On the right side "
							<< widthPlace << " "
							<< lengthPlace << "\n";
						if (kitchen[lengthPlace][widthPlace] == "B")
						{
							kitchen[lengthPlace][widthPlace] = mover("R", "B");
							if (kitchen[lengthPlace][widthPlace] == "R")
								blueCounter--;
							else if (kitchen[lengthPlace][widthPlace] == "B")
								redCounter--;
							kitchen[x][y] = "X";
						}
						else if (kitchen[lengthPlace][widthPlace] == "X")
						{
							kitchen[lengthPlace][widthPlace] == temp;
							kitchen[x][y] = "X";
						}
					}
				}

				/*
				Checks for if the object on the array is
				an blue army ant, and moves it accordingly
				*/

				if (kitchen[x][y] == "B")
				{
					if (x == 0 && y == 0)
					{
						lengthPlace = topLength(x);
						widthPlace = leftWidth(y);
						temp = kitchen[x][y];
						cout << "left corner "
							<< widthPlace << " "
							<< lengthPlace << "\n";
						if (kitchen[lengthPlace][widthPlace] == "R")
						{
							kitchen[lengthPlace][widthPlace] = mover("R", "B");
							if (kitchen[lengthPlace][widthPlace] == "R")
								blueCounter--;
							else if (kitchen[lengthPlace][widthPlace] == "B")
								redCounter--;
							kitchen[x][y] = "X";
						}
						else if (kitchen[lengthPlace][widthPlace] == "X")
						{
							kitchen[lengthPlace][widthPlace] == temp;
							kitchen[x][y] = "X";
						}

					}
					else if (x == 0 && y == width - 1)
					{
						lengthPlace = topLength(x);
						widthPlace = rightWidth(y);
						cout << "In right corner "
							<< widthPlace << " "
							<< lengthPlace << "\n";
						if (kitchen[lengthPlace][widthPlace] == "R")
						{
							kitchen[lengthPlace][widthPlace] = mover("R", "B");
							if (kitchen[lengthPlace][widthPlace] == "R")
								blueCounter--;
							else if (kitchen[lengthPlace][widthPlace] == "B")
								redCounter--;
							kitchen[x][y] = "X";
						}
						else if (kitchen[lengthPlace][widthPlace] == "X")
						{
							kitchen[lengthPlace][widthPlace] == temp;
							kitchen[x][y] = "X";
						}
					}
					else if (x == 0 && (y != 0 || y != width - 1))
					{
						lengthPlace = topLength(x);
						widthPlace = edgeWidth(y);
						cout << "On the top edge "
							<< widthPlace << " "
							<< lengthPlace << "\n";
						if (kitchen[lengthPlace][widthPlace] == "R")
						{
							kitchen[lengthPlace][widthPlace] = mover("R", "B");
							if (kitchen[lengthPlace][widthPlace] == "R")
								blueCounter--;
							else if (kitchen[lengthPlace][widthPlace] == "B")
								redCounter--;
							kitchen[x][y] = "X";
						}
						else if (kitchen[lengthPlace][widthPlace] == "X")
						{
							kitchen[lengthPlace][widthPlace] == temp;
							kitchen[x][y] = "X";
						}
					}
					else if (x == length - 1 && y == 0)
					{
						lengthPlace = bottomLength(x);
						widthPlace = leftWidth(y);
						cout << "On the bottom left "
							<< widthPlace << " "
							<< lengthPlace << "\n";
						if (kitchen[lengthPlace][widthPlace] == "R")
						{
							kitchen[lengthPlace][widthPlace] = mover("R", "B");
							if (kitchen[lengthPlace][widthPlace] == "R")
								blueCounter--;
							else if (kitchen[lengthPlace][widthPlace] == "B")
								redCounter--;
							kitchen[x][y] = "X";
						}
						else if (kitchen[lengthPlace][widthPlace] == "X")
						{
							kitchen[lengthPlace][widthPlace] == temp;
							kitchen[x][y] = "X";
						}
					}
					else if (x == length - 1 && y == width - 1)
					{
						lengthPlace = bottomLength(x);
						widthPlace = leftWidth(y);
						cout << "on the bottom right "
							<< widthPlace << " "
							<< lengthPlace << "\n";
						if (kitchen[lengthPlace][widthPlace] == "R")
						{
							kitchen[lengthPlace][widthPlace] = mover("R", "B");
							if (kitchen[lengthPlace][widthPlace] == "R")
								blueCounter--;
							else if (kitchen[lengthPlace][widthPlace] == "B")
								redCounter--;
							kitchen[x][y] = "X";
						}
						else if (kitchen[lengthPlace][widthPlace] == "X")
						{
							kitchen[lengthPlace][widthPlace] == temp;
							kitchen[x][y] = "X";
						}
					}
					else if (x == length - 1 && (y != 0 || y != width - 1))
					{
						lengthPlace = bottomLength(x);
						widthPlace = edgeWidth(y);
						cout << "on the bottom edge "
							<< widthPlace << " "
							<< lengthPlace << "\n";
						if (kitchen[lengthPlace][widthPlace] == "R")
						{
							kitchen[lengthPlace][widthPlace] = mover("R", "B");
							if (kitchen[lengthPlace][widthPlace] == "R")
								blueCounter--;
							else if (kitchen[lengthPlace][widthPlace] == "B")
								redCounter--;
							kitchen[x][y] = "X";
						}
						else if (kitchen[lengthPlace][widthPlace] == "X")
						{
							kitchen[lengthPlace][widthPlace] == temp;
							kitchen[x][y] = "X";
						}
					}
					else if (y = 0 && (x != 0 || x != length - 1))
					{
						lengthPlace = edgeLength(x);
						widthPlace = leftWidth(y);
						cout << "On the left side "
							<< widthPlace << " "
							<< lengthPlace << "\n";
						if (kitchen[lengthPlace][widthPlace] == "R")
						{
							kitchen[lengthPlace][widthPlace] = mover("R", "B");
							if (kitchen[lengthPlace][widthPlace] == "R")
								blueCounter--;
							else if (kitchen[lengthPlace][widthPlace] == "B")
								redCounter--;
							kitchen[x][y] = "X";
						}
						else if (kitchen[lengthPlace][widthPlace] == "X")
						{
							kitchen[lengthPlace][widthPlace] == temp;
							kitchen[x][y] = "X";
						}
					}
					else if (y = width - 1 && (x != 0 || x != length - 1))
					{
						lengthPlace = edgeLength(x);
						widthPlace = rightWidth(y);
						cout << "On the right side "
							<< widthPlace << " "
							<< lengthPlace << "\n";
						if (kitchen[lengthPlace][widthPlace] == "R")
						{
							kitchen[lengthPlace][widthPlace] = mover("R", "B");
							if (kitchen[lengthPlace][widthPlace] == "R")
								blueCounter--;
							else if (kitchen[lengthPlace][widthPlace] == "B")
								redCounter--;
							kitchen[x][y] = "X";
							redCounter--;
						}
						else if (kitchen[lengthPlace][widthPlace] == "X")
						{
							kitchen[lengthPlace][widthPlace] == temp;
							kitchen[x][y] = "X";
						}
					}
				}
			}
			//cout << "\n";
			daysCount++;

			if (daysCount % 10 == 0)
			{

				for (int x = 0; x < length; x++)
				{
					for (int y = 0; y < width; y++)
						cout << kitchen[x][y] << " ";
					cout << "\n";
				}
				cout << redCounter << " red ants left" << "\n";
				cout << blueCounter << " blue ants left" << "\n";
				system("pause");
			}

		}
	}


	for (int x = 0; x < length; x++)
	{
		for (int y = 0; y < width; y++)
			cout << kitchen[x][y] << " ";
		cout << "\n";
	}
	cout << redCounter << " red ants left" << "\n";
	cout << blueCounter << " blue ants left" << "\n";
	system("pause");


}

