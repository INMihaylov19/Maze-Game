#include <iostream>
#include "BackEnd.h"
#include "controls.h"

using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[1;91m" 
#define GREEN   "\033[1;92m" 
#define YELLOW  "\033[1;93m"
#define BLUE    "\033[1;96m"
#define PURPLE  "\033[1;95m"
#define WHITE   "\033[4;37m"

//the character used for printing the walls of the maze
const char field = 'X';

void check(int size) //checks where to put a square or empty space
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
				cout << BLUE;
				cout << field;
				cout << RESET;
			}
			else if (grid[i][j] == 'y')
			{
				cout << " ";
			}
		}
		cout << endl;
	}

	//add the moving character
	controls(grid, size);

	//deallocate memory
	for (int i = 0; i < size; i++)
		delete[] grid[i];
	delete[] grid;
}



