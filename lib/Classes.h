#ifndef Kernal
#define Kernal

// To get clear fuctionality (without deep explanation) delete code between //{ .... }// and clean up ukrainian expalnations

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class Fraction {
public:
    int numerator;
    int denominator;

    Fraction();
    Fraction(int n);
    Fraction(int n, int d);
    Fraction(const Fraction& temp);

    Fraction& operator= (const Fraction& a);
    bool operator!= (const Fraction& a);
    Fraction operator+ (const Fraction& a);
    Fraction operator- (const Fraction& a);
    Fraction operator* (const Fraction& a);
    Fraction operator/ (const Fraction& a);
    friend std::ostream& operator<< (std::ostream& out, const Fraction& temp);
    friend std::istream& operator>> (std::istream& in, Fraction& temp);

    Fraction GCD();       //Great Common Divisor
    int lenth();
};

class Matrix {
public:
    int i_size, j_size;
    std::vector <std::vector <Fraction>> matrix;

    Matrix();
    Matrix(int i_size, int j_size, std::vector <std::vector <Fraction>> matrix);
    Matrix(const Matrix& a);

    Matrix& operator= (const Matrix& a);
    bool operator!= (const Matrix& a);
    Matrix operator+ (const Matrix& a);
    Matrix operator- (const Matrix& a);
    Matrix operator* (const Matrix& a);
    friend Matrix operator* (Fraction& a, Matrix& b);
    friend std::ostream& operator<< (std::ostream& out, const Matrix& temp);
    friend std::istream& operator>> (std::istream& in, Matrix& temp);

    Matrix Gaussian_Method();
    Matrix minor(int i, int j);
    Fraction determinant();
    Matrix transpose();
    Matrix inverse();
    int rank();
};

namespace Math {
    Fraction pow(Fraction a, int b);
}

#endif
