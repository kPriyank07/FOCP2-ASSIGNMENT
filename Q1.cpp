#include <iostream>
using namespace std;

int main() {
    float m1, m2, m3, average;
    cout << "Enter marks of three students: ";
    cin >> m1 >> m2 >> m3;
    average = (m1 + m2 + m3) / 3;
    cout << "Average marks = " << average << endl;

    return 0;
}
