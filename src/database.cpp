#include <include/database.hpp>

Database::Database(const char* dbPath)
    : db(nullptr)
    , dbPath(dbPath){}

Database::~Database() {
    disconnect();
}

bool Database::connect() {
    int rc = sqlite3_open(dbPath, &db);
    if (rc != SQLITE_OK) {
        std::cerr << "Error connecting to database: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    std::cout << "Connected to database.\n";
    return true;
}

bool Database::disconnect() {
    if (db) {
        int rc = sqlite3_close(db);
        if (rc != SQLITE_OK) {
            std::cerr << "Error disconnecting from database: " << sqlite3_errmsg(db) << std::endl;
            return false;
        }
        std::cout << "Disconnected from database.\n";
        db = nullptr;
    }
    return true;
}

bool Database::createSchema() {
    const char* sql = "CREATE TABLE IF NOT EXISTS users ("
                      "uid INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "username TEXT NOT NULL UNIQUE,"
                      "password TEXT NOT NULL,"
                      "salt TEXT NOT NULL,"
                      "creation_date DATETIME DEFAULT CURRENT_TIMESTAMP"
        ");";
    char* errmsg;
    int rc = sqlite3_exec(db, sql, nullptr, nullptr, &errmsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Schema creation failed! ";
        return false;
    }
    std::cout << "Schema created successfully: ";

    return true;
}
