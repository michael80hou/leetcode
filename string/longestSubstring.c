#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

int characterReplacement(char* s, int k) {
    assert(s);
    assert(k>=0);

    int *map = malloc(sizeof(int) * 26);
    if(NULL == map) {
        return -1;
    }
    
    int len = strlen(s);
    if(len == 0) {
        return 0;
    }

    if(k >= len) {
        return len;
    }

    int res = 0;
    for(int l = 0; l <= len - k; l++) {
        memset(map, 0, sizeof(int) * 26);
        int max = 0;
        for(int r = l; r < len; r++) {
            int index = s[r] - 'A';
            map[index]++;
            max = max > map[index] ? max : map[index]; 


            int num = r - l + 1;
            if(num - max > k) {
                res = res > num - 1 ? res : num - 1;
                break;
            }

            if(len - 1 == r) {
                res = res > len - l ? res : len - l;
            }
        }


    }

    return res;
    
}


int main()
{
    int res = 0;
    char* s = "AABABBA";
    int k = 1;

    res =  characterReplacement(s, k);


    printf("%d \n", res);
    
    return 0;

}


