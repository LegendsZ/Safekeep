#pragma once
#include <string>

#include <algorithm>

class Account {
public:
	std::string domain;
	std::string username;
	std::string password;
	std::string notes;

	Account(std::string domainG, std::string usernameG, std::string passwordG, std::string notesG) :domain(domainG), username(usernameG), password(passwordG), notes(notesG) {
		
	}

	std::string toLower(std::string provided);

	bool includes(std::string toLookFor);
};