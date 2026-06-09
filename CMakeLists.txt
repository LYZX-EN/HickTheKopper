cmake_minimum_required(VERSION 3.16)
project(HickTheHopper)

set(CMAKE_CXX_STANDARD 17)

# logger
add_subdirectory(log)

# Source files
add_executable(${PROJECT_NAME}
    src/main.cpp
)

# Raylib – lokal aus libs/raylib/src einbinden
add_library(raylib STATIC IMPORTED)
set_target_properties(raylib PROPERTIES
    IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/raylib/src/libraylib.a
    INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR}/libs/raylib/src
)

# macOS Frameworks
target_link_libraries(${PROJECT_NAME}
    raylib
    "-framework OpenGL"
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreVideo"
)

target_include_directories(${PROJECT_NAME} PRIVATE
    log/include
)