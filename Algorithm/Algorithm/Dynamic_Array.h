#pragma once
#include <iostream>
#include <type_traits>
#include <array>

template<typename ... Args> //	
auto build_Array(Args&& ... _Args)->std::array<typename std::common_type<Args...>::type, sizeof...(_Args)>
{
	using common_type = typename std::common_type<Args...>::type;
	return {std::forward<common_type>((Args&&)_Args)...};
}
/*
*  build_Array 컨테이너 생성 함수  array를 반환
*  임의 개수의 매개변수를 허용하기 위해 가변 템플릿 이용
* 
* https://stackoverflow.com/questions/11215227/should-the-trailing-return-type-syntax-style-become-the-default-for-new-c11-pr
* 후행 반환 유형
* 
* 데이터 타입이 모호할때 이용 가능
* 
*/

auto a()-> int
{
	int b=0;
	return b;
}

