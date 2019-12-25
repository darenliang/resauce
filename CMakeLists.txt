cmake_minimum_required(VERSION 3.5)

project(resauce LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(resauce
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        aboutdialog.cpp
        aboutdialog.h
        aboutdialog.ui
        fileutil.cpp
        fileutil.h
        info.h
        )

target_link_libraries(resauce PRIVATE Qt5::Widgets)
