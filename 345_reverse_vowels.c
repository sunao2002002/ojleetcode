#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_vowels(char *buf)
{
    buf['A'] = buf['a'] = 1;
    buf['E'] = buf['e'] = 1;
    buf['I'] = buf['i'] = 1;
    buf['O'] = buf['o'] = 1;
    buf['U'] = buf['u'] = 1;

}
char* reverseVowels(char* s) {
    char buf[128] = {0};
    int length = strlen(s);
    if(length <=1)
        return s;
    init_vowels(buf);
    char *pStart = s;
    char *pEnd = s+length -1;
    char c;
    while(pStart < pEnd){
        while(pStart<pEnd && buf[*pStart] !=1 )pStart++;
        while(pEnd>pStart && buf[*pEnd] !=1) pEnd--;
        c = *pStart;
        *pStart = *pEnd;
        *pEnd =c ;
        pStart++;
        pEnd--;
    }
    return s;
}
int main(int argc, char** argv)
{
    char string[] = "leetcode";
    reverseVowels(string);
    printf("%s\n", string);
}