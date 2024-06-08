#include <iostream>
#include <vector>
using namespace std;

struct line
{
	int node;
	int weight;
};

int dfs(vector<vector<line>>& tree, vector<bool>& check, vector<int>& endNode, int v)
{
	int max = 0;
	check[v] = true;
	if (tree[v].size() == 1) //말단 노드
	{
		endNode[v] = v;
	}

	for (int i = 0; i < tree[v].size(); i++)
	{
		if (check[tree[v][i].node] == false)
		{
			int temp = dfs(tree, check, endNode, tree[v][i].node) + tree[v][i].weight;
			if (temp > max)
			{
				max = temp;

				endNode[v] = endNode[tree[v][i].node];
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

	vector<vector<line>> tree(n + 1);
	vector<bool> check(n + 1, false);
	vector<int> endNode(n + 1, 0);

	for (int i = 0; i < n - 1; i++)
	{
		int parent, node, weight;
		cin >> parent >> node >> weight;
		line temp;
		temp.node = node;
		temp.weight = weight;

		tree[parent].emplace_back(temp);

		temp.node = parent;
		tree[node].emplace_back(temp);
	}

	dfs(tree, check, endNode, 1); // 끝점 탐색
	check = vector<bool>(n + 1, false);


	cout << dfs(tree, check, endNode,  endNode[1]);
}

