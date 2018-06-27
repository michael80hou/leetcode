#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

bool isMatch(char* s, char* p) {
    assert(s && p);
    int len_s = strlen(s);
    int len_p = strlen(p);
    bool res = false;

    int (*dp)[len_p  + 1] =  malloc(sizeof(int) * (len_s + 1) * (len_p + 1));
    memset(dp, 0,  sizeof(int) * (len_s + 1)* (len_p + 1));
    dp[len_s][len_p] = 1;
    
    
    int i = 0, j = 0;

    for(i = len_s; i >= 0 ; i--) {
        for(j = len_p - 1; j >= 0 ; j--) {
        
            bool first_match = ((len_s - i) > 0 && (s[i] == p[j] || p[j] == '.'));
            if(len_p - j >= 2 && p[j + 1] == '*') {
                dp[i][j] = (first_match && dp[i + 1][j]) || dp[i][j + 2];
            } else {
                dp[i][j] = first_match && dp[i + 1][j + 1];
            }           
        }
    }

    res = dp[0][0] == 1 ? true : false;


    free(dp);
    return res;    
}


int main() 
{

    char s[] = "a";
    char p[] = "a*";

    bool res = isMatch((char *)&s, (char *)&p);

    printf("res %d\n", res);
    
    return 0;
}

