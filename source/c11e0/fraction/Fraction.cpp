#include <iostream>
#include "Fraction.h"
#include <numeric>
#include <stdexcept>

using namespace std;

string Fraction::to_string() {
    if(den == 1) return std::to_string(num);
    return std::to_string(num) + "/" + std::to_string(den);
}

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

bool Fraction::equals(Fraction f){
    return f.num == this->num && f.den == this->den;
}

Fraction Fraction::plus(Fraction f) {
    int n = this->num * f.den + f.num * this->den;
    int d = f.den * this->den;
    return Fraction(n, d);
}

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

Fraction::Fraction(int n, int d) {
    int gcd = std::gcd(n, d);
    num = n/gcd;
    den = d/gcd;
}

Fraction::Fraction(int n){
    (*this) = Fraction(n, 1);
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