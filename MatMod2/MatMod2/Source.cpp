#include <iostream>
#include <cmath>
#include <fstream>

static double f(double, double, double, double);
static void coord(double, double, double, double, double, double, double, double);

int main() {
    double A = 2.0;
    double B = 3.0;

    double x0 = 3.0;
    double y0 = 2.0;

    double h = 0.1;
    double M = 1.5;
    double N = 0.5;
    double epsilon = 0.001;

    coord(A, B, x0, y0, h, M, N, epsilon);

    return 0;
}

static double f(double x, double y, double A, double B) {
    return pow(x / A, 2) + pow(y / B, 2);
}

static void coord(double A, double B, double x0, double y0, double h, double M, double N, double epsilon) {
    double x = x0;
    double y = y0;
    int k = 0;
    double h1 = h;
    double h2 = h;

    std::ofstream file("result.txt");
    while (true) {
        ++k;
        double x_prev = x;
        double x_new = x + h1;
        if (f(x_new, y, A, B) < f(x, y, A, B)) {
            x = x_new;
            h1 *= M;
        }
        else {
            h1 *= -N;
        }
       
        double y_prev = y;        
        double y_new = y + h2;
        if (f(x, y_new, A, B) < f(x, y, A, B)) {
            y = y_new;
            h2 *= M;
        }
        else {
            h2 *= -N;
        }
        
        file << x << '\t' << y << '\t' << f(x, y, A, B) << "\n";
        
        if (std::abs(f(x_new, y_new, A, B) - f(x_prev, y_prev, A, B)) < epsilon) {
            break;
        }
    }

    file.close();

    std::cout << "Iterations: " << k << "\n";
    std::cout << "Min coord: (" << x << "\t " << y << ")" << "\n";
    std::cout << "Min value: " << f(x, y, A, B) << "\n";
}