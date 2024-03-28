#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <sqlite3.h>

class Database {

public:
    Database(const char* dbPath);
    ~Database();
    bool connect();
    bool disconnect();
    bool createSchema();

private:
    sqlite3* db;
    const char* dbPath;

};

#endif