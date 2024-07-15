#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
constexpr int MAX_RANGE = 100001;

int Bfs(vector<bool>& VisitVec, queue<int>& Queue, const int &K, const int &N)
{
    int Result = 0;
    while (true)
    {
        queue<int> TempQueue;
        while (!Queue.empty())
        {
            int CurrentPoint = Queue.front();
            Queue.pop();

            if (CurrentPoint == K)
            {
                return Result;
            }


            if (CurrentPoint == 0)
            {
                TempQueue.push(CurrentPoint + 1);
                VisitVec[CurrentPoint + 1] = true;
            }
            else
            {
                if (CurrentPoint * 2 < MAX_RANGE && !VisitVec[CurrentPoint * 2])
                {
                    TempQueue.push(CurrentPoint * 2);
                    VisitVec[CurrentPoint * 2] = true;
                }
                if (CurrentPoint + 1 < MAX_RANGE && !VisitVec[CurrentPoint + 1])
                {
                    TempQueue.push(CurrentPoint + 1);
                    VisitVec[CurrentPoint + 1] = true;
                }
                if (CurrentPoint - 1 >= 0 && !VisitVec[CurrentPoint - 1])
                {
                    TempQueue.push(CurrentPoint - 1);
                    VisitVec[CurrentPoint - 1] = true;
                }
            }
        }
        Queue = TempQueue;
        Result++;
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    vector<bool> VisitVec(MAX_RANGE, 0);
    queue<int> Queue;
    Queue.push(N);


    cout << Bfs(VisitVec, Queue, K, N);
    
    return 0;
}
