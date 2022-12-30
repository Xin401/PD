#include <iostream>
using namespace std;

int find_common(int a, int b)
{
    int common = 0, max = 0;
    if (a >= b)
    {
        max = a;
    }
    else
    {
        max = b;
    }
    for (int i = 1; i <= max; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            common = i;
        }
    }
    return common;
}
int main()
{
    int a = 0, b = 0;
    cin >> a >> b;
    cout << find_common(a, b);
}