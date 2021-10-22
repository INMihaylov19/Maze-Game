#include <conio.h>
#include <iostream>
using namespace std;

#define KEY_UP    72
#define KEY_LEFT  75
#define KEY_RIGHT 77
#define KEY_DOWN  80

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