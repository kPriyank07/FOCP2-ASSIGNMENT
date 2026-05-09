#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {

        long long n;
        cin >> n;

        int count = 0;

        if (n % 2 == 0) {
            count++;

            while (n % 2 == 0) {
                n = n / 2;
            }
        }

        for (long long i = 3; i * i <= n; i = i + 2) {

            if (n % i == 0) {
                count++;

                while (n % i == 0) {
                    n = n / i;
                }
            }
        }

        if (n > 1) {
            count++;
        }

        long long ans = 1;

        for (int i = 0; i < count; i++) {
            ans = ans * 2;
        }

        cout << ans << "\n";
    }

    return 0;
}
