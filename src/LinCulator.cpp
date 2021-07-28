#include "../lib/Classes.h"

// Пофіксити:
// cout матриць в Gaussian_Method() (напвено пов'язано із знаменником, коли чиссельник 0)
// PDE (core dumped) помилка при великих числах - Метод Гауса (long long int у Fraction)
// Всі g_error поміняти на assert аьо на exit("");

int g_language = 1, g_error = 0;                                     // if somewhere occure error, the value will be changed to 1 and the wil be report about mistake in the end

int main() {
    // Ядро і образ лінійного оператора ??????
    // Перевірка на пряму суму просторів ??????

    // Заміна базису / матриці переходу
    // Координати вектора в іншому базисі
    // Матриця лінійного оператора в іншому базисі
    // Процес ортогоналіції Грамма-Шміта + ортонормація

    // Ортогональне доповнення
    // Знаходження ортогональної проекції та ортогональної складової
    // Знайти матрицю спряженого оператора
    // Побудувати ортонормаваний базис із влачних векторів

    // Знайти власні числа та власні вектори
    // Нормальна форма Жодана + пошук функції
    // Розв'язок СЛАР методом Крамара + загальний розв'язоу системи


    system("clear");
    std::cout << "Choose youe language: \nEN - 1 \nUA - 2 \n";
    while (true) {
        std::cin >> g_language;
        if (std::cin.fail() || (g_language != 1 && g_language != 2)) {
            std::cout << "Incorrect value!! Try one more time. \n";
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }
        else break;
    }
    std::system("clear");

    while (1) {
        if (g_language == 1) {
            std::cout << "Choose your task: \n"
                "1) solve a SLAE by the Gaussian method \n"
                "2) find a determinant of the matrix \n"
                "3) find an inverse matrix \n"
                "4) fing a rank of the matrix \n"
                "5) check the system for linear independence \n"
                "6) find the basis of the system \n"
                "7) solve the SLAE by the Cramer method (do not work) \n"
                "8) find the basis of the sum and intersection of subspaces \n"
                "9) base replacement \n"

                "\n0) exit \n";
        }
        else {
            std::cout << "Вибири свою задачу: \n"
                "1) вирішити СЛАР методом Гауса \n"
                "2) знайти визначник матриці \n"
                "3) знайти обернену матрицю \n"
                "4) знайти ранг матриці \n"
                "5) перевірити систему на лінійну незалежність \n"
                "6) знайти базис системи \n"
                "7) вирішити СЛАР методом Крамера (не працює) \n"
                "8) знайти базис суми та перетину підпросторів \n"
                "9) заміна базису \n"

                "\n0) вийти \n";
        }

        int task;
        while (true) {
            std::cin >> task;
            if (std::cin.fail()) {
                if (g_language == 1) {
                    std::cout << "Incorrect value!! Try one more time. \n";
                }
                else {
                    std::cout << "Некоректне значення!! Спробуйте ще раз. \n";
                }
                std::cin.clear();
                std::cin.ignore(32767, '\n');
            }
            else break;
        }
        std::system("clear");
        switch (task) {
            case 0: {
                std::cout << "\n";
                return 0;
            }; break;

            case 1: {
                if (g_language == 1) {
                    std::cout << "Enter the coefficients of extended SLAE in the form of a matrix: \n";
                }
                else {
                    std::cout << "Введіть коефіцієенти розширеної СЛАР у вигляді матриці: \n";
                }
                Matrix matrix;
                std::cin >> matrix;
                if (g_language == 1) {
                    std::cout << "\nThe solve: \n";
                }
                else {
                    std::cout << "\nРішення: \n";
                }
                matrix.Gaussian_Method_With_Extract_Answer();
            }; break;

            case 2: {
                if (g_language == 1) {
                    std::cout << "Enter dimensions of the matrix and this matrix: \n";
                }
                else {
                    std::cout << "Введіть розмірність матриці та саму матрицю: \n";
                }
                Matrix matrix;
                std::cin >> matrix;
                Fraction determinant = Math::Determinant_with_explanation(matrix);
                if (g_language == 1) {
                    std::cout << "\nThe determinant of this matrix is equel: " << determinant << std::endl;
                }
                else {
                    std::cout << "\nВизначник цієї матриці дорівнює: " << determinant << std::endl;
                }
            } break;

            case 3: {
                if (g_language == 1) {
                    std::cout << "Enter dimensions of the matrix and this matrix: \n";
                }
                else {
                    std::cout << "Введіть розмірність матриці та саму матрицю: \n";
                }
                Matrix matrix;
                std::cin >> matrix;
                if (g_language == 1) {
                    std::cout << "\nThe solution: \n";
                }
                else {
                    std::cout << "\nРішення: \n";
                }
                std::cout << "\nA = \n";
                std::cout << matrix;
                matrix.inverse();
            }; break;

            case 4: {
                if (g_language == 1) {
                    std::cout << "Enter dimensions of the matrix and this matrix: \n";
                }
                else {
                    std::cout << "Введіть розмірність матриці та саму матрицю: \n";
                }
                Matrix matrix;
                std::cin >> matrix;
                if (g_language == 1) {
                    std::cout << "\nThe solve: \n";
                }
                else {
                    std::cout << "\nРішення: \n";
                }
                int rank = matrix.rank();
                //{
                if (g_language == 1) {
                    std::cout << "\nThe rank of the matrix is equal to: " << rank;
                }
                else {
                    std::cout << "\nРанг матриці дорівнює: " << rank;
                }
                //}
            }; break;

            case 5: {
                if (g_language == 1) {
                    std::cout << "Enter the vectors of the system as a matrix: \n";
                }
                else {
                    std::cout << "Введіть вектори системи як матрицю: \n";
                }
                Matrix matrix;
                std::cin >> matrix;
                matrix.linear_independence();
            }; break;

            case 6: {
                if (g_language == 1) {
                    std::cout << "Enter the vectors of the system as a matrix: \n";
                }
                else {
                    std::cout << "Введіть вектори системи як матрицю: \n";
                }
                Matrix matrix;
                std::cin >> matrix;
                std::cout << matrix.basis();
            }; break;

            case 7: {
                if (g_language == 1 ) {
                    std::cout << "Enter the coefficients of extended SLAE in the form of a matrix: \n";
                }
                else {
                    std::cout << "Введіть коефіцієенти розширеної СЛАР у вигляді матриці: \n";
                }
                Matrix matrix;
                std::cin >> matrix;
                matrix.Cramer_Method();
            }; break;

            case 8: {
                if (g_language == 1) {
                    std::cout << "Enter the basis of the first and second subspaces as a matrix: \n";
                }
                else {
                    std::cout << "Введіть базис першого та другого підпросторів як матрицю: \n";
                }
                Matrix subspace1, subspace2;
                std::cin >> subspace1 >> subspace2;
                if (g_language == 1) {
                    std::cout << "\nFind the basis and dimension of the first subspace: \n";
                }
                else {
                    std::cout << "\nЗнайдемо базис та розмірність першого підпростору: \n";
                }
                std::cout << (subspace1 = subspace1.basis());
                if (g_language == 1) {
                    std::cout << "\nThe dimension of the matrix is equal: " << subspace1.get_j_size() + 1 << "\n";
                }
                else {
                    std::cout << "\nРозмірність цієї матриці дорівнює: " << subspace1.get_j_size() + 1 << "\n";
                }
                if (g_language == 1) {
                    std::cout << "\nFind the basis and dimension of the second subspace: \n";
                }
                else {
                    std::cout << "\nЗнайдемо базис та розмірність другого підпростору: \n";
                }
                std::cout << (subspace2 = subspace2.basis());
                if (g_language == 1) {
                    std::cout << "\nThe dimension of the matrix is equal: " << subspace2.get_j_size() + 1 << "\n";
                }
                else {
                    std::cout << "\nРозмірність цієї матриці дорівнює: " << subspace2.get_j_size() + 1 << "\n";
                }
                if (g_language == 1) {
                    std::cout << "\nFind the basis and dimension of the sum of subspaces: \n";
                }
                else {
                    std::cout << "\nЗнайдемо базис та розмірність суми підпросторів: \n";
                }
                Matrix sum(subspace1);
                std::vector <std::vector <Fraction>> temp = subspace1.get_matrix();
                for (int i = 0; i <= subspace2.get_i_size(); i++) {
                    for (int j = 0; j <= subspace2.get_j_size(); j++) {
                        temp[i].push_back(subspace2.get_matrix()[i][j]);
                    }
                }
                sum.set_j_size(subspace1.get_j_size() + subspace2.get_j_size() + 1);
                sum.set_matrix(temp);
                std::cout << (sum = sum.basis());
                if (g_language == 1) {
                    std::cout << "\nThe dimension of the matrix is equal: " << sum.get_j_size() + 1 << "\n";
                }
                else {
                    std::cout << "\nРозмірність цієї матриці дорівнює: " << sum.get_j_size() + 1 << "\n";
                }
                if (g_language == 1) {
                    std::cout << "\nFind the basis and dimension of the intersection of subspaces: \n";
                }
                else {
                    std::cout << "\nЗнайдемо базис та розмірність перетину підпросторів: \n";
                }
                std::cout << "\ndim(L1 ⋂ L2) = dimL1 + dimL2 - dim(L1 + L2) = " << subspace1.get_j_size() + subspace2.get_j_size() - sum.get_j_size() + 1 << ";\n";
                std::cout << "x ∈ L1 && x ∈ L2 => \n";
                Matrix intersection(subspace1);
                temp = subspace1.get_matrix();
                for (int i = 0; i <= subspace2.get_i_size(); i++) {
                    Fraction fr(-1, 1);
                    for (int j = 0; j <= subspace2.get_j_size(); j++) {
                        temp[i].push_back(subspace2.get_matrix()[i][j] * fr);
                    }
                    temp[i].push_back(0);
                }
                intersection.set_j_size(subspace1.get_j_size() + subspace2.get_j_size() + 2);
                intersection.set_matrix(temp);
                intersection.Gaussian_Method();
                if (g_language == 1) {
                    std:: cout << "\nWrite a matrix as a system, express some basis vectors through others, write the vector on the basis and determine the basis vectors of intersection of subspaces. \n";
                }
                else {
                    std::cout << "\nЗапишіть матрицю у вигляді системи, виразіть одні базисні вектори через інші, розпишіть вектор за базисом та визначіть базисні вектори перетину підпросторів. \n";
                }
            }

            case 9: {

            } break;
        }

        if (g_error) {
            if (g_language == 1) {
                std::cout << "\nSeems like somewhere occured a mistake. Please, check your input data! \n";
            }
            else {
                std::cout << "\nВиглядає ніби десь трапилась помилка, перегляньте коректність вводу данних! \n";
            }
            g_error = 0;
        }

        if (g_language == 1) {
            std::cout << "\nPress ENTER to come back... \n";
        }
        else {
            std::cout << "\nЩоб повернутися, натисніть ENTER... \n";
        }
        system("read");
        system("clear");
    }
}
