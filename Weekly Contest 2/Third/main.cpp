#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
using LL = long long;
using PII = pair<LL, int>;

const int MAX_N = 100010, MAX_M = 200010;

int h[MAX_N], e[MAX_M], ne[MAX_M], w[MAX_M],id[MAX_M],idx;
bool st[MAX_N];
LL dist[MAX_N];

int n, m, k;
vector<int> ans;

void add(int a, int b, int c, int d) {
    e[idx] = b;
    ne[idx] = h[a];
    id[idx] = d;
    w[idx] = c;
    h[a] = idx++;
}

void dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, 1});
    
    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        
        LL distance = t.first;
        int ver = t.second;
        if (st[ver])
            continue;
        st[ver] = true;
        for (int i = h[ver]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[ver] + w[i]) {
                dist[j] = dist[ver] + w[i];
                pq.push({dist[j], j});
            }
        }
    }
}

void dfs(int u) {
    st[u] = true;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j] && dist[j] == dist[u] + w[i]) {
            if (ans.size() < k)
                ans.push_back(id[i]);
            dfs(j);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m >> k;
    
    memset(h, -1, sizeof(h));
    
    int d = 1;    
    while (m --) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c, d);
        add(b, a, c, d);
        d++;
    }
    
    dijkstra();
    
    memset(st, false, sizeof(st));
    dfs(1);
    printf("%d\n", ans.size());
    for (auto i : ans)
        printf("%d ", i);
    return 0;
}