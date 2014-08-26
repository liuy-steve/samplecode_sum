/*******************************************************************************
* 版权所有 (C)2014年5月16日,中兴通讯股份有限公司。
* 系统名称	: windows 获取内存使用情况
* 文件名称	: QueryMemory.cpp
* 内容摘要	: 
* 当前版本	: 
* 作    者	: liuy
* 设计日期	: 2014年5月16日
* 修改记录	: 
* 日    期		版   本			修改人		修改摘要
*******************************************************************************/
/**************************** 条件编译选项和头文件 ****************************/
#include "QueryMemory.h"
#include <iostream>

#include <windows.h> 
#include <Psapi.h>
#include <process.h>
using namespace std;

#pragma comment(lib, "psapi.lib") 
/********************************** 宏、常量 **********************************/

/********************************** 数据类型 **********************************/
// typedef struct _PROCESS_MEMORY_COUNTERS {
// 	DWORD cb;
// 	DWORD PageFaultCount;//缺页中断次数
// 	SIZE_T PeakWorkingSetSize; //峰值内存使用
// 	SIZE_T WorkingSetSize; //当前使用的内存
// 	SIZE_T QuotaPeakPagedPoolUsage;//使用页面缓存池高峰
// 	SIZE_T QuotaPagedPoolUsage; //使用页面缓存池
// 	SIZE_T QuotaPeakNonPagedPoolUsage;//使用非分页缓存池高峰
// 	SIZE_T QuotaNonPagedPoolUsage;//使用非分页缓存池
// 	SIZE_T PagefileUsage;		//虚拟内存使用
// 	SIZE_T PeakPagefileUsage; //峰值虚拟内存使用
// } PROCESS_MEMORY_COUNTERS, 

// cb
// The size of the structure, in bytes.
// PageFaultCount
// The number of page faults.
// PeakWorkingSetSize
// The peak working set size, in bytes.
// WorkingSetSize
// The current working set size, in bytes.
// QuotaPeakPagedPoolUsage
// The peak paged pool usage, in bytes.
// QuotaPagedPoolUsage
// The current paged pool usage, in bytes.
// QuotaPeakNonPagedPoolUsage
// The peak nonpaged pool usage, in bytes.
// QuotaNonPagedPoolUsage
// The current nonpaged pool usage, in bytes.
// PagefileUsage
// The Commit Charge value in bytes for this process. Commit Charge is the total amount of memory that the memory manager has committed for a running process.
// PeakPagefileUsage
// The peak value in bytes of the Commit Charge during the lifetime of this process.
/************************************ 变量 ************************************/

/********************************** 函数实现 **********************************/

/*********************************** 类实现 ***********************************/


