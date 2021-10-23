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

    gotoxy(38, 3); color(SetColor[0]); cout << "======================================="; color(SetColor[1]);
    gotoxy(38, 4); color(SetColor[1]); cout << " _____   _   _   _       _____   _____ ";
    gotoxy(38, 5); color(SetColor[1]); cout << "| ___ \\ | | | | | |     |  ___| /  ___|";
    gotoxy(38, 6); color(SetColor[1]); cout << "| |_/ / | | | | | |     | |__   \\ `--.";
    gotoxy(38, 7); color(SetColor[1]); cout << "|    /  | | | | | |     |  __|   `--. \\";
    gotoxy(38, 8); color(SetColor[1]); cout << "| |\\ \\  | |_| | | |____ | |___  /\\__/ /";
    gotoxy(38, 9); color(SetColor[1]); cout << "\\_| \\_|  \\___/  \\_____/ \\____/  \\____/";
    gotoxy(38, 11); color(SetColor[0]); cout << "======================================="; color(SetColor[1]);
    gotoxy(50, 13); cout << "1. Have fun!!";
    gotoxy(50, 14); cout << "1. Have fun!!";
    gotoxy(50, 15); cout << "1. Have fun!!";
    gotoxy(50, 15); cout << "4. Press Backspace to go to the previous page.";


    back = _getch();

    if (back == '\b') // ASCII code for backspace key
    {
        system("CLS");
        Menu();
    }
}

