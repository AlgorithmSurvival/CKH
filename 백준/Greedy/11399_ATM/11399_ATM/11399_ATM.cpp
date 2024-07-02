#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int N;
	cin >> N;

	vector<short> Times;
	for (int i = 0; i < N; i++)
	{
		short Input;
		cin >> Input;
		Times.emplace_back(Input);
	}

	sort(Times.begin(), Times.end());

	int Sum = 0;
	int Result = 0;
	for (const auto Time : Times)
	{
		Sum += Time;
		Result += Sum;
	}

	cout << Result;
	return 0;
}
