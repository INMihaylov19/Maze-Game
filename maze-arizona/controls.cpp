#include <conio.h>
#include <iostream>
#include <windows.h>
#include "controls.h"
using namespace std;

#define KEY_UP    72
#define KEY_LEFT  75
#define KEY_RIGHT 77
#define KEY_DOWN  80

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

void controls()
{
    int character, arrow;

    while (true)
    {
        character = _getch();

        if (character && character != 224)
        {
            cout << endl << "Not arrow: " << (char)character << endl;
        }
        else
        {
            switch (arrow = _getch())
            {
            case KEY_UP:
                cout << endl << "Up" << endl;//key up
                break;
            case KEY_DOWN:
                cout << endl << "Down" << endl;   // key down
                break;
            case KEY_LEFT:
                cout << endl << "Left" << endl;  // key left
                break;
            case KEY_RIGHT:
                cout << endl << "Right" << endl;  // key right
                break;
            default:
                cout << endl << (char)arrow << endl;  // not arrow
                break;
            }
        }
    }
}