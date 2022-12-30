#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

int main()
{
    int sum = 0,time = 0;
    char a[1000] = {0};
    cin.getline(a, 1000);
    for (int i = 0; i < 1000; i++)
    {
        if (a[i] == '\0')
        {
            break;
        }
        switch (a[i])
        {
        case ',':
            sum++;
            break;
        case '.':
            sum++;
            break;
        case ':':
            sum++;
            break;
        case ';':
            sum++;
            break;
        case '?':
            sum++;
            break;
        case '!':
            sum++;
            break;
        }
    }
    cout << sum;
}