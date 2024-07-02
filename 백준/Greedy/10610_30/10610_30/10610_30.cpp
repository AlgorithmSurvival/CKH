#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string N;
    cin >> N;

    vector<short> Numbers;
    for (int i = 0; i < N.length(); i++)
    {
        Numbers.push_back(N[i] - 48);
    }

    sort(Numbers.begin(), Numbers.end());
    if (Numbers[0] != 0)
    {
        cout << -1;
        return 0;
    }



    int Remain = 0;
    for (int i = 1; i < Numbers.size(); i++)
    {
        Remain = ((Remain + Numbers[i]) % 3);
        Remain *= 10;
    }
    if (Remain != 0)
    {
        cout << -1;
        return 0;
    }



    for (int i = Numbers.size() - 1; i >= 0; i--)
    {
        cout << Numbers[i];
    }

    return 0;
}