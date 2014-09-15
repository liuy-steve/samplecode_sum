#include <vector>

using std::vector;

class Solution {
public:
	void rotate(vector<vector<int> > &matrix) {
		const unsigned int n = matrix.size();
		if (n <= 1)
		{
			return;
		}

		for (unsigned int i = 0; i < n / 2; i++)
		{
			for (unsigned int j = i; j < n - 1 - i; j++)
			{
				convert(matrix, i, j);
			}
		}
	}
	void convert(vector<vector<int> > &matrix, unsigned int row, unsigned int col)
	{
		const unsigned int n = matrix.size();
		int num = matrix[row][col];
		matrix[row][col] = matrix[n - 1 - col][row];
		matrix[n - 1 - col][row] = matrix[n - 1 - row][n - 1 - col];
		matrix[n - 1 - row][n - 1 - col] = matrix[col][n - 1 - row];
		matrix[col][n - 1 - row]= num;
	}
};