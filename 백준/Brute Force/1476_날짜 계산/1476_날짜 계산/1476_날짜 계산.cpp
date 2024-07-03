#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int E, S, M;
    cin >> E >> S >> M;

    int Result = 1;

    while (!(E == 1 && S == 1 && M == 1))
    {
        E--;
        S--;
        M--;
        if (E <= 0)
        {
            E = 15;
        }
        if (S <= 0)
        {
            S = 28;
        }
        if (M <= 0)
        {
            M = 19;
        }
        Result++;
    }
    
    cout << Result;
    return 0;
}
