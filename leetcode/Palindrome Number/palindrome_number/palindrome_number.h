#include <climits>

class Solution {
public:
	bool isPalindrome(int x) {
		return x < 0 ? false : static_cast<long long>(x) == reverse(x);
	}

private:
	long long  reverse(int x)
	{
		long long lret = 0;
		while(x != 0)
		{
			lret = lret * 10 + x % 10;
			x /= 10;
		}
		return lret;
	}
};