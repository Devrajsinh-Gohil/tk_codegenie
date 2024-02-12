#include <iostream>
#include <chrono>
#include "solution.h"

using namespace std;

int main()
{
    Solution solution;

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<string> words;
    cout << "Enter the strings separated by space: ";
    string temp;
    for(int i=0;i<n;i++){
        cin >> temp;
        words.push_back(temp);
    }

    // to calculate start time of execution
    auto start = chrono::high_resolution_clock::now();

    // executing function
    int pairs  = solution.studentWordPlayChallenge(words);

    // to calculate end time of execution
    auto end = chrono::high_resolution_clock::now();

    // to calculate duration of executeion
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    // print exectuion time
    cout << "Elapsed time: " << duration.count() << " microseconds" << endl;

    // print result
    cout << pairs << endl;
    
    return 0;
}