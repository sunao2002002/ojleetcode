#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1: 
Input: “Let’s take LeetCode contest” 
Output: “s’teL ekat edoCteeL tsetnoc” 
Note: In the string, each word is separated by single space and there will not be any extra space in the string.

*/
void _reverse(char *pStart, char *pEnd)
{
    if(pStart >= pEnd)
        return;
    char c ;
    while(pStart < pEnd){
        c = *pStart;
        *pStart = *pEnd;
        *pEnd = c;
        pStart++;
        pEnd--;
    }
}
char* reverseWords(char* s) {
   int length = strlen(s);
   if(length <= 1)
       return s;
   char *pStart = s;
   char *pEnd = s+length -1;
   char *p ;
    while(pStart <pEnd){
        p=pStart;
        while(*p!= ' ' && *p!='\0') p++;
        _reverse(pStart, p-1);
        pStart = ++p;
    }
    return s;
}

int main(int argc, char const *argv[])
{
    /* code */
    char buf[] = "Let's take leetcode contest";
    printf("%s\n", buf);
    printf("%s\n",reverseWords(buf));
    return 0;
}

