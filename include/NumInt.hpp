#ifndef NUMINT_HPP
#define NUMINT_HPP

#include <functional> 

namespace NumInt {
    double TrapezoidalRule(const std::function<double(double)>& f, double a, double b, int n);
// the function 'TrapezoidalRule' will return a double, take an interval [a;b] divided into 'n' trapezoids
    double SimpsonRule(const std::function<double(double)>& f, double a, double b, int n);

    double MCInt(const std::function<double(double)>& f, double a, double b, int n);
}

#endif