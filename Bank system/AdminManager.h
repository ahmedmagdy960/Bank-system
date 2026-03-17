#pragma once
#include "EmployeeManager.h"
class AdminManager
{
private: 
	static void prientAdminMenu() {
		system("cls");
		cout << "(1) Display my info " << endl;
		cout << "(2) Update Password" << endl;
		cout << "(3) Add new client" << endl;
		cout << "(4) Search for client" << endl;
		cout << "(5) List all clients" << endl;
		cout << "(6) Edit client info" << endl;
		cout << "(7) Add new Employee " << endl;
		cout << "(8) Search for Employee " << endl;
		cout << "(9) List all  Employees " << endl;
		cout << "(10) Edit Employee info " << endl;
		cout << "(11) Logout\n" << endl;
	}

	static void back_exit(Admin* admin) {
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
				adminOptions(admin);
				break;
			default:
				cout << "Invalid choice. Please try again." << endl;
				break;
			}
		} while (c < 0 || c > 1);
	}


public:

	static Admin* login(int id, string password) {
		for (eIt = allAdmins.begin(); eIt != allAdmins.end(); eIt++) {
			if (eIt->getId() == id && eIt->getPass() == password) {
				return &(*eIt);
			}
		}
		return nullptr;
	}




	static void newEmployee(Admin* admin) {
		Employee employee;
		int id = FilesHeleper::getLast(E_last_Id_Path) + 1;
		employee.setId(id);
		employee.setName(Validation::enterName("Employee name :  "));
		employee.setPass(Validation::enterPass("Employee password :  "));
		employee.setSalary(Validation::enterSalary("Employee salary :  "));
		admin->addEmployee(employee);
		FilesManager::addEmployee(employee);
		cout << "Employee added successfully with ID: " << employee.getId() << endl;
	}




	static void searchForEmployee(Admin* admin) {
		int id = Validation::getIntNumber("Enter employee ID to search: ");
		Employee* employee = admin->searchEmployee(id);
		if (employee != nullptr) {
			employee->displayInfo();
		}
		else {
			cout << "Employee not found." << endl;
		}
	}



	static void listAllEmployee(Admin* admin) {
		cout << "List of employees:" << endl;
		admin->listEmployee();
	}




	static void editEmployeeInfo(Admin* admin) {
		int id = Validation::getIntNumber("Enter employee ID to edit: ");
		Employee* employee = admin->searchEmployee(id);
		if (employee != nullptr) {
			cout << "=====Update Employee Info=====" << endl;
			string name = Validation::enterName("Enter new employee name: ");
			string pass = Validation::enterPass("Enter new employee password: ");
			double salary = Validation::enterSalary("Enter new employee salary: ");
			admin->editEmployee(employee, name, pass, salary);
			FilesManager::updateEmployees();
			cout << "Employee information updated successfully." << endl;
		}
		else {
			cout << "Employee not found." << endl;
		}
	}



	static bool adminOptions(Admin* admin) {
		prientAdminMenu();
		int choice;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			system("cls");
			admin->display();
			break;
		case 2:
			system("cls");
			ClientManager::updatePassword(admin);
			FilesManager::updateAdmins();
			break;
		case 3:
			system("cls");
			EmployeeManager::newClient(admin);
			break;
		case 4:
			system("cls");
			EmployeeManager::searchForClient(admin);
			break;
		case 5:
			system("cls");
			EmployeeManager::listAllClient(admin);
			break;
		case 6:
			system("cls");
			EmployeeManager::editClientInfo(admin);
			break;
		case 7:
			system("cls");
			newEmployee(admin);
			break;
		case 8:
			system("cls");
			searchForEmployee(admin);
			break;
		case 9:
			system("cls");
			listAllEmployee(admin);
			break;
		case 10:
			system("cls");
			editEmployeeInfo(admin);
			break;
		case 11:
			return false;
			break;
		default:
			system("cls");
			adminOptions(admin);
			return true;
		}
		back_exit(admin);
		return true;
	}
	
};

