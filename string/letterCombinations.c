#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>

char mapping[10][5] = {
"",
"",
"abc",
"def",
"ghi",
"jkl",
"mno",
"pqrs",
"tuv",
"wxyz"
};

int num_len[10] = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4 };

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

char**  letterCombinations(char* digits, int* returnSize) {
    assert(digits);
    assert(returnSize);

    int len = strlen(digits);
    if(len == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    int *ans = calloc(sizeof(int), len);
    assert(ans);

    int res_len = 1;
    for(int i = 0; i < len; i++) {
        res_len *= num_len[digits[i] - '0'];
    }

    //char (*res)[len + 1] = calloc(sizeof(char[len]) + 1, res_len);
    //assert(res);

    char **res = NULL;
    res = calloc(sizeof(char *), res_len);
    assert(res);
    for(int i = 0; i < res_len; i++) {
        res[i] = calloc(sizeof(char[len]) + 1, res_len);
        assert(res[i]);
    }

    int k = 0;    
    while(1) {
        
        for(int i = 0; i < len; i++) {
            res[k][i] = mapping[digits[i] - '0'][ans[i]];
        }
        k++;


        int j = len - 1;
        while(j >= 0) {
            if(ans[j] < num_len[digits[j] - '0'] - 1) {
                ans[j]++; 
                break;
            } else {
                ans[j] = 0;
                j--;
            }
        }

        if(j < 0)
            break;
    }

    *returnSize = k;
    return (char**) res;   

}





int main()
{
    char digits[] = {"23"};
    int returnSize = 0;

    int len = strlen(digits);
    //char (*res)[len + 1] = NULL;
    char **res;
    
    //res = (char (*)[len + 1]) letterCombinations((char *)&digits, &returnSize);
    res = letterCombinations((char *)&digits, &returnSize);


    for(int i = 0; i < returnSize; i++) {
        printf("%s\n", res[i]);
    }

    return 0;

}


