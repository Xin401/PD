#include <iostream>
using namespace std;

int countZero(int **arr, int n, int current);
int SumArr(int **arr, int n, int current, int start);
int main()
{
    int sum = 0, n = 0, count = 0;
    cin >> n;
    // 動態二維陣列
    int **arr = new int *[n];
    // 二維陣列是n*n
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }
    // 輸入陣列資料順便算總和
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            sum += arr[i][j];
        }
    }
    //從1*1到n*n
    for (int i = 1; i <= n; i++)
    {
        //算i*i有幾個陣列總和=0
        count += countZero(arr, n, i);
    }
    cout << count << ',' << sum;
    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}

int countZero(int **arr, int n, int current)
{
    int time = 0;
    for (int i = 0; i <= n - current; i++)
    {
        time += SumArr(arr, n, current, i);
    }
    return time ;
}

int SumArr(int **arr, int n, int current, int start)
{
    int time = 0;
    for (int i = 0; i <= n - current; i++)
    {
        int sum = 0;
        for (int j = 0; j < current; j++)
        {
            for (int k = 0; k < current; k++)
            {
                sum += arr[start + j][k+i];
            }
        }
        if (sum == 0)
        {
            time ++;
        }
    }
    return time;
}