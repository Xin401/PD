#include <iostream>
using namespace std;

int main()
{
    int station = 0, demand = 0, seat[10] = {0}, seatNow[10] = {0}, user[2][100] = {0};
    cin >> station >> demand;
    for (int i = 0; i < station; i++)
    {
        cin >> seat[i];
    }
    for (int i = 0; i < station; i++)
    {
        cin >> seatNow[i];
    }
    for (int i = 0; i < demand; i++)
    {
        cin >> user[0][i] >> user[1][i];
    }
    for (int i = 0; i < demand; i++)
    {
        if (user[0][i] != user[1][i])
        {
            if ((seatNow[user[0][i] - 1] > 0) && (seatNow[user[1][i] - 1] != seat[user[1][i]-1]))
            {
                seatNow[user[0][i] - 1]--;
                seatNow[user[1][i] - 1]++;
            }
        }
    }
    cout << seatNow[0];
    for (int i = 1; i < station; i++)
    {
        cout << "," << seatNow[i];
    }
}