#include <iostream>
using namespace std;

int main()
{
    int a = 0, b = 0;
    cin >> a >> b;
    if (a == b && a > 0)
    {
        cout << a + b;
    }
    if (a == b && a <= 0)
    {
        cout << a * b;
    }
    if (a != b)
    {
        cout << a - b;
    }
}