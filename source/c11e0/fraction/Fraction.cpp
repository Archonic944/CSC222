#include <iostream>
#include "Fraction.h"
#include <numeric>

using namespace std;

string Fraction::to_string() {
    return std::to_string(num) + "/" + std::to_string(den);
}

bool Fraction::equals(Fraction f){
    Fraction f1 = this->reduce();
    Fraction f2 = f.reduce();
    return f1.num == f2.num && f1.den == f2.den;
}

Fraction Fraction::reduce() {
    int gcd = std::gcd(num, den);
    return Fraction(num / gcd, den / gcd);
}

Fraction Fraction::plus(Fraction f) {
    int n = this->num * f.den + f.num * this->den;
    int d = f.den * this->den;
    return Fraction(n, d);
}

Fraction::Fraction(int n, int d) {
    num = n;
    den = d;
}

Fraction::Fraction() {
    num = 0;
    den = 1;
}

Fraction Fraction::minus(Fraction f){
    int den = f.den * this->den;
    int num = this->num * f.den - f.num * this->den;
    return Fraction(num,den);
}