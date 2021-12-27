#include <iostream>
using namespace std;
using LL = long long;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m, r, c;
        cin >> n >> m >> r >> c;
        LL res = 0;
        res = max(max(r - 1 + c - 1, r + (m - c - 1)), max(n - r + c - 1, n - r + m - c));
        cout << res << endl;
    }
    return 0;
}