#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>


#define DP_VERSION 0
#define REC_VERSION 1
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
#if (DP_VERSION == 1)
char**  letterCombinations(char* digits, int* returnSize) {
    assert(digits);
    assert(returnSize);

    int len = strlen(digits);
    if(len == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    int res_len = 1;
    for(int i = 0; i < len; i++) {
        res_len *= num_len[digits[i] - '0'];
    }

    char **res = NULL;
    res = calloc(sizeof(char *), res_len);
    assert(res);
    for(int i = 0; i < res_len; i++) {
        res[i] = calloc(sizeof(char[len]) + 1, res_len);
        assert(res[i]);
    }
    
    int factor = 1;    
    for(int j = len - 1; j >= 0; j--) {    
        int digits_len = num_len[digits[j] - '0'];
        for(int i = 0; i < res_len; i++) {            
            res[i][j] = mapping[digits[j] - '0'][i / factor % digits_len];  
        }
        factor *= digits_len;
    }

    *returnSize = res_len;

    return res;

}
#elif (REC_VERSION == 1)

int hnd(char* digits, int index, int len, int res_len, char** res) {

    int num = digits[index] - '0';
    int digits_len = num_len[num];
    
    if(index == len - 1) {
        for(int i = 0; i < res_len; i++) {
            res[i][index] = mapping[num][i % digits_len];
        }
        return digits_len;
    } else {
        int block = hnd(digits, index + 1, len, res_len, res);
        for(int i = 0; i < res_len; i++) {
            res[i][index] = mapping[num][i / block % digits_len];
        }
        return block*digits_len;
    }
}

char**  letterCombinations(char* digits, int* returnSize) {
    assert(digits);
    assert(returnSize);

    int len = strlen(digits);
    if(len == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    int res_len = 1;
    for(int i = 0; i < len; i++) {
        res_len *= num_len[digits[i] - '0'];
    }
    *returnSize = res_len;

    char **res = NULL;
    res = calloc(sizeof(char *), res_len);
    assert(res);
    for(int i = 0; i < res_len; i++) {
        res[i] = calloc(sizeof(char[len]) + 1, res_len);
        assert(res[i]);
    }

    hnd(digits, 0, len, res_len, res);

    return res;

}


#else
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

#endif



int main()
{
    char digits[] = {"23"};
    int returnSize = 0;

    int len = strlen(digits);
    //char (*res)[len + 1] = NULL;
    char **res;
    
    //res = (char (*)[len + 1]) letterCombinations((char *)&digits, &returnSize);
    res = letterCombinations((char *)&digits, &returnSize);

    printf("size %d\n", returnSize);

    for(int i = 0; i < returnSize; i++) {
        printf("%s\n", res[i]);
    }

    //todo: add free res

    return 0;

}


