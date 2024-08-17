#include <iostream>
#include <vector>
using namespace std;
using SaveType = vector<vector<vector<int>>>;

int Dp(const int& N, const int& M, const int& K, const vector<int>& Dy, const vector<int>& Dx,
    const string& Word, const vector<vector<char>>& Grid, const int CurrentY, const int CurrentX,
    int Index, SaveType &Save)
{
    if (Index == Word.length() - 1)
    {
        if (Grid[CurrentY][CurrentX] == Word[Index])
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    if (Save[CurrentY][CurrentX][Index] == -1)
    {
        int Sum = 0;

        int Range = K * 4;
        for (int i = 0; i < Range; i++)
        {
            if (CurrentY + Dy[i] >= 0 && CurrentY + Dy[i] < N && CurrentX + Dx[i] >= 0 && CurrentX + Dx[i] < M)
            {
                if (Grid[CurrentY + Dy[i]][CurrentX + Dx[i]] == Word[Index + 1])
                {
                    Sum += Dp(N, M, K, Dy, Dx, Word, Grid, CurrentY + Dy[i], CurrentX + Dx[i], Index + 1, Save);
                }
            }
        }

        Save[CurrentY][CurrentX][Index] = Sum;
    }

    return Save[CurrentY][CurrentX][Index];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<char>> Grid(N, vector<char>(M, ' '));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char Input;
            cin >> Input;

            Grid[i][j] = Input;
        }
    }

    string Word;
    cin >> Word;

    vector<int> Dy = { -1, 1, 0, 0, -2, 2, 0, 0, -3, 3, 0, 0, -4, 4, 0, 0, -5, 5, 0 , 0 };
    vector<int> Dx = { 0, 0, -1, 1, 0, 0, -2, 2, 0, 0, -3, 3, 0, 0, -4, 4, 0, 0, -5, 5 };

    SaveType Save(N, vector<vector<int>>(M, vector<int>(Word.length(), -1))); //-1이면 미탐색.

    int Result = 0;

    //첫글자 서치.
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (Word[0] == Grid[i][j])
            {
                Result += Dp(N, M, K, Dy, Dx, Word, Grid, i, j, 0, Save);
            }
        }
    }

    cout << Result;
    return 0;
}