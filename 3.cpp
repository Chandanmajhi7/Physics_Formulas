/* The Trapezoidal Rule approximates definite integrals by dividing the area under a curve into trapezoids. It's derived from the General Quadrature Formula by using linear interpolation.
Formula: ∫[a to b] f(x)dx ≈ (h/2)[f(a) + 2∑f(xi) + f(b)]
where h = (b-a)/n
Limitations:

Less accurate for functions with high curvature
Error is proportional to h³, so requires many intervals for high precision
Assumes linear behavior between points */

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Function to integrate: f(x) = x² + 1
double f(double x) {
    return x*x + 1;
}

double trapezoidalRule(double a, double b, int n) {
    double h = (b - a) / n;  // Step size
    double sum = f(a) + f(b);  // First and last terms
    
    // Add middle terms with coefficient 2
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += 2 * f(x);
    }
    
    return (h / 2) * sum;
}

int main() {
    double a = 0.0;  // Lower limit
    double b = 1.0;  // Upper limit  
    int n = 10;      // Number of subintervals
    
    cout << fixed << setprecision(6);
    cout << "=== TRAPEZOIDAL RULE INTEGRATION ===" << endl;
    cout << "Function: f(x) = x² + 1" << endl;
    cout << "Limits: [" << a << ", " << b << "]" << endl;
    cout << "Number of subintervals: " << n << endl;
    
    double result = trapezoidalRule(a, b, n);
    
    cout << "\nApproximate integral: " << result << endl;
    
    // Exact value for comparison: ∫(x² + 1)dx from 0 to 1 = [x³/3 + x] = 1/3 + 1 = 4/3
    double exact = 4.0/3.0;
    cout << "Exact value: " << exact << endl;
    cout << "Error: " << abs(result - exact) << endl;
    cout << "Relative error: " << abs(result - exact)/exact * 100 << "%" << endl;
    
    return 0;
}