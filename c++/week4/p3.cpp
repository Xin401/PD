#include <iostream>
using namespace std;

int find_common(int a, int b, int c)
{
    int common = 0, max = 0;
    for (int i = 1; i <= a; i++)
    {
        if (a % i == 0 && b % i == 0 && c % i == 0)
        {
            common = i;
        }
    }
    return common;
}
int main()
{
    int a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    cout << find_common(a, b, c);
}