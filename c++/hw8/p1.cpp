#include <iostream>
#include <cstring>
using namespace std;

const int MAX_LEN = 21;
int countSame(const char target[], const char str[]);
int main()
{
    int n = 0;
    cin >> n;
    cin.ignore();
    char target[MAX_LEN] = {0};
    char **str = new char *[n];
    for (int i = 0; i < n; i++)
    {
        str[i] = new char[MAX_LEN];
    }
    for (int i = 0; i < n; i++)
    {
        cin.getline(str[i], MAX_LEN);
    }
    cin.getline(target, MAX_LEN);
    for (int i = 0; i < n; i++)
    {
        i == 0 ? cout << countSame(target, str[i]) : cout << ',' << countSame(target, str[i]);
    }
    for (int i = 0; i < n; i++)
    {
        delete[] str[i];
    }
    delete[] str;
}

int countSame(const char target[], const char str[])
{
    //level 1
    if (strlen(target) == strlen(str))
    {
        if (strstr(str, target) != nullptr)
        {
            return 10000;
        }
    }
    //level 2 完整包含
    if (strstr(str, target) != nullptr)
    {
        const char *count = strstr(str, target);
        int time = 0;
        while (count != nullptr)
        {
            time++;
            count = strstr(count + 1, target);
        }
        return 1000 + time;
    }
    else
    {
        // i = 長度（遞減）
        for (int i = strlen(target) - 1; i > 0; i--)
        {
            // j = 起始位置（遞增）
            for (int j = 0; j <= strlen(target) - i; j++)
            {
                char *temp = new char[i+1];
                for (int k = 0; k < i; k++)
                {
                    temp[k] = target[j+k];
                }
                temp[i] = '\0';
                if (strstr(str, temp) != nullptr)
                {
                    delete[] temp;
                    return i * 10;
                }
                delete[] temp;
            }
        }
    }
    return 0;
}