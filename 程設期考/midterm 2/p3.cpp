#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    int count = 0;
    cin >> n;
    int **graph = new int *[n];
    int *length = new int[n];
    int *isPaint = new int[n];
    for (int i = 0; i < n; i++)
    {
        length[i] = 0;
        isPaint[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        graph[i] = new int[n - 1];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            graph[i][j] = -1;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a = 0, b = 0;
        cin >> a >> b;
        for (int j = 0; j < n - 1; j++)
        {
            if (graph[a - 1][j] == -1)
            {
                graph[a - 1][j] = b - 1;
                break;
            }
        }
        for (int j = 0; j < n - 1; j++)
        {
            if (graph[b - 1][j] == -1)
            {
                graph[b - 1][j] = a - 1;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (graph[i][j] != -1)
            {
                length[i]++;
            }
            else
            {
                break;
            }
        }
    }
    bool isSatis = false;
    while (!isSatis)
    {
        // 編號,長度
        int max[2] = {0, length[0]};
        // find one to print
        for (int i = 0; i < n; i++)
        {
            if (length[i] > max[1])
            {
                max[1] = length[i];
                max[0] = i;
            }
        }
        for (int i = 0; i < length[max[0]]; i++)
        {
            isPaint[graph[max[0]][i]] = 1;
            length[graph[max[0]][i]]--;
            for (int j = 0; j < length[graph[max[0]][i]]; j++)
            {
                length[graph[graph[max[0]][i]][j]+1]--;
            }
        }
        isPaint[max[0]] = 1;
        length[max[0]] = 0;
        for (int i = 0; i < n; i++)
        {
            if (isPaint[i] != 1)
            {
                break;
            }
            if (isPaint[i] == 1 && i == n - 1)
            {
                isSatis = true;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (length[i] > 0)
            {
                break;
            }
            if (length[i] <= 0 && i == n - 1)
            {
                isSatis = true;
            }
        }
        count++;
    }

    cout << count;
    for (int i = 0; i < n; i++)
    {
        delete[] graph[i];
    }
    delete[] graph;
    delete[] length;
    delete[] isPaint;
}