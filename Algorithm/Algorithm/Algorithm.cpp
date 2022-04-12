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

int R,C,res,nx,ny;
char a[21][21];
const int dx[]= {-1,1,0,0};
const int dy[] = { 0,0,-1,1 };

void solve(int _x, int _y, int _num, int _cnt)
{
	res = max(res,_cnt);
	
	for (int i = 0; i < 4; ++i)
	{
		nx= _x+ dx[i];
		ny = _y + dy[i];

		if(nx<0||ny<0||nx>=R||ny>=C) continue;
		
		int _next =(1<<(int)(a[nx][ny]-'A'));
		
		if ((_num & _next) == 0)
		{	
			//스택프레임 이용
			solve(nx,ny,_num|_next,_cnt+1);
		}
	}

	return;
}


int main()
{
	cin>>R>>C;

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			cin>>a[i][j];
		}
	}

	solve(0,0,1<<(int)(a[0][0]-'A'),1);

	cout<<res<<endl;

	return 0;
}
