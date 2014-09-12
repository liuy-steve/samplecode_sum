#include <set>

using std::set;

class Solution {
public:
	int removeDuplicates(int A[], int n) 
	{
		if (n < 2)
		{
			return n;
		}
		int* pcur = A + 1;
		int* pdest = A + 1;
		int ntmp = A[0];
		while(pdest - A < n)
		{
			if (ntmp != *pdest)
			{
				ntmp = *pdest;
				*(pcur++) = ntmp;
			}
			pdest++;
		}
		return pcur - A;

	}
};