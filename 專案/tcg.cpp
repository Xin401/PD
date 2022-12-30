#include <iostream>
using namespace std;

const int MINn = 1;
const int MAXn = 50;
const int MINm = 1;
const int MAXm = 1000;
const int MINc = 1;
const int MAXc = 10;
const int MINs = 1;
const int MAXs = 2;
const int MINx = 0;
const int MAXx = 200;
const int MINy = 0;
const int MAXy = 200;
const int MINu = 0;
const int MAXu = 200;
const int MINv = 0;
const int MAXv = 200;
const int MIND = 1;
const int MAXD = 1000;
const int MINf = 1;
const int MAXf = 1e6;
const int MINp = 1;
const int MAXp = 500;
const int MINh = 1;
const int MAXh = 1e7;
const int MINK = 1;
const int MAXK = 1e5;

const int MINtest = 1;
const int MAXtest = 25;

const int S[MAXtest] = {
        1,   1,   1,   1,   1,
        1,   1,   1,   1,   1,
        2,   2,   2,   2,   2,
        2,   2,   2,   2,   2,
        1,   1,   2,   2,   2
};
const int N[MAXtest] = {
        1,   2,   3,   4,   5,
       10,  15,  20,  30,  40,
        2,   3,   5,   7,   9,
       10,  15,  20,  30,  40,
       50,  50,  50,  50,  50
};
const int M[MAXtest] = {
       5,  10,  30,  60, 100,
     200, 400, 600, 800,1000,
       5,  10,  30,  60, 100,
     200, 400, 600, 800, 987,
    1000,1000,1000,1000,1000
};
const int C[MAXtest] = {
        2, 1, 1, 1, 1,
        1, 2, 1, 1, 1,
        1, 1, 2, 1, 1,
        1, 1, 1, 2, 1,
        1, 1, 1, 1, 2
};
long long int magicNumber = 0;
const long long int BASE = 8705029; // Randomly pick a prime number
const long long int MOD = 1e11 + 3; // Yet another prime number
const long long int OFFSET =
( static_cast<long long int>('I')
+ static_cast<long long int>(' ')
+ static_cast<long long int>('<')
+ static_cast<long long int>('3')
+ static_cast<long long int>(' ')
+ static_cast<long long int>('P')
+ static_cast<long long int>('r')
+ static_cast<long long int>('o')
+ static_cast<long long int>('g')
+ static_cast<long long int>('r')
+ static_cast<long long int>('a')
+ static_cast<long long int>('m')
+ static_cast<long long int>('m')
+ static_cast<long long int>('i')
+ static_cast<long long int>('n')
+ static_cast<long long int>('g')
+ static_cast<long long int>(' ')
+ static_cast<long long int>('D')
+ static_cast<long long int>('e')
+ static_cast<long long int>('s')
+ static_cast<long long int>('i')
+ static_cast<long long int>('g')
+ static_cast<long long int>('n')
+ static_cast<long long int>('!')
)
*
( static_cast<long long int>('R')
+ static_cast<long long int>('o')
+ static_cast<long long int>('c')
+ static_cast<long long int>('k')
+ static_cast<long long int>(' ')
+ static_cast<long long int>('&')
+ static_cast<long long int>(' ')
+ static_cast<long long int>('r')
+ static_cast<long long int>('r')
+ static_cast<long long int>('r')
+ static_cast<long long int>('o')
);

// As its name indicates, this function terminates the process with function call
void byebye(){
    cout << "Generator terminated." << endl;
    exit(-1); // exit(-1) terminates the whole process abnormally and unconditionally
}

// RNG is the abbreviation of "Random Number Generator"
long long int naiveRNG(long long int l, long long int r){
    if (r < l) {
        cout << "Error: In naiveRNG, ";
        cout << "the lower bound should not be greater than the upper bound.\n";
        byebye();
    }
    magicNumber %= MOD;
    magicNumber = (BASE * magicNumber + OFFSET) % MOD;
    return magicNumber % (r - l + 1) + l;
}

void printSeperator(){
    for (int i = 0; i < 20; i++)
        cout << "=";
    cout << '\n';
    cout.flush();
}
void printSampleTestCase(){
    cout << "2 6 1 1\n";
    cout << "2 2 4 5\n";
    cout << "1 1 1 2 2 5 3 1 7 1 8 4\n";
    cout << "3 4 5 6 7 8\n";
    cout << "5 5 5 3 3 3\n";
    cout << "10 8 7 9 9 9\n";
    cout << "20 20\n";
    cout << "50 50\n";
    cout.flush();
}

void generator(int n, int m, int c, int s){
    // first line
    cout << n << ' ' << m << ' ' << c << ' ' << s << '\n';
    
    // second line
    for (int i = 0; i < n; i++)
        cout << naiveRNG(MINu, MAXu) << ' ' << naiveRNG(MINv, MAXv) << " \n"[i == n - 1];
    
    // third line
    for (int i = 0; i < m; i++)
        cout << naiveRNG(MINx, MAXx) << ' ' << naiveRNG(MINy, MAXy) << " \n"[i == m - 1];

    // 4th line
    for (int i = 0; i < m; i++)
        cout << naiveRNG(MIND, MAXD) << " \n"[i == m - 1];

    // 5th line
    for (int i = 0; i < m; i++)
        cout << naiveRNG(MINf, MAXf) << " \n"[i == m - 1];

    // 6th line
    for (int i = 0; i < m; i++)
        cout << naiveRNG(MINp, MAXp) << " \n"[i == m - 1];

    // 7th line
    for (int i = 0; i < n; i++)
        cout << naiveRNG(MINh, MAXh) << " \n"[i == n - 1];

    // 8th line
    for (int i = 0; i < n; i++)
        cout << naiveRNG(MINK, MAXK) << " \n"[i == n - 1];

    cout.flush();
}

int main(){

    /* interaction begin */
    cout << " _________________________________________\n/ Welcome to PD Midterm Project Test Case \\\n\\ Generator.                              /\n -----------------------------------------\n        \\   ^__^\n         \\  (oo)\\_______\n            (__)\\       )\\/\\\n                ||----w |\n                ||     ||\n\n";
    cout << "Let\'s begin with choosing a lucky number!\n";
    cout << "Please enter your lucky number (integer between 0 and 10^11): ";
    cout.flush();
    /* interaction end */

    char spell[100];
    cin >> spell;
    magicNumber = 0;
    for (int i = 0; spell[i]; i++)
        magicNumber = magicNumber * static_cast<long long>(10) + (spell[i] - '0');
    
    /* interaction begin */
    cout << endl;
    /* interaction end */

    if (magicNumber < 0 || magicNumber > static_cast<long long int>(1e11)){

        /* interation begin */
        cout << "Invalid lucky number.\n";
        cout << "Your lucky number are supposed to be between 0 and 10^11.\n";
        /* interaction end */

        byebye();
    }

    /* interaction begin */
    cout << "Please enter a character, specifying the type of test case you would like.";
    cout << endl;
    cout << "(\'S\' for Sample Test Case; \'H\' for Hidden Test Case Simulation)";
    cout << endl;
    cout << "Enter your character: ";
    cout.flush();
    /* interation end */

    char testCaseProperty = 'a';
    cin >> testCaseProperty;
    
    /* interaction begin */
    cout << endl;
    /* interaction end */
    
    if (testCaseProperty != 'S' && testCaseProperty != 'H'){
        
        /* interaction begin */
        cout << "Invalid test case property.\n";
        cout << "More specifically, ";
        cout << "it should be either \'S\' or \'H\' rather than your input: \'";
        cout << testCaseProperty;
        cout << "\'.\n";
        cout.flush();
        /* interaction end */
        
        byebye();
    }
    else if (testCaseProperty == 'S'){
        
        /* interaction begin */
        cout << "Here is your test case. Enjoy!\n";
        printSeperator();
        cout.flush();
        /* interaction end */
        
        printSampleTestCase();
    }
    else if (testCaseProperty == 'H'){
        
        /* interaction begin */
        cout << "Would you like to customize your n, m, c and s? [Y/n]: ";
        cout.flush();
        /* interaction end */
        
        char cmd = 'a';
        cin >> cmd;
        
        /* interaction begin */
        cout << endl;
        /* interaction end */
        
        int n, m, c, s;
        if (cmd != 'Y' && cmd != 'n') {
            
            /* interaction begin */
            cout << "Invalid Customization Request.\n";
            cout << "More specifically, ";
            cout << "it should be either \'Y\' or \'n\' rather than your input: \'";
            cout << cmd;
            cout << "\'.\n";
            cout.flush();
            /* interaction end */
            
            byebye();
        }
        else if (cmd == 'Y'){
            
            /* interaction begin */
            cout << "Please specify your n, m, c, s:\n";
            cout << "n = ";
            cout.flush();
            /* interaction end */
            
            cin >> n;
            
            /* interaction begin */
            cout << "m = ";
            cout.flush();
            /* interaction end */

            cin >> m;

            /* interaction begin */
            cout << "c = ";
            cout.flush();
            /* interaction end */

            cin >> c;

            /* interaction begin */
            cout << "s = ";
            cout.flush();
            /* interaction end */

            cin >> s;

            if (n < MINn || n > MAXn || 
                m < MINm || m > MAXm ||
                c < MINc || c > MAXc ||
                s < MINs || s > MAXs  ){
                
                /* interaction begin */
                cout << "Invalid n, m, c, s. Check the spec carefully.\n";
                cout.flush();
                /* interaction end */

                byebye();
            }

            /* interaction begin */
            cout << endl;
            /* interaction end */
        }
        else {
            int level = 0;

            /* interaction begin */
            cout << "Please enter the challenge level of test case you would like. (1-25): ";
            cout.flush();
            /* interaction end */

            cin >> level;
            
            /* interaction begin */
            cout << endl;
            /* interaction end */

            if (level < MINtest || level > MAXtest){
                
                /* interaction begin */
                cout << "Invalid level, it is supposed to be between 1 to 25.\n";
                cout.flush();
                /* interaction end */

                byebye();
            }

            level--;
            
            n = N[level];
            m = M[level];
            c = C[level];
            s = S[level];
        }

        /* interaction begin */
        cout << "Here is your test case. Enjoy!\n";
        printSeperator();
        cout.flush();
        /* interaction end */

        generator(n, m, c, s);
    }
    return 0;
}