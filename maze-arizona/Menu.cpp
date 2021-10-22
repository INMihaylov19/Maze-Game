#include <iostream>  
#include <windows.h>
#include <conio.h>
#include "Menu.h"
#include "controls.h"
#include "Rules.h"
using namespace std;


void menuArt()
{
    gotoxy(40, 3); color(SetColor[0]); cout << "================================";
    gotoxy(40, 4); color(SetColor[1]); cout << " __  __   _____   _   _   _   _";
    gotoxy(40, 5); color(SetColor[1]); cout << "|  \\/  | |  ___| | \\ | | | | | |";
    gotoxy(40, 6); color(SetColor[1]); cout << "| .  . | | |__   |  \\| | | | | |";
    gotoxy(40, 7); color(SetColor[1]); cout << "| |\\/| | |  __|  | . ` | | | | |";
    gotoxy(40, 8); color(SetColor[1]); cout << "| |  | | | |___  | |\\  | | |_| |";
    gotoxy(40, 9); color(SetColor[1]); cout << "\\_|  |_/ \\____/  \\_| \\_/  \\___/";
    gotoxy(40, 11); color(SetColor[1]); cout << "================================";
}

int Menu()
{
    int counter = 1;
    char key;

    menuArt();


    for (int i = 0;;)
    {
        gotoxy(48, 13); color(SetColor[0]); cout << "1. Get started ";

        gotoxy(48, 14); color(SetColor[1]); cout << "2. Rules ";

        gotoxy(48, 15); color(SetColor[2]); cout << "3. Exit " << endl; color(SetColor[0]);

        key = _getch();

        if (key == 72 && (counter >= 2 && counter <= 3)) // 72 is the ASCII code for the up arrow
        {
            counter--;
        }
        if (key == 80 && (counter >= 1 && counter <= 2)) // 80 is the ASCII code for the up arrow
        {
            counter++;
        }
        if (key == '\r') // enter key
        {
            if (counter == 1)
            {
                system("CLS");
                //maze();
                break;
            }
            if (counter == 2)
            {
                system("CLS");
                rules();
                break;
            }
            if (counter == 3)
            {
                return 0;
            }
        }

        SetColor[0] = 7;
        SetColor[1] = 7;
        SetColor[2] = 7;

        if (counter == 1) { SetColor[0] = 13; }
        if (counter == 2) { SetColor[1] = 13; }
        if (counter == 3) { SetColor[2] = 13; }
    }
}