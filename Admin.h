#pragma once
#include <iostream>
#include <string>
#include "Validation.h"
#include "Person.h"
#include "Employee.h"

class Admin :public Employee {
protected:
	vector<Employee> employees;

public:
	Admin(int Id, string Name, string Pasword, double salary) :
		Employee(Id, Name, Pasword, salary) {
	}

	void display() override
	{
		Person::displayPerson();
		cout << "Salary: " << salary << endl;
	}

	///////////////////////////////////////////////
	// Phase 2 
  //add employee
	void AddEmployee(Employee& employee) {
		employees.push_back(employee);
	}

	//search employee
	Employee* searchEmployee(int id) {
		for (Employee& employee : employees) {
			if (employee.getid() == id) {
				return &employee;
			}
		}
		return nullptr;
	}

	//list of employees
	void ListEmployees() {
		cout << "List of Employees:" << endl;
		for (Employee& employee : employees) {
			employee.display();
			cout << "------------------------" << endl;
		}
	}
	//edit employee
	void EditEmployee(int id, string newName, string newPassword, double newSalary) {
		Employee* employee = searchEmployee(id);
		if (employee != nullptr) {
			employee->setname(newName);
			employee->setpassword(newPassword);
			employee->setSalary(newSalary);
			cout << "Employee information updated successfully." << endl;
		}
		else {
			cout << "Employee not found." << endl;
		}
	}
};



