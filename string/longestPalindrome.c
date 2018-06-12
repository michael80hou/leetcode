#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#if 0
//O(n^3)
char* longestPalindrome(char* s) {
    assert(s);
    int len = strlen(s);
    int l = 0, r = 0;
    int max = 0;
    int maxl = 0, maxr = 0;
    
    for(l = 0; l < len - 1; l++) {
        for(r = len - 1; r > l; r--) {
            int i = l;
            int j = r;
            if(max > r - l) {
                break;
            }
            int valid = 0;
            while(s[i] == s[j]) {
                if(i == j || j - i == 1) {
                    if(r - l > max) {
                        max = r - l;
                        maxl = l;
                        maxr = r;                    
                    }
                    valid = 1;
                    break;
                }

                i++; 
                j--;
            } 

            if(valid) { break; }

        }
    }

    s[maxr + 1] = '\0';

    return (s + maxl);
    
}
#else 
//O(n^2)
char* longestPalindrome(char* s) {
    assert(s);
    int len = strlen(s);    
    char (*p)[len] = malloc(len * len);
    assert(p);
    memset(p, 0, len * len);

    int max_diff = 0, index_l = 0, index_r = 0;
    int l = 0, i = 0;
    for(l = 0; l < len; l++) {
        for(i = 0; i < len - l; i++) {
            if(l == 0) {
                p[i][i] = 1;
            } else if(l == 1){
                if(s[i] == s[i + 1]) {
                    p[i][i + 1] = 1;
                    if(1 > max_diff) {
                        max_diff = 1;
                        index_l = i;
                        index_r = i + 1;
                    }
                }
            } else {
                if(p[i + 1][i + l - 1] && s[i] == s[i + l]) {
                    p[i][i + l] = 1;
                    if(l > max_diff) {
                        max_diff = l;
                        index_l = i;
                        index_r = i + l;
                    }
                }
            }
        }
    }

    s[index_r + 1] = '\0';
    return (s + index_l);
    

}

#endif



int main()
{
    char test[] = {"babad"};
    char* res;
    res =  longestPalindrome((char *) &test);
    printf("%s\n", res);
    return 0;

}


