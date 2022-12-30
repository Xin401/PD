#include <iostream>
using namespace std;

void middle(int number[]);

int main()
{
    int number[3];
    for (int i = 0; i < 3; i++)
    {
        cin >> number[i];
    }
    middle (number);
    cout << number[1];
}

void middle(int number[])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(number[j]>number[i])
            {
                int temp = number[j];
                number[j] = number[i];
                number[i] = temp;
            }
        }
    }
}