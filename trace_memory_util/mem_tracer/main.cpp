/*******************************************************************************
* 版权所有 (C)2014年8月26日,中兴通讯股份有限公司。
* 系统名称	: 
* 文件名称	: main.cpp
* 内容摘要	: 
* 当前版本	: 
* 作    者	: liuy
* 设计日期	: 2014年8月26日
* 修改记录	: 
* 日    期		版   本			修改人		修改摘要
*******************************************************************************/
/**************************** 条件编译选项和头文件 ****************************/
#include <stdio.h>
#include <iostream>

#include "QueryMemory.h"
/********************************** 宏、常量 **********************************/

/********************************** 数据类型 **********************************/

/************************************ 变量 ************************************/

/********************************** 函数实现 **********************************/

/*********************************** 类实现 ***********************************/
const int SHOW_WAY = SHOW_BYTE;

using std::cin;
using std::cout;
using std::endl;
int main()
{
	cout << "Please input the PID of process which you want to check!.." << endl;
	int npid = 0;
	cin >> npid;
	QueryMemory<SHOW_WAY>().SetPID(npid);
	cout << QueryMemory<SHOW_WAY>();
	
	return 0;
}