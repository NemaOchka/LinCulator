#include "./Classes.h"

extern int g_language, g_error;

Fraction::Fraction() {
    numerator = 0;
    denominator = 1;
}

Fraction::Fraction(int n) {
    numerator = n;
    denominator = 1;
}

Fraction::Fraction(int n, int d) {
    numerator = n;
    denominator = d;
}

Fraction::Fraction(const Fraction& temp) {
    numerator = temp.numerator;
    denominator = temp.denominator;
}

Fraction& Fraction::operator= (const Fraction& a) {
    if (this != &a) {
        numerator = a.numerator;
        denominator = a.denominator;
    }

    return *this;
}

bool Fraction::operator!= (const Fraction &a) {

    return !(numerator == a.numerator && denominator == a.denominator);
}

Fraction Fraction::operator+ (const Fraction& a) {
    Fraction temp(*this);
    temp.numerator = temp.numerator * a.denominator + a.numerator * temp.denominator;
    temp.denominator *= a.denominator;

    return temp.GCD();
}

Fraction Fraction::operator- (const Fraction& a) {
    Fraction temp(*this);
    temp.numerator = temp.numerator * a.denominator - a.numerator * temp.denominator;
    temp.denominator *= a.denominator;

    return temp.GCD();
}

Fraction Fraction::operator* (const Fraction &a) {
    Fraction temp(*this);
    temp.numerator *= a.numerator;
    temp.denominator *= a.denominator;

    return  temp.GCD();
}

Fraction Fraction::operator/ (const Fraction &a) {
    Fraction temp(*this);
    if (a.numerator != 0) {
        temp.numerator *= a.denominator;
        temp.denominator *= a.numerator;
    }
    else {
        if (g_language == 1) {
            std::cout << "Error!! You cannot divide by zero. \n";
        }
        else {
            std::cout << "Помилка!! Ділення на нуль. \n";
        }
        g_error = 1;
    }

    return temp.GCD();
}

std::ostream& operator<< (std::ostream& out, const Fraction& temp) {
    if (temp.numerator == 0) {
        out << temp.numerator;
    }
    else if (temp.denominator == 1) {
        out << temp.numerator;
    }
    else {
        out << temp.numerator << "/" << temp.denominator;
    }

    return out;
}

std::istream& operator>> (std::istream& in, Fraction& temp) {
    std::string fract, fract1, fract2;
again:
    in >> fract;
    fract.push_back('/');
    for (; fract[0] != '/';) {
        fract1.push_back(fract[0]);
        fract.erase(fract.begin());
    }
    if (fract.size() > 1) {
        fract.erase(fract.begin());
        for (; fract[0] != '/';) {
            fract2.push_back(fract[0]);
            fract.erase(fract.begin());
        }
    }
    else fract2.push_back('1');

    std::stringstream fr1(fract1);
    fr1 >> temp.numerator;

    std::stringstream fr2(fract2);
    fr2 >> temp.denominator;

    if (temp.denominator == 0) {
        if (g_language == 1) {
            std::cout << "Incorrect value!! Try again. \n";
        }
        else {
            std::cout << "Некоректне значення!! Спробуйте ще раз. \n";
        }
        fract1.clear();
        fract2.clear();
        goto again;
    }
    temp.GCD();

    return in;
}

int Fraction::get_numerator() {

    return this->numerator;
}

int Fraction::get_denominator() {

    return this->denominator;
}

void Fraction::set_numerator(int a) {
    numerator = a;
}

void Fraction::set_denominator(int a) {
    denominator = a;
}

Fraction Fraction::GCD() {
    int gcd = 1;

    if ((numerator < 0 || numerator > 0) && denominator < 0) {
        numerator *= -1;
        denominator *= -1;
    }

    for (int i = 1; i <= denominator; i++) {
        if (numerator % i == 0 && denominator % i == 0) {
        gcd = i;
        }
    }
    Fraction fr(numerator /= gcd, denominator /= gcd);

    return fr;
}

int Fraction::lenth() {
    std::string buff = std::to_string(numerator);
    buff.push_back('/');
    buff += std::to_string(denominator);
    int len = buff.size();

    return len;
}
