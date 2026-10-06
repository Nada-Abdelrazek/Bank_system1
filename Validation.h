#pragma once

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Validation
{
public:

    static bool isValidName(const string& name)
    {
        if (name.length() < 5 || name.length() > 20)
            return false;

        for (char c : name)
        {
            if (!isalpha(c) && c != ' ')
                return false;
        }

        return true;
    }

    static bool containsSpecialChar(const string& password)
    {
        for (char c : password)
        {
            if (!isalnum(c))
                return true;
        }

        return false;
    }

    static bool isValidPassword(const string& password)
    {
        if (password.length() < 8 || password.length() > 20)
            return false;

        for (char c : password)
        {
            if (isspace(c))
                return false;
        }

        return containsSpecialChar(password);
    }


    static bool isValidBalance(double balance)
    {
        return balance >= 1500.0;
    }

    static bool isValidSalary(double salary)
    {
        return salary >= 5000.0;
    }
    static bool manageName(string& name) {
        while (!isValidName(name)) {
            cout << "Invalid Name! Please enter again: ";
            getline(cin >> ws, name);
        }

        return true;
    }


    static string enterName()
    {
        string name;

        cout << "Enter Name: ";
        getline(cin >> ws, name);

        while (!isValidName(name))
        {
            cout << "Invalid Name! Please enter again: ";
            getline(cin >> ws, name);
        }

        return name;
    }

    static string enterPassword() {
        string password;
        cout << "Enter Password: ";
        cin >> password;
        while (!isValidPassword(password)) {
            cout << "Invalid Password! Must be 8-20 characters and contain a special character.\nPlease enter again: ";
            cin >> password;
        }
        return password;
    }

};

