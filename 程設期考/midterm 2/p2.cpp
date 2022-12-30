#include <iostream>
#include <cstring>

using namespace std;
int main()
{
    char string[5];
    cin.getline(string, 5);
    int number = atoi(string);
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == '0' && i != 0)
        {
            number -= static_cast<int>(string[i - 1] - '0');
        }
        if (string[i] == '1' && i != strlen(string) - 1)
        {
            number += static_cast<int>(string[i + 1] - '0');
        }
    }
    cout << number;
}