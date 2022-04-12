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

const int INF=987654321;
int n,m,a[11],Tmp,Res=INF,comp[11],visited[11];
vector<int> adj[11];

pair<int, int> dfs(int here, int _value)
{
	visited[here]=1;
	pair<int,int> res= {1,a[here]};
	for (int i: adj[here])
	{
		if(comp[i] != _value) continue;
		if(visited[i]) continue;

		pair<int,int> tmp= dfs(i,_value);
		res.first +=tmp.first;
		res.second += tmp.second;
	}

	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin>>n;

	//인구수
	for(int i=1;i<=n;++i)
		cin>>a[i];

	// 인접 구역 정보
	for(int i=1;i<=n;++i)
	{
		cin>>m;	// 인접한 구역의 수 
		for (int j = 0; j < m; ++j)
		{
			cin>>Tmp;	// 인접 구역의 번호 / 서로 연결
			adj[i].push_back(Tmp);
			adj[Tmp].push_back(i);
		}
	}
		
	// 경우의 수 최대
	for (int i = 1; i <(1<<n)-1; ++i)
	{	
		memset(&comp,0,sizeof(comp));
		memset(&visited, 0, sizeof(visited));	// 초기화

		int idx1= -1; int idx2 = -1;

		//2개의 connected component인지 확인
		for (int j = 0; j < n; ++j)
		{
			if(i & (1<<j))	 //모든 경우의 수중 연결되있으면 인덱스 증가
			{
				comp[j+1]=1;
				idx1= j+1;	
			}
			else
			{
				idx2=j+1;
			}
		}

		pair<int,int> cmp1= dfs(idx1,1);
		pair<int, int> cmp2= dfs(idx2, 0);

		if(cmp1.first + cmp2.first ==n) // 다합쳐서 n
		Res =min(Res,abs(cmp1.second - cmp2.second)); 

	}

	std::cout<<(Res == INF ? -1  : Res)<<"\n";

	/*int i =5;

	cout<<(n&-n);*/

	return 0;

}