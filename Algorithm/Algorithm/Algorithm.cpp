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
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int cnt = 0;
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



int main()
{

#pragma region last

#pragma region 3474

	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);

	////2,5의 개수 

	//int T , N ;
	//
	//cin >> T;
	//
	//for (int i = 0; i < T; ++i)
	//{
	//	int Res2 =0, Res5=0;
	//	cin >>N;

	//	for (int i = 2; i <= N; i *= 2)
	//	{
	//		Res2 += N/i;
	//	}

	//	for (int i = 5; i <= N; i *= 5)

	//	{
	//		Res5 += N/i;
	//	}

	//	cout << min(Res2, Res5) << endl;
	//}

#pragma endregion 3474

#pragma region 9012

	/*ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t = 0,res=0;
	string s;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		res = 0;
		cin >> s;

		for (char ch : s)
		{
			if (ch == '(')
			{
				++res;
			}
			else
			{
				--res;
			}

			if (res < 0) break;
		}

		if (0 == res) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}*/

#pragma endregion 9012

#pragma region 1436
	/*int n = 0;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	int i = 666;

	while (true)
	{
		if (to_string(i).find("666") != string::npos)
			--n;
		if (n == 0)
			break;

		++i;
	}

	cout << i << "\n";
*/
#pragma endregion 1436

#pragma region 4949
//ios_base::sync_with_stdio(false);
//cin.tie(NULL); cout.tie(NULL);

//bool flag = true;
//string s;
//
//while (true)
//{
//	stack<char> stk;
//	flag = true;
//	getline(cin, s);

//	if (s == ".") break;

//	for (char ch : s)
//	{
//		if (ch == '('|| ch == '[')
//		{
//			stk.push(ch);
//		}
//		else if (ch == ')')
//		{
//			if ((0 == stk.size()) || stk.top() == '[')
//			{
//				flag = false;
//				break;
//			}
//			else
//				stk.pop();
//		}	
//		else if (ch == ']')
//		{
//			if ((0 == stk.size()) || stk.top() == '(')
//			{
//				flag = false;
//				break;
//			}
//			else
//				stk.pop();
//		}

//	}

//	if (flag&&stk.empty())
//		cout << "yes" << "\n";
//	else
//		cout << "no" << "\n";
//}

#pragma endregion 4949


#pragma region 2852

	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);

	//int N = 0,TeamNum=0,Asum=0,Bsum=0,A=0,B=0;
	//string strTime,strPrev;
	//
	//cin >> N;
	//// 작은 것 기준으로 계산
	//for (int i = 0; i < N; ++i)
	//{
	//	cin >> TeamNum >> strTime;
	//	
	//	if (A>B)
	//	{
	//		Asum += ChangeToTime(strPrev, strTime);
	//	}
	//	else if(B>A)
	//	{
	//		Bsum += ChangeToTime(strPrev, strTime);
	//	}

	//	TeamNum == 1 ? ++A : ++B;
	//	
	//	strPrev = strTime;
	//}

	//if(A>B) 
	//	Asum += ChangeToTime(strPrev,"48:00");
	//else if(B>A)
	//	Bsum += ChangeToTime(strPrev, "48:00");

	//cout <<PrintTime(Asum)<< "\n";
	//cout << PrintTime(Bsum) << "\n";



#pragma endregion 2852

#pragma region 17298

	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);

	//int N = 0;
	//
	//cin >> N;

	//vector<int> v(N,-1);
	//vector<int> Res(N,-1);

	//stack<int> stk;

	// 순회 줄이기
	//for (int i = 0; i < N; ++i)
	//{
	//		cin >> v[i];
	//		
	//		while (stk.size() && v[stk.top()] < v[i]) 
	//		{
	//			Res[stk.top()] = v[i];
	//			stk.pop();
	//		}

	//		stk.push(i);
	//}

	// 느림
	//for (int i = 0; i < N; ++i)
	//	cin >> v[i];

	//for (int i = 0; i < N; ++i)
	//{
	//	flag = false;

	//	for (int j = i+1; j < N; ++j)
	//	{
	//		if (v[i] < v[j])
	//		{
	//			res.push_back(v[j]);
	//			flag = true;
	//			break;
	//		}
	//	}

	//	if (!flag)
	//		res.push_back(-1);
	//}


	//for (int num : Res)
	//	cout << num << " ";

	//cout << "\n";
#pragma endregion 17298

#pragma endregion last

//
//cin >> n >> m;
//
////입력 받기
//for (int i = 0; i < n; i++) 
//{
//	for (int j = 0; j < m; j++) 
//	{
//		cin >> a[i][j];
//		if (!a[i][j]) v.push_back({ i, j });
//	}
//}
//	assert(v.size() >= 3);
//
//	int ans = 0;
//
//for (int i = 0; i < v.size(); i++) 
//{
//	for (int j = 0; j < i; j++) 
//	{
//		for (int k = 0; k < j; k++)
//		{
//			a[v[i].first][v[i].second] = a[v[j].first][v[j].second] = a[v[k].first][v[k].second] = 1;
//			ans = max(ans, Solve());
//			a[v[i].first][v[i].second] = a[v[j].first][v[j].second] = a[v[k].first][v[k].second] = 0;
//		}
//	}
//}
//cout << ans;

#pragma region List_Test

//List<int> li;
//
//List<int>::iterator eraseIt;
//// [ ] <-> [ ] <-> [ ] <-> [ ]  <-> [ ]  <-> [ ]
//for (int i = 0; i < 10; i++)
//{
//	if (i == 5)
//	{
//		eraseIt = li.insert(li.end(), i);
//	}
//	else
//	{
//		li.push_back(i);
//	}
//}
//
//li.pop_back();
//
//li.erase(eraseIt);
//
//for (List<int>::iterator it = li.begin(); it != li.end(); it++)
//{
//	cout << (*it) << endl;
//}
#pragma endregion List_Test



//cin >> n >> m;
//
//for (int i = 0; i < n; ++i)
//{
//	for (int j = 0; j < m; ++j)
//	{
//		cin >> a[i][j];
//
//		if (!a[i][j]) v.push_back({ i,j });
//	}
//}
//
//int ans = 0;
//
//for (int i = 0; i < v.size(); ++i)
//{
//	for (int j = 0; j < i; ++j)
//	{
//		for (int k = 0; k < j; ++k)
//		{
//			//순회하면서 0 체크
//			a[v[i].first][v[i].second] = a[v[j].first][v[j].second] = a[v[k].first][v[k].second] = 1;
//			ans = max(ans,Solve());
//			a[v[i].first][v[i].second] = a[v[j].first][v[j].second] = a[v[k].first][v[k].second] = 0;
//
//		}
//	}
//}
//
//cout << ans << endl;

#pragma region 1325

//vector<int> v[10001];
//int dp[10001] = { 0, }, visited[10001] = { 0, };
//int n = 0, m = 0;
//
//int dfs(int _num)
//{
//	visited[_num] = 1;
//
//	int res = 1;
//
//	for (int cur : v[_num])
//	{
//		if (!visited[cur])
//			res += dfs(cur);
//	}
//
//	return res;
//}

//int res = 0;
//
//cin >> n >> m;
//
//for (int i = 0; i < m; ++i)
//{
//	int a, b;
//	cin >> a >> b;
//	v[b].push_back(a);
//}
//
//
//for (int i = 0; i < n; ++i)
//{
//	memset(visited, 0, sizeof(visited));
//
//	dp[i] = dfs(i);
//	res = max(dp[i], res);
//}
//
//for (int i = 1; i < n; ++i)
//{
//	if (res == dp[i]) cout << i <<" ";
//}

#pragma endregion 1325


#pragma region 2636


#pragma endregion 2636

 	return 0;
}	