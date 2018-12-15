#include<iostream>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    int count = 0;
    int prev_barrier = 0, current = 0;
    for (int i = 0; i < n; i++)
    {

        int barrierx,upper,down;
        cin >> barrierx >> down >> upper;
        int can = false;
        int first;

        for (int j = down + 1;j < upper; j++)//find the first reachable point
        {
            if ((j - barrierx)%2==0)
            {
                can = true;
                first = j;
                break;
            }
        }

        if(current > upper - 1 + barrierx - prev_barrier||current < down + 1 - barrierx +prev_barrier||!can)//judge if it's reachable
        {
            cout << "GG" << endl;
            return 0;
        }
        int temp = ceil(float(barrierx - prev_barrier + first - current) / 2);//calculate the number of taps
        count += temp;

        current = current - barrierx + prev_barrier + 2 * temp;//refresh
        prev_barrier = barrierx;
    }
    cout << count << endl;
}
