#pragma once
#include <iostream>
#include "Parser.h"
#include <fstream>

#define	C_File_Path "data/Client.txt"
#define	E_File_Path "data/Employee.txt"
#define	A_File_Path "data/Admin.txt"

#define C_last_Id_Path "data/ClientLastID.txt"
#define E_last_Id_Path "data/EmployeeLastID.txt"
#define A_Last_Id_Path "data/AdminLastID.txt"

class FilesHeleper
{
public:
	static void saveLast(string fileName, int id) {
	
		fstream file(fileName, ios::out);
		//cout << id;
		file << id;
		file.close();

	}

	static int getLast(string fileName) {
		fstream file;
		file.open(fileName, ios::in);
		int id;
		file >> id;
		file.close();
		return id;
		
	}

	static void saveClient(string fileName, Client c) {
		fstream file(C_File_Path ,  ios :: app);
		file << c.getId() << "|" << c.getName() << "|" << c.getPass() << "|" << c.getBalance() << endl;
		file.close();
		saveLast(C_last_Id_Path, c.getId());
	}

	static void saveEmployee(Employee e) {
		fstream file(E_File_Path, ios::app);
		file << e.getId() << "|" << e.getName() << "|" << e.getPass() << "|" << e.getSalary() << endl;
		file.close();
		saveLast(E_last_Id_Path, e.getId());
	}

	static void saveAdmin(Admin a) {
		fstream file(A_File_Path, ios::app);
		file << a.getId() << "|" << a.getName() << "|" << a.getPass() << "|" << a.getSalary() << endl;
		file.close();
		saveLast(A_Last_Id_Path, a.getId());
	}

	static void getAllClients() {
		fstream file(C_File_Path, ios::in);
		string line;
		while (getline(file, line)) {
			allClients.push_back(Parser::parseToClient(line));
		}
		file.close();
	}

	static void getAllEmployees() {
		fstream file(E_File_Path, ios::in);
		string line;

		while (getline(file, line)) {
			allEmployees.push_back(Parser::parseToEmployee(line));
		}
		file.close();
	}

	static void getAllAdmins() {
		fstream file(A_File_Path, ios::in);
		string line;

		while (getline(file, line)) {
			allAdmins.push_back(Parser::parseToAdmin(line));
		}
		file.close();
	}

	static void clearFile(string fileName , string lastIdFile , int startID) {
		fstream file;
		file.open(fileName, ios::out);
		file.close();
		file.open(fileName, ios::out);
		file << startID;
		file.close();
	}


};

