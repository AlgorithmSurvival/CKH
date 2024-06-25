#include <iostream>
#include <vector>
using namespace std;
using Grid = vector<vector<bool>>;

void MakePattern(Grid& Arr, int Y, int X, int N)
{
    if (N <= 3)
    {
        //위
        Arr[Y][X] = 1;
        //중간
        Arr[Y + 1][X - 1] = 1;
        Arr[Y + 1][X] = 0;
        Arr[Y + 1][X + 1] = 1;
        //아래
        for (int i = -2; i < 3; i++)
        {
            Arr[Y + 2][X + i] = 1;
        }
        return;
    }

    int NextN = N / 2;
    //위
    MakePattern(Arr, Y, X, NextN);

    //왼쪽
    MakePattern(Arr, Y + NextN, X - NextN, NextN);

    //오른쪽
    MakePattern(Arr, Y + NextN, X + NextN, NextN);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   
    int N;
    cin >> N;
    int Size = N * 2 - 1;

    Grid Arr = Grid(N , vector<bool>(Size , 0));

    MakePattern(Arr, 0, N - 1, N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < Size; j++)
        {
            if (Arr[i][j] == 1)
            {
                cout << '*';
            }
            else
            {
                cout << ' ';
            }
        }
        cout << '\n';
    }
}

