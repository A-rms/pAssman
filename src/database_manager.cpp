#include <include/database_manager.hpp>

DatabaseManager::DatabaseManager() {
}

DatabaseManager::~DatabaseManager() {
}

bool DatabaseManager::initializeDatabase(const char* dbPath) {
    if (db) {
        std::cerr << "Error: Database already initialized.\n";
        return false;
    }
    db = std::make_unique<Database>(dbPath);
    if (!db->connect()) {
        std::cerr << "Error: Failed to connect to the database.\n";
        db.reset();  // Reset the unique_ptr
        return false;
    }
    std::cout << "Connected to database.\n";
    if (!db->createSchema()) {
        std::cerr << "Failed to create schema!";
        db.reset();
        return false;
    }
    // Perform additional initialization if needed
    // Create tables, setup index's, call schema creation.
    return true;
}

