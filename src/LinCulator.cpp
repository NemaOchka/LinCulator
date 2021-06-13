#include "../lib/Classes.h"

// Пофіксити:
// зробити перевірку на коректність вводу данних користувача в language та task
// cout матриць в Gaussian_Method()

int g_language, g_error = 0;                                     // if somewhere occure error, the value will be changed to 1 and the wil be report about mistake in the end

int main() {
    // Переписати розроблені методи із чітким поясненням (визначник + Гауса)

    // Ядро та образ лінійного оператора
    // Розв'язок СЛАР методом Крамара + загальний розв'язоу системи
    // базис суми та перетину підпросторів
    // Заміна базису / матриці переходу
    // Координати вектора в іншому базисі
    // Матриця лінійного оператора в іншому базисі
    // Знайти власні числа та власні вектори
    // Нормальна форма Жодана + пошук функції
    // Процес ортогоналіції Грамма-Шміта + ортонормація
    // Перевірка на пряму суму просторів
    // Ортогональне доповнення
    // Знаходження ортогональної проекції та ортогональної складової
    // Знайти матрицю спряженого оператора
    // Побудувати ортонормаваний базис із влачних векторів

    system("clear");
    std::cout << "Choose youe language: \nEN - 1 \nUA - 2 \n";
    std::cin >> g_language;
    if (g_language != 1 && g_language != 2) {
        std::cout << "Enter correct answer! \n";
        std::cin >> g_language;
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

                "\n0) вийти \n";
        }

        int task;
        std::cin >> task;
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
                matrix.Gaussian_Method();

                /*
                std::vector <Matrix> answer = matrix.Gaussian_Method();
                for (unsigned long i = 0; i < answer.size(); i++) {
                    std::cout << "\n" << answer[i];
                }*/
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
                std::cout << matrix.rank() << "\n";
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
        }

        if (g_error) {
            if (g_language == 1) {
                std::cout << "\nSeems like somewhere occured a mistake. Please, check your input data! \n";
            }
            else {
                std::cout << "\nВиглядає ніби десь трапилась помилка, перегляньте корекність вводу данних! \n";
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
