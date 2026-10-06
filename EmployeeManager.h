#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Employee.h"
#include "Client.h"
#include "FilesHelper.h"
using namespace std;

class EmployeeManager {
private:
    inline static vector<Employee> employees;

public:
    //  Print Employee Menu
    static void printEmployeMenu() {
        cout << "========== Employee Menu ==========" << endl;
        cout << "1. New Client" << endl;
        cout << "2. List All Clients" << endl;
        cout << "3. Search For Client" << endl;
        cout << "4. Edit Client Info" << endl;
        cout << "5. Logout" << endl;
        cout << "===================================" << endl;
    }

    //  Add New Client
    static void newClient(Employee* employee) {
        string name;
        string password;
        double balance;

        int id = FilesHelper::GetLast("ClientLastId.txt") + 1;
        cout << "Enter Client Name: ";
        cin >> name;

        cout << "Enter Client Password: ";
        cin >> password;

        cout << "Enter Client Balance: ";
        cin >> balance;

        Client client(id, name, password, balance);
        employee->AddClient(client);

        FilesHelper::SaveClient(client);

        cout << "Client added" << endl;
        cout << "ClientID: " << id << endl;

    }

    // List All Clients
    static void listAllClients(Employee* employee) {
        employee->ListClients();
    }

    // Search For Client
    static void searchForClient(Employee* employee) {
        int id;

        cout << "Enter Client ID: ";
        cin >> id;

        Client* client = employee->searchClient(id);

        if (client != nullptr) {
            client->display();
        }
        else {
            cout << "Client not found" << endl;
        }
    }

    //  Edit Client Information
    static void editClientInfo(Employee* employee) {
        int id;
        string newName;
        string newPassword;
        double newBalance;
        cout << "Enter Client ID: ";
        cin >> id;
        Client* client = employee->searchClient(id);
        if (client == nullptr)
        {
            cout << "Client not found" << endl;
            return;
        }

        cout << "Enter NewName: ";
        cin >> newName;

        cout << "Enter NewPassword: ";
        cin >> newPassword;

        cout << "Enter NewBalance: ";
        cin >> newBalance;

        employee->EditClient(id, newName, newPassword, newBalance);
    }

    //  Login
    static Employee* login(int id, string password) {

        employees = FilesHelper::GetEmployees();
        for (Employee& employee : employees) {
            if (employee.getid() == id && employee.getpassword() == password)
            {
                cout << "Login successful." << endl;
                cout << "Welcome " << employee.getname() << endl;

                return &employee;
            }
        }
        cout << "Invalid ID or Password." << endl;
        return nullptr;
    }

    //  Employee Options
    static bool employeeOptions(Employee* employee)
    {
        vector<Client> clients = FilesHelper::GetClients();

        for (Client& client : clients)
        {
            employee->AddClient(client);
        }

        int choice;

        while (true)
        {
            printEmployeMenu();

            cout << "Enter Choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                newClient(employee);
                break;

            case 2:
                listAllClients(employee);
                break;

            case 3:
                searchForClient(employee);
                break;

            case 4:
                editClientInfo(employee);
                break;

            case 5:
                cout << "Logged out successfully." << endl;
                return false;

            default:
                cout << "Invalid Choice." << endl;
            }

            
        }
    }
};

