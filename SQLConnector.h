#pragma once
#include <mysql.h>

class SQLConnector {
private:
	static MYSQL* session;
	static char* host;
	static char* user;
	static char* pass;
	static char* db;
	static unsigned int port;
public:
	static bool startConnection();
	static bool endConnection();
	static bool setDb(char* dbG);
	static bool setHost(char* hostG);
	static bool setUser(char* userG);
	static bool setPass(char* passG);
	static bool setPort(unsigned int portG);
	static MYSQL* getSession();
	static const char* getError(MYSQL* conn);
};