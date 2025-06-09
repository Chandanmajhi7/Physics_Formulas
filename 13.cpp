/*
13: Linear Differential Equation
Problem: dy/dx + y = e^x, y(0) = 1
This is a first-order linear differential equation of the form: dy/dx + P(x)y = Q(x)
Where P(x) = 1 and Q(x) = e^x
Integrating Factor Method:
Step 1: Find the integrating factor μ(x)
μ(x) = e^(∫P(x)dx) = e^(∫1 dx) = e^x
Step 2: Multiply the equation by μ(x)
e^x(dy/dx) + e^x·y = e^x·e^x
e^x(dy/dx) + ye^x = e^(2x)
Step 3: The left side is the derivative of ye^x
d/dx(ye^x) = e^(2x)
Step 4: Integrate both sides
ye^x = ∫e^(2x)dx = (1/2)e^(2x) + C
Step 5: Solve for y
y = (1/2)e^x + Ce^(-x)
Step 6: Apply initial condition y(0) = 1
1 = (1/2)e^0 + Ce^0 = 1/2 + C
C = 1/2
Final Solution: y = (1/2)e^x + (1/2)e^(-x) = (1/2)(e^x + e^(-x))
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Analytical solution
double analyticalSolution(double x) {
    return 0.5 * (exp(x) + exp(-x));
}

// Numerical solution using 4th order Runge-Kutta
double rungeKutta4(double x0, double y0, double x, double h) {
    int n = static_cast<int>((x - x0) / h);
    double y = y0;
    double xi = x0;
    
    for (int i = 0; i < n; i++) {
        double k1 = h * (-y + exp(xi));
        double k2 = h * (-(y + k1/2) + exp(xi + h/2));
        double k3 = h * (-(y + k2/2) + exp(xi + h/2));
        double k4 = h * (-(y + k3) + exp(xi + h));
        
        y = y + (k1 + 2*k2 + 2*k3 + k4) / 6;
        xi = xi + h;
    }
    
    return y;
}

int main() {
    double x0 = 0.0, y0 = 1.0;
    double h = 0.1;
    double x_final = 1.0;
    
    cout << fixed << setprecision(6);
    cout << "Solving dy/dx + y = e^x, y(0) = 1" << endl;
    cout << "Using integrating factor method" << endl << endl;
    
    cout << "x\t\tAnalytical\tNumerical\tError" << endl;
    cout << "--------------------------------------------" << endl;
    
    for (double x = x0; x <= x_final; x += 0.2) {
        double analytical = analyticalSolution(x);
        double numerical = rungeKutta4(x0, y0, x, h);
        double error = abs(analytical - numerical);
        
        cout << x << "\t\t" << analytical << "\t" << numerical << "\t" << error << endl;
    }
    
    return 0;
}