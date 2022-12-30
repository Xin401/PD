#include <iostream>
using namespace std;

int main()
{
    int number = 0, items[2][100] = {0}, money = 0;
    cin >> number >> money;
    for (int i = 0; i < number; i++)
    {
        cin >> items[0][i];
    }
    for (int i = 0; i < number; i++)
    {
        cin >> items[1][i];
    }

    if (items[1][0] == 1 && money >= items[0][0])
    {
        money -= items[0][0];
    }
    if (items[1][0] == 0 && items[0][0] <= money / 2)
    {
        money -= items[0][0];
    }
    cout << money;
    for (int i = 1; i < number; i++)
    {
        if (items[1][i] == 1 && money >= items[0][i])
        {
            money -= items[0][i];
        }
        if (items[1][i] == 0 && items[0][i] <= money / 2)
        {
            money -= items[0][i];
        }
        cout << "," << money;
    }
}