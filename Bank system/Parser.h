#pragma once
#include <iostream>
#include <vector>
#include "Admin.h"
#include "Client.h"
#include <sstream>
class Parser
{
public:
	static vector<string> split(string line) {
		vector<string> parts;
		string part;
		stringstream ss(line);
		while (getline(ss, part, '|')) {
			parts.push_back(part);
		}
		return parts;
	}

	static Client parseToClient(string line) {
		vector<string> parts = split(line);

		Client c;
		c.setId(stoi(parts[0]));
		c.setName(parts[1]);
		c.setPass(parts[2]);
		c.setBalance(stod(parts[3]));

		return c;
	}

	static Employee parseToEmployee(string line) {
		vector<string> parts = split(line);

		Employee e;
		e.setId(stoi(parts[0]));
		e.setName(parts[1]);
		e.setPass(parts[2]);
		e.setSalary(stod(parts[3]));

		return e;
	}

	static Admin parseToAdmin(string line) {
		vector<string> parts = split(line);

		Admin a;
		a.setId(stoi(parts[0]));
		a.setName(parts[1]);
		a.setPass(parts[2]);
		a.setSalary(stod(parts[3]));

		return a;
	}

};

