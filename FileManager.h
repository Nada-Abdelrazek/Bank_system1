#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "DataSourceInterface.h"
#include "Parser.h"
#include "Person.h"
#include "Employee.h"
#include "Admin.h"
#include "FilesHelper.h"
using namespace std;
class FilesManager : public DataSourceInterface {
public:
    ///add //////////////////////
    void addClient(Client& c)  override {
        FilesHelper::SaveClient(c);
    }
    void addEmployee(Employee& e) override {
        FilesHelper::SaveEmployee("Employee.txt","EmployeeLastId.txt", e);
    }

    void addAdmin(Admin& a) override {
        FilesHelper::SaveAdmin(a);
    }

    // ==================== Get All ====================

    vector<Client>   getAllClients() override
    {
        return FilesHelper::GetClients();
    }


    vector<Employee>  getAllEmployees()  override
    {
        return FilesHelper::GetEmployees();
    }


    vector<Admin> getAllAdmins()  override
    {
        return FilesHelper::GetAdmins();


    }
    /// remove//////////////////////////////////////////////
    void removeAllClients() override {
        FilesHelper::ClearFile("Client.txt", "ClientLastId.txt");
    }

    void removeAllEmployees() override {
        FilesHelper::ClearFile("Employee.txt", "EmployeeLastId.txt");
    }

    void removeAllAdmins() override {
        FilesHelper::ClearFile("Admin.txt", "AdminLastId.txt");
    }
};



  