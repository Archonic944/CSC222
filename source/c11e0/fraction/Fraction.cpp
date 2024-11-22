#include <iostream>
#include "Fraction.h"
#include <numeric>

using namespace std;

string Fraction::to_string() {
    return std::to_string(num) + "/" + std::to_string(den);
}

bool Fraction::equals(Fraction f){
    return f.num == this->num && f.den == this->den;
}

Fraction Fraction::plus(Fraction f) {
    int n = this->num * f.den + f.num * this->den;
    int d = f.den * this->den;
    return Fraction(n, d);
}

Fraction::Fraction(int n, int d) {
    int gcd = std::gcd(n, d);
    num = n/gcd;
    den = d/gcd;
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

Fraction Fraction::times(Fraction f){
    int num = this->num * f.num;
    int den = this->den * f.den;
    return Fraction(num, den);
}

Fraction Fraction::divided_by(Fraction f){
    int num = f.den * this->num;
    int den = f.num * this->den;
    return Fraction(num, den);
}