#pragma once

#include <QDialog>
#include <QDir>
#include <QListWidget>
#include <QPushButton>
#include <QSettings>
#include <QString>

class DbSelector : public QDialog {
    Q_OBJECT
  public:
    explicit DbSelector(QWidget *parent = nullptr);

    QString selectedDbFile() const;

  private slots:
    void createNewList();
    void openSelectedDb();

  private:
    QListWidget *dbList;
    QPushButton *newListBtn;
    QPushButton *openBtn;
    QPushButton *deleteBtn;

    QString dbFolderPath;
    QString selectedFile;

    void loadDbFiles();
    void deleteSelectedDb();
    void selectFolder();
};
