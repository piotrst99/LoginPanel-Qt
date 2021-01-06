#ifndef VERIFYDATA_H
#define VERIFYDATA_H

#include <string>
#include <set>
#include <regex>

namespace verifyData {
	bool isMonkey(std::string& eMail) {
		return (eMail.find('@') != std::string::npos) ? false : true;
	}

	bool emailCheck(const std::string& email){
		const std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
		return std::regex_match(email, pattern);
	}

	bool checkEmail(std::string email) {
		if (email.length() > 5 && email.length() < 256) {
			if ((email[email.length() - 3] == '.' || email[email.length() - 4] == '.') && !isMonkey(email)) {
				return true;
			}
		}
		return false;
	}

	bool minimumLength(std::string& pwd) { return (pwd.length() >= 8); }
	bool areLowercase(std::string& pwd) { return std::any_of(begin(pwd), end(pwd), islower); }
	bool areUppercase(std::string& pwd) { return std::any_of(begin(pwd), end(pwd), isupper); }
	bool areNumber(std::string& pwd) { return std::any_of(begin(pwd), end(pwd), isdigit); }
	bool areSpecialChar(std::string& pwd) {
		auto specialChar = [](char sChar) {
			std::set<char> specialChars = { '_','$','-','%','!','@','#','^','&','*','(',')','=','+','/','?','.','<','>',',',':',';' };
			return specialChars.count(sChar);
		};
		return std::any_of(begin(pwd), end(pwd), specialChar);
	}

	bool checkPassword(std::string password) {
		return minimumLength(password) &&
			areLowercase(password) &&
			areUppercase(password) &&
			areNumber(password) &&
			areSpecialChar(password);
	}

	bool checkName(std::string name) {
		if (name.length() > 0) {
			return areLowercase(name) &&
				areUppercase(name) &&
				!areNumber(name) &&
				!areSpecialChar(name);
		}
		return false;
	}

	bool checkAge(int age) { return (age > 0) ? true : false; }
}

#endif // !VERIFYDATA_H


/*du¿ych i ma³ych liter alfabetu ³aciñskiego[A - Za - z],
cyfr[0 - 9],
znaku kropki(co najmniej jednego),
znaku “@”(dok³adnie jednego),
znaków myœlnika i podkreœleñ dolnych.*/

