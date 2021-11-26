/*
 * 3578.最大中位数
 * https://www.acwing.com/problem/content/3581/
 * 
 * Solution:
 * 1. greedy
 *    对于小于中位数的数字来说，将其增一不起作用，浪费次数。应该将大于等于中位数的数字增一。这种方法本质上
 *    是填平。因为最小的数字会沦为中位数。
 * 2. binary search
 *    利用二分搜索枚举最大的中位数。
 */
#include <iostream>
#include <algorithm>
using namespace std;
using LL = long long;

int a[200010];
int n, k;

int main1() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    
    LL mid = a[n / 2];
    LL temp = 0;
    int i;
    for (i = n / 2 + 1; i < n; ++i) {
        if (temp + (a[i] - mid) * (i - n / 2) <= k) {
            temp += (a[i] - mid) * (i - n / 2);
            mid = a[i];
        } else {
            break;
        }
    }
    if (k > temp)
        mid += (k - temp) / (i - (n / 2 + 1) + 1);
    cout << mid << endl;
    
    return 0;
}

int main2() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    LL left = 1, right = 2e9;
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

    return 0;
}