#include <stdlib.h>
#include<time.h>
#include <string>
using namespace std;

void random (int* i, int* j)
{
	srand(time(NULL));
	/* false - horizontal
	* true - vertical
	*/
	bool r = rand() % 2 ? false : true;

	if (r)
		rand() % 2 ? i-1 : i+1;
	else
		rand() % 2 ? j-1 : j+1;
}

void maze_grid(int size, int** grid)
{
	for (int i = 0; i < size; i++)
	{
		grid[i] = new int[size];
	}

	//set values
	/* 0 - the algorithm still hasn't gone through the cell
	* 1 - path
	* 2 - wall
	*/
	for (int i = 1; i < size - 1; i++)
		for (int j = 1; j < size - 1; j++)
			grid[i][j] = 0;
	
	for (int i = 0; i < size; i++)
	{
		grid[0][i] = 2;
		grid[size - 1][i] = 2;
		grid[i][0] = 2;
		grid[i][size - 1] = 2;
	}

	int *tempi = new int, *tempj = new int;
	//tuka cikula ima malko da se doizmisli mai (da produlji ot poziciqta na koqto e otishlo)
	for (int i = 1; i < size - 1; i++)
		for (int j = 1; j < size - 1; j++)
		{
			//sloji gi v assignovete na grida
			*tempi = i;
			*tempj = j;
			random(&i, &j);
			grid[i][j] = 1;
			//assign values to walls
			grid[i - 1][j - 1] != 1 ? grid[i - 1][j - 1] = 2 : grid[i][j]; //up left
			grid[i - 1][j    ] != 1 ? grid[i - 1][j    ] = 2 : grid[i][j]; //up center
			grid[i - 1][j + 1] != 1 ? grid[i - 1][j + 1] = 2 : grid[i][j]; //up right
			grid[i    ][j - 1] != 1 ? grid[i    ][j - 1] = 2 : grid[i][j]; //center left
			grid[i    ][j + 1] != 1 ? grid[i    ][j + 1] = 2 : grid[i][j]; //center right
			grid[i + 1][j - 1] != 1 ? grid[i + 1][j - 1] = 2 : grid[i][j]; //down left
			grid[i + 1][j    ] != 1 ? grid[i + 1][j    ] = 2 : grid[i][j]; //down center
			grid[i + 1][j + 1] != 1 ? grid[i + 1][j + 1] = 2 : grid[i][j]; //down right
		}

	//deallocate memory
	delete tempi;
	delete tempj;

	for (int i = 0; i < size; i++)
		delete[] grid[i];
	delete[] grid;
}