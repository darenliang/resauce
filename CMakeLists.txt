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
        src/main.cpp
        src/mainwindow.cpp
        src/mainwindow.h
        src/mainwindow.ui
        src/aboutdialog.cpp
        src/aboutdialog.h
        src/aboutdialog.ui
        src/fileutil.cpp
        src/fileutil.h
        src/info.h
        src/state.cpp
        src/state.h
        src/dirutil.cpp
        src/dirutil.h
        src/resaucefileinfo.cpp
        src/resaucefileinfo.h
        src/resaucefilemodel.cpp
        src/resaucefilemodel.h
        src/resaucer.cpp
        src/resaucer.h
        src/resaucerprocessor.cpp
        src/resaucerprocessor.h
        src/resaucernumbering.cpp
        src/resaucernumbering.h)

target_link_libraries(resauce PRIVATE Qt5::Widgets)
