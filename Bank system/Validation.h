#pragma once
#include <iostream>
#include <string>
using namespace std;
class Validation
{
public:
	

	static bool validateName(string name) {
		if (name.size() < 3 || name.size() > 20) {
		
			return false; 
		}
		for (int i = 0; i < name.size(); i++) {
			if (!isalpha(name[i])) {
				
				return false;
			}
		}
		return true;


	}

	static bool validatePass(string pass) {
		if (pass.length() >= 8 && pass.length() <= 20) {
			return false;
		}
		
		for (int i = 0; i < pass.size(); i++) {
			if (pass[i]==' ') {
				return false;
			}
		}

		return true;
			
	}

	static bool validateBalance(double balance) {
		return balance >= 1500;
	}

	static bool validateSalary(double salary) {
		if (salary < 3000) {
			return false;
		}
		return true;
	}

	static string enterName(string message) {
		string name;
		do {
			cout << message;
			getline(cin, name);
		} while (!validateName(name));
		return name;
	}

	static string enterPass(string message) {
		string pass;
		do {
			cout << message;
			getline(cin, pass);
		} while (!validatePass(pass));
		return pass;
	}

	static double enterBalance(string message) {
		double balance;
		do {
			cout << message;
			cin >> balance;
		} while (!validateBalance(balance));
		return balance;
	}

	static double enterSalary(string message) {
		double salary;
		do {
			cout << message;
			cin >> salary;
		} while (!validateSalary(salary));
		return salary;
	}

	

	static int getIntNumber(string message) {
		int number;
		while (true) {
			cout << message;
			cin >> number;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input. Please enter a valid integer." << endl;
			}
			else {
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				return number;
			}
		}
	}

	


	
};

