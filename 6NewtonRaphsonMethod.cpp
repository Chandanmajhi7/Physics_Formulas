#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Function: f(x) = x² - 2
double f(double x) {
    return x*x - 2;
}

// Derivative: f'(x) = 2x
double df(double x) {
    return 2*x;
}

double newtonRaphson(double x0, double tolerance, int maxIterations) {
    cout << "=== NEWTON-RAPHSON METHOD ===" << endl;
    cout << "Solving equation: x² - 2 = 0" << endl;
    cout << "Initial guess: x₀ = " << x0 << endl;
    cout << "Tolerance: " << tolerance << endl;
    cout << "Formula: x_{n+1} = x_n - f(x_n)/f'(x_n)" << endl << endl;
    
    cout << setw(10) << "Iteration" << setw(15) << "x_n" << setw(15) << "f(x_n)" 
         << setw(15) << "f'(x_n)" << setw(15) << "x_{n+1}" << setw(15) << "Error" << endl;
    cout << string(90, '-') << endl;
    
    double x = x0;
    
    for (int i = 0; i < maxIterations; i++) {
        double fx = f(x);
        double dfx = df(x);
        
        if (abs(dfx) < 1e-12) {
            cout << "Derivative is zero. Method fails." << endl;
            return x;
        }
        
        double x_new = x - fx/dfx;
        double error = abs(x_new - x);
        
        cout << setw(10) << i+1 << setw(15) << fixed << setprecision(6) << x
             << setw(15) << fx << setw(15) << dfx 
             << setw(15) << x_new << setw(15) << error << endl;
        
        if (error < tolerance) {
            cout << "\nConverged after " << i+1 << " iterations." << endl;
            return x_new;
        }
        
        x = x_new;
    }
    
    cout << "Maximum iterations reached without convergence." << endl;
    return x;
}

int main() {
    double x0 = 1.0;      // Initial guess
    double tolerance = 1e-6;  // Tolerance (3 decimal places ≈ 1e-3, but using 1e-6 for better precision)
    int maxIterations = 10;
    
    double root = newtonRaphson(x0, tolerance, maxIterations);
    
    cout << "\n=== RESULTS ===" << endl;
    cout << "Root found: x = " << fixed << setprecision(6) << root << endl;
    cout << "Verification: f(" << root << ") = " << f(root) << endl;
    cout << "Exact root: √2 = " << sqrt(2) << endl;
    cout << "Error from exact: " << abs(root - sqrt(2)) << endl;
    
    return 0;
}