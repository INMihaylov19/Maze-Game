#pragma once
#include <stack>
#include <cstdlib>
#include <ctime>
using namespace std;

void assign_new_values(pair<int, int> pair, int& i, int& j);

void check_path_cell(char** arr, pair<int, int> pair, int& i, int& j);

void maze_grid(int size, char** grid);