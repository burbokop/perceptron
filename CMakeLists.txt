cmake_minimum_required(VERSION 3.16)

project(perceptron)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_LIST_DIR})

include(klibcore/klibcore.cmake)

find_package(Qt5 COMPONENTS
    Core
    Quick
    Multimedia
    Widgets
    Test
    Qml
    REQUIRED
    )

add_executable(perceptron
    src/main.cpp
    src/perceptronview.cpp
    src/perceptronview.h
    src/perceptron.cpp
    src/perceptron.h
    src/perceptrontrainer.cpp
    src/perceptrontrainer.h
    src/pointview.cpp
    src/pointview.h
    resources.qrc
    )

target_link_libraries(perceptron
    Qt5::Quick
    Qt5::Multimedia
    Qt5::Widgets
    Qt5::Test
    Qt5::Qml
    klibcore
    )
