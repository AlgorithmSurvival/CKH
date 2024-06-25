#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<bool> arr(20000001, 0);
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        if (input < 0)
        {
            input *= -1;
            input += 10000000;
        }
        arr[input] = true;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int input;
        cin >> input;
        if (input < 0)
        {
            input *= -1;
            input += 10000000;
        }
        if (arr[input] == true)
        {
            cout << 1 << " ";
        }
        else
        {
            cout << 0 << " ";
        }
    }

    return 0;
}
