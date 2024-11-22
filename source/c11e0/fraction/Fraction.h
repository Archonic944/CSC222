struct Fraction {
    int num;
    int den;

    Fraction(int n, int d);
    Fraction();

    //NOTE: I decided to implement to_string instead of print because it's easier to test
    std::string to_string();

    Fraction plus(Fraction f);
    Fraction minus(Fraction f);
    Fraction times(Fraction f);
    Fraction divided_by(Fraction f);
    Fraction reduce();
    bool equals(Fraction f);
};