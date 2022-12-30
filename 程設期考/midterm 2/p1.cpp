#include <iostream>
using namespace std;

struct Vector
{
    int x;
    int y;
};
int main()
{
    int n = 0, k = 0;
    cin >> n >> k;
    Vector *vectorarr = new Vector[n];
    for (int i = 0; i < n; i++)
    {
        cin >> vectorarr[i].x;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> vectorarr[i].y;
    }
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if ((vectorarr[j].x + vectorarr[j].y) > (vectorarr[j + 1].x + vectorarr[j + 1].y))
            {
                int tempx = vectorarr[j].x;
                int tempy = vectorarr[j].y;
                vectorarr[j].x = vectorarr[j + 1].x;
                vectorarr[j].y = vectorarr[j + 1].y;
                vectorarr[j + 1].x = tempx;
                vectorarr[j + 1].y = tempy;
            }
            if ((vectorarr[j].x + vectorarr[j].y) == (vectorarr[j + 1].x + vectorarr[j + 1].y))
            {
                if (vectorarr[j].x > vectorarr[j + 1].x)
                {
                    int tempx = vectorarr[j].x;
                    int tempy = vectorarr[j].y;
                    vectorarr[j].x = vectorarr[j + 1].x;
                    vectorarr[j].y = vectorarr[j + 1].y;
                    vectorarr[j + 1].x = tempx;
                    vectorarr[j + 1].y = tempy;
                }
            }
        }
    }
    if(k>n)
    {
        cout << vectorarr[n-1].x << ' ' << vectorarr[n-1].y;
    }
    else if(k<1)
    {
        cout << vectorarr[0].x << ' ' << vectorarr[0].y;
    }
    else
    {
        cout << vectorarr[k-1].x << ' ' << vectorarr[k-1].y;
    }
    delete[] vectorarr;
}