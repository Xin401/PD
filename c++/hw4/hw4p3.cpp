#include <iostream>
using namespace std;

int seatCheck(int seat[16][16], int s, int t, int n);
int checkIfChange(int seat[16][16], int s, int t, int n);
void buySeat(int seat[16][16], int s, int t, int num, int n, int m);

int main()
{
    int n = 0, m = 0, k = 0;
    cin >> n >> m >> k;
    int seat[16][16] = {0};
    int s = 0, t = 0, num = 0;
    for (int i = 0; i < k; i++)
    {
        num++;
        cin >> s >> t;
        if (t <= s)
        {
            continue;
        }
        if (seatCheck(seat, s, t, n))
        {
            buySeat(seat, s, t, num, n , m);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << seat[1][i];
        for (int j = 2; j <= m; j++)
        {
            cout << "," << seat[j][i];
        }
        cout << endl;
    }
}

int seatCheck(int seat[16][16], int s, int t, int n)
{
    for (int j = s + 1; j <= t; j++)
    {
        if (seat[j][0] >= n)
        {
            return 0;
        }
    }
    for (int j = s + 1; j <= t; j++)
    {
        seat[j][0]++;
    }
    return 1;
}
int checkIfChange(int seat[16][16], int s, int t, int n)
{
    for (int i = 1; i <= n; i++)
    {
        int a= t-s;
        for (int j = s + 1; j <= t; j++)
        {
            if (seat[j][i] != 0)
            {
                break;
            }
            else
            {
                a-=1;
            }
        }
        if(a==0)
        {
            return i;
        }
    }
    return 0;
}
void buySeat(int seat[16][16], int s, int t, int num, int n , int m)
{
    int seat_num = 0;
    seat_num = checkIfChange(seat, s, t, n);
    if (seat_num != 0)
    {
        for (int i = s + 1; i <= t; i++)
        {
            seat[i][seat_num] = num;
        }
    }
    else
    {
        for (int j = s + 1; j <= t; j++)
        {
            for (int i = 1; i <= n; i++)
            {
                if(seat[j][i]==0)
                {
                    seat[j][i]=num;
                    break;
                }
            }
        }
    }
}