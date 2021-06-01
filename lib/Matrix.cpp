#include "./Classes.h"

Matrix::Matrix() {
    i_size = 0;
    j_size = 0;
    Fraction fr(0, 1);
    std::vector <std::vector <Fraction>> temp {{fr}};
    matrix = temp;
};

Matrix::Matrix(int i, int j, std::vector <std::vector <Fraction>> matr) {
    i_size = i;
    j_size = j;
    matrix = matr;
}

Matrix::Matrix(Matrix& a) {
    i_size = a.i_size;
    j_size = a.j_size;
    matrix = a.matrix;
}

Matrix& Matrix::operator= (const Matrix &a) {
    if (this != &a) {
        i_size = a.i_size;
        j_size = a.j_size;
        matrix = a.matrix;
    }

    return *this;
}

Matrix Matrix::operator+ (const Matrix &a) {
    Matrix temp(*this);
    if (i_size == a.i_size && j_size == a.j_size) {
        for (int i = 0; i <= i_size; i++) {
            for (int j = 0; j <= j_size; j++) {
                temp.matrix[i][j] = matrix[i][j] + a.matrix[i][j];
            }
        }
    }
    else {
        std::cout << "\nError!! Diferent dimentions. \n";
    }

    return temp;
}

Matrix Matrix::operator- (const Matrix &a) {
    Matrix temp(*this);
    if (i_size == a.i_size && j_size == a.j_size) {
        for (int i = 0; i <= i_size; i++) {
            for (int j = 0; j <= j_size; j++) {
                temp.matrix[i][j] = matrix[i][j] - a.matrix[i][j];
            }
        }
    }
    else {
        std::cout << "\nError!! Diferent dimentions. \n";
    }

    return temp;
}

Matrix Matrix::operator* (const Matrix &a) {
    std::vector <std::vector <Fraction>> vec(i_size + 1, std::vector <Fraction> (a.j_size + 1));
    Matrix temp(i_size, a.j_size, vec);
    if (j_size == a.i_size) {
        for (int i = 0; i <= i_size; i++) {
            for (int a_j = 0; a_j <= a.j_size; a_j++) {
                Fraction buff, fr;
                for (int j = 0, a_i = 0; j <= j_size; j++, a_i++) {
                    fr = (matrix[i][j] * a.matrix[a_i][a_j]);
                    buff = buff + fr;
                }
                temp.matrix[i][a_j] = buff;
            }
        }
    }
    else {
        std::cout << "\nError!! Diferent dimentions. \n";
    }

    return temp;
}

std::ostream& operator<< (std::ostream& out, Matrix& temp) {
    int len = 3;
    for (int i = 0; i <= temp.i_size; i++) {
        for (int j = 0; j <= temp.j_size; j++) {
            int l = temp.matrix[i][j].lenth();
            if (len < l) len = l;
        }
    }

    for (int i = 0; i <= temp.i_size; i++) {
        out << "|";
        for (int j = 0; j <= temp.j_size; j++) {
            for (int k = 0; k < len - temp.matrix[i][j].lenth() + 2; k++) {
                out << " ";
            }
            if (temp.matrix[i][j].numerator == 0 || temp.matrix[i][j].denominator == 1) out << "  ";
            out << temp.matrix[i][j];
        }
        out << " | \n";
    }

    return out;
}

std::istream& operator>> (std::istream& in, Matrix& temp) {
    in >> temp.i_size >> temp.j_size;
    while(temp.i_size < 0 && temp.j_size < 0) {
        std::cout << "The dimension of the matrix cannot be negative! Try again. \n";
    }
    std::vector <Fraction> b;
    temp.matrix.clear();
    for (int i = 0; i <= temp.i_size; i++) {
        for (int j = 0; j <= temp.j_size; j++) {
            Fraction fr;
            in >> fr;
            b.push_back(fr);
        }
        temp.matrix.push_back(b);
        b.clear();
    }

    return in;
}

Matrix Matrix::minor (int i, int j) {
    Matrix temp(*this);
    if (i_size != 0 && j_size != 0) {
        if (i >= 0 && i <= i_size && j >= 0 && j <= j_size) {
            temp.matrix.erase(temp.matrix.begin() + i);
            temp.i_size--;
            for (int k = 0; k <= temp.i_size; k++) {
                temp.matrix[k].erase(temp.matrix[k].begin() + j);
            }
            temp.j_size--;
        }
        else {
            std::cout << "Error!! Wrong minor`s indexes. \n";
        }
    }
    else {
        std::cout << "Error!! The dimention of the matrix is too low to take a minor. \n";
    }

    return temp;
}

Fraction Matrix::determinant() {
    Fraction determinat;

    if (i_size != j_size) {
        std::cout << "Error!! It is not a square matrix. \n";
    }
    else {
        if (i_size == 0 && j_size == 0) {
            determinat = matrix[0][0];
        }
        else if (i_size == 1 && j_size == 1) {
            determinat = matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
        }
        else {
            for (int j = 0; j <= j_size; j++) {
                Fraction fr(-1, 1);
                fr = Math::pow(fr, j+2);
                determinat = determinat + fr * matrix[0][j] * this->minor(0, j).determinant();
            }
        }
    }

    return determinat;
}

Matrix Matrix::transpose() {
    std::vector <std::vector <Fraction>> vec;

    for (int j = 0; j <= j_size; j++) {
        std::vector <Fraction> buff;
        for (int i = 0; i <= i_size; i++) {
            buff.push_back(matrix[i][j]);
        }
        vec.push_back(buff);
        buff.clear();
    }
    Matrix temp(j_size, i_size, vec);

    return temp;
}

Matrix Matrix::inverse() {
    Matrix temp(*this), trans;
    trans = this->transpose();
    Fraction determ = this->determinant();
    if (determ.numerator == 0 ) {
        std::cout << "Error!! Inverse matrix cannot be found cause of determinant is equal to zero. \n";
    }
    else {
    for (int i = 0; i <= temp.i_size; i++) {
            Fraction fr(1, 1);
            for (int j = 0; j <= temp.j_size; j++) {
                Fraction fr2(-1, 1);
                fr2 = Math::pow(fr2, i + j);
                temp.matrix[i][j] = fr / determ * fr2 * trans.minor(i, j).determinant();
            }
        }
    }

    return temp;
}
