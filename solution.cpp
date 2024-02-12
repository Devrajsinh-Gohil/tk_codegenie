#include <iostream>
#include <vector>
#include <tgmath.h>
#include "solution.h"
using namespace std;



/**
 * @brief ``guessTheNumber`` function to calculate the number based on the given operations
 * 
 * @param n 
 * @param operationSequence 
 * @return int 
 */

int Solution::guessTheNumber(int n, vector<string> operationSequence)
{
    // initalizing data structure and variables
    vector<pair<char, int>> mp;
        //  getting total operations
    int len = operationSequence.size(), ans = n;

    // seprating operation and number from the expression
    for (int i = 0; i < len; i++)
    {
        mp.push_back({operationSequence[i][2], stoi(operationSequence[i].substr(4))});
    }

    // getting the operations in reverse order
    reverse(mp.begin(), mp.end());

    // applying inverse operations to the final number to get inital number and checking anomalies in operations
    for (auto i : mp)
    {
        float p;
        switch (i.first)
        {
        case '%':
            return -2;
            break;
        case '*':
            if (i.second == 0)
                return -2;
            ans /= i.second;
            break;
        case '^':
            if (i.second == 0)
                return -2;
            p = 1.0 / i.second;
            ans = pow(ans, p);
            break;
        case '/':
            if (i.second == 0)
                return -1;
            ans *= i.second;
            break;
        case '+':
            ans -= i.second;
            break;
        case '-':
            ans += i.second;
            break;
        }
    }

    // return the initial number
    return ans;
}

/**
 * @brief ``urbanPlanningChallenge`` function to check if the two parks are overlapping or not.
 * 
 * @param park1 
 * @param park2 
 * @param park1Radius 
 * @param park2Radius 
 * @return bool 
 */

bool Solution::urbanPlanningChallenge(pair<int,int> park1, pair<int,int> park2, int park1Radius, int park2Radius){

    // seprating varibales
    int x1 = park1.first;
    int y1 = park1.second;
    int x2 = park2.first;
    int y2 = park2.second;
    int r1 = park1Radius;
    int r2 = park2Radius;

    // calculating euclidean distance between the centers of circle
    int d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    // if distance between center greater than or equal to sum of radii then there is no overlap else parks will overlap.
    if (d >= r1 + r2)
        return false;
    else
        return true;
}

/**
 * @brief ``studentWordPlayChallenge`` give the number of anagram pairs in given string vector
 * @param input 
 * @return int 
 */

int Solution::studentWordPlayChallenge(vector<string> input){
    // variables and data structures initializations
    vector<string> words(input.begin(),input.end());
    unordered_map<string,int> mp;
    int ans=0, cnt;

    // sorting each word so all anagrams become same, and counting their frequencies using unordered map
    for(string i:words){
        sort(i.begin(),i.end());
        mp[i]++;
    }

    //  adding combinations to ans to get all possible pair using tgamma function to find factorial
    for(auto i:mp){
        cnt = i.second;
        if(cnt>1) ans+=(tgamma(cnt+1)/(tgamma(cnt-2+1)*2));
    }

    // return total pairs of anagram
    return ans;
}