#pragma once
#include <stack>
#include <cstdlib>
#include <ctime>

void assign_new_values(const stack<pair<int, int>>& stack, int& i, int& j);

void check_path_cell(char** arr, const stack<pair<int, int>>& stack, int& i, int& j);

void maze_grid(int size, char** grid);