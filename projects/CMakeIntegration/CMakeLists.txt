cmake_minimum_required( VERSION 3.5 )

project( Catch2CMakeIntegrationTest LANGUAGES CXX )

add_executable(${PROJECT_NAME} CMakeCTestRegistration.tests.cpp)
target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${CATCH_DIR}/single_include/catch2/)

include(${CATCH_DIR}/contrib/ParseAndAddCatchTests.cmake)
ParseAndAddCatchTests(${PROJECT_NAME})
