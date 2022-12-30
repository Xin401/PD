#include <iostream>
using namespace std;

struct employee
{
    int c;
    int s;
    double cp;
};
int main()
{
    // n:數量   m:幾個配對  b:預算
    int n = 0, m = 0, b = 0;
    cin >> n >> m >> b;
    employee *empInfo = new employee[n];
    // 是否被雇用
    bool *isHired = new bool[n];
    // 被雇用的編號
    int *hireMan = new int[n];
    for (int i = 0; i < n; i++)
    {
        isHired[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        hireMan[i] = -1;
    }
    // 輸入貢獻
    for (int i = 0; i < n; i++)
    {
        cin >> empInfo[i].c;
    }
    // 輸入薪水
    for (int i = 0; i < n; i++)
    {
        cin >> empInfo[i].s;
    }
    for (int i = 0; i < n; i++)
    {
        empInfo[i].cp = static_cast<double>(empInfo[i].c) / static_cast<double>(empInfo[i].s);
    }
    // 輸入結仇
    int **mad = new int *[n];
    for (int i = 0; i < n; i++)
    {
        mad[i] = new int[n - 1];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            mad[i][j] = -1;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int a = 0, b = 0;
        cin >> a >> b;
        for (int j = 0; j < n - 1; j++)
        {
            if (mad[a - 1][j] == -1)
            {
                mad[a - 1][j] = b - 1;
                break;
            }
        }
        for (int j = 0; j < n - 1; j++)
        {
            if (mad[b - 1][j] == -1)
            {
                mad[b - 1][j] = a - 1;
                break;
            }
        }
    }
    // 結仇長度
    int *length = new int[n];
    for (int i = 0; i < n; i++)
    {
        length[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (mad[i][j] != -1)
            {
                length[i]++;
            }
            else
            {
                break;
            }
        }
    }
    int round = 0;
    while (b > 0)
    {
        int max = 0;
        double maxCp = 0;
        for (int i = 0; i < n; i++)
        {
            if (isHired[i] == false)
            {
                if (maxCp < empInfo[i].cp)
                {
                    maxCp = empInfo[i].cp;
                    max = i;
                }
                if (maxCp == empInfo[i].cp)
                {
                    if (length[max] > length[i])
                    {
                        max = i;
                    }
                }
            }
        }
        hireMan[round] = max;
        isHired[max] = true;
        for (int i = 0; i < length[max]; i++)
        {
            isHired[mad[max][i]] = true;
        }
        if (b >= empInfo[max].s)
        {
            b -= empInfo[max].s;
        }
        else
        {
            break;
        }
        round++;
    }
    for (int i = 0; i < round; i++)
    {
        (i != round - 1) ? cout << hireMan[i] + 1 << ',' : cout << hireMan[i] + 1;
    }
    delete[] empInfo;
    delete[] isHired;
    delete[] hireMan;
    for (int i = 0; i < n; i++)
    {
        delete[] mad[i];
    }
    delete[] mad;
    delete[] length;
}