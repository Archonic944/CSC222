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

TEST_CASE("Test equals"){
    Fraction f1(1, 2);
    Fraction f2(2, 4);
    CHECK(f1.equals(f2) == true);
    Fraction f3(1, 3);
    CHECK(f1.equals(f3) == false);
}

TEST_CASE("Test multiply"){
    Fraction f1(1, 4);
    Fraction f2(2,3);
    Fraction f3 = f1.times(f2);
    CHECK(f3.equals(Fraction(1, 6)));
}

TEST_CASE("Test divided_by"){
    Fraction f1(1, 4);
    Fraction f2(2, 3);
    Fraction f3 = f1.divided_by(f2);
    CHECK(f3.equals(Fraction(3, 8)));
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