#pragma once
#include <iostream>
#include <string>
#include "Validation.h"
#include "Person.h"
#include "Client.h"
#include <vector>

class Employee :public Person
{
protected:
	double salary;
	vector<Client> clients;
public:
	//Constructor
	Employee(int Id, string Name, string Pasword, double salary) : Person(Id, Name, Pasword) {
		setSalary(salary);
	}
	//setter salary 
	void setSalary(double salary) {
		if (Validation::isValidSalary(salary)) {
			this->salary = salary;
		}
		else {
			cout << "Invalid Salary" << endl;
		}
	}


	//GETTER salary
	double  getSalary() {
		return salary;
	}

	//////////////////////////////////////////////
	// phase 2
	//Add Client
	void AddClient(Client& client) {
		clients.push_back(client);
	}
	//search client
	Client* searchClient(int id) {
		for (Client& client : clients) {
			if (client.getid() == id) {
				return &client;
			}
		}
		return nullptr;
	}
	//list of clients
	void ListClients() {
		cout << "List of Clients:" << endl;
		for (Client& client : clients) {
			client.display();
			cout << "------------------------" << endl;
		}
	}
	//edit client
	void EditClient(int id, string newName, string newPassword, double newBalance) {
		Client* client = searchClient(id);
		if (client != nullptr) {
			client->setname(newName);
			client->setpassword(newPassword);
			client->SetBalance(newBalance);
			cout << "Client information updated successfully." << endl;
		}
		else {
			cout << "Client not found." << endl;
		}
	}

	//display 

	void display() override {
		Person::displayPerson();
		cout << "Salary: " << salary << endl;
	}
};