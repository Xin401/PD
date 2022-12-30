#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

int main()
{
    char a[1000] = {0};
    char b[1000] = {0};
    cin.getline(a, 1000);
    cin.getline(b, 1000);
    int flag = 1;
    for (int i = 0; i < strlen(a); i++)
    {
        a[i] = tolower(a[i]);
    }
    for (int i = 0;i<strlen(b);i++)
    {
        b[i] = tolower(b[i]);
    }
    for (int i = 0; i <= strlen(a) - strlen(b); i++)
    {
        flag = 1;
        for (int j = 0; j < strlen(b); j++)
        {
            if (a[i + j] != b[j])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            break;
        }
    }
    if (flag == 1)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
}