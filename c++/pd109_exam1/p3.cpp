#include <iostream>
using namespace std;

int main()
{
    int map[101][101] = {0}, x = 0, y = 0, station = 0, road = 0, station_point[2][20] = {0}, sum = 0;
    int rail[2][100] = {0};
    cin >> x >> y >> station >> road;
    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
        {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < station; i++)
    {
        cin >> station_point[0][i] >> station_point[1][i];
    }
    for (int i = 0; i < road; i++)
    {
        cin >> rail[0][i] >> rail[1][i];
    }
    for (int i = 0; i < road; i++)
    {
        if (rail[0][i] == rail[1][i])
        {
            continue;
        }
        else
        {
            //same x
            if (station_point[0][rail[0][i]] == station_point[0][rail[0][rail[1][i]]])
            {
                if(station_point[0][rail[0][i]]>=station_point[0][rail[1][i]])
                {
                    for(int j = station_point[0][rail[1][i]])
                }
            }
        }
    }
}