#include "QtTodo.hpp"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    TodoWindow window;

    window.show();
    return app.exec();
}