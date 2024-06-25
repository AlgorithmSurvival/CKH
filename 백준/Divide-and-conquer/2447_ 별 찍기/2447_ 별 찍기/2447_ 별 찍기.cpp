#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
using Grid = vector<vector<bool>>;

void MakePattern(Grid& MyGrid, int Y, int X, int N)
{
    if (N <= 1)
    {
        MyGrid[Y][X] = 1;
        return;
    }
    int NextN = N / 3;

    //위
    MakePattern(MyGrid, Y, X, NextN);
    MakePattern(MyGrid, Y, X + N / 3, NextN);
    MakePattern(MyGrid, Y, X + N / 3 * 2, NextN);

    //왼쪽 중간
    MakePattern(MyGrid, Y + N / 3, X, NextN);

    //중간
    for (int i = 0; i < NextN; i++)
    {
        for (int j = 0; j < NextN; j++)
        {
            MyGrid[Y + N / 3 + i][X + N / 3 + j] = 0;
        }
    }

    //오른쪽 중간
    MakePattern(MyGrid, Y + N / 3, X + N / 3 * 2, NextN);

    //아래
    MakePattern(MyGrid, Y + N / 3 * 2, X, NextN);
    MakePattern(MyGrid, Y + N / 3 * 2, X + N / 3, NextN);
    MakePattern(MyGrid, Y + N / 3 * 2, X + N / 3 * 2, NextN);


    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    Grid MyGrid(N , vector<bool>(N , 0));

    MakePattern(MyGrid, 0, 0, N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (MyGrid[i][j])
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


    return 0;
}


