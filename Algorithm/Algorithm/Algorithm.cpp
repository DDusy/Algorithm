// Algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

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


		/* 비트 1의 개수가 K 일때 O(k)
		* Result ^= 1;	// 짝수 홀수 반복
		* _x &= (_x - 1); // 하위비트를 지워가며 실행
		*/
	}

	return Result;
}


short ParityMask(unsigned long long _x)
{
	const int MaskSize = 16;
	const int BitMask = 0xffff;

	return PreCompute[_x >> (3 * MaskSize)];
}


int main()
{
    std::cout <<"Bit Count :	"<< Parity(11);
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
