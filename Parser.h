#pragma once

#include <vector>
#include <string>

#include "Client.h"
#include "Employee.h"
#include "Admin.h"

using namespace std;

class Parser
{
public:

    static vector<string> split(string line)
    {
        vector<string> result;
        string W = "";

        for (char c : line)
        {
            if (c == '/')
            {
                result.push_back(W);
                W = "";
            }
            else
            {
                W += c;
            }
        }

        result.push_back(W);

        return result;
    }

    static Client parseToClient(string line)
    {
        vector<string> data = split(line);

        int id = stoi(data[0]);
        string name = data[1];
        string password = data[2];
        double balance = stod(data[3]);

        return Client(id, name, password, balance);
    }

    static Employee parseToEmployee(string line)
    {
        vector<string> data = split(line);

        int id = stoi(data[0]);
        string name = data[1];
        string password = data[2];
        double salary = stod(data[3]);

        return Employee(id, name, password, salary);
    }

    static Admin parseToAdmin(string line)
    {
        vector<string> data = split(line);

        int id = stoi(data[0]);
        string name = data[1];
        string password = data[2];
        double salary = stod(data[3]);

        return Admin(id, name, password, salary);
    }
};