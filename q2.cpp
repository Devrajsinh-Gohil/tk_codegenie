#include <iostream>
#include <chrono>
#include "solution.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Solution solution;

    // predefined testcase
    // ---------------------
    // pair<int,int>park1{5,10};
    // pair<int,int>park2{20,10};
    // int park1Radius = 15;
    // int park2Radius = 10;

    // pair<int,int>park1{0,0};
    // pair<int,int>park2{20,20};
    // int park1Radius = 10;
    // int park2Radius = 5;
    // ----------------------

    // custom test cases
    // for custom test case use: ./q1 x1 y1 x2 y2 r1 r2
    pair<int, int> park1{stoi(argv[1]), stoi(argv[2])};
    pair<int, int> park2{stoi(argv[3]), stoi(argv[4])};
    int park1Radius = stoi(argv[5]);
    int park2Radius = stoi(argv[6]);

    // to calculate start time of execution    
    auto start = chrono::high_resolution_clock::now();

    // executing function
    bool isOverlapping = solution.urbanPlanningChallenge(park1, park2, park1Radius, park2Radius);

    // to calculate end time of execution  
    auto end = chrono::high_resolution_clock::now();
    
    // to calculate duration of executeion
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    // print exectuion time
    cout << "Elapsed time: " << duration.count() << " microseconds" << endl;
    
    // print result
    cout << ((isOverlapping) ? "true" : "false") << endl;

    return 0;
}