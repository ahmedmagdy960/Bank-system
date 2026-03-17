#pragma once
#include <iostream>
#include "Employee.h"
class Admin : public Employee
{
public:
	Admin() : Employee() {
	}
	Admin(int id, string name, string password, double salary) : Employee(id, name, password, salary) {
	}
	void addEmployee(Employee& employee) {
		allEmployees.push_back(employee);
	}

	Employee* searchEmployee(int id) {
		for (eIt = allEmployees.begin(); eIt != allEmployees.end(); eIt++) {
			if (eIt->getId() == id) {
				return &(*eIt);
			}
		}
		return nullptr;
	}

	void editEmployee(Employee *e, string name , string password, double salary) {
			e->setName(name);
			e->setPass(password);
			e->setSalary(salary);
	}

	void listEmployee() {
		for (eIt = allEmployees.begin(); eIt != allEmployees.end(); eIt++) {
			if (eIt->getId() != id) {
				eIt->displayInfo();
			}
		}
	}
	
};
static vector<Admin> allAdmins;
static vector<Admin>::iterator eIt;
