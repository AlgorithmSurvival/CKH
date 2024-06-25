#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void search(int low, int high, vector<int>& point, int c, int& result)
{
    if (low > high) return;
    int mid = (high + low) / 2;

    int curNum = point[0];
    int index = 1;
    int count = 1;
    while (true)
    {
        if (index >= point.size())
        {
            search(low, mid - 1, point, c, result);
            break;
        }
        if (point[index] - curNum >= mid)
        {
            curNum = point[index];
            count++;
            if (count >= c)
            {
                result = mid;
                search(mid + 1, high, point, c, result);
                break;
            }
        }
        index++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, c;
    cin >> n >> c;
    vector<int> point;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        point.emplace_back(input);
    }
    sort(point.begin(), point.end());
    int result = 0;

    search(0, point[n - 1]- point[0], point, c, result);
    cout << result;

    return 0;
}
