#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int ans = n;

    for (int l = 1; l <= n; l++) {

        int count = 0;

        for (int i = 0; i < n; i++) {

            if (s[i] == '1') {
                count++;
                i = i + l - 1;
            }
        }

        if (count <= k) {
            ans = l;
            break;
        }
    }

    cout << ans;

    return 0;
}
