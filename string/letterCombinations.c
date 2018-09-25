#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>

char letter[10][5] = {
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

int total[10] = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4 };

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char**  letterCombinations(char* digits, int* returnSize) {
    assert(digits);
    assert(returnSize);

#if 0
    char c = '\0';
    int len = strlen(digits);
    int rows = 4^len;

    char **res = malloc(sizeof(char[len]) * rows);
    assert(res);

    int i = 0, j = 0, k = 0;
    for(i = 0; i < len; i++) {
        for(j = 0; j < 4 && letter[digits[i] - '2'][j] != '\0'; j++) {
            //res[k][j] = letter[digits[i] - '2'][j];
            printf("%c ", letter[digits[i] - '2'][j]);
        }

        printf("\n");
    }

    return (char**)res;
#else
    int len = strlen(digits);

    int *ans = calloc(sizeof(int), len);
    assert(ans);

    int j = len - 1;

    while(1) {
        int i = 0;//, int j = 0;

        for(i = 0; i < len; i++) {
            printf("%c", letter[digits[i] - '0'][ans[i]] );

        }
        printf("\n");


        //j = len - 1;
        if(j  >= 0)
        {
            if(ans[j] < total[j] - 1) {
                ans[j]++;
            } else {
                ans[j] = 0;
                if(j == 0) {
                    break;
                }else {                    
                    j--;
                }
            }
        }
    }

    return NULL;

    
#endif    
}





int main()
{
    char digits[] = {"23"};
    int returnSize = 9;

    char **res =     letterCombinations((char *)&digits, &returnSize);

    


    return 0;

}


