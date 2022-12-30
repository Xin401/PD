#include <iostream>
using namespace std;

int main()
{
    int Wh = 0, Wl = 0, Th = 0, Tl = 0, wood = 0, time = 0, Ph = 0, Pl = 0, max = 0;
    cin >> wood >> time >> Wh >> Wl >> Th >> Tl >> Ph >> Pl;
    int maxhigh = 0;
    maxhigh = min(wood / Wh, time / Th);
    for (int i = maxhigh; i >= 0; i--)
    {
        int tempTime = time, tempWood = wood, low = 0;
        tempTime -= i * Th;
        tempWood -= i * Wh;
        low = min(tempTime/Tl,tempWood/Wl);
        if(max <= i*Ph+low*Pl)
        {
            max = i*Ph+low*Pl;
        }
    }
    cout << max;
}