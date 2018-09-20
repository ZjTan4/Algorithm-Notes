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

LeetCode 654(2018/9/20(Th-3))
 Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:
    The root is the maximum number in the array.
    The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
    The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
Construct the maximum tree by the given array and output the root node of this tree.

Example 1:
Input: [3,2,1,6,0,5]
Output: return the tree root node representing the following tree:

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1

Note:The size of the given array will be in the range [1,1000].

