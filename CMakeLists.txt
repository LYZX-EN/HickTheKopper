cmake_minimum_required(VERSION 3.16)
project(HickTheHopper)

set(CMAKE_CXX_STANDARD 17)


# source fies
add_executable(${PROJECT_NAME}
    src/main.cpp
)

# raylib
target_link_libraries(${PROJECT_NAME} raylib)