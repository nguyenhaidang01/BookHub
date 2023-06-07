cmake_minimum_required(VERSION 3.12)
project(BookHub)

# C++ standard version
set(CMAKE_CXX_STANDARD 11)

# Add the library files
set(LIBRARY_FILES
    Book.h
    Novel.h
    TextBook.h
    SkillBook.h
    BookSearcher.h
    Warehouse.h
    Reporter.h
    MenuView.h 
    BookHub.h  
)

# Add the main.cpp file
set(MAIN_FILE main.cpp)

# Add the text files
set(DATA_FILES
    warehouse.txt
    log.txt
)

# Add the executable target
add_executable(BookHub ${MAIN_FILE} ${LIBRARY_FILES})

# Copy the data files to the build directory
foreach(DATA_FILE ${DATA_FILES})
    configure_file(${DATA_FILE} ${CMAKE_CURRENT_BINARY_DIR}/${DATA_FILE} COPYONLY)
endforeach()