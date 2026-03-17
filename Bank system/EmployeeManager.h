#pragma once
#include "ClientManager.h"
class EmployeeManager
{
	static void prientEmployeeMenu() {
		system("cls");
		cout << "(1) Display my info " << endl;
		cout << "(2) Update Password" << endl;
		cout << "(3) Add new client" << endl;
		cout << "(4) Search for client" << endl;
		cout << "(5) List all clients" << endl;
		cout << "(6) Edit client info" << endl;
		cout << "(7) Logout\n" << endl;
	}
	static void back_exit(Employee* employee) {
		int c;
		do {
			cout << "\n\n(1) Option\t\t(0) Exit\n";
			c = Validation::getIntNumber("Enter your choice: ");
			switch (c)
			{
			case 0:
				exit(0);
				break;
			case 1:
				system("cls");
				employeetOptions(employee);
				break;
			default:
				cout << "Invalid choice. Please try again." << endl;
				break;
			}

		} while (c < 0 || c > 1);
	}
public:

	static Employee* login(int id, string password) {

		for (cIt = allEmployee.begin(); cIt != allEmployee.end(); cIt++) {
			if (cIt->getId() == id && cIt->getPass() == password) {
				return &(*cIt);
			}
		}
		return nullptr;
	}

	static void newClient(Employee* employee) {
		Client client;
		int id = FilesHeleper::getLast(C_last_Id_Path) + 1;
		client.setId(id);
		client.setName(Validation::enterName("Client name :  "));
		client.setPass(Validation::enterPass("Client password :  "));
		client.setBalance(Validation::enterBalance("Client balance :  "));

		employee->addClient(client);

		FilesManager::addClient(client);

		cout << "Client added successfully with ID: " << client.getId() << endl;
	} 



	static void listClients(Employee* employee) {
		cout << "List of clients:" << endl;
		employee->listClient();
	}


	static void searchForClient(Employee* employee) {
		int id;
		id = Validation::getIntNumber("Enter client ID to search: ");
		Client* client = employee->searchClient(id);
		if (client == nullptr)cout << "Client not found." << endl;
		else client->displayInfo();
	}



	static void editClientInfo(Employee* employee) {
	
		int id = Validation::getIntNumber("Enter client ID to edit: ");
		Client* client = employee->searchClient(id);
		if (client != nullptr) {
		
			cout << "=====Update Client Info=====" << endl;
			string name = Validation::enterName("Enter new client name: ");
			string pass = Validation::enterPass("Enter new client password: ");
			double balance = Validation::enterBalance("Enter new client balance: ");

			employee->editClient(id, name, pass, balance);
			FilesManager::updateClients();
			cout << "Client information updated successfully." << endl;
		}
		else {
			cout << "Client not found." << endl;
		}
	
	}







	

	static bool employeeOptions(Employee* employee) {
		prientEmployeeMenu();
		int choice;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			system("cls");
			employee->display();
			break;
		case 2:
			system("cls");
			ClientManager::updatePassword(employee);
			FilesManager::updateEmployees();
			break;
		case 3:
			system("cls");
			newClient(employee);
			break;
		case 4:
			system("cls");
			searchForClient(employee);
			break;
		case 5:
			system("cls");
			employee->listClient();

			break;
		case 6:
			system("cls");
			editClientInfo(employee);
			break;
		case 7:
			return false;
			break;
		default:
			system("cls");
			cout << "Invalid choice. Please try again." << endl;
			employeeOptions(employee);
			return true;
			
		}
		back_exit(employee);
		return true;

	}
};

