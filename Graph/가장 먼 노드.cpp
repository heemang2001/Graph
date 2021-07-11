#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

#define MAX 20001

int Lenth[MAX];
bool Graph[MAX][MAX];
bool isVisited[MAX];

int solution(int n, vector<vector<int>> edge)
{
	int answer = 0;
	queue<int> q;

	for (int i = 0; i < edge.size(); i++)
	{
		Graph[edge[i][0]][edge[i][1]] = true;
		Graph[edge[i][1]][edge[i][0]] = true;
	}

	q.push(1);
	isVisited[1] = true;

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		for (int i = 2; i <= n; i++)
		{
			if (Graph[node][i] && !isVisited[i])
			{
				q.push(i);
				isVisited[i] = true;
				Lenth[i] = Lenth[node] + 1;
			}
		}
	}

	int maxLenth = *max_element(Lenth, Lenth + n + 1);

	for (int i = 1; i <= n; i++)
	{
		if (Lenth[i] == maxLenth)
		{
			answer++;
		}
	}

	return answer;
}

int main()
{
	cout << solution(6, { {3, 6},{4, 3},{3, 2},{1, 3},{1, 2},{2, 4},{5, 2} }) << '\n';

	return 0;
}