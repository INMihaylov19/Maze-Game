#include <iostream>
#include "BackEnd.h"

using namespace std;

const char field = char(219);

void check(int size) // checks where to put a square or empty space
{
	//declare the grid for the maze
	int** grid = new int* [size];

	maze_grid(size, grid);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (grid[i][j] == 2)
			{
				cout << field << field;
			}
		}
		cout << endl;
	}
}



