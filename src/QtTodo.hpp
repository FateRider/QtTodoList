#pragma once
#include <QComboBox>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QRadioButton>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QWidget>

class TodoWindow : public QMainWindow {
    Q_OBJECT
  public:
    TodoWindow(QWidget *parent = nullptr);
    ~TodoWindow() override;

  private slots:
    void addTodo();
    void removeTodo();
    void editTodo();
    void checkTodo();

  private:
    QWidget *centralWidget;
    QVBoxLayout *mainLayout;

    QLineEdit *titleInput;
    QLineEdit *descriptionInput;

    QRadioButton *checkedInput;

    QPushButton *addButton;

    QTableWidget *todoTable;

    void setupUI();
};