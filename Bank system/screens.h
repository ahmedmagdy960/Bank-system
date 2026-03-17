#include <chrono>
#include <thread>
#include <windows.h>
#include "AdminManager.h"
#include <stdlib.h>
#pragma once
class screens
{
	static void bankName() {
	
		cout << "==============================" << endl;
		cout << "     Welcome to our bank      " << endl;
		cout << "==============================" << endl;
		Sleep(2000);
	}

	static void welcome() {

		 
	}


	static void loginOptions() {
		bankName();
		cout << "Login as : " << endl;
		cout << "(1) Client" << endl;
		cout << "(2) Employee" << endl;
		cout << "(3) Admin\n" << endl;
	}

	static int loginAs() {
		loginOptions();

		int choice = Validation::getIntNumber("Login as : ");

		if (choice == 1 || choice == 2 || choice == 3) {
			system("cls");
			return choice;
		}
		else {
			system("cls");
			cout << "Invalid choice. Please try again." << endl;
			return loginAs();
		}


	}



	static void invalid(int c) {
	
		system("cls");
		cout << "Invalid ID or password. Please try again." << endl;
		loginScreen(c);

	}


	static void logout() {
		system("cls");
		loginScreen(loginAs());
		
	}

public:

	static void loginScreen(int c) {
	
		int choice = c, id;
		string pass;

		id = Validation::getIntNumber("Enter ID: ");

		cout << "Enter password: ";
		cin >> pass;

		switch (choice)
		{

			case 1:
				if (AdminManager::login(id, pass) != nullptr) {
					while (AdminManager::adminOptions(AdminManager::login(id, pass)) != false);
					logout();
				}
				else invalid(1);
			break;



			case 2 :
				if (EmployeeManager::login(id, pass) != nullptr) {
				
					while (EmployeeManager::employeeOptions(EmployeeManager::login(id, pass)) != false);
					logout();
				}
				else invalid(2);
				break;


			case 3:
				if (ClientManager::login(id, pass) != nullptr) {
					while (ClientManager::clientOptions(ClientManager::login(id, pass)) != false);
					logout();
				}
				else invalid(3);
				break;

			default:
				system("cls");
				cout << "Invalid choice. Please try again." << endl;
				loginScreen(choice);
				

		}


	}
	static void runApp() {

		FileManager::getAllData();



		loginScreen(loginAs());
	}
};

