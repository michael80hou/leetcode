#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define CHAR_SIZE (128)
int lengthOfLongestSubstring(char* s) {
    assert(s);
    int len = strlen(s);
    int max = 0;
    
    if(len == 0) {
        max = 0;
    } else if(len == 1) {
        max = 1;
    } else {
        char direct_hash[CHAR_SIZE] = {0};
        int i = 0, j = 0;        
        int sub_max = 0;
        int pre_stop_pos = 0;

        for(i = 0; i < len; i++) {
            int k = i ? i - 1 : 0;
            direct_hash[(int)(s[k])] = 0;
            //printf("%c \n", s[i]);
            for(j = pre_stop_pos; j < len; j++) {
               //printf("%c \n", s[j]);
                if(direct_hash[(int)(s[j])] == 0) {
                    direct_hash[(int)(s[j])] = 1;
                } else {            
                    break;
                }
            }
            
            pre_stop_pos = j;
            sub_max = j - i;
            //printf("max %d sub_max %d pre_stop %d  i %d \n",max, sub_max, pre_stop_pos, i);
            max = max > sub_max ? max : sub_max;
            if(pre_stop_pos == len) {
                break;
            }
            
        }
    }   

    return max;
}



int main()
{
    char* test = "aab";

    int res;
    res =  lengthOfLongestSubstring(test);
    printf("%d\n", res);
    return 0;

}


