#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;


void Bfs(queue<string>& PuzzleQueue, const string &Answer, set<string> &Visited)
{
    vector<int> Y = { 1, -1, 0, 0 };
    vector<int> X = { 0, 0, -1, 1 };
    
    int Count = 0;
    while (true)
    {
        queue<string> TempQueue;
        while (!PuzzleQueue.empty())
        {
            string Current = PuzzleQueue.front();
            PuzzleQueue.pop();

            if (Current == Answer)
            {
                cout << Count;
                return;
            }

            int ZeroPos = Current.find('0');
            for (int i = 0; i < 4; i++)
            {
                int YPos = ZeroPos / 3 + Y[i];
                int XPos = ZeroPos % 3 + X[i];

                if (YPos >= 0 && YPos <= 2 && XPos >= 0 && XPos <= 2)
                {
                    string PushString = Current;
                    swap(PushString[ZeroPos], PushString[YPos * 3 + XPos]);
                    if (Visited.find(PushString) == Visited.end())
                    {
                        Visited.insert(PushString);
                        TempQueue.push(PushString);
                    }

                }

            }
        }
        Count++;
        if (TempQueue.empty())
        {
            cout << -1;
            return;
        }
        else
        {
            PuzzleQueue = TempQueue;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string Answer = "123456780";
    string Input = "";

    for (int i = 0; i < 9; i++)
    {
        char TempInput;
        cin >> TempInput;
        Input += TempInput;
    }
    
    queue<string> PuzzleQueue;
    set<string> Visited;
    PuzzleQueue.push(Input);
    Visited.insert(Input);

    Bfs(PuzzleQueue, Answer, Visited);

    return 0;
}