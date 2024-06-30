#include <iostream>
#include <vector>
using namespace std;

bool NextGo(const int InEndY, const int InEndX, int& OutCurrentPosY, int& OutCurrentPosX, int& OutResult)
{
    if (OutCurrentPosY + 2 <= InEndY && OutCurrentPosX + 1 <= InEndX)
    {
        OutResult++;
        OutCurrentPosY += 2;
        OutCurrentPosX += 1;
        return 1;
    }
    else if (OutCurrentPosY - 2 >= 0 && OutCurrentPosX + 1 <= InEndX)
    {
        OutResult++;
        OutCurrentPosY -= 2;
        OutCurrentPosX += 1;
        return 1;
    }
    else if (OutCurrentPosY + 1 <= InEndY && OutCurrentPosX + 2 <= InEndX)
    {
        OutResult++;
        OutCurrentPosY += 1;
        OutCurrentPosX += 2;
        return 1;
    }
    else if (OutCurrentPosY - 1 >= 0 && OutCurrentPosX + 2 <= InEndX)
    {
        OutResult++;
        OutCurrentPosY -= 1;
        OutCurrentPosX += 2;
        return 1;
    }
    else
    {
        cout << OutResult;
        return 0;
    }
}

void NextGoCheck(const int InEndY, const int InEndX, int& OutCurrentPosY, int& OutCurrentPosX, int& OutResult, vector<bool>& OutCheckCases)
{
    for (int i = 0; i < 4; i++)
    {
        if (OutCurrentPosY + 2 <= InEndY && OutCurrentPosX + 1 <= InEndX && !OutCheckCases[0])
        {
            OutCheckCases[0] = 1;
            OutResult++;
            OutCurrentPosY += 2;
            OutCurrentPosX += 1;
        }
        else if (OutCurrentPosY - 2 >= 0 && OutCurrentPosX + 1 <= InEndX && !OutCheckCases[1])
        {
            OutCheckCases[1] = 1;
            OutResult++;
            OutCurrentPosY -= 2;
            OutCurrentPosX += 1;
        }
        else if (OutCurrentPosY + 1 <= InEndY && OutCurrentPosX + 2 <= InEndX && !OutCheckCases[2])
        {
            OutCheckCases[2] = 1;
            OutResult++;
            OutCurrentPosY += 1;
            OutCurrentPosX += 2;
        }
        else if (OutCurrentPosY - 1 >= 0 && OutCurrentPosX + 2 <= InEndX && !OutCheckCases[3])
        {
            OutCheckCases[3] = 1;
            OutResult++;
            OutCurrentPosY -= 1;
            OutCurrentPosX += 2;
        }
        else
        {
            break;
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    const int EndY = N - 1;
    const int EndX = M - 1;
    int CurrentPosY = 0;
    int CurrentPosX = 0;

    vector<bool> CheckCases = vector<bool>(4, 0);
    int Result = 1;


    //모든 경우 가능 여부 체크.
    NextGoCheck(EndY, EndX, CurrentPosY, CurrentPosX, Result, CheckCases);

    for (const auto& CheckCase : CheckCases)
    {
        if (!CheckCase) //모든 경우를 다 돌지 못한 케이스가 생기면
        {
            Result = 1;
            CurrentPosY = 0;
            CurrentPosX = 0;
            while (true)
            {
                if (Result < 4) //탐색은 4칸밖에 못감.
                {
                    if (!NextGo(EndY, EndX, CurrentPosY, CurrentPosX, Result))
                    {
                        return 0;
                    }
                }
                else
                {
                    cout << 4;
                    return 0;
                }
            }

            break;
        }
    }

    Result += (EndX - CurrentPosX);
    cout << Result;
    return 0;
}

