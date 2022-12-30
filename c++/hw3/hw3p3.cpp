#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    //最多的天數
    const int max_days = 1000;

    //S:每次進貨到多少     //cost_o:存貨成本   //cost_u:缺貨成本  //stock:存貨    //days:要算的天數   //least_cost：最少的成本    //best_s:最佳s
    int S = 0, cost_o = 0, cost_u = 0, stock = 0, days = 0, leastcost = 0, best_s = 0;
    cin >> S >> cost_o >> cost_u >> stock >> days;
    //demand:每天的需求     //cost:各種s的總成本
    int demand[max_days] = {0}, cost[100] = {0};
    //輸入每天的需求(從第一天開始)
    for (int i = 1; i <= days; i++)
    {
        cin >> demand[i];
    }
    //算哪個s才是最佳的
    for (int s = 0; s < S; s++)
    {
        //stock_in_loop:迴圈中的存貨（每次算之前都要重置）   //cost_sum:當前s的總成本
        int cost_sum = 0, stock_in_loop = stock;    
        //計算當前s每天的存貨及成本
        for (int i = 1; i <= days; i++)
        {
            stock_in_loop -= demand[i];         //當天存貨＝存貨-需求
            if (stock_in_loop >= 0)             //如果有存貨，計算存貨成本
            {
                cost_sum += stock_in_loop * cost_o;
            }
            else //如果沒存貨，計算缺貨成本
            {
                cost_sum += abs(stock_in_loop) * cost_u;
            }
            if (stock_in_loop <= s) //如果存貨 <= s 就進貨到 Ｓ
            {
                stock_in_loop = S;
            }
        }
        cost[s] = cost_sum; //將當前s的成本存入陣列
    }
    leastcost = cost[0];    //先假設s=0成本最低
    for (int i = 1; i < S ; i++)
    {
        if (leastcost > cost[i])    //有更低的成本就取代原本的成本跟s
        {
            leastcost = cost[i];
            best_s = i;
        }
    }
    //輸出結果
    cout << best_s << "," << leastcost << endl; 
}