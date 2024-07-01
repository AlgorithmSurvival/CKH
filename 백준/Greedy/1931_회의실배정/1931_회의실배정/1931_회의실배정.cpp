#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using Data = vector<pair<int, int>>;

bool Compare(pair<int, int> InFirst, pair<int, int> InSecond)
{
    if (InFirst.second == InSecond.second)
    {
        return InFirst.first < InSecond.first;
    }
    return InFirst.second < InSecond.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Data Times;
    int Result = 0;
    int CurrentIndex = 0;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int Start, End;
        cin >> Start >> End;
        Times.emplace_back(Start, End);
    }
    sort(Times.begin(), Times.end(), Compare);

    for (const auto Time : Times)
    {
        if (Time.first >= CurrentIndex)
        {
            Result++;
            CurrentIndex = Time.second;
        }
    }

    cout << Result;
    return 0;
}

