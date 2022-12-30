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

    // 輸入物流中心座標
    lc *lcInfo = new lc[n];
    for (int i = 0; i < n; i++)
    {
        cin >> lcInfo[i].x >> lcInfo[i].y;
    }

    // 輸入商店座標
    store *storeInfo = new store[m];
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
    // 還需不需要補貨
    bool needSupply = true;
    while (needSupply)
    {
        // 找沒被滿足的商店
        bool unsatis = false;
        int *unsatisArr = new int[m];
        for (int i = 0; i < m; i++)
        {
            unsatisArr[i] = 0;
        }
        for (int i = 0; i < m; i++)
        {
            // 有無尚未滿足的商店
            if (storeInfo[i].demand > 0)
            {
                unsatisArr[i] = 1;
                unsatis = true;
            }
        }
        // 有未滿足的商店
        if (unsatis)
        {
            // 找出有獲利的物流中心
            bool canHaveProfit = false;
            int **haveProfit = new int*[n];
            int *supplyLc = new int[m];
            for (int i = 0; i < n; i++)
            {
                haveProfit[i] = new int[m];
            }
            for (int i = 0; i < m; i++)
            {
                supplyLc[i] = -1;
            }
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (unsatisArr[i] == 0)
                    {
                        haveProfit[j][i] = 0;
                    }
                    else
                    {
                        haveProfit[j][i] = (findRev(lcInfo[j], storeInfo[i], p, c, distance[j][i]) > 0 ? 1 : 0);
                        if (findRev(lcInfo[j], storeInfo[i], p, c, distance[j][i]) > 0)
                        {
                            canHaveProfit = true;
                        }
                    }
                }
            }
            if (canHaveProfit)
            {
                // 找到每個組合
                for (int i = 0; i < m; i++)
                {
                    bool first = true;
                    for (int j = 0; j < n; j++)
                    {
                        if (haveProfit[j][i] == 1)
                        {
                            if (first)
                            {
                                supplyLc[i] = j;
                                first = false;
                            }
                            else
                            {
                                // 找最小距離且有獲利的
                                if (distance[supplyLc[i]][i] > distance[j][i])
                                {
                                    supplyLc[i] = j;
                                }
                                // 距離一樣找庫存大的
                                if (distance[supplyLc[i]][j] == distance[j][i])
                                {
                                    supplyLc[i] = (lcInfo[supplyLc[i]].capacity > lcInfo[j].capacity ? supplyLc[i] : j);
                                }
                            }
                        }
                    }
                }
                // 找到這輪要補貨的組合(補貨中心,商店)
                int correct[2] = {0};
                correct[0] = supplyLc[0];
                for (int i = 1; i < m; i++)
                {
                    if (supplyLc[i] != -1)
                    {
                        // 找距離小的
                        if (distance[supplyLc[i]][i] < distance[correct[0]][correct[1]])
                        {
                            correct[0] = supplyLc[i];
                            correct[1] = i;
                        }
                        // 距離一樣找未滿足大的
                        if (distance[supplyLc[i]][i] == distance[correct[0]][correct[1]])
                        {
                            if (storeInfo[i].demand > storeInfo[correct[1]].demand)
                            {
                                correct[0] = supplyLc[i];
                                correct[1] = i;
                            }
                        }
                    }
                }
                revenue += findRev(lcInfo[correct[0]], storeInfo[correct[1]], p, c, distance[correct[0]][correct[1]]);
                if (lcInfo[correct[0]].capacity >= storeInfo[correct[1]].demand)
                {
                    lcInfo[correct[0]].capacity -= storeInfo[correct[1]].demand;
                    storeInfo[correct[1]].demand = 0;
                }
                else
                {
                    storeInfo[correct[1]].demand -= lcInfo[correct[0]].capacity;
                    lcInfo[correct[0]].capacity = 0;
                }
            }
            else
            {
                needSupply = false;
            }
            // delete
            for (int i = 0; i < n; i++)
            {
                delete[] haveProfit[i];
            }
            delete[] haveProfit;
            delete[] supplyLc;
        }
        // 每個商店都沒有需求了，就不用補貨
        else
        {
            needSupply = false;
        }
        delete[] unsatisArr;
    }
    for (int i = 0; i < m; i++)
    {
        unsatisDemand += storeInfo[i].demand;
    }
    cout << revenue << ',' << unsatisDemand;
    // delete
    delete[] lcInfo;
    delete[] storeInfo;
    for (int i = 0; i < n; i++)
    {
        delete[] distance[i];
    }
    delete[] distance;
    return 0;
}

int findRev(lc lcInfo, store storeInfo, int p, int c, int distance)
{
    int revenue = 0;
    // 需求比存貨小，獲利用需求算，反之
    revenue = (lcInfo.capacity > storeInfo.demand ? storeInfo.demand * p - distance * c : lcInfo.capacity * p - distance * c);
    return revenue;
}