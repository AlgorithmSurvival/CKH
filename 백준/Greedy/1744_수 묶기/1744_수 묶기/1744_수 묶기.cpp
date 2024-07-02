#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void MinusProcess(deque<int>& MinusVec, int& Result)
{
    while (MinusVec.size() > 1) //1개이하가 남을 때까지 시행. -> 2개 이상을 보장
    {
        int Min = *MinusVec.begin();
        MinusVec.pop_front();
        int NextMin = *MinusVec.begin();
        MinusVec.pop_front();

        Result += Min * NextMin;
    }
    if (!MinusVec.empty())
    {
        Result += MinusVec[0]; //마지막 값은 그냥 더해주기.
    }

    return;
}

void PlusProcess(deque<int> &PlusVec, int &Result)
{
    while (PlusVec.size() > 1)
    {
        int Max = *(PlusVec.end() - 1);
        PlusVec.pop_back();
        int NextMax = *(PlusVec.end() - 1);
        PlusVec.pop_back();

        if (Max == 1 || NextMax == 1)
        {
            Result += Max + NextMax;
        }
        else
        {
            Result += Max * NextMax;
        }
    }
    if (!PlusVec.empty())
    {
        Result += PlusVec[0];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    deque<int> MinusVec;
    deque<int> PlusVec;
    int Result = 0;
    
    for (int i = 0; i < N; i++)
    {
        int Input;
        cin >> Input;
        if (Input <= 0)
        {
            MinusVec.emplace_back(Input);
        }
        else
        {
            PlusVec.emplace_back(Input);
        }
    }
    sort(MinusVec.begin(), MinusVec.end());
    sort(PlusVec.begin(), PlusVec.end());
    
    //음수
    MinusProcess(MinusVec, Result);

    //양수
    PlusProcess(PlusVec, Result);
    
    cout << Result;
    return 0;
}
