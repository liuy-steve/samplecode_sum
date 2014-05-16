/*******************************************************************************
* 版权所有 (C)2014年5月12日,中兴通讯股份有限公司。
* 系统名称	: 
* 文件名称	: main.cpp
* 内容摘要	: 
* 当前版本	: 
* 作    者	: liuy
* 设计日期	: 2014年5月12日
* 修改记录	: 
* 日    期		版   本			修改人		修改摘要
*******************************************************************************/
/**************************** 条件编译选项和头文件 ****************************/
#include <stdio.h>
#include <iostream>
#include <new>
#include <exception>
#include <vector>


#include "new-handle-dll.hpp"
#include "QueryMemory.h"
/********************************** 宏、常量 **********************************/
const int MY_MAX_MEM_SIZE = 2147483647; //2G
const int MY_MEM_SIZE_BLOCK = 1024;
/********************************** 数据类型 **********************************/

/************************************ 变量 ************************************/

/********************************** 函数实现 **********************************/
void My_New_Handle()
{
	std::cout << "log:Operator New failed!" << std::endl;
	std::cout << QueryMemory<SHOW_KIlO_BYTE>();
	throw std::bad_alloc("Print:Operator New failed!");
}

/*********************************** 类实现 ***********************************/

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