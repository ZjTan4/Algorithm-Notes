/*
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

*/
#include<iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;
	int *a = new int[N];
	for (int i = 0; i<N; i++)
	{
		cin >> a[i];
	}
	int rightMost = 1;
	for (int i = 0; i < N; i++) {
		if (rightMost < i + 1) break;
		rightMost = rightMost> i + 1 + a[i] ? rightMost : i + 1 + a[i];
	}
	if (rightMost >= N)cout << "yes" << endl;
	else cout << "no" << endl;
};