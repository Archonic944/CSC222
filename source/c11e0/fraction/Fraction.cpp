#include <iostream>
#include "Fraction.h"
#include <numeric>
#include <stdexcept>

using namespace std;

//Helpers, to_string, equals (the boring stuff)

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

string Fraction::to_string() {
    if(den == 1) return std::to_string(num);
    return std::to_string(num) + "/" + std::to_string(den);
}

bool Fraction::equals(const Fraction& f) const{
    return f.num == this->num && f.den == this->den;
}

//Constructors

Fraction::Fraction(string str){
    int indexOfSlash1 = str.find_first_of("/");
    if(indexOfSlash1 == -1 || (indexOfSlash1 != str.find_last_of("/"))){
        if(is_number(str)){
            (*this) = Fraction(stoi(str), 1);
            return;
        }else throw invalid_argument("Invalid fraction string: " + str);
    }
    string numStr = str.substr(0, indexOfSlash1);
    string denoStr = str.substr(indexOfSlash1 + 1, str.length() - (indexOfSlash1 + 1));
    if(!is_number(numStr) || !is_number(denoStr)){
        throw invalid_argument("Invalid fraction string: " + str);
    }
    (*this) = Fraction (stoi(numStr), stoi(denoStr));
}

Fraction::Fraction(int n){
    (*this) = Fraction(n, 1);
}

Fraction::Fraction() {
    num = 0;
    den = 1;
}

Fraction::Fraction(int n, int d) {
    int gcd = std::gcd(n, d);
    num = n/gcd;
    den = d/gcd;
}

//Arithmetic operators + functions leftover from previous exercise

Fraction Fraction::operator+(const Fraction& f) const {
    int n = this->num * f.den + f.num * this->den;
    int d = f.den * this->den;
    return Fraction(n, d);
}

Fraction Fraction::operator-(const Fraction& f) const {
    int den = f.den * this->den;
    int num = this->num * f.den - f.num * this->den;
    return Fraction(num, den);
}

Fraction Fraction::operator*(const Fraction& f) const {
    int num = this->num * f.num;
    int den = this->den * f.den;
    return Fraction(num, den);
}

Fraction Fraction::operator/(const Fraction& f) const {
    int num = f.den * this->num;
    int den = f.num * this->den;
    return Fraction(num, den);
}

//Comparison operators

bool Fraction::operator>(const Fraction& f) const{
    return (this->num * f.den) > (f.num * this->den);
};

bool Fraction::operator>=(const Fraction& f) const{
    return this->operator>(f) || this->equals(f);
};

bool Fraction::operator<(const Fraction& f) const{
    return !(this->operator>=(f));;
};

bool Fraction::operator<=(const Fraction& f) const{
    return this->operator<(f) || this->equals(f);
};

bool Fraction::operator==(const Fraction& f) const{
    return this->equals(f);
};

bool Fraction::operator!=(const Fraction& f) const{
    return !(this->equals(f));
};

//Comparison operators with integers

// Comparison operators with integers
bool Fraction::operator>(int value) const {
    return *this > Fraction(value);
}

bool Fraction::operator<(int value) const {
    return *this < Fraction(value);
}

bool Fraction::operator>=(int value) const {
    return *this >= Fraction(value);
}

bool Fraction::operator<=(int value) const {
    return *this <= Fraction(value);
}

bool Fraction::operator==(int value) const {
    return *this == Fraction(value);
}

bool Fraction::operator!=(int value) const {
    return *this != Fraction(value);
}