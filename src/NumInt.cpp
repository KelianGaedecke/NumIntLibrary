#include "NumInt.hpp"
#include <cmath>
#include <random>
#include <stdexcept>

namespace NumInt {

    double TrapezoidalRule(const std::function<double(double)>& f, double a, double b, int n) {
        if (n <= 0) {
            throw std::runtime_error("Number of intervals 'n' must be greater than 0.");
        }
        double h = (b - a) / n;  // Step size
        double result{0};

        for (int i = 1; i < n; ++i) {
            result += (f(a + i * h) + f(a)) * h;
        }

        return result;
    }

    double SimpsonRule(const std::function<double(double)>& f, double a, double b, int n) {
        if (n <= 0) {
            throw std::runtime_error("Number of intervals 'n' must be greater than 0.");
        }
        if (n % 2 != 0) {
            n++;
        }
        double h = (b - a) / n;
        double result = f(b) + f(a);

        for (int i = 1; i < n; i += 2) {
            result += 4 * f(a + i * h);
        }
        for (int i = 2; i < n; i += 2) {
            result += 2 * f(a + i * h);
        }

        result = result * (h / 3.0);
        return result;
    }

    double MCInt(const std::function<double(double)>& f, double a, double b, int n) {
        if (n <= 0) {
            throw std::runtime_error("Number of samples 'n' must be greater than 0.");
        }
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(a, b);

        double sum = 0.0;
        for (int i = 0; i < n; ++i) {
            double x = dis(gen);
            sum += f(x);
        }
        return (b - a) * sum / n;
    }

}
