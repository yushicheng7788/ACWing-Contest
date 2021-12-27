/*
 * @Author: ysc
 * @Date: 2021-12-27 14:52:01
 * @LastEditTime: 2021-12-27 14:54:17
 * @Description: 3695. 扩充序列
 */
#include <iostream>
using namespace std;
using LL = long long;

LL dfs(int n, LL k) {
    if (k == (1LL << n - 1))
        return n;
    else if (k < (1LL << n - 1))
        return dfs(n-1, k);
    else
        return dfs(n-1, k - (1LL << n - 1));
}

int main() {
    int n;
    LL k;
    cin >> n >> k;
    cout << dfs(n, k) << endl;
    return 0;
}