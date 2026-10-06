#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Employee.h"
#include "Client.h"
#include"Admin.h"
#include"EmployeeManager.h"
#include"FilesHelper.h"
using namespace std;
class AdminManager :public EmployeeManager {
private:
    inline static vector<Admin> admins;
public:
    // 1. Print Admin Menu
    static void printAdminMenu() {
        cout << "========== Admin Menu ==========" << endl;
        cout << "1. New Client" << endl;
        cout << "2. List All Clients" << endl;
        cout << "3. Search For Client" << endl;
        cout << "4. Edit Client Info" << endl;
        cout << "5.  New Employee" << endl;
        cout << "6. List All Employees" << endl;
        cout << "7. Edit Employee Info" << endl;
        cout << "8. Logout" << endl;
        cout << "===================================" << endl;
    }

    // 2. Login
    static Admin* login(int id, string password) {
        admins = FilesHelper::GetAdmins();
        for (Admin& admin : admins) {
            if (admin.getid() == id &&
                admin.getpassword() == password)
            {
                cout << "Login successful." << endl;
                cout << "Welcome " << admin.getname() << endl;

                return &admin;
            }

        }
                cout << "Invalid ID or Password." << endl;
                return nullptr;
            
        
    }
    // 2. Add New Employee
    static void newEmployee(Admin* admin) {
       
        string name;
        string password;
        double salary;
        int id = FilesHelper::GetLast("EmployeeLastId.txt") + 1;
       
        cout << "Enter Employee Name: ";
        cin >> name;
        cout << "Enter Employee Password: ";
        cin >> password;
        cout << "Enter Employee Balance: ";
        cin >> salary;
        Employee employee(id, name, password, salary);
        admin->AddEmployee(employee);
        FilesHelper::SaveEmployee("Employee.txt", "EmployeeLastId.txt",employee );
        cout << "Employee added successfully." << endl;
        cout << "Employee ID: " << id << endl;
    }
    //5. Edit Employee Information
    static void editEmployeeInfo(Admin* admin) {
        int id;
        string newName;
        string newPassword;
        double newSalary;

        cout << "Enter Employee ID: ";
        cin >> id;
        Employee* employee = admin->searchEmployee(id);
        if (employee == nullptr)
        {
            cout << "Employee not found." << endl;
            return;
        }


        cout << "Enter New Name: ";
        cin >> newName;

        cout << "Enter New Password: ";
        cin >> newPassword;

        cout << "Enter New Saiary: ";
        cin >> newSalary;
        admin->EditEmployee(id, newName, newPassword, newSalary);
    }

    // Admin Options
    static bool AdminOptions(Admin* admin)
    {
       
        vector<Client> clients = FilesHelper::GetClients();

        for (Client& client : clients)
        {
            admin->AddClient(client);
        }

      
        vector<Employee> employees = FilesHelper::GetEmployees();

        for (Employee& employee : employees)
        {
            admin->AddEmployee(employee);
        }

        int choice;
        while (true)
        {
            printAdminMenu();

            cout << "Enter Choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                newClient(admin);
                break;

            case 2:
                listAllClients(admin);
                break;

            case 3:
                searchForClient(admin);
                break;

            case 4:
                editClientInfo(admin);
                break;
            case 5:

                newEmployee(admin);
                break;
            case 6:

                admin->ListEmployees();
                break;
            case 7:

                editEmployeeInfo(admin);
                break;

            case 8:
                cout << "Logged out successfully." << endl;
                return false;

            default:
                cout << "Invalid Choice." << endl;
            }

        }
    }
};

    
