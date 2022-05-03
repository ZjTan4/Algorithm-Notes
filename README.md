﻿﻿
﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿# CppNote
### Below are the list of problems that the algorithm in this repo solved
**3-2 最小公倍数(2018/9/19(We-3))**
我们都会求两个数的最小公倍数，现在的问题和多个数的最小公倍数有关。a和b都是正整数(a<b),用lcm(a,…,b)代表[a,b]区间内的所有数字的最小公倍数，输入一个正整数N，求最小的M(M>N)，满足： lcm(1,…,M)=lcm(N+1,…,M)。
Input
输入只有一个数字N(2<=N<=100000)。
Output
输出满足条件的最小M。
```
Example
Input
    3
Output
    6
```
Explanation
    lcm(1,2,3,4,5,6) = lcm(4,5,6) = 60.



**3-3 Jump Game(2018/9/19(We-3))**
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.
```
Input
First line contains a single integer N(1<=N<=100 0000), 
which is the length of array. Second line contains N integers, splited by spaces.
Output
If the last index is reacheable, print string "yes\n", else print "no\n".
Example
Input
    5
    2 3 1 1 4
output
    yes
```
Explanation
    Jump 1 step from index 0 to 1, then 3 steps to the last index.



**LeetCode 654(2018/9/20(Th-3))**
 Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:
    The root is the maximum number in the array.
    The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
    The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
Construct the maximum tree by the given array and output the root node of this tree.

```
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
```

Note:The size of the given array will be in the range [1,1000].



**807. Max Increase to Keep City Skyline(unsolved)(2018/9/20(Th-3))**
In a 2 dimensional array grid, each value grid[i][j] represents the height of a building located there. We are allowed to increase the height of any number of buildings, by any amount (the amounts can be different for different buildings). Height 0 is considered to be a building as well.
At the end, the "skyline" when viewed from all four directions of the grid, i.e. top, bottom, left, and right, must be the same as the skyline of the original grid. A city's skyline is the outer contour of the rectangles formed by all the buildings when viewed from a distance. See the following example.
What is the maximum total sum that the height of the buildings can be increased?
```
Example:
Input: grid = [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]
Output: 35
Explanation:
The grid is:
[ [3, 0, 8, 4],
[2, 4, 5, 7],
[9, 2, 6, 3],
[0, 3, 1, 0] ]

The skyline viewed from top or bottom is: [9, 4, 8, 7]
The skyline viewed from left or right is: [8, 7, 9, 3]

The grid after increasing the height of buildings without affecting skylines is:

gridNew = [ [8, 4, 8, 7],
[7, 4, 7, 7],
[9, 4, 8, 7],
[3, 3, 3, 3] ]
```

Notes:
1 < grid.length = grid[0].length <= 50.
All heights grid[i][j] are in the range [0, 100].
All buildings in grid[i][j] occupy the entire grid cell: that is, they are a 1 x 1 x grid[i][j] rectangular prism.



**814. Binary Tree Pruning(2018/9/26(Th-4))**
We are given the head node root of a binary tree, where additionally every node's value is either a 0 or a 1.
Return the same tree where every subtree (of the given tree) not containing a 1 has been removed.
(Recall that the subtree of a node X is X, plus every node that is a descendant of X.)

```
Example 1:
Input: [1,null,0,0,1]
Output: [1,null,0,null,1]

Explanation:
Only the red nodes satisfy the property "every subtree not containing a 1".
The diagram on the right represents the answer.

Example 2:
Input: [1,0,1,0,0,0,1]
Output: [1,null,1,null,1]

Example 3:
Input: [1,1,0,1,1,0,1,0]
Output: [1,1,0,1,1,null,1]
```

Note:

The binary tree will have at most 100 nodes.
The value of each node will only be 0 or 1.



**1-2 链表的反转(2018/9/22(Sa-3))**
下面所给的是链表节点的结构，你的任务是写一个函数将链表反转。
  
```
  struct ListNode {
        int val;
        ListNode *next;
        ListNode(){
            val=0;
            next=NULL;
        }
        ListNode(int x) : val(x), next(NULL) {}
        ~ListNode(){}
    };
```



**4-4 Unique Path**
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach 
the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?

![robot_maze](https://leetcode.com/static/images/problemset/robot_maze.png)

Above is a 7 x 3 grid. How many possible unique paths are there?
Note: m and n will be at most 100.

Input

A single line, m and n sperated by space.

Output

The number of all possible paths.



**4-1 Word Ladder(2018/09/28(Fri-4))**
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

    Only one letter can be changed at a time.
    Each transformed word must exist in the word list. Note that beginWord is not a transformed word.

Note:

```
    Return 0 if there is no such transformation sequence.
    All words have the same length.
    All words contain only lowercase alphabetic characters.
    You may assume no duplicates in the word list.
    You may assume beginWord and endWord are non-empty and are not the same.
    You may assume endWord is a transformed word.
```

输入

第一行，字符串beginWord。 第二行，字符串endWord。 第三行，word list中的word个数N(1=<N<=50)。 后面N行为N个word list中的word。 (beginWord, endWord和word list中word的长度l的范围为3<=l<=5)
输出shortest transformation sequence 的长度，如果不存在则输出0。
```
Example

Input:

    hit
    cog
    6
    hot
    dot
    dog
    lot
    log
    cog

Output:

    5

Explanation:
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog", return its length 5.
```


**4-2 Intersection of two linked list(2018/9/28(Fri-4))**
Write a program to find the node at which the intersection of two singly linked lists begins.

```
For example, the following two linked lists:

A: a1 → a2 →c1 → c2 → c3
B: b1 → b2 → b3→c1 → c2 → c3

begin to intersect at node c1.
```

Notes:
```
If the two linked lists have no intersection at all, return null. The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure. Your code should preferably run in O(n) time and use only O(1) memory.
```
链表结构体定义在linkNode.h中，你只需要实现函数getIntersectionNode，
该函数的声明如下，参数为两个链表的头指针，返回值为相交处的第一个节点指针。
linkNode *getIntersectionNode(linkNode *headA, linkNode *headB);



**4-3 Jump Game 2 (2018/09/29(Sun-4))**
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.

```
Input
First line contains a single integer N(1<=N<=100 0000), 
which is the length of array. Second line contains N integers, splited by spaces.

Output
If the last index is reacheable, 
print the minimum number of jumps to reach the last index, else print -1.
```

Example

```
Input
    5
    2 3 1 1 4
output
    2
```

Explanation
```
 The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
```




