#include <iostream>
#include <fstream>
#include <string>
#include "header.h"

using namespace std;

int main()
{
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n"
         << "@  Welcome to the login/register system!  @\n\n"
         << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n";

start:
    int num;
    cout << "Choose your option:\n\n";
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "3. Exit\n\n";
    cout << "Enter your choice(1/2/3): ";
    cin >> num;

    Login obj;

    switch (num) // Enter choise
    {
    case 1: // Register
        obj.getdata();
        goto start;
    case 2: // Login
        obj.input();
        goto start;
    case 3: // Exit
        cout << "Goodbye! Have a nice day!\n";
        break;
    default:
        cout << "Invalid Choice!!!\nPlease try again!" << endl;
        goto start;
    }
    return 0;
}
