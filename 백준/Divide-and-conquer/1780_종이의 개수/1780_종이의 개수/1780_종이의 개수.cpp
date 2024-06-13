#include <iostream>
#include <vector>
using namespace std;
using Matrix = vector<vector<int>>;


void Search(const Matrix& Arr, int N, int Y, int X, int &PlusOne,int &Zero, int& MinusOne)
{
    int CheckNum = Arr[Y][X]; //기준점이 될 숫자

    int YEnd = Y + N;
    int XEnd = X + N;
    for (int i = Y; i < YEnd; i++)
    {
        for (int j = X; j < XEnd; j++)
        {
            if (CheckNum != Arr[i][j])
            {
                Search(Arr, N / 3, Y, X, PlusOne, Zero, MinusOne);
                Search(Arr, N / 3, Y, X + N / 3, PlusOne, Zero, MinusOne);
                Search(Arr, N / 3, Y, X + N / 3 * 2, PlusOne, Zero, MinusOne);

                Search(Arr, N / 3, Y + N / 3, X, PlusOne, Zero, MinusOne);
                Search(Arr, N / 3, Y + N / 3, X + N / 3, PlusOne, Zero, MinusOne);
                Search(Arr, N / 3, Y + N / 3, X + N / 3 * 2, PlusOne, Zero, MinusOne);

                Search(Arr, N / 3, Y + N / 3 * 2, X, PlusOne, Zero, MinusOne);
                Search(Arr, N / 3, Y + N / 3 * 2, X + N / 3, PlusOne, Zero, MinusOne);
                Search(Arr, N / 3, Y + N / 3 * 2, X + N / 3 * 2, PlusOne, Zero, MinusOne);

                return;
            }
        }
    }
    //모든 요소가 같음.
    if (CheckNum == -1)
    {
        MinusOne++;
    }
    else if (CheckNum == 1)
    {
        PlusOne++;
    }
    else
    {
        Zero++;
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

    Matrix Arr = Matrix(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int input;
            cin >> input;
            Arr[i][j] = input;
        }
    }
    int PlusOne = 0;
    int Zero = 0;
    int MinusOne = 0;

    Search(Arr, N, 0, 0, PlusOne, Zero, MinusOne);

    cout << MinusOne << '\n' << Zero << '\n' << PlusOne << '\n';

    return 0;
}


