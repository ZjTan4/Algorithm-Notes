# CppNote
3-2 最小公倍数(2018/9/19(We-3))
我们都会求两个数的最小公倍数，现在的问题和多个数的最小公倍数有关。a和b都是正整数(a<b),用lcm(a,…,b)代表[a,b]区间内的所有数字的最小公倍数，输入一个正整数N，求最小的M(M>N)，满足： lcm(1,…,M)=lcm(N+1,…,M)。
Input
输入只有一个数字N(2<=N<=100000)。
Output
输出满足条件的最小M。
Example
Input
    3
Output
    6
Explanation
    lcm(1,2,3,4,5,6) = lcm(4,5,6) = 60.

3-3 Jump Game(2018/9/19(We-3))
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.
Input
First line contains a single integer N(1<=N<=100 0000), which is the length of array. Second line contains N integers, splited by spaces.
Output
If the last index is reacheable, print string "yes\n", else print "no\n".
Example
Input
    5
    2 3 1 1 4
output
    yes
Explanation
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
