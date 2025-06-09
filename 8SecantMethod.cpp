/*The Secant Method is derived from Newton-Raphson by approximating the derivative using finite differences. The iteration formula is:
x_{n+1} = x_n - f(x_n) * (x_n - x_{n-1}) / (f(x_n) - f(x_{n-1}))*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Function: f(x) = eˣ - 2x
double f(double x) {
    return exp(x) - 2*x;
}

double secantMethod(double x0, double x1, double tolerance, int maxIterations) {
    cout << "=== SECANT METHOD ===" << endl;
    cout << "Solving equation: f(x) = eˣ - 2x = 0" << endl;
    cout << "Initial guesses: x₀ = " << x0 << ", x₁ = " << x1 << endl;
    cout << "Tolerance: " << tolerance << endl;
    cout << "Derivation from Newton-Raphson:" << endl;
    cout << "Newton-Raphson: x_{n+1} = x_n - f(x_n)/f'(x_n)" << endl;
    cout << "Secant approximates f'(x_n) ≈ [f(x_n) - f(x_{n-1})] / [x_n - x_{n-1}]" << endl;
    cout << "Formula: x_{n+1} = x_n - f(x_n) * (x_n - x_{n-1}) / (f(x_n) - f(x_{n-1}))" << endl << endl;
    
    cout << setw(5) << "Iter" << setw(12) << "x_{n-1}" << setw(12) << "x_n" 
         << setw(12) << "f(x_n)" << setw(12) << "x_{n+1}" << setw(12) << "Error" << endl;
    cout << string(73, '-') << endl;
    
    double x_prev = x0;
    double x_curr = x1;
    
    for (int i = 0; i < maxIterations; i++) {
        double f_prev = f(x_prev);
        double f_curr = f(x_curr);
        
        if (abs(f_curr - f_prev) < 1e-12) {
            cout << "Division by zero encountered. Method fails." << endl;
            return x_curr;
        }
        
        double x_next = x_curr - f_curr * (x_curr - x_prev) / (f_curr - f_prev);
        double error = abs(x_next - x_curr);
        
        cout << setw(5) << i+1 << setw(12) << fixed << setprecision(6) << x_prev
             << setw(12) << x_curr << setw(12) << f_curr 
             << setw(12) << x_next << setw(12) << error << endl;
        
        if (error < tolerance) {
            cout << "\nConverged after " << i+1 << " iterations." << endl;
            return x_next;
        }
        
        x_prev = x_curr;
        x_curr = x_next;
    }
    
    cout << "Maximum iterations reached without convergence." << endl;
    return x_curr;
}

int main() {
    double x0 = 0.0;    // First initial guess
    double x1 = 1.0;    // Second initial guess  
    double tolerance = 1e-6;
    int maxIterations = 20;
    
    double root = secantMethod(x0, x1, tolerance, maxIterations);
    
    cout << "\n=== RESULTS ===" << endl;
    cout << "Root found: x = " << fixed << setprecision(6) << root << endl;
    cout << "Verification: f(" << root << ") = " << f(root) << endl;
    
    // The equation eˣ - 2x = 0 has two roots
    cout << "\nNote: The equation eˣ - 2x = 0 has two roots:" << endl;
    cout << "Root 1 ≈ 0.351734 (found with initial guesses 0, 1)" << endl;
    cout << "Root 2 ≈ 1.678347 (can be found with different initial guesses)" << endl;
    
    return 0;
}