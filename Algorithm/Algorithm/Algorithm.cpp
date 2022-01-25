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


bool cmp(string _a, string _b)
{
	if (_a.size() == _b.size()) return _a < _b;
	return _a.size() < _b.size();
}
int main()
{

#pragma region last

#pragma region 2468
	//cin >> N;

	//for (int i = 0; i < N; ++i)
	//{
	//	for (int j = 0; j < N; ++j)
	//	{
	//		cin >> board[i][j];
	//	}
	//}


	//for (int depth = 1; depth < 101; ++depth)
	//{

	//	fill(&checked[0][0], &checked[0][0] + 101 * 101, 0);
	//	tmp = 0;

	//	for (int i = 0; i < N; ++i)
	//	{
	//		for (int j = 0; j < N; ++j)
	//		{
	//			if (depthboard[i][j] == 1) continue;

	//			if (board[i][j]<=depth) depthboard[i][j] = 1;

	//		}
	//	}

	//	for (int i = 0; i < N; ++i)
	//	{
	//		for (int j = 0; j < N; ++j)
	//		{
	//			if (!checked[i][j] && depthboard[i][j] == 0)
	//			{
	//				DFS(i, j);
	//				++tmp;
	//			}
	//		}
	//	}
	//	res = max(res, tmp);

	//}

	//cout << res << endl;

	//
#pragma endregion
#pragma region 10988
	//string str;
	//int res = 1;
	//cin >> str;

	//int range = str.length();
	//for (int i = 0; i < range/2; ++i)
	//{
	//	if (str[i] != str[range - i-1])
	//	{
	//		res = 0;
	//		break;
	//	}
	//}

	//cout << res << endl;

#pragma endregion

#pragma region 1159

	//int N = 0;
	//cin >> N;
	//int cnt[26] = {0,};
	//vector<string> v(N);
	//string Res="";

	//for (int i = 0; i < N; ++i)
	//{
	//	cin >> v[i];
	//	++cnt[v[i][0]-'a'];
	//}

	//for (int num=0;num<26;++num)
	//{
	//	if (cnt[num] >= 5)
	//		Res += 'a' + num;
	//}
	//
	//if(Res=="")
	//cout <<"PREDAJA" << endl;
	//else
	//	cout <<Res<< endl;
#pragma endregion

#pragma region 11655
	//string str;
	//getline(cin,str);
	//
	//for (char& ch : str)
	//{
	//	if (ch >= 'a' && ch <= 'z')
	//	{
	//		if (ch + 13 > 'z') ch = ch - 13;
	//		else ch += 13;
	//	}
	//	else if (ch >= 'A' && ch <= 'Z')
	//	{
	//		if (ch + 13 > 'Z') ch = ch - 13;
	//		else ch += 13;
	//	}
	//}

	//cout << str;

#pragma endregion

#pragma region 9996

//int N = 0;
//cin >> N;
//string input,pattern, filename,pre,last;
//vector<string> Res(N);
//cin >> input;
//
////pattern = input[0];
////pattern += ".";
////pattern += input.substr(1);
//
//
//
//int pos= input.find("*");
//
//pre = input.substr(0, pos);
//last = input.substr(pos + 1);
//
//
//regex re(pre + ".*" + last);
//
//for (int i = 0; i < N; ++i)
//{
//	cin >> filename;
//
//	//
//	//if (pre == filename.substr(0, pos) && last == filename.substr(filename.length() - last.length()))
//	if(regex_match(filename,re))
//		Res[i] = "DA";
//	else
//		Res[i] = "NE";
//}
//
//
//for (string str : Res)
//cout << str << endl;

#pragma endregion 9996

#pragma region 2559
//int N = 0, K = 0,res=0;
//int sum[100] = {0,};
//cin >> N >> K;
//
//vector<int> v(N+1);
//
//for (int i = 1; i <= N; ++i)
//{
//	cin >> v[i];
//	sum[i] = sum[i - 1] + v[i];
//}
//
//for (int i = K; i <= N; i++)
//{
//	res = max(res, (sum[i]-sum[i-K]));
//}
//cout << res << endl;

#pragma endregion 2559

#pragma region 1620

//string PokeStr;
//map<string, int> map_name;
//map<int, string> map_num;
//
//int N = 1, M = 1;
//
//cin >> N >> M;
//
//for (int i = 0; i < N; ++i)
//{
//	cin >> PokeStr;
//	map_name[PokeStr] = i + 1;
//	map_num[i + 1] = PokeStr;
//}
//
//for (int i = 0; i < M; ++i)
//{
//	cin >> PokeStr;
//	if (atoi(PokeStr.c_str()) == 0)
//	{
//		cout << map_name[PokeStr] << endl;
//	}
//	else
//	{
//		cout << map_num[atoi(PokeStr.c_str())] << endl;
//	}
//}
#pragma endregion 1620


#pragma region 1213

//int cnt[123] = { 0, }, flag = 0;
//string input, res;
//char mid = ' ';
//
//cin >> input;
//
//for (char ch : input)
//++cnt[ch];
//
//for (int i = 'Z'; i >= 'A'; --i)
//{
//	if (cnt[i])
//	{
//		if (cnt[i] & 1)
//		{
//			mid = (char)i;
//			--cnt[i];
//			++flag;
//			if (2 == flag) break;
//		}
//
//		for (int j = 0; j < cnt[i]; j += 2)
//		{
//			res = (char)(i)+res;
//			res += (char)i;
//		}
//	}
//}
//
//	if (flag == 2)
//	 cout << "I'm Sorry Hansoo" << endl;
//	else
//	{
//		if(mid!=' ')
//		res.insert(res.begin()+ res.size()/2, mid);
//		cout << res << endl;
//	}
#pragma endregion 1213

#pragma region 9375
//string type, pos;
//map<string, int> tb;
//int N = 0, T = 0;
//long long res = 0;
//
//cin >> T;
//
//while (T--)
//{
//	res = 1;
//	tb.clear();
//
//	cin >> N;
//	for (int i = 0; i < N; ++i)
//	{
//		cin >> type >> pos;
//		++tb[pos];
//	}
//
//	for (auto d : tb)
//	{
//		res *= (long long)d.second + 1;
//	}
//	--res;
//
//	cout << res << endl;
//}
#pragma endregion 9375

#pragma region 1940

//int N = 0,M=0,res=0;
//
//cin >> N>>M;
//vector<int> v(N);
//
//for (int i = 0; i < N; ++i)
//	cin >> v[i];
//
//if (M > 200000)
//{
//	cout << 0 << "\n";
//	return 0;
//}
//
//sort(v.begin(), v.end());
//
//	for (int i = 0; i < N; i++) {
//		for (int j = i + 1; j < N; j++) {
//			if (v[i] + v[j] == M)
//				++res;
//		}
//	}
//	cout << res << "\n";

#pragma endregion 1940

#pragma region 3986

//ios_base::sync_with_stdio(false);
//cin.tie(NULL); cout.tie(NULL);
//
//int N = 0,res=0;
//string s;
//
//cin>> N;
//
//for (int i = 0; i < N; ++i)
//{
//	stack<char> stk;
//
//	cin >> s;
//
//	for (char ch : s)
//	{
//		if (!stk.empty() && stk.top() == ch)
//			stk.pop();
//		else
//		stk.push(ch);
//	}
//
//	if (!stk.size())
//		++res;
//}
//
//cout << res << endl;
#pragma endregion 3986

#pragma region 1629

//ios_base::sync_with_stdio(false);
//cin.tie(NULL); cout.tie(NULL);

//long long a, b, c;
//함수로
//long long Divide(long long _a, long long _b)
//{
//	if (_b == 1) return _a % c;
//	long long _c = Divide(_a, _b / 2);
//	_c = (_c * _c) % c;
//
//	if (_b & 1)_c = (_c * _a) % c;
//	return _c;
//}
//
//cin >> a >> b >> c;
//cout << Divide(a, b) << "\n";


#pragma endregion 1629

#pragma region 4375

//int N = 0;
//
//while (scanf_s("%d", &N) != EOF)
//{
//	int cnt = 1, res = 1;
//
//	while (true)
//	{
//		if (cnt % N == 0)	// N의 배수인지 체크
//		{
//			cout << res << "\n";
//			break;
//		}
//		else
//		{	//11... 추가하고 N으로 나누기
//			cnt = (cnt * 10) + 1;
//			cnt %= N;
//			++res;
//		}
//	}
//}
#pragma endregion 4375

#pragma region 2178

//// bfs
//int dx[] = { -1,0,1,0 };
//int dy[] = { 0,1,0,-1 };
//int n = 0, m = 0;
//queue<pair<int,int>> q;
//
//scanf_s("%d%d",&n, &m);
//
//vector<vector<int>> v(n,vector<int>(m));
//vector<vector<bool>> checked(n, vector<bool>(m,false));
//
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < m; ++j)
//			scanf_s("%1d",&v[i][j]);
//	}
//
//	checked[0][0] = true;
//	q.push({ 0,0 });
//
//	while (q.size())
//	{
//		
//		int cur_x =q.front().first;
//		int cur_y =q.front().second;
//
//		q.pop();
//
//		for (int i = 0; i < 4; ++i)
//		{
//			int nx = cur_x + dx[i];
//			int ny = cur_y + dy[i];
//
//			if (nx<0 || ny<0 || nx>=n || ny>=m || (v[nx][ny] == 0)) continue;
//			if (checked[nx][ny]) continue;
//
//			v[nx][ny] = v[cur_x][cur_y] + 1;
//
//			q.push({ nx,ny });
//			checked[nx][ny] = true;
//		}
//
//	}
//
//	cout <<v[n-1][m-1]<<endl;

#pragma endregion 2178

#pragma region 1012


ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
//cin >> t;
//
//while (t--)
//{
//
//	res = 0;
//	cin >> m >> n >> k;
//
//	fill(checked.begin(), checked.end(), vector<bool>(n,false));
//	fill(v.begin(), v.end(), vector<int>(n, 0));
//
//	for (int i = 0; i < k; ++i)
//	{
//		cin >> x >> y;
//		v[x][y] = 1;
//	}
//
//	for (int i = 0; i < m; ++i)
//	{
//		for (int j = 0; j < n; ++j)
//		{
//			if ((1 == v[i][j]) && !checked[i][j])
//			{
//				dfs(i, j);
//				++res;
//			}
//		}
//	}
//
//	cout << res << endl;
//}

#pragma endregion 1012

#pragma region 2583

//
//
//cin >> m >> n >> k;
//
//vector<vector<int>> v(m, vector<int>(n, 0));
//vector<vector<bool>> checked(m, vector<bool>(n, false));
//vector<int> res;
//
//for (int i = 0; i < k; ++i)
//{
//	cin >> posx1 >> posy1 >> posx2 >> posy2;
//
//	for (int j = m-posy2; j < (m-posy1); ++j)
//	{
//		for (int h = posx1; h < posx2; ++h)
//		{
//			v[j][h] = 1;
//		}
//	}
//}
//
//for (int i = 0; i < m; ++i)
//{
//	for (int j = 0; j < n; ++j)
//	{
//		if (!checked[i][j]&& (0==v[i][j]))
//		{
//			cnt = 1;
//			dfs(i, j,v,checked);
//			res.push_back(cnt);
//		}
//	}
//}
//
//cout << res.size() << endl;
//
//sort(res.begin(), res.end());
//	for (int r : res)
//	cout << r << " ";

#pragma endregion 2583

#pragma region 1992

//int n;
//cin >> n;
//vector<vector<int>> v(n+1, vector<int>(n+1, 0));
//
//string s;
//
//for (int i = 0; i <n; ++i)
//{
//	cin >> s;
//
//	for (int j = 0; j <n; ++j)
//	{
//		v[i][j]=s[j];
//	}
//}
//
//cout << quard(0, 0, n,v) << endl;

#pragma endregion 1992


//int n, m, j, l, r, tmp, res=0;
//
//cin >> n >> m >> j;
//l = 1;
//
//for (int i = 0; i < j; ++i)
//{
//	r = l + m - 1; // 바구니 범위
//	cin >> tmp;
//
//	if (tmp >= l && tmp <= r) continue;	// 범위안이면 필요X
//	else
//	{
//		if (tmp < l)
//		{
//			res += (l - tmp);
//			l = tmp;
//		}
//		else
//		{
//			l += (tmp - r);
//			res += (tmp - r);
//
//		}
//	}
//}
//
//cout << res << endl;

#pragma region 2910

//unordered_map<int, pair<int, int>> tb;
//
//bool cmp(tuple<int, int, int> _a, tuple<int, int, int> _b)
//{
//	if (get<1>(_a) == get<1>(_b))
//	{
//		return get<2>(_a) < get<2>(_b);
//	}
//
//	return get<1>(_a) > get<1>(_b);
//}


//vector<tuple<int, int, int>> v;
//int N = 0, C = 0, tmp = 0;
//
//cin >> N >> C;
//for (int i = 0; i < N; ++i)
//{
//	cin >> tmp;
//
//	if (tb[tmp].first == 0)
//		tb[tmp].second += i;
//
//	++tb[tmp].first;
//}
//
//for (auto iter : tb)
//{
//	v.push_back({ iter.first, iter.second.first,iter.second.second });
//}
//
//sort(v.begin(), v.end(), cmp);
//
//for (auto iter : v)
//{
//	for (int i = 0; i < get<1>(iter); ++i)
//		cout << get<0>(iter) << " ";
//}

#pragma endregion 2910


#pragma region 4659번
//string s;
//int consonant = 0, vowel = 0, size = 0,cnt=0;
//bool ischeck = true;
//
//
//	while (true)
//	{
//	cin >> s;
//
//	if (s == "end")
//		break;
//
//	size = s.length();
//	ischeck = true;
//
//	cnt = 0;
//	consonant = 0;
//	vowel = 0;
//	
//	for (int i=0;i<size;++i)
//	{
//		if (i > 0 && (s[i] == s[i - 1])&& (s[i] != 'e'&& s[i] != 'o'))
//		{
//			ischeck=false;
//			break;
//		}
//
//		if (Isvowel(s[i]))
//		{
//			++vowel, consonant = 0;
//			++cnt;
//		}
//		else
//		{
//			++consonant, vowel = 0;
//		}
//
//		if (vowel > 2 || consonant > 2)
//		{
//			ischeck = false;
//			break;
//		}
//	}
//
//	if (ischeck&& cnt>0)
//		cout << "<" << s << ">" << " is acceptable." << endl;
//	else
//		cout << "<" << s << ">" << " is not acceptable." << endl;
//	
//	}
#pragma endregion 4659번
#pragma endregion last

#pragma region 2870

int N = 0;
string s,numstr;
vector<string> v;
cin >> N;

for (int i = 0; i < N; ++i)
{
	cin >> s;
	
	for (char ch : s)
	{
		if (ch >= '0' && ch <= '9')
		{
			numstr += ch;
		}
		else
		{
			if (numstr.size())
			{
				while (true)
				{
					if (numstr.size() && numstr.front() == '0')
						numstr.erase(numstr.begin());
					else
						break;
				}

				if (!numstr.size()) numstr = "0";
				v.push_back(numstr);
				numstr="";

			}

		
		}
	}


	if (numstr.size())
	{
		while (true)
		{
			if (numstr.size() && numstr.front() == '0')
				numstr.erase(numstr.begin());
			else
				break;
		}

		if (!numstr.size()) numstr = "0";
		v.push_back(numstr);

		numstr = "";

	}
}

	sort(v.begin(), v.end(), cmp);

	for (string num : v)
		cout << num << endl;

#pragma endregion 2870
 	return 0;
}