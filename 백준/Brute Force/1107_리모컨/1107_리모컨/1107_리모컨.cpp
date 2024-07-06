#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    int M;
    cin >> N >> M;

    vector<char> BrokenButtons;
    for (int i = 0; i < M; i++)
    {
        char Input;
        cin >> Input;
        BrokenButtons.emplace_back(Input);
    }

    int UpInitChannelNum = N;
    int DownInitChannelNum = N;
     

    int Result = abs(N - 100);

    //Up
    for(int i = 0; i <= Result; i++)
    {
        string UpInitChannel = to_string(UpInitChannelNum);
        bool Success = true;
        bool exit = false;
        for (int i = 0; i < UpInitChannel.length(); i++)
        {
            if (find(BrokenButtons.begin(), BrokenButtons.end(), UpInitChannel[i]) != BrokenButtons.end())
            {
                UpInitChannelNum++;
                Success = false;
                break;
            }
        }

        if (Success)
        {
            break;
        }

    }

    //Down
    for (int i = 0; i <= Result; i++)
    {
        string DownInitChannel = to_string(DownInitChannelNum);
        bool Success = true;
        for (int i = 0; i < DownInitChannel.length(); i++)
        {
            if (find(BrokenButtons.begin(), BrokenButtons.end(), DownInitChannel[i]) != BrokenButtons.end())
            {
                DownInitChannelNum--;
                Success = false;
                break;
            }
        }

        if (Success)
        {
            break;
        }
    }


    if (UpInitChannelNum - N + to_string(UpInitChannelNum).length() < Result)
    {
        Result = UpInitChannelNum - N + to_string(UpInitChannelNum).length();
    }
    

    if (DownInitChannelNum >= 0)
    {
        if (N - DownInitChannelNum + to_string(DownInitChannelNum).length() < Result)
        {
            Result = N - DownInitChannelNum + to_string(DownInitChannelNum).length();
        }
    }


    cout << Result;
    return 0;
}

