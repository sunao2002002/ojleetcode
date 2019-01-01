/*
Given n non-negative integers representing the histogram’s bar height where the
width of each bar is 1, find the area of largest rectangle in the histogram.

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given heights = [2,1,5,6,2,3],
return 10.
---------------------
作者：大胃孙
来源：CSDN
原文：https://blog.csdn.net/sunao2002002/article/details/52893452
版权声明：本文为博主原创文章，转载请附上博文链接！
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    vector<int> h(heights.begin(), heights.end());
    h.push_back(0);
    int maxSize = h[0];
    stack<int> iStack;
    int i = 0;
    while (i < h.size()) {
      int curHeight = h[i];
      if (iStack.empty() || (curHeight > h[iStack.top()])) {
        iStack.push(i++);
      } else {
        int barHeight = h[iStack.top()];
        iStack.pop();
        int width = (iStack.empty() ? i : i - iStack.top() - 1);
        maxSize = max(maxSize, barHeight * width);
      }
    }
    return maxSize;
  }
};
int main(int argc, char const *argv[]) {

  vector<int> height;
  int buf[] = {2, 1, 5, 6, 2, 3};
  for (int index = 0; index < sizeof(buf) / sizeof(buf[0]); index++) {
    height.push_back(buf[index]);
  }
  Solution sln;
  cout << sln.largestRectangleArea(height) << endl;
  return 0;
}
