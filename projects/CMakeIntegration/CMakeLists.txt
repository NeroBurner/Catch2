cmake_minimum_required( VERSION 3.5 )

project( Catch2CMakeIntegrationTest LANGUAGES CXX )

add_executable(${PROJECT_NAME} CMakeCTestRegistration.tests.cpp)

include(${CATCH_DIR}/contrib/ParseAndAddCatchTests.cmake)
ParseAndAddCatchTests(${PROJECT_NAME})
