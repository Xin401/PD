#include <iostream>
#include <fstream>
#include <unistd.h>
using namespace std;

int main()
{
    chdir("/Users/xin/Desktop");
    ofstream myfile("test.txt");
    myfile << "555555" << endl;
    myfile.close();
    return 0;
}