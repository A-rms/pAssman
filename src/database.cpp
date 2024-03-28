#include <include/database.hpp>

Database::Database(const char* dbPath)
    : db(nullptr)
    , dbPath(dbPath){}

Database::~Database() {
    disconnect();
}

bool Database::connect() {
    int rc = sqlite3_open(dbPath, &db);
    if (rc) {
        // Handle error.
        return false;
    }

    return true;
}

bool Database::disconnect() {
    if (db) {
        sqlite3_close(db);
        return true;
    }
    return false;
}

bool Database::createSchema() {
    // Create DB schema.

    return true;
}
