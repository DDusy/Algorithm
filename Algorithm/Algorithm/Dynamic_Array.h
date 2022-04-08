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
*  build_Array �����̳� ���� �Լ�  array�� ��ȯ
*  ���� ������ �Ű������� ����ϱ� ���� ���� ���ø� �̿�
* 
* https://stackoverflow.com/questions/11215227/should-the-trailing-return-type-syntax-style-become-the-default-for-new-c11-pr
* ���� ��ȯ ����
* 
* ������ Ÿ���� ��ȣ�Ҷ� �̿� ����
* 
*/

auto a()-> int
{
	int b=0;
	return b;
}

