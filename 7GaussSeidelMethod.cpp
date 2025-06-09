/*The Gauss-Seidel method is an iterative technique for solving systems of linear equations. It updates each variable using the most recent values of other variables.*/

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

class GaussSeidel {
private:
    int n;
    vector<vector<double>> A;
    vector<double> b;
    
public:
    GaussSeidel(vector<vector<double>>& matrix, vector<double>& rhs) {
        n = matrix.size();
        A = matrix;
        b = rhs;
    }
    
    bool isDiagonallyDominant() {
        for (int i = 0; i < n; i++) {
            double sum = 0;
            for (int j = 0; j < n; j++) {
                if (i != j) sum += abs(A[i][j]);
            }
            if (abs(A[i][i]) < sum) return false;
        }
        return true;
    }
    
    void rearrangeForDominance() {
        // Rearrange to make diagonally dominant
        // 12x₁ + 3x₂ - 5x₃ = 1
        // x₁ + 5x₂ + 3x₃ = 28  
        // 3x₁ + 7x₂ + 13x₃ = 76
        
        A = {{12, 3, -5}, {1, 5, 3}, {3, 7, 13}};
        b = {1, 28, 76};
        
        cout << "System rearranged for diagonal dominance:" << endl;
        cout << "12x₁ + 3x₂ - 5x₃ = 1" << endl;
        cout << "x₁ + 5x₂ + 3x₃ = 28" << endl;  
        cout << "3x₁ + 7x₂ + 13x₃ = 76" << endl << endl;
    }
    
    vector<double> solve(double tolerance = 1e-6, int maxIterations = 50) {
        cout << "=== GAUSS-SEIDEL METHOD ===" << endl;
        
        rearrangeForDominance();
        
        if (!isDiagonallyDominant()) {
            cout << "Warning: Matrix is not diagonally dominant. Convergence not guaranteed." << endl;
        }
        
        vector<double> x(n, 0);  // Initial guess: all zeros
        vector<double> x_old(n);
        
        cout << "Iterative formulas:" << endl;
        cout << "x₁ = (1 - 3x₂ + 5x₃) / 12" << endl;
        cout << "x₂ = (28 - x₁ - 3x₃) / 5" << endl;
        cout << "x₃ = (76 - 3x₁ - 7x₂) / 13" << endl << endl;
        
        cout << setw(5) << "Iter" << setw(12) << "x₁" << setw(12) << "x₂" 
             << setw(12) << "x₃" << setw(12) << "Max Error" << endl;
        cout << string(65, '-') << endl;
        
        for (int iter = 0; iter < maxIterations; iter++) {
            x_old = x;
            
            // Update each variable using most recent values
            for (int i = 0; i < n; i++) {
                double sum = 0;
                for (int j = 0; j < n; j++) {
                    if (i != j) sum += A[i][j] * x[j];
                }
                x[i] = (b[i] - sum) / A[i][i];
            }
            
            // Calculate maximum error
            double maxError = 0;
            for (int i = 0; i < n; i++) {
                double error = abs(x[i] - x_old[i]);
                if (error > maxError) maxError = error;
            }
            
            cout << setw(5) << iter + 1;
            for (int i = 0; i < n; i++) {
                cout << setw(12) << fixed << setprecision(6) << x[i];
            }
            cout << setw(12) << maxError << endl;
            
            if (maxError < tolerance) {
                cout << "\nConverged after " << iter + 1 << " iterations." << endl;
                break;
            }
        }
        
        return x;
    }
};

int main() {
    // Original system:
    // 12x₁ + 3x₂ - 5x₃ = 1
    // x₁ + 5x₂ + 3x₃ = 28
    // 3x₁ + 7x₂ + 13x₃ = 76
    
    vector<vector<double>> matrix = {{12, 3, -5}, {1, 5, 3}, {3, 7, 13}};
    vector<double> rhs = {1, 28, 76};
    
    GaussSeidel gs(matrix, rhs);
    vector<double> solution = gs.solve();
    
    cout << "\n=== FINAL SOLUTION ===" << endl;
    cout << "x₁ = " << fixed << setprecision(6) << solution[0] << endl;
    cout << "x₂ = " << fixed << setprecision(6) << solution[1] << endl;
    cout << "x₃ = " << fixed << setprecision(6) << solution[2] << endl;
    
    // Verification
    cout << "\n=== VERIFICATION ===" << endl;
    double eq1 = 12*solution[0] + 3*solution[1] - 5*solution[2];
    double eq2 = solution[0] + 5*solution[1] + 3*solution[2];
    double eq3 = 3*solution[0] + 7*solution[1] + 13*solution[2];
    
    cout << "12x₁ + 3x₂ - 5x₃ = " << eq1 << " (should be 1)" << endl;
    cout << "x₁ + 5x₂ + 3x₃ = " << eq2 << " (should be 28)" << endl;
    cout << "3x₁ + 7x₂ + 13x₃ = " << eq3 << " (should be 76)" << endl;
    
    return 0;
}