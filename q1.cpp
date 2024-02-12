#include <iostream>
#include <chrono>
#include "solution.h"

using namespace std;

int main( int argc, char const *argv[])
{
    // solution object
    Solution solution;

    // predefined teast cases;

    // vector<string> operations{"x + 10", "x - 5", "x * 5", "x ^ 2"};
    // int n = 2500;
    // vector<string> operations{"x * 5", "x / 0", "x ^ 3"};
    // int n = 1000;
    // vector<string> operations{"x * 5", "x * 0", "x + 10"};
    // int n = 10;
    // vector<string> operations{"x + 5", "x - 0", "x + 1", "x / 2", "x ^ 1"};
    // int n = 617283948;


    // custom test cases
    // for custom test case use: ./q1 n "exp1" "exp2" ......
    vector<string> operations;
    int n = stoi(argv[1]);

    for(int i= 2; i < argc; i++){
        operations.push_back(argv[i]);
    }
    

    // to calculate start time of execution  
    auto start = chrono::high_resolution_clock::now();

    // executing function
    int initialX = solution.guessTheNumber(n, operations);

    // to calculate end time of execution  
    auto end = chrono::high_resolution_clock::now();

    // to calculate duration of executeion
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    // print exectuion time
    cout << "Elapsed time: " << duration.count() << " microseconds" << endl;
    cout << initialX << endl;
    return 0;
}