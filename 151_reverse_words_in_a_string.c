#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Given an input string, reverse the string word by word.

Example:

Input: “the sky is blue”, 
Output: “blue is sky the”. 
Note:

A word is defined as a sequence of non-space characters. 
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces. 
You need to reduce multiple spaces between two words to a single space in the reversed string. 
Follow up: For C programmers, try to solve it in-place in O(1) space.
*/
enum{
    STATE_BEGIN,
    STATE_SPACE,
    STATE_CAPITAL
};
void  remove_duplicate_space(char *s)
{
    if(s==NULL || *s=='\0')
        return;
    int length = strlen(s);
    int index = 0;
    int state = STATE_BEGIN;
    for(int i=0; i<length; i++){
        if(s[i] == ' '){
            if(state == STATE_CAPITAL){
                state = STATE_SPACE;
            }
        }else{
            if(state == STATE_SPACE){
                s[index++] = ' ';
            }
            s[index++] = s[i];
            state = STATE_CAPITAL;
        }
    }
    s[index] = '\0';

}


void _reverse(char *pStart, char *pEnd)
{
    if(pStart >= pEnd)
        return;
    while((*pEnd == ' ') && (pEnd >=pStart))
        pEnd--;
    while(pStart < pEnd){
        char c = *pStart;
        *pStart = *pEnd;
        *pEnd = c;
        pStart++;
        pEnd--;
    }
}
void reverseWords(char *s) {
    remove_duplicate_space(s);
   int length = strlen(s);
   if(length <= 1)
       return;
   char *pStart = s;
   char *pEnd = s+length -1;
    _reverse(pStart, pEnd);
    while(pStart <pEnd){
        while(*pStart == ' ')pStart++;
        char *p=pStart;
        while(*p!= ' ' && *p!='\0') p++;
        _reverse(pStart, p-1);
        pStart = p++;
    }
}
int main(int argc, char const *argv[])
{
    
    char buf[] = "the sky is blue";
    printf("before: %s\n",buf);
    reverseWords(buf);
    printf("after: %s\n",buf);
    return 0;
}
