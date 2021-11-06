#include <iostream>
#include "BackEnd.h"

using namespace std;

const char field = '*';

void check(int size) // checks where to put a square or empty space
{
	//declare the grid for the maze
	char** grid = new char* [size];
	for (int i = 0; i < size; i++)
	{
		grid[i] = new char[size];
	}

	maze_grid(size, grid);

	//print the maze
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (grid[i][j] == 'x')
			{
				cout << field;
			}
			else if (grid[i][j] == 'y')
			{
				cout << " ";
			}
			/*else
			{
				cout << " ";
			}*/
		}
		cout << endl;
	}

	//deallocate memory
	for (int i = 0; i < size; i++)
		delete[] grid[i];
	delete[] grid;
}



