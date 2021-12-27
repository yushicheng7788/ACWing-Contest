#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 1e5 + 10;

int q[MAX_N];

int T;
int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> T;
    
    while (T --) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; ++i)
            cin >> q[i];
        int res = n;
        for (int i = 1; i <= 100; ++i) {
            int s = 0;
            for (int j = 0; j < n; ++j) {
                if (q[j] != i) {
                    ++s;
                    j += k - 1;
                }
            }
            res = min(res, s);
        }
        printf("%d\n", res);
    }
    return 0;
}