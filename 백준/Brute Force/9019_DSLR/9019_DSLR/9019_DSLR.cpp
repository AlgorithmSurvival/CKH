#include <iostream>
#include <vector>
#include <queue>
using namespace std;

constexpr int MAX_RANGE = 10001;

int LeftRotate(const int Input)
{
    int TempInput = Input;
    int LeftOver = TempInput / 1000;
    TempInput %= 1000;
    TempInput *= 10;
    TempInput += LeftOver;

    return TempInput;

}
int RightRotate(const int Input)
{
    int TempInput = Input;
    int RightOver = TempInput % 10;
    TempInput /= 10;
    TempInput += RightOver * 1000;

    return TempInput;

}

void Bfs(const int& B, vector<bool>& Visited, queue<pair<int, string>> &DSLRQueue)
{

    while (!DSLRQueue.empty())
    {
        int CurrentNumber = DSLRQueue.front().first;
        string CurrentCommand = DSLRQueue.front().second;
        DSLRQueue.pop();

        if (CurrentNumber == B)
        {
            cout << CurrentCommand << '\n';
            return;
        }

        //분기
        if (!Visited[(CurrentNumber * 2) % 10000])
        {
            DSLRQueue.push(make_pair((CurrentNumber * 2) % 10000, CurrentCommand + "D"));
            Visited[(CurrentNumber * 2) % 10000] = true;
        }

        if (CurrentNumber <= 0 && !Visited[9999])
        {
            DSLRQueue.push(make_pair(9999, CurrentCommand + "S"));
            Visited[9999] = true;
        }
        else if(CurrentNumber - 1 >= 0 && !Visited[CurrentNumber - 1])
        {
            DSLRQueue.push(make_pair(CurrentNumber - 1, CurrentCommand + "S"));
            Visited[CurrentNumber - 1] = true;
        }

        int TempLeft = LeftRotate(CurrentNumber);
        if (!Visited[TempLeft])
        {
            DSLRQueue.push(make_pair(TempLeft, CurrentCommand + "L"));
            Visited[TempLeft] = true;
        }

        int TempRight = RightRotate(CurrentNumber);
        if (!Visited[TempRight])
        {
            DSLRQueue.push(make_pair(TempRight, CurrentCommand + "R"));
            Visited[TempRight] = true;
        }
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int A, B;
        cin >> A >> B;

        vector<bool> Visited(MAX_RANGE, 0);
        queue<pair<int, string>> DSLRQueue;
        DSLRQueue.push(make_pair(A, ""));
        Bfs(B, Visited, DSLRQueue);
        Visited[A] = true;
    }

    return 0;

}

