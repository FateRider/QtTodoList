#include "Todo.hpp"

// Constructor: opens or creates the database file
DbManager::DbManager(const char *filename) {
    if (sqlite3_open(filename, &db) != SQLITE_OK) {
        qDebug() << "Cannot open database:" << sqlite3_errmsg(db);
        db = nullptr; // security
    } else {
        qDebug() << "Database opened successfully.";
    }
}

// Destructor: closes the database connection
DbManager::~DbManager() {
    if (db) {
        sqlite3_close(db);
        qDebug() << "Database closed.";
    }
}

void DbManager::addTodo(std::string &title, std::string &description) {
    if (!db) return;

    std::string sql = "INSERT INTO todos (title, description) VALUES ('" + title + "', '" + description + "');";

    char *errMsg = nullptr;
    if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg) != SQLITE_OK) {
        qDebug() << "Error inserting todo:" << errMsg;
        sqlite3_free(errMsg);
    } else {
        qDebug() << "Todo added successfully.";
    }
}