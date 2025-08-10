#include "DbSelector.hpp"
#include "QtTodo.hpp"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    DbSelector selector;
    if (selector.exec() == QDialog::Accepted) {
        QString dbFile = selector.selectedDbFile();
        if (!dbFile.isEmpty()) {
            TodoWindow window(dbFile);
            window.show();
            return app.exec();
        }
    }
    return 0;
}
