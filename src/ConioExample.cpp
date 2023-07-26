#include <iostream>
#include <cstdlib>      // for system()
#include <thread>       // for sleep
#include <conio.h>      // for _kbhit() and _getch()

const int KB_ESCAPE = 27;

const int SPECIAL_KEY = 224;

// special keys
const int KB_UP = 72;
const int KB_DOWN = 80;
const int KB_LEFT = 75;
const int KB_RIGHT = 77;

void handleSpecialKey();

int main()
{
    std::system("cls");
    int c = 0;
    do
    {
        while (!_kbhit())       // Wait for a key to be pressed
            std::this_thread::sleep_for(std::chrono::milliseconds(500));

        c = _getch();
        switch (c)
        {
        case 0:
        case SPECIAL_KEY:
            handleSpecialKey();
            break;
        case 'A':
            std::cout << "A pressed" << std::endl;
            break;
        case 'a':
            std::cout << "a pressed" << std::endl;
            break;
        case KB_ESCAPE:
            std::cout << "Escape pressed. Exiting..." << std::endl;
            break;
        default:
            std::cout << "Unknown regular key pressed (code = " << c << ")" << std::endl;
            break;
        }
    } while (c != KB_ESCAPE);

    std::cout << "Press any key to exit..." << std::endl;
    _getch();
}

void handleSpecialKey()
{
    int c = _getch();
    switch (c)
    {
    case KB_UP:
        std::cout << "Arrow Up pressed" << std::endl;
        break;
    case KB_DOWN:
        std::cout << "Arrow Down pressed" << std::endl;
        break;
    case KB_LEFT:
        std::cout << "Arrow Left pressed" << std::endl;
        break;
    case KB_RIGHT:
        std::cout << "Arrow Right pressed" << std::endl;
        break;
    default:
        std::cout << "Unknown special key pressed (code = " << c << ")" << std::endl;
        break;
    }
}