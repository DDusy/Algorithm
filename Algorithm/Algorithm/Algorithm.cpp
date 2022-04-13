// Algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//


#include "MyVector.h"

#include <iostream>
#include <regex>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <assert.h>

#include "Mylist.h"


#include "permutation.h"
#include "Combination.h"

#include <boost/regex.hpp>

#include <openssl//rsa.h>
#include <openssl//pem.h>
#include <openssl//err.h>


using namespace std;

int m, n, cnt = 0, mx, big;
int board[51][51] = { 0, }, visited[51][51] = { 0, }, Rooms[51];

int dx[] = { 0,-1,0,1 };
int dy[] = { -1,0,1,0};

int dfs(int x, int y, int cnt)
{
	if (visited[x][y]) return 0;
	visited[x][y] = cnt;

	int res = 1;

	for (int i = 0; i < 4; ++i)
	{
		if (!(board[x][y] & (1 << i)))
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

			res += dfs(nx, ny, cnt);
		}
	}

	return res;
}

int main()
{
	cin >> m >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (!visited[i][j])
			{
				++cnt;
				Rooms[cnt] = dfs(i, j, cnt);
				mx = max(mx, Rooms[cnt]);
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int cur = visited[i][j];
			if (i + 1 < n)
			{
				int tmp = visited[i + 1][j];

				if(cur!=tmp)
				big = max(big, Rooms[cur] + Rooms[tmp]);

			}

			if (j + 1 < m)
			{
				
				int tmp = visited[i][j + 1];

				if (cur != tmp)
				big = max(big, Rooms[cur] + Rooms[tmp]);
			}
		}
	}


	cout << cnt << "\n" << mx << "\n" << big << "\n";
	return 0;
}