cmake_minimum_required( VERSION 3.5...${CMAKE_VERSION})

project( Catch2CMakeIntegrationTest LANGUAGES CXX )

# CATCH_DIR is normally set by Catch project, but to make this example self contained define a default dir
set(CATCH_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../.." CACHE STRING "Path to root of Catch project directory")

add_executable(${PROJECT_NAME} CMakeCTestRegistration.tests.cpp)
target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${CATCH_DIR}/single_include/catch2/)

if(BUILD_TESTING AND CATCH_BUILD_TESTING)
    enable_testing()
endif()
#include(${CATCH_DIR}/contrib/ParseAndAddCatchTests.cmake)
#ParseAndAddCatchTests(${PROJECT_NAME})
include(${CATCH_DIR}/contrib/Catch.cmake)
catch_discover_tests(${PROJECT_NAME})
