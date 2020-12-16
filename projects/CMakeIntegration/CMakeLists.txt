cmake_minimum_required( VERSION 3.5 )

project( Catch2CMakeIntegrationTest LANGUAGES CXX )

# CATCH_DIR is normally set by Catch project, but to make this example self contained define a default dir
set(CATCH_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../.." CACHE STRING "Path to root of Catch project directory")

add_executable(${PROJECT_NAME} CMakeCTestRegistration.tests.cpp)
target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${CATCH_DIR}/single_include/catch2/)

include(${CATCH_DIR}/contrib/ParseAndAddCatchTests.cmake)
ParseAndAddCatchTests(${PROJECT_NAME})
