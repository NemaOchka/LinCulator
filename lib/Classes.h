#ifndef Kernal
#define Kernal

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

class Fraction {
public:
    int numerator;
    int denominator;

    Fraction();
    Fraction(int n);
    Fraction(int n, int d);
    Fraction(const Fraction& temp);

    Fraction& operator= (const Fraction& a);
    Fraction operator+ (const Fraction& a);
    Fraction operator- (const Fraction& a);
    Fraction operator* (const Fraction& a);
    Fraction operator/ (const Fraction& a);
    friend std::ostream& operator<< (std::ostream& out, Fraction& temp);
    friend std::istream& operator>> (std::istream& in, Fraction& temp);

    Fraction GCD();       //Great Common Divisor
    int lenth();
};

class Matrix {
   int i_size, j_size;
   std::vector <std::vector <Fraction>> matrix;

public:
    Matrix();
    Matrix(int i_size, int j_size, std::vector <std::vector <Fraction>> matrix);
    Matrix(Matrix& temp);

    Matrix& operator= (const Matrix& a);
    Matrix operator+ (const Matrix& a);
    Matrix operator- (const Matrix& a);
    Matrix operator* (const Matrix& a);
    friend std::ostream& operator<< (std::ostream& out, Matrix& temp);
    friend std::istream& operator>> (std::istream& in, Matrix& temp);

    Matrix minor(int i, int j);
    Fraction determinant();
    Matrix transpose();
    Matrix inverse();
};




namespace Math {
    Fraction pow(Fraction a, int b);
}

#endif
