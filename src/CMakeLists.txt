# Source files
set(SOURCES
    main.cpp
    editor.cpp
    file_operations.cpp
    terminal.cpp
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries (add any required libraries here)
target_include_directories(${PROJECT_NAME} PRIVATE ../include)
# Set output directory
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
