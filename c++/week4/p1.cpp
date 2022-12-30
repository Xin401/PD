#include <iostream>
using namespace std;

int find_min(int a, int b)
{
    if (a > b)
    {
        return b;
    }
    else 
    {
        return a;
    }
}
int main()
{
    int a = 0, b = 0;
    cin >> a >> b;
    cout << find_min(a,b);
}
