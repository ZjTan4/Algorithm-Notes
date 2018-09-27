/*
4-4 Unique Path
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach 
the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?

Input

A single line, m and n sperated by space.

Output

The number of all possible paths.
*/
#include<iostream>
using namespace std;
int main()
{
	int m, n;
	cin >> m >> n;
	int a[100][100];
	a[0][0] = 0;
	for (int i = 1; i < m; i++)
	{
		a[i][0] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		a[0][i] = 1;
	}
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			a[i][j] = a[i - 1][j] + a[i][j - 1];
		}
	}
	cout << a[m - 1][n - 1] << endl;
}