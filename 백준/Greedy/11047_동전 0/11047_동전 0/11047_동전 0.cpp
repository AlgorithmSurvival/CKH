#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    vector<int> Prices;
    for (int i = 0; i < N; i++)
    {
        int Input;
        cin >> Input;
        Prices.emplace_back(Input);
    }

    int Result = 0;

    int Money = K;
    int Index = N - 1;
    while (Money > 0)
    {
        if (Prices[Index] <= Money)
        {
            Result += Money / Prices[Index];
            Money %= Prices[Index];
        }

        Index--;
    }
        
    cout << Result;
    return 0;
}
