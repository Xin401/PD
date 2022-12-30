#include <iostream>
using namespace std;

const int MAX_ELE_CNT = 100;

float calculateCost(int ssIndex, int ssElement[25][101], int cost[25], int road[101]);
void deal(int ssIndex, int ssElement[25][101], int road[101], int time);
int countElement(int road[101], int element);

int main()
{
    //ssNumber:子集合數 //element:元素數
    int ssNumber = 0, element = 0;
    cin >> ssNumber >> element;
    //ssElement:存所有子集合的元素資料  //raod:路段     //ifChosen:該子集合有沒有被選過
    int ssElement[25][101], road[101] = {0}, ifChosen[25] = {0};
    for (int i = 1; i <= element; i++)
    {
        road[i] = 1;
    }
    for (int i = 0; i < ssNumber; i++)
    {
        cin >> ssElement[i][0];
        for (int j = 1; j <= ssElement[i][0]; j++)
        {
            cin >> ssElement[i][j];
        }
    }
    //name:子集合名字
    char name[25];
    for (int i = 0; i < ssNumber; i++)
    {
        cin >> name[i];
    }
    //cost:子集合成本
    int cost[25];
    for (int i = 0; i < ssNumber; i++)
    {
        cin >> cost[i];
    }
    //當還有路段沒被包含時
    int a = element;
    while(a>0)
    {
        //index:成本最低的子集合是哪個
        int index = 0;
        for (int i = 1; i < ssNumber; i++)
        {
            if (ifChosen[i] == 0)
            {
                if (calculateCost(i, ssElement, cost, road) < calculateCost(index, ssElement, cost, road))
                {
                    index = i;
                }
            }
        }
        ifChosen[index] = 1;
        //deal:記錄選過的路段
        deal(index, ssElement, road, ssElement[index][0]);
        cout << name[index];
        cout << index << endl;
        for (int i = 1; i <= element; i++)
        {
            cout << road[i] << ",";
        }
        //countElement:計算還剩幾個路段沒被選
        a = countElement(road,element);
        cout << a << endl;
    }
}

float calculateCost(int ssIndex, int ssElement[25][101], int cost[25], int road[101])
{
    //sum:還沒被選過的路段數
    int sum = 0;
    for (int i = 1; i <= ssElement[ssIndex][0]; i++)
    {
        if (road[ssElement[ssIndex][i]] == 1)
        {
            sum++;
        }
    }
    return cost[ssIndex] / sum;
}

int countElement(int road[101], int element)
{
    int sum = 0;
    for (int i = 1; i <= element; i++)
    {
        if (road[i] == 1)
        {
            sum++;
        }
    }
    return sum;
}

void deal(int ssIndex, int ssElement[25][101], int road[101], int time)
{
    for (int i = 1; i <= time; i++)
    {
        road[ssElement[ssIndex][i]] = 0;
    }
}