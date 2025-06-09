#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

class NumericalDifferentiation {
private:
    vector<double> x, y;
    int n;
    
public:
    void addPoint(double xi, double yi) {
        x.push_back(xi);
        y.push_back(yi);
        n = x.size();
    }
    
    vector<vector<double>> computeDifferenceTable() {
        vector<vector<double>> table(n, vector<double>(n, 0));
        
        // First column is y values
        for (int i = 0; i < n; i++) {
            table[i][0] = y[i];
        }
        
        // Compute forward differences
        for (int j = 1; j < n; j++) {
            for (int i = 0; i < n - j; i++) {
                table[i][j] = table[i+1][j-1] - table[i][j-1];
            }
        }
        
        return table;
    }
    
    void printDifferenceTable(const vector<vector<double>>& table) {
        cout << "=== FORWARD DIFFERENCE TABLE ===" << endl;
        cout << setw(6) << "x" << setw(10) << "y" << setw(10) << "Δy" 
             << setw(10) << "Δ²y" << setw(10) << "Δ³y" << setw(10) << "Δ⁴y" << endl;
        cout << string(60, '-') << endl;
        
        for (int i = 0; i < n; i++) {
            cout << setw(6) << fixed << setprecision(1) << x[i];
            for (int j = 0; j < n - i; j++) {
                cout << setw(10) << setprecision(4) << table[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    
    double newtonForwardDerivative(double x_val, const vector<vector<double>>& table) {
        // Find the interval containing x_val
        int index = 0;
        double h = x[1] - x[0];  // Assuming equal spacing
        
        // For Newton's forward formula: f'(x₀) ≈ (1/h)[Δy₀ - (1/2)Δ²y₀ + (1/3)Δ³y₀ - ...]
        cout << "=== NEWTON'S FORWARD DIFFERENTIATION FORMULA ===" << endl;
        cout << "For equally spaced points with h = " << h << endl;
        cout << "f'(x₀) ≈ (1/h)[Δy₀ - (1/2)Δ²y₀ + (1/3)Δ³y₀ - (1/4)Δ⁴y₀ + ...]" << endl << endl;
        
        double derivative = table[0][1]/h;  // First term: Δy₀/h
        cout << "First term: Δy₀/h = " << table[0][1] << "/" << h << " = " << derivative << endl;
        
        if (n > 2) {
            double term2 = -0.5 * table[0][2]/h;
            derivative += term2;
            cout << "Second term: -(1/2)Δ²y₀/h = -0.5 × " << table[0][2] << "/" << h << " = " << term2 << endl;
        }
        
        if (n > 3) {
            double term3 = (1.0/3.0) * table[0][3]/h;
            derivative += term3;
            cout << "Third term: (1/3)Δ³y₀/h = (1/3) × " << table[0][3] << "/" << h << " = " << term3 << endl;
        }
        
        if (n > 4) {
            double term4 = -0.25 * table[0][4]/h;
            derivative += term4;
            cout << "Fourth term: -(1/4)Δ⁴y₀/h = -0.25 × " << table[0][4] << "/" << h << " = " << term4 << endl;
        }
        
        return derivative;
    }
    
    double centralDifference(int index) {
        if (index <= 0 || index >= n-1) {
            cout << "Central difference not applicable at endpoints." << endl;
            return 0;
        }
        
        double h = x[1] - x[0];
        return (y[index+1] - y[index-1]) / (2*h);
    }
    
    void demonstrateMethods() {
        cout << "=== NUMERICAL DIFFERENTIATION METHODS ===" << endl;
        cout << "Given data points for function f(x):" << endl;
        
        for (int i = 0; i < n; i++) {
            cout << "f(" << x[i] << ") = " << y[i] << endl;
        }
        cout << endl;
        
        auto table = computeDifferenceTable();
        printDifferenceTable(table);
        
        // Newton's forward differentiation at x₀
        double forward_deriv = newtonForwardDerivative(x[0], table);
        cout << "\nNewton's forward derivative at x₀ = " << x[0] << ": " << forward_deriv << endl;
        
        // Central difference at middle point
        int mid = n/2;
        double central_deriv = centralDifference(mid);
        cout << "Central difference at x = " << x[mid] << ": " << central_deriv << endl;
        
        // Backward difference at last point
        double h = x[1] - x[0];
        double backward_deriv = (y[n-1] - y[n-2]) / h;
        cout << "Backward difference at x = " << x[n-1] << ": " << backward_deriv << endl;
    }
};

int main() {
    NumericalDifferentiation nd;
    
    // Example: f(x) = x² + 2x + 1
    // Exact derivative: f'(x) = 2x + 2
    nd.addPoint(0.0, 1.0);   // f(0) = 1
    nd.addPoint(1.0, 4.0);   // f(1) = 4  
    nd.addPoint(2.0, 9.0);   // f(2) = 9
    nd.addPoint(3.0, 16.0);  // f(3) = 16
    nd.addPoint(4.0, 25.0);  // f(4) = 25
    
    nd.demonstrateMethods();
    
    cout << "\n=== VERIFICATION ===" << endl;
    cout << "For f(x) = x² + 2x + 1, exact derivative f'(x) = 2x + 2" << endl;
    cout << "f'(0) = 2, f'(2) = 6, f'(4) = 10" << endl;
    cout << "Compare with numerical results above." << endl;
    
    cout << "\n=== APPLICATIONS ===" << endl;
    cout << "Newton's interpolation formulas for differentiation are used when:" << endl;
    cout << "1. Analytical derivative is difficult to compute" << endl;
    cout << "2. Function is known only at discrete points" << endl;
    cout << "3. Data comes from experiments or measurements" << endl;
    cout << "4. Forward differences: near beginning of interval" << endl;
    cout << "5. Central differences: best accuracy in middle" << endl;
    cout << "6. Backward differences: near end of interval" << endl;
    
    return 0;
}