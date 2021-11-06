#include <iostream>  
#include <windows.h>
#include <conio.h>
#include "FrontEnd.h"
#include "Menu.h"
#include "controls.h"
#include "Rules.h"
using namespace std;


void menuArt()
{
    gotoxy(40, 3); cout << "================================";
    gotoxy(40, 4); cout << " __  __   _____   _   _   _   _";
    gotoxy(40, 5); cout << "|  \\/  | |  ___| | \\ | | | | | |";
    gotoxy(40, 6); cout << "| .  . | | |__   |  \\| | | | | |";
    gotoxy(40, 7); cout << "| |\\/| | |  __|  | . ` | | | | |";
    gotoxy(40, 8); cout << "| |  | | | |___  | |\\  | | |_| |";
    gotoxy(40, 9); cout << "\\_|  |_/ \\____/  \\_| \\_/  \\___/";
    gotoxy(40, 11); cout << "================================";
}

void choice()
{
    int choiceCount = 1;
    char choice;

    for (int i = 0;;)
    {
        gotoxy(48, 13); color(SetColor[0]); cout << "1. 10x10 "; color(SetColor[1]);

        gotoxy(48, 14); color(SetColor[1]); cout << "2. 20x20 "; color(SetColor[1]);

        gotoxy(48, 15); color(SetColor[2]); cout << "3. 30x30 " << endl; color(SetColor[0]);

        choice = _getch();

        if (choice == 72 && (choiceCount >= 2 && choiceCount <= 3)) // 72 is the ASCII code for the up arrow
        {
            choiceCount--;
        }
        if (choice == 80 && (choiceCount >= 1 && choiceCount <= 2)) // 80 is the ASCII code for the up arrow
        {
            choiceCount++;
        }
        if (choice == '\r') // enter key
        {
            if (choiceCount == 1)
            {
                //display the 10x10 grid
                system("CLS");
                check(11);
                break;
            }
            if (choiceCount == 2)
            {
                //display the 20x20 grid
                system("CLS");
                check(21);
                break;
            }
            if (choiceCount == 3)
            {
                //display the 30x30 grid
                system("CLS");
                check(31);
                break;
            }
        }

        SetColor[0] = 7;
        SetColor[1] = 7;
        SetColor[2] = 7;

        if (choiceCount == 1) { SetColor[0] = 13; }
        if (choiceCount == 2) { SetColor[1] = 13; }
        if (choiceCount == 3) { SetColor[2] = 13; }

    }

}

int Menu()
{
    int counter = 1;
    char key;

    menuArt();


    for (int i = 0;;)
    {
        gotoxy(48, 13); color(SetColor[0]); cout << "1. Get started "; color(SetColor[2]);

        gotoxy(48, 14); color(SetColor[1]); cout << "2. Rules "; color(SetColor[2]);

        gotoxy(48, 15); color(SetColor[2]); cout << "3. Exit " << endl; color(SetColor[2]);

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
                choice();
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