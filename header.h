//
// Created by Thống Hoàng Danh on 10.4.2022.
//

#ifndef UNTITLED_HEADER_H
#define UNTITLED_HEADER_H

#endif // UNTITLED_HEADER_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Register
{
    string re_passwd;

protected:
    string user_name;
    string password;

public:
    void getdata() // input data to be registered.
    {
        cout << "Enter username: ";
        cin >> user_name;
    create_password:
        cout << "Enter password: ";
        cin >> password;
        cout << "Enter password again: ";
        cin >> re_passwd;
        if (password.length() < 6)
        {
            cout << "Registation failed! Password must be at least 6 characters\n Please try again with your password!\n";
            goto create_password;
        }
        check();

        cout << "User successfully registered.\nWelcome to the system\n\n";
    }
    void writedata() // writing data to file.
    {
        if (password == re_passwd)
        {
            fstream data;
            data.open("data.dat", ios::app);
            if (!data)
            {
                cout << "There is some error, try again!\n\n";
            }
            else
            {
                data << user_name;
                data << endl;
                data << password;
                data << endl;

                data.close();
            }
        }
        else
        {
            cout << "Password doesn't match. Enter again!!!\n\n"
                 << endl;
            getdata();
        }
    }
    void check() // checking already registered user.
    {
        int count1 = 0;
        fstream data;
        data.open("data.dat", ios::in);
        if (data)
        {
            string user;
            string passwd;

            while (1)
            {
                data >> user;
                data >> passwd;
                if (user == user_name)
                    count1++;
                if (data.eof())
                    break;
            }
            if (count1 != 0)
            {
                cout << "Invalid user name. Please enter another user name! " << endl;
                getdata();
            }
            else
            {
                writedata();
            }
        }
        else
            writedata();

        data.close();
    }
};
class Login : public Register
{
    int count = 0;

public:
    void input() // input username and password to login.
    {
        cout << "Enter user name: ";
        cin >> user_name;
        cout << "Enter password: ";
        cin >> password;
        readdata();
    }
    void readdata() // read data from file.
    {
        fstream data;
        data.open("data.dat", ios::in);
        if (!data)
        {
            cout << "No such file\n";
        }
        else
        {
            string user;
            string passwd;
            while (1)
            {
                data >> user;
                data >> passwd;
                if (user_name == user && password == passwd)
                {
                    count++;
                    break;
                }
                if (data.eof())
                    break;
            }
            if (count != 0)
            {
                cout << "Login successful\n\n"
                     << endl;
            }
            else
            {
                cout << "Login failed! please check your user name and password.\n";
            }
        }
        data.close();
    }
};
