#include <iostream>
using namespace std;

int main()
{
    int town[100] = {0}, radius = 0, number = 0, max = 0;
    cin >> number >> radius;
    for (int i = 0; i < number; i++)
    {
        cin >> town[i];
    }
    if (number > radius * 2 + 1)
    {
        for (int i = radius; i < number - radius; i++)
        {
            int a = 0;
            for (int j = i - radius; j <= i + radius; j++)
            {
                a += town[j];
            }
            if (a >= max)
            {
                max = a;
            }
        }
    }
    else
    {
        for (int i = 0; i < number; i++)
        {
            max += town[i];
        }
    }
    cout << max;
}