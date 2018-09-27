/*
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
*/
#include<iostream>
using namespace std;
bool isEnd(int *a, int N)
{
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		if (a[i] == 0)count++;
	}
	if (count == N - 1) return true;
	return false;
}
int lcm(int *a,int N)
{
	int m = 1;
	for (int i = 0; i < N; i++)
	{
		m *= a[i];
	}
	for (int i = 0; i < N; i++)
	{
		a[i] = m / a[i];
	}
	int j;
	while (!isEnd(a, N))
	{
		int small;
		for (int i = 0; i < N; i++)
		{
			if (a[i] != 0)
			{
				small = a[i];
				j = i;
				break;
			}
		}
		for (int i = 0; i < N; i++)
		{
			if (small > a[i] && a[i] != 0)
			{
				small = a[i];
				j = i;
			}
		}
		for (int i = 0; i < N; i++)
		{
			if (i == j || a[j] == 0)continue;
			a[i] = a[i] % a[j];
		}
	}
	return m / a[j];
}

int main()
{
	int N;
	cin >> N;
	int *a = new int[N+1];
	int count = 2;
	int *b = new int[count];
	for (int i = 0; i < N + 1; i++)
	{
		a[i] = i + 1;
	}
	for (int i = 0; i < count; i++)
	{
		b[i] = N + i + 1;
	}
	while (lcm(a, N - 1 + count) != lcm(b, count))
	{
		delete[] a;
		delete[] b;
		count++;
		a = new int[N - 1 + count];
		b = new int[count];
		for (int i = 0; i < N - 1 + count; i++)
		{
			a[i] = i + 1;
		}
		for (int i = 0; i < count; i++)
		{
			b[i] = N + i + 1;
		}
	}
	cout << N + count;
	delete[] a;
	delete[] b;
}