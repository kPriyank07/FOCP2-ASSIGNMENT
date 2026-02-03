#include <iostream>
using namespace std;

int main() {
    int n; float s;
    cin >> n;
    while(n--) {
        cin >> s;
        cout << "Bonus: " << s*0.12 
             << " Net Salary: " << s*1.12 << endl;
    }
}
