#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    float Woman = N;
    int Man = M;
    int KCount = K;

    if (Woman / 2 <= 0 || Man <= 0)
    {
        cout << 0;
        return 0;
    }


    while (KCount > 0)
    {
        if (Woman / 2 > Man)
        {
            Woman--;
        }
        else
        {
            Man--;
        }
        KCount--;
    }

    if (Woman / 2 > Man)
    {
        cout << Man;
    }
    else
    {
        cout << (int)(Woman / 2);
    }
    
    return 0;
}

