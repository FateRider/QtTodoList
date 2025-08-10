cmake_minimum_required(VERSION 3.16)

project(QtTodoApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
find_package(SQLite3 REQUIRED)


add_executable(QtTodo
    ./src/main.cpp
    ./src/DbSelector.cpp
    ./src/QtTodo.cpp
    ./src/Todo.cpp
)

target_include_directories(QtTodo PRIVATE src)


target_link_libraries(QtTodo PRIVATE Qt6::Core Qt6::Widgets SQLite::SQLite3)
