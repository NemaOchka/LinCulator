#include <LinCulator/Classes.h>

extern int g_language, g_error;


Fraction Math::pow (Fraction a, int b) {
    Fraction buff = 1;
    if (a.get_numerator() == 0) {
        buff.set_numerator(0);
    }
    else if (b < 0) {
        int temp = a.get_numerator();
        a.set_numerator(a.get_denominator());
        a.set_denominator(temp);
    }
    for (int i = 0; i < b; i++) {
        buff = buff * a;
    }

    return buff;
}

//{
Fraction Math::Determinant_with_explanation(Matrix mat) {
    Matrix temp(mat), check(mat);
    Fraction determinant(1,1);
    int row_swap = 0;
    std::vector <Fraction> coeffs;

    if (mat.get_i_size() != mat.get_j_size()) {
        if (g_language == 1) {
            std::cout << "Error!! It is not a square matrix. \n";
        }
        else {
            std::cout << "Помилка!! Це не квадратна матриця. \n";
        }
        g_error = 1;
    }
    else {
        std::cout << "\n" << temp;

        for (int i = 0, k = 0; (i <= temp.get_i_size()) && (k <= temp.get_j_size()); i++, k++) {
            start:
            if (temp.get_matrix()[i][k].get_numerator() == 0) {
                int all_column_zero = 1;
                for (int g = i + 1; g <= temp.get_i_size() && all_column_zero; g++) {
                    if (temp.get_matrix()[g][k].get_numerator() != 0) {
                        std::vector <Fraction> buff = temp.get_matrix()[g];
                        temp.set_matrix(g, temp.get_matrix()[i]);
                        temp.set_matrix(i, buff);
                        all_column_zero = 0;
                        row_swap++;
                    }
                }
                if (all_column_zero) {
                    k++;
                    goto start;
                }
            }
            if (temp != check) {
                std::cout << "\n" << temp;
                check = temp;
            }
            Fraction row_divider = temp.get_matrix()[i][k];
            coeffs.push_back(row_divider);
            for (int j = k; j <= temp.get_j_size(); j++) {
                temp.set_matrix(i, j, temp.get_matrix()[i][j] / row_divider);
            }
            if (temp != check) {
                std::cout << "\n" << temp;
                check = temp;
            }
            for (int h = i + 1; h <= temp.get_i_size(); h++) {
                Fraction row_multiplier = temp.get_matrix()[h][k];
                for (int j = k; j <= temp.get_j_size(); j++) {
                    temp.set_matrix(h, j, temp.get_matrix()[h][j] - row_multiplier * temp.get_matrix()[i][j]);
                }
            }
            if (temp != check) {
                std::cout << "\n" << temp;
                check = temp;
            }
        }

        if (g_language == 1) {
            std::cout << "During the elementary transformations, we changed the lines " << row_swap << " times, then multiply by: ";
        }
        else {
            std::cout << "\nПід час елементарних перетворень ми поміняли рядки " << row_swap << " разів, то домножатимемо на: ";
        }
        if (row_swap % 2 == 0) {
            row_swap = 1;
        }
        else {
            row_swap = -1;
        }
        std::cout << row_swap << ";\n\n";
        if (g_language == 1) {
            std::cout << "To find the determinant, multiply the sign that determines the number of line permutations, division coefficients for elementary transformations and elements that are on the main diagonal. \n";
        }
        else {
            std::cout << "Щоб знайти визначник, перемножимо знак, що визначає кількість перестановок рядків, коефіцієнти ділення при елементарних перетвореннях та елементи, що знаходяться на головній діагоналі. \n";
        }
        std::cout << "det = " << row_swap;
        determinant = determinant * row_swap;
        for (unsigned int i = 0; i < coeffs.size(); i++) {
            determinant = determinant * coeffs[i];
            if (coeffs[i].get_denominator() != 0) {
                std::cout << " * " << coeffs[i];
            }
        }
        for (int i = 0; i <= temp.get_i_size(); i++) {
            determinant = determinant * temp.get_matrix()[i][i];
            std::cout << " * " << temp.get_matrix()[i][i];
        }
        std::cout << " = " << determinant << "\n";
    }

    return determinant;
}
//}

Matrix Math::get_matrix_from_array_of_vectors(std::vector <Matrix>& a) {
    std::vector <std::vector <Fraction>> buff(a[0].get_i_size() + 1);
    for (unsigned int j = 0; j < a.size(); j++) {
        for (int i = 0; i <= a[0].get_i_size(); i++) {
            buff[i].push_back(a[j].get_matrix()[i][0]);
        }
    }
   Matrix temp(buff.size() - 1, a.size() - 1, buff);

    return temp;
}
