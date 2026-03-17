#pragma once
#include "Person.h"
class Employee : Person 
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

};

