/*
The string “PAYPALISHIRING” is written in a zigzag pattern on a given number of
rows like this: (you may want to display this pattern in a fixed font for better
legibility)

P A H N
A P L S I I G
Y I R

And then read line by line: “PAHNAPLSIIGYIR”

Write the code that will take a string and make this conversion given a number
of rows:

string convert(string text, int nRows);

convert(“PAYPALISHIRING”, 3) should return “PAHNAPLSIIGYIR”.

*/

#include <cstring>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  string convert(string s, int numRows) {
    size_t len = s.size();
    string result;
    if (len <= numRows || numRows == 1)
      return s;
    int groupLen = 2 * numRows - 2;
    for (int row = 0; row < numRows; row++) {
      int offset = 2 * numRows - 2 - 2 * row;
      for (int i = row; i < len; i += groupLen) {
        result.push_back(s[i]);
        if (offset != 0 && offset != groupLen && i + offset < len) {
          result.push_back(s[i + offset]);
        }
      }
    }
    return result;
  }
};

int main(int argc, char const *argv[]) {
  string s = ("PAYPALISHIRING");
  int row = 3;
  Solution sln;
  string result = sln.convert(s, row);
  cout << result << endl;
  return 0;
}
