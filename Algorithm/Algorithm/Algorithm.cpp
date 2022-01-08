// Algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//


#include "MyVector.h"

#include <iostream>
#include <regex>
#include <vector>
#include <string>
#include <map>

#include <algorithm>


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

int main()
{

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

int N = 0,M=0,res=0;

cin >> N>>M;
vector<int> v(N);

for (int i = 0; i < N; ++i)
	cin >> v[i];

if (M > 200000)
{
	cout << 0 << "\n";
	return 0;
}

sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (v[i] + v[j] == M)
				++res;
		}
	}
	cout << res << "\n";

#pragma endregion 1940

#pragma region 3986
#pragma endregion 3986


	return 0;
}