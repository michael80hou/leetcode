#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

int characterReplacement(char* s, int k) {
    assert(s);
    assert(k>=0);

    int *map = calloc(sizeof(int), 26);
    if(NULL == map) {
        return -1;
    }
    
    int len = strlen(s);
    if(k >= len) {
        return len;
    }

    int res = 0, start = 0, max = 0;
    for(int end = 0; end < len; end++) {
        int tmp = ++map[s[end] - 'A'];
        max = max > tmp ? max : tmp; 

        if(end - start + 1 - max > k) {
            res = res > end - start ? res :  end - start;            
            map[s[start] - 'A']--; 
            start++;
        }
        
        res = res > end - start + 1 ? res : end - start + 1;
    }

    return res;    
}


int main()
{
    int res = 0;
    char* s = "AAAA";
    int k = 0;

    res =  characterReplacement(s, k);


    printf("%d \n", res);
    
    return 0;

}


