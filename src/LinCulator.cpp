#include <LinCulator/Classes.h>

// Пофіксити:
// cout матриць в Gaussian_Method() (напвено пов'язано із знаменником, коли чиссельник 0)
// PDE (core dumped) помилка при великих числах - Метод Гауса (long long int у Fraction)
// Всі g_error поміняти на assert аьо на exit("");

int g_language = 1, g_error = 0;                                     // if somewhere occure error, the value will be changed to 1 and the wil be report about mistake in the end

int main() {
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
                "2) scalar product of vectors \n"
                "3) find a determinant of the matrix \n"
                "4) find an inverse matrix \n"
                "5) fing a rank of the matrix \n"
                "6) check the system for linear independence \n"
                "7) find the basis of the system \n"
                "8) solve the SLAE by the Cramer method (do not work) \n"
                "9) find the basis of the sum and intersection of subspaces \n"
                "10) matrix of transition from basis to basis \n"
                "11) the coordinates of the vector in another basis \n"
                "12) find the matrix of the linear operator in another basis \n"
                "13) find the matrix of the linear operator in another basis(in pair of basis) \n"
                "14) Gram-Schmidt orthogonalization process \n"
                "15) find the orthogonal projection and orthogonal complement of the vector \n"
                "16) find an orthogonal complement to the linear shell \n"
                "17) find the matrix of the conjugate linear operator \n"
                "18) find eigenvectors of a linear operator + normal Jordan form \n"

                "\n0) exit \n";
        }
        else {
            std::cout << "Вибири свою задачу: \n"
                "1) вирішити СЛАР методом Гауса \n"
                "2) скалярний добуток векторів \n"
                "3) знайти визначник матриці \n"
                "4) знайти обернену матрицю \n"
                "5) знайти ранг матриці \n"
                "6) перевірити систему на лінійну незалежність \n"
                "7) знайти базис системи \n"
                "8) вирішити СЛАР методом Крамера (не працює) \n"
                "9) знайти базис суми та перетину підпросторів \n"
                "10) матриця переходу від базису до базису \n"
                "11) кoординати вектора в іншому базисі \n"
                "12) знайти матрицю лінійного оператора в іншому базисі \n"
                "13) знайти матрицю лінійного оператора в іншому базисі(в парі базисів) \n"
                "14) процес ортогоналізації Грамма-Шміта \n"
                "15) знайти ортогональну проекцію та ортогональне доповнення вектора \n"
                "16) знайти ортогональне доповнення до лінійної оболонки \n"
                "17) знайти матрицю спряженого лінійного оператора \n"
                "18) знайти власні вектори лінійного оператора + нормальна форма Жордана \n"

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
                    std::cout << "Enter two vectors as matrix: \n";
                }
                else {
                    std::cout << "Введіть два вектори як матриці: \n";
                }
                Matrix vector1, vector2;
                std::cin >> vector1 >> vector2;
                if (g_language == 1) {
                    std::cout << "\nThe solve: \n";
                }
                else {
                    std::cout << "\nРішення: \n";
                }
                std::cout << vector1.scalar_product(vector2);
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
                Fraction determinant = Math::Determinant_with_explanation(matrix);
                if (g_language == 1) {
                    std::cout << "\nThe determinant of this matrix is equel: " << determinant << std::endl;
                }
                else {
                    std::cout << "\nВизначник цієї матриці дорівнює: " << determinant << std::endl;
                }
            } break;

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
                    std::cout << "\nThe solution: \n";
                }
                else {
                    std::cout << "\nРішення: \n";
                }
                std::cout << "\nA = \n";
                std::cout << matrix;
                matrix.inverse();
            }; break;

            case 5: {
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

            case 6: {
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

            case 7: {
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

            case 8: {
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

            case 9: {
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

            case 10: {
                if (g_language == 1) {
                    std::cout << "Enter the bases as the matrices from which you want to make the transition: \n";
                }
                else {
                    std::cout << "Введіть базиси, як матриці, з яких потрібно зробити перехід: \n";
                }
                Matrix basis1, basis2;
                std::cin >> basis1 >> basis2;
                if (g_language == 1) {
                    std::cout << "\nThe solution: \n";
                }
                else {
                    std::cout << "\nРішення: \n";
                }
                std::cout << basis1.transiotion_matrix(basis2);
            } break;

            case 11: {
                if (g_language == 1) {
                    std::cout << "Enter coordinats of the vector, as matrix, its basis and transitional basis: \n";
                }
                else {
                    std::cout << "Введіть координати вектра, як матрицю, його базис та базис, до якого звести: \n";
                }
                Matrix vector, basis1, basis2;
                std::cin >> vector >> basis1 >> basis2;
                if (g_language == 1) {
                    std::cout << "\nLet`s find the transiotion matrix: \n";
                }
                else {
                    std::cout << "\nЗнайдемо матрицю переходу: \n";
                }
                basis2 = basis2.transiotion_matrix(basis1);
                std::cout << basis2;
                if (g_language == 1) {
                    std::cout << "\nTo find the coordinates of the vector in the new basis, multiply the transition matrix by the 'old' coordinates: \n";
                }
                else {
                    std::cout << "\nЩоб знайти координати вектора у новому базисі, перемножимо матрицю переходу на 'старі' координати: \n";
                }
                vector = basis2 * vector;
                std::cout << vector << std::endl;
            } break;

            case 12: {
                if (g_language == 1) {
                    std::cout << "Enter the matrix of liner operator, its basis and transitional basis: \n";
                }
                else {
                    std::cout << "Введіть матрицю, її базис та базис, до якого звести: \n";
                }
                Matrix mat_of_lin_oper, basis1, basis2;
                std::cin >> mat_of_lin_oper >> basis1 >> basis2;
                if (g_language == 1) {
                    std::cout << "\nLet`s fint the transition matrix: \n";
                }
                else {
                    std::cout << "\nЗнайдемо матрицю переходу: \n";
                }
                basis1 = basis1.transiotion_matrix(basis2);
                std::cout << basis1 << std::endl;
                if (g_language == 1) {
                    std::cout << "\nLet`s find inverse matrix of the transition matrix: \n";
                }
                else {
                    std::cout << "\nЗнайдемо обернену матрицю матриці переходу: \n";
                }
                mat_of_lin_oper = basis1.inverse() * mat_of_lin_oper * basis1;
                if (g_language == 1) {
                    std::cout << "\nLet A be the matrix of a linear operator in the 'old' basis, A' be the matrix of the linear operator in the 'new' basis, and U be the matrix of the transition from the old basis to the new one, then: \n";
                }
                else {
                    std::cout << "\nНехай A - матриця лінійного оператора в 'старому' базисі, А' - матриця лінійного оператора  в 'новому' базисі, а U - матриця переходу від старого базису до нового, то: \n";
                }
                std::cout << "\nA' = U^{-1} * A * U; \nA` = \n";
                std::cout << mat_of_lin_oper;
            } break;

            case 13: {
                if (g_language == 1) {
                    std::cout << "Enter the matrix of liner operator, its basis(in pair) and transitional basis(in pair): \n";
                }
                else {
                    std::cout << "Введіть матрицю, її базис(в парі) та базис(в парі), до якого звести: \n";
                }
                Matrix mat_of_lin_oper, basis1_1, basis1_2, basis2_1, basis2_2;
                std::cin >> mat_of_lin_oper >> basis1_1 >> basis1_2 >> basis2_1 >> basis2_2;
                if (g_language == 1) {
                    std::cout << "\nLet`s find the transposition matrix for first pair of basises: \n";
                }
                else {
                    std::cout << "\nЗнайдемо матрицю переходу для першої пари базисів: \n";
                }
                Matrix trans_mat1 = basis1_1.transiotion_matrix(basis2_1);
                std::cout << trans_mat1;
                if (g_language == 1) {
                    std::cout << "\nLet`s find the transposition matrix for second pair of basises: \n";
                }
                else {
                    std::cout << "\nЗнайдемо матрицю переходу для другої пари базисів: \n";
                }
                Matrix trans_mat2 = basis1_2.transiotion_matrix(basis2_2);
                std::cout << trans_mat2;
                if (g_language == 1) {
                    std::cout << "\nLet`s find inverse matrix of second transition matrix: \n";
                }
                else {
                    std::cout << "\nЗнайдемо обернену матрицю другої матриці переходу: \n";
                }
                mat_of_lin_oper = trans_mat2.inverse() * mat_of_lin_oper * trans_mat1;
                if (g_language == 1) {
                    std::cout << "\nLet A be the matrix of a linear operator in the 'old' pair of basises, A' be the matrix of the linear operator in the 'new' pair of basises, U be the matrix of the transition from the first old pair of basises to the new one, and V be the matrix of the transition from the second old pair of basises to the new one, then: \n";
                }
                else {
                    std::cout << "\nНехай A - матриця лінійного оператора в 'старшій' парі базисів, А' - матриця лінійного оператора  в 'новомій' парі базисів, U - матриця переходу від першої старої пари базисів до нової, V - матриця переходу від другої старої пари базисів до новохї, то: \n";
                }
                std::cout << "\nA' = V^{-1} * A * U; \nA` = \n";
                std::cout << mat_of_lin_oper;
            } break;

            case 14: {
                if (g_language == 1) {
                    std::cout << "Enter the basis: \n";
                }
                else {
                    std::cout << "Введіть базис: \n";
                }
                Matrix basis;
                std::cin >> basis;
                if (g_language == 1) {
                    std::cout << "\nThe solve: \n";
                }
                else {
                    std::cout << "\nРішення: \n";
                }
                basis = basis.GrammSchmidt_orthogonalization();
                if (g_language == 1) {
                    std::cout << "\nThe orthonormal basis has the form: \n";
                }
                else {
                    std::cout << "\nОртонормований базис має вигляд: \n";
                }
                std::cout << basis;

            } break;

            case 15: {
                if (g_language == 1) {
                    std::cout << "Enter vector as matrix and its linear shell: \n";
                }
                else {
                    std::cout << "Введіть вектор як матицю та його лінійну оболонку: \n";
                }
                Matrix vector, linear_shell;
                std::cin >> vector >> linear_shell;
                if (g_language == 1) {
                    std::cout << "\nLet`s find the basis of linear shell: \n";
                }
                else {
                    std::cout << "\nЗнайдемо базис лінійної оболонки: \n";
                }
                linear_shell = linear_shell.basis();
                std::cout << linear_shell;
                std::cout << "\nx = pr(x) + ort(x); \npr(x) = x1 * a1 + x2 * a2 + ... + x[i] * a[i]; -";
                if (g_language == 1) {
                    std::cout << " where a[i] - it is vector of basis; \n";
                }
                else {
                    std::cout << " де a[i] - вектор базису; \n";
                }
                if (g_language == 1) {
                    std::cout << "\nMultiply scalarly each member of the equation by vectors from the basis, create a system and solve it by the Gaussian method: \n";
                }
                else {
                    std::cout << "\nДомножимо скалярно кожний член рівняння на вектори з базису, створимо систему та вирішимо її методом Гаус: \n";
                }
                std::cout << "\n{ x1 * (a1; a1) + x2 * (a2; a1) + ... + x[i] * (a[i]; a1) = (x; a1);"
                    "\n{ x1 * (a1; a2) + x2 * (a2; a2) + ... + x[i] * (a[i]; a2) = (x; a2);"
                    "\n{ ................................................................."
                    "\n{ x1 * (a1; a[i]) + x2 * (a2; a[i]) + ... + x[i] * (a[i]; a[i]) = (x; a[i]); \n";
                std::vector <Matrix> vectors_of_basis = linear_shell.extract_vectors();
                std::vector <std::vector <Fraction>> buff(linear_shell.get_j_size() + 1);
                for (unsigned int i = 0; i < buff.size(); i++) {
                    for (unsigned int j = 0; j < buff.size(); j++) {
                        buff[i].push_back(vectors_of_basis[j].scalar_product(vectors_of_basis[i]));
                    }
                    buff[i].push_back(vector.scalar_product(vectors_of_basis[i]));
                }
                Matrix temp(buff.size() - 1, buff.size(), buff);
                std::vector <Matrix> ttemp = temp.Gaussian_Method_With_Extract_Answer();
                if (g_language == 1) {
                    std::cout << "\nSubstitute the obtained values of the coefficients in pr (x): \npr(x) = \n";
                }
                else {
                    std::cout << "\nПідставимо отримані значення коефіцієнтів у pr(x): \npr(x) = \n";
                }
                Matrix prx = ttemp[0].get_matrix()[0][0] * vectors_of_basis[0];
                std::cout << prx << "\nort(x) = x - pr(x); \nort(x) = \n";
                for (int i = 1; i <= ttemp[0].get_i_size(); i++) {
                    prx = prx + ttemp[0].get_matrix()[i][0] * vectors_of_basis[i];
                }
                Matrix ortx = vector - prx;
                std::cout << ortx;
            } break;

            case 16: {
                if (g_language == 1) {
                    std::cout << "Enter the linear shell: \n";
                }
                else {
                    std::cout << "Введіть лінійну оболонку: \n";
                }
                Matrix linear_shell;
                std::cin >> linear_shell;
                if (g_language == 1) {
                    std::cout << "\nLet`s find the basis of the linear shell: \n";
                }
                else {
                    std::cout << "\nЗнайдемо базис лінійної оболонки: \n";
                }
                linear_shell = linear_shell.basis();
                std::cout << linear_shell;
                if (g_language == 1) {
                    std::cout << "\nLet L` be an orthogonal complement to a given space, a[i] - vectors of basis, then: \n";
                }
                else {
                    std::cout << "\nНехай L` - ортогональне доповнення до заданого простору, a[i] - базисні вектори, то: \n";
                }
                std::cout << "x є L` => \n"
                    "{ (x; a1) = 0; \n"
                    "{ (x; a2) = 0;         =>\n"
                    "............. \n"
                    "{ (x; a[i]) = 0; \n"
                    "\n"
                    "{ x1 * a1_1 + x2 * a1_2 + ... + x[j] * a1_[j] = 0; \n"
                    "{ x1 * a2_1 + x2 * a2_2 + ... + x[j] * a2_[j] = 0; \n"
                    "................................................. \n"
                    "{ x1 * a[i]_1 + x2 * a[i]_2 + ... + x[j] * a[i]_[j] = 0; \n";
                linear_shell = linear_shell.transpose();
                std::vector <std::vector <Fraction>> buff = linear_shell.get_matrix();
                for (int i = 0; i <= linear_shell.get_i_size(); i++) {
                    buff[i].push_back(Fraction(0, 1));
                }
                linear_shell.set_j_size(linear_shell.get_j_size() + 1);
                linear_shell.set_matrix(buff);
                std::vector <Matrix> ort_complement = linear_shell.Gaussian_Method_With_Extract_Answer();
                if (g_language == 1) {
                    std::cout << "\nThe orthogonal complement consists of vectors: \n";
                }
                else {
                    std::cout << "\nОртогональне доповнення складається із векторів: \n";
                }
                for (unsigned int i = 0; i < ort_complement.size() - 1; i++) {
                    std::cout << ort_complement[i] << std::endl;
                }
            } break;

            case 17: {
                if (g_language == 1) {
                    std::cout << "Enter the matrix of the linear operator and its basis: \n";
                }
                else {
                    std::cout << "Введіть матрицю лінійного оператора та його базис: \n";
                }
                Matrix mat_of_linear_operator, basis;
                std::cin >> mat_of_linear_operator >> basis;
                if (g_language == 1) {
                    std::cout << "\nFind the matrix of the transition from the canonical basis to this: \n";
                }
                else {
                    std::cout << "\nЗнайдемо матрицю переходу від канонічного базису до даного: \n";
                }
                std::vector <std::vector <Fraction>> buff(basis.get_i_size() + 1);
                for (int i = 0; i <= basis.get_i_size(); i++) {
                    for (int j = 0; j <= basis.get_j_size(); j++) {
                        if (i == j) buff[i].push_back(Fraction(1, 1));
                        else buff[i].push_back(Fraction(0, 1));
                    }
                }
                Matrix canon_basis(basis.get_i_size(), basis.get_j_size(), buff);
                basis = canon_basis.transiotion_matrix(basis);
                std::cout << basis;
                if (g_language == 1) {
                    std::cout << "\nLet`s find the inverse matrix of the transition matrix: \n";
                }
                else {
                    std::cout << "\nЗнайдемо обернену матрицю до матриці переходу: \n";
                }
                Matrix basis_inverse = basis.inverse();
                mat_of_linear_operator = basis * mat_of_linear_operator * basis_inverse;
                std::cout << "\nA_e = U * A * U^{-1}; \nA_e = \n" << mat_of_linear_operator << std::endl;
                if (g_language == 1) {
                    std::cout << "\nWe transpose the matrix of the linear operator in the canonical basis: \n";
                }
                else {
                    std::cout << "\nТранспонуємо матрицю лінійного оператора в канонічному базисі: \n";
                }
                mat_of_linear_operator = mat_of_linear_operator.transpose();
                std::cout << "\nA`_e = \n" << mat_of_linear_operator << std::endl;
                if (g_language == 1) {
                    std::cout << "\nThe matrix of the conjugate operator is sought by the formula: \n";
                }
                else {
                    std::cout << "\nМатриця спряженого оператора шукається за формулою: \n";
                }
                std::cout << "\nA`_f = U^{-1} * A`_e * U; \nA`_f = \n";
                mat_of_linear_operator = basis_inverse * mat_of_linear_operator * basis;
                std::cout << mat_of_linear_operator;

            } break;

            case 18: {
                if (g_language == 1) {
                    std::cout << "Enter the matrix of the linear operator: \n";
                }
                else {
                    std::cout << "Введіть матрицю лінійного оператора: \n";
                }
                Matrix mat_of_linear_operator;
                std::cin >> mat_of_linear_operator;
                if (g_language == 1) {
                    std::cout << "\nEnter the number of eigenvalues and the eigenvalues themselves: \n";
                }
                else {
                    std::cout << "\nВведіть кількість власних чисел та самі власні числа: \n";
                }
                int amount_of_eigenvalues;
                std::cin >> amount_of_eigenvalues;
                std::vector <Fraction> eigenvalues;
                for (int i = 0; i < amount_of_eigenvalues; i++) {
                    Fraction buff;
                    std::cin >> buff;
                    eigenvalues.push_back(buff);
                }
                std::vector <std::vector <Fraction>> buff = mat_of_linear_operator.get_matrix();
                for (int i = 0; i <= mat_of_linear_operator.get_i_size(); i++) {
                    buff[i].push_back(Fraction(0, 1));
                }
                mat_of_linear_operator.set_j_size(mat_of_linear_operator.get_j_size() + 1);
                mat_of_linear_operator.set_matrix(buff);
                for (int i = 0; i < amount_of_eigenvalues; i++) {
                    if (g_language == 1) {
                        std::cout << "\nLet`s find eigenvector for eigenvalue " << eigenvalues[i] << ": \n";
                    }
                    else {
                        std::cout << "\nЗнайдемо власний вектор для власного числа " << eigenvalues[i] << ": \n";
                    }
                    std::vector <std::vector <Fraction>> ttemp = buff;
                    for (int j = 0; j <= mat_of_linear_operator.get_i_size(); j++) {
                        ttemp[j][j] = ttemp[j][j] - eigenvalues[i];
                    }
                    Matrix temp(mat_of_linear_operator.get_i_size(), mat_of_linear_operator.get_j_size(), ttemp);
                    temp.Gaussian_Method_With_Extract_Answer();
                }

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
