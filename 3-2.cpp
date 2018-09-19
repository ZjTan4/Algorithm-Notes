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