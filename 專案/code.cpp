#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

struct Lc
{
    int x;
    int y;
    int capacity;
    int buildingCost;
    double cpc;
    void countcpc()
    {
        if (buildingCost != 0)
        {
            cpc = static_cast<double>(capacity) / buildingCost;
        }
        else
        {
            cpc = 0;
        }
    }
    bool isBuilt; //判斷要不要算建造成本
    int myRev;    //初始化為0
};
struct Store
{
    int x;
    int y;
    int demand;
    int buildingCost;
    int price;
    bool isBuilt;    //判斷要不要算建造成本
    int chosenTimes; //chosenTimes = s
    int *fromLc;     //一個一維陣列，長度為n，紀錄補貨數量，初始值為0
};
double findRevenue(const Store, const Lc, const int);
int doBestCombination(Store *, Lc *, int, int, int, int);

int main()
{
    int n, m, cost, s;
    cin >> n >> m >> cost >> s; //第一行輸入
    Lc *center = new Lc[n];
    Store *retailer = new Store[m];
    // 開始初始化
    for (int i = 0; i < n; i++)
    {
        center[i].isBuilt = false;
        center[i].myRev = 0;
    }
    for (int i = 0; i < m; i++)
    {
        retailer[i].isBuilt = false;
        if (s == 1)
            retailer[i].chosenTimes = 1;
        if (s == 2)
            retailer[i].chosenTimes = n;
        retailer[i].fromLc = new int[n];
        for (int j = 0; j < n; j++)
            retailer[i].fromLc[j] = 0;
    }
    // 初始化完畢
    for (int i = 0; i < n; i++)
    {
        cin >> center[i].x >> center[i].y; //第二行輸入
    }
    for (int i = 0; i < m; i++)
    {
        cin >> retailer[i].x >> retailer[i].y; //第三行輸入
    }
    for (int i = 0; i < m; i++)
    {
        cin >> retailer[i].demand; //第四行輸入
    }
    for (int i = 0; i < m; i++)
    {
        cin >> retailer[i].buildingCost; //第五行輸入
    }
    for (int i = 0; i < m; i++)
    {
        cin >> retailer[i].price; //第六行輸入
        if (retailer[i].price * retailer[i].demand <= retailer[i].buildingCost)
        {
            retailer[i].chosenTimes = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cin >> center[i].buildingCost; //第七行輸入
    }
    for (int i = 0; i < n; i++)
    {
        cin >> center[i].capacity; //第八行輸入
    }
    for (int i = 0; i < n; i++)
    {
        center[i].countcpc();
        cout << center[i].cpc << endl;
    }
    while (true)
    {
        bool det = doBestCombination(retailer, center, cost, n, m, s);
        if (det == false)
            break;
    }
    // 開始輸出
    int lcNum = 0; //算出架設物流中心的數量
    for (int i = 0; i < n; i++)
    {
        if (center[i].isBuilt)
            lcNum += 1;
    }
    int rNum = 0; //算出架設零售店的數量
    for (int i = 0; i < m; i++)
    {
        if (retailer[i].isBuilt)
            rNum += 1;
    }
    cout << lcNum;
    if (lcNum != 0)
    {
        cout << " ";
        int *centerBuilt = new int[lcNum];
        int x = 0;
        for (int i = 0; i < n; i++)
        {
            if (center[i].isBuilt)
            {
                centerBuilt[x] = i;
                x++;
            }
        }
        for (int i = 0; i < lcNum - 1; i++)
            cout << centerBuilt[i] + 1 << " ";
        cout << centerBuilt[lcNum - 1] + 1 << endl;
        delete[] centerBuilt;
    }
    else
        cout << "\n";
    cout << rNum;
    if (rNum != 0)
    {
        cout << " ";
        int *storeBuilt = new int[rNum];
        int x = 0;
        for (int i = 0; i < m; i++)
        {
            if (retailer[i].isBuilt)
            {
                storeBuilt[x] = i + 1;
                x++;
            }
        }
        for (int i = 0; i < rNum - 1; i++)
            cout << storeBuilt[i] << " ";
        cout << storeBuilt[rNum - 1] << endl;
        delete[] storeBuilt;
    }
    else
        cout << "\n";
    //m rNum零售店 n lcNum物流中心
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
            cout << retailer[i].fromLc[j] << " ";
        cout << retailer[i].fromLc[n - 1] << endl;
    }
    for (int j = 0; j < n - 1; j++)
        cout << retailer[m - 1].fromLc[j] << " ";
    cout << retailer[m - 1].fromLc[n - 1];
    /* int totalRev = 0;
    for(int i = 0; i < n; i++)
        totalRev += center[i].myRev;
    cout << "\n" << totalRev; */
    for (int i = 0; i < m; i++)
    {
        delete[] retailer[i].fromLc;
    }
    delete[] center;
    delete[] retailer;

    return 0;
}

double findRevenue(const Store store1, const Lc lc1, const int c)
{
    //宣告補貨數量
    int deliveryNum = (lc1.capacity >= store1.demand ? store1.demand : lc1.capacity);
    // 補貨數量是零售店需求量和物流中心容量中比較小的
    int Revenue = (store1.price - (abs(store1.x - lc1.x) + abs(store1.y - lc1.y)) * c) * deliveryNum; //帶公式得到revenue
    //如果是沒蓋的建築要把建造成本算進去
    if (!store1.isBuilt)
        Revenue -= store1.buildingCost;
    if (!lc1.isBuilt) //如果是沒蓋的建築要把建造成本算進去
        Revenue -= lc1.buildingCost;
    if (deliveryNum == 0)
        return Revenue;
    double avgRevenue = static_cast<double>(Revenue) / deliveryNum;
    return avgRevenue;
}
int doBestCombination(Store *retailer, Lc *center, int c, int n, int m, int s)
{
    int highRev = INT_MIN, curRev = 0;
    int bestSto = 0, bestLc = 0; // 記住最佳組合各自的編號
    for (int i = 0; i < m; i++)  //對每一個零售店而言
    {
        if (retailer[i].chosenTimes == 0) //扣打用完的零售店要去旁邊玩沙
            continue;
        for (int j = 0; j < n; j++) //跟每一個物流中心比
        {
            if (center[j].capacity == 0) //沒貨可以送的物流中心請滾蛋
                continue;
            curRev = findRevenue(retailer[i], center[j], c);
            if (highRev < curRev)
            {
                highRev = curRev;
                bestSto = i;
                bestLc = j;
            }
        }
    }
    //迴圈跑完，得到最佳組合跟最佳revenue
    if (highRev < 0)
        return false;
    int deliveryNum = 0;
    if (retailer[bestSto].demand <= center[bestLc].capacity) //找個補貨數量
        deliveryNum = retailer[bestSto].demand;
    else
        deliveryNum = center[bestLc].capacity;
    center[bestLc].myRev += highRev;                //計入賺到的錢
    center[bestLc].capacity -= deliveryNum;         //原本的容量扣掉送出的貨物數量，變成剩餘容量
    retailer[bestSto].demand -= deliveryNum;        //原本的需求扣掉收到的補貨數量，變成剩餘需求量
    center[bestLc].isBuilt = true;                  //標示這棟建築已經蓋了，之後不會再算到他的建造成本
    retailer[bestSto].isBuilt = true;               //標示這棟建築已經蓋了，之後不會再算到他的建造成本
    retailer[bestSto].fromLc[bestLc] = deliveryNum; //紀錄補貨數量
    retailer[bestSto].chosenTimes -= 1;             //被選到的零售店扣打會被減一
    return true;
}