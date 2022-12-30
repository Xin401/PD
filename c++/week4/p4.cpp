#include <iostream>
using namespace std;

int find_number(int a, int b)
{
    int sum = 0;
    int grade[a];
    for (int i = 0; i < a; i++)
    {
        cin >> grade[i];
    }
    for (int i = 0; i < a; i++)
    {
        if (grade[i] >= b)
        {
            sum++;
        }
    }
    return sum;
}
int main()
{
    int a = 0, b = 0;
    cin >> a >> b;
    cout << find_number(a, b);
}