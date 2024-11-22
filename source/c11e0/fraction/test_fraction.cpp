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
    CHECK(f3.equals(Fraction(5, 6)));
}

TEST_CASE("Test minus"){
    Fraction f1(1,2);
    Fraction f2(1,6);
    Fraction f3 = f1.minus(f2);
    CHECK(f3.equals(Fraction(1, 3)));
}

TEST_CASE("Test reduce"){
    Fraction f1(2, 4);
    Fraction f2 = f1.reduce();
    CHECK(f2.to_string() == "1/2");
}

TEST_CASE("Test equals"){
    Fraction f1(1, 2);
    Fraction f2(2, 4);
    CHECK(f1.equals(f2) == true);
    Fraction f3(1, 3);
    CHECK(f1.equals(f3) == false);
}