/*******************************************************************************
* ��Ȩ���� (C)2014��5��16��,����ͨѶ�ɷ����޹�˾��
* ϵͳ����	: windows ��ȡ�ڴ�ʹ�����
* �ļ�����	: QueryMemory.cpp
* ����ժҪ	: 
* ��ǰ�汾	: 
* ��    ��	: liuy
* �������	: 2014��5��16��
* �޸ļ�¼	: 
* ��    ��		��   ��			�޸���		�޸�ժҪ
*******************************************************************************/
/**************************** ��������ѡ���ͷ�ļ� ****************************/
#include "QueryMemory.h"
#include <iostream>

#include <windows.h> 
#include <Psapi.h>
#include <process.h>
using namespace std;

#pragma comment(lib, "psapi.lib") 
/********************************** �ꡢ���� **********************************/

/********************************** �������� **********************************/
// typedef struct _PROCESS_MEMORY_COUNTERS {
// 	DWORD cb;
// 	DWORD PageFaultCount;//ȱҳ�жϴ���
// 	SIZE_T PeakWorkingSetSize; //��ֵ�ڴ�ʹ��
// 	SIZE_T WorkingSetSize; //��ǰʹ�õ��ڴ�
// 	SIZE_T QuotaPeakPagedPoolUsage;//ʹ��ҳ�滺��ظ߷�
// 	SIZE_T QuotaPagedPoolUsage; //ʹ��ҳ�滺���
// 	SIZE_T QuotaPeakNonPagedPoolUsage;//ʹ�÷Ƿ�ҳ����ظ߷�
// 	SIZE_T QuotaNonPagedPoolUsage;//ʹ�÷Ƿ�ҳ�����
// 	SIZE_T PagefileUsage;		//�����ڴ�ʹ��
// 	SIZE_T PeakPagefileUsage; //��ֵ�����ڴ�ʹ��
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
/************************************ ���� ************************************/

/********************************** ����ʵ�� **********************************/

/*********************************** ��ʵ�� ***********************************/


