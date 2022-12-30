#include <iostream>
using namespace std;

int main()
{
    //0:wood 1:time 2:price
    int level = 0, wood = 0, time = 0, cost[3][10] = {0}, max = 0;
    cin >> level >> wood >> time;
    for (int i = 0; i < level; i++)
    {
        cin >> cost[0][i];
    }
    for (int i = 0; i < level; i++)
    {
        cin >> cost[1][i];
    }
    for (int i = 0; i < level; i++)
    {
        cin >> cost[2][i];
    }
    int begin = 0;
    begin = min(wood / cost[0][0], time / cost[1][0]);
    for (int i = begin; i >= 0; i--)
    {
        int tempwood = wood, temptime = time, sum = 0;
        tempwood -= i * cost[0][0];
        temptime -= i * cost[1][0];
        sum += cost[2][0] * i;
        for (int j = 1; j < level; j++)
        {
            int a = min(tempwood / cost[0][j], temptime / cost[1][j]);
            sum += cost[2][j]*a;
            tempwood -= cost[0][j] * a;
            temptime -= cost[1][j] * a;
        }
        if (sum >= max)
        {
            max = sum;
        }
    }
    cout << max;
}