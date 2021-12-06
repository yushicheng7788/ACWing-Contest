#include <iostream>
using namespace std;

int T;

void solve(int n) {
    for (int i = 0; i * 3 <= n; ++i) {
        for (int j = 0; j * 5 <= n; ++j) {
            for (int k = 0; k * 7 <= n; ++k) {
                if (i * 3 + j * 5 + k * 7 == n) {
                    cout << i << " " << j << " " << k << endl;
                    return;
                }
            }
        }
    }
    cout << "-1" << endl;
    return;
}

int main() {
    cin >> T;
    while (T --) {
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}