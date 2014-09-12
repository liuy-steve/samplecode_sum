#include <vector>

using std::vector;
class Solution {
public:
	int reverse(int x) {
		int nret = 0;
		while(x != 0)
		{
			nret = nret * 10 + x % 10;
			x = x / 10;
		}
		return nret ;
	}
};