#pragma once

#include <iostream>
#include <stdlib.h>

#include "ClientManager.h"
#include "EmployeeManager.h"
#include "AdminManager.h"

using namespace std;

class Screens
{
private:

    static void clearScreen()
    {
        system("cls");
    }


    static void bankName()
    {
        cout << "========================================\n";



        cout << "         WELCOME TO BANK SYSTEM         \n";





        cout << "========================================\n\n";
    }


    static void welcome()
    {
        clearScreen();


        bankName();
    }


    static void loginOptions()
    {
        cout << " [1] Client Login\n";
        cout << " [2] Employee Login\n";
        cout << " [3] Admin Login\n";
        cout << " [0] Exit\n";
        cout << "----------------------------------------\n";
        cout << " Please select your role: ";
    }


    static int loginAs()
    {
        int choice;

        cin >> choice;

        return choice;
    }


    static void invalid(int c)
    {
        cout << "\nInvalid option (" << c<< ")! Press Enter to try again...";

        cin.ignore();
        cin.get();
    }


public:    

    static void clientScreen()
    {
        clearScreen();

        bankName();

        cout << "--- CLIENT LOGIN ---\n\n";

        int id;
        string password;

        cout << "Enter ID: ";
        cin >> id;

        cout << "Enter Password: ";
        cin >> password;

        Client* client = ClientManager::login(id, password);

        if (client != nullptr)
        {
            system("pause");

            clearScreen();

            ClientManager::clientOptions(client);
        }
        else
        {
            system("pause");
        }
    }


 
    

    static void employeeScreen()
    {
        clearScreen();
        bankName();

        cout << "--- EMPLOYEE LOGIN ---\n\n";

        int id;
        string password;

        cout << "Enter ID: ";
        cin >> id;

        cout << "Enter Password: ";
        cin >> password;

        Employee* employee =EmployeeManager::login(id, password);

        if (employee != nullptr)
        {
            cout << "\nLogin Successful!\n";

            system("pause");

            clearScreen();
            EmployeeManager::employeeOptions(employee);

        }
        else
        {
            cout << "\nInvalid ID or Password!\n";

            system("pause");
        }
    }


  
  
   

    static void adminScreen()
    {
        clearScreen();
        bankName();

        cout << "--- ADMIN LOGIN ---\n\n";

        int id;
        string password;

        cout << "Enter ID: ";
        cin >> id;

        cout << "Enter Password: ";
        cin >> password;

        Admin* admin =AdminManager::login(id, password);

        if (admin != nullptr)
        {
            cout << "\nLogin Successful!\n";

            system("pause");

            clearScreen();

            AdminManager::AdminOptions(admin);
        }
        else
        {
            cout << "\nInvalid ID or Password!\n";

            system("pause");
        }
    }


  

    static void loginScreen(int c)
    {
        switch (c)
        {
        case 1:
            clientScreen();
            break;

        case 2:
            employeeScreen();
            break;

        case 3:
            adminScreen();
            break;

        default:
            invalid(c);
            break;
        }
    }


  //run 

    static void runApp()
    {
        while (true)
        {
            welcome();

            loginOptions();

            int choice = loginAs();

            if (choice == 0)
            {
                cout << "\nThank you for using our Bank System. Goodbye!\n";
                break;
            }

            loginScreen(choice);
        }
    }
};