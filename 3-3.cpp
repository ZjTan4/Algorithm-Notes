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