/*
a) Compute the factorial of a number
*/

// C++ Factorial Implementation
#include <iostream>
using namespace std;

// Iterative approach
long long factorialIterative(int n) {
    if (n < 0) return -1; // Error case
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Recursive approach
long long factorialRecursive(int n) {
    if (n < 0) return -1; // Error case
    if (n == 0 || n == 1) return 1;
    return n * factorialRecursive(n - 1);
}

int main() {
    int number;
    cout << "Enter a number to find its factorial: ";
    cin >> number;
    
    if (number < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
    } else {
        cout << "Factorial of " << number << " (iterative): " << factorialIterative(number) << endl;
        cout << "Factorial of " << number << " (recursive): " << factorialRecursive(number) << endl;
    }
    
    return 0;
}

/*
b) Roots of a Quadratic Equation
*/

// C++ Quadratic Roots
#include <iostream>
#include <cmath>
#include <complex>
using namespace std;

void solveQuadratic(double a, double b, double c) {
    if (a == 0) {
        if (b == 0) {
            cout << "Invalid equation (both a and b are zero)." << endl;
        } else {
            double root = -c / b;
            cout << "Linear equation root: x = " << root << endl;
        }
        return;
    }
    
    double discriminant = b * b - 4 * a * c;
    cout << "Discriminant = " << discriminant << endl;
    
    if (discriminant > 0) {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Two real and distinct roots:" << endl;
        cout << "Root 1 = " << root1 << endl;
        cout << "Root 2 = " << root2 << endl;
    } else if (discriminant == 0) {
        double root = -b / (2 * a);
        cout << "One real root (repeated): x = " << root << endl;
    } else {
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        cout << "Two complex roots:" << endl;
        cout << "Root 1 = " << realPart << " + " << imaginaryPart << "i" << endl;
        cout << "Root 2 = " << realPart << " - " << imaginaryPart << "i" << endl;
    }
}

int main() {
    double a, b, c;
    cout << "Enter coefficients a, b, c for ax² + bx + c = 0:" << endl;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "c = "; cin >> c;
    
    cout << "Equation: " << a << "x² + " << b << "x + " << c << " = 0" << endl;
    solveQuadratic(a, b, c);
    
    return 0;
}

/*
c) Sum and Average of Numbers
*/

// C++ Sum and Average
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of values: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Number of values must be positive." << endl;
        return 1;
    }
    
    vector<double> numbers(n);
    double sum = 0;
    
    cout << "Enter " << n << " numbers:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Number " << (i + 1) << ": ";
        cin >> numbers[i];
        sum += numbers[i];
    }
    
    double average = sum / n;
    
    cout << fixed << setprecision(2);
    cout << "\nResults:" << endl;
    cout << "Numbers entered: ";
    for (int i = 0; i < n; i++) {
        cout << numbers[i];
        if (i < n - 1) cout << ", ";
    }
    cout << endl;
    cout << "Sum = " << sum << endl;
    cout << "Average = " << average << endl;
    
    return 0;
}

/*
d) Largest of Three Numbers
*/

// C++ Largest of Three Numbers
#include <iostream>
#include <algorithm>
using namespace std;

// Method 1: Using if-else
double findLargestIfElse(double a, double b, double c) {
    if (a >= b && a >= c) {
        return a;
    } else if (b >= a && b >= c) {
        return b;
    } else {
        return c;
    }
}

// Method 2: Using ternary operator
double findLargestTernary(double a, double b, double c) {
    return (a >= b) ? ((a >= c) ? a : c) : ((b >= c) ? b : c);
}

// Method 3: Using STL max function
double findLargestSTL(double a, double b, double c) {
    return max({a, b, c});
}

int main() {
    double num1, num2, num3;
    
    cout << "Enter three numbers:" << endl;
    cout << "First number: "; cin >> num1;
    cout << "Second number: "; cin >> num2;
    cout << "Third number: "; cin >> num3;
    
    cout << "\nUsing different methods:" << endl;
    cout << "Largest (if-else): " << findLargestIfElse(num1, num2, num3) << endl;
    cout << "Largest (ternary): " << findLargestTernary(num1, num2, num3) << endl;
    cout << "Largest (STL max): " << findLargestSTL(num1, num2, num3) << endl;
    
    return 0;
}

/*
e) Arrange a List of Numbers in Ascending and Descending Order
*/

// C++ Sorting Numbers
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void displayVector(const vector<int>& vec, const string& title) {
    cout << title << ": ";
    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Number of elements must be positive." << endl;
        return 1;
    }
    
    vector<int> numbers(n);
    cout << "Enter " << n << " numbers:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Number " << (i + 1) << ": ";
        cin >> numbers[i];
    }
    
    // Display original array
    displayVector(numbers, "Original array");
    
    // Sort in ascending order
    vector<int> ascending = numbers;
    sort(ascending.begin(), ascending.end());
    displayVector(ascending, "Ascending order");
    
    // Sort in descending order
    vector<int> descending = numbers;
    sort(descending.begin(), descending.end(), greater<int>());
    displayVector(descending, "Descending order");
    
    // Manual bubble sort implementation for educational purposes
    vector<int> bubbleSort = numbers;
    int size = bubbleSort.size();
    
    cout << "\nBubble Sort Process (Ascending):" << endl;
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (bubbleSort[j] > bubbleSort[j + 1]) {
                swap(bubbleSort[j], bubbleSort[j + 1]);
                swapped = true;
            }
        }
        cout << "Pass " << (i + 1) << ": ";
        for (int k = 0; k < size; k++) {
            cout << bubbleSort[k] << " ";
        }
        cout << endl;
        
        if (!swapped) break; // Early termination if already sorted
    }
    
    return 0;
}