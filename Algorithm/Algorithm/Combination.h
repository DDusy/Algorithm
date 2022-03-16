#pragma once
#include<iostream>
#include <vector>
#include <stack>
#include<algorithm>


using namespace std;
static int Ccnt = 0;

void Pre_Combination(int n, int r, int depth,std::vector<int>& _stk, std::vector<int>& _v)
{
	if (_stk.size() == r)
	{
		for (int num:_stk)
		{
			std::cout << num;
		}

		std::cout << std::endl;
		return;
	}


	for (int i = depth + 1; i < n; ++i)
	{
		_stk.push_back(i);
		Pre_Combination(n, r, i, _stk, _v);
		_stk.pop_back();
	}
}

void Layer_Combination(int n,int r,vector<int>& _v)
{
	for (int i = 0; i < n; ++n)
	{
		for (int j = i + 1; i < n; ++i)
		{
			for (int k = j + 1; k < n; k++)
			{
				cout << i << "	" << j << "	" << k << endl;
			}
		}
	}
}

