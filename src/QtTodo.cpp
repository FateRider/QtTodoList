#include "QtTodo.hpp"
#include <qboxlayout.h>
TodoWindow::TodoWindow(QWidget *parent) : QMainWindow(parent) { setupUI(); };
TodoWindow::~TodoWindow() {};

void TodoWindow::setupUI() {
    centralWidget = new QWidget(this);
    mainLayout = new QVBoxLayout();
}

void TodoWindow::addTodo() {};
void TodoWindow::removeTodo() {};
void TodoWindow::editTodo() {};
void TodoWindow::checkTodo() {};