#include <iostream>
#include <string>
using namespace std;

void bubbleSort(int unsorted[], int sorted[], int len);
bool jump(int sorted[], int len);
int main()
{
  int n = 0;
  cin >> n;
  int sorted[20] = {0};
  int unsorted[20] = {0};
  for (int i = 0; i < n; i++)
  {
    cin >> unsorted[i];
  }
  bubbleSort(unsorted, sorted, n);
  return 0;
}

void bubbleSort(int unsorted[], int sorted[], int len)
{
  int count = 0, circular = 0;
  for (int i = 0; i < len; i++)
  {
    sorted[i] = unsorted[i];
  }

  for (int i = len - 1; i > 0; i--) // here
  {
    circular++;
    if (jump(sorted, len))
      break;
    for (int j = 0; j < i; j++)
    {
      if (sorted[j] > sorted[j + 1])
      {
        int temp = sorted[j];
        sorted[j] = sorted[j + 1];
        sorted[j + 1] = temp;
        count++;
      }
    }
  }
  cout << count << "," << circular;
}

bool jump(int sorted[], int len)
{
  for (int k = 0; k < len - 1; k++)
  {
    if (sorted[k] > sorted[k + 1])
    {
      return false;
    }
  }
  return true;
}
