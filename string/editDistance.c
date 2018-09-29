#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

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





int main()
{
    char word1[] = {"intention"};
    char word2[] = {"execution"};

    int res = minDistance((char *) &word1, (char *) &word2);
    printf("%d\n", res);

    return 0;

}
