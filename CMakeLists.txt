cmake_minimum_required(VERSION 3.10)
project(Secure_Code)

set(CMAKE_CXX_STANDARD 17)

# Define the source files
set(SOURCES
    src/main.cpp
    src/parser.cpp
)

# Define the header files
set(HEADERS
    include/parser.h
)

# Add executable
add_executable(Secure_Code ${SOURCES})

# Include project headers
include_directories(${CMAKE_SOURCE_DIR}/include)

# Set output directory
set_target_properties(Secure_Code PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
