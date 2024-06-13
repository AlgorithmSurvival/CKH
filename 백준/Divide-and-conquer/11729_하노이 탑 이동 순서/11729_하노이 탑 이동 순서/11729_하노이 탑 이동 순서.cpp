#include <iostream>
#include <vector>
using namespace std;
using Process = vector<pair<int, int>>;

void Hanoi(int N, int CurrentNum, int MiddleNum, int DestNum, int &Result, Process &Point)
{
    if (N != 1)
    {
        Hanoi(N - 1, CurrentNum, DestNum, MiddleNum, Result, Point);
        Point.emplace_back(CurrentNum, DestNum);
        Result++;
        Hanoi(N - 1, MiddleNum, CurrentNum, DestNum, Result, Point);
    }
    else
    {
        Point.emplace_back(CurrentNum, DestNum);
        Result++;
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    int Result = 0;
    Process Point;

    Hanoi(N, 1, 2, 3, Result, Point);

    cout << Result << '\n';
    for (int i = 0; i < Point.size(); i++)
    {
        cout << Point[i].first << " " << Point[i].second << '\n';
    }

    return 0;
}