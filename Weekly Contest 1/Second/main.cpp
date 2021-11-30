#include <iostream>
#include <algorithm>
using namespace std;
using LL = long long;

const int MAX_N = 200010;

int a[MAX_N];
int n, k;

// 贪心，相当于一直填坑
void solve() {
    LL mid = a[n / 2], temp = 0;
    int i;
    for (i = n / 2 + 1; i < n; ++i) {
        if (temp + (i - n / 2) * (a[i] - mid) < k) {
            temp += (i - n / 2) * (a[i] - mid);
        } else 
            break;
    }
    if (temp < k) {
        mid += (k - temp) / (i - (n / 2 + 1) + 1);
    }
    cout << mid << endl;
}

// binary search
void solve2() {
    LL left = 2, right = 2e9;
    while (left <= right) {
        LL mid = left + (right - left) / 2;
        LL need = 0;
        for (int i = n / 2; i < n; ++i)
            need += max(0LL, mid - a[i]);
        if (need <= k)
            left = mid + 1;
        else
            right = mid - 1;
    }
    cout << right << endl;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    sort(a, a + n);

    // solve();
    // solve2();

    return 0;
}