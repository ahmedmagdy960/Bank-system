#pragma once
#include "FilesManager.h"
class ClientManager
{
	static void prientClientMenu() {
		system("cls");
		cout << "(1) Display my info " << endl;
		cout << "(2) Check balance" << endl;
		cout << "(3) Update Password" << endl;
		cout << "(4) Withdraw" << endl;
		cout << "(5) Deposit" << endl;
		cout << "(6) Transfer" << endl;
		cout << "(7) Logout\n" << endl;

	}

	static void back_exit(Client* client) {
		int c; 
		do {
			cout << "\n\n(1) Option\t\t(0) Exit\n";
			c = Validation::getIntNumber("Enter your choice: ");
			switch (c)
			{
			case 0 :
					exit(0);
					break;
			case 1:
				system("cls");
				clientOptions(client);
				break;
			default:
				cout << "Invalid choice. Please try again." << endl;
				break;
			}

		} while (c < 0 || c > 1);
	}

public:


	static Client* login(int id, string password) {

		for (cIt = allClients.begin(); cIt != allClients.end(); cIt++) {
			if (cIt->getId() == id && cIt->getPass() == password) {
				return &(*cIt);
			}
		}
		return nullptr;
	}

	static void updatePassword(Person* person) {
		string newPass;
		do {
			cout << "Enter new password: ";
			cin >> newPass;
			while (!Validation::validatePass(newPass)) {
				person->setPassword(newPass);
				cout << "password updated successfully." << endl;
			}
		}
	}

	static bool clientOptions(Client* client) {
			prientClientMenu();
			int choice;
			double amount;
			int id;
			Client* recipient;
			Employee e;
			cout << "Enter your choice: ";
			cin >> choice;
			switch (choice) {
			case 1:
				system("cls");
				client->display();
				break;
			case 2:
				system("cls");
				cout << "Your balance is: " << client->getBalance() << endl;
				break;
			case 3:
				system("cls");
				updatePassword(client);
				FilesManager::updateClients();
				break;
			case 4:
				system("cls");
				amount = Validation::getDoubleNumber("Enter amount to withdraw: ");
				client->withdraw(amount);
				FilesManager::updateClients();
				break;
			case 5:
				system("cls");
				amount = Validation::getDoubleNumber("Enter amount to deposit: ");
				client->deposit(amount);
				FilesManager::updateClients();
				break;
				
			case 6:
				system("cls");
				id = Validation::getIntNumber("Enter recipient client ID: ");
				recipient = e.searchClient(id);
				if (recipient != nullptr) {
					amount = Validation::getDoubleNumber("Enter amount to transfer: ");
					client->transfer(*recipient, amount);
					
				}
				else {
					cout << "Recipient client not found." << endl;
				}
				break;
			case 7:
				return false;
				break;
			default:
				system("cls");
				clientOptions(client);
				return true;
			}
			back_exit(client);
			return true;

	}
	
};

