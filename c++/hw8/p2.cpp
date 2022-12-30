#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int MAX_LEN = 5000;
struct store
{
    int x;
    int y;
    int demand;
    void getX()
    {
        char tempX[MAX_LEN + 1] = {0};
        char Xnumber[MAX_LEN + 1] = {0};
        cin.getline(tempX, MAX_LEN, ',');
        // get x
        char *toX = strpbrk(tempX, "1234567890");
        while (toX != nullptr)
        {
            strncat(Xnumber, toX, 1);
            toX = strpbrk(toX + 1, "1234567890");
        }
        x = atoi(Xnumber);
    }
    void getY()
    {
        char tempY[MAX_LEN + 1] = {0};
        char Ynumber[MAX_LEN + 1] = {0};
        cin.getline(tempY, MAX_LEN, ',');
        char *toY = strpbrk(tempY, "1234567890");
        while (toY != nullptr)
        {
            strncat(Ynumber, toY, 1);
            toY = strpbrk(toY + 1, "1234567890");
        }
        y = atoi(Ynumber);
    }
    void getLastY()
    {
        char tempY[MAX_LEN + 1] = {0};
        char Ynumber[MAX_LEN + 1] = {0};
        cin.getline(tempY, MAX_LEN);
        char *toY = strpbrk(tempY, "1234567890");
        while (toY != nullptr)
        {
            strncat(Ynumber, toY, 1);
            toY = strpbrk(toY + 1, "1234567890");
        }
        y = atoi(Ynumber);
    }
    void getDemand()
    {
        char tempDemand[MAX_LEN + 1] = {0};
        char Demandnumber[MAX_LEN + 1] = {0};
        cin.getline(tempDemand, MAX_LEN, ',');
        char *toDemand = strpbrk(tempDemand, "1234567890");
        while (toDemand != nullptr)
        {
            strncat(Demandnumber, toDemand, 1);
            toDemand = strpbrk(toDemand + 1, "1234567890");
        }
        demand = atoi(Demandnumber);
    }
    void getLastDemand()
    {
        char tempDemand[MAX_LEN + 1] = {0};
        char Demandnumber[MAX_LEN + 1] = {0};
        cin.getline(tempDemand, MAX_LEN);
        char *toDemand = strpbrk(tempDemand, "1234567890");
        while (toDemand != nullptr)
        {
            strncat(Demandnumber, toDemand, 1);
            toDemand = strpbrk(toDemand + 1, "1234567890");
        }
        demand = atoi(Demandnumber);
    }
};
struct lc
{
    int x;
    int y;
    void getX()
    {
        char tempX[MAX_LEN + 1] = {0};
        char Xnumber[MAX_LEN + 1] = {0};
        cin.getline(tempX, MAX_LEN, ',');
        // get x
        char *toX = strpbrk(tempX, "1234567890");
        while (toX != nullptr)
        {
            strncat(Xnumber, toX, 1);
            toX = strpbrk(toX + 1, "1234567890");
        }
        x = atoi(Xnumber);
    }
    void getY()
    {
        char tempY[MAX_LEN + 1] = {0};
        char Ynumber[MAX_LEN + 1] = {0};
        cin.getline(tempY, MAX_LEN, ',');
        char *toY = strpbrk(tempY, "1234567890");
        while (toY != nullptr)
        {
            strncat(Ynumber, toY, 1);
            toY = strpbrk(toY + 1, "1234567890");
        }
        y = atoi(Ynumber);
    }
    void getLastY()
    {
        char tempY[MAX_LEN + 1] = {0};
        char Ynumber[MAX_LEN + 1] = {0};
        cin.getline(tempY, MAX_LEN);
        char *toY = strpbrk(tempY, "1234567890");
        while (toY != nullptr)
        {
            strncat(Ynumber, toY, 1);
            toY = strpbrk(toY + 1, "1234567890");
        }
        y = atoi(Ynumber);
    }
};

int main()
{
    // n:lc, m:store, p:price, c:cost
    int n = 0, m = 0, p = 0, c = 0;
    // line1:n    line2:m    line3:p    line4:c
    char line1[MAX_LEN + 1] = {0}, line2[MAX_LEN + 1] = {0}, line3[MAX_LEN + 1] = {0}, line4[MAX_LEN + 1] = {0};
    char number[] = "1234567890";
    char N[MAX_LEN + 1] = {0}, M[MAX_LEN + 1] = {0}, P[MAX_LEN + 1] = {0}, C[MAX_LEN + 1] = {0};
    cin.getline(line1, MAX_LEN, ',');
    cin.getline(line2, MAX_LEN, ',');
    cin.getline(line3, MAX_LEN, ',');
    cin.getline(line4, MAX_LEN);
    // get n
    char *toN = strpbrk(line1, number);
    while (toN != nullptr)
    {
        strncat(N, toN, 1);
        toN = strpbrk(toN + 1, number);
    }
    n = atoi(N);
    // get m
    char *toM = strpbrk(line2, number);
    while (toM != nullptr)
    {
        strncat(M, toM, 1);
        toM = strpbrk(toM + 1, number);
    }
    m = atoi(M);
    // get p
    char *toP = strpbrk(line3, number);
    while (toP != nullptr)
    {
        strncat(P, toP, 1);
        toP = strpbrk(toP + 1, number);
    }
    p = atoi(P);
    // get c
    char *toC = strpbrk(line4, number);
    while (toC != nullptr)
    {
        strncat(C, toC, 1);
        toC = strpbrk(toC + 1, number);
    }
    c = atoi(C);
    // create lc info
    lc *lcInfo = new lc[n];
    for (int i = 0; i < n - 1; i++)
    {
        lcInfo[i].getX();
        lcInfo[i].getY();
    }
    lcInfo[n - 1].getX();
    lcInfo[n - 1].getLastY();

    // create store info
    store *storeInfo = new store[m];
    for (int i = 0; i < m - 1; i++)
    {
        storeInfo[i].getX();
        storeInfo[i].getY();
    }
    storeInfo[m - 1].getX();
    storeInfo[m - 1].getLastY();

    for (int i = 0; i < m - 1; i++)
    {
        storeInfo[i].getDemand();
    }
    storeInfo[m - 1].getLastDemand();

    for (int i = 0; i < m; i++)
    {
        int *rev = new int[n];
        bool ifGive = 0;
        int max = 0;
        for (int j = 0; j < n; j++)
        {
            rev[j] = p - (abs(storeInfo[i].x - lcInfo[j].x) + abs(storeInfo[i].y - lcInfo[j].y)) * c;
            if (rev[j] >= max)
            {
                max = rev[j];
            }
            if (rev[j] >= 0)
            {
                ifGive = 1;
            }
        }
        if (ifGive == 0)
        {
            i == m - 1 ? cout << '0' : cout << '0' << ',';
        }
        // 要給
        else
        {
            int lcNum = 0;
            int theLc = 0;
            // 存要給的中心數量
            for (int i = 0; i < n; i++)
            {
                if (rev[i] == max)
                {
                    lcNum++;
                }
            }
            // 存要給的中心的編號
            int *maxNum = new int[lcNum];
            int now = 0;
            for (int i = 0; i < n; i++)
            {
                if (rev[i] == max)
                {
                    maxNum[now] = i;
                    now++;
                }
            }
            if (lcNum == 1)
            {
                i == m - 1 ? cout << maxNum[0] + 1 : cout << maxNum[0] + 1 << ',';
                delete[] maxNum;
                continue;
            }
            // 找最小x
            int minX = 0;
            bool isXsame = 0;
            int minNum = 0;
            int minTime = 0;
            for (int i = 1; i < lcNum; i++)
            {
                if (lcInfo[maxNum[minX]].x > lcInfo[maxNum[i]].x)
                {
                    minX = i;
                    minNum = lcInfo[maxNum[i]].x;
                }
            }
            int record[2] = {0};
            int recordNow = 0;
            for (int i = 0; i < lcNum; i++)
            {
                if (minNum == lcInfo[maxNum[i]].x)
                {
                    record[recordNow] = i;
                    recordNow++;
                    minTime++;
                }
            }
            if (minTime == 1)
            {
                i == m - 1 ? cout << maxNum[minX] + 1 : cout << maxNum[minX] + 1 << ',';
            }
            else
            {
                int minY = record[0];
                if (lcInfo[maxNum[record[0]]].y > lcInfo[maxNum[record[1]]].y)
                {
                    minY = record[1];
                }
                i == m - 1 ? cout << maxNum[minY] + 1 : cout << maxNum[minY] + 1 << ',';
            }
            delete[] maxNum;
        }
        delete[] rev;
    }

    delete[] lcInfo;
    delete[] storeInfo;
}
