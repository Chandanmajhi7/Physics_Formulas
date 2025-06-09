/*
| **Data Type** | **Description**                                | **Example**           |
| ------------- | ---------------------------------------------- | --------------------- |
| `int`         | Stores integer values (whole numbers)          | `int age = 25;`       |
| `float`       | Stores single-precision decimal values         | `float pi = 3.14f;`   |
| `double`      | Stores double-precision decimal values         | `double g = 9.80665;` |
| `char`        | Stores a single character (enclosed in quotes) | `char grade = 'A';`   |

*/
// Example in C++:
#include <iostream>
using namespace std;

int main() {
    int age = 20;
    float height = 5.9f;
    double pi = 3.1415926535;
    char grade = 'A';

    cout << "Age: " << age << endl;
    cout << "Height: " << height << endl;
    cout << "Pi: " << pi << endl;
    cout << "Grade: " << grade << endl;

    return 0;
}

/*
User-Defined Function in C++: A user-defined function is a block of code created by the programmer to perform a specific task. It improves code reusability, readability, and modularity.
Example: Function to Add Two Numbers:
*/

#include <iostream>
using namespace std;

// User-defined function
int add(int a, int b) {
    return a + b;
}

int main() {
    int result = add(5, 3);
    cout << "Sum = " << result << endl;
    return 0;
}
