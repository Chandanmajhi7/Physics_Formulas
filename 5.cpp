/*5) Gauss Elimination Method
The Gauss Elimination Method solves systems of linear equations by transforming the coefficient matrix into row echelon form through elementary row operations.
Steps:

Forward elimination: Create upper triangular matrix
Back substitution: Solve for variables starting from the last equation*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class GaussElimination {
private:
    int n;
    vector<vector<double>> A;
    
public:
    GaussElimination(vector<vector<double>>& matrix) {
        n = matrix.size();
        A = matrix;
    }
    
    void printMatrix(string title) {
        cout << title << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= n; j++) {
                cout << setw(10) << fixed << setprecision(3) << A[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    
    vector<double> solve() {
        cout << "=== GAUSS ELIMINATION METHOD ===" << endl;
        cout << "System of equations:" << endl;
        cout << "x + 2y + 3z = 9" << endl;
        cout << "2x + 3y + z = 8" << endl;
        cout << "3x + y + 2z = 10" << endl << endl;
        
        printMatrix("Initial Augmented Matrix:");
        
        // Forward elimination
        cout << "Forward Elimination Steps:" << endl;
        for (int k = 0; k < n - 1; k++) {
            // Partial pivoting
            int maxRow = k;
            for (int i = k + 1; i < n; i++) {
                if (abs(A[i][k]) > abs(A[maxRow][k])) {
                    maxRow = i;
                }
            }
            
            if (maxRow != k) {
                swap(A[k], A[maxRow]);
                cout << "Swapped rows " << k + 1 << " and " << maxRow + 1 << endl;
            }
            
            // Eliminate column k
            for (int i = k + 1; i < n; i++) {
                if (A[k][k] != 0) {
                    double factor = A[i][k] / A[k][k];
                    cout << "R" << i + 1 << " = R" << i + 1 << " - (" << factor << ") * R" << k + 1 << endl;
                    
                    for (int j = k; j <= n; j++) {
                        A[i][j] -= factor * A[k][j];
                    }
                }
            }
            
            printMatrix("After elimination step " + to_string(k + 1) + ":");
        }
        
        // Back substitution
        cout << "Back Substitution:" << endl;
        vector<double> x(n, 0);
        
        for (int i = n - 1; i >= 0; i--) {
            x[i] = A[i][n];
            for (int j = i + 1; j < n; j++) {
                x[i] -= A[i][j] * x[j];
            }
            x[i] /= A[i][i];
            cout << "x[" << i + 1 << "] = " << x[i] << endl;
        }
        
        return x;
    }
};

int main() {
    // System: x + 2y + 3z = 9
    //         2x + 3y + z = 8  
    //         3x + y + 2z = 10
    
    vector<vector<double>> matrix = {
        {1, 2, 3, 9},
        {2, 3, 1, 8},
        {3, 1, 2, 10}
    };
    
    GaussElimination gauss(matrix);
    vector<double> solution = gauss.solve();
    
    cout << "\n=== SOLUTION ===" << endl;
    cout << "x = " << solution[0] << endl;
    cout << "y = " << solution[1] << endl;
    cout << "z = " << solution[2] << endl;
    
    // Verification
    cout << "\n=== VERIFICATION ===" << endl;
    double eq1 = solution[0] + 2*solution[1] + 3*solution[2];
    double eq2 = 2*solution[0] + 3*solution[1] + solution[2];
    double eq3 = 3*solution[0] + solution[1] + 2*solution[2];
    
    cout << "x + 2y + 3z = " << eq1 << " (should be 9)" << endl;
    cout << "2x + 3y + z = " << eq2 << " (should be 8)" << endl;
    cout << "3x + y + 2z = " << eq3 << " (should be 10)" << endl;
    
    return 0;
}