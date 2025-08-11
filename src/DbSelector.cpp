#include "DbSelector.hpp"
#include "qpushbutton.h"
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QInputDialog>
#include <QMessageBox>
#include <QVBoxLayout>

DbSelector::DbSelector(QWidget *parent) : QDialog(parent) {
    QSettings settings("RiderSoft", "QtTodoApp");
    dbFolderPath = settings.value("dbFolderPath", "").toString();

    setWindowTitle("Select or Create Todo List");

    dbList = new QListWidget(this);
    newListBtn = new QPushButton("New List", this);
    openBtn = new QPushButton("Open", this);
    deleteBtn = new QPushButton("Delete", this);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *btnLayout = new QHBoxLayout();

    btnLayout->addWidget(newListBtn);
    btnLayout->addWidget(openBtn);
    btnLayout->addWidget(deleteBtn);

    mainLayout->addWidget(dbList);
    mainLayout->addLayout(btnLayout);

    setLayout(mainLayout);
    resize(400, 300);

    connect(newListBtn, &QPushButton::clicked, this, &DbSelector::createNewList);
    connect(openBtn, &QPushButton::clicked, this, &DbSelector::openSelectedDb);
    connect(deleteBtn, &QPushButton::clicked, this, &DbSelector::deleteSelectedDb);

    loadDbFiles();
}

void DbSelector::loadDbFiles() {
    QDir dir(dbFolderPath);
    if (!dir.exists()) { dir.mkpath("."); }

    dbList->clear();
    QStringList dbFiles = dir.entryList(QStringList() << "*.db", QDir::Files);
    for (const QString &file : dbFiles) {
        dbList->addItem(file);
    }
}

void DbSelector::createNewList() {
    // If no folder selected yet, ask user to select/create one
    if (dbFolderPath.isEmpty()) {
        QString folder = QFileDialog::getExistingDirectory(this, "Select Folder to Store Todo Lists", QDir::homePath());
        if (folder.isEmpty()) return;

        QDir dir(folder);
        if (!dir.exists()) {
            if (!dir.mkpath(".")) {
                QMessageBox::critical(this, "Error", "Could not create folder.");
                return;
            }
        }

        QSettings settings("RiderSoft", "QtTodoApp");
        settings.setValue("dbFolderPath", dbFolderPath);

        dbFolderPath = folder;
    }

    bool ok;
    QString newFileName = QInputDialog::getText(this, "New List", "Enter new list name:", QLineEdit::Normal, "", &ok);

    if (!ok || newFileName.isEmpty()) return;

    if (!newFileName.endsWith(".db")) newFileName += ".db";

    QString fullPath = dbFolderPath + "/" + newFileName;

    QFile file(fullPath);
    if (file.exists()) {
        QMessageBox::warning(this, "Error", "File already exists.");
        return;
    }

    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::critical(this, "Error", "Cannot create file.");
        return;
    }
    file.close();

    loadDbFiles();

    QList<QListWidgetItem *> items = dbList->findItems(newFileName, Qt::MatchExactly);
    if (!items.empty()) { dbList->setCurrentItem(items.first()); }
}

void DbSelector::openSelectedDb() {
    QListWidgetItem *item = dbList->currentItem();
    if (!item) {
        QMessageBox::warning(this, "Error", "Please select a list.");
        return;
    }

    selectedFile = dbFolderPath + "/" + item->text();
    accept();
}

QString DbSelector::selectedDbFile() const { return selectedFile; }

void DbSelector::deleteSelectedDb() {
    QListWidgetItem *item = dbList->currentItem();
    if (!item) {
        QMessageBox::warning(this, "Error", "Please select a list to delete.");
        return;
    }

    QString filePath = dbFolderPath + "/" + item->text();

    QMessageBox::StandardButton reply = QMessageBox::question(this, "Delete Confirmation", QString("Are you sure you want to delete '%1'?").arg(item->text()), QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        if (QFile::remove(filePath)) {
            loadDbFiles();
        } else {
            QMessageBox::critical(this, "Error", "Failed to delete the file.");
        }
    }
}