#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void search(long long low, long long high, vector<int>& arr, int n, int m, int& result)
{
    if (low > high) return;
    int mid = (low + high) / 2;

    long long length = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = arr[i] - mid;
        if (temp > 0)
        {
            length += temp;
        }
    }

    if (length >= m)
    {
        result = mid;
        search(mid + 1, high, arr, n, m, result);
    }
    else
    {
        search(low, mid - 1, arr, n, m, result);
    }

}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;

        arr.emplace_back(input);
    }

    int result = 0;
    search(0, *max_element(arr.begin(), arr.end()), arr, n, m, result);
    cout << result;

    return 0;
}