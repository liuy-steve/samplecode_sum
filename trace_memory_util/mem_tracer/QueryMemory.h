/*******************************************************************************
* ��Ȩ���� (C)2014��5��16��,����ͨѶ�ɷ����޹�˾��
* ϵͳ����	: windows ��ȡ�ڴ�ʹ�����
* �ļ�����	: QueryMemory.h
* ����ժҪ	: 
* ��ǰ�汾	: 
* ��    ��	: liuy
* �������	: 2014��5��16��
* �޸ļ�¼	: 
* ��    ��		��    ��		�޸���		�޸�ժҪ
*******************************************************************************/
/**************************** ��������ѡ���ͷ�ļ� ****************************/
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
/********************************** �����ͺ� **********************************/

/********************************** �������� **********************************/

/********************************** �������� **********************************/
/*********************************** �ඨ�� ***********************************/
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
			<< "���¸������"
			<<	(map_dic.find(obj.scale()))->second
									<<"Ϊ��λ" << endl

			<< "���������������ʾΪ����ֵ�������ã��ڴ棩" << pmc.PeakWorkingSetSize / obj.scale() << endl
			<< "���������������ʾΪ���������ã��ڴ棩    " << pmc.WorkingSetSize / obj.scale() << endl

			<< "���������������ʾΪ��ҳ�滺��أ��ڴ棩  " << pmc.QuotaPagedPoolUsage / obj.scale() << endl
			<< "                      ҳ�滺��ظ߷�      " << pmc.QuotaPeakPagedPoolUsage / obj.scale() << endl

			<< "���������������ʾΪ���߷幤�������ڴ棩  " <<pmc.PeakPagefileUsage / obj.scale() << endl
			<< "���������������ʾΪ���ڴ棨ר�ù������������ڴ� "<<pmc.PagefileUsage / obj.scale() << endl;
	}
	return os;
}

template<unsigned int T>
int QueryMemory<T>::s_npid = 0;

#endif 
