#include <iostream>
using namespace std;

int highgrades(int a, int b, int c)
{
    int grades[10][50] = {0};
    int sum[10] = {0}, max = 0;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cin >> grades[i][j];
            if (grades[i][j] >= c)
            {
                sum[i]++;
            }
        }
    }
    for (int i = 1; i < a; i++)
    {
        if (sum[max] < sum[i])
        {
            max = i;
        }
    }
    return max + 1;
}

int main()
{
    int a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    cout << highgrades(a, b, c);
}