#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void search(long long low, long long high, int& max, vector<int> &lan, int n)
{
    if (low > high) return;

    long long mid = (low + high) / 2;

    long long count = 0;
    for (int i = 0; i < lan.size(); i++)
    {
        count += lan[i] / mid;
    }

    if (count >= n)
    {
        max = mid;
        search(mid + 1, high, max, lan, n);
    }
    else
    {
        search(low, mid - 1, max, lan, n);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int k, n;
    cin >> k >> n;

    vector<int> lan;
    for (int i = 0; i < k; i++)
    {
        int input;
        cin >> input;
        lan.emplace_back(input);
    }

    int max = 1;
    search(1, *max_element(lan.begin(), lan.end()), max, lan, n);

    cout << max;
}
