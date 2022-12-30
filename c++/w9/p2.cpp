#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

int main()
{
    char a[1000] = {0};
    char c;
    cin.getline(a, 1000);
    a[0] = toupper(a[0]);
    for (int i = 1; i < strlen(a); i++)
    {
        if (a[i - 1] == ' ')
        {
            a[i] = toupper(a[i]);
        }
        else
        {
            a[i] = tolower(a[i]);
        }
    }
    cout << a;
}