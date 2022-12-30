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
    // capacity/buildingCost
    double cpc;
    void countcpc()
    {
        if (capacity != 0)
        {
            cpc = static_cast<double>(buildingCost) / capacity;
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
    // demand/buildingCost
    double cpd;
    void countcpd()
    {
        if (demand != 0)
        {
            cpd = static_cast<double>(buildingCost) / demand;
        }
        else
        {
            cpd = 0;
        }
    }
    bool isBuilt;    //判斷要不要算建造成本
    int chosenTimes; // chosenTimes = s
    int *fromLc;     //一個一維陣列，長度為n，紀錄補貨數量，初始值為0
};
int findRevenue(const Store store1, const Lc, int deliveryNum);
void doBestCombination(Store *retailer, Lc *center, double **canEarn, int betterLc);
int countRev(Store *retailer, Lc *center, double **canEarn, int number);

int n, m, cost, s;

int main()
{
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
    // 初始化
    for (int i = 0; i < n; i++)
    {
        center[i].countcpc();
    }
    for (int i = 0; i < m; i++)
    {
        retailer[i].countcpd();
    }
    // 可以賺錢的表
    double **canEarn = new double *[n];
    for (int i = 0; i < n; i++)
    {
        canEarn[i] = new double[m];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            double deliveryNum = (center[i].capacity >= retailer[j].demand ? retailer[j].demand : center[i].capacity);
            if (deliveryNum > 0)
            {
                canEarn[i][j] = retailer[j].price - ((abs(center[i].x - retailer[j].x) + abs(center[i].y - retailer[j].y)) * cost + center[i].cpc + retailer[j].cpd);
            }
            else
            {
                canEarn[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        center[i].myRev = countRev(retailer, center, canEarn, i);
    }
    for (int i = 0; i < n; i++)
    {
        int max = INT_MIN, betterLc = 0;
        for (int j = 0; j < n; j++)
        {
            if (center[j].myRev >= center[betterLc].myRev && center[j].myRev > 0)
            {
                betterLc = j;
                max = center[j].myRev;
            }
        }
        if (max <= 0)
        {
            break;
        }
        doBestCombination(retailer, center, canEarn, betterLc);
        for (int i = 0; i < n; i++)
        {
            center[i].myRev = countRev(retailer, center, canEarn, i);
        }
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
    // m rNum零售店 n lcNum物流中心
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
            cout << retailer[i].fromLc[j] << " ";
        cout << retailer[i].fromLc[n - 1] << endl;
    }
    for (int j = 0; j < n - 1; j++)
        cout << retailer[m - 1].fromLc[j] << " ";
    cout << retailer[m - 1].fromLc[n - 1];
    //===================================================================================
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
    for (int i = 0; i < n; i++)
    {
        delete[] canEarn[i];
    }
    delete[] canEarn;
    return 0;
}

int findRevenue(const Store store1, const Lc lc1, int deliveryNum)
{
    int Revenue = (store1.price - (abs(store1.x - lc1.x) + abs(store1.y - lc1.y)) * cost) * deliveryNum; //帶公式得到revenue
    //如果是沒蓋的建築要把建造成本算進去
    if (!store1.isBuilt)
        Revenue -= store1.buildingCost;
    return Revenue;
}
void doBestCombination(Store *retailer, Lc *center, double **canEarn, int betterLc)
{
    for (int i = 0; i < 2; i++)
    {
        int betterSto = 0;
        for (int j = 0; j < m; j++)
        {
            if (canEarn[betterLc][betterSto] < canEarn[betterLc][j])
            {
                betterSto = j;
            }
        }
        if (canEarn[betterLc][betterSto] <= 0)
        {
            break;
        }
        canEarn[betterLc][betterSto] = 0;
        int deliveryNum = (center[betterLc].capacity >= retailer[betterSto].demand ? retailer[betterSto].demand : center[betterLc].capacity);
        if (deliveryNum != 0)
        {
            center[betterLc].capacity -= deliveryNum;           //原本的容量扣掉送出的貨物數量，變成剩餘容量
            retailer[betterSto].demand -= deliveryNum;          //原本的需求扣掉收到的補貨數量，變成剩餘需求量
            center[betterLc].isBuilt = true;                    //標示這棟建築已經蓋了，之後不會再算到他的建造成本
            retailer[betterSto].isBuilt = true;                 //標示這棟建築已經蓋了，之後不會再算到他的建造成本
            retailer[betterSto].fromLc[betterLc] = deliveryNum; //紀錄補貨數量
            retailer[betterSto].chosenTimes -= 1;               //被選到的零售店扣打會被減一
        }
        else
        {
            break;
        }
    }
}

int countRev(Store *retailer, Lc *center, double **canEarn, int number)
{
    bool have = false;
    double *tempCanEarn = new double[m];
    for (int i = 0; i < m; i++)
    {
        tempCanEarn[i] = canEarn[number][i];
    }
    int bestSto = 0, max = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        if (tempCanEarn[i] > max && tempCanEarn[i] > 0)
        {
            max = tempCanEarn[i];
            bestSto = i;
            have = true;
        }
    }
    if (have)
    {
        int capacity = center[number].capacity;
        int rev = center[number].buildingCost;
        // 算可不可以賺錢
        for (int i = 0; i < m; i++)
        {
            int betterSto = 0;
            for (int j = 0; j < m; j++)
            {
                if (tempCanEarn[betterSto] < tempCanEarn[j])
                {
                    betterSto = j;
                }
            }
            if (tempCanEarn[betterSto] <= 0)
            {
                break;
            }
            int deliveryNum = (capacity >= retailer[betterSto].demand ? retailer[betterSto].demand : capacity);
            rev -= findRevenue(retailer[betterSto], center[number], deliveryNum);
            capacity -= deliveryNum;
            tempCanEarn[betterSto] = 0;
            if (capacity == 0)
            {
                break;
            }
        }
        delete[] tempCanEarn;
        return -rev;
    }
    return 0;
}