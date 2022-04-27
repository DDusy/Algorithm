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


int n,res=987654321;

int s[20][20]={0,};
int visited[20]={0,};


int main()
{
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> s[i][j];
		}
	}

	for (int i = 0; i < (1 << n); ++i)
	{
		int cnt = 0;
		for (int j = 0; j < n; ++j)
		{
			if (i & (1 << j))++cnt;
		}

		if (n / 2 != cnt) continue;

		vector<int> vTeam1, vTeam2;
		for (int j = 0; j < n; ++j)
		{
			if (i & (1 << j))
				vTeam1.push_back(j);
			else
				vTeam2.push_back(j);
		}

		int t1 = 0, t2 = 0;
		for (int j = 0; j < (n / 2); ++j)
		{
			for (int h = 0; h < (n / 2); ++h)
			{

				t1 += s[vTeam1[j]][vTeam1[h]];
				t2 += s[vTeam2[j]][vTeam2[h]];
			}

		}

		int diff = t1 - t2;
		if (diff < 0) diff = -diff;

		res = min(res, diff);
	}

	cout << res << '\n';

	return 0;
}