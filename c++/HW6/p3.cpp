#include <iostream>
using namespace std;

int getLenth(char a[]);
void bigMoneyAdd(char m1[], char m2[], char sum[], int n, int len1, int len2);
void bigMoneySub(char m1[], char m2[], char diff[], int n, int len1, int len2);
bool ifNotZero(char a[], int n);
int main()
{
    char m1[100], m2[100], sum[101], diff[100];
    int digits = 0;
    cin >> digits;
    cin >> m1 >> m2;
    int len1 = getLenth(m1);
    int len2 = getLenth(m2);
    bigMoneyAdd(m1, m2, sum, digits, len1, len2);
    bigMoneySub(m1, m2, diff, digits, len1, len2);
    if (ifNotZero(sum, digits))
    {
        int flag = 0;
        cout << '$';
        for (int i = 0; i < digits; i++)
        {
            if (sum[i] != 48)
            {
                flag = 1;
            }
            if(flag == 1)
            {
                cout << sum[i];
                if ((digits - i) != 1 && (digits - i) % 3 == 1)
                {
                    cout << ',';
                }
            }
        }
        cout << endl;
    }
    else
    {
        cout << "$0" << endl;
    }
    if (ifNotZero(diff, digits))
    {
        int flag1 = 0;
        cout << '$';
        for (int i = 0; i < digits; i++)
        {
            if (diff[i] != 48)
            {
                flag1 = 1;
            }
            if(flag1 == 1)
            {
                cout << diff[i];
                if ((digits - i) != 1 && (digits - i) % 3 == 1)
                {
                    cout << ',';
                }
            }
        }
    }
    else
    {
        cout << "$0";
    }
}

void bigMoneyAdd(char m1[], char m2[], char sum[], int n, int len1, int len2)
{
    int arr1[100] = {0}, arr2[100] = {0};
    for (int i = 0; i < len1; i++)
    {
        arr1[n - len1 + i] = static_cast<int>(m1[i]) - 48;
    }
    for (int i = 0; i < len2; i++)
    {
        arr2[n - len2 + i] = static_cast<int>(m2[i]) - 48;
    }
    for (int i = n-1; i >= 0; i--)
    {
        if (arr1[i] + arr2[i] >= 10)
        {
            arr1[i - 1]++;
            sum[i] = static_cast<char>(arr1[i] + arr2[i] + 38);
        }
        else
        {
            sum[i] = static_cast<char>(arr1[i] + arr2[i] + 48);
        }
    }
}
void bigMoneySub(char m1[], char m2[], char diff[], int n, int len1, int len2)
{
    int arr1[100] = {0}, arr2[100] = {0};
    for (int i = 0; i < len1; i++)
    {
        arr1[n - len1 + i] = static_cast<int>(m1[i]) - 48;
    }
    for (int i = 0; i < len2; i++)
    {
        arr2[n - len2 + i] = static_cast<int>(m2[i]) - 48;
    }
    for (int i = n-1; i >= 0; i--)
    {
        if (arr1[i] - arr2[i] < 0)
        {
            arr1[i - 1]--;
            diff[i] = static_cast<char>(arr1[i] - arr2[i] + 58);
        }
        else
        {
            diff[i] = static_cast<char>(arr1[i] - arr2[i] + 48);
        }
    }
}
int getLenth(char a[])
{
    int L = 0;
    for (int i = 0; i < 100; i++)
    {
        if (a[i] != '\0')
        {
            L++;
            continue;
        }
        else
        {
            break;
        }
    }
    return L;
}

bool ifNotZero(char a[], int n)
{
    for (int i = n-1; i >= 0; i--)
    {
        if (a[i] != 48)
        {
            return true;
        }
    }
    return false;
}