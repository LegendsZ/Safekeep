#include "SQLConnector.h"

MYSQL* SQLConnector::session = nullptr;
char* SQLConnector::host = "";
char* SQLConnector::user = "";
char* SQLConnector::pass = "";
char* SQLConnector::db = "";
unsigned int SQLConnector::port = 0;

bool SQLConnector::startConnection(){
	session = mysql_init(0);
	session = mysql_real_connect(session, host, user, pass, db, port, NULL, 0);
	if (!session) {
		return false;
	}
	//continue
	return true;
}

bool SQLConnector::endConnection() {
	return true;
}

bool SQLConnector::setDb(char* dbG)
{
	db = dbG;
	return true;
}

bool SQLConnector::setHost(char* hostG)
{
	host = hostG;
	return true;
}

MYSQL* SQLConnector::getSession()
{
	return session;
}

const char* SQLConnector::getError(MYSQL* conn)
{
	return mysql_error(SQLConnector::getSession());
}

bool SQLConnector::setUser(char* userG)
{
	user = userG;
	return true;
}

bool SQLConnector::setPass(char* passG)
{
	pass = passG;
	return true;
}

bool SQLConnector::setPort(unsigned int portG)
{
	port = portG;
	return true;
}
