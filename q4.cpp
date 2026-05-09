#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        int a[100000];

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a, a + n, greater<int>());

        long long alex = 0;
        long long bob = 0;

        set<int> alexUsed;
        set<int> bobUsed;

        bool turn = true;

        for (int i = 0; i < n; i++) {

            if (turn == true) {

                if (alexUsed.count(a[i]) == 0) {
                    alex += a[i];
                    alexUsed.insert(a[i]);
                    turn = false;
                }
            }
            else {

                if (bobUsed.count(a[i]) == 0) {
                    bob += a[i];
                    bobUsed.insert(a[i]);
                    turn = true;
                }
            }
        }

        if (alex > bob)
            cout << "Alex" << endl;
        else
            cout << "Bob" << endl;
    }

    return 0;
}
