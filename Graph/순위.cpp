#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 플로이드와샬 알고리즘 사용해야함
int solution(int n, vector<vector<int>> results)
{
	int answer = 0;

	vector<vector<int>> vecWinLose(n+1,vector<int>(n+1));

	for (int i = 0; i < results.size(); i++)
	{
		vecWinLose[results[i][0]][results[i][1]] = 1;
		vecWinLose[results[i][1]][results[i][0]] = -1;
	}

	for (int i = 1; i <= n; i++) // 거쳐가는 정점
	{
		for (int j = 1; j <= n; j++) // 행(출발 정점)
		{
			for (int k = 1; k <= n; k++) // 열(도착 정점)
			{
				if ((vecWinLose[j][i] == 1) && (vecWinLose[i][k] == 1))
				{
					vecWinLose[j][k] = 1;
					vecWinLose[k][j] = -1;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		bool bRank = true;

		for (int j = 1; j <= n; j++)
		{
			if ((i != j) && vecWinLose[i][j] == 0)
			{			
				bRank = false;
				break;
			}
		}

		if (bRank)
		{
			answer++;
		}
	}	

	return answer;
}

int main()
{
	cout << solution(5, { {4, 3} ,{4, 2},{3, 2},{1, 2},{2, 5} }) << '\n';	// 2

	return 0;
}