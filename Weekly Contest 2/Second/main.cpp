#include <iostream>
#include <algorithm>
using namespace std;
using LL = long long;

const int MAX_N = 200010;

int T;
int q[MAX_N];

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> T;
    while (T --) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; ++i)
            cin >> q[i];
        sort(q, q + n, greater<int>());
        LL res = 0;
        for (int i = 0; i <= k; ++i)
            res += q[i];
        cout << res << endl;
    }
    return 0;
}