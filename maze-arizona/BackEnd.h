#pragma once
#include <stack>
#include <cstdlib>
#include <ctime>
using namespace std;

void assign_new_values(pair<int, int> pair, int& i, int& j);

void check_path_cell(char** arr, int size, pair<int, int> pair, int& i, int& j);

int eswn_rand(int max);

void maze_grid(int size, char** arr);