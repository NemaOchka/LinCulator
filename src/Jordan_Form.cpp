#include "../lib/Classes.h"

// Пофіксити:
// - при виводі через std::cout не можна використовувати методи користувацьких класів (те ж саме при використанні return)
//


// Написати програму яка буде знаходи Нормальну Жорданову Форму Матриці, отримуючи на вхід тільки матриці лінійного оператора
// Написати клас Matrix, Frac (математичні дроби) та їх відповідні методи
// Описати роботу програми із змінними (знаходження власно числа) та в системі лінійних рівнянь



int main() {


    Matrix mat, mat2;
    std::cout << "Enter matrix: \n";
    std::cin >> mat;
    std::cout << "\nNow get it inversed: \n";
    mat2 = mat.inverse();
    std::cout << mat2;

    std::cout << "\n";
    return 0;
}
