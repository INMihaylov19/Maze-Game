#include <stack>
#include <cstdlib>
#include <ctime>
using namespace std;

void assign_new_values(pair<int, int> pair, int& i, int& j)
{ //assign the new cell's values to the coordinate variables
	i = pair.first;
	j = pair.second;
}

void check_path_cell(char** arr, int size, pair<int, int> pair, int& i, int& j)
{ //make the cell between the two filled cells a path cell
    if (i == pair.first) //if it's on the same row
    {
        if (j < size - 1 && j + 2 == pair.second) //if it's after (right) the current cell
            arr[pair.first][j + 1] = 'y';

        else if (j > 1 && j - 2 == pair.second) //if it's before (left) the current cell
            arr[pair.first][j - 1] = 'y';
    }
    else if (j == pair.second) // if it's in the same column
    {
        if (i < size -1 && i + 2 == pair.first) //if it's above the current cell
            arr[i + 1][pair.second] = 'y';

        else if (i > 1 && i - 2 == pair.first) //if it's below the current cell
            arr[i - 1][pair.second] = 'y';
    }
}

void maze_grid(int size, char** arr)
{
    //cell count
    int counter = 0;

    // wall - x
    // path cell - y
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
    pair<int, int> available;
    bool available_arr[4] = { false, false, false, false };
    bool av_check = false;

    //the path used for backtracking
    stack<pair<int, int>> path;

    //coordinates
    int i = 1; int j = 1;

    //continues until all cells have been assigned a value
    while (counter != size*size)
    {
        if (j < size - 1 && arr[i][j + 2] != 'y' && arr[i][j + 2] != 'x') //East
        {
            available_arr[0] = true;
            av_check = true;
        }
        if (i < size - 1 && arr[i + 2][j] != 'y' && arr[i + 2][j] != 'x') //South
        {
            available_arr[1] = true;
            av_check = true;
        }
        if (j > 1 && arr[i][j - 2] != 'y' && arr[i][j - 2] != 'x') //West
        {
            available_arr[2] = true;
            av_check = true;
        }
        if (i > 1 && arr[i - 2][j] != 'y' && arr[i - 2][j] != 'x') //North
        {
            available_arr[3] = true;
            av_check = true;
        }

        if (av_check) //
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

                available.first = i;
                available.second = j + 2;

                //make the cell between the two filled cells a path cell
                check_path_cell(arr, size, available, i, j);

                //assign the new cell's values to the coordinate variables
                assign_new_values(available, i, j);

                path.push(available);
                counter += 2;
                break;

            case 2: // South
                arr[i + 2][j] = 'y';

                available.first = i + 2;
                available.second = j;

                //make the cell between the two filled cells a path cell
                check_path_cell(arr, size, available, i, j);

                //assign the new cell's values to the coordinate variables
                assign_new_values(available, i, j);

                path.push(available);
                counter += 2;
                break;

            case 3: // West
                arr[i][j - 2] = 'y';

                available.first = i;
                available.second = j - 2;

                //make the cell between the two filled cells a path cell
                check_path_cell(arr, size, available, i, j);

                //assign the new cell's values to the coordinate variables
                assign_new_values(available, i, j);

                path.push(available);
                counter += 2;
                break;

            case 4: // North
                arr[i - 2][j] = 'y';

                available.first = i - 2;
                available.second = j;

                //make the cell between the two filled cells a path cell
                check_path_cell(arr, size, available, i, j);

                //assign the new cell's values to the coordinate variables
                assign_new_values(available, i, j);

                path.push(available);
                counter += 2;
                break;
            }

            av_check = false;
        }
        else
        {
            path.pop();
            //assign the previous cell's values to the coordinate variables
            assign_new_values(path.top(), i, j);
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