# 题目大意
给定一个整数数组A，其包含n个正整数，以及一个整数数组B，其包含m个正整数。
请从数组A中挑选一个元素a并从数组B中挑选一个元素b，使得a+b既不包含于A也不包含于B。

# Solution
可以枚举。更为简便的做法是从两个数组中都挑选出最大值。