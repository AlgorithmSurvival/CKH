#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<vector<pair<int, int>>>& tree, vector<bool>& check,vector<int> &endNode, int v)
{
	int max = 0;
	if (tree[v].size() == 1) //말단 노드
	{
		endNode[v] = v;
	}
	for (int i = 0; i < tree[v].size(); i++)
	{
		if (check[tree[v][i].first] == false)
		{
			check[tree[v][i].first] = true;

			int temp = dfs(tree, check, endNode, tree[v][i].first) + tree[v][i].second;
			if (temp > max)
			{
				endNode[v] = endNode[tree[v][i].first]; //말단 노드 찾기
				max = temp; //길이 찾기
			}
		}
	}
	return max;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<vector<pair<int, int>>> tree(n + 1, vector<pair<int, int>>());
	vector<bool> check(n + 1, 0);
	vector<int> endNode(n + 1, 0);

	for (int i = 0; i < n; i++)
	{
		int v;
		cin >> v;

		while (true)
		{
			int first;
			cin >> first;
			if (first == -1)
			{
				break;
			}

			int second;
			cin >> second;

			tree[v].emplace_back(make_pair(first, second));
		}
	}

	check[1] = true;
	dfs(tree, check, endNode, 1); //말단 노드 검색


	check = vector<bool>(n + 1, 0);
	check[endNode[1]] = true;
	cout << dfs(tree, check, endNode, endNode[1]); //실제 지름 탐색
	
}

