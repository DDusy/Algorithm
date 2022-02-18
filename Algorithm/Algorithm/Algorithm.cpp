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

using namespace std;

// 비트 수 만큼의 시간 복잡도 O(n)
short FindBitCount(unsigned int _num) 
{
    short num_bits = 0;

	while (_num)
	{

		num_bits += _num & 1;
		_num >>= 1;  // 다음 자리수로 이동
	}

	return num_bits;
}


//패리티 계산
short Parity(unsigned long long _x)
{
	short Result = 0;

	while (_x)
	{
		/*  입력 크기인 O(_x)

		* Result ^= (_x & 1);
		*
		*_x >>= 1;
		*/


		// 비트 1의 개수가 K 일때 O(k)
		Result ^= 1;	// 짝수 홀수 반복
		_x &= (_x - 1); // 하위비트를 지워가며 실행
		
	}

	return Result;
}

long long PreCompute[1000001] = { 1,1,1,0,1,0,1,0};

long long ParityMask(unsigned long long _x)
{
	//? 잘못했는데 아직 못찾음 캐시 저장을 어떻게 해야되나
	/*const int MaskSize = 16;
	const int BitMask = 0xFFFF;

	return PreCompute[_x >> (3 * MaskSize)] ^
		PreCompute[(_x >> (2 * MaskSize)) & BitMask] ^
		PreCompute[(_x>> MaskSize) & BitMask] ^
		PreCompute[_x & BitMask];*/

	_x ^= _x >> 32;
	_x ^= _x >> 16;
	_x ^= _x >> 8;
	_x ^= _x >> 4;
	_x ^= _x >> 2;
	_x ^= _x >> 1;

	return _x & 0x1;
}

long long BitSwap(long long _x, int i, int j)
{
	// 비트가 같은지 확인
	if (((_x >> i) & 1) != ((_x >> j) & 1))
	{
		// * 1L은 long 타입의 리터럴 표시
		unsigned long long BitMask = (1L << i) | (1L << j);
		_x ^= BitMask;
	}

	return _x;
}

long long PreComputed[100000] = { 1,0,0,1,0,0,1,1, };

long long ReverseBits(unsigned long long _x)
{
	const int MaskSize = 16;
	const int BitMask = 0xFFFF;

	return PreComputed[_x & BitMask] << (3 * MaskSize) |
		PreComputed[(_x >> MaskSize) & BitMask] & (2 * MaskSize) |
		PreComputed[(_x >> MaskSize) & BitMask] & (2 * MaskSize) |
		PreComputed[(_x >> (2 * MaskSize)) & BitMask] <<MaskSize |
		PreComputed[(_x >> (3* MaskSize))& BitMask];

}

int main1()
{
	std::cout << "Bit Swap :	" << ReverseBits(8) << endl;

	//..문자열 정규식 
	/*
	*  주어진 문자열이 주어진 규칙에 맞는지 확인할때
	*  주어진 문자열에서 원하는 패턴의 문자열을 검색할 때
	*  주어진 문자열에서 원하는 패턴의 문자열로 치환할 때
	*
	* \d* 임의의 개수의 숫자
	* . 임의의 문자
	* \\ 단락 시작
	*
	* regex_match 정규식에대해 대상이 매치하는지 return bool
	*
	*
	*/

	vector<string> file_names = { "Test-123-file.txt" , "Test_5-file.txt" ,
									"Test-db1-file.txt" ,"Test-12223-file.txt" ,"Test-rert-file.txt" };


	regex re("Test-\\d*-file\\.txt"); // 정규식 표현 개체

	//regex re("Test-\\d*-file\\.txt",regex::grep); // 정규식 표현 개체
	//regex re("Test-\\d*-file\\.txt", regex::grep | regex::icase|regex::optimize); // 정규식 표현 개체


	// default는 regex::ECMAScript 추가조건은 | 로 추가 icase는 대소문자 구분
	//optimize를 통해 객체 생성시간 단축 (?)

	for (const auto& filename : file_names)
	{
		cout << filename << "	: " << boolalpha << regex_match(filename, re) << endl;
	}


	//부분매칭

	std::vector<std::string> phone_numbers = { "020-1234-5678", "01c-123-4567",
											"011-1234-5567", "010-12345-6789",
											"123-4567-8901", "010-1234-567" };
	/*
	* [가능한 숫자/문자]
	* {문자 수}
	*/
	cout << "regex 부분 매칭" << endl;

	regex re2("[01c]{3}-(\\d{3,4})-\\d{4}");

	smatch match;

	for (const auto& number : phone_numbers)
	{
		cout << number << "	:	" << boolalpha << regex_match(number, re2) << endl;

	}



	//MyVector<int> v;

//	v.reserve(10);

	//for (int i = 0; i < 100; ++i)
	//{
	//	v.push_back(i);
	//}



	//for (int i = 0; i < 100; ++i)
	//{
	//	cout << v[i] << ",";
	//}


	//int cnt[26] = { 0, }; // 알파벳 26개
	//string Str;

	//cin >> Str;

	//for(char ch :Str)
	//{
	//	++cnt[ch - 'a'];
	//}

	//for (int num : cnt)
	//{
	//	cout << num << " ";
	//}

	
#pragma  region 1번
/*
	int n, m;
	cin >> n >> m;
	int arr[100000] = {0,};
	int sumArr[100000] = { 0, };

	std::vector<int> v;
	
	//개선전
	//for (int i = 0; i < n; ++i)
	//	cin >> arr[i];

	//int start=0, end = 0;
	//for (int i = 0; i < m; ++i)
	//{
	//	cin >> start >> end ;

	//	int sum = 0;
	//	for (int j = start - 1; j < end; ++j)
	//	{
	//		sum += arr[j];
	//	}

	//	v.push_back(sum);
	//}
	//


	//개선후
	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
		sumArr[i] = sumArr[i - 1] + arr[i];
	}

	int start=0, end = 0;

	for (int i = 0; i < m; ++i)
	{
		cin >> start >> end ;

		v.push_back(sumArr[end]-sumArr[start-1]);
	}

	cout << "결과" << endl;

	for (int num : v)
		cout << num << endl;

*/

#pragma  endregion


	///////////////////////////////////////
#pragma  region 2번
	/*string str = "life is limited";

	//1
	cout << str.substr(0,3) << endl;

	reverse(str.begin(), str.end());

	cout <<str<< endl;

	str += "dopa!!";

		cout << str << endl;
*/
#pragma endregion


return 0;


}

#pragma region 2468 전역변수 & DFS함수
//int N = 0, tmp = 0, res = 1;
//
//int dx[] = { -1,0,1,0 };
//int dy[4] = { 0,1,0,-1 };
//
//bool checked[101][101] = { 0, };
//int board[101][101] = { 0, };
//int depthboard[101][101] = { 0, };
//
//
//void DFS(int x, int y)
//{
//	checked[x][y] = true;
//
//	for (int i = 0; i < 4; ++i)
//	{
//		int nx = x + dx[i];
//		int ny = y + dy[i];
//
//		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
//		if (!checked[nx][ny] && depthboard[nx][ny] == 0) DFS(nx, ny);
//	}
//}
#pragma endregion

//int m, n, k, x, y, res, nx, ny, t;
//vector<vector<int>> v;
//vector<vector<bool>> checked;
//
//void dfs(int _x, int _y)
//{
//	checked[_x][_y] = true;
//
//	for (int i = 0; i < 4; ++i)
//	{
//		nx = _x + dx[i];
//		ny = _y + dy[i];
//
//		if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
//		if ((v[nx][ny] == 1) && !checked[nx][ny])
//		{
//			dfs(nx, ny);
//		}
//	}
//	return;
//}

//2
//int m, n, k, posx1, posx2, posy1, posy2;
//
//void dfs(int _x, int _y,vector<vector<int>>& _v, vector<vector<bool>>& _check)
//{
//	_check[_x][_y] = true;
//
//	for (int i = 0; i < 4; ++i)
//	{
//		int nx = _x + dx[i];
//		int ny = _y + dy[i];
//
//		if (nx < 0 || ny<0 || nx >= m || ny>=n) continue;
//
//		if (!_check[nx][ny] && (_v[nx][ny] == 0))
//		{
//			++cnt;
//			dfs(nx, ny,_v,_check);
//
//		}
//
//	}

//}

string quard(int _x, int _y, int _size, vector<vector<int>>& _v)
{
	if (_size == 1)	return string(1, _v[_y][_x]); // 0,1 출력
	char b = _v[_y][_x];

	string res = "";

	for (int i = _y; i < _y + _size; ++i)
	{
		for (int j = _x; j < _x + _size; ++j)
		{
			if (b != _v[i][j])
			{
				res += "(";
				res += quard(_x, _y, _size / 2,_v);
				res += quard(_x+ _size / 2, _y, _size / 2,_v);
				res += quard(_x, _y+ _size / 2, _size / 2,_v);
				res += quard(_x + _size / 2, _y + _size / 2, _size / 2, _v);
				res += ")";

				return res;
			}
		}
	}
	
	return string(1, _v[_y][_x]);
}



bool Isvowel(char& _ch)
{
	if (_ch == 'a' || _ch == 'e'|| _ch == 'i' || _ch == 'o' || _ch == 'u')
		return true;

	return false;
}

string PrintTime(int& _Time)
{
	string m = "0"+to_string(_Time / 60);
	string s= "0"+to_string(_Time % 60);

	return	m.substr(m.size()-2,2) + ":" + s.substr(s.size()-2,2);
}

int ChangeToInt(const string& _S)
{
	return atoi(_S.substr(0, 2).c_str()) * 60 + atoi(_S.substr(3).c_str());
}

int ChangeToTime(const string& _a,const string& _b)
{
	return ChangeToInt(_b) - ChangeToInt(_a);
}


//int n, m, a[8][8];
//
//bool checked[8][8];
//vector<pair<int, int>> v;
//
//void dfs(int _x, int _y)
//{
//	if (a[_x][_y] == 1 || checked[_x][_y]) return;
//
//	checked[_x][_y] = true;
//
//	for (int i = 0; i < 4; i++) 
//	{
//		if (_x + dx[i] < 0 || _y + dy[i] < 0 || _x + dx[i] >= n || _y + dy[i] >= m) 
//		{
//			continue;
//		}
//
//		dfs(_x + dx[i], _y + dy[i]);
//	}
//}
//
//int Solve()
//{
//	memset(checked, 0, sizeof(checked));
//	
//	// 바이러스
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++) 
//		{
//			if (a[i][j] == 2) dfs(i, j);
//		}
//	}
//	
//	int ans = 0;
//
//	// 영역 체크
//	for (int i = 0; i < n; i++) 
//	{
//		for (int j = 0; j < m; j++) 
//		{
//			if (!checked[i][j] && a[i][j] == 0) ++ans;
//		}
//	}
//
//	return ans;
//}

int n, m, cnt = 0, cnt2 = 0;
bool visited[100][100];
int  board[100][100];

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void dfs(int x, int y)
{
	visited[x][y] = true;

	if (board[x][y])
	{
		board[x][y] = 0;
		++cnt2;
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny])
			continue;

		dfs(nx, ny);
	}
}

int main()
{
	int bFlag = false;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> board[i][j];
		}
	}

	while (true)
	{
		memset(visited, 0, sizeof(visited));
		cnt2 = 0;
		bFlag = false;

		dfs(0, 0);
		++cnt;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (board[i][j])
				{
					bFlag = true;
					break;
				}
			}
		}

		if (!bFlag)
			break;
	}

	cout << cnt << endl;
	cout << cnt2 << endl;

	return 0;
}