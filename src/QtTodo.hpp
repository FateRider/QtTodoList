#pragma once
#include <QComboBox>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QIcon>
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
    QHBoxLayout *formLayout;

    QLineEdit *titleInput;
    QLineEdit *descriptionInput;

    QPushButton *addButton;
    QPushButton *removeButton;
    QPushButton *editoButton;

    QRadioButton *checkedInput;
    QTableWidget *todoTable;

    void setupUI();
};