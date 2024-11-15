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

TEST_CASE("Testing only_odds") {
    vector<int> nums = {1, 2, 3, 4, 6, 7, 8, 11, 12, 14, 27, 22};
    vector<int> evens = only_odds(nums);
    string expected = "1 3 7 11 27";
    CHECK(render_num_vector(evens) == expected);
}

TEST_CASE("Testing nums_between function") {
    //should be ≥ 10 and ≤ 20
    vector<int> nums = {11, 2, 13, 4, 10, 26, 7, 88, 19, 20, 14, 5, 32};
    vector<int> nums2 = nums_between(nums, 10, 20);
    string expected = "11 13 10 19 20 14";
    CHECK(render_num_vector(nums2) == expected);
}

TEST_CASE("Testing mean function") {
    vector<int> nums = {1, 2, 3, 4, 5};
    CHECK(mean(nums) == 3.0);

    nums = {10, 20, 30, 40, 50};
    CHECK(mean(nums) == 30.0);

    nums = {5, 10, 15};
    CHECK(mean(nums) == 10.0);
}

TEST_CASE("Testing median function") {
    vector<int> nums1 = {1, 2, 3, 4, 5};
    double expected1 = 3.0;
    CHECK(median(nums1) == doctest::Approx(expected1));

    vector<int> nums2 = {1, 2, 3, 4, 5, 6};
    double expected2 = 3.5;
    CHECK(median(nums2) == doctest::Approx(expected2));
}

