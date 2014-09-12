#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using std::string;
using std::stack;
using std::vector;
using std::find;
using std::distance;

static const char left_part_pare[] = {'(', '[', '{'};
static const char right_part_pare[] = {')', ']', '}'};
static const char* pleft_pare_begin = &left_part_pare[0];
static const char* pleft_pare_end = &left_part_pare[0] + sizeof(left_part_pare);
static const char* pright_pare_begin = &right_part_pare[0];
static const char* pright_pare_end = &right_part_pare[0] + sizeof(right_part_pare);

class Solution {
public:
	bool isValid(string s) {
		stack<char> pare;
		for (string::iterator it = s.begin(); it != s.end(); it++)
		{
			if (find(pleft_pare_begin, pleft_pare_end, *it) != pleft_pare_end)
			{
				pare.push(*it);
			}

			if (find(pright_pare_begin, pright_pare_end, *it) != pright_pare_end)
			{	
				if (pare.empty() || pare.top() != peer(*it))
				{
					return false;
				}
				else
				{
					pare.pop();
				}
				
			}
		}
		return pare.size() == 0;
	}

private:
	char peer(char pare)
	{
		return left_part_pare[distance(pright_pare_begin, find(pright_pare_begin, pright_pare_end, pare))];
	}

private:

};