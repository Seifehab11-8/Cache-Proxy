cmake_minimum_required(VERSION 3.15)

project(cachingProxy
    VERSION 1.0.0
    LANGUAGES CXX
)

# Enable compile_commands.json generation for IDEs/clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Enforce C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Source files
set(SOURCES
    main.cpp
    src/cache.cpp
    src/socketManager.cpp
)

# Add executable
add_executable(cachingProxy ${SOURCES})

# Include search paths (header directory and project root)
target_include_directories(cachingProxy PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/header
    ${CMAKE_CURRENT_SOURCE_DIR}
)
