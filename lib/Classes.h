#ifndef Kernal
#define Kernal

// To get clear fuctionality (without deep explanation) delete code between //{ .... }// and clean up ukrainian expalnations

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class Fraction {
    int numerator;
    int denominator;

public:
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

    int get_numerator();
    int get_denominator();
    void set_numerator(int a);
    void set_denominator(int a);
    Fraction GCD();       //Great Common Divisor
    int lenth();
};

class Matrix {
    int i_size, j_size;
    std::vector <std::vector <Fraction>> matrix;

public:
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

    int get_i_size();
    int get_j_size();
    std::vector <std::vector <Fraction>> get_matrix();
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
