#include <iostream>
#include <vector>
#include <random>
#include <algorithm>


bool Linear_search(int N, std::vector<int>& _Arr)
{
	for (auto i : _Arr)
	{
		if (i == N)
			return true;
	}

	return false;
}

bool Binary_Search(int N, std::vector<int>& _Arr)
{
	auto first = _Arr.begin();
	auto last = _Arr.end();
	
	while (true)
	{
		int Range_length = (int)std::distance(first,last);
		int Mid_Idx = Range_length / 2;
		int Mid = _Arr[Mid_Idx];

		if (Mid == N) return true;
		else if (Mid > N)
			std::advance(last, -Mid_Idx);
		else
			std::advance(first, Mid_Idx);

		if (Range_length == 1)
			return false;
	}
}

void Run_Search_small()
{
	auto N = 2;
	std::vector<int> vTest { 1, 3, 2, 4, 5, 7, 9, 8, 6 };

	std::sort(vTest.begin(), vTest.end());

	if (Binary_Search(N, vTest))
		std::cout << "Binary Search Success" << std::endl;
	else
		std::cout << "Binary Fail" << std::endl;
}