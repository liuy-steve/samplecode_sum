#include <vector>
#include <map>
#include <algorithm>

using std::vector;
using std::find;
using std::map;

struct Node
{
	int num, pos;
	Node(int n, int p)
		:num(n)
		,pos(p)
	{

	}
};

struct Compare_Opt
{
	bool operator() (const Node& i, const Node& j)
	{
		return i.num < j.num;
	}
};

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<Node> numbers_map;
		vector<int> ret;

		for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
		{
			numbers_map.push_back(Node(*it, distance(numbers.begin(), it) + 1));
		}

		sort(numbers_map.begin(), numbers_map.end(), Compare_Opt());

		vector<Node>::iterator head, tail;
		head = numbers_map.begin();
		tail = numbers_map.end() - 1;

		for (; tail != head; )
		{
			int sum = tail->num + head->num;
			if (sum < target) 
			{
				head ++;
			}
			else if (sum > target)
			{
				tail --;
			}
			else
			{
				ret.push_back(std::min<int>(tail->pos, head->pos));
				ret.push_back(std::max<int>(tail->pos, head->pos));
				return ret;
			}
		}
		return ret;
	}
};