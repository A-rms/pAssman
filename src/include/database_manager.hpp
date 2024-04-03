#ifndef DATABASE_MANAGER_HPP
#define DATABASE_MANAGER_HPP

#include <memory>
#include <iostream>

#include <include/database.hpp>

class DatabaseManager {
public:
    DatabaseManager();
    ~DatabaseManager();
    bool initializeDatabase(const char* dbPath);

private:
    std::unique_ptr<Database> db;
};

#endif
