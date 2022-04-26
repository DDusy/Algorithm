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

int r,c,t;
int origin[51][51];
int temp[51][51];
int dx[]=  { 0,-1,0,1};
int dy[] = { 1,0,-1,0};
int dx2[] = { 0,1,0,-1 };
int dy2[] = { 1,0,-1,0 };

pair<int, int> Purifier1={-1,-1},Purifier2= { -1,-1 };

queue<pair<int,int>> q;
vector<pair<int,int>>  route1,route2;

int res=0;

void Dust()
{
	memset(&temp,0,sizeof(temp));

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if(-1!=origin[i][j] && origin[i][j])	// 다 집어넣기
					q.push({i,j});
		}
	}

	while (!q.empty())
	{

		int _x=q.front().first;
		int _y=q.front().second;
		q.pop();

		int spread = origin[_x][_y] / 5;

		for (int i = 0; i < 4; ++i)
		{
			int nx = _x + dx[i];
			int ny = _y + dy[i];

			if (nx < 0 || ny < 0 || nx >= r || ny >= c || -1 == origin[nx][ny]) continue;

			temp[nx][ny] += spread;
			origin[_x][_y] -= spread;
		}
	}
	

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			origin[i][j]+=temp[i][j];

		}
	}
}

void SetRoute(pair<int,int> _start,vector<pair<int,int>>& _route,int _dx[], int _dy[])
{
	
	int dirX =_start.first;
	int dirY = _start.second;

	int idx=0;

	while (true)
	{
		if(idx==4)
		 break;

		int nx = dirX + _dx[idx];
		int ny = dirY + _dy[idx];

		if (nx < 0 || ny < 0 || nx >= r || ny >= c || -1 == origin[nx][ny] )
		{
			++idx;
			continue;
		}

		dirX=nx;
		dirY=ny;

		_route.push_back({dirX,dirY});
	}
}

void AirClean(vector<pair<int, int>>& _route)
{
	for (int i = _route.size() - 1; i > 0; --i)
	{
		origin[_route[i].first][_route[i].second] = origin[_route[i-1].first][_route[i-1].second];
	}
	
	origin[_route[0].first][_route[0].second]= 0;
}

int main()
{
	cin>>r>>c>>t;

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cin>>origin[i][j];

			if(-1==origin[i][j])
				{
					if(Purifier1.first==-1 )
						{
							Purifier1={i,j};
							SetRoute(Purifier1, route1, dx, dy);
						}
					else
						{
							Purifier2 = { i,j };
							SetRoute(Purifier2, route2, dx2, dy2);
						}
				}	

		}
	}

	

	while (t--)
	{
		Dust();

		cout<< "확산"<<endl;

		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
				cout<<origin[i][j]<<" ";
				cout<<endl;
		}
		AirClean(route1);
		AirClean(route2);


		cout << "결과" << endl;

		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
				cout << origin[i][j] << " ";
			cout << endl;
		}
	}


	for (int i = 0; i < r; ++i)
	{
		for(int j=0;j<c;++j)
		 res+=origin[i][j];
	}

	cout<<res+2<<"\n";
	return 0;
}