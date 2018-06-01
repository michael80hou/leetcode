#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

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




int main()
{
    char test[] = {"babad"};
    char* res;
    res =  longestPalindrome((char *) &test);
    printf("%s\n", res);
    return 0;

}


