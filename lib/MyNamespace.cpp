#include "./Classes.h"

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
