/*******************************************************************************
* ��Ȩ���� (C)2014��5��12��,����ͨѶ�ɷ����޹�˾��
* ϵͳ����	: 
* �ļ�����	: main.cpp
* ����ժҪ	: 
* ��ǰ�汾	: 
* ��    ��	: liuy
* �������	: 2014��5��12��
* �޸ļ�¼	: 
* ��    ��		��   ��			�޸���		�޸�ժҪ
*******************************************************************************/
/**************************** ��������ѡ���ͷ�ļ� ****************************/
#include <stdio.h>
#include <iostream>
#include <new>
#include <exception>
#include <vector>


#include "new-handle-dll.hpp"
#include "QueryMemory.h"
/********************************** �ꡢ���� **********************************/
const int MY_MAX_MEM_SIZE = 2147483647; //2G
const int MY_MEM_SIZE_BLOCK = 1024;
/********************************** �������� **********************************/

/************************************ ���� ************************************/

/********************************** ����ʵ�� **********************************/
void My_New_Handle()
{
	std::cout << "log:Operator New failed!" << std::endl;
	std::cout << QueryMemory<SHOW_KIlO_BYTE>();
	throw std::bad_alloc("Print:Operator New failed!");
}

/*********************************** ��ʵ�� ***********************************/

int main()
{
	std::new_handler pold_handle = std::set_new_handler(My_New_Handle);
	std::cout << "old handle is " << pold_handle  << std::endl;

 	try
	{
		char* pmem = new char[MY_MAX_MEM_SIZE];
	}
	catch (std::bad_alloc & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		void* pmem = New_Operation_Dll(MY_MAX_MEM_SIZE);
	}
	catch (std::bad_alloc & e)
	{
		std::cout << e.what() << std::endl;
	}

#if 0
	{
		std::vector<char*> vpool;
		try
		{
			while(1)
			{
				vpool.push_back(new char[MY_MEM_SIZE_BLOCK]);
			}
		}
		catch (std::bad_alloc & e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "cur heap size more than " << vpool.size() << 'K' << std::endl; 
		for (;!vpool.empty();)
		{
			char* pmem = vpool.back();
			delete []pmem;
			vpool.pop_back();
		}
	}
#endif
	

	char* pmem = new char[MY_MAX_MEM_SIZE];
	return 0;
}