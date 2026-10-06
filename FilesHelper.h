#pragma once
#include <iostream>

#include<vector>
#include<fstream>
#include"Parser.h"
#include "Person.h"
#include "Employee.h"
#include "Admin.h"


using namespace std;

class FilesHelper
{
public:

    static void SaveLast(string FileName, int id) {
        ofstream output(FileName);
        output << id;
        output.close();
    }

    static int GetLast(string FileName)
    {
        ifstream input(FileName);

        int id = 0;

        input >> id;

        input.close();

        return id;
    }



    /// //////////////////////////////////
    static void SaveClient(Client c)
    {
        ofstream output("Client.txt", ios::app);

        output << c.getid() << "/"<< c.getname() << "/" << c.getpassword() << "/"<< c.GetBalance()<< endl;

        output.close();
        SaveLast("ClientLastId.txt", c.getid());
    }


   

    static void SaveEmployee(string FileName, string LastIdFile, Employee e)
    {
        ofstream output(FileName, ios::app);

        output << e.getid() << "/" << e.getname() << "/" << e.getpassword() << "/" << e.getSalary() << endl;
        output.close();

        SaveLast(LastIdFile, e.getid());

    }
    static void SaveAdmin(Admin a)
    {
        SaveEmployee("Admin.txt", "AdminLastId.txt", a);

    }



    ////////////////////////////////////////////////////

    static vector<Client> GetClients()
    {
        vector<Client> clients;

        ifstream input("Client.txt");

        string line;

        while (getline(input, line))
        {
            if (!line.empty())
            {
                Client c = Parser::parseToClient(line);
                clients.push_back(c);
               
            }
        }

        input.close();

        return clients;
    }


  

    static vector<Employee> GetEmployees()
    {
        vector<Employee> employees;

        ifstream input("Employee.txt");

        string line;

        while (getline(input, line))
        {
            if (!line.empty())
            {
                Employee e = Parser::parseToEmployee(line);
                employees.push_back(e);
            }
        }

        input.close();

        return employees;
    }

   
  
    
    static vector<Admin> GetAdmins()
    {
        vector<Admin> admins;

        ifstream input("Admin.txt");

        string line;

        while (getline(input, line))
        {
            if (!line.empty())
            {
                Admin a = Parser::parseToAdmin(line);

                admins.push_back(a);
            }
        }

        input.close();

        return admins;
    }


    

    static void ClearFile(string FileName, string LastIdFile)
    {
        ofstream output(FileName, ios::trunc);

        output.close();

        ofstream lastFile(LastIdFile, ios::trunc);

        lastFile << 0;

        lastFile.close();
    }
};