#pragma once
#include "DataSourceInterface.h"
#include "FilesHeleper.h"
class FilesManager :public DataSourceInterface
{
public:
	void addClient(Client obj) {
		FilesHeleper::saveClient(obj);
	}
	void addEmployee(Employee obj) {
		FilesHeleper::saveEmployee(obj);
	}
	void addAdmin(Admin obj) {
		FilesHeleper::saveAdmin(obj);
	}
	void getAllClients() {
		FilesHeleper::getAllClients();
	}
	void getAllEmployees() {
		FilesHeleper::getAllEmployees();
	}
	void getAllAdmins() {
		FilesHeleper::getAllAdmins();
	}
	void removeAllClients() {
		FilesHeleper::clearFile(C_File_Path , C_last_Id_Path , 0);
		
	}
	void removeAllEmployees() {
		
		FilesHeleper::clearFile(E_File_Path, E_last_Id_Path, 100);
	}
	void removeAllAdmins() {
		FilesHeleper::clearFile(A_File_Path, A_last_Id_Path, 1000);
	}

	static void updateClients() {
		FilesHeleper::clearFile(C_File_Path, C_last_Id_Path, 0);
		for (cIt = allClients.begin(); cIt != allClients.end(); cIt++) {
			FilesHeleper::saveClient(*cIt);
		}
	}
	static void updateEmployees() {
		FilesHeleper::clearFile(E_File_Path, E_last_Id_Path, 100);
		for (eIt = allEmployee.begin(); eIt != allEmployee.end(); eIt++) {
			FilesHeleper::saveEmployee(*eIt);
		}
	}
	static void updateAdmins() {
		FilesHeleper::clearFile(A_File_Path, A_Last_Id_Path, 1000);
		for (aIt = allAdmins.begin(); aIt != allAdmins.end(); aIt++) {
			FilesHeleper::saveAdmin(*aIt);
		}
	}

	static void getAllData() {
		getAllClients();
		getAllEmployees();
		getAllAdmins();
	}


};

