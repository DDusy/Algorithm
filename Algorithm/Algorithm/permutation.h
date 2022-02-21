#pragma once
#include<iostream>
#include <vector>
#include<algorithm>

/*
	깊이를 이용
*/

static int cnt = 0;

static void Pre_Permutation(int n,int r,int depth,std::vector<int>& _v)
{
	if (r == depth)
	{
		for (int i =0;i<r;++i)
		{
			std::cout << _v[i] << " ";
		}

		std::cout << std::endl;
		++cnt;
	}
	
	for (int i = depth; i < n; ++i)
	{
		std::swap(_v[i], _v[depth]);
		Pre_Permutation(n, r, depth + 1,_v);
		std::swap(_v[i], _v[depth]);
	}
	
}

