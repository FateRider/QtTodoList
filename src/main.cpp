#include "DbSelector.hpp"
#include "QtTodo.hpp"
#include <QApplication>
#include <qicon.h>

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
    selector.setWindowIcon(QIcon("../assets/icon.png"));
    app.setWindowIcon(QIcon("../assets/icon.png"));
    return 0;
}
