#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using LL = long long;

const int MAX_N = 100010;

vector<int> alls;
int n;
int q[MAX_N];
LL tr[MAX_N];
LL f[MAX_N];

int lowbit(int x) {
    return x & -x;
}

void add(int x, LL k) {
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] = max(tr[i], k);
}

LL query(int k) {
    LL res = 0;
    for (int i = k; i > 0; i -= lowbit(i))
        res = max(res, tr[i]);
    return res;
}

int find(int x) {
    int left = 0, right = alls.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (alls[mid] == x)
            return mid;
        else if (alls[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> q[i];
        alls.push_back(q[i]);
    }
    
    // 离散化
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    
    LL res = 0;
    for (int i = 0; i < n; ++i) {
        int k = find(q[i]);
        f[i] = query(k - 1) + q[i];
        res = max(res, f[i]);
        add(k, f[i]);
    }
    printf("%lld\n", res);
    return 0;
}