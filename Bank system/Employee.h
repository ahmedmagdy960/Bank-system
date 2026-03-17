#pragma once
#include <iostream>
#include "Person.h"
class Employee : public Person
{
	double salary;
public:
	Employee() : Person() {
		salary = 0;
	}
	Employee(int id, string name, string password, double salary) : Person(id, name, password) {
		setSalary(salary);
	}
	void setSalary(double salary) {
		if (Validation::validateSalary(salary)) {
			this->salary = salary;
		}

	}
	double getSalary() {
		return salary;
	}
	void displayInfo() {
		Person::displayInfo();
		cout << "Salary: " << salary << endl;
	}

	static void deallcateAllEmployees() {

		delete allEmployees;

	}

	void addClient(Client& client) {
		allClients.push_back(client);

	}
	Client* searchClient(int id) {
		for (cIt = allClients.begin(); cIt != allClients.end(); cIt++) {
			if (cIt->getId() == id) {
				return &(*cIt);
			}

		}
		return nullptr;

	}

	void listClient() {
		for (cIt = allClients.begin(); cIt != allClients.end(); cIt++) {
			cIt->displayInfo();
		}
	
	}
	void editClient(int id, string name, string pass, double balance) {
		Client* c = searchClient(id);
		if (c != nullptr) {
			c->setName(name);
			c->setPass(pass);
			c->setBalance(balance);
		}
	}

};

static vector<Employee>* allEmployees= new vector<Employee>;

