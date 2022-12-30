#include <iostream>
using namespace std;

struct Time
{
    int hour;
    int minute;
    int second;
    void setTime(int h, int m, int s);
    bool isEarlierThan(Time t);
    void print();
    void printNicely();
    void printTwoDigits(int n);
};

void Time::setTime(int h, int m, int s)
{
    hour = h;
    minute = m;
    second = s;
}
void Time::printTwoDigits(int n)
{
  cout << (n < 10 ? "0" : "") << n;
}
void Time::printNicely()
{
  printTwoDigits(hour);
  cout << ":"; 
  printTwoDigits(minute); 
  cout << ":"; 
  printTwoDigits(second);
}

bool Time::isEarlierThan(Time t)
{
    int mySec = hour * 3600 + minute * 60 + second;
    int itsSec = t.hour * 3600 + t.minute * 60 + t.second;
    if (mySec < itsSec)
        return true;
    else
        return false;
}

int main()
{
    int max = 0;
    Time time[3];
    for (int i = 0;i<3;i++)
    {
        int h = 0, m = 0, s = 0;
        cin >> h >> m >> s;
        time[i].setTime(h,m,s);    
    }
    max = time[0].isEarlierThan(time[1]) ? 1:0;
    max = time[max].isEarlierThan(time[2])? 2:max;
    time[max].printNicely();
}