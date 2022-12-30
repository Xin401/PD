#include <iostream>
using namespace std;

const int MAX_NODE_CNT = 20;
int findDegree(int[MAX_NODE_CNT][MAX_NODE_CNT], int, int);

int main()
{
    // number:頂點數量  //odd_sum:奇頂點數
    int number = 0, odd_sum = 0;
    cin >> number;
    int map[MAX_NODE_CNT][MAX_NODE_CNT] = {0};
    //輸入資料
    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < number; j++)
        {
            cin >> map[i][j];
        }
    }
    //先輸出頂點1的度數
    cout << findDegree(map, 0, number);
    if (findDegree(map, 0, number) % 2 == 1)
    {
        odd_sum++;
    }
    for (int i = 1; i < number; i++)
    {
        cout << "," << findDegree(map, i, number);
        if (findDegree(map, i, number) % 2 == 1)        //如果是奇頂點，odd_sum++
        {
            odd_sum++;
        }
    }
    //若超過4個奇頂點
    if (odd_sum >= 4)
    {
        cout << ";" << 1;
    }
    //沒超過4個奇頂點
    else
    {
        cout << ";" << 0;
    }
}
//findDegree:算第i點的度數
int findDegree(int map[MAX_NODE_CNT][MAX_NODE_CNT], int i, int number)
{
    //sum:度數
    int sum = 0;
    for (int j = 0; j < number; j++)
    {
        sum += map[i][j];
    }
    return sum;
}