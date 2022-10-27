#include "Account.h"

std::string Account::toLower(std::string provided)
{
	std::transform(provided.begin(), provided.end(), provided.begin(), ::tolower);
	return provided;
}

bool Account::includes(std::string toLookFor)
{
	toLookFor = toLower(toLookFor);
	if (toLower(domain).find(toLookFor) != std::string::npos || toLower(username).find(toLookFor) != std::string::npos || toLower(password).find(toLookFor) != std::string::npos || toLower(notes).find(toLookFor) != std::string::npos) {
		return true;
	}
	return false;
}
