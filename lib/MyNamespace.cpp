#include "./Classes.h"


Fraction Math::pow (Fraction a, int b) {
    Fraction buff = 1;
    if (a.numerator == 0) {
        buff.numerator = 0;
    }
    else if (b < 0) {
        int temp = a.numerator;
        a.numerator = a.denominator;
        a.denominator = temp;
    }
    for (int i = 0; i < b; i++) {
        buff = buff * a;
    }

    return buff;
}
