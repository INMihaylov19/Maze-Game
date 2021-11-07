#include <conio.h>
#include <iostream>
#include <windows.h>
#include "controls.h"
#include "Menu.h"
using namespace std;

#define KEY_UP    72
#define KEY_LEFT  75
#define KEY_RIGHT 77
#define KEY_DOWN  80

#define RESET   "\033[0m"
#define RED     "\033[1;91m" 
#define GREEN   "\033[1;92m" 
#define YELLOW  "\033[1;93m"
#define BLUE    "\033[1;96m"
#define PURPLE  "\033[1;95m"
#define WHITE   "\033[4;37m"

//player character
const char Player = 'O';

int SetColor[3] = { 13, 7, 7 };

void color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y)
{ //get the coordinates inside the console
    COORD coord;
    coord.X = x; //character's X cordinates
    coord.Y = y; //character's Y cordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void controls(char **arr, int size)
{
    int x, y, lastX, lastY;

    //current and previous coodrinates
    x = 1; lastX = x;
    y = 1; lastY = y;

    bool loop = true;

    while (loop)
    {
        char movement;
        //go to lastX and lastY and clear old O
        gotoxy(lastX, lastY);
        cout << " ";

        //draw new O
        gotoxy(x, y);
        cout << YELLOW; cout << Player; cout << RESET;

        // remember old x and y
        lastX = x; lastY = y;

        movement = _getch();
     
        //get input from the keyboard
        switch (movement)
        {
        case KEY_UP:
            if (y > 0 && arr[y - 1][x] == 'y')
                y--;
            else if (y > 0 && arr[y - 1][x] == 'z')
            {
                y--;
                system("CLS");
                winMessage();
                loop = false;
            }
            break;
        case KEY_DOWN:
            if (y < size - 1 && arr[y + 1][x] == 'y')
                y++;
            else if (y < size - 1 && arr[y + 1][x] == 'z')
            {
                y++;
                system("CLS");
                winMessage();
                loop = false;
            }
            break;
        case KEY_LEFT:
            if (x > 0 && arr[y][x - 1] == 'y')
                x--;
            else if (x > 0 && arr[y][x - 1] == 'z')
            {
                x--;
                system("CLS");
                winMessage();
                loop = false;
            }
            break;
        case KEY_RIGHT:
            if (x < size - 1 && arr[y][x + 1] == 'y')
                x++;
            else if (x < size - 1 && arr[y][x + 1] == 'z')
            {
                x++;
                system("CLS");
                winMessage();
                loop = false;
            }
            break;
        }
    }
}