#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    //學生數最多1000
    const int max_students = 1000;
    //students:學生數   //score:學生分數陣列    //leastscore:標準    //sum:高於最低分的分數總和  //max:最高分    //over:超過標準的學生數
    int students = 0, score[max_students] = {0}, leastscore = 0, sum = 0, max = 0, over = 0;
    cin >> students >> leastscore;
    //輸入各同學分數，同時找到最高分。
    for (int i = 0; i < students; i++)
    {
        cin >> score[i];
        if (max <= score[i]) //輸入的分數若大於最高分，則成為新的最高分。
        {
            max = score[i];
        }
    }
    //計算超出標準的分數總和和學生數
    for (int i = 0; i < students; i++)
    {
        if (score[i] >= leastscore)
        {
            sum += score[i];
            over++;
        }
    }
    //如果沒人超出標準，輸出最高分＆-1
    if (sum == 0)
    {
        cout << max << ","
             << "-1";
    }
    //輸出最高分＆超出標準分數平均
    else
    {
        cout << max << "," << floor(sum / over);
    }
}