/*
*   Programmer: Ibrahim Johar Farooqi (23K-0074)
*   Date: 17 March 2024
*   Description: You have been asked to write a program that calculates the batting average and strike rate for a cricket player. The program should take as input the total number of runs scored by the player 
*                and the total number of balls faced, and should output the batting average and strike rate. To calculate the batting average, divide the total runs scored by the number of times
*                the player has been dismissed (i.e., gotten out). To calculate the strike rate, divide the total runs scored by the total number of balls faced and multiply the result by 100.
*                To implement this program, create an inline function that takes the total number of runs scored and the number of times the player has been dismissed as arguments,
*                and returns the batting average. Create another inline function that takes the total number of runs scored and the total number of balls faced as arguments, and returns
*                the strike rate. Demonstrate the functions using main function
*/

#include <iostream>
using namespace std;

inline double battingAvg(int totalRuns, int nOuts) //inline function for calculating batting average
{
    if (nOuts == 0)
    {
        return 0;
    }
    double batAvg;
    batAvg = static_cast<double>(totalRuns) / nOuts;
    return batAvg;
}

inline double strikeRate(int totalRuns, int nBalls) //inline function for calculating strikerate
{
    if (nBalls == 0)
    {
        return 0;
    }
    double strikeRate;
    strikeRate = (static_cast<double>(totalRuns) / nBalls) * 100.0; 
    return strikeRate;
}

int main()
{
    int totalRuns, nBalls, nOuts;
    double strikeRateValue, battingAverage;

    cout << "Enter Total Runs scored by batsman: ";
    cin >> totalRuns;
    cout << "Enter Total number of balls faced by batsman: ";
    cin >> nBalls;
    cout << "Enter Total number of times the batsman has been dismissed: ";
    cin >> nOuts;

    battingAverage = battingAvg(totalRuns, nOuts);
    strikeRateValue = strikeRate(totalRuns, nBalls);

    cout << "\nBatsman's Strike Rate: " << strikeRateValue << "\n";
    cout << "\nBatsman's Batting Average: " << battingAverage << "\n";

    return 0;
}
