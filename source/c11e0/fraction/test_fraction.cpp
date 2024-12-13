#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "Fraction.h"

using namespace std;

TEST_CASE("Test print"){
    Fraction f(1, 2);
    CHECK(f.to_string() == "1/2");
    Fraction f_0 = Fraction();
    CHECK(f_0.to_string() == "0");
}

TEST_CASE("Test can create Fractions using two constructors") {
    Fraction f1;
    CHECK(f1.num == 0);
    CHECK(f1.den == 1);
    Fraction f2(3, 4);
    CHECK(f2.num == 3);
    CHECK(f2.den == 4);
}

TEST_CASE("Test third Fraction constructor using a string") {
    Fraction f1("3/4");
    CHECK(f1.num == 3);
    CHECK(f1.den == 4);
    Fraction f2("37/149");
    cout << f2.num << " <== num in test case" << endl;
    CHECK(f2.num == 37);
    CHECK(f2.den == 149);
}

TEST_CASE("Test Fractions are stored in lowest terms") {
    Fraction f1(6, 8);
    CHECK(f1.to_string() == "3/4");
    Fraction f2(8, 16);
    CHECK(f2.to_string() == "1/2");
}

TEST_CASE("Test can construct Fraction from integer") {
    Fraction f1(5);
    CHECK(f1.num == 5);
    CHECK(f1.den == 1);
    Fraction f2(42);
    CHECK(f2.num == 42);
    CHECK(f2.den == 1);
}

TEST_CASE("Test integer Fractions render properly") {
    Fraction f1(5, 1);
    CHECK(f1.to_string() == "5");
    Fraction f2(18, 3);
    CHECK(f2.to_string() == "6");
}

TEST_CASE("Test string constructor with integers") {
    Fraction f1("15");
    cout << f1.num << endl;
    CHECK(f1.num == 15);
    CHECK(f1.den == 1);
    Fraction f2("42");
    CHECK(f2.num == 42);
    CHECK(f2.den == 1);
}

TEST_CASE("Test comparison operators for Fractions") {
    Fraction f1(1, 4);
    Fraction f2(3, 4);
    Fraction f3(2, 5);
    Fraction f4(6, 8);
    CHECK((f2 > f1) == true);
    CHECK((f2 == f4) == true);
    CHECK((f1 < f3) == true);
    CHECK((f3 != f2) == true);
    CHECK((f4 >= f1) == true);
    CHECK((f4 <= f2) == true);
}

TEST_CASE("Test arthmetic operators"){
    Fraction f1(1, 4);
    Fraction f2(1,2);
    Fraction f3(2, 5);
    Fraction f4(1, 5);
    Fraction f5(4,5);
    Fraction f6(2);

    CHECK((f1 + f1) == f2);
    CHECK(f1 * f6 == f2);
    CHECK(f2 * f3 == f4);
    CHECK(f3 - f4 == f4);
    CHECK(f3 / f2 == f5);
}