class Solution {
public:
	int removeElement(int A[], int n, int elem) {
		int* pcur = A;
		int* pdest = A;
		while(pdest - A < n)
		{
			if (*pdest != elem)
			{
				*pcur = *pdest;
				pcur++;
			}
			pdest++;
		}
		return pcur - A;
	}
};