#pragma once
#include "Validation.h"
class Person
{

protected:
	int id;
	string name;
	string password;

public:
	Person() {
		id = 0;
	}
	Person(int id, string name, string pass) {
		this->id = id;
		//this->name = name;
		//this->password = password;

		setName(name);
		setPass(pass);
	}

	void setId(int id) {
		this->id = id;
	}


	void setName(string name) {
		if (Validation::validateName(name)) {
						this->name = name;

		}
		else {
			this->name = "invalid name";
		}
	}
	void setPass(string pass) {
		if (Validation::validatePass(pass)) {
			this->password = pass;
		}
		else {
			this->password = "invalid password";
		}
	}

	int getId() {
		return id;
	}

	string getName() {
		return name;
	}

	string getPass() {
		return password;
	}

	virtual void displayInfo() {
		cout << "ID: " << id << endl;
		cout << "Name: " << name << endl;
		cout << "Password: " << password << endl;
	}


};

