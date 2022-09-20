//
// Created by Семён Чубенко on 17.09.2022.
//

#include "Complex_num.h"

Complex_num::Complex_num() {
    a = 0;
    b = 0;
}

Complex_num::Complex_num(double a, double b) {
    this->a = a;
    this->b = b;
}

Complex_num Complex_num::operator*(const Complex_num &num) const {
    return {a * num.a - b * num.b, a * num.b + b * num.a};
}

double Complex_num::abs() const {
    return sqrt(b * b + a * a);
}

Complex_num Complex_num::operator+(const Complex_num &num) const {
    return {a + num.a, b + num.b};
}
