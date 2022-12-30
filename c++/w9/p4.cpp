#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

int main()
{
    char a[50], b[50];
    int num = 0, flag = 1;
    cin >> num;
    cin >> a;
    for (int i = 0; i < strlen(a); i++)
    {
        a[i] = tolower(a[i]);
    }
    for(int i =0;i<num;i++)
    {
        flag = 1;
        cin >> b;
        for (int i = 0; i < strlen(b); i++)
        {
            b[i] = tolower(b[i]);
        }
        for (int i = 0; i < strlen(a); i++)
        {
            if (a[i] != b[i])
            {
                flag = 0;
                break;
            }
        }
        if(strlen(a)<strlen(b))
        {
            flag = 0;
        }
        if (flag == 1)
        {
            break;
        }
    }
    flag == 1 ? cout << 1 : cout << 0;
}