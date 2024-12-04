#include <iostream>
#include "NumInt.hpp"

double examplefunction(double x) {
    return x * x;
}

int main() {
    const double a = 0.0;
    const double b = 1.0;
    const int n = 1000;

    printf("Integration of f(x) = x^2 over the interval [%f, %f]:\n", a, b);

    double result_Trap = NumInt::TrapezoidalRule(examplefunction, a, b, n);
    printf("Using trapezoidal rule: %f\n", result_Trap);

    double result_Simpson = NumInt::SimpsonRule(examplefunction, a, b, n);
    printf("Using Simpson rule: %f\n", result_Simpson);

    double result_mc = NumInt::MCInt(examplefunction, a, b, n);
    printf("Using Monte Carlo integration: %f\n", result_mc);

    printf("Normally Simpson rule is the more precise numerical method \n than the other one chosen here, and the MC integration obviously \n slightly vary between runs because of its stochastic nature");

    return 0;
}

