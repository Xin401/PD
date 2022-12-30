#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    //最多的天數
    const int max_days = 1000;

    //S:每次進貨到多少   //s:多少以下要進貨  //cost_o:存貨成本   //cost_u:缺貨成本  //stock:存貨    //days:天數     //sum:總成本    //shortday:缺貨日數
    int S = 0, s = 0, cost_o = 0, cost_u = 0, stock = 0, days = 0, sum = 0, shortday = 0;
    cin >> S >> s >> cost_o >> cost_u >> stock >> days;
    int demand[max_days] = {0};
    //輸入每天的需求(從第一天開始)
    for (int i = 1; i <= days; i++)
    {
        cin >> demand[i];
    }
    //計算每天的存貨及成本
    for (int i = 1; i <= days; i++)
    {
        stock -= demand[i]; //當天存貨＝存貨-需求
        if (stock >= 0)     //如果有存貨，計算存貨成本
        {
            sum += stock * cost_o;
        }
        else //如果沒存貨，計算缺貨成本
        {
            sum += abs(stock) * cost_u;
            shortday++;
        }
        if (stock <= s) //如果存貨 <= s 就進貨到 Ｓ
        {
            stock = S;
        }
    }
    //輸出結果
    cout << shortday << "," << sum;
}