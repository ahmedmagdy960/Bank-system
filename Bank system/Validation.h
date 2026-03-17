#pragma once
#include <string>
using namespace std;
class Validation
{
public:
	/// <summary>
	/// return true if the name size between 3 and 20 and all char are alpha
	/// otherwise return fals
	/// </summary>
	/// 
	/// <param name="userName"></param>
	/// <returns>
	/// bool
	/// </returns>

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
		if (pass.length() < 8 || pass.length() > 20) {
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
		if (balance < 1500) {
			
			return false;
		}
		return true;
	}

	static bool validateSalary(double salary) {
		if (salary < 3000) {
			return false;
		}
		return true;
	}

	
};

