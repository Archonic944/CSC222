#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "Fraction.h"

using namespace std;

TEST_CASE("Test print"){
    Fraction f(1, 2);
    CHECK(f.to_string() == "1/2");
    Fraction f_0 = Fraction();
    CHECK(f_0.to_string() == "0/1");
}

TEST_CASE("Test add"){
    Fraction f1(1, 2);
    Fraction f2(1, 3);
    Fraction f3 = f1.plus(f2);
    CHECK(f3.to_string() == "5/6");
}

TEST_CASE("Test minus"){
    Fraction f1(1,2);
    Fraction f2(1,6);
    Fraction f3 = f1.minus(f2);
    CHECK(f3.to_string() == "2/6");
}