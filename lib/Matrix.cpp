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

    while (true) {
        in >> temp.i_size >> temp.j_size;
        if (std::cin.fail() || (temp.i_size < 0 && temp.j_size < 0)) {
            if (g_language == 1) {
                std::cout << "The dimension of the matrix cannot be negative! Try again. \n";
            }
            else {
                std::cout << "Розмірність матриці не може приймати негативне занчення! Спробуйте ще раз. \n";
            }
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }
        else break;
    }
    temp.i_size--;
    temp.j_size--;

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
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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

void Matrix::set_i_size (int i) {
    i_size = i;
}

void Matrix::set_j_size (int j) {
    j_size = j;
}

void Matrix::set_matrix (std::vector<std::vector<Fraction>> mat) {
    if (((unsigned)i_size == mat.size() - 1) && ((unsigned)j_size == mat[0].size() - 1))  {
        matrix = mat;
    }
    else {
        if (g_language == 1) {
            std::cout << "Error!! Dimensions do not match. \n";
        }
        else {
            std::cout << "Помилка!! Розмірності не співпадають. \n";
        }
        g_error = 1;
    }
}

void Matrix::set_matrix (int i, std::vector<Fraction> row) {
    if ((unsigned)j_size == row.size() - 1) {
        matrix[i] = row;
    }
    else {
        if (g_language == 1) {
            std::cout << "Error!! Dimensions do not match. \n";
        }
        else {
            std::cout << "Помилка!! Розмірності не співпадають. \n";
        }
        g_error = 1;
    }
}

void Matrix::set_matrix (int i, int j, Fraction a) {
    matrix[i][j] = a;
}

Matrix Matrix::main_matrix() {
    Matrix temp(*this);
    temp.j_size = temp.j_size - 1;
    for (int i = 0; i <= i_size; i++) {
        std::vector <Fraction> buff = temp.matrix[i];
        buff.pop_back();
        temp.set_matrix(i, buff);
    }

    return temp;
}

Matrix Matrix::Gaussian_Method() {
        Matrix temp(*this);
        //{
        Matrix check(*this);
        std::cout << "\n" << temp;
        //}
        for (int i = 0, k = 0; (i <= temp.i_size) && (k <= temp.j_size ); i++, k++) {
            int row_delition = 0;
            if (temp.matrix[i][k].get_numerator() == 0) {
                int all_in_column_zero = 1;
                for (int g = i + 1; g <= temp.i_size && all_in_column_zero; g++) {
                    if (temp.matrix[g][k].get_numerator() != 0) {
                        temp.swap_rows(i, g);
                        all_in_column_zero = 0;
                    }
                }
                if (all_in_column_zero) {
                    int all_in_row_zero = 1;
                    for (int g = k + 1; g <= temp.j_size && all_in_row_zero; g++) {
                        if (temp.matrix[i][g].get_numerator() != 0){
                            //{
                            if (g_language == 1) {
                                std::cout << "Swap " << i + 1 << " and " << g + 1 << " columns: \n";
                            }
                            else {
                                std::cout << "Поміняємо місцями " << i + 1 << " та " << g + 1 << " стовпці: \n";
                            }
                            //}
                            temp.swap_columns(i, g);
                            all_in_row_zero = 0;
                        }
                    }
                    if (all_in_row_zero) {
                        std::vector <std::vector <Fraction>> buff = temp.get_matrix();
                        buff.erase(buff.begin() + i + 1);
                        temp.set_i_size(temp.get_i_size() - 1);
                        temp.set_matrix(buff);
                        i--;
                        row_delition = 1;
                    }
                }
            }
            if (!row_delition) {
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
                row_delition = 0;
            }
        }

        return temp;
}

std::vector <Matrix> Matrix::Gaussian_Method_With_Extract_Answer() {
    std::vector <Matrix> answer;
    Matrix temp(*this);
    std::vector <std::vector <int>> swappiness;
    //{
    Matrix check(*this);
    std::cout << "\n" << temp;
    //}
    for (int i = 0, k = 0; (i <= temp.i_size) && (k <= temp.j_size ); i++, k++) {
        int row_delition = 0;
        if (temp.matrix[i][k].get_numerator() == 0) {
            int all_in_column_zero = 1;
            for (int g = i + 1; g <= temp.i_size && all_in_column_zero; g++) {
                if (temp.matrix[g][k].get_numerator() != 0) {
                    temp.swap_rows(i, g);
                    all_in_column_zero = 0;
                }
            }
            if (all_in_column_zero) {
                int all_in_row_zero = 1;
                for (int g = k + 1; g < temp.j_size && all_in_row_zero; g++) {
                    if (temp.matrix[i][g].get_numerator() != 0){
                        //{
                        if (g_language == 1) {
                            std::cout << "Swap " << i + 1 << " and " << g + 1 << " columns: \n";
                        }
                        else {
                            std::cout << "Поміняємо місцями " << i + 1 << " та " << g + 1 << " стовпці: \n";
                        }
                        //}
                        temp.swap_columns(i, g);
                        swappiness.insert(swappiness.begin(), {i , g});
                        all_in_row_zero = 0;
                    }
                }
                if (all_in_row_zero) {
                    std::vector <std::vector <Fraction>> buff = temp.get_matrix();
                    buff.erase(buff.begin() + i + 1);
                    temp.set_i_size(temp.get_i_size() - 1);
                    temp.set_matrix(buff);
                    i--;
                    row_delition = 1;
                }
            }
        }
        if (!row_delition) {
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
            row_delition = 0;
        }
    }

    int rank = temp.rank();
    //{
    if (g_language == 1) {
        std::cout << "\nThe rank of the matrix is equal to: " << rank << "; \nFind the rank of the main matrix: \n";
    }
    else {
        std::cout << "\nРанг матриці дорівнює: " << rank << "; \nЗнайдемо ранг основної матриці: \n";
    }
    //}
    Matrix temp_main = this->main_matrix();
    int rank_main = temp_main.rank();
    //{
    if (g_language == 1) {
        std::cout << "\nThe rank of the main matrix is equal to: " << rank_main << ";";
    }
    else {
        std::cout << "\nРанг основої матриці дорівнює: " << rank_main << ";";
    }
    //}
    if (rank != rank_main) {
        //{
        if (g_language == 1) {
            std::cout << "\nSince the rank of the extended and basic matrices do not coincide, the ";
        }
        else {
            std::cout << "\nОскільки ранг розширеної та основної матриці не співпадають, то ";
        }
        //}
        if (g_language == 1) {
            std::cout << "\nSystem has no solution. \n";
        }
        else {
            std::cout << "\nСистема немає розв'язку. \n";
        }
        g_error = 1;
    }
    else {
        //{
        if (g_language == 1) {
            std::cout << "\nSince the rank of the extended and basic matrices coincide, the solution has the form: \n\n";
        }
        else {
            std::cout << "\nОскільки ранг розширеної та основної матриці співпадають, то розв'язок має вигляд: \n\n";
        }
        for (int i = 1; i <= temp.get_j_size(); i++) {
                std::cout << "| x" << i << " |";
                if (i == (temp.get_j_size() + 1) / 2) {
                std::cout << " = ";
            }
            std::cout << "\n";
        }
        //}
        if (rank == temp.get_j_size()) {
            std::vector <Fraction> vector;
            for (int i = rank - 1; i >= 0; i--) {
                Fraction sum = temp.get_matrix()[i][temp.get_j_size()];
                for (int j = temp.get_j_size() - 1, k = 1; j > i; j--, k++) {
                    sum = sum - temp.get_matrix()[i][j] * vector[vector.size() - k];
                }
                vector.insert(vector.begin(), sum);
            }
            Matrix mat (0, temp.get_j_size() - 1, {vector});
            answer.insert(answer.begin(), mat.transpose());
            for (unsigned int i = 0; i < swappiness.size(); i++) {
                answer[0].swap_rows(swappiness[i][0], swappiness[i][1]);
            }
            //{
            std::cout << "=\n" << answer[0];
            //}
        } else {
            for (int i = temp.get_j_size() - rank, r = 0; i >= 0; i--, r++) {
                std::vector <Fraction> vector;
                for (int t = temp.get_j_size() - rank; t > 0; t--) {
                    if (t == temp.get_j_size() - rank + 1 - r) {
                        vector.insert(vector.begin(), 1);
                    }
                    else {
                        vector.insert(vector.begin(), 0);
                    }
                }
                for (int k = rank - 1; k >= 0; k--) {
                    Fraction buff = temp.get_matrix()[k][temp.get_j_size() - r];
                    if (r) {
                        Fraction fr(-1, 1);
                        buff = buff * fr;
                    }
                    for (int g = 1; k + g < rank; g++) {
                        buff = buff - temp.get_matrix()[k][k + g] * vector[g - 1];
                    }
                    vector.insert(vector.begin(), buff);
                }

                Matrix mat(0, temp.get_j_size() - 1, {vector});
                answer.insert(answer.begin(), mat.transpose());
            }
            for (unsigned int i = 0; i < answer.size(); i++) {
                for (unsigned int j = 0; j < swappiness.size(); j++) {
                    answer[i].swap_rows(swappiness[j][0], swappiness[j][1]);
                }
            }
            //{
            std::cout << "= ";
            for (unsigned int i = 0; i < answer.size(); i++) {
                std::cout << "+ ";
                if (i != answer.size() - 1) {
                std::cout <<"x" << i + rank + 1 << " * ";
                }
                std::cout << "\n" << answer[i];
            }
            //}
        }
    }

    return answer;
}
void Matrix::swap_rows(int a, int b) {

    if (a > b) std::swap(a, b);
    if (a >= 0 && b >= 0 && (a + b) < 2 * this->get_i_size() && (a != b)) {
        std::vector <Fraction> buff = this->get_matrix()[a];
        this->set_matrix(a, this->get_matrix()[b]);
        this->set_matrix(b, buff);
    }
    else {
        if (g_language == 1) {
            std::cout << "Error!! Wrong indexes. \n";
        }
        else {
            std::cout << "Помилка!! Не вірні індекси. \n";
        }
        g_error = 1;
    }
}

void Matrix::swap_columns(int a, int b) {

    if (a > b) std::swap(a, b);
    if (a >= 0 && b >= 0 && (a + b) < 2 * this->get_j_size() && (a != b)) {
        for (int i = 0; i <= this->get_i_size(); i++) {
            Fraction buff = this->get_matrix()[i][a];
            this->set_matrix(i, a, this->get_matrix()[i][b]);
            this->set_matrix(i, b, buff);
        }
    }
    else {
        if (g_language == 1) {
            std::cout << "Error!! Wrong indexes. \n";
        }
        else {
            std::cout << "Помилка!! Не вірні індекси. \n";
        }
        g_error = 1;
    }
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
            std::cout << "Помилка!! Розмірність матриці замала, щоб визначити мінор. \n";
        }
        g_error = 1;
    }

    return temp;
}

Matrix Matrix::minor(std::vector<int> a, std::vector<int> b) {
    Matrix temp(*this);
    unsigned int a_s = a.size(), b_s = b.size();
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    a.erase(std::unique(begin(a), end(a)), end(a));
    b.erase(std::unique(begin(b), end(b)), end(b));
    if (a.size() != a_s || b.size() != b_s) {
        if (g_language == 1) {
            std::cout << "Error!! Indices are repeated. \n";
        }
        else {
            std::cout << "Помилка!! Індекси повторються. \n";
        }
        g_error = 1;
    }
    else if (a.size() != b.size()) {
        if (g_language == 1) {
            std::cout << "Error!! The minor has to be square. \n";
        }
        else {
            std::cout << "Помилка!! Мінор повинен бути квадратним. \n";
        }
        g_error = 1;
    }
    else {
        if (a[0] < 0 || b[0] < 0 || a[a.size() - 1] > this->get_i_size() || b[b.size() - 1] > this->get_j_size()) {
            if (g_language == 1) {
                std::cout << "Error!! Wrong index. \n";
            }
            else {
                std::cout << "Помилка!! Не вірний індекс. \n";
            }
            g_error = 1;
        }
        else {
            std::vector <std::vector <Fraction>> buff;
            for (unsigned int i = 0; i < a.size(); i++) {
                std::vector <Fraction> bbuff;
                for (unsigned int j = 0; j < b.size(); j++) {
                    bbuff.push_back(temp.get_matrix()[a[i]][b[j]]);
                }
                buff.push_back(bbuff);
            }
            temp.set_i_size(a.size() - 1);
            temp.set_j_size(b.size() - 1);
            temp.set_matrix(buff);
        }
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

    int rank = temp.i_size + 1;


    for (int i = i_size; i >= 0; i--) {
        Fraction sum;
        for (int j = 0; j <= j_size; j++) {
            sum = sum + Math::pow(temp.matrix[i][j], 2);
        }
        if (sum.get_numerator() == 0) {
            rank--;
        }
    }

    return rank;
}

bool Matrix::linear_independence() {
    int rank = this->rank();
    //{
    if (g_language == 1) {
        std::cout << "\nThe rank of the matrix is equal to: " << rank << ";";
    }
    else {
        std::cout << "\nРанг матриці дорівнює: " << rank << ";";
    }
    //}

    if (rank == this->get_j_size() + 1) {
        //{
        if (g_language == 1) {
            std::cout << "\n Rank = j demension. \nThe system is linearly independent. \n";
        }
        else {
            std::cout << "\nРанг = розмірності j. \nСистема лінійно незалежна. \n";
        }
        //}

        return true;
    }
    else {
        //{
        if (g_language == 1) {
            std::cout << "\nRank ≠ j demension. \nThe system is linearly dependent. \n";
        }
        else {
            std::cout << "\nРанг ≠ розмірності j. \nСистема лінійно залежна. \n";
        }
        //}

        return false;
    }
}

Matrix Matrix::basis() {
    std::vector <std::vector <Fraction>> mat;

    int rank = this->rank();
    //{
    if (g_language == 1) {
        std::cout << "\nThe rank of the matrix is equal to: " << rank << ";";
    }
    else {
        std::cout << "\nРанг матриці дорівнює: " << rank << ";";
    }
    //}

    for (int i = 0; i <= this->get_i_size(); i++) {
        std::vector <Fraction> buff;
        for (int j = 0; j < rank; j++) {
            buff.push_back(this->get_matrix()[i][j]);
        }
        mat.push_back(buff);
        buff.clear();
    }
    Matrix temp(this->get_i_size(), rank - 1, mat);
    //{
    if (g_language == 1) {
        std::cout << "\nTherefore, the basic vectors will be: \n";
    }
    else {
        std::cout << "\nОтже, базисними векторами будуть: \n";
    }
    //}

    return temp;
}

std::vector <std::vector <Fraction>> Matrix::Cramer_Method() {
    Matrix temp(*this);
    std::vector <std::vector <Fraction>> answer;

    int rank = temp.rank(), rank_main = temp.main_matrix().rank();
    if (rank != rank_main) {
        //{
        if (g_language == 1) {
            std::cout << "\nSince the rank of the extended and basic matrices do not coincide, the ";
        }
        else {
            std::cout << "\nОскільки ранг розширеної та основної матриці не співпадають, то ";
        }
        //}
        if (g_language == 1) {
            std::cout << "\nSystem has no solution. \n";
        }
        else {
            std::cout << "\nСистема немає розв'язку. \n";
        }
        g_error = 1;
    }
    else {

    }

    return answer;
}

/*Matrix Matrix::get_matrix_for_Cramer_method() {
    Matrix temp(*this);

    int rank = temp.rank();
    std::vector <int> rows, columns;
    for (int i = 0; i < rank; i++) {
        rows.push_back(i);
        columns.push_back(i);
    }
    for (int i = 0; *****; i++, columns[columns.size() - 1] = rank + i - 1) {
        for (int j = 0; j <= i; j++) {
            columns[columns.size() - j - 1]++;
        }
        for (; columns[columns.size() - 1] <= temp.get_j_size(); columns[columns.size() - 1]++) {
            /// метод має повартити вектори з номерами рядків і стовпців базисного мінора, сам по собі він не потрібен, тому потім просто вставити в метод Крамара
            /// допустим у нас ранг 3 а довжина 5, рухаємо останній індекс до кінця, потім переде останній на крок вперед і останній на крок вперед, тепер сунето знову остнанній до кінця,
            /// тким способом переберем всі стовпці, а потім также і рядки
            if(temp.minor(rows, columns).determinant().get_numerator()) break;
        }
    }
    return temp;
}*/

Matrix Matrix::transiotion_matrix(Matrix mat) {
    Matrix temp(*this);

    if (i_size == mat.i_size && j_size == mat.j_size) {
        std::vector <std::vector <Matrix>> answer;
        for (int j = 0; j <= mat.j_size; j++) {
            temp = *this;
            std::vector <std::vector <Fraction>> ttemp = temp.get_matrix();
            for (int i = 0; i <= mat.i_size; i++) {
                ttemp[i].push_back(mat.matrix[i][j]);
            }
            temp.set_j_size(temp.j_size + 1);
            temp.set_matrix(ttemp);
            //{
            if (g_language == 1) {
                std::cout << "\nLet's find " << j + 1 << " column of transiotion matrix: \n";
            }
            else {
                std::cout << "\nЗнайдемо " << j + 1 << " сповчик матриці переходу: \n";
            }
            //}
            answer.push_back(temp.Gaussian_Method_With_Extract_Answer());
        }
        std::vector <std::vector <Fraction>> buff(mat.i_size + 1);
        for (unsigned int j = 0; j < answer.size(); j++) {
            for (int i = 0; i <= answer[0][0].get_i_size(); i++) {
                buff[i].push_back(answer[j][0].get_matrix()[i][0]);
            }
        }
        temp.set_j_size(mat.j_size);
        temp.set_matrix(buff);
        //{
        if (g_language == 1) {
            std::cout << "\nThe transition matrix is: \n";
        }
        else {
            std::cout << "\nМатриця переходу має вигляд: \n";
        }
        //}
    }
    else {
        if (g_language == 1) {
            std::cout << "\nError!! Wrong dimensions. \n";
        }
        else {
            std::cout << "\nПомилка!! Не вірні розмірності. \n";
        }
        g_error = 1;
    }

    return temp;
}
