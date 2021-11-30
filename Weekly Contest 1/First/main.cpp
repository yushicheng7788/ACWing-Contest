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