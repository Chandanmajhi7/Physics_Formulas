#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

// Differential equation: dy/dx = x² + y, y(0) = 1
double f(double x, double y) {
    return x*x + y;
}

// Exact solution for verification: y = -x² - 2x - 2 + 3e^x
double exactSolution(double x) {
    return -x*x - 2*x - 2 + 3*exp(x);
}

class RungeKutta2nd {
public:
    void derivation() {
        cout << "=== RUNGE-KUTTA 2ND ORDER DERIVATION ===" << endl;
        cout << "Starting from Taylor series expansion:" << endl;
        cout << "y(x+h) = y(x) + h*y'(x) + (h²/2)*y''(x) + O(h³)" << endl << endl;
        
        cout << "Since y' = f(x,y), we have:" << endl;
        cout << "y''(x) = df/dx + (df/dy)*y' = df/dx + (df/dy)*f(x,y)" << endl << endl;
        
        cout << "Runge-Kutta 2nd order approximates y''(x) using:" << endl;
        cout << "k₁ = h*f(xₙ, yₙ)" << endl;
        cout << "k₂ = h*f(xₙ + h, yₙ + k₁)" << endl;
        cout << "yₙ₊₁ = yₙ + (1/2)(k₁ + k₂)" << endl << endl;
        
        cout << "This gives us second-order accuracy O(h³) truncation error." << endl;
        cout << "Alternative forms exist (Heun's method, Modified Euler, etc.)" << endl << endl;
    }
    
    vector<pair<double, double>> solve(double x0, double y0, double h, double x_final) {
        vector<pair<double, double>> solution;
        
        double x = x0;
        double y = y0;
        
        cout << "=== RUNGE-KUTTA 2ND ORDER SOLUTION ===" << endl;
        cout << "Solving: dy/dx = x² + y, y(0) = 1" << endl;
        cout << "Step size h = " << h << endl;
        cout << "Final x = " << x_final << endl << endl;
        
        cout << setw(5) << "n" << setw(8) << "xₙ" << setw(10) << "yₙ" 
             << setw(10) << "k₁" << setw(10) << "k₂" << setw(12) << "yₙ₊₁" 
             << setw(12) << "Exact" << setw(12) << "Error" << endl;
        cout << string(85, '-') << endl;
        
        int n = 0;
        solution.push_back({x, y});
        
        while (x < x_final) {
            double k1 = h * f(x, y);
            double k2 = h * f(x + h, y + k1);
            
            double y_new = y + 0.5 * (k1 + k2);
            double exact = exactSolution(x + h);
            double error = abs(y_new - exact);
            
            cout << setw(5) << n << setw(8) << fixed << setprecision(3) << x
                 << setw(10) << setprecision(4) << y << setw(10) << k1 
                 << setw(10) << k2 << setw(12) << y_new 
                 << setw(12) << exact << setw(12) << error << endl;
            
            x += h;
            y = y_new;
            solution.push_back({x, y});
            n++;
        }
        
        return solution;
    }
    
    void compareWithEuler(double x0, double y0, double h, double x_final) {
        cout << "\n=== COMPARISON WITH EULER'S METHOD ===" << endl;
        
        double x = x0, y_euler = y0, y_rk2 = y0;
        
        cout << setw(8) << "x" << setw(12) << "Euler" << setw(12) << "RK2" 
             << setw(12) << "Exact" << setw(12) << "Euler Err" << setw(12) << "RK2 Err" << endl;
        cout << string(80, '-') << endl;
        
        while (x <= x_final) {
            double exact = exactSolution(x);
            double euler_error = abs(y_euler - exact);
            double rk2_error = abs(y_rk2 - exact);
            
            cout << setw(8) << fixed << setprecision(3) << x
                 << setw(12) << setprecision(6) << y_euler << setw(12) << y_rk2
                 << setw(12) << exact << setw(12) << euler_error << setw(12) << rk2_error << endl;
            
            if (x < x_final) {
                // Euler step
                y_euler = y_euler + h * f(x, y_euler);
                
                // RK2 step
                double k1 = h * f(x, y_rk2);
                double k2 = h * f(x + h, y_rk2 + k1);
                y_rk2 = y_rk2 + 0.5 * (k1 + k2);
                
                x += h;
            } else {
                break;
            }
        }
    }
};

int main() {
    RungeKutta2nd rk;
    
    rk.derivation();
    
    double x0 = 0.0;  // Initial x
    double y0 = 1.0;  // Initial y  
    double h = 0.1;   // Step size
    double x_final = 0.1;  // Final x
    
    auto solution = rk.solve(x0, y0, h, x_final);
    
    rk.compareWithEuler(x0, y0, h, x_final);
    
    cout << "\n=== METHOD CHARACTERISTICS ===" << endl;
    cout << "Runge-Kutta 2nd Order (RK2):" << endl;
    cout << "• Order of accuracy: O(h³) truncation error" << endl;
    cout << "• More accurate than Euler's method O(h²)" << endl;
    cout << "• Requires 2 function evaluations per step" << endl;
    cout << "• Good balance between accuracy and computational cost" << endl;
    cout << "• Also known as Heun's method or Modified Euler method" << endl;
    
    return 0;
}