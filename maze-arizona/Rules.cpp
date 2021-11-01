#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Menu.h"
#include "controls.h"
#include "Rules.h"

using namespace std;



void rules()
{
    char back;

    gotoxy(38, 3); cout << "=======================================";
    gotoxy(38, 4); cout << " _____   _   _   _       _____   _____ ";
    gotoxy(38, 5); cout << "| ___ \\ | | | | | |     |  ___| /  ___|";
    gotoxy(38, 6); cout << "| |_/ / | | | | | |     | |__   \\ `--.";
    gotoxy(38, 7); cout << "|    /  | | | | | |     |  __|   `--. \\";
    gotoxy(38, 8); cout << "| |\\ \\  | |_| | | |____ | |___  /\\__/ /";
    gotoxy(38, 9); cout << "\\_| \\_|  \\___/  \\_____/ \\____/  \\____/";
    gotoxy(38, 11); cout << "=======================================";
    gotoxy(40, 13); cout << "1. Wait for the maze to generate.";
    gotoxy(40, 14); cout << "2. Try to figure out how to solve it.";
    gotoxy(40, 15); cout << "3. Have fun solving it!!";
    gotoxy(40, 16); cout << "4. Press Backspace to go to the previous page.";


    back = _getch();

    if (back == '\b') // ASCII code for backspace key
    {
        system("CLS");
        Menu();
    }
}

