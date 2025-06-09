/*Weighted least squares is used when data points have different reliabilities. The normal equations for fitting y = a + bx with weights w_i are:
Normal Equations:

Σ(w_i)a + Σ(w_ix_i)b = Σ(w_iy_i)
Σ(w_ix_i)a + Σ(w_ix_i²)b = Σ(w_ix_iy_i)
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct DataPoint {
    double x, y, w;  // x, y coordinates and weight
};

class WeightedLeastSquares {
private:
    vector<DataPoint> data;
    
public:
    void addDataPoint(double x, double y, double w) {
        data.push_back({x, y, w});
    }
    
    pair<double, double> fit() {
        cout << "=== WEIGHTED LEAST SQUARES ===" << endl;
        cout << "Fitting line: y = a + bx" << endl;
        cout << "Minimizing: Σ w_i * (y_i - a - b*x_i)²" << endl << endl;
        
        cout << "Data points:" << endl;
        cout << setw(5) << "i" << setw(8) << "x_i" << setw(8) << "y_i" << setw(8) << "w_i" << endl;
        cout << string(35, '-') << endl;
        
        for (int i = 0; i < data.size(); i++) {
            cout << setw(5) << i+1 << setw(8) << data[i].x << setw(8) << data[i].y << setw(8) << data[i].w << endl;
        }
        
        // Calculate sums for normal equations
        double sum_w = 0, sum_wx = 0, sum_wy = 0, sum_wx2 = 0, sum_wxy = 0;
        
        for (const auto& point : data) {
            sum_w += point.w;
            sum_wx += point.w * point.x;
            sum_wy += point.w * point.y;
            sum_wx2 += point.w * point.x * point.x;
            sum_wxy += point.w * point.x * point.y;
        }
        
        cout << "\n=== NORMAL EQUATIONS DERIVATION ===" << endl;
        cout << "To minimize Σ w_i * (y_i - a - b*x_i)², we take partial derivatives:" << endl;
        cout << "∂/∂a: Σ w_i * (y_i - a - b*x_i) * (-1) = 0" << endl;
        cout << "∂/∂b: Σ w_i * (y_i - a - b*x_i) * (-x_i) = 0" << endl << endl;
        
        cout << "This gives the normal equations:" << endl;
        cout << "Σ(w_i)*a + Σ(w_i*x_i)*b = Σ(w_i*y_i)" << endl;
        cout << "Σ(w_i*x_i)*a + Σ(w_i*x_i²)*b = Σ(w_i*x_i*y_i)" << endl << endl;
        
        cout << "Calculated sums:" << endl;
        cout << "Σ w_i = " << sum_w << endl;
        cout << "Σ w_i*x_i = " << sum_wx << endl;
        cout << "Σ w_i*y_i = " << sum_wy << endl;
        cout << "Σ w_i*x_i² = " << sum_wx2 << endl;
        cout << "Σ w_i*x_i*y_i = " << sum_wxy << endl << endl;
        
        // Solve normal equations using Cramer's rule
        double det = sum_w * sum_wx2 - sum_wx * sum_wx;
        
        if (abs(det) < 1e-12) {
            cout << "Singular matrix! Cannot solve." << endl;
            return {0, 0};
        }
        
        double a = (sum_wy * sum_wx2 - sum_wx * sum_wxy) / det;
        double b = (sum_w * sum_wxy - sum_wx * sum_wy) / det;
        
        cout << "Normal equations in matrix form:" << endl;
        cout << "[" << sum_w << "  " << sum_wx << "] [a]   [" << sum_wy << "]" << endl;
        cout << "[" << sum_wx << "  " << sum_wx2 << "] [b] = [" << sum_wxy << "]" << endl << endl;
        
        cout << "Determinant = " << det << endl;
        cout << "Solution using Cramer's rule:" << endl;
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        
        return {a, b};
    }
    
    void evaluateFit(double a, double b) {
        cout << "\n=== FIT EVALUATION ===" << endl;
        cout << "Fitted line: y = " << a << " + " << b << "x" << endl << endl;
        
        cout << setw(5) << "i" << setw(8) << "x_i" << setw(8) << "y_i" << setw(8) << "ŷ_i" 
             << setw(10) << "residual" << setw(12) << "w_residual²" << endl;
        cout << string(60, '-') << endl;
        
        double total_weighted_error = 0;
        
        for (int i = 0; i < data.size(); i++) {
            double y_pred = a + b * data[i].x;
            double residual = data[i].y - y_pred;
            double weighted_sq_error = data[i].w * residual * residual;
            total_weighted_error += weighted_sq_error;
            
            cout << setw(5) << i+1 << setw(8) << fixed << setprecision(3) << data[i].x 
                 << setw(8) << data[i].y << setw(8) << y_pred 
                 << setw(10) << residual << setw(12) << weighted_sq_error << endl;
        }
        
        cout << "\nTotal weighted sum of squared errors: " << total_weighted_error << endl;
    }
};

int main() {
    WeightedLeastSquares wls;
    
    // Sample data with different weights
    // Higher weight means more reliable data
    wls.addDataPoint(1.0, 2.1, 1.0);
    wls.addDataPoint(2.0, 3.9, 2.0);  // More reliable
    wls.addDataPoint(3.0, 6.2, 1.5);
    wls.addDataPoint(4.0, 8.0, 3.0);  // Most reliable
    wls.addDataPoint(5.0, 9.8, 1.0);
    
    auto [a, b] = wls.fit();
    wls.evaluateFit(a, b);
    
    cout << "\n=== COMPARISON WITH ORDINARY LEAST SQUARES ===" << endl;
    cout << "Weighted least squares gives more importance to points with higher weights." << endl;
    cout << "This is useful when some measurements are more reliable than others." << endl;
    cout << "Points with higher weights have more influence on the fitted line." << endl;
    
    return 0;
}