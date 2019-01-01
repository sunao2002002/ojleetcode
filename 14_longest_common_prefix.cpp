/*
Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of
strings.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    int length = strs.size();
    if (length <= 0)
      return "";
    string prefix = strs[0];
    int i, j;
    for (i = 1; i < length; i++) {
      string tmpStr = strs[i];
      if (prefix.length() == 0 || tmpStr.length() == 0)
        return "";
      int len = min(prefix.length(), tmpStr.length());
      for (j = 0; j < len; j++) {
        if (prefix[j] != tmpStr[j])
          break;
      }
      prefix = prefix.substr(0, j);
    }
    return prefix;
  }
};

int main(int argc, char **argv) { return 0; }