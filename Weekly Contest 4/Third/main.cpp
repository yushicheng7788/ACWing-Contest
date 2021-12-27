/*
 * @Author: ysc
 * @Date: 2021-12-27 21:05:31
 * @LastEditTime: 2021-12-27 21:05:32
 * @Description: file content
 */
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX_N = 200010;

int h[MAX_N], e[MAX_N], ne[MAX_N], idx;
int pos[MAX_N], in_edge[MAX_N];
int q[MAX_N];

int n, m, k;

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

struct Edge {
    int a, b;
} edge[MAX_N];

bool topsort()
{
    int hh = 0, tt = -1;

    // d[i] 存储点i的入度
    for (int i = 1; i <= n; i ++ )
        if (!in_edge[i])
            q[ ++ tt] = i;

    while (hh <= tt)
    {
        int t = q[hh ++ ];

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (-- in_edge[j] == 0)
                q[ ++ tt] = j;
        }
    }
    
    return tt == n - 1;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T -- )
    {
        scanf("%d%d", &n, &m);
        memset(h, -1, (n + 1) * 4);
        memset(in_edge, 0, (n + 1) * 4);
        idx = k = 0;
        while (m -- )
        {
            int t, a, b;
            scanf("%d%d%d", &t, &a, &b);
            if (!t) edge[k ++ ] = {a, b};
            else
            {
                add(a, b);
                in_edge[b] ++ ;
            }
        }
        if (!topsort()) puts("NO");
        else
        {
            puts("YES");
            for (int i = 1; i <= n; i ++ )
                for (int j = h[i]; ~j; j = ne[j])
                    printf("%d %d\n", i, e[j]);

            for (int i = 0; i < n; i ++ ) pos[q[i]] = i;
            for (int i = 0; i < k; i ++ )
            {
                int a = edge[i].a, b = edge[i].b;
                if (pos[a] > pos[b]) swap(a, b);
                printf("%d %d\n", a, b);
            }
        }
    }
    return 0;
}