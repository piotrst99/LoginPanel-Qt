#ifndef VERIFYDATA_H
#define VERIFYDATA_H

#include <string>

namespace verifyData {
	bool checkEmail(std::string email) {
		if (email.length() > 5 && email.length() < 256) {
			if ((email[email.length() - 3] == '.' || email[email.length() - 4] == '.')) {
				return true;
			}
		}
		return false;
	}

	bool checkPassword(std::string password) {
		if (password.length() >= 8) {
			return true;
		}
		return false;
	}

	bool checkName(std::string name) {
		if (name.length() > 0) {
			for (int i = 0; i < name.length(); ++i) {
				if (!isalpha(name[i])) {
					return false;
				}
			}
			return true;
		}
		return false;
	}

	bool checkAge(int age) {
		if (age > 0) {
			return true;
		}
		return false;
	}
}

#endif // !VERIFYDATA_H


/*du¿ych i ma³ych liter alfabetu ³aciñskiego[A - Za - z],
cyfr[0 - 9],
znaku kropki(co najmniej jednego),
znaku “@”(dok³adnie jednego),
znaków myœlnika i podkreœleñ dolnych.*/

