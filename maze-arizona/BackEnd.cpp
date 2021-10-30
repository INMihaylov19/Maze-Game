#include <stack>
#include <cstdlib>
using namespace std;

void assign_new_values(const stack<pair<int, int>>& stack, int& i, int& j)
{ //assign the new cell's values to the coordinate variables
	i = stack.top().first;
	j = stack.top().second;
}

void check_path_cell(char** arr, const stack<pair<int, int>>& stack, int& i, int& j)
{ //make the cell between the two filled cells a path cell
    if (i == stack.top().first)
    {
        if (j + 2 == stack.top().second)
            arr[stack.top().first][stack.top().second + 1] = 'y';
        else if (j - 2 == stack.top().second)
            arr[stack.top().first][stack.top().second - 1] = 'y';
    }
    else if (j == stack.top().second)
    {
        if (i + 2 == stack.top().first)
            arr[stack.top().first + 1][stack.top().second] = 'y';
        else if (i - 2 == stack.top().first)
            arr[stack.top().first - 1][stack.top().second] = 'y';
    }
}

void maze_grid(int size, int** grid)
{
    int size = 10;

    char** arr = new char* [size];
    for (int i = 0; i < size; i++)
        arr[i] = new char[size];

    //cell count
    int counter = 0;

    // stena - x
    // zapulnena kletka - y
    for (int i = 0; i < size; i++)
    {
        arr[0][i] = 'x';
        arr[i][0] = 'x';
        arr[size - 1][i] = 'x';
        arr[i][size - 1] = 'x';
        counter += 4;
    }
    arr[1][1] = 'y';

    //available spaces around current cell
    stack<pair<int, int>> available;

    //the path used for backtracking
    stack<pair<int, int>> path;

    //coordinates
    int i = 1; int j = 1;

    //continues until all cells have been assigned a value
    while (counter != (size - 1) * size + size)
    {
        if (arr[i][j + 2] != 'y' && arr[i][j + 2] != 'x')
            available.push({ i, j + 2 });
        if (arr[i + 2][j] != 'y' && arr[i + 2][j] != 'x')
            available.push({ i + 2, j });
        if (arr[i - 2][j] != 'y' && arr[i - 2][j] != 'x')
            available.push({ i - 2, j });
        if (arr[i][j - 2] != 'y' && arr[i][j - 2] != 'x')
            available.push({ i, j - 2 });

        if (!available.empty())
        {
            // Choose one available neighbour at random
            int next_cell = rand() % available.size();

            // Create a path between the neighbour and the current cell
            switch (next_cell)
            {
            case 0: // East
                arr[available.top().first][available.top().second] = 'y';

                //make the cell between the two filled cells a path cell
                check_path_cell(arr, available, i, j);

                //assign the new cell's values to the coordinate variables
                assign_new_values(available, i, j);

                path.push(available.top());
                counter += 2;
                break;

            case 1: // South
                available.pop();
                arr[available.top().first][available.top().second] = 'y';

                //make the cell between the two filled cells a path cell
                check_path_cell(arr, available, i, j);

                //assign the new cell's values to the coordinate variables
                assign_new_values(available, i, j);

                path.push(available.top());
                counter += 2;
                break;

            case 2: // West
                available.pop();
                available.pop();
                arr[available.top().first][available.top().second] = 'y';

                //make the cell between the two filled cells a path cell
                check_path_cell(arr, available, i, j);

                //assign the new cell's values to the coordinate variables
                assign_new_values(available, i, j);

                path.push(available.top());
                counter += 2;
                break;

            case 3: // North
                available.pop();
                available.pop();
                available.pop();
                arr[available.top().first][available.top().second] = 'y';

                //make the cell between the two filled cells a path cell
                check_path_cell(arr, available, i, j);

                //assign the new cell's values to the coordinate variables
                assign_new_values(available, i, j);

                path.push(available.top());
                counter += 2;
                break;
            }

            available.empty();
        }
        else
        {
            path.pop();
            //assign the previous cell's values to the coordinate variables
            assign_new_values(path, i, j);
        }
    }
}