#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cout << "Enter three sides of triangle: ";
    cin >> a >> b >> c;

    if (a + b <= c || a + c <= b || b + c <= a) {
        cout << "Not a valid triangle";
    }
    else {
        if (a == b && b == c)
            cout << "Equilateral triangle";
        else if (a == b || b == c || a == c)
            cout << "Isosceles triangle";
        else
            cout << "Scalene triangle";
    }

    return 0;
}
