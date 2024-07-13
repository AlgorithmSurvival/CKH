#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
static constexpr int MAX = 10000001;

bool Movable(const vector<vector<int>>& Distances, const vector<int>& PermutationVec, const int N)
{
    for (int i = 0; i < N; i++)
    {
        if (PermutationVec[i] == i)
        {
            return 0;
        }

        if (Distances[PermutationVec[i]][i] == 0)
        {
            return 0;
        }
    }

    vector<bool> Check(N, 0);
    int Next = PermutationVec[0];
    for (int i = 0; i < N; i++)
    {
        Next = PermutationVec[Next];
        Check[Next] = true;
    }
    for (int i = 0; i < N; i++)
    {
        if (!Check[i])
        {
            return 0;
        }
    }

    return 1;
}

int Sum(const vector<vector<int>>& Distances, const vector<int>& PermutationVec, const int N)
{
    int OutSum = 0;
    for (int i = 0; i < N; i++)
    {
        OutSum += Distances[PermutationVec[i]][i];
    }

    return OutSum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<vector<int>> Distances(N, vector<int>(N, 0));
    vector<int> PermutationVec(N, 0);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int Input;
            cin >> Input;
            Distances[i][j] = Input;
        }
    }
    for (int i = 0; i < N; i++)
    {
        PermutationVec[i] = i;
    }

    int Result = MAX;
    do
    {
        if (Movable(Distances, PermutationVec, N))
        {
            int TempSum = Sum(Distances, PermutationVec, N);
            if (TempSum < Result)
            {
                Result = TempSum;
            }
        }
    } while (next_permutation(PermutationVec.begin(), PermutationVec.end()));

    cout << Result;

    return 0;
}