#pragma once
#include "Account.h"
#include <vector>
#include "Encryptioner.h"
#include <sstream>

class DataRowCustom {
public:
	int id;
	char* username;
	char* password;
	std::string accounts; //useless?
	EncryptionLevel elvl;

	std::vector<Account*> accs;

	DataRowCustom() : id(-1), username(nullptr), password(nullptr), accounts(NULL) {}

	DataRowCustom(int idG, char* usernameG, char* passwordG, std::string accountsG) : id(idG), username(usernameG), password(passwordG), accounts(accountsG) {
		std::vector<std::string> strings;
		std::istringstream f(accounts);
		std::string larges;
		while (getline(f, larges, ':')) {
			std::string smalls;
			std::vector<std::string> accInfo;
			
			std::istringstream g(larges);
			while (getline(g, smalls, ',')) {
				accInfo.push_back(smalls);
			}
			accs.push_back(new Account(accInfo.at(0), accInfo.at(1), accInfo.at(2), accInfo.at(3)));
		}
	}

	std::vector<int> includes(std::string toLookFor);

	bool changeEncryptionLvl(int lvl);
	EncryptionLevel retEncryptionLvl();
};