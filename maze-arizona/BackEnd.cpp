#include <stack>
#include <cstdlib>
#include <ctime>
using namespace std;

void assign_new_values(const stack<pair<int, int>>& stack, int& i, int& j)
{ //assign the new cell's values to the coordinate variables
	i = stack.top().first;
	j = stack.top().second;
}

void check_path_cell(char** arr, const stack<pair<int, int>>& stack, int& i, int& j)
{ //make the cell between the two filled cells a path cell
    if (i == stack.top().first) //if it's on the same row
    {
        if (j + 2 == stack.top().second) //if it's after (right) the current cell
            arr[stack.top().first][j + 1] = 'y';

        else if (j - 2 == stack.top().second) //if it's before (left) the current cell
            arr[stack.top().first][j - 1] = 'y';
    }
    else if (j == stack.top().second) // if it's in the same column
    {
        if (i + 2 == stack.top().first) //if it's above the current cell
            arr[i + 1][stack.top().second] = 'y';

        else if (i - 2 == stack.top().first) //if it's below the current cell
            arr[i - 1][stack.top().second] = 'y';
    }
}

void maze_grid(int size, char** arr)
{
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
    bool available_arr[4] = { false, false, false, false };

    //the path used for backtracking
    stack<pair<int, int>> path;

    //coordinates
    int i = 1; int j = 1;

    //continues until all cells have been assigned a value
    while (counter != size*size)
    {
        if (arr[i][j + 2] != 'y' && arr[i][j + 2] != 'x') //East
        {
            available.push({ i, j + 2 });
            available_arr[0] = true;
        }
        if (arr[i + 2][j] != 'y' && arr[i + 2][j] != 'x') //South
        {
            available.push({ i + 2, j });
            available_arr[1] = true;
        }
        if (j > 1 && arr[i][j - 2] != 'y' && arr[i][j - 2] != 'x') //West
        {
            available.push({ i, j - 2 });
            available_arr[2] = true;
        }
        if (i > 1 && arr[i - 2][j] != 'y' && arr[i - 2][j] != 'x') //North
        {
            available.push({ i - 2, j });
            available_arr[3] = true;
        }

        if (!available.empty())
        {
            // Choose one available neighbour at random
            srand((unsigned)time(0));
            int next_cell;
            while (true) //break if the cell is available
            {
                next_cell = (rand() % 4) + 1;
                if (available_arr[next_cell - 1])
                    break;
            }

            // Create a path between the neighbour and the current cell
            switch (next_cell)
            {
            case 1: // East
                arr[i][j + 2] = 'y';

                //make the cell between the two filled cells a path cell
                check_path_cell(arr, available, i, j);

                //assign the new cell's values to the coordinate variables
                assign_new_values(available, i, j);

                path.push({ i, j + 2 });
                counter += 2;
                break;

            case 2: // South
                arr[i + 2][j] = 'y';

                //make the cell between the two filled cells a path cell
                check_path_cell(arr, available, i, j);

                //assign the new cell's values to the coordinate variables
                assign_new_values(available, i, j);

                path.push({ i + 2, j });
                counter += 2;
                break;

            case 3: // West
                arr[i][j - 2] = 'y';

                //make the cell between the two filled cells a path cell
                check_path_cell(arr, available, i, j);

                //assign the new cell's values to the coordinate variables
                assign_new_values(available, i, j);

                path.push({ i, j - 2 });
                counter += 2;
                break;

            case 4: // North
                arr[i - 2][j] = 'y';

                //make the cell between the two filled cells a path cell
                check_path_cell(arr, available, i, j);

                //assign the new cell's values to the coordinate variables
                assign_new_values(available, i, j);

                path.push({ i - 2, j });
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

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (int(arr[i][j]) == 0)
                arr[i][j] = 'x';
        }
    }
}