

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
add_library(person src/Person.cpp)
target_include_directories(person PUBLIC include)

add_library(patron src/Patron.cpp)
target_include_directories(patron PUBLIC include)
target_link_libraries(patron PUBLIC person) # cuz patron inherits person

# -----------------------------
# include directories
# -----------------------------

add_executable(app src/main.cpp)
target_link_libraries(app PRIVATE patron)

# -----------------------------
# Fetch GoogleTest
# -----------------------------

# makes googletest available to the project
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

# -----------------------------
# GoogleTest Target Creation
# -----------------------------

enable_testing()

add_executable(patron_tests tests/test_patron.cpp)
# add_executable(patron_tests tests/test_person.cpp)

target_link_libraries(patron_tests PRIVATE
    person
    patron
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(patron_tests)


# -----------------------------
# commands/notes
# -----------------------------

# cmake -D . -B build
# cmake --build build

# ctest --test-dir build