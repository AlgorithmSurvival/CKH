#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int MakeSum(const vector<short>& Arr)
{
    int Result = 0;
    for (int i = 0; i < Arr.size() - 1; i++)
    {
        Result += abs(Arr[i] - Arr[i + 1]);
    }
    return Result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<short> Arr;
    int Result = 0;

    for (int i = 0; i < N; i++)
    {
        int Input;
        cin >> Input;
        Arr.emplace_back(Input);
    }
    sort(Arr.begin(), Arr.end());

    do {
        int SumNum = MakeSum(Arr);
        if (Result <= SumNum)
        {
            Result = SumNum;
        }
    } while (next_permutation(Arr.begin(), Arr.end()));

    cout << Result;
    return 0;
}
