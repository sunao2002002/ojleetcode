#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLastWord(char *s) {
  if (s == NULL)
    return 0;
  int count = 0;
  int length = strlen(s);
  char *p = s + length - 1;
  int index = length - 1;
  for (; index >= 0; index--) {
    if (s[index] != ' ')
      break;
  }
  for (; index >= 0; index--) {
    if (s[index] == ' ')
      break;
    count++;
  }
  return count;
}
int main(int argc, char **argv) {
  printf("%d\n", lengthOfLastWord("Hello World"));
}
