#include <iostream>

#include <include/database_manager.hpp>
#include "include/menu.hpp"
#include <sqlite3.h>

int main(int argc, char* argv[]) {
    DatabaseManager manager;
    const char* dbPath = "example.db3";
    if (manager.initializeDatabase(dbPath)) {
        std::cout << "Database initialized successfully.\n";

    } else {
        std::cerr << "Error initializing database.\n";
    }
    // handleMenuLoop();
    return 0;
}
