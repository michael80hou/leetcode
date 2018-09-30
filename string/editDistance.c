#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


#define DP_VERSION 1

#ifdef DP_VERSION
int minDistance(char* word1, char* word2) {

    int res = -1;
    int row = strlen(word1) + 1;
    int column = strlen(word2) + 1;

    int (*table)[column] = calloc(sizeof(int[column]), row);
    if(NULL == table) {
        printf("fatal error!\n");
        return res;
    }


    for(int i = row - 1; i >= 0; i--) {
        for(int j = column - 1 ; j >= 0; j--) {
            if(row - 1 == i) {
                table[i][j] = column - 1 - j;
            } else if(column - 1 == j) {
                table[i][j] = row - 1 - i;
            } else {
                if(word1[i] == word2[j]) {
                    table[i][j] = table[i + 1][j + 1];
                } else {
                    int tmp = table[i + 1][j] < table[i + 1][j + 1] ? table[i + 1][j] : table[i + 1][j + 1];
                    tmp = tmp < table[i][j + 1] ? tmp : table[i][j + 1];
                    table[i][j] = tmp + 1;
                }
            }
        }
    }

    res = table[0][0];
    if(table) {
        free(table);
        table = NULL;
    }

    return res;
    
    
}


#else
int minDistance(char* word1, char* word2) {

    int len1 = strlen(word1);
    int len2 = strlen(word2);

    if(len1 == 0) {
        return len2;
    } else if(len2 == 0) {
        return len1;
    } else {
        if(*word1 == *word2) {
            return minDistance(word1 + 1, word2 + 1);
        } else {
            int case1 = 0, case2 = 0, case3 = 0;
            int res = 0;

            case1 = 1 + minDistance(word1 + 1, word2 + 1);
            case2 = 1 + minDistance(word1, word2 + 1);
            case3 = 1 + minDistance(word1 + 1, word2);

            res = case1 < case2 ? case1 : case2;
            res = res < case3 ? res : case3;

            return res;
        }
    }
}
#endif




int main()
{
    char word1[] = {"intention"};
    char word2[] = {"execution"};

    int res = minDistance((char *) &word1, (char *) &word2);
    printf("%d\n", res);

    return 0;

}
