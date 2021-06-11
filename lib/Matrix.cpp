#include "./Classes.h"

extern int g_language, g_error;

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

Matrix::Matrix(const Matrix& a) {
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

bool Matrix::operator!= (const Matrix &a) {
    bool answer = true;

    if ((i_size == a.i_size) && (j_size == a.j_size)) {
        answer = false;
        for (int i = 0; i <= i_size; i++) {
            for (int j = 0; j <= j_size; j++) {
                if (matrix[i][j] != a.matrix[i][j]) {
                    answer = true;
                }
            }
        }
    }

    return answer;
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
        if (g_language == 1) {
            std::cout << "\nError!! Diferent dimentions. \n";
        }
        else {
            std::cout << "\nПомилка!! Розмірності не співпадають. \n";
        }
        g_error = 1;
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
        if (g_language == 1) {
            std::cout << "\nError!! Diferent dimentions. \n";
        }
        else {
            std::cout << "\nПомилка!! Розмірності не співпадають. \n";
        }
        g_error = 1;
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
        if (g_language == 1) {
            std::cout << "\nError!! Diferent dimentions. \n";
        }
        else {
            std::cout << "\nПомилка!! Розмірності не співпадають. \n";
        }
        g_error = 1;
    }

    return temp;
}

Matrix operator* (Fraction& a, Matrix& b) {
    Matrix temp(b);

    for (int i = 0; i <= temp.j_size; i++) {
        for (int j = 0; j <= temp.j_size; j++) {
            temp.matrix[i][j] = a * temp.matrix[i][j];
        }
    }

    return temp;
}

std::ostream& operator<< (std::ostream& out, const Matrix& a) {
    Matrix temp(a);
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
            if (temp.matrix[i][j].get_numerator() == 0 || temp.matrix[i][j].get_denominator() == 1) out << "  ";
            out << temp.matrix[i][j];
        }
        out << " | \n";
    }

    return out;
}

std::istream& operator>> (std::istream& in, Matrix& temp) {
    in >> temp.i_size >> temp.j_size;
    temp.i_size--;
    temp.j_size--;

    while(temp.i_size < 0 && temp.j_size < 0) {
        if (g_language == 1) {
            std::cout << "The dimension of the matrix cannot be negative! Try again. \n";
        }
        else {
            std::cout << "Розмірність матриці не може приймати негативне занчення! Спробуйте ще раз. \n";
        }
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

int Matrix::get_i_size() {

    return i_size;
}

int Matrix::get_j_size() {

    return j_size;
}

std::vector <std::vector <Fraction>> Matrix::get_matrix() {

    return matrix;
}

Matrix Matrix::Gaussian_Method() {
    Matrix temp(*this);

    //{
    Matrix check(*this);
    std::cout << "\n" << temp;
    //}
    for (int i = 0, k = 0; (i <= temp.i_size) && (k <= temp.j_size ); i++, k++) {
        start:
        if (temp.matrix[i][k].get_numerator() == 0) {
            int all_column_zero = 1;
            for (int g = i + 1; g <= temp.i_size && all_column_zero; g++) {
                if (temp.matrix[g][k].get_numerator() != 0) {
                    std::vector <Fraction> buff = temp.matrix[g];
                    temp.matrix[g] = temp.matrix[i];
                    temp.matrix[i] = buff;
                    all_column_zero = 0;
                 }
             }
             if (all_column_zero) {
                k++;
                goto start;
             }
        }
        //{
        if (temp != check) {
            std::cout << "\n" << temp;
            check = temp;
        }
        //}
        Fraction row_divider = temp.matrix[i][k];
        for (int j = k; j <= temp.j_size; j++) {
             temp.matrix[i][j] = temp.matrix[i][j] / row_divider;
        }
        //{
        if (temp != check) {
            std::cout << "\n" << temp;
            check = temp;
        }
        //}
        for (int h = i + 1; h <= temp.i_size; h++) {
            Fraction row_multiplier = temp.matrix[h][k];
            for (int j = k; j <= temp.j_size; j++) {
                temp.matrix[h][j] = temp.matrix[h][j] - row_multiplier * temp.matrix[i][j];
            }
        }
        //{
        if (temp != check) {
            std::cout << "\n" << temp;
            check = temp;
        }
        //}
    }

    /*
    int rank = i_size;
    for (int i = i_size; i >= 0; i--) {
        Fraction sum;
        for (int j = 0; j <= j_size; j++) {
            sum = sum + Math::pow(temp.matrix[i][j], 2);
        }
        if (sum.numerator == 0) {
            rank--;
        }
    }

    std::vector <Matrix> answer;
    if (rang == j_size - 1) {
        std::vector <Fraction> coordinats;
        for (int i = rang; i >= 0; i--) {
                Fraction sum = temp.matrix[i][j_size];
                for (int k = j_size - 1; k > i; k--) {
                    sum = sum - temp.matrix[i][k]*coordinats[k];
                }
                coordinats.insert(coordinats.begin(), sum);
        }
        Matrix vector(j_size - 1, 0, {coordinats});
        answer.push_back(vector);

        return answer;
    }
    else if (rang > j_size - 1) {

    }
    else {

    }
    */

    return temp;
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
            if (g_language == 1) {
                std::cout << "Error!! Wrong minor`s indexes. \n";
            }
            else {
                std::cout << "Помилка!! Не вірний індекс.  \n";
            }
            g_error = 1;
        }
    }
    else {
        if (g_language == 1) {
            std::cout << "Error!! The dimention of the matrix is too low to take a minor. \n";
        }
        else {
            std::cout << "помилка!! Розмірність матриці замала, щоб визначити мінор. \n";
        }
        g_error = 1;
    }

    return temp;
}

Fraction Matrix::determinant() {
    Fraction determinant;

    if (i_size != j_size) {
        if (g_language == 1) {
            std::cout << "Error!! It is not a square matrix. \n";
        }
        else {
            std::cout << "Помилка!! Це не квадратна матриця. \n";
        }
        g_error = 1;
    }
    else {
        if (i_size == 0 && j_size == 0) {
            determinant = matrix[0][0];
        }
        else {
            for (int j = 0; j <= j_size; j++) {
                Fraction fr(-1, 1);
                fr = Math::pow(fr, j+2);
                determinant = determinant + fr * matrix[0][j] * this->minor(0, j).determinant();
            }
        }
    }

    return determinant;
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
    Matrix temp(*this), trans = this->transpose();
    Fraction determ = this->determinant();

    if (determ.get_numerator() == 0 ) {
        if (g_language == 1) {
        std::cout << "Error!! Inverse matrix cannot be found cause of determinant is equal to zero. \n";
        }
        else {
            std::cout << "Помилка!! Обернена матриця не може бути знайдена, оскільки визначник дорівнює нулю. \n";
        }
        g_error = 1;
    }
    else {
        //{
        std::cout << "\nA' = 1/det(A) * (-1)^(i + j) * \n";
        for (int i = 0; i <= this->get_i_size(); i++) {
            std::cout << "|";
            for (int j = 0; j <= this->get_j_size(); j++) {
                std::cout << " A[" << j << "][" << i << "]";
            }
            std::cout << "|\n";
        }
        //}
        std::cout << "\ndet(A) = " << this->determinant() << "\n\n";
        for (int i = 0; i <= temp.i_size; i++) {
            Fraction fr(1, 1);
            for (int j = 0; j <= temp.j_size; j++) {
                Fraction fr2(-1, 1);
                fr2 = Math::pow(fr2, i + j);
                temp.matrix[i][j] = fr / determ * fr2 * trans.minor(i, j).determinant();
                //{
                std::cout << "A[" << j << "][" << i << "] = \n" << trans.minor(i, j);
                std::cout << "det(A[" << j << "][" << i << "])  =" << trans.minor(i, j).determinant() << "\n\n";
                //}
            }
        }
        //{
        if (g_language == 1) {
            std::cout << "The inverse matrix looks like: \n";
        }
        else {
            std::cout << "Обернена матриця має такий вигляд: \n";
        }
        std::cout << temp;
        //}
    }

    return temp;
}

int Matrix::rank() {
    Matrix temp(*this);

    temp = temp.Gaussian_Method();

    int rank = i_size + 1;
    for (int i = i_size; i >= 0; i--) {
        Fraction sum;
        for (int j = 0; j <= j_size; j++) {
            sum = sum + Math::pow(temp.matrix[i][j], 2);
        }
        if (sum.get_numerator() == 0) {
            rank--;
        }
    }
    //{
    if (g_language == 1) {
        std::cout << "\nThe rank of the matrix is equal to: ";
    }
    else {
        std::cout << "\nРанг матриці дорівнює: ";
    }
    //}

    return rank;
}
