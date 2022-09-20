//
// Created by Семён Чубенко on 17.09.2022.
//

#ifndef FRACTALS_COMPLEX_NUM_H
#define FRACTALS_COMPLEX_NUM_H

#include "iostream"
#include "cmath"

class Complex_num {
public:
    double a, b;

    Complex_num();
    Complex_num(double a, double  b);

    double abs() const;

    Complex_num operator * (const Complex_num& num) const;
    Complex_num operator + (const Complex_num& num) const;
};


#endif //FRACTALS_COMPLEX_NUM_H
