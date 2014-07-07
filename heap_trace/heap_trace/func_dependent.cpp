#include "func_dependent.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cassert>

#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <intsafe.h>

using namespace std;

void NewPieceOfMemory()
{
	cout << "input size of memory:" ;
	string sinput;
	if (cin >> sinput)
	{
		stringstream ss(sinput);
		int ncount = 0;
		ss >> ncount;

		ostream::fmtflags curr_fmt = cout.flags();
		
		cout << showbase << uppercase;
		cout << "new data len = <" << ncount << ">" << '\n';
		char* pbuf = new char[ncount];
		cout << "buffer = <" << hex << static_cast<void*>(pbuf) << ">" << endl;

		cout.flags(curr_fmt);
		Sleep(10);
	}
	else
	{
		
	}
}

void DeletePieceOfMemory()
{
	unsigned int nbuf = 0;
	istream::fmtflags curr_fmt = cin.flags();
	if (cin >> hex >> nbuf)
	{
		cout << "delete buffer = <" << nbuf << ">" << endl;
		char* pbuf = (char*)nbuf;
		delete []pbuf;
		Sleep(10);
	}
	else
	{
		assert(0);
	}
	cin.flags(curr_fmt);
}

void CreateHeap()
{
	HANDLE heap = HeapCreate(0, 4096, 0);
	ostream::fmtflags curr_fmt = cout.flags();
	cout << "heap handle is <" << hex << heap << ">";
	cout.flags(curr_fmt);
}

void DestroyHeap()
{
	istream::fmtflags curr_fmt_in = cin.flags();
	HANDLE heap;
	cin >> hex >> heap;
	HeapDestroy(heap);
	ostream::fmtflags curr_fmt_out = cout.flags();
	cout << "heap handle is <" << hex << heap << ">";
	cout.flags(curr_fmt_out);
	cin.flags(curr_fmt_in);
}

void QueryHeaps()
{
	DWORD NumberOfHeaps;
	DWORD HeapsIndex;
	DWORD HeapsLength;
	HANDLE hDefaultProcessHeap;
	HRESULT Result;
	PHANDLE aHeaps;
	SIZE_T BytesToAllocate;

	NumberOfHeaps = GetProcessHeaps(0, NULL);
	if (NumberOfHeaps == 0) {
		cout << TEXT("Failed to retrieve the number of heaps with LastError %d.\n")  << GetLastError() << endl;
		return ;
	}

	//
	// Calculate the buffer size.
	//
	Result = SIZETMult(NumberOfHeaps, sizeof(*aHeaps), &BytesToAllocate);
	if (Result != S_OK) {
		_tprintf(TEXT("SIZETMult failed with HR %d.\n"), Result);
		return;
	}

	//
	// Get a handle to the default process heap.
	//
	hDefaultProcessHeap = GetProcessHeap();
	if (hDefaultProcessHeap == NULL) {
		_tprintf(TEXT("Failed to retrieve the default process heap with LastError %d.\n"),
			GetLastError());
		return ;
	}

	//
	// Allocate the buffer from the default process heap.
	//
	aHeaps = (PHANDLE)HeapAlloc(hDefaultProcessHeap, 0, BytesToAllocate);
	if (aHeaps == NULL) {
		_tprintf(TEXT("HeapAlloc failed to allocate %d bytes.\n"),
			BytesToAllocate);
		return ;
	}

	// 
	// Save the original number of heaps because we are going to compare it
	// to the return value of the next GetProcessHeaps call.
	//
	HeapsLength = NumberOfHeaps;

	//
	// Retrieve handles to the process heaps and print them to stdout. 
	// Note that heap functions should be called only on the default heap of the process
	// or on private heaps that your component creates by calling HeapCreate.
	//
	NumberOfHeaps = GetProcessHeaps(HeapsLength, aHeaps);
	if (NumberOfHeaps == 0) {
		_tprintf(TEXT("Failed to retrieve heaps with LastError %d.\n"),
			GetLastError());
		return ;
	}
	else if (NumberOfHeaps > HeapsLength) {

		//
		// Compare the latest number of heaps with the original number of heaps.
		// If the latest number is larger than the original number, another
		// component has created a new heap and the buffer is too small.
		//
		_tprintf(TEXT("Another component created a heap between calls. ") \
			TEXT("Please try again.\n"));
		return ;
	}

	_tprintf(TEXT("Process has %d heaps.\n"), HeapsLength);
	for (HeapsIndex = 0; HeapsIndex < HeapsLength; ++HeapsIndex) {
		_tprintf(TEXT("Heap %d at address: %#p.\n"),
			HeapsIndex,
			aHeaps[HeapsIndex]);
	}

	//
	// Release memory allocated from default process heap.
	//
	if (HeapFree(hDefaultProcessHeap, 0, aHeaps) == FALSE) {
		_tprintf(TEXT("Failed to free allocation from default process heap.\n"));
	}

	return ;

}
