/*
Loop Differences and Examples
While Loop
Executes a block of code repeatedly as long as a condition is true. The condition is checked before each iteration.
Syntax:

C++: while (condition) { statements; }
Python: while condition: statements

Do-While Loop (C++ only)
Executes a block of code at least once, then repeats as long as a condition is true. The condition is checked after each iteration.
Syntax: do { statements; } while (condition);
Note: Python doesn't have a built-in do-while loop, but it can be simulated.
For Loop
Used for iterating a specific number of times or over a sequence of values.
Syntax:

C++: for (initialization; condition; increment) { statements; }
Python: for variable in sequence: statements

*/

/*
1. while Loop
*/
#include <iostream>
using namespace std;

int main() {
    int i = 1;
    while (i <= 5) {
        cout << i << " ";
        i++;
    }
    return 0;
}


/*
2. do-while Loop
*/
#include <iostream>
using namespace std;

int main() {
    int i = 1;
    do {
        cout << i << " ";
        i++;
    } while (i <= 5);
    return 0;
}


/*
3. for Loop
*/
#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 5; i++) {
        cout << i << " ";
    }
    return 0;
}
