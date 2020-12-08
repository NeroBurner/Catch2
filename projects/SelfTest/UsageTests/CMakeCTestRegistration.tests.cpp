#include "catch.hpp"

#include <tuple>

namespace { namespace CMakeCTestRegistrationTests {

static void testFunction(){}

struct FakeFixture
{
    void fakeTest(){}
};
template<typename...> struct TemplateFixture{};
template<int> struct FixtureWithValue{};

template<typename> struct TemplateStruct{};
template<int> struct CompileTimeValue{};

using SimpleTestTypes = std::tuple<int>;


SCENARIO(){}
SCENARIO("scenario_no_tag"){}
SCENARIO("scenario", "[cmake_integration]"){}

SCENARIO_METHOD(FakeFixture){}
SCENARIO_METHOD(FakeFixture, "scenario_method_no_tag"){}
SCENARIO_METHOD(FakeFixture, "scenario_method", "[cmake_integration]"){}

TEMPLATE_TEST_CASE("template_test_case_empty_tag", "", int){}
TEMPLATE_TEST_CASE("template_test_case", "[cmake_integration]", int){}

TEMPLATE_TEST_CASE_SIG("template_test_case_sig", "[cmake_integration]", ((int V), V), 42){}

TEMPLATE_TEST_CASE_METHOD(TemplateFixture, "template_test_case_method_empty_tag", "", int){}
TEMPLATE_TEST_CASE_METHOD(TemplateFixture, "template_test_case_method", "[cmake_integration]", int){}

TEMPLATE_TEST_CASE_METHOD_SIG(FixtureWithValue,
                              "template_test_case_method_sig",
                              "[cmake_integration]",
                              ((int V), V), 42){}

TEMPLATE_LIST_TEST_CASE("template_list_test_case_empty_tag", "", SimpleTestTypes){}
TEMPLATE_LIST_TEST_CASE("template_list_test_case", "[cmake_integration]", SimpleTestTypes){}

TEMPLATE_LIST_TEST_CASE_METHOD(TemplateFixture, "template_list_test_case_method_empty_tag", "",
                               SimpleTestTypes){}
TEMPLATE_LIST_TEST_CASE_METHOD(TemplateFixture,
                               "template_list_test_case_method", "[cmake_integration]",
                               SimpleTestTypes){}

TEMPLATE_PRODUCT_TEST_CASE("template_product_test_case_empty_tag", "", TemplateStruct, int){}
TEMPLATE_PRODUCT_TEST_CASE("template_product_test_case", "[cmake_integration]", TemplateStruct, int){}

TEMPLATE_PRODUCT_TEST_CASE_SIG("template_product_test_case_sig", "[cmake_integration]",
                               ((int V), V), CompileTimeValue, 42){}

TEMPLATE_PRODUCT_TEST_CASE_METHOD(TemplateFixture,
                                  "template_product_test_case_method",
                                  "[cmake_integration]",
                                  TemplateStruct, int){}

TEMPLATE_PRODUCT_TEST_CASE_METHOD_SIG(TemplateFixture,
                                      "template_product_test_case_method_sig", "[cmake_integration]",
                                      ((int V), V), CompileTimeValue, 42){}

TEST_CASE(){}
TEST_CASE("test_case_no_tag"){}
TEST_CASE("test_case", "[cmake_integration]"){}

TEST_CASE_METHOD(FakeFixture){}
TEST_CASE_METHOD(FakeFixture, "test_case_method_no_tag"){}
TEST_CASE_METHOD(FakeFixture, "test_case_method", "[cmake_integration]"){}

ANON_TEST_CASE(){}

METHOD_AS_TEST_CASE(FakeFixture::fakeTest)
METHOD_AS_TEST_CASE(FakeFixture::fakeTest, "method_as_test_case_no_tag")
METHOD_AS_TEST_CASE(FakeFixture::fakeTest, "method_as_test_case", "[cmake_integration]")

REGISTER_TEST_CASE(testFunction)
REGISTER_TEST_CASE(testFunction, "register_test_case_no_tag")
REGISTER_TEST_CASE(testFunction, "register_test_case", "[cmake_integration]")

}} // namespace CMakeCTestRegistrationTests
