#include <iostream>
#include <vector>
using namespace std;
using QuadTree = vector<vector<bool>>;

void Search(const QuadTree& Tree, int N, int X, int Y)
{
    int Value = Tree[Y][X];
    int EndY = Y + N;
    int EndX = X + N;

    for (int i = Y; i < EndY; i++)
    {
        for (int j = X; j < EndX; j++)
        {
            if (Value != Tree[i][j])
            {
                cout << "(";
                int NextN = N / 2;
                Search(Tree, NextN, X, Y);
                Search(Tree, NextN, X + NextN, Y);
                Search(Tree, NextN, X, Y + NextN);
                Search(Tree, NextN, X + NextN, Y + NextN);
                cout << ")";

                return;
            }
        }
    }
    cout << Value;
}

int main()
{
    int N;
    cin >> N;

    QuadTree Tree = QuadTree(N, vector<bool>(N, 0));

    for (int i = 0; i < N; i++)
    {
        string Input;
        cin >> Input;
        for (int j = 0; j < Input.size(); j++)
        {
            Tree[i][j] = Input[j] - 48;
        }
    }


    Search(Tree, N, 0, 0);

    return 0;
}

