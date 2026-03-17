#pragma once
#include "Person.h"
class Client:Person
{
	double balance;	

public:
	Client(): Person() {
		balance = 0;
	}

	Client(int id, string name, string password, double balance) : Person(id, name, password) {
		setBalance(balance);
	}

	void setBalance(double balance) {
		if (Validation::validateBalance(balance)) {
			this->balance = balance;
		}
		
	}

	double getBalance() {
		return balance;
	}

	void deposit(double amount) {
		if (amount > 0) {
			balance+= amount;
			cout << "Deposit successful. New balance: " << balance << endl;
		}
		cout << "Invalid amount. Deposit failed." << endl;
	}

	void withdraw(double amount) {
		if (amount > 0 && amount <= balance) {
			balance -= amount;
			cout << "Withdrawal successful. New balance: " << balance << endl;
		}
		else {
			cout << "Invalid amount or insufficient funds. Withdrawal failed." << endl;
		}
	}

	void transfer(Client& recipient, double amount) {
		if (amount > 0 && amount <= balance) {
			balance -= amount;
			recipient.balance +=amount;
			cout << "Transfer successful. New balance: " << balance << endl;
		}
		else {
			cout << "Invalid amount or insufficient funds. Transfer failed." << endl;
		}
	}

	void displayInfo() {
		Person::displayInfo();
		cout << "Salary: " << balance << endl;
	}
};

