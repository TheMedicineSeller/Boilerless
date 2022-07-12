CMAKE_MINIMUM_REQUIRED(VERSION 3.22)

project(Boilerless)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(Boilerless
    main.cpp
)