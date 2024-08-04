#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool Check(int A, int B, int C, set<string>& Visited)
{
    string CurrentString;
    CurrentString = to_string(A) + to_string(B) + to_string(C);

    if (Visited.find(CurrentString) == Visited.end())
    {
        Visited.insert(CurrentString);
        return false;
    }
    else
    {
        return true;
    }
}

void Dfs(int A, int B, int C, set<string>& Visited, vector<int>& Answer, const int &AMax, const int &BMax, const int &CMax)
{
    if(A == 0)
    {
        Answer.emplace_back(C);
    }
    if (A != 0)
    {
        //A To B
        int ATemp = A;
        int BTemp = B;
        int CTemp = C;

        int BLeft = BMax - BTemp;

        if (ATemp >= BLeft)
        {
            ATemp -= BLeft;
            BTemp = BMax;
        }
        else
        {
            BTemp += ATemp;
            ATemp = 0;
        }

        bool IsVisit = Check(ATemp, BTemp, CTemp, Visited);
        if (!IsVisit)
        {
            Dfs(ATemp, BTemp, CTemp, Visited, Answer, AMax, BMax, CMax);
        }

        //A To C
        ATemp = A;
        BTemp = B;
        CTemp = C;

        int CLeft = CMax - CTemp;

        if (ATemp >= CLeft)
        {
            ATemp -= CLeft;
            CTemp = CMax;
        }
        else
        {
            CTemp += ATemp;
            ATemp = 0;
        }

        IsVisit = Check(ATemp, BTemp, CTemp, Visited);
        if (!IsVisit)
        {
            Dfs(ATemp, BTemp, CTemp, Visited, Answer, AMax, BMax, CMax);
        }

    }
    if (B != 0)
    {
        //B To A
        int ATemp = A;
        int BTemp = B;
        int CTemp = C;

        int ALeft = AMax - ATemp;

        if (BTemp >= ALeft)
        {
            BTemp -= ALeft;
            ATemp = AMax;
        }
        else
        {
            ATemp += BTemp;
            BTemp = 0;
        }

        bool IsVisit = Check(ATemp, BTemp, CTemp, Visited);
        if (!IsVisit)
        {
            Dfs(ATemp, BTemp, CTemp, Visited, Answer, AMax, BMax, CMax);
        }

        //B To C
        ATemp = A;
        BTemp = B;
        CTemp = C;

        int CLeft = CMax - CTemp;

        if (BTemp >= CLeft)
        {
            BTemp -= CLeft;
            CTemp = CMax;
        }
        else
        {
            CTemp += BTemp;
            BTemp = 0;
        }

        IsVisit = Check(ATemp, BTemp, CTemp, Visited);
        if (!IsVisit)
        {
            Dfs(ATemp, BTemp, CTemp, Visited, Answer, AMax, BMax, CMax);
        }
    }
    if (C != 0)
    {
        //C To A
        int ATemp = A;
        int BTemp = B;
        int CTemp = C;

        int ALeft = AMax - ATemp;

        if (CTemp >= ALeft)
        {
            CTemp -= ALeft;
            ATemp = AMax;
        }
        else
        {
            ATemp += CTemp;
            CTemp = 0;
        }

        bool IsVisit = Check(ATemp, BTemp, CTemp, Visited);
        if (!IsVisit)
        {
            Dfs(ATemp, BTemp, CTemp, Visited, Answer, AMax, BMax, CMax);
        }

        //C To B
        ATemp = A;
        BTemp = B;
        CTemp = C;

        int BLeft = BMax - BTemp;

        if (CTemp >= BLeft)
        {
            CTemp -= BLeft;
            BTemp = BMax;
        }
        else
        {
            BTemp += CTemp;
            CTemp = 0;
        }

        IsVisit = Check(ATemp, BTemp, CTemp, Visited);
        if (!IsVisit)
        {
            Dfs(ATemp, BTemp, CTemp, Visited, Answer, AMax, BMax, CMax);
        }

    }


}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int A, B, C;
    cin >> A >> B >> C;

    vector<int> Answer;
    queue<char> MainQueue;
    set<string> Visited;

    Dfs(0, 0, C, Visited, Answer, A, B, C);

    sort(Answer.begin(), Answer.end());
    Answer.erase(unique(Answer.begin(), Answer.end()), Answer.end());

    for (int i = 0; i < Answer.size(); i++)
    {
        cout << Answer[i] << " ";
    }

    return 0;
}

