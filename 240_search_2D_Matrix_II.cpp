/*


Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted in ascending from left to right.
    Integers in each column are sorted in ascending from top to bottom.

For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]

Given target = 5, return true.

Given target = 20, return false.
*/

#include<iostream>
#include <stack>
#include<vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        	int rows = matrix.size();
		if (rows<=0)
			return false;
		int cols = matrix[0].size();
		int i = rows-1;
		int j = 0;
		while(i>=0 && j<cols){
			if (matrix[i][j] == target)
				return true;
			else if (matrix[i][j]<target)
				j++;
			else
				i--;
		}
		return false;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
