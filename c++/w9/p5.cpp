#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

int main()
{
    char a[1000], b[4000];
    int time = 0;
    cin.getline(a, 1000);
    for (int i = 0; i < strlen(a); i++)
    {
        b[i + 3 * time] = a[i];
        if (a[i] == '0' && (a[i - 1] < '0' || a[i - 1] > '9') && (a[i + 1] < '0' || a[i + 1] > '9'))
        {
            b[i + 3 * time] = 'z';
            b[i + 1 + 3 * time] = 'e';
            b[i + 2 + 3 * time] = 'r';
            b[i + 3 + 3 * time] = 'o';
            time++;
        }
    }
    cout << b;
}