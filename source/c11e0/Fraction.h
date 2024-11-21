struct Fraction {
    int num;
    int den;

    Fraction(int n, int d);
    Fraction();

    void print();
    Fraction plus(Fraction f);
    Fraction minus(Fraction f);
    Fraction times(Fraction f);
    Fraction divided_by(Fraction f);
};