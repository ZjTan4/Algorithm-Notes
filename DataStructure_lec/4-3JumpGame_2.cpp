/*
4-3 Jump Game 2 (2018/09/29(Sun-4))
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.

Input
First line contains a single integer N(1<=N<=100 0000), which is the length of array. Second line contains N integers, splited by spaces.

Output
If the last index is reacheable, print the minimum number of jumps to reach the last index, else print -1.

Example

Input
    5
    2 3 1 1 4
output
    2

Explanation
    The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

*/
#include<iostream>
using namespace std;
int main()
{
    //the length of the given array
	int N;
	cin >> N;
	int *a = new int[N];
	for (int i = 0; i<N; i++)
	{
		cin >> a[i];
	}

    //used as pointer that points to the current position 
	int ptr = 0;
	int count = 0;
	while (true)
	{
		int temp = a[ptr];
		int temp_1 = ptr;
        int biggest = temp + temp_1;
        //compare the values of a[ptr] + ptr to a[ptr + a[ptr]] + (ptr + a[ptr]), select the largest value to jump to
		for (int i = 1; i <= temp && i + ptr < N; i++)
		{
			if (biggest < a[ptr + i] + ptr + i)
			{
				biggest = a[ptr + i] + ptr + i;
				ptr = ptr + i;
			}
		}
		count++;

		if (a[ptr]+ptr >= N - 1)break;
		
        //if pointer doesn't move in 1 loop, which means a[ptr] == 0, the last index is not reacheable
        if (temp_1 == ptr)
		{
			cout << -1 << endl;
			return 1;
		}
	}
	cout << count + 1 << endl;
}