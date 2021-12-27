/*
 * @Author: ysc
 * @Date: 2021-12-20 15:14:25
 * @LastEditTime: 2021-12-20 15:16:27
 * @Description: file content
 */
#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    int a[2];
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        if (c == 'A')
            ++a[0];
        else
            ++a[1];
    }
    if (a[0] == a[1])
        puts("T");
    else if (a[0] > a[1])
        puts("A");
    else
        puts("B");
    return 0;
}