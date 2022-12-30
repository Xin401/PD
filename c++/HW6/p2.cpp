#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int num[3] = {0}, numberarray[6] = {0};
    int number = 0, n = 0;
    cin >> number >> n;
    if (number >= 100)
    {
        num[0] = number / 100;
        num[1] = (number % 100) / 10;
        num[2] = number % 10;
    }
    //二位數
    if (number >= 10 && number < 100)
    {
        num[1] = number / 10;
        num[2] = number % 10;
    }
    //個位數
    if (number < 10)
    {
        num[2] = number;
    }
    numberarray[0] = 100*num[0] + 10*num[1] + num[2];
    numberarray[1] = 100*num[0] + 10*num[2] + num[1];
    numberarray[2] = 100*num[1] + 10*num[0] + num[2];
    numberarray[3] = 100*num[1] + 10*num[2] + num[0];
    numberarray[4] = 100*num[2] + 10*num[0] + num[1];
    numberarray[5] = 100*num[2] + 10*num[1] + num[0];
    sort(numberarray,numberarray+6);
    cout << numberarray[6-n];
}