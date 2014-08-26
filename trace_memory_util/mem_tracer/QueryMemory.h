/*******************************************************************************
* 版权所有 (C)2014年5月16日,中兴通讯股份有限公司。
* 系统名称	: windows 获取内存使用情况
* 文件名称	: QueryMemory.h
* 内容摘要	: 
* 当前版本	: 
* 作    者	: liuy
* 设计日期	: 2014年5月16日
* 修改记录	: 
* 日    期		版    本		修改人		修改摘要
*******************************************************************************/
/**************************** 条件编译选项和头文件 ****************************/
#ifndef __QUERYMEMORY_H__  
#define __QUERYMEMORY_H__  
#include <iostream>
#include <map>

#include <windows.h> 
#include <Psapi.h>
#include <process.h>
using std::map;
using std::endl;
using std::ostream;
/********************************** 常量和宏 **********************************/

/********************************** 数据类型 **********************************/

/********************************** 函数声明 **********************************/
/*********************************** 类定义 ***********************************/
const int SHOW_BYTE = 1;
const int SHOW_KIlO_BYTE = 1024;
const int SHOW_MEGA_BYTE = SHOW_KIlO_BYTE * SHOW_KIlO_BYTE;

typedef std::map <int, const char*> MCharacterTable;
const MCharacterTable::value_type map_table[] = 
{
	MCharacterTable::value_type(SHOW_BYTE, "B"),
	MCharacterTable::value_type(SHOW_KIlO_BYTE, "KB"), 
	MCharacterTable::value_type(SHOW_MEGA_BYTE, "MB")
};

const MCharacterTable map_dic(map_table, map_table + sizeof(map_table) - 1);

template<unsigned int T>
class QueryMemory
{
public:
	QueryMemory()
		:m_scale(T)
	{
	};
	~QueryMemory(){};
	const int scale() const{return m_scale;};
public:
	static void SetPID(int const i_nPID) {s_npid = i_nPID;}
	const int GetPID() const {return s_npid;}
private:
	const unsigned m_scale;
	static int s_npid;
};

template<unsigned int T>
ostream& operator << ( ostream& os, const QueryMemory<T>& obj )
{
	char aprocess_name[MAX_PATH] = "........";
	HANDLE hProcess = OpenProcess( PROCESS_QUERY_INFORMATION | PROCESS_VM_READ,
		FALSE, 
		obj.GetPID());
	if ( hProcess )
	{

		GetModuleFileNameEx(hProcess,NULL,aprocess_name,MAX_PATH);            
		PROCESS_MEMORY_COUNTERS pmc; 

		GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc)); 
		os 
			<< "以下各项均以"
			<<	(map_dic.find(obj.scale()))->second
									<<"为单位" << endl

			<< "在任务管理器中显示为：峰值工作设置（内存）" << pmc.PeakWorkingSetSize / obj.scale() << endl
			<< "在任务管理器中显示为：工作设置（内存）    " << pmc.WorkingSetSize / obj.scale() << endl

			<< "在任务管理器中显示为：页面缓冲池（内存）  " << pmc.QuotaPagedPoolUsage / obj.scale() << endl
			<< "                      页面缓存池高峰      " << pmc.QuotaPeakPagedPoolUsage / obj.scale() << endl

			<< "在任务管理器中显示为：高峰工作集（内存）  " <<pmc.PeakPagefileUsage / obj.scale() << endl
			<< "在任务管理器中显示为：内存（专用工作集）虚拟内存 "<<pmc.PagefileUsage / obj.scale() << endl;
	}
	return os;
}

template<unsigned int T>
int QueryMemory<T>::s_npid = 0;

#endif 
