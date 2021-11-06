#include <conio.h>
#include <iostream>
#include <windows.h>
#include "controls.h"
using namespace std;

#define KEY_UP    72
#define KEY_LEFT  75
#define KEY_RIGHT 77
#define KEY_DOWN  80

const char Player = char(234);

int SetColor[3] = { 13, 7, 7 };

void color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x; // your X cordinates
    coord.Y = y; // your Y cordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void controls(char **arr)
{
    int character, arrow;

    int x, y, lastX, lastY;

    x = 1; lastX = x;
    y = 1; lastY = y;

    /* start an Infinite Loop */

    while (true)
    {
        /* Head to LastX and LastY and clear old O*/
        gotoxy(lastX, lastY);
        cout << " ";
        /* Draw New O */
        gotoxy(x, y);
        cout << Player;
        /* Remember Old X and Y */
        lastX = x; lastY = y;
     
            switch (_getch())
            {
            case KEY_UP:
                if (arr[x][y] == 'y')
                    y--;
                break;
            case KEY_DOWN:
                if (arr[x][y] == 'y')
                    y++;
                break;
            case KEY_LEFT:
                if (arr[x][y] == 'y')
                    x--;
                break;
            case KEY_RIGHT:
                if (arr[x][y] == 'y')
                    x++;
                break;
            }
        }
    }