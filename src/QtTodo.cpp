#include "QtTodo.hpp"
#include <qabstractitemview.h> //important
#include <qdebug.h>
#include <qlogging.h>
#include <qpushbutton.h>

TodoWindow::TodoWindow(QWidget *parent) : QMainWindow(parent) {
    // db selection
    QString filePath = QFileDialog::getSaveFileName(this, "Select or Create Database", QDir::homePath() + "/todos.db", "SQLite Database (*.db)");

    if (!filePath.isEmpty()) {
        dbManager = new DbManager(filePath.toUtf8().constData());
    } else {
        dbManager = nullptr;
    }

    setupUI();
};

TodoWindow::~TodoWindow() {};

void TodoWindow::setupUI() {
    centralWidget = new QWidget(this);
    mainLayout = new QVBoxLayout();
    formLayout = new QHBoxLayout();

    titleInput = new QLineEdit();
    titleInput->setPlaceholderText("Title");
    descriptionInput = new QLineEdit();
    descriptionInput->setPlaceholderText("Description");
    addButton = new QPushButton("Add Todo");
    addButton->setStyleSheet("QPushButton{ background-color: green }");

    todoTable = new QTableWidget();
    todoTable->setColumnCount(3);
    todoTable->setHorizontalHeaderLabels({"Title", "Description", "Buttons"});
    todoTable->horizontalHeader()->setStretchLastSection(true);
    todoTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    formLayout->addWidget(titleInput, 1);
    formLayout->addWidget(descriptionInput, 3);
    formLayout->addWidget(addButton, 1);
    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(todoTable);

    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
    setWindowTitle("Your Todo List");
    setWindowIcon(QIcon("../assets/icon.svg"));

    connect(addButton, &QPushButton::clicked, this, &TodoWindow::addTodo);
}

void TodoWindow::addTodo() { qDebug("hmm"); };
void TodoWindow::removeTodo() {};
void TodoWindow::editTodo() {};
void TodoWindow::checkTodo() {};