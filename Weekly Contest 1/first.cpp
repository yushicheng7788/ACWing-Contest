/*
 *  题目大意：
 *  给你两个数组A,B，请你从AB中各挑选出一个数字，这两个数字满足a+b既不出现在A中，也不出现在B中。
 * 
 *  Solution:
 *      可以枚举。更简单的方法应该是从A和B中均取出最大值。两个数字的最大值之和当然不会出现在两个数组中。
 */


#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 110;

int n, m;
int a[MAX_N], b[MAX_N];

int main() {
    int ma1 = 0, ma2 = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ma1 = max(ma1, a[i]);
    }
        
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        ma2 = max(ma2, b[i]);
    }
    
    cout << ma1 << " " << ma2 << endl;

    return 0;
}