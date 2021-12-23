// Algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <regex>
#include <vector>
#include <string>

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

int main()
{
    std::cout <<"Bit Swap :	"<< ReverseBits(8)<<endl;

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


	

}