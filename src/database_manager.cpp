#include <include/database_manager.hpp>

DatabaseManager::DatabaseManager() {
    db = nullptr;
}

DatabaseManager::~DatabaseManager() {
    delete db;
}

bool DatabaseManager::initializeDatabase(const char* dbPath) {
    if (db) {
        // Database already exists.
        return false;
    }
    db = new Database(dbPath);
    if (!db->connect()) {
        // Handle connection error.
        delete db;
        db = nullptr;
        return false;
    }
    // Perform additional init.
    return true;
}
