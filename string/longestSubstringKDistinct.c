#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int longestSubstringKDistinct(char* s, int k) {
    assert(s);
    assert(k>=0);

    int *map = calloc(sizeof(int), 26);
    if(NULL == map) {
        return -1;
    }

    int start = 0, res = 0, count = 0;
    for(int end = 0; end < strlen(s); end++) {
        int i = s[end] - 'a';
        if(0 == map[i]++) {
            count++;
        }

        if(count > k) {
            map[start]--;
            if(0 == map[start]) {
                count--;
            }
            start++;            
        }

        res = res > (end - start + 1) ? res : (end - start + 1);
        
    }
    return res;    
}


int main()
{
    int res = 0;
    char* s = "eceba";
    int k = 3;

    res =  longestSubstringKDistinct(s, k);


    printf("%d \n", res);
    
    return 0;

}



