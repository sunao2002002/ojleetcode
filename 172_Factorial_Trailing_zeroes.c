/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
*/

#include <stdio.h>
#include <stdlib.h>
int count_5(int n) {
  int result = 0;
  while (n > 0 && n % 5 == 0) {
    result++;
    n = n / 5;
  }
  return result;
}

int trailingZeroes(int n) {
  int result = 0;
  for (int i = 1; i <= n; i++) {
    if (i % 5 == 0) {
      result += count_5(i);
    }
  }
  return result;
}

int trailingZeroes2(int n) {
  int result = 0;
  while (n) {
    n = n / 5;
    result += n;
  }
  return result;
}

int main(int argc, char const *argv[]) {
  /* code */
  int n = 10;
  printf("%d\n", trailingZeroes(n));
  printf("%d\n", trailingZeroes2(n));
  return 0;
}
