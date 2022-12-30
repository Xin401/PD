#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // n:lc     m:store     p:price     c:cost
    int n = 0, m = 0, p = 0, c = 0, earn = 0, unSatis = 0;
    cin >> n >> m >> p >> c;
    // 物流中心地圖
    int *lc = new int[2 * n];
    int *storemap = new int[2 * m];
    // store第一列：距離    第二列：需求
    int **store = new int *[2];
    for (int i = 0; i < 2; i++)
    {
        store[i] = new int[m];
    }
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> lc[i];
    }
    for (int i = 0; i < 2 * m; i++)
    {
        cin >> storemap[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> store[1][i];
    }
    //算距離
    for (int i = 0; i < m; i++)
    {
        store[0][i] = abs(storemap[2 * i] - lc[0]) + abs(storemap[2 * i + 1] - lc[1]);
        for (int j = 1; j < n; j++)
        {
            if (store[0][i] > abs(storemap[2 * i] - lc[2 * j]) + abs(storemap[2 * i + 1] - lc[2 * j + 1]))
            {
                store[0][i] = abs(storemap[2 * i] - lc[2 * j]) + abs(storemap[2 * i + 1] - lc[2 * j + 1]);
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (store[0][i] * c > p)
        {
            unSatis += store[1][i];
        }
        else
        {
            earn += store[1][i] * (p - store[0][i] * c);
        }
    }
    cout << earn << ',' << unSatis;
    delete[] lc;
    delete[] storemap;
    for (int i = 0; i < 2; i++)
    {
        delete[] store[i];
    }
    delete[] store;
}
