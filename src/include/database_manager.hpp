#ifndef DATABASE_MANAGER_HPP
#define DATABASE_MANAGER_HPP

#include <include/database.hpp>

class DatabaseManager {
	
public:
    DatabaseManager();
    ~DatabaseManager();
    bool initializeDatabase(const char* dbPath);

private:
    Database* db;

};

#endif