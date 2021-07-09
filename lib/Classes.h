#ifndef Kernal
#define Kernal

// To get clear fuctionality (without deep explanation) delete code between //{ .... }// and clean up ukrainian expalnations

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <limits>
#include <algorithm>

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
    void set_i_size(int i);
    void set_j_size(int j);
    void set_matrix(std::vector <std::vector <Fraction>> mat);
    void set_matrix(int i, std::vector <Fraction> row);
    void set_matrix(int i, int j, Fraction a);
    Matrix main_matrix();
    Matrix Gaussian_Method();
    std::vector <Matrix> Gaussian_Method_With_Extract_Answer();
    Matrix minor(int i, int j);
    Matrix minor(std::vector <int> a, std::vector <int> b);
    Fraction determinant();
    Matrix transpose();
    Matrix inverse();
    int rank();
    bool linear_independence();
    Matrix basis();
    std::vector <std::vector <Fraction>> Cramer_Method();
};

namespace Math {
    Fraction pow(Fraction a, int b);
    //{
    Fraction Determinant_with_explanation(Matrix temp);
    //}
}

#endif
