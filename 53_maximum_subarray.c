//
//  main.c
//  test
//
//  Created by david on 2017/9/25.
//  Copyright © 2017年 david. All rights reserved.
//

#include <libgen.h>
#include <stdio.h>
#include <string.h>

#define out(...) printf(__VA_ARGS__)

/*53. Maximum Subarray*/

int max(int a, int b) { return a > b ? a : b; }

int maxSubArray(int *nums, int numsSize) {
  int cur_sum, max_sum;
  cur_sum = max_sum = nums[0];
  int right, left, cur_right, cur_left;
  right = left = cur_right = cur_left = 0;
  int index = 0;
  for (index = 1; index < numsSize; index++) {
    if (cur_sum > 0) {
      cur_sum += nums[index];
      cur_right = index;
    } else {
      cur_sum = nums[index];
      cur_left = cur_right = index;
    }
    if (max_sum < cur_sum) {
      max_sum = cur_sum;
      left = cur_left;
      right = cur_right;
    }
  }
  printf("max_sum = %d\t left=%d\t right=%d\n", max_sum, left, right);
  return max_sum;
}

int main(int argc, const char *argv[]) {
  // insert code here...
  int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 7};
  int max = maxSubArray(nums, 9);
  out("max=%d\n", max);
  return 0;
}
