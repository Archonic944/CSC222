#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include <vector>
#include "num_vector_utils.h"
using namespace std;

TEST_CASE("3 elements, testing render_num_vector") {
    {
    vector<int> nums = {1, 3, 7};
    string numstr = render_num_vector(nums);
    string expected = "1 3 7";
    CHECK(numstr == expected);
    }
    {
    vector<int> nums = {1, 3, 7, 8};
    string numstr = render_num_vector(nums);
    string expected = "1 3 7 8";
    CHECK(numstr == expected);
    }
    {
    string expected = "";
    vector<int> nums = {};
    string numstr = render_num_vector(nums);
    CHECK(numstr == expected);
    }
}

TEST_CASE("Testing num_vector_sum") {
    vector<int> nums = {1, 3, 7};
    CHECK(11 == num_vector_sum(nums));
    CHECK(15 == num_vector_sum({1, 2, 3, 4, 5}));
    CHECK(0 == num_vector_sum({}));
}

TEST_CASE("Testing num_vector_product") {
    vector<int> nums = {2, 3, 7};
    CHECK(42 == num_vector_product(nums));
    CHECK(50 == num_vector_product({25, 2}));
    CHECK(60 == num_vector_product({5, 6, 2}));
}

TEST_CASE("Testing only_evens") {
    vector<int> nums = {1, 2, 3, 4, 6, 7, 8, 11, 12, 14, 27, 22};
    vector<int> evens = only_evens(nums);
    string expected = "2 4 6 8 12 14 22";
    CHECK(render_num_vector(evens) == expected);
}