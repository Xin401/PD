#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    //number:輸入的數字//num:存入三個位數
    int number = 0, num[3]={0};
    cin >> number;
    //三位數
    if (number >= 100)   
    {
        num[0] = number/100;
        num[1] = (number%100)/10;
        num[2] = number%10;
    }
    //二位數
    if (number >=10 && number <100)
    {
        num[1] = number/10;
        num[2] = number%10;
    }
    //個位數
    if (number <10)
    {
        num[2] = number;
    }
    sort(num,num+3);
    for (int i =2;i>=0;i--)
    {
        cout << num[i];
    }
}