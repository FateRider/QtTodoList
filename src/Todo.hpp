#pragma once
#include "sqlite3.h"
#include <QDebug>
#include <string>

class DbManager {
  private:
    sqlite3 *db;

  public:
    // db connection
    DbManager(const char *fileName);
    // db close
    ~DbManager();

    // add todo
    void addTodo(std::string &title, std::string &descripton);

    // edit todo
    void editTodo(const int &id);

    // check todo
    void checkTodo(const int &id);

    // remove todo
    void removeTodo(const int &id);
};