cmake_minimum_required(VERSION 3.5)

project(QtConsoleApp LANGUAGES CXX)

# Find the Qt packages
find_package(Qt6 6.2 REQUIRED COMPONENTS Core Qml Quick Widgets QuickControls2 Svg)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Set source files
set(SOURCES
    main.cpp
    mainwindow.cpp
    texteditor.cpp
    mainhelp.cpp
    timer.cpp
    calendar.cpp
    DateCell.cpp
    CSideBar.cpp
)

# Set header files
set(HEADERS
    mainwindow.h
    texteditor.hpp
    mainhelp.h
    timer.h
    Calendar.hpp
    DateCell.hpp
    CSideBar.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Core
    Qt6::Qml
    Qt6::Quick
    Qt6::Widgets
    Qt6::QuickControls2
    Qt6::Svg
)
