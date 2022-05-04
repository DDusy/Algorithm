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


//int n,m,res=987654321,high=0,low=0;

struct point
{
	int x,y;
};

int n,m,high,low;
int a[100001]={0,};


bool check(int _mid)
{
	int cnt=1;
	int remain=_mid;

	for (int i = 0; i < n; ++i)
	{
		if(_mid-a[i]>=0)
		{
			_mid-=a[i];
		}
		else
		{
			_mid= remain;
			++cnt;
			if(a[i]>_mid) return false;
			else _mid -=a[i];
		}

	}

	return cnt<=m;
}
int main()
{	
	cin>>n>>m;

	for (int i = 0; i <n; ++i)
	{
		cin>>a[i];
		high+=a[i];
	}

	while (low<=high)
	{
		int mid=  (low + high)/2;

		if (check(mid))
		{
			high= mid-1;
		}
		else 
		{
			low= mid+1;
		}
	}

	cout<<low<<endl;
}