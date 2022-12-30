#include <iostream>
#include <cmath>
using namespace std;

struct store
{
    int x;
    int y;
    int demand;
};

struct lc
{
    int x;
    int y;
    int capacity;
};

int findRev(lc lcInfo, store storeInfo, int p, int c, int distance);

int main()
{
    // n:lc number  m: store number  p:price  c:cost
    int n = 0, m = 0, p = 0, c = 0;
    // 要輸出的：獲利＆未滿足數量
    int revenue = 0, unsatisDemand = 0;
    cin >> n >> m >> p >> c;
    lc *lcInfo = new lc[n];
    // 輸入物流中心座標
    for (int i = 0; i < n; i++)
    {
        cin >> lcInfo[i].x >> lcInfo[i].y;
    }
    store *storeInfo = new store[m];
    // 輸入商店座標
    for (int i = 0; i < m; i++)
    {
        cin >> storeInfo[i].x >> storeInfo[i].y;
    }
    // 輸入商店需求
    for (int i = 0; i < m; i++)
    {
        cin >> storeInfo[i].demand;
    }
    // 輸入物流中心容量
    for (int i = 0; i < n; i++)
    {
        cin >> lcInfo[i].capacity;
    }
    // 創建一個distance的表
    int **distance = new int *[n];
    for (int i = 0; i < n; i++)
    {
        distance[i] = new int[m];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            distance[i][j] = abs(lcInfo[i].x - storeInfo[j].x) + abs(lcInfo[i].y - storeInfo[j].y);
        }
    }
    // 創建一個revenue的表
    int **revenueTable = new int *[n];
    for (int i = 0; i < n; i++)
    {
        revenueTable[i] = new int[m];
    }
    // 填入獲利
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            revenueTable[i][j] = findRev(lcInfo[i], storeInfo[j], p, c, distance[i][j]);
        }
    }

    bool needSupply = false;
    while (needSupply)
    {
        // 找沒被滿足的商店
        bool unsatis = false;
        for (int i = 0; i < m; i++)
        {
            // 有無尚未滿足的商店
            if (storeInfo[i].demand > 0)
            {
                unsatis = true;
            }
        }
        // lcPick存：revenue+獲利最大物流中心座標
        int lcPick[3] = {revenueTable[0][0], 0, 0};
        if (unsatis)
        {
            // 找有沒有獲利為正的物流中心
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (revenueTable[i][j] > lcPick[0])
                    {
                        lcPick[0] = revenueTable[i][j];
                        lcPick[1] = lcInfo[i].x;
                        lcPick[2] = lcInfo[i].y;
                        continue;
                    }
                    if (revenueTable[i][j] == lcPick[0])
                    {
                    }
                }
            }
        }
        else
        {
            needSupply = false;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << revenueTable[i][j] << ',';
        }
        cout << endl;
    }
    delete[] lcInfo;
    delete[] storeInfo;
    for (int i = 0; i < n; i++)
    {
        delete[] distance[i];
    }
    delete[] distance;
    for (int i = 0; i < n; i++)
    {
        delete[] revenueTable[i];
    }
    delete[] revenueTable;
    return 0;
}

int findRev(lc lcInfo, store storeInfo, int p, int c, int distance)
{
    int revenue = 0;
    // 需求比存貨小，獲利用需求算，反之
    revenue = (lcInfo.capacity > storeInfo.demand ? storeInfo.demand * p - distance * c : lcInfo.capacity * p - distance * c);
    return revenue;
}