/*
True Random vs Pseudo-Random Numbers
True Random Numbers:

Generated from unpredictable physical processes (radioactive decay, thermal noise, atmospheric noise)
Truly unpredictable and non-reproducible
Examples: Random.org uses atmospheric noise, hardware random number generators use quantum effects

Pseudo-Random Numbers:

Generated using deterministic algorithms with a seed value
Appear random but are actually deterministic and reproducible
Examples: Linear Congruential Generator (LCG), Mersenne Twister
Formula example (LCG): X_(n+1) = (aX_n + c) mod m

Monte Carlo Integration for π
Monte Carlo method estimates π by randomly sampling points in a unit square and counting how many fall inside a quarter circle.
Theory:

Area of quarter circle = π/4
Area of unit square = 1
Ratio = (points inside circle)/(total points) ≈ π/4
Therefore: π ≈ 4 × (points inside circle)/(total points)
*/

#include <iostream>
#include <random>
#include <cmath>
using namespace std;

double estimatePi(int numSamples, double stepSize) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(0.0, 1.0);
    
    int pointsInsideCircle = 0;
    
    for (int i = 0; i < numSamples; i++) {
        double x = dis(gen);
        double y = dis(gen);
        
        // Check if point is inside unit circle
        if (x*x + y*y <= 1.0) {
            pointsInsideCircle++;
        }
    }
    
    return 4.0 * pointsInsideCircle / numSamples;
}

int main() {
    double h = 0.1;  // step size
    int numSamples = static_cast<int>(1.0 / (h * h));  // samples based on step size
    
    cout << "Step size h = " << h << endl;
    cout << "Number of samples = " << numSamples << endl;
    
    double piEstimate = estimatePi(numSamples, h);
    cout << "Estimated value of π = " << piEstimate << endl;
    cout << "Actual value of π = " << M_PI << endl;
    cout << "Error = " << abs(piEstimate - M_PI) << endl;
    
    return 0;
}