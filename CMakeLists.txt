

#------------------------------
# notes:
#   I tried, but honestly not sure about this set up
#   I've only added the libraries of patron and person
#   for now, and only the tests for patron. (10/22/26)
#   
# -----------------------------
cmake_minimum_required(VERSION 3.16)
project(CS410-Project)
set(CMAKE_CXX_STANDARD 17)

# -----------------------------
# Class Libraries
# -----------------------------

# gets source files to compile, for person&patron
#add_library(person src/Person.cpp)
#target_include_directories(person PUBLIC include)

#add_library(patron src/Patron.cpp)
#target_include_directories(patron PUBLIC include)
#target_link_libraries(patron PUBLIC person) # cuz patron inherits person

#add_library(librarian src/Librarian.cpp)
#target_include_directories(librarian PUBLIC include)
#target_link_libraries(librarian PUBLIC person) # cuz patron inherits person

#add_library(library src/Library.cpp)
#target_include_directories(library PUBLIC include)

#add_library(catalog src/Catalog.cpp)
#target_include_directories(catalog PUBLIC include)

#add_library(item src/Item.cpp src/Book.cpp src/Game.cpp src/Audiobook.cpp)
#target_include_directories(item PUBLIC include)
#target_link_libraries(item PUBLIC patron)

file(GLOB CORE_SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp) #NEW LINE
list(REMOVE_ITEM CORE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)#NEW LINE
add_library(core ${CORE_SOURCES})#NEW LINE
target_include_directories(core PUBLIC include)#NEW LINE

# -----------------------------
# include directories
# -----------------------------

add_executable(app src/main.cpp)
target_link_libraries(app PRIVATE core)#NEW LINE
#target_link_libraries(app PRIVATE patron)
#target_link_libraries(app PRIVATE person)
#target_link_libraries(app PRIVATE librarian)
#target_link_libraries(app PRIVATE library)
#target_link_libraries(app PRIVATE catalog)
#target_link_libraries(app PRIVATE item)
# -----------------------------
# Fetch GoogleTest
# -----------------------------

# makes googletest available to the project
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE#NEW LINE
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)#NEW LINE
FetchContent_MakeAvailable(googletest)

# -----------------------------
# GoogleTest Target Creation
# -----------------------------

enable_testing()
include(GoogleTest)#NEW LINE
add_custom_target(all_tests)#NEW LINE

#add_executable(patron_tests tests/test_patron.cpp)
# add_executable(patron_tests tests/test_person.cpp)

#target_link_libraries(patron_tests PRIVATE
#    person
#    patron
#    GTest::gtest_main
#)

#include(GoogleTest)
#gtest_discover_tests(patron_tests)

#add_executable(item_tests tests/test_item.cpp)

#target_link_libraries(item_tests PRIVATE
#    person
#    patron
#    item
#    GTest::gtest_main
#)
#gtest_discover_tests(item_tests)

#everything below is new

file(GLOB TEST_SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_*.cpp)
foreach(test_src ${TEST_SOURCES})  
    get_filename_component(name ${test_src} NAME_WE)  
    string(REGEX REPLACE "^test_" "" name ${name})  
    add_executable(${name}_tests ${test_src})  
    target_link_libraries(${name}_tests PRIVATE core GTest::gtest_main)  
    gtest_discover_tests(${name}_tests DISCOVERY_MODE PRE_TEST)  
    add_dependencies(all_tests ${name}_tests)  
endforeach() 


# -----------------------------
# commands/notes
# -----------------------------

# cmake -S . -B build
# cmake --build build

# ctest --test-dir build