#include <iostream>
#include <include/database_manager.hpp>

int main(int argc, char* argv[]) {
    DatabaseManager manager;
    const char* dbPath = "example.db3";
    if (manager.initializeDatabase(dbPath)) {
        std::cout << "Database initialized successfully.\n";
    } else {
        std::cerr << "Error initializing database.\n";
        return 1;  
    }
    return 0;
}
