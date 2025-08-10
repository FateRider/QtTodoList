cmake_minimum_required(VERSION 3.16)

project(QtTodo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

add_executable(QtTodo
    ./src/main.cpp
    ./src/QtTodo.cpp
    ./src/QtTodo.hpp
    ./src/Todo.cpp
    ./src/Todo.hpp
)


target_link_libraries(QtTodo
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)