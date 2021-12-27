# 3662. 最大上升子序列和
给定一个长度为 $n$ 的整数序列 $a_1,a_2,…,a_n$。

请你选出一个该序列的严格上升子序列，要求所选子序列的各元素之和尽可能大。

请问这个最大值是多少？

# 输入格式
第一行包含整数 $n$。

第二行包含 $n$ 个整数 $a_1,a_2,…,a_n$。

# 输出格式
输出最大的上升子序列和。

# 数据范围
对于前三个测试点，$1≤n≤4$。

对于全部测试点，$1≤n≤10^{5},1≤ai≤10^{9}$。

# Solution
最长上升子序列问题是经典的动态规划问题。一种比较容易想到的方法是令 $dp[i]$ 表示以 $arr[i]$ 结尾的最大上升子序列和。

那么 $dp[i] = max(dp[j]), 0 <= j <= i - 1 \cap arr[j] < arr[i]$。这种做法的时间复杂度为 $O(n^2)$，因此本题会超时。

一般地，动态规划有两种优化手段。一种是类似背包问题，从状态转移方程出发；另一种是利用数据结构进行优化。

本题可以使用树状数组进行优化，使用树状数组维护前缀最大值。本题数据范围较大，还需要进行离散化。