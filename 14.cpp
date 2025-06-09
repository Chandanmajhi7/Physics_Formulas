/*
Buffon's Needle Problem
Theory
Buffon's Needle Problem is a classic geometric probability problem used to estimate π.
Setup:

Parallel lines separated by distance d
Needle of length l (where l ≤ d)
Needle dropped randomly onto the ruled surface

Mathematical Derivation:

Let θ be the angle between needle and lines (0 ≤ θ ≤ π/2)
Let x be the distance from needle's center to nearest line (0 ≤ x ≤ d/2)
Needle crosses a line if: x ≤ (l/2)sin(θ)

Probability Calculation:
P(crossing) = ∫₀^(π/2) ∫₀^((l/2)sin(θ)) (2/d) · (2/π) dx dθ
= (4/πd) ∫₀^(π/2) (l/2)sin(θ) dθ
= (2l/πd) [-cos(θ)]₀^(π/2)
= (2l/πd) [0 - (-1)]
= 2l/(πd)
Therefore: π = 2l/(P(crossing) × d)
For l = d: π = 2/P(crossing)
*/

#include <iostream>
#include <random>
#include <cmath>
#include <iomanip>
using namespace std;

double buffonsNeedle(int numTrials, double needleLength, double lineSpacing) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> angleDist(0.0, M_PI);
    uniform_real_distribution<double> positionDist(0.0, lineSpacing/2);
    
    int crossings = 0;
    
    for (int i = 0; i < numTrials; i++) {
        double angle = angleDist(gen);
        double position = positionDist(gen);
        
        // Check if needle crosses a line
        if (position <= (needleLength/2) * sin(angle)) {
            crossings++;
        }
    }
    
    double probability = static_cast<double>(crossings) / numTrials;
    return (2 * needleLength) / (probability * lineSpacing);
}

int main() {
    double l = 1.0;  // needle length
    double d = 1.0;  // line spacing (l ≤ d)
    
    cout << fixed << setprecision(6);
    cout << "Buffon's Needle Problem - Estimating π" << endl;
    cout << "Needle length: " << l << endl;
    cout << "Line spacing: " << d << endl << endl;
    
    vector<int> trials = {1000, 10000, 100000, 1000000};
    
    for (int numTrials : trials) {
        double piEstimate = buffonsNeedle(numTrials, l, d);
        double error = abs(piEstimate - M_PI);
        
        cout << "Trials: " << setw(8) << numTrials 
             << " | π estimate: " << setw(8) << piEstimate 
             << " | Error: " << setw(8) << error << endl;
    }
    
    cout << "\nActual π = " << M_PI << endl;
    
    return 0;
}