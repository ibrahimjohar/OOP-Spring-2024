#include <iostream>
using namespace std;

inline double battingAvg(int totalRuns, int nOuts)
{
    if (nOuts == 0)
    {
        return 0;
    }
    double batAvg;
    batAvg = static_cast<double>(totalRuns) / nOuts;
    return batAvg;
}

inline double strikeRate(int totalRuns, int nBalls)
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
