#include <iostream>
using namespace std;

int main()
{
    //number:要分解的數     //start:用來判斷是不是最小的因數的變數
    int number = 0, start = 1;
    //輸入要分解的數
    cin >> number;
    //因數從2開始，每次+1，加到要分解的數本身
    for (int i = 2; i <= number; i++)
    {
        int time = 0;             //當前因數的次數
        while ((number % i) == 0) //除到不能整除為止
        {
            time++;
            number /= i;
        }
        if (time > 0) //如果i是因數time就不會是0
        {
            if (start == 1) //如果是最小的因數
            {
                if (time == 1) //如果只有一次，輸出因數本身
                {
                    cout << i;
                }
                else //如果不止一次，輸出因數＋次數
                {
                    cout << i << " ^ " << time;
                }
                start = 0;
            }
            else //其他因數
            {
                if (time == 1) //如果只有一次，輸出因數本身
                {
                    cout << " * " << i;
                }
                else //如果不止一次，輸出因數＋次數
                {
                    cout << " * " << i << " ^ " << time;
                }
            }
        }
    }
}