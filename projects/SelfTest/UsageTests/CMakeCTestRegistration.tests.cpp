#include "catch.hpp"

#include <tuple>

namespace { namespace CMakeCTestRegistrationTests {

struct FakeFixture{};


SCENARIO(){}
SCENARIO("scenario_no_tag"){}
SCENARIO("scenario", "[cmake_integration]"){}

SCENARIO_METHOD(FakeFixture){}
SCENARIO_METHOD(FakeFixture, "scenario_method_no_tag"){}
SCENARIO_METHOD(FakeFixture, "scenario_method", "[cmake_integration]"){}

TEMPLATE_TEST_CASE("template_test_case_empty_tag", "", int){}
TEMPLATE_TEST_CASE("template_test_case", "[cmake_integration]", int){}

TEST_CASE(){}
TEST_CASE("test_case_no_tag"){}
TEST_CASE("test_case", "[cmake_integration]"){}

TEST_CASE_METHOD(FakeFixture){}
TEST_CASE_METHOD(FakeFixture, "test_case_method_no_tag"){}
TEST_CASE_METHOD(FakeFixture, "test_case_method", "[cmake_integration]"){}

}} // namespace CMakeCTestRegistrationTests
