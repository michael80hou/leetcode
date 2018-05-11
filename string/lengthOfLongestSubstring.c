#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    assert(s);
    int len = strlen(s);
    int max = len ? 1 : 0;
    int i = 0, j = 0, k = 0;
    int flag_break = 0;

    for(i = 0; i < len; i++)
    {
        for(j = i + 1; j < len; j++)
        {
            char key = s[j];
            int sub_len = 0;
            flag_break = 0;
            for(k = i; k <= j; k++)
            {
                sub_len++;
                if(s[k] == key && k != j)
                {
                    flag_break = 1;
                    break;
                }

            }

            max = sub_len > max ? sub_len : max;
            if(flag_break)
            {
                break;
            }
            
        }
    }

    return max;
    
}


int main()
{
    char* test = "abcabcbb";

    int res;
    res =  lengthOfLongestSubstring(test);
    printf("%d\n", res);
    return 0;

}


