/*******************************************************************************
* 版权所有 (C)2014年5月12日,中兴通讯股份有限公司。
* 系统名称	: 
* 文件名称	: new-handle-dll.cpp
* 内容摘要	: 
* 当前版本	: 
* 作    者	: liuy
* 设计日期	: 2014年5月12日
* 修改记录	: 
* 日    期		版   本			修改人		修改摘要
*******************************************************************************/
/**************************** 条件编译选项和头文件 ****************************/
#include "new-handle-dll.hpp"
/********************************** 宏、常量 **********************************/

/********************************** 数据类型 **********************************/

/************************************ 变量 ************************************/

/********************************** 函数实现 **********************************/

/*********************************** 类实现 ***********************************/


void* New_Operation_Dll( size_t size )
{
	return new char[size];
}
