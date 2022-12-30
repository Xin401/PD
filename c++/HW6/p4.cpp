#include <iostream>
using namespace std;

int getLenth(char a[]);
void SameBigMoneyAdd(char m1[], char m2[], char sum[], int n, int len1, int len2);
void SameBigMoneySub(char m1[], char m2[], char diff[], int n, int len1, int len2);
void BigMoneyAdd(char m1[], char m2[], char sum[], int n, int len1, int len2);
void BigMoneySub(char m1[], char m2[], char sum[], int n, int len1, int len2);
bool ifNotZero(char a[], int n);
int main()
{
    char m1[100], m2[100], sum[101], diff[100];
    int digits = 0, ifSame = 0;
    cin >> digits;
    cin >> m1 >> m2;
    // 看是不是同號
    if ((m1[0] == '-' && m2[0] == '-') || (m1[0] != '-' && m2[0] != '-'))
    {
        ifSame = 1;
    }
    //取長度
    int len1 = getLenth(m1);
    int len2 = getLenth(m2);
    switch (ifSame)
    {
    case 1:
        SameBigMoneyAdd(m1, m2, sum, digits, len1, len2);
        SameBigMoneySub(m1, m2, diff, digits, len1, len2);
        break;
    case 0:
        BigMoneyAdd(m1, m2, sum, digits, len1, len2);
        BigMoneySub(m1, m2, diff, digits, len1, len2);
        break;
    }
}
void SameBigMoneyAdd(char m1[], char m2[], char sum[], int n, int len1, int len2)
{
    int arr1[100] = {0}, arr2[100] = {0};
    if (m1[0] == '-')
    {
        for (int i = 0; i < len1; i++)
        {
            arr1[n - len1 + i] = static_cast<int>(m1[i + 1]) - 48;
        }
    }
    else
    {
        for (int i = 0; i < len1; i++)
        {
            arr1[n - len1 + i] = static_cast<int>(m1[i]) - 48;
        }
    }
    if (m2[0] == '-')
    {
        for (int i = 0; i < len2; i++)
        {
            arr2[n - len2 + i] = static_cast<int>(m2[i + 1]) - 48;
        }
    }
    else
    {
        for (int i = 0; i < len2; i++)
        {
            arr2[n - len2 + i] = static_cast<int>(m2[i]) - 48;
        }
    }
    for (int i = n - 1; i >= 0; i--)
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
    if (ifNotZero(sum, n)) //如果和不是0
    {
        //flag:看到達第一個不為0的數字了沒
        int flag = 0;
        m1[0] == '-' ? cout << "$-" : cout << '$';
        for (int i = 0; i < n; i++)
        {
            if (sum[i] != 48)
            {
                flag = 1;
            }
            if (flag == 1) //到達第一個不為0的數字後，開始輸出金額
            {
                cout << sum[i];
                if ((n - i) != 1 && (n - i) % 3 == 1) //每三位就要加逗號
                {
                    cout << ',';
                }
            }
        }
        cout << endl;
    }
    else //和=0，輸出$0
    {
        cout << "$0" << endl;
    }
}
void SameBigMoneySub(char m1[], char m2[], char diff[], int n, int len1, int len2)
{
    int arr1[100] = {0}, arr2[100] = {0}, temp[100] = {0}, bigger = 1;
    if (m1[0] == '-')
    {
        for (int i = 0; i < len1; i++)
        {
            arr1[n - len1 + i] = static_cast<int>(m1[i + 1]) - 48;
        }
    }
    else
    {
        for (int i = 0; i < len1; i++)
        {
            arr1[n - len1 + i] = static_cast<int>(m1[i]) - 48;
        }
    }
    if (m2[0] == '-')
    {
        for (int i = 0; i < len2; i++)
        {
            arr2[n - len2 + i] = static_cast<int>(m2[i + 1]) - 48;
        }
    }
    else
    {
        for (int i = 0; i < len2; i++)
        {
            arr2[n - len2 + i] = static_cast<int>(m2[i]) - 48;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr1[i] - arr2[i] < 0)
        {
            temp[i] = arr1[i] + 10 - arr2[i];
            arr1[i - 1]--;
        }
        else
        {
            temp[i] = arr1[i] - arr2[i];
        }
    }
    temp[0] = arr1[0] - arr2[0];
    for (int i = 0; i < n; i++)
    {
        if (temp[i] < 0)
        {
            bigger = 0;
        }
    }
    for (int i = 0; i < 100; i++)
    {
        arr1[i] = 0;
    }
    if (m1[0] == '-')
    {
        for (int i = 0; i < len1; i++)
        {
            arr1[n - len1 + i] = static_cast<int>(m1[i + 1]) - 48;
        }
    }
    else
    {
        for (int i = 0; i < len1; i++)
        {
            arr1[n - len1 + i] = static_cast<int>(m1[i]) - 48;
        }
    }
    if (bigger)
    {
        for (int i = n - 1; i >= 0; i--)
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
        if (ifNotZero(diff, n)) //如果和不是0
        {
            //flag:看到達第一個不為0的數字了沒
            int flag = 0;
            m1[0] == '-' ? cout << "$-" : cout << '$';
            for (int i = 0; i < n; i++)
            {
                if (diff[i] != 48)
                {
                    flag = 1;
                }
                if (flag == 1) //到達第一個不為0的數字後，開始輸出金額
                {
                    cout << diff[i];
                    if ((n - i) != 1 && (n - i) % 3 == 1) //每三位就要加逗號
                    {
                        cout << ',';
                    }
                }
            }
            cout << endl;
        }
        else //和=0，輸出$0
        {
            cout << "$0" << endl;
        }
    }
    else
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (arr2[i] - arr1[i] < 0)
            {
                arr2[i - 1]--;
                diff[i] = static_cast<char>(arr2[i] - arr1[i] + 58);
            }
            else
            {
                diff[i] = static_cast<char>(arr2[i] - arr1[i] + 48);
            }
        }
        if (ifNotZero(diff, n)) //如果和不是0
        {
            //flag:看到達第一個不為0的數字了沒
            int flag = 0;
            m1[0] == '-' ? cout << "$" : cout << "$-";
            for (int i = 0; i < n; i++)
            {
                if (diff[i] != 48)
                {
                    flag = 1;
                }
                if (flag == 1) //到達第一個不為0的數字後，開始輸出金額
                {
                    cout << diff[i];
                    if ((n - i) != 1 && (n - i) % 3 == 1) //每三位就要加逗號
                    {
                        cout << ',';
                    }
                }
            }
            cout << endl;
        }
        else //和=0，輸出$0
        {
            cout << "$0" << endl;
        }
    }
}
void BigMoneyAdd(char m1[], char m2[], char sum[], int n, int len1, int len2)
{
    int arr1[100] = {0}, arr2[100] = {0}, temp[100] = {0}, bigger = 1;
    if (m1[0] == '-')
    {
        for (int i = 0; i < len1; i++)
        {
            arr1[n - len1 + i] = static_cast<int>(m1[i + 1]) - 48;
        }
    }
    else
    {
        for (int i = 0; i < len1; i++)
        {
            arr1[n - len1 + i] = static_cast<int>(m1[i]) - 48;
        }
    }
    if (m2[0] == '-')
    {
        for (int i = 0; i < len2; i++)
        {
            arr2[n - len2 + i] = static_cast<int>(m2[i + 1]) - 48;
        }
    }
    else
    {
        for (int i = 0; i < len2; i++)
        {
            arr2[n - len2 + i] = static_cast<int>(m2[i]) - 48;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr1[i] - arr2[i] < 0)
        {
            temp[i] = arr1[i] + 10 - arr2[i];
            arr1[i - 1]--;
        }
        else
        {
            temp[i] = arr1[i] - arr2[i];
        }
    }
    temp[0] = arr1[0] - arr2[0];
    for (int i = 0; i < n; i++)
    {
        if (temp[i] < 0)
        {
            bigger = 0;
        }
    }
    for (int i = 0; i < 100; i++)
    {
        arr1[i] = 0;
    }
    if (m1[0] == '-')
    {
        for (int i = 0; i < len1; i++)
        {
            arr1[n - len1 + i] = static_cast<int>(m1[i + 1]) - 48;
        }
    }
    else
    {
        for (int i = 0; i < len1; i++)
        {
            arr1[n - len1 + i] = static_cast<int>(m1[i]) - 48;
        }
    }
    if (bigger)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (arr1[i] - arr2[i] < 0)
            {
                arr1[i - 1]--;
                sum[i] = static_cast<char>(arr1[i] - arr2[i] + 58);
            }
            else
            {
                sum[i] = static_cast<char>(arr1[i] - arr2[i] + 48);
            }
        }
        if (ifNotZero(sum, n)) //如果和不是0
        {
            //flag:看到達第一個不為0的數字了沒
            int flag = 0;
            m1[0] == '-' ? cout << "$-" : cout << '$';
            for (int i = 0; i < n; i++)
            {
                if (sum[i] != 48)
                {
                    flag = 1;
                }
                if (flag == 1) //到達第一個不為0的數字後，開始輸出金額
                {
                    cout << sum[i];
                    if ((n - i) != 1 && (n - i) % 3 == 1) //每三位就要加逗號
                    {
                        cout << ',';
                    }
                }
            }
            cout << endl;
        }
        else //和=0，輸出$0
        {
            cout << "$0" << endl;
        }
    }
    else
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (arr2[i] - arr1[i] < 0)
            {
                arr2[i - 1]--;
                sum[i] = static_cast<char>(arr2[i] - arr1[i] + 58);
            }
            else
            {
                sum[i] = static_cast<char>(arr2[i] - arr1[i] + 48);
            }
        }
        if (ifNotZero(sum, n)) //如果和不是0
        {
            //flag:看到達第一個不為0的數字了沒
            int flag = 0;
            m1[0] == '-' ? cout << "$" : cout << "$-";
            for (int i = 0; i < n; i++)
            {
                if (sum[i] != 48)
                {
                    flag = 1;
                }
                if (flag == 1) //到達第一個不為0的數字後，開始輸出金額
                {
                    cout << sum[i];
                    if ((n - i) != 1 && (n - i) % 3 == 1) //每三位就要加逗號
                    {
                        cout << ',';
                    }
                }
            }
            cout << endl;
        }
        else //和=0，輸出$0
        {
            cout << "$0" << endl;
        }
    }
}
void BigMoneySub(char m1[], char m2[], char diff[], int n, int len1, int len2)
{
    int arr1[100] = {0}, arr2[100] = {0};
    if (m1[0] == '-')
    {
        for (int i = 0; i < len1; i++)
        {
            arr1[n - len1 + i] = static_cast<int>(m1[i + 1]) - 48;
        }
    }
    else
    {
        for (int i = 0; i < len1; i++)
        {
            arr1[n - len1 + i] = static_cast<int>(m1[i]) - 48;
        }
    }
    if (m2[0] == '-')
    {
        for (int i = 0; i < len2; i++)
        {
            arr2[n - len2 + i] = static_cast<int>(m2[i + 1]) - 48;
        }
    }
    else
    {
        for (int i = 0; i < len2; i++)
        {
            arr2[n - len2 + i] = static_cast<int>(m2[i]) - 48;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr1[i] + arr2[i] >= 10)
        {
            arr1[i - 1]++;
            diff[i] = static_cast<char>(arr1[i] + arr2[i] + 38);
        }
        else
        {
            diff[i] = static_cast<char>(arr1[i] + arr2[i] + 48);
        }
    }
    if (ifNotZero(diff, n)) //如果和不是0
    {
        //flag:看到達第一個不為0的數字了沒
        int flag = 0;
        m1[0] == '-' ? cout << "$-" : cout << '$';
        for (int i = 0; i < n; i++)
        {
            if (diff[i] != 48)
            {
                flag = 1;
            }
            if (flag == 1) //到達第一個不為0的數字後，開始輸出金額
            {
                cout << diff[i];
                if ((n - i) != 1 && (n - i) % 3 == 1) //每三位就要加逗號
                {
                    cout << ',';
                }
            }
        }
        cout << endl;
    }
    else //和=0，輸出$0
    {
        cout << "$0" << endl;
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
    if (a[0] == '-')
    {
        L--;
    }
    return L;
}

bool ifNotZero(char a[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] != 48)
        {
            return true;
        }
    }
    return false;
}