#include <stack>
#include <cstdlib>
#include <ctime>
#include "contols.h"
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

int eswn_rand(int max)
{ //return a random number in the range [1; 4]
    return (rand() % max) + 1;
} 

void maze_grid(int size, char** arr)
{
    //cell count
    int counter = 1;

    //consequtive moves of the maze-generating
    pair <int, int> consq_counter (0, 0); //first - direction; second - consequtive choices

    //assign a random value [0; 3] to a variable for the max consequrive moves
    srand(time(0));
    int max_consq = rand() % 4;

    // wall - x
    // path cell - y
    // end - z
    for (int i = 0; i < size; i++)
    {
        arr[0][i] = 'x';
        arr[i][0] = 'x';
        arr[size - 1][i] = 'x';
        arr[i][size - 1] = 'x';
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

    //random number generator variable
    int next_cell;

    //end value maze
    int max_maze = ((size - 2) / 2 + 1) * ((size - 2) / 2 + 1) - 1;

    //continues until all cells have been assigned a value
    while (counter <= max_maze)
    {
        if (counter == max_maze)
        {
            //assign end field's value
            arr[i][j] = 'z';
        }

        if (j < size - 2)
        if (arr[i][j + 2] != 'y' && arr[i][j + 2] != 'x') //East
        {
            available_arr[0] = true;
            av_check = true;
        }
        if (i < size - 2)
        if (arr[i + 2][j] != 'y' && arr[i + 2][j] != 'x') //South
        {
            available_arr[1] = true;
            av_check = true;
        }
        if (j > 1)
        if (arr[i][j - 2] != 'y' && arr[i][j - 2] != 'x') //West
        {
            available_arr[2] = true;
            av_check = true;
        }
        if (i > 1)
        if (arr[i - 2][j] != 'y' && arr[i - 2][j] != 'x') //North
        {
            available_arr[3] = true;
            av_check = true;
        }

        if (av_check == true)
        {
            // Choose one available neighbour at random
            srand(time(0));
            while (true) //break if the cell is available
            {
                next_cell = eswn_rand(4);
                //check if the cell is free
                if (available_arr[next_cell - 1] == true)
                {
                    //if the direction choice is different from the last choice
                    if (consq_counter.first != next_cell)
                    {
                        consq_counter.first = next_cell;
                        max_consq = (rand() % 3) + 1;
                        consq_counter.second = 1;
                        av_check = false;
                        break;
                    }
                    //if the direction choice is the same as the last one
                    else
                    {
                        //if the choice has been made less times than the max counter
                        if (consq_counter.second <= max_consq)
                        {
                            consq_counter.second++;
                            av_check = false;
                            break;
                        }
                        //if the choice has been made more times than the max allowed
                        else
                        {
                            available_arr[next_cell - 1] = false;
                            consq_counter.first = 0;
                            consq_counter.second = 0;
                            //check if backtracking is needed
                            if (available_arr[0] == false && available_arr[1] == false && available_arr[2] == false && available_arr[3] == false)
                            {
                                av_check = false;
                                break;
                            }
                        }
                    }
                }
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
                counter++;
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
                counter++;
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
                counter++;
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
                counter++;
                break;
            }

            //assign values to checker variables
            av_check = false;
            for (int i = 0; i < 4; i ++)
                available_arr[i] = false;
        }
        else
        {
            path.pop();
            //assign the previous cell's values to the coordinate variables
            if (!path.empty())
                assign_new_values(path.top(), i, j);
            else
                break;
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i][j] != 'y' && arr[i][j] != 'z')
                arr[i][j] = 'x';
        }
    }
}